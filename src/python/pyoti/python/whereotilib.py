## @package whereotilib.py
# The intention of this script is to provide the path to the location of the 
# otilib so that all files that will be loaded, can be loaded without path errors.

## @mainpage  OTI Number library spr_otinum
# Library to handle sparse Order Truncated Imaginary Numbers in Python, with a particular
# focus on automatic differentiation. \n\n
#
# <b> Current Version</b>: 0.1  \n
# <b> First Created</b>: 04/08/2017 \n
# <b> Last Modified</b>: 04/08/2017 \n
#
# <b>Contributors</b>: \n
# Mauricio Aristizabal Cano\n
# Applied Mechanics Research Group (Mecanica Aplicada) \n
# Universidad EAFIT, Medellín, Colombia.
#
# Manuel Julio Garcia Ruiz\n
# Applied Mechanics Research Group (Mecanica Aplicada) \n
# Universidad EAFIT, Medellín, Colombia.\n
# Department of Mechanical Engineering\n
# University of Texas at San Antonio, USA.



#-----------------------------------------------------------------------------------------------------
#---------------------------------   EXTERNAL LIBRARIES IMPORTS     ----------------------------------
#-----------------------------------------------------------------------------------------------------

import sys, os  					# System and OS tools.

#-----------------------------------------------------------------------------------------------------

#*****************************************************************************************************
def getpath():
	"""
    PURPOSE:      Provides the path of the directory where the otilib is located.

    EXAMPLE:      if the library is located in /dir/path/, the result is a string with '/dir/path/'
                  
    """
	#return repr(__file__)[1:-15]      # __file__ has the relative path to this file in the system.
	return repr(os.path.realpath(__file__))[1:-15]      # __file__ has the relative path to this file in the system.

#-----------------------------------------------------------------------------------------------------