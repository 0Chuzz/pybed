#include <Python.h>
#include <bed.h>
#include <bedio.h>


typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    bed_var var;
} bed_varObject;
static int Var_init (bed_varObject * self, PyObject* args, PyObject *kwds)
{
    int var = -1;
    if (!PyArg_ParseTuple(args, "|i", &var)) return -1;
    if (var == -1)
        self->var = bed_new_variables(1);
    else
        self->var = var;
    return 0;
}

static PyTypeObject bed_varType = {
    PyObject_HEAD_INIT(&PyType_Type)
    .tp_name = "bedbindings.Var",                 /*tp_name*/
    .tp_basicsize = sizeof(bed_varObject),         /*tp_basicsize*/
    .tp_doc = "bed_var object",
    .tp_init = Var_init,
    .tp_flags = Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    .tp_new = PyType_GenericNew,
    //.tp_alloc = PyType_GenericAlloc
};


typedef struct {
    PyObject_HEAD
    /* Type-specific fields go here. */
    bed_node node;
} bed_nodeObject;
static PyTypeObject bed_nodeType;

static bed_nodeObject * makeNode(bed_node node)
{
    if (node == 0) return Py_None;
    bed_nodeObject *ret;
    ret = bed_nodeType.tp_new(&bed_nodeType, Py_None, Py_None);
    if (ret != NULL) ret->node = node;
    return ret;
}


static void Node_dealloc(bed_nodeObject *self)
{
    bed_deref(self->node);
    self->ob_type->tp_free(self);
}

static int Node_compare(bed_nodeObject *o1, bed_nodeObject *o2)
{
    if (o1->node < o2->node) return -1;
    else if (o1->node == o2 ->node) return 0;
    else return 1;
}

static PyObject *Node_get_var(bed_nodeObject *self, PyObject *_)
{
    bed_varObject *ret = bed_varType.tp_new(&bed_varType,
        Py_BuildValue("(i)", bed_get_var(self->node)), Py_None);

    return ret;
}
static PyObject *Node_get_op(bed_nodeObject *self, PyObject *_)
{
    return Py_BuildValue("i", bed_get_op(self->node));
}
static PyObject *Node_get_low(bed_nodeObject *self, PyObject *_)
{
    return makeNode(bed_get_low(self->node));
}
static PyObject *Node_get_high(bed_nodeObject *self, PyObject *_)
{
    return makeNode(bed_get_high(self->node));
}

static PyObject *Node_write_graph(bed_nodeObject *self, PyObject *args)
{
    char *filename;
    if (!PyArg_ParseTuple(args, "s", &filename))
        return NULL;
    FILE *fout = fopen(filename, "w");
    if (!fout) return NULL;
    bed_io_root_entry nodes = {
        "test", self->node, NULL
    };
    bed_io_write(fout, &nodes);
    fclose(fout);
    return Py_None;
}

static PyMethodDef Node_methods[] = {
    {"get_var", (PyCFunction)Node_get_var, METH_NOARGS, ""},
    {"get_op", (PyCFunction)Node_get_op, METH_NOARGS, ""},
    {"get_low", (PyCFunction)Node_get_low, METH_NOARGS, ""},
    {"get_high", (PyCFunction)Node_get_high, METH_NOARGS, ""},
    {"write_graph", (PyCFunction)Node_write_graph, METH_VARARGS, ""},
    {NULL}
};

static PyTypeObject bed_nodeType = {
    PyObject_HEAD_INIT(&PyType_Type)
    .tp_name = "bedbindings.Node",                 /*tp_name*/
    .tp_basicsize = sizeof(bed_nodeObject),         /*tp_basicsize*/
    .tp_flags = Py_TPFLAGS_DEFAULT,            /*tp_flags*/
    .tp_doc = "bed_node objects",               /* tp_doc */
    .tp_new = PyType_GenericNew,
    .tp_alloc = PyType_GenericAlloc,
    .tp_compare = Node_compare,
    .tp_methods = Node_methods
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
    return ret;
}

static PyObject *
pybed_read_file(PyObject *self, PyObject* args)
{
    char *fname;
    if (!PyArg_ParseTuple(args, "s", &fname)) return NULL;

    bed_io_read_info *result = bed_io_read(fname);
    if (!result) return NULL;

    bed_io_root_entry *head = result->roots;
     {
        bed_nodeObject *ret;
        ret = bed_nodeType.tp_new(&bed_nodeType, Py_None, Py_None);
        ret->node = head->root;
        return ret;
    }

    bed_nodeObject *ret;
    ret = bed_nodeType.tp_new(&bed_nodeType, Py_None, Py_None);
    if (ret == NULL) return NULL;
    return ret;
}

static PyMethodDef pyBedMethods[] = {

    {"mk_op",  pybed_mk_op, METH_VARARGS,
     "generic operation node"},
    {"mk_var",  pybed_mk_var, METH_VARARGS,
      "variable node"},
      {"read_file", pybed_read_file, METH_VARARGS, ""},
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
