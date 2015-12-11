#include <Python.h>
#include <bed.h>




static PyObject *
pybed_init(PyObject *self, PyObject *args)
{
    unsigned long n, c;
    int sts;


    if (!PyArg_ParseTuple(args, "uu", &n, &c))
        return NULL;
    bed_init(n,c);
    return Py_None;
}
static PyMethodDef pyBedMethods[] = {

    {"init",  pybed_init, METH_VARARGS,
     "bed_init"},
    {NULL, NULL, 0, NULL}        /* Sentinel */
};

PyMODINIT_FUNC
initbed(void)
{
    (void) Py_InitModule("bed", pyBedMethods);
}
