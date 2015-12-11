#include <Python.h>
#include <bed.h>

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    bed_node node;
} bed_nodeObject;

static PyTypeObject bed_nodeType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "bed.Node",             /*tp_name*/
    sizeof(bed_nodeObject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    0,                         /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "bed_node objects",           /* tp_doc */
};

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    bed_var var;
} bed_varObject;

static PyTypeObject bed_varType = {
    PyObject_HEAD_INIT(NULL)
    0,                         /*ob_size*/
    "bed.Var",             /*tp_name*/
    sizeof(bed_varObject), /*tp_basicsize*/
    0,                         /*tp_itemsize*/
    0,                         /*tp_dealloc*/
    0,                         /*tp_print*/
    0,                         /*tp_getattr*/
    0,                         /*tp_setattr*/
    0,                         /*tp_compare*/
    0,                         /*tp_repr*/
    0,                         /*tp_as_number*/
    0,                         /*tp_as_sequence*/
    0,                         /*tp_as_mapping*/
    0,                         /*tp_hash */
    0,                         /*tp_call*/
    0,                         /*tp_str*/
    0,                         /*tp_getattro*/
    0,                         /*tp_setattro*/
    0,                         /*tp_as_buffer*/
    Py_TPFLAGS_DEFAULT,        /*tp_flags*/
    "bed_var objects",           /* tp_doc */
};




static PyObject *
pybed_init(PyObject *self, PyObject *args)
{
    unsigned long n, c;
    int sts;


    if (!PyArg_ParseTuple(args, "uu", &n, &c))
        return NULL;
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
    bed_init(10*1024*1024,5*1024*1024);

    PyObject *module = Py_InitModule("bed", pyBedMethods);
    Py_INCREF(bed_nodeType);
    PyModule_AddObject(module, "Node", bed_nodeType);
    Py_INCREF(bed_varType);
    PyModule_AddObject(module, "Var", bed_varType);
}
