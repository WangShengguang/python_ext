#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Python.h"

int fac(int n) {
    if (n < 2)
        return (1);
    return n * fac(n - 1);
}

char *reverse(char *s) {
    register char t, *p = s, *q = (s + (strlen(s) - 1));
    while (p < q) {
        t = *p;
        *p++ = *q;
        *q-- = t;
    }
    return s;
}

static PyObject *Extest_fac(PyObject *self, PyObject *args) {
    int num;
    if (!PyArg_ParseTuple(args, "i", &num)) {   //TypeError
        return NULL;
    }
    return (PyObject *) Py_BuildValue("i", fac(num));
}

static PyObject *Extest_doppel(PyObject *self, PyObject *args) {
    char *orig_str, *dupe_str;
    PyObject *retval;
    if (!PyArg_ParseTuple(args, "s", &orig_str)) return NULL;
    retval = (PyObject *) Py_BuildValue("ss", orig_str, dupe_str = reverse(strdup(orig_str)));
    free(dupe_str);
    return retval;
}

static PyMethodDef ExtestMethods[] = {
        {"fac",    Extest_fac,    METH_VARARGS},
        {"doppel", Extest_doppel, METH_VARARGS},
        {NULL, NULL},
};

#if PY_MAJOR_VERSION >= 3

static struct PyModuleDef Extest =
{
    PyModuleDef_HEAD_INIT,
    "Extest", /* name of module */
    "Extest doc",/* module documentation, may be NULL */
    -1, /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    ExtestMethods
};

PyMODINIT_FUNC PyInit_Extest()
{
    return PyModule_Create(&Extest);
}
#else

PyMODINIT_FUNC initExtest() {
    (void) Py_InitModule("Extest", ExtestMethods);
}

#endif
