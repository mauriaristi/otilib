
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

# finally, we can pass all this to distutils
setup(
  name="OTILIB",
  # packages=["otilib", "otilib.oticore", "otilib.otinum","otilib.ndarray"],
  # ext_modules=extensions,
  # cmdclass = {'build_ext': build_ext},
  # ext_modules = cythonize(module),
  ext_modules  = cythonize('*.pyx',   include_path=["../../include/"]),
  # build_dir    = "../../build/lib",
  # extra_compile_args = ["-arch i386 -arch x86_64"],
  include_dirs = [numpy.get_include(), "../../include/","."],
  # libraries    = [("oti"),("otifem")],
  # library_dirs = ["../../build/lib"]
)

# CFLAGS="-I../../include"  \
# LDFLAGS="-L../../build/lib"     \
# python3 setup.py build_ext -i