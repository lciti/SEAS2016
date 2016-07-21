//#include <stdio.h>
#include <Python.h>
#include <numpy/arrayobject.h>
#include "bandinverse.h"

/* Docstrings */
static char module_docstring[] =
    "This module provides an interface for computing the inverse of a symmetric banded matrix.";
static char sample_gig_docstring[] =
    "Compute the inverse of a symmetric banded matrix";

/* Available functions */
static PyObject *bandinv_bandinverse(PyObject *self, PyObject *args);

/* Module specification */
static PyMethodDef module_methods[] = {
    {"bandinv", bandinv_bandinverse, METH_VARARGS, sample_gig_docstring},
    {NULL, NULL, 0, NULL}
};


/* Initialize the module */
//extern "C" {

PyMODINIT_FUNC init_bandinverse(void)
{
  PyObject *m = Py_InitModule3("_bandinverse", module_methods, module_docstring);
  if (m == NULL)
      return;

  /* Load `numpy` functionality. */
  import_array();
}

//}

//void sample_gig(double* p,double* a,double* b,double* x,int n,unsigned long *seed)


static PyObject *bandinv_bandinverse(PyObject *self, PyObject *args)
{
    int M, N, Psize;
    PyObject *U_obj;
    PyArrayObject *P_array;
    double* P;


    /* Parse the input tuple */
    if (!PyArg_ParseTuple(args, "Oii", &U_obj, &M, &N))
        return NULL;

    /* Interpret the input objects as numpy arrays. */
    PyObject *U_array = PyArray_FROM_OTF(U_obj, NPY_DOUBLE, NPY_IN_ARRAY);

    /* If that didn't work, throw an exception. */
    if (U_array == NULL) {
        Py_XDECREF(U_array);
        return NULL;
    }

    /* Get pointers to the data as C-types. */
    double *U    = (double*)PyArray_DATA(U_array);

    /* Create array to store output */
    Psize = (M+1)*N;
    P_array = (PyArrayObject*) PyArray_FromDims(1, &Psize, NPY_DOUBLE);

    /* Access pointer to first element of data */
    P = (double *) P_array->data;
    //pyvector_to_Carrayptrs(x_array);

    /* Call the external C function to compute banded inverse. */
    bandinverse(P, U, M, N);

    /* Clean up. */
    Py_DECREF(U_array);

    /* Build the output tuple */
    //PyObject *ret = Py_BuildValue("d", value);
    return Py_BuildValue("O",P_array);

}

//double *pyvector_to_Carrayptrs(PyArrayObject *arrayin)  {
//  int n=arrayin->dimensions[0];
//  return (double *) arrayin->data;  /* pointer to arrayin data as double */
//}
