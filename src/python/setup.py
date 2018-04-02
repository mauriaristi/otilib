# from distutils.core import setup
# from Cython.Build import cythonize
# import numpy


# setup(
#     # ext_modules = cythonize("otilib.pyx"),
#     # ext_modules = cythonize("oticore.pyx"),
#     ext_modules = cythonize("otinum.pyx"),
#     # ext_modules = cythonize("ndarray.pyx"),
#  	include_dirs=[numpy.get_include()]
# )







# # build script for 'otilib' - Python libdv wrapper

# # change this as needed
# # libdvIncludeDir = "/usr/include/libdv"

import sys, os
from distutils.core import setup
from distutils.extension import Extension
import numpy 

# we'd better have Cython installed, or it's a no-go
try:
    from Cython.Distutils import build_ext 
    from Cython.Build import cythonize
except:
    print("You don't seem to have Cython installed. Please get a")
    print("copy from www.cython.org and install it")
    sys.exit(1)


# # scan the 'cyt1' directory for extension files, converting
# # them to extension names in dotted notation
# def scandir(dir, files=[]):
#     for file in os.listdir(dir):
#         path = os.path.join(dir, file)
#         if os.path.isfile(path) and path.endswith(".pyx"):
#             files.append(path.replace(os.path.sep, ".")[:-4])
#         elif os.path.isdir(path):
#             scandir(path, files)
#     return files


# # generate an Extension object from its dotted name
# def makeExtension(extName):
#     extPath = extName.replace(".", os.path.sep)+".pyx"
#     return Extension(
#         extName,
#         [extPath],
#         include_dirs = [numpy.get_include(), "."],   # adding the '.' to include_dirs is CRUCIAL!!
#         )

# # get the list of extensions
# extNames = scandir("otilib")
# print("\nFound the following names:\n")
# print(extNames)

# # and build up the set of Extension objects
# extensions = [makeExtension(name) for name in extNames]

# finally, we can pass all this to distutils
setup(
  # name="otilib",
  # packages=["otilib", "otilib.oticore", "otilib.otinum","otilib.ndarray"],
  # ext_modules=extensions,
  # cmdclass = {'build_ext': build_ext},
  ext_modules  = cythonize('*.pyx'),
  include_dirs = [numpy.get_include(),"."]
)











