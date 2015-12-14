#include <Python.h>
#include <bed.h>

typedef struct {
        PyObject_HEAD
        /* Type-specific fields go here. */
        bed_node node;
        PyObject *lowRef, *hiRef;
} bed_nodeObject;

static PyObject* Node_new (PyTypeObject * type, PyObject* args, PyObject *kwds)
{
        bed_nodeObject *self;
        self = type->tp_alloc(type, 0);
        int size;
        if (!PyArg_ParseTupleAndKeywords(args, kwds, "d", "", &size)) return NULL;
        //bed_mk();
        return NULL; //TODO

}

static PyTypeObject bed_nodeType = {
        PyObject_HEAD_INIT(&PyType_Type)
        .tp_name = "bed.Node",         /*tp_name*/
        .tp_basicsize = sizeof(bed_nodeObject), /*tp_basicsize*/
        .tp_flags = Py_TPFLAGS_DEFAULT,    /*tp_flags*/
        .tp_doc = "bed_node objects",       /* tp_doc */
        .tp_new = Node_new
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

        if (!PyArg_ParseTupleAndKeywords(args, kwds, "", "", &size))
                return NULL;
        self = type->tp_alloc(type, 0);
        self->var = bed_new_variables(size);
        self->size = size;
        return self;

}

static PyTypeObject bed_varType = {
        PyObject_HEAD_INIT(&PyType_Type)
        .tp_name = "bed.Var",         /*tp_name*/
        .tp_basicsize = sizeof(bed_varObject), /*tp_basicsize*/
        .tp_doc = "bed_var object",
        .tp_new = Var_new,
};




static PyObject *
pybed_not(PyObject *self, PyObject *args)
{
        bed_nodeObject *base,*ret;
        int sts;


        if (!PyArg_ParseTuple(args, "O!", &bed_varType, &base))
                return NULL;

        ret = bed_nodeType.tp_new(&bed_nodeType, Py_None, Py_None);
        if (ret == NULL) return NULL;
        ret->node = bed_mk_not(base->node);
        ret->lowRef = base;
        ret->hiRef = NULL;
        Py_INCREF(base);
        return ret;
}
static PyMethodDef pyBedMethods[] = {

        {"not",  pybed_not, METH_VARARGS,
         "not"},
        {NULL, NULL, 0, NULL}    /* Sentinel */
};

PyMODINIT_FUNC
initbed(void)
{
        if (PyType_Ready(&bed_nodeType) < 0) return;
        if (PyType_Ready(&bed_varType) < 0) return;


        bed_init(10*1024,5*1024);

        PyObject *module = Py_InitModule("bed", pyBedMethods);
        Py_INCREF(&bed_nodeType);
        PyModule_AddObject(module, "Node", &bed_nodeType);
        Py_INCREF(&bed_varType);
        PyModule_AddObject(module, "Var", &bed_varType);
}
