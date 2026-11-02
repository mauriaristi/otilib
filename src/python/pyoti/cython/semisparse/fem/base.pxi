# Phase 5: FEM element helper (elm_help).
# (PLAN-semisparse-sparse-leveling.md)
#
# Semi-sparse counterpart of pyoti.sparse.elm_help (src/python/pyoti/cython/sparse/fem/base.pxi), the
# object pyoti.fem elements hold when pyoti.fem.set_global_algebra(pyoti.semisparse) is active.
# Shape functions and their reference derivatives are Gauss-point arrays (oarrssfe, 1 x nbasis);
# weights, determinants and differentials are Gauss-point scalars (ssotife); nodal coordinates are
# plain SoA columns (oarrss, nbasis x 1). compute_jacobian is batched over the integration points:
# every Jacobian entry is one Gauss-by-plain dot product (a single SoA matrix product), det/inv use
# closed forms for n <= 3, and the spatial derivatives are per-point broadcasts.


# ********************************************************************************************************
cdef oarrss _fe_take_rows(oarrss src, object rows, int64_t ncols=-1):
    """
    Gather rows of a plain SoA matrix (same active set and order).

    Parameters
    ----------
    src : oarrss
        Source matrix, n x m.
    rows : array_like of int
        Row indices, each < n.
    ncols : int
        Number of leading columns to keep (-1: all).

    Returns
    -------
    oarrss
        len(rows) x ncols matrix.
    """

    cdef np.ndarray[np.int64_t, ndim=1] idx = np.asarray(rows, dtype=np.int64).ravel()
    cdef uint64_t nr = idx.shape[0], m = src.arr.ncols, n = src.arr.nrows
    cdef uint64_t nb = 1 + sshelp_ndir_total(src.arr.nbases, src.arr.trc_order)
    cdef oarrss_t res = oarrss_zeros(src.arr.p_bases, src.arr.nbases, nr, m, src.arr.trc_order)
    cdef uint64_t d, c, i, r

    if ncols >= 0 and <uint64_t>ncols < m:

        oarrss_free(&res)
        m = ncols
        res = oarrss_zeros(src.arr.p_bases, src.arr.nbases, nr, m, src.arr.trc_order)

    # end if

    for i in range(nr):

        if idx[i] < 0 or <uint64_t>idx[i] >= n:

            oarrss_free(&res)
            raise IndexError("row index {} out of range for {} rows".format(idx[i], n))

        # end if

    # end for

    for d in range(nb):

        for c in range(m):

            for i in range(nr):

                r = idx[i]
                res.p_data[d * res.size + i + c * nr] = src.arr.p_data[d * src.arr.size + r + c * n]

            # end for

        # end for

    # end for

    res.act_order = src.arr.act_order

    return oarrss.wrap(res)

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef object _fe_local(object arr, object rows, int64_t ncols=-1):
    """
    Gather the element rows of a global array given as oarrss, matso or arrss.

    Parameters
    ----------
    arr : oarrss or matso or arrss
        Global array (nodes x columns).
    rows : array_like of int
        Element node indices.
    ncols : int
        Number of leading columns to keep (-1: all).

    Returns
    -------
    oarrss
        Element rows.
    """

    cdef object src = arr
    cdef oarrss res
    cdef uint64_t i, j, m
    cdef np.ndarray idx

    if isinstance(src, arrss):

        src = src.to_soa()

    # end if

    if isinstance(src, oarrss):

        return _fe_take_rows(src, rows, ncols)

    # end if

    if isinstance(src, matso):

        # Per-entry conversion: converting the whole global array for every element would be O(n).
        idx = np.asarray(rows, dtype=np.int64).ravel()
        m   = src.shape[1] if ncols < 0 else min(ncols, src.shape[1])
        res = oarrss.zeros((idx.shape[0], m), order=src.order)

        for i in range(idx.shape[0]):

            for j in range(m):

                res[i, j] = src[int(idx[i]), j]

            # end for

        # end for

        return res

    # end if

    raise TypeError("expected an oarrss, arrss or sparse matso, got {}".format(type(arr).__name__))

# end function
# --------------------------------------------------------------------------------------------------------


# ********************************************************************************************************
cdef class elm_help:
    """
    Element helper of pyoti.semisparse: integration points, shape functions, Jacobians.

    Field names and meaning follow pyoti.sparse.elm_help: N, Nxi, Neta, Nzeta, Nx, Ny, Nz (1 x nbasis
    Gauss arrays), J (ndim x ndim_an), Jinv (ndim_an x ndim), detJ, dV, w, xi, eta, zeta (Gauss
    scalars), and x, y, z (nbasis x 1 plain columns of nodal coordinates).
    """

    cdef public object special
    cdef public uint64_t nbasis, nip, ndim_an
    cdef public uint8_t ndim, compute_Jinv
    cdef public object otinbases, otiorder
    cdef public object xi, eta, zeta, w
    cdef public object N, Nxi, Neta, Nzeta, Nx, Ny, Nz
    cdef public object x, y, z
    cdef public object J, detJ, Jinv, dV

    # ****************************************************************************************************
    def __cinit__(self):
        """
        Create an unallocated helper.
        """

        self.end()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def __repr__(self):
        """
        Describe the allocation state and the integration rule.

        Returns
        -------
        str
            Representation.
        """

        body = ""

        if self.is_allocated():

            body += " - Object allocation: ------------ Allocated\n"
            body += " - Number of Integration points: - " + str(self.nip) + "\n"
            body += " - Integration points: \n"
            body += " ----   xi: \n" + repr(self.xi.real) + "\n"
            body += " ----  eta: \n" + repr(self.eta.real) + "\n"
            body += " ---- zeta: \n" + repr(self.zeta.real) + "\n"
            body += " - Integration weights: \n" + repr(self.w.real) + "\n"

        else:

            body += " - Object allocation: -------------- Not allocated\n"

        # end if

        return "< elm_help (semisparse) object: \n" + body + "end elm_help object >"

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def allocate(self, ndim, nbasis, nip, nbases=0, order=0):
        """
        Allocate the integration-point fields.

        Parameters
        ----------
        ndim : int
            Reference dimension of the element.
        nbasis : int
            Number of shape functions.
        nip : int
            Number of integration points.
        nbases : int
            Accepted for pyoti.sparse compatibility (a capacity hint there); unused.
        order : int
            Truncation order of the helper fields.
        """

        self.ndim      = ndim
        self.nip       = nip
        self.nbasis    = nbasis
        self.otiorder  = order
        self.otinbases = nbases

        self.N     = _fe_zeros((1, nbasis), (), order, nip)
        self.Nxi   = _fe_zeros((1, nbasis), (), order, nip)
        self.Neta  = _fe_zeros((1, nbasis), (), order, nip)
        self.Nzeta = _fe_zeros((1, nbasis), (), order, nip)

        self.w    = _fe_scalar(0.0, (), order, nip)
        self.xi   = _fe_scalar(0.0, (), order, nip)
        self.eta  = _fe_scalar(0.0, (), order, nip)
        self.zeta = _fe_scalar(0.0, (), order, nip)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def allocate_spatial(self, ndim_an, compute_Jinv=False):
        """
        Allocate the spatial fields (coordinates, Jacobian, differentials).

        Parameters
        ----------
        ndim_an : int
            Number of spatial dimensions of the analysis.
        compute_Jinv : bool
            Also allocate and compute Jinv and the spatial derivatives Nx, Ny, Nz.
        """

        cdef object order = self.otiorder

        if not self.is_allocated():

            raise ValueError("elm_help must be allocated first. "
                             "Trying to allocate spatial coordinates with no allocated element.")

        # end if

        self.ndim_an = ndim_an
        self.J = _fe_zeros((self.ndim, ndim_an), (), order, self.nip)
        self.x = oarrss.zeros((self.nbasis, 1), order=order)
        self.y = oarrss.zeros((self.nbasis, 1), order=order)
        self.z = oarrss.zeros((self.nbasis, 1), order=order)
        self.detJ = _fe_scalar(0.0, (), order, self.nip)
        self.dV   = _fe_scalar(0.0, (), order, self.nip)
        self.compute_Jinv = compute_Jinv

        if compute_Jinv:

            self.Jinv = _fe_zeros((ndim_an, self.ndim), (), order, self.nip)
            self.Nx   = _fe_zeros((1, self.nbasis), (), order, self.nip)
            self.Ny   = _fe_zeros((1, self.nbasis), (), order, self.nip)
            self.Nz   = _fe_zeros((1, self.nbasis), (), order, self.nip)

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def is_allocated(self):
        """
        Tell whether allocate() has been called.

        Returns
        -------
        bool
            True when the integration-point fields exist.
        """

        return self.w is not None

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def reset(self):
        """
        Zero the spatial fields.
        """

        self.J.set(0.0)
        self.x = oarrss.zeros((self.nbasis, 1), order=self.otiorder)
        self.y = oarrss.zeros((self.nbasis, 1), order=self.otiorder)
        self.z = oarrss.zeros((self.nbasis, 1), order=self.otiorder)
        self.detJ.set(0.0)
        self.dV.set(0.0)

        if self.compute_Jinv:

            self.Jinv.set(0.0)
            self.Nx.set(0.0)
            self.Ny.set(0.0)
            self.Nz.set(0.0)

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def end(self):
        """
        Release every field.
        """

        self.special   = None
        self.nbasis    = 0
        self.nip       = 0
        self.ndim      = 0
        self.ndim_an   = 0
        self.otiorder  = 0
        self.otinbases = 0
        self.compute_Jinv = False

        self.xi = self.eta = self.zeta = self.w = None
        self.N = self.Nxi = self.Neta = self.Nzeta = None
        self.Nx = self.Ny = self.Nz = None
        self.x = self.y = self.z = None
        self.J = self.detJ = self.Jinv = self.dV = None

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get(self, a, elem_indices, out=None):
        """
        Extract the element's nodal values (first column) from a global array.

        Parameters
        ----------
        a : oarrss or matso or arrss
            Global array.
        elem_indices : numpy.ndarray
            Element node indices.
        out : oarrss, optional
            Receives the result.

        Returns
        -------
        oarrss
            nbasis x 1 column.
        """

        return _fe_store(_fe_local(a, elem_indices, 1), out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_coordinates(self, x, y, z, elem_indices):
        """
        Copy the element's nodal coordinates from the global coordinate columns.

        Parameters
        ----------
        x, y, z : oarrss or matso or arrss
            Global coordinate columns (nodes x 1); sparse matso columns are accepted too.
        elem_indices : numpy.ndarray
            Element node indices.
        """

        self.x = _fe_local(x, elem_indices)
        self.y = _fe_local(y, elem_indices)
        self.z = _fe_local(z, elem_indices)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def set_array(self, arr, elem_indices, out=None):
        """
        Gather the element rows of a global array (all columns).

        Parameters
        ----------
        arr : oarrss or matso or arrss
            Global array.
        elem_indices : numpy.ndarray
            Element node indices.
        out : oarrss, optional
            Receives the result.

        Returns
        -------
        oarrss
            nbasis x ncols array.
        """

        return _fe_store(_fe_local(arr, elem_indices), out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def get_local(self, arr, elem_indices, out=None):
        """
        Gather the element rows of a global array (all columns).

        Parameters
        ----------
        arr : oarrss or matso or arrss
            Global array.
        elem_indices : numpy.ndarray
            Element node indices.
        out : oarrss, optional
            Receives the result.

        Returns
        -------
        oarrss
            nbasis x ncols array.
        """

        return _fe_store(_fe_local(arr, elem_indices), out)

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def _reference_derivatives(self):
        """
        Return the reference-derivative arrays used by this element's dimension.

        Returns
        -------
        list of oarrssfe
            [Nxi], [Nxi, Neta] or [Nxi, Neta, Nzeta].
        """

        return [self.Nxi, self.Neta, self.Nzeta][:self.ndim]

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def _finish(self):
        """
        Compute detJ, dV and, when requested, Jinv and Nx, Ny, Nz from J (in place).
        """

        cdef uint64_t a, r
        cdef list Nd = self._reference_derivatives()
        cdef list targets
        cdef object acc, term, s

        if self.ndim == 0:

            _fe_store(_fe_scalar(1.0, (), 0, self.nip), self.detJ)
            _fe_store(self.w.copy(), self.dV)

            return

        # end if

        if self.ndim == self.ndim_an:

            _fe_det(self.J, out=self.detJ)
            _fe_store(self.w * self.detJ, self.dV)

            if self.compute_Jinv:

                _fe_inv(self.J, out=self.Jinv)
                targets = [self.Nx, self.Ny, self.Nz]

                # Row a of Jinv maps the reference derivatives to d/dx_a.
                for a in range(self.ndim_an):

                    acc = self.Jinv[a, 0] * Nd[0]

                    for r in range(1, self.ndim):

                        acc = acc + self.Jinv[a, r] * Nd[r]

                    # end for

                    _fe_store(acc, targets[a])

                # end for

            # end if

        elif self.ndim == 1:

            # Line element in 2-D or 3-D: detJ = |dx/dxi|.
            s = self.J[0, 0] * self.J[0, 0]

            for a in range(1, self.ndim_an):

                s = s + self.J[0, a] * self.J[0, a]

            # end for

            _fe_store(s ** 0.5, self.detJ)
            _fe_store(self.w * self.detJ, self.dV)

        else:

            # Surface element in 3-D: detJ = |dx/dxi x dx/deta|.
            s = None

            for a in range(3):

                term = (self.J[0, (a + 1) % 3] * self.J[1, (a + 2) % 3]
                        - self.J[0, (a + 2) % 3] * self.J[1, (a + 1) % 3])
                s = term * term if s is None else s + term * term

            # end for

            _fe_store(s ** 0.5, self.detJ)
            _fe_store(self.w * self.detJ, self.dV)

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compute_jacobian(self):
        """
        Compute J, detJ, dV and (with compute_Jinv) Jinv and the spatial derivatives.

        J[r, c] is the dot product of the r-th reference derivative with the c-th coordinate column,
        one Gauss-by-plain SoA product per entry, batched over the points.
        """

        cdef uint64_t r, c
        cdef list Nd = self._reference_derivatives()
        cdef list X = [self.x, self.y, self.z]

        for r in range(self.ndim):

            for c in range(self.ndim_an):

                self.J[r, c] = _fe_dot_product(Nd[r], X[c])

            # end for

        # end for

        self._finish()

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def compute_jacobian_bruteforce(self):
        """
        Compute the same fields as compute_jacobian through a different path, for checking.

        J = G X with G the ndim x nbasis stack of reference derivatives (a Gauss array) and X the
        nbasis x ndim_an coordinate matrix (one Gauss-by-plain matrix product); the spatial
        derivatives are Jinv G (a Gauss-by-Gauss product).
        """

        cdef uint64_t r, c, i
        cdef list Nd = self._reference_derivatives()
        cdef list X = [self.x, self.y, self.z]
        cdef list targets
        cdef object G, XM, D

        if self.ndim == 0:

            self._finish()

            return

        # end if

        G  = _fe_zeros((self.ndim, self.nbasis), (), 0, self.nip)
        XM = oarrss.zeros((self.nbasis, self.ndim_an), order=max([x.order for x in X]))

        for r in range(self.ndim):

            G[r, :] = Nd[r]

        # end for

        for i in range(self.nbasis):

            for c in range(self.ndim_an):

                XM[i, c] = X[c][i, 0]

            # end for

        # end for

        _fe_store(_fe_dot(G, XM), self.J)

        if self.ndim == self.ndim_an and self.compute_Jinv:

            _fe_det(self.J, out=self.detJ)
            _fe_store(self.w * self.detJ, self.dV)
            _fe_inv(self.J, out=self.Jinv)

            D = _fe_dot(self.Jinv, G)
            targets = [self.Nx, self.Ny, self.Nz]

            for r in range(self.ndim_an):

                _fe_store(D[r, :], targets[r])

            # end for

        else:

            self._finish()

        # end if

    # end function
    # ----------------------------------------------------------------------------------------------------

    # ****************************************************************************************************
    def integrate(self, val, out=None):
        """
        Integrate over the element: the sum over points of dV_ip times val at ip.

        Parameters
        ----------
        val : ssotife or oarrssfe
            Integrand at the integration points.
        out : ssotinum or oarrss, optional
            Receives the result.

        Returns
        -------
        ssotinum or oarrss
            Integral.
        """

        return gauss_integrate(val, self.dV, out=out)

    # end function
    # ----------------------------------------------------------------------------------------------------

# end class
# --------------------------------------------------------------------------------------------------------
