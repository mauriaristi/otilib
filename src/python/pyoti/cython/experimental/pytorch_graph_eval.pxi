
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

	if   type_xin is oti_m1n1.omatm1n1:

		w = pytorch_agraph_eval_m1n1( graph, x_in, c)

	elif type_xin is oti_m1n2.omatm1n2:

		w = pytorch_agraph_eval_m1n2( graph, x_in, c)

	elif type_xin is oti_m1n3.omatm1n3:

		w = pytorch_agraph_eval_m1n3( graph, x_in, c)

	elif type_xin is oti_m1n4.omatm1n4:

		w = pytorch_agraph_eval_m1n4( graph, x_in, c)

	elif type_xin is oti_m2n1.omatm2n1:

		w = pytorch_agraph_eval_m2n1( graph, x_in, c)

	elif type_xin is oti_m2n2.omatm2n2:

		w = pytorch_agraph_eval_m2n2( graph, x_in, c)

	elif type_xin is oti_m2n3.omatm2n3:

		w = pytorch_agraph_eval_m2n3( graph, x_in, c)

	elif type_xin is oti_m2n4.omatm2n4:

		w = pytorch_agraph_eval_m2n4( graph, x_in, c)

	elif type_xin is oti_m3n1.omatm3n1:

		w = pytorch_agraph_eval_m3n1( graph, x_in, c)

	elif type_xin is oti_m3n2.omatm3n2:

		w = pytorch_agraph_eval_m3n2( graph, x_in, c)

	elif type_xin is oti_m3n3.omatm3n3:

		w = pytorch_agraph_eval_m3n3( graph, x_in, c)

	elif type_xin is oti_m3n4.omatm3n4:

		w = pytorch_agraph_eval_m3n4( graph, x_in, c)

	else:

		return NotImplemented

	# end if

	return w


def pytorch_agraph_eval_m1n1( graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m1n1.omatm1n1 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m1n1.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m1n1(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]

def pytorch_agraph_eval_m1n2(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m1n2.omatm1n2 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m1n2.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m1n2(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)
	return w[stack_size-1,:]

def pytorch_agraph_eval_m1n3(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m1n3.omatm1n3 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m1n3.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m1n3(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]

def pytorch_agraph_eval_m1n4(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m1n4.omatm1n4 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m1n4.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m1n4(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]


def pytorch_agraph_eval_m2n1(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m2n1.omatm2n1 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m2n1.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m2n1(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]


def pytorch_agraph_eval_m2n2(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m2n2.omatm2n2 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m2n2.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m2n2(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]


def pytorch_agraph_eval_m2n3(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m2n3.omatm2n3 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m2n3.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m2n3(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]

def pytorch_agraph_eval_m2n4(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m2n4.omatm2n4 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m2n4.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m2n4(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]

def pytorch_agraph_eval_m3n1(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m3n1.omatm3n1 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m3n1.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m3n1(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]

def pytorch_agraph_eval_m3n2(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m3n2.omatm3n2 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m3n2.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m3n2(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]

def pytorch_agraph_eval_m3n3(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m3n3.omatm3n3 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m3n3.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m3n3(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]


def pytorch_agraph_eval_m3n4(graph, x_in, c):
	"""
	@brief Evaluate pytorch graph.

	@param[in] graph: numpy array of int64 of shape (stack_size,3) containing the graph
	    following pytorch graph format.
	@param[in] x: omatm1n1 array of shape (nvars,neval_points) containing the points at which
		the graph should be evaluated.
	@param[in] c: numpy array of doubles with the constants of the evaluation.

	@returns This function returns an omatm1n1 of shape (stack_size,neval_points) with the graph's
		intermediate evaluations.
	"""

	# TODO: Verify that all inputs have consistent dimensions.
	# TODO: Verify that the input data types are consistent.
	# TODO: Verfy that the arrays come contigous (numpy arrays in specific.)
	cdef int stack_size, neval_points, nconst, nvars
	# cdef np.ndarray[np.int64_t,ndim=2] graph = graph_in
	# cdef np.ndarray[double,ndim=1] c = c_in
	cdef np.int64_t[:,::1] graph_buff = graph#np.ascontiguousarray(graph, dtype = np.int64)
	cdef np.float64_t[::1] c_buff = c #np.ascontiguousarray(c, dtype = np.float64)
	cdef int64_t* graph_ptr
	cdef double* c_arr_ptr
	cdef oti_m3n4.omatm3n4 x, w
	x = x_in
	stack_size = graph.shape[0]
	neval_points = x.shape[1]
	nconst = c.size

	w = oti_m3n4.zeros((stack_size,neval_points))
	
	graph_ptr = &graph_buff[0,0]
	c_arr_ptr = &c_buff[0]


	pytorch_graph_eval_m3n4(graph_ptr,&stack_size, 
		c_arr_ptr,&nconst,
		&x.arr,&w.arr)
	# print(w)


	return w[stack_size-1,:]
