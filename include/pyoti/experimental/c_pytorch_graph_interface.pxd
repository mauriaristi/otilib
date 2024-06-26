from pyoti.c_otilib cimport * 


# define external fortran wrapper call.
cdef extern from "oti/experimental.h" nogil:
	void pytorch_graph_eval_m1n1(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm1n1_t* x_matso, oarrm1n1_t* res_matso);

	void pytorch_graph_eval_m1n2(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm1n2_t* x_matso, oarrm1n2_t* res_matso);

	void pytorch_graph_eval_m1n3(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm1n3_t* x_matso, oarrm1n3_t* res_matso);

	void pytorch_graph_eval_m1n4(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm1n4_t* x_matso, oarrm1n4_t* res_matso);

	void pytorch_graph_eval_m2n1(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm2n1_t* x_matso, oarrm2n1_t* res_matso);

	void pytorch_graph_eval_m2n2(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm2n2_t* x_matso, oarrm2n2_t* res_matso);

	void pytorch_graph_eval_m2n3(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm2n3_t* x_matso, oarrm2n3_t* res_matso);

	void pytorch_graph_eval_m2n4(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm2n4_t* x_matso, oarrm2n4_t* res_matso);

	void pytorch_graph_eval_m3n1(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm3n1_t* x_matso, oarrm3n1_t* res_matso);

	void pytorch_graph_eval_m3n2(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm3n2_t* x_matso, oarrm3n2_t* res_matso);

	void pytorch_graph_eval_m3n3(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm3n3_t* x_matso, oarrm3n3_t* res_matso);


	void pytorch_graph_eval_m3n4(int64_t* graph, int* stack_size, 
		double* c_arr, int* c_size,
		oarrm3n4_t* x_matso, oarrm3n4_t* res_matso);