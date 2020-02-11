




# This library will aim to generate Fortran code to support DENSE oti numbers in fortran.






class otiwriter:

	def __init__(self, language="fortran", n = 1, m = 1, matrix_operations = True, sparse = False):

		self.matops_flag = matrix_operations
		self.lang   = language
		self.torder = n
		self.nbases = m
	#

	#
	def write(self):
		"""
		PORPUSE:

		INPUTS:

		OUTPUTS:

		"""

		# First write the type

		





