from distutils.core import setup, Extension
import numpy.distutils.misc_util

bandinverse_c_ext = Extension(
    name="_bandinverse",
    sources=["_bandinverse.c"],
    extra_objects=["bandinverse.o"])
    #extra_link_args=["-lgsl -lm -lblas"])

setup(
    ext_modules=[bandinverse_c_ext],
    include_dirs=numpy.distutils.misc_util.get_numpy_include_dirs(),
)
