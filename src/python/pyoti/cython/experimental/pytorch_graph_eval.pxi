
# Add interface to wrapper function
# I am c-importing a library wrapper function. 


def pytorch_agraph_eval( graph, x_in, c):
    """
    pytorch_agraph_eval( graph, x_in, c):

    Evaluate pytorch graph.

    :param graph: numpy array of int64 of shape (stack_size,3) containing the graph
        following pytorch graph format.
    :param x_in: static omatm<x>n<y> array of shape (nvars,neval_points) containing the points at which
        the graph should be evaluated.
    :param c: numpy array of doubles with the constants of the evaluation.

    :returns : This function returns a statuc omatm<x>n<y> of shape (stack_size,neval_points) with the graph's
        intermediate evaluations.
    """

    type_xin = type(x_in)

    if   type_xin is otispr.matso :
        
        w = pytorch_agraph_eval_matso( graph, x_in, c)

    # elif type_xin is oti_m1n1.omatm1n1:

    #     w = pytorch_agraph_eval_m1n1( graph, x_in, c)

    # elif type_xin is oti_m1n2.omatm1n2:

    #     w = pytorch_agraph_eval_m1n2( graph, x_in, c)

    # elif type_xin is oti_m1n3.omatm1n3:

    #     w = pytorch_agraph_eval_m1n3( graph, x_in, c)

    # elif type_xin is oti_m1n4.omatm1n4:

    #     w = pytorch_agraph_eval_m1n4( graph, x_in, c)

    # elif type_xin is oti_m2n1.omatm2n1:

    #     w = pytorch_agraph_eval_m2n1( graph, x_in, c)

    # elif type_xin is oti_m2n2.omatm2n2:

    #     w = pytorch_agraph_eval_m2n2( graph, x_in, c)

    # elif type_xin is oti_m2n3.omatm2n3:

    #     w = pytorch_agraph_eval_m2n3( graph, x_in, c)

    # elif type_xin is oti_m2n4.omatm2n4:

    #     w = pytorch_agraph_eval_m2n4( graph, x_in, c)

    # elif type_xin is oti_m3n1.omatm3n1:

    #     w = pytorch_agraph_eval_m3n1( graph, x_in, c)

    # elif type_xin is oti_m3n2.omatm3n2:

    #     w = pytorch_agraph_eval_m3n2( graph, x_in, c)

    # elif type_xin is oti_m3n3.omatm3n3:

    #     w = pytorch_agraph_eval_m3n3( graph, x_in, c)

    # elif type_xin is oti_m3n4.omatm3n4:

    #     w = pytorch_agraph_eval_m3n4( graph, x_in, c)

    else:

        return NotImplemented

    # end if

    return w


def pytorch_agraph_eval_matso( graph, x_in, c):
    """
    @brief Evaluate pytorch graph with a matso array.

    @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
        following pytorch graph format.
    @param[in] x: matso array of shape (neval_points,nvars) containing the points at which
        the graph should be evaluated.
    @param[in] c: numpy array of doubles with the constants of the evaluation.

    @returns This function returns a matso array of shape (1,neval_points) with the graph's
        intermediate evaluations.
    """

    cdef int stack_size, neval_points, nconst, nvars, nthreads
    
    cdef np.int64_t[:,:] graph_buff = graph
    cdef np.float64_t[:] c_buff = c # not necessary to be c-contiguous. 
    
    cdef np.int64_t it1, it2, node, i_op, i_trpt, i

    cdef otispr.matso x, w, y

    cdef sotinum_t* p_tmpi 
    cdef sotinum_t* p_x1 
    cdef sotinum_t* p_x2
    cdef sotinum_t tmp2
    cdef arrso_t *w_all, wi
    
    
    x = x_in
    
    stack_size = graph.shape[0]
    neval_points = x.shape[0]
    nvars        = x.shape[1] # 
    nconst = c.size

    nthreads = omp_get_num_procs()
    w_all = <arrso_t *>malloc(nthreads*sizeof(arrso_t))

    active_temp_arrs = []
    
    # # Temporal array for a single operator evaluation.
    # for i in range(nthreads):

    #     w = otispr.zeros((stack_size,1))#,nbases=neval_points,order=x.order)
    #     w_all[i] = w.arr
    #     active_temp_arrs.append(w)

    # # end for 

    w = otispr.zeros((stack_size,1))#,nbases=neval_points,order=x.order)
    wi = w.arr
    
    # Preallocate output array.
    y = otispr.zeros((neval_points,1))
    
    for i_trpt in range(neval_points): 
    # for i_trpt in prange(neval_points, nogil=True): 
        
        # wi = w_all[omp_get_thread_num()]

        # Evaluate single item
        for i_op in range(stack_size):
            
            # Get operator
            node  = graph_buff[i_op,0]
            it1   = graph_buff[i_op,1]
            it2   = graph_buff[i_op,2]

            # Get temporal from w, unsafe but avoids reallocations in the future.
            p_tmpi = &wi.p_data[i_op]

            if   node == -1: # What is this operation?
                
                soti_set_r(it1, p_tmpi, dhl)

            elif node ==  0: # Load variable, tmpi = x[i_trpt, it1]
                
                p_x1 = &x.arr.p_data[ i_trpt*x.arr.ncols + it1]
                # j + i*arr->ncols
                
                # set tmp from read item
                soti_set_o(p_x1, p_tmpi, dhl)
                
                # If perturbations are to be added, this is the moment.

            elif node ==  1: # Set from constant, tmpi = c[it1]

                # Unsafe for c_buff. Careful
                soti_set_r(c_buff[it1], p_tmpi, dhl)

            elif node ==  2: # Add tmpi = x1 + x2
                
                p_x1 = &wi.p_data[it1]
                p_x2 = &wi.p_data[it2]
                
                soti_sum_oo_to(p_x1,p_x2,p_tmpi,dhl)

            elif node ==  3: # Sub tmpi = x1 - x2

                p_x1 = &wi.p_data[it1]
                p_x2 = &wi.p_data[it2]
                
                soti_sub_oo_to(p_x1,p_x2,p_tmpi,dhl)

            elif node ==  4: # Multiply tmpi = x1 * x2
                
                p_x1 = &wi.p_data[it1]
                p_x2 = &wi.p_data[it2]
                
                soti_mul_oo_to(p_x1,p_x2,p_tmpi,dhl)

            elif node ==  5: # Divide tmpi = x1 / x2

                p_x1 = &wi.p_data[it1]
                p_x2 = &wi.p_data[it2]
                
                soti_div_oo_to(p_x1,p_x2,p_tmpi,dhl)

            elif node ==  6: # Sine tmpi = sin(x1)

                p_x1 = &wi.p_data[it1]
                
                soti_sin_to(p_x1,p_tmpi,dhl)

            elif node ==  7: # Cosine tmpi = cos(x1)

                p_x1 = &wi.p_data[it1]
                
                soti_cos_to(p_x1,p_tmpi,dhl)

            elif node ==  8: # Exp tmpi = exp(x1)

                p_x1 = &wi.p_data[it1]
                
                soti_exp_to(p_x1,p_tmpi,dhl)

            elif node ==  9: # Log tmpi = log(x1)

                p_x1 = &wi.p_data[it1]
                
                soti_log_to(p_x1,p_tmpi,dhl)

            elif node == 10: # power tmpi = x1 ** x2

                p_x1 = &wi.p_data[it1]
                p_x2 = &wi.p_data[it2]
                
                soti_pow_soti_to(p_x1,p_x2,p_tmpi,dhl)

            elif node == 11: # abs tmpi = abs(x1)

                p_x1 = &wi.p_data[it1]
                
                soti_abs_to(p_x1,p_tmpi,dhl)

            elif node == 12: # sqrt(abs()) tmpi = sqrt(abs(x1))

                p_x1 = &wi.p_data[it1]
                tmp2 = soti_get_rtmp(10, p_x1[0].trc_order, dhl)
                
                soti_abs_to(p_x1,&tmp2,dhl)
                soti_sqrt_to(&tmp2,p_tmpi,dhl)
            
            elif node == 13: # abs power tmpi = (abs(x1))**x2

                p_x1 = &wi.p_data[it1]
                p_x2 = &wi.p_data[it2]

                tmp2 = soti_get_rtmp(10, p_x1[0].trc_order, dhl)

                soti_abs_to( p_x1, &tmp2, dhl)
                soti_pow_soti_to( &tmp2, p_x2, p_tmpi, dhl)
            
            elif node == 14: # hyp. sine   tmpi = sinh(x1)

                p_x1 = &wi.p_data[it1]
                
                soti_sinh_to( p_x1, p_tmpi, dhl)
            
            elif node == 15: # hyp. cosine tmpi = cosh(x1)

                p_x1 = &wi.p_data[it1]
                
                soti_cosh_to( p_x1, p_tmpi, dhl)

            else:
                # with gil:
                    raise IndexError(f"Node value {node} unrecognized") 

            # end if 
            
        # end for  (i_op)
            
        # The last tmpi contains the "solution"
        # Set the tmpi item to the corresponding location of the output array.
        # y[i_trpt,0] = tmpi
        #                    &tmpi  [   i ,  j]   y 
        arrso_set_item_ij_o( p_tmpi, i_trpt, 0, &y.arr, dhl)

    # end for  (i_trpt)

    free(w_all)

    return y

# end function


# def pytorch_agraph_eval_m1n1( graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m1n1.omatm1n1 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m1n1.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m1n1(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]

# # end function

# def pytorch_agraph_eval_m1n2(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m1n2.omatm1n2 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m1n2.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m1n2(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)
#     return w[stack_size-1,:]

# def pytorch_agraph_eval_m1n3(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m1n3.omatm1n3 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m1n3.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m1n3(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]

# def pytorch_agraph_eval_m1n4(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m1n4.omatm1n4 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m1n4.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m1n4(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]


# def pytorch_agraph_eval_m2n1(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m2n1.omatm2n1 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m2n1.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m2n1(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]


# def pytorch_agraph_eval_m2n2(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m2n2.omatm2n2 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m2n2.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m2n2(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]


# def pytorch_agraph_eval_m2n3(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m2n3.omatm2n3 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m2n3.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m2n3(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]

# def pytorch_agraph_eval_m2n4(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m2n4.omatm2n4 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m2n4.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m2n4(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]

# def pytorch_agraph_eval_m3n1(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m3n1.omatm3n1 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m3n1.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m3n1(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]

# def pytorch_agraph_eval_m3n2(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m3n2.omatm3n2 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m3n2.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m3n2(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]

# def pytorch_agraph_eval_m3n3(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m3n3.omatm3n3 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m3n3.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m3n3(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]


# def pytorch_agraph_eval_m3n4(graph, x_in, c):
#     """
#     @brief Evaluate pytorch graph.

#     @param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
#         following pytorch graph format.
#     @param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
#         the graph should be evaluated.
#     @param[in] c: numpy array of doubles with the constants of the evaluation.

#     @returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
#         intermediate evaluations.
#     """

#     # TODO: Verify that all inputs have consistent dimensions.
#     # TODO: Verify that the input data types are consistent.
#     # TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
#     cdef int stack_size, neval_points, nconst, nvars
#     # cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
#     # cdef np.ndarray[double,ndim=1] c = c_in
#     cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
#     cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
#     cdef int64_t* graph_ptr
#     cdef double* c_arr_ptr
#     cdef oti_m3n4.omatm3n4 x, w
#     x = x_in
#     stack_size = graph.shape[0]
#     neval_points = x.shape[1]
#     nconst = c.size

#     w = oti_m3n4.zeros((stack_size,neval_points))
    
#     graph_ptr = &graph_buff[0,0]
#     c_arr_ptr = &c_buff[0]


#     pytorch_graph_eval_m3n4(graph_ptr,&stack_size, 
#         c_arr_ptr,&nconst,
#         &x.arr,&w.arr)
#     # print(w)


#     return w[stack_size-1,:]
