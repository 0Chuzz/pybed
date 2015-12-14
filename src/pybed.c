#include <Python.h>
#include <bed.h>

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    bed_node node;
    PyObject *lowRef, *hiRef;
} bed_nodeObject;


static void Node_dealloc(bed_nodeObject *self)
{
    Py_XDECREF(self->lowRef);
    Py_XDECREF(self->hiRef);
}

static PyTypeObject bed_nodeType = {
    PyObject_HEAD_INIT(&PyType_Type)
    .tp_name = "bedbindings.Node",                 /*tp_name*/
    .tp_basicsize = sizeof(bed_nodeObject),         /*tp_basicsize*/
    .tp_flags = Py_TPFLAGS_DEFAULT,            /*tp_flags*/
    .tp_doc = "bed_node objects",               /* tp_doc */
    .tp_new = PyType_GenericNew,
    .tp_alloc = PyType_GenericAlloc
};

typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    bed_var var;
    unsigned int size;
} bed_varObject;
static PyObject* Var_new (PyTypeObject * type, PyObject* args, PyObject *kwds)
{
    bed_varObject *self;
    int size = 1;

    self = type->tp_alloc(type, 0);
    self->var = bed_new_variables(size);
    self->size = size;
    return self;

}

static PyTypeObject bed_varType = {
    PyObject_HEAD_INIT(&PyType_Type)
    .tp_name = "bedbindings.Var",                 /*tp_name*/
    .tp_basicsize = sizeof(bed_varObject),         /*tp_basicsize*/
    .tp_doc = "bed_var object",
    .tp_new = Var_new,
    .tp_alloc = PyType_GenericAlloc
};


static PyObject *
pybed_mk_op(PyObject *self, PyObject *args)
{
    bed_nodeObject *base1, *base2,*ret;
    int op;

    if (!PyArg_ParseTuple(args, "iO!O!", &op, &bed_nodeType, &base1, &bed_nodeType, &base2))
        return NULL;

    ret = bed_nodeType.tp_new(&bed_nodeType, Py_None, Py_None);
    if (ret == NULL) return NULL;
    ret->node = bed_ref(bed_mk_op(op,base1->node, base2->node));
    ret->lowRef = base1;
    ret->hiRef = base2;
    Py_INCREF(base1);
    Py_INCREF(base2);
    return ret;
}

static PyObject *
pybed_mk_var(PyObject *self, PyObject *args)
{
    bed_nodeObject *ret;
    bed_varObject *base;
    int sts;

    if (!PyArg_ParseTuple(args, "O!", &bed_varType, &base))
        return NULL;

    ret = bed_nodeType.tp_new(&bed_nodeType, Py_None, Py_None);
    if (ret == NULL) return NULL;
    ret->node = bed_ref(bed_mk_var(base->var, bed_false, bed_true));
    ret->lowRef = (PyObject *) base;
    ret->hiRef = NULL;
    Py_INCREF(base);
    return ret;
}

static PyMethodDef pyBedMethods[] = {

    {"mk_op",  pybed_mk_op, METH_VARARGS,
     "generic operation node"},
    {"mk_var",  pybed_mk_var, METH_VARARGS,
      "variable node"},
    {NULL, NULL, 0, NULL}            /* Sentinel */
};


PyMODINIT_FUNC
initbedbindings(void)
{
    if (PyType_Ready(&bed_nodeType) < 0) return;
    if (PyType_Ready(&bed_varType) < 0) return;


    bed_init(10*1024,5*1024);

    PyObject *module = Py_InitModule("bedbindings", pyBedMethods);
    Py_INCREF(&bed_nodeType);
    PyModule_AddObject(module, "Node", &bed_nodeType);
    Py_INCREF(&bed_varType);
    PyModule_AddObject(module, "Var", &bed_varType);
}
