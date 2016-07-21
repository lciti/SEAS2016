# SEAS2016
Research visit at Harvard SEAS with Dr Ba


## Building Python C extension of Luca's algorithm for computing inverse of a banded matrix

1. Use Makefile to generate `bandinverse.o` (object file corresponding to C version of Luca's code)

2. The Python C extension will build a module `_bandinverse` that can be imported as one would any Python module

 * Compile the C extension as follows  `python setup.py build_ext --inplace`, which will generate the module

 * The `_bandinverse` module has one function `bandinv` that takes in arguments in the same format as Luca's C code.

  * Test the function as follows

3. Testing the code on a simple 3 by 3 matrix with bandwidth 2 (only one off diagonal):
 ```python
 import _bandinverse
 U = np.array([0,1.0,0.7,1.0,0.7,1.0])
 M, N = 2, 3
 U.reshape(M,N,order='Fortran')
 P =  _bandinverse.bandinv(U,M,N)

 ```
