/* BED reduction tables -- computer generated file : DO NOT EDIT */

#include "tables.h"
#include "op.h"

Op symmetric_operator_array[] = {
 NOP,  /* Dummy row */
 K0,  /* K0 */
 PI2,  /* PI1 */
 PI1,  /* PI2 */
 NOR,  /* NOR */
 NIMP,  /* NLIMP */
 NPI2,  /* NPI1 */
 NLIMP,  /* NIMP */
 NPI1,  /* NPI2 */
 XOR,  /* XOR */
 NAND,  /* NAND */
 AND,  /* AND */
 BIIMP,  /* BIIMP */
 LIMP,  /* IMP */
 IMP,  /* LIMP */
 OR,  /* OR */
 K1,  /* K1 */
 0   /* Dummy row */
};

struct one_terminal_reduction one_terminal_reduction_array[] = {
 { 0, 0, 0, 0 },  /* Dummy row */
 { K0, K0, K0, K0 },  /* K0 */
 { K0, K1, PI1, PI1 },  /* PI1 */
 { PI1, PI1, K0, K1 },  /* PI2 */
 { NPI1, K0, NPI1, K0 },  /* NOR */
 { PI1, K0, K0, NPI1 },  /* NLIMP */
 { K1, K0, NPI1, NPI1 },  /* NPI1 */
 { K0, NPI1, PI1, K0 },  /* NIMP */
 { NPI1, NPI1, K1, K0 },  /* NPI2 */
 { PI1, NPI1, PI1, NPI1 },  /* XOR */
 { K1, NPI1, K1, NPI1 },  /* NAND */
 { K0, PI1, K0, PI1 },  /* AND */
 { NPI1, PI1, NPI1, PI1 },  /* BIIMP */
 { K1, PI1, NPI1, K1 },  /* IMP */
 { NPI1, K1, K1, PI1 },  /* LIMP */
 { PI1, K1, PI1, K1 },  /* OR */
 { K1, K1, K1, K1 },  /* K1 */
 { 0, 0, 0, 0 }   /* Dummy row */
};

Op identical_children_reduction_array[] = {
 NOP,  /* Dummy row */
 K0,  /* K0 */
 PI1,  /* PI1 */
 PI1,  /* PI2 */
 NPI1,  /* NOR */
 K0,  /* NLIMP */
 NPI1,  /* NPI1 */
 K0,  /* NIMP */
 NPI1,  /* NPI2 */
 K0,  /* XOR */
 NPI1,  /* NAND */
 PI1,  /* AND */
 K1,  /* BIIMP */
 K1,  /* IMP */
 K1,  /* LIMP */
 PI1,  /* OR */
 K1,  /* K1 */
 0   /* Dummy row */
};

Op negation_child_reduction_array[] = {
 NOP,  /* Dummy row */
 K0,  /* K0 */
 NPI1,  /* PI1 */
 PI2,  /* PI2 */
 NIMP,  /* NOR */
 AND,  /* NLIMP */
 PI1,  /* NPI1 */
 NOR,  /* NIMP */
 NPI2,  /* NPI2 */
 BIIMP,  /* XOR */
 LIMP,  /* NAND */
 NLIMP,  /* AND */
 XOR,  /* BIIMP */
 OR,  /* IMP */
 NAND,  /* LIMP */
 IMP,  /* OR */
 K1,  /* K1 */
 0   /* Dummy row */
};

Op negation_parent_reduction_array[] = {
 NOP,  /* Dummy row */
 K1,  /* K0 */
 NPI1,  /* PI1 */
 NPI2,  /* PI2 */
 OR,  /* NOR */
 LIMP,  /* NLIMP */
 PI1,  /* NPI1 */
 IMP,  /* NIMP */
 PI2,  /* NPI2 */
 BIIMP,  /* XOR */
 AND,  /* NAND */
 NAND,  /* AND */
 XOR,  /* BIIMP */
 NIMP,  /* IMP */
 NLIMP,  /* LIMP */
 NOR,  /* OR */
 K0,  /* K1 */
 0   /* Dummy row */
};

Op two_nodes_left_reduction_array[] = {
 K0,  /* K0, K0 */
 K0,  /* K0, PI1 */
 K0,  /* K0, PI2 */
 K0,  /* K0, NOR */
 K0,  /* K0, NLIMP */
 K0,  /* K0, NPI1 */
 K0,  /* K0, NIMP */
 K0,  /* K0, NPI2 */
 K0,  /* K0, XOR */
 K0,  /* K0, NAND */
 K0,  /* K0, AND */
 K0,  /* K0, BIIMP */
 K0,  /* K0, IMP */
 K0,  /* K0, LIMP */
 K0,  /* K0, OR */
 K0,  /* K0, K1 */
 K0,  /* PI1, K0 */
 PI1,  /* PI1, PI1 */
 PI2,  /* PI1, PI2 */
 NOR,  /* PI1, NOR */
 NLIMP,  /* PI1, NLIMP */
 NPI1,  /* PI1, NPI1 */
 NIMP,  /* PI1, NIMP */
 NPI2,  /* PI1, NPI2 */
 XOR,  /* PI1, XOR */
 NAND,  /* PI1, NAND */
 AND,  /* PI1, AND */
 BIIMP,  /* PI1, BIIMP */
 IMP,  /* PI1, IMP */
 LIMP,  /* PI1, LIMP */
 OR,  /* PI1, OR */
 K1,  /* PI1, K1 */
 PI1,  /* PI2, K0 */
 PI1,  /* PI2, PI1 */
 PI1,  /* PI2, PI2 */
 PI1,  /* PI2, NOR */
 PI1,  /* PI2, NLIMP */
 PI1,  /* PI2, NPI1 */
 PI1,  /* PI2, NIMP */
 PI1,  /* PI2, NPI2 */
 PI1,  /* PI2, XOR */
 PI1,  /* PI2, NAND */
 PI1,  /* PI2, AND */
 PI1,  /* PI2, BIIMP */
 PI1,  /* PI2, IMP */
 PI1,  /* PI2, LIMP */
 PI1,  /* PI2, OR */
 PI1,  /* PI2, K1 */
 NPI1,  /* NOR, K0 */
 NPI1,  /* NOR, PI1 */
 NOR,  /* NOR, PI2 */
 NLIMP,  /* NOR, NOR */
 NOR,  /* NOR, NLIMP */
 K0,  /* NOR, NPI1 */
 NPI1,  /* NOR, NIMP */
 NLIMP,  /* NOR, NPI2 */
 NOR,  /* NOR, XOR */
 K0,  /* NOR, NAND */
 NPI1,  /* NOR, AND */
 NLIMP,  /* NOR, BIIMP */
 K0,  /* NOR, IMP */
 NLIMP,  /* NOR, LIMP */
 NOR,  /* NOR, OR */
 K0,  /* NOR, K1 */
 PI1,  /* NLIMP, K0 */
 K0,  /* NLIMP, PI1 */
 NIMP,  /* NLIMP, PI2 */
 PI1,  /* NLIMP, NOR */
 PI1,  /* NLIMP, NLIMP */
 PI1,  /* NLIMP, NPI1 */
 AND,  /* NLIMP, NIMP */
 AND,  /* NLIMP, NPI2 */
 AND,  /* NLIMP, XOR */
 AND,  /* NLIMP, NAND */
 NIMP,  /* NLIMP, AND */
 NIMP,  /* NLIMP, BIIMP */
 NIMP,  /* NLIMP, IMP */
 K0,  /* NLIMP, LIMP */
 K0,  /* NLIMP, OR */
 K0,  /* NLIMP, K1 */
 K1,  /* NPI1, K0 */
 NPI1,  /* NPI1, PI1 */
 NPI2,  /* NPI1, PI2 */
 OR,  /* NPI1, NOR */
 LIMP,  /* NPI1, NLIMP */
 PI1,  /* NPI1, NPI1 */
 IMP,  /* NPI1, NIMP */
 PI2,  /* NPI1, NPI2 */
 BIIMP,  /* NPI1, XOR */
 AND,  /* NPI1, NAND */
 NAND,  /* NPI1, AND */
 XOR,  /* NPI1, BIIMP */
 NIMP,  /* NPI1, IMP */
 NLIMP,  /* NPI1, LIMP */
 NOR,  /* NPI1, OR */
 K0,  /* NPI1, K1 */
 K0,  /* NIMP, K0 */
 K0,  /* NIMP, PI1 */
 NLIMP,  /* NIMP, PI2 */
 NOR,  /* NIMP, NOR */
 NLIMP,  /* NIMP, NLIMP */
 NPI1,  /* NIMP, NPI1 */
 K0,  /* NIMP, NIMP */
 NOR,  /* NIMP, NPI2 */
 NLIMP,  /* NIMP, XOR */
 NPI1,  /* NIMP, NAND */
 K0,  /* NIMP, AND */
 NOR,  /* NIMP, BIIMP */
 NPI1,  /* NIMP, IMP */
 NOR,  /* NIMP, LIMP */
 NLIMP,  /* NIMP, OR */
 NPI1,  /* NIMP, K1 */
 NPI1,  /* NPI2, K0 */
 NPI1,  /* NPI2, PI1 */
 NPI1,  /* NPI2, PI2 */
 NPI1,  /* NPI2, NOR */
 NPI1,  /* NPI2, NLIMP */
 NPI1,  /* NPI2, NPI1 */
 NPI1,  /* NPI2, NIMP */
 NPI1,  /* NPI2, NPI2 */
 NPI1,  /* NPI2, XOR */
 NPI1,  /* NPI2, NAND */
 NPI1,  /* NPI2, AND */
 NPI1,  /* NPI2, BIIMP */
 NPI1,  /* NPI2, IMP */
 NPI1,  /* NPI2, LIMP */
 NPI1,  /* NPI2, OR */
 NPI1,  /* NPI2, K1 */
 PI1,  /* XOR, K0 */
 K0,  /* XOR, PI1 */
 XOR,  /* XOR, PI2 */
 LIMP,  /* XOR, NOR */
 OR,  /* XOR, NLIMP */
 K1,  /* XOR, NPI1 */
 AND,  /* XOR, NIMP */
 BIIMP,  /* XOR, NPI2 */
 PI2,  /* XOR, XOR */
 IMP,  /* XOR, NAND */
 NIMP,  /* XOR, AND */
 NPI2,  /* XOR, BIIMP */
 NAND,  /* XOR, IMP */
 NOR,  /* XOR, LIMP */
 NLIMP,  /* XOR, OR */
 NPI1,  /* XOR, K1 */
 K1,  /* NAND, K0 */
 NPI1,  /* NAND, PI1 */
 NAND,  /* NAND, PI2 */
 K1,  /* NAND, NOR */
 K1,  /* NAND, NLIMP */
 K1,  /* NAND, NPI1 */
 IMP,  /* NAND, NIMP */
 IMP,  /* NAND, NPI2 */
 IMP,  /* NAND, XOR */
 IMP,  /* NAND, NAND */
 NAND,  /* NAND, AND */
 NAND,  /* NAND, BIIMP */
 NAND,  /* NAND, IMP */
 NPI1,  /* NAND, LIMP */
 NPI1,  /* NAND, OR */
 NPI1,  /* NAND, K1 */
 K0,  /* AND, K0 */
 PI1,  /* AND, PI1 */
 AND,  /* AND, PI2 */
 K0,  /* AND, NOR */
 K0,  /* AND, NLIMP */
 K0,  /* AND, NPI1 */
 NIMP,  /* AND, NIMP */
 NIMP,  /* AND, NPI2 */
 NIMP,  /* AND, XOR */
 NIMP,  /* AND, NAND */
 AND,  /* AND, AND */
 AND,  /* AND, BIIMP */
 AND,  /* AND, IMP */
 PI1,  /* AND, LIMP */
 PI1,  /* AND, OR */
 PI1,  /* AND, K1 */
 NPI1,  /* BIIMP, K0 */
 K1,  /* BIIMP, PI1 */
 BIIMP,  /* BIIMP, PI2 */
 NLIMP,  /* BIIMP, NOR */
 NOR,  /* BIIMP, NLIMP */
 K0,  /* BIIMP, NPI1 */
 NAND,  /* BIIMP, NIMP */
 XOR,  /* BIIMP, NPI2 */
 NPI2,  /* BIIMP, XOR */
 NIMP,  /* BIIMP, NAND */
 IMP,  /* BIIMP, AND */
 PI2,  /* BIIMP, BIIMP */
 AND,  /* BIIMP, IMP */
 OR,  /* BIIMP, LIMP */
 LIMP,  /* BIIMP, OR */
 PI1,  /* BIIMP, K1 */
 K1,  /* IMP, K0 */
 K1,  /* IMP, PI1 */
 LIMP,  /* IMP, PI2 */
 OR,  /* IMP, NOR */
 LIMP,  /* IMP, NLIMP */
 PI1,  /* IMP, NPI1 */
 K1,  /* IMP, NIMP */
 OR,  /* IMP, NPI2 */
 LIMP,  /* IMP, XOR */
 PI1,  /* IMP, NAND */
 K1,  /* IMP, AND */
 OR,  /* IMP, BIIMP */
 PI1,  /* IMP, IMP */
 OR,  /* IMP, LIMP */
 LIMP,  /* IMP, OR */
 PI1,  /* IMP, K1 */
 NPI1,  /* LIMP, K0 */
 K1,  /* LIMP, PI1 */
 IMP,  /* LIMP, PI2 */
 NPI1,  /* LIMP, NOR */
 NPI1,  /* LIMP, NLIMP */
 NPI1,  /* LIMP, NPI1 */
 NAND,  /* LIMP, NIMP */
 NAND,  /* LIMP, NPI2 */
 NAND,  /* LIMP, XOR */
 NAND,  /* LIMP, NAND */
 IMP,  /* LIMP, AND */
 IMP,  /* LIMP, BIIMP */
 IMP,  /* LIMP, IMP */
 K1,  /* LIMP, LIMP */
 K1,  /* LIMP, OR */
 K1,  /* LIMP, K1 */
 PI1,  /* OR, K0 */
 PI1,  /* OR, PI1 */
 OR,  /* OR, PI2 */
 LIMP,  /* OR, NOR */
 OR,  /* OR, NLIMP */
 K1,  /* OR, NPI1 */
 PI1,  /* OR, NIMP */
 LIMP,  /* OR, NPI2 */
 OR,  /* OR, XOR */
 K1,  /* OR, NAND */
 PI1,  /* OR, AND */
 LIMP,  /* OR, BIIMP */
 K1,  /* OR, IMP */
 LIMP,  /* OR, LIMP */
 OR,  /* OR, OR */
 K1,  /* OR, K1 */
 K1,  /* K1, K0 */
 K1,  /* K1, PI1 */
 K1,  /* K1, PI2 */
 K1,  /* K1, NOR */
 K1,  /* K1, NLIMP */
 K1,  /* K1, NPI1 */
 K1,  /* K1, NIMP */
 K1,  /* K1, NPI2 */
 K1,  /* K1, XOR */
 K1,  /* K1, NAND */
 K1,  /* K1, AND */
 K1,  /* K1, BIIMP */
 K1,  /* K1, IMP */
 K1,  /* K1, LIMP */
 K1,  /* K1, OR */
 K1,  /* K1, K1 */
 0   /* Dummy row */
};

struct three_nodes_reduction three_nodes_reduction_array[] = {
 { 1, K0, K0 }, /* K0, K0, K0 */
 { 1, K0, K0 }, /* K0, K0, PI1 */
 { 1, K0, K0 }, /* K0, K0, PI2 */
 { 1, K0, K0 }, /* K0, K0, NOR */
 { 1, K0, K0 }, /* K0, K0, NLIMP */
 { 1, K0, K0 }, /* K0, K0, NPI1 */
 { 1, K0, K0 }, /* K0, K0, NIMP */
 { 1, K0, K0 }, /* K0, K0, NPI2 */
 { 1, K0, K0 }, /* K0, K0, XOR */
 { 1, K0, K0 }, /* K0, K0, NAND */
 { 1, K0, K0 }, /* K0, K0, AND */
 { 1, K0, K0 }, /* K0, K0, BIIMP */
 { 1, K0, K0 }, /* K0, K0, IMP */
 { 1, K0, K0 }, /* K0, K0, LIMP */
 { 1, K0, K0 }, /* K0, K0, OR */
 { 1, K0, K0 }, /* K0, K0, K1 */
 { 1, K0, K0 }, /* K0, PI1, K0 */
 { 1, K0, K0 }, /* K0, PI1, PI1 */
 { 1, K0, K0 }, /* K0, PI1, PI2 */
 { 1, K0, K0 }, /* K0, PI1, NOR */
 { 1, K0, K0 }, /* K0, PI1, NLIMP */
 { 1, K0, K0 }, /* K0, PI1, NPI1 */
 { 1, K0, K0 }, /* K0, PI1, NIMP */
 { 1, K0, K0 }, /* K0, PI1, NPI2 */
 { 1, K0, K0 }, /* K0, PI1, XOR */
 { 1, K0, K0 }, /* K0, PI1, NAND */
 { 1, K0, K0 }, /* K0, PI1, AND */
 { 1, K0, K0 }, /* K0, PI1, BIIMP */
 { 1, K0, K0 }, /* K0, PI1, IMP */
 { 1, K0, K0 }, /* K0, PI1, LIMP */
 { 1, K0, K0 }, /* K0, PI1, OR */
 { 1, K0, K0 }, /* K0, PI1, K1 */
 { 1, K0, K0 }, /* K0, PI2, K0 */
 { 1, K0, K0 }, /* K0, PI2, PI1 */
 { 1, K0, K0 }, /* K0, PI2, PI2 */
 { 1, K0, K0 }, /* K0, PI2, NOR */
 { 1, K0, K0 }, /* K0, PI2, NLIMP */
 { 1, K0, K0 }, /* K0, PI2, NPI1 */
 { 1, K0, K0 }, /* K0, PI2, NIMP */
 { 1, K0, K0 }, /* K0, PI2, NPI2 */
 { 1, K0, K0 }, /* K0, PI2, XOR */
 { 1, K0, K0 }, /* K0, PI2, NAND */
 { 1, K0, K0 }, /* K0, PI2, AND */
 { 1, K0, K0 }, /* K0, PI2, BIIMP */
 { 1, K0, K0 }, /* K0, PI2, IMP */
 { 1, K0, K0 }, /* K0, PI2, LIMP */
 { 1, K0, K0 }, /* K0, PI2, OR */
 { 1, K0, K0 }, /* K0, PI2, K1 */
 { 1, K0, K0 }, /* K0, NOR, K0 */
 { 1, K0, K0 }, /* K0, NOR, PI1 */
 { 1, K0, K0 }, /* K0, NOR, PI2 */
 { 1, K0, K0 }, /* K0, NOR, NOR */
 { 1, K0, K0 }, /* K0, NOR, NLIMP */
 { 1, K0, K0 }, /* K0, NOR, NPI1 */
 { 1, K0, K0 }, /* K0, NOR, NIMP */
 { 1, K0, K0 }, /* K0, NOR, NPI2 */
 { 1, K0, K0 }, /* K0, NOR, XOR */
 { 1, K0, K0 }, /* K0, NOR, NAND */
 { 1, K0, K0 }, /* K0, NOR, AND */
 { 1, K0, K0 }, /* K0, NOR, BIIMP */
 { 1, K0, K0 }, /* K0, NOR, IMP */
 { 1, K0, K0 }, /* K0, NOR, LIMP */
 { 1, K0, K0 }, /* K0, NOR, OR */
 { 1, K0, K0 }, /* K0, NOR, K1 */
 { 1, K0, K0 }, /* K0, NLIMP, K0 */
 { 1, K0, K0 }, /* K0, NLIMP, PI1 */
 { 1, K0, K0 }, /* K0, NLIMP, PI2 */
 { 1, K0, K0 }, /* K0, NLIMP, NOR */
 { 1, K0, K0 }, /* K0, NLIMP, NLIMP */
 { 1, K0, K0 }, /* K0, NLIMP, NPI1 */
 { 1, K0, K0 }, /* K0, NLIMP, NIMP */
 { 1, K0, K0 }, /* K0, NLIMP, NPI2 */
 { 1, K0, K0 }, /* K0, NLIMP, XOR */
 { 1, K0, K0 }, /* K0, NLIMP, NAND */
 { 1, K0, K0 }, /* K0, NLIMP, AND */
 { 1, K0, K0 }, /* K0, NLIMP, BIIMP */
 { 1, K0, K0 }, /* K0, NLIMP, IMP */
 { 1, K0, K0 }, /* K0, NLIMP, LIMP */
 { 1, K0, K0 }, /* K0, NLIMP, OR */
 { 1, K0, K0 }, /* K0, NLIMP, K1 */
 { 1, K0, K0 }, /* K0, NPI1, K0 */
 { 1, K0, K0 }, /* K0, NPI1, PI1 */
 { 1, K0, K0 }, /* K0, NPI1, PI2 */
 { 1, K0, K0 }, /* K0, NPI1, NOR */
 { 1, K0, K0 }, /* K0, NPI1, NLIMP */
 { 1, K0, K0 }, /* K0, NPI1, NPI1 */
 { 1, K0, K0 }, /* K0, NPI1, NIMP */
 { 1, K0, K0 }, /* K0, NPI1, NPI2 */
 { 1, K0, K0 }, /* K0, NPI1, XOR */
 { 1, K0, K0 }, /* K0, NPI1, NAND */
 { 1, K0, K0 }, /* K0, NPI1, AND */
 { 1, K0, K0 }, /* K0, NPI1, BIIMP */
 { 1, K0, K0 }, /* K0, NPI1, IMP */
 { 1, K0, K0 }, /* K0, NPI1, LIMP */
 { 1, K0, K0 }, /* K0, NPI1, OR */
 { 1, K0, K0 }, /* K0, NPI1, K1 */
 { 1, K0, K0 }, /* K0, NIMP, K0 */
 { 1, K0, K0 }, /* K0, NIMP, PI1 */
 { 1, K0, K0 }, /* K0, NIMP, PI2 */
 { 1, K0, K0 }, /* K0, NIMP, NOR */
 { 1, K0, K0 }, /* K0, NIMP, NLIMP */
 { 1, K0, K0 }, /* K0, NIMP, NPI1 */
 { 1, K0, K0 }, /* K0, NIMP, NIMP */
 { 1, K0, K0 }, /* K0, NIMP, NPI2 */
 { 1, K0, K0 }, /* K0, NIMP, XOR */
 { 1, K0, K0 }, /* K0, NIMP, NAND */
 { 1, K0, K0 }, /* K0, NIMP, AND */
 { 1, K0, K0 }, /* K0, NIMP, BIIMP */
 { 1, K0, K0 }, /* K0, NIMP, IMP */
 { 1, K0, K0 }, /* K0, NIMP, LIMP */
 { 1, K0, K0 }, /* K0, NIMP, OR */
 { 1, K0, K0 }, /* K0, NIMP, K1 */
 { 1, K0, K0 }, /* K0, NPI2, K0 */
 { 1, K0, K0 }, /* K0, NPI2, PI1 */
 { 1, K0, K0 }, /* K0, NPI2, PI2 */
 { 1, K0, K0 }, /* K0, NPI2, NOR */
 { 1, K0, K0 }, /* K0, NPI2, NLIMP */
 { 1, K0, K0 }, /* K0, NPI2, NPI1 */
 { 1, K0, K0 }, /* K0, NPI2, NIMP */
 { 1, K0, K0 }, /* K0, NPI2, NPI2 */
 { 1, K0, K0 }, /* K0, NPI2, XOR */
 { 1, K0, K0 }, /* K0, NPI2, NAND */
 { 1, K0, K0 }, /* K0, NPI2, AND */
 { 1, K0, K0 }, /* K0, NPI2, BIIMP */
 { 1, K0, K0 }, /* K0, NPI2, IMP */
 { 1, K0, K0 }, /* K0, NPI2, LIMP */
 { 1, K0, K0 }, /* K0, NPI2, OR */
 { 1, K0, K0 }, /* K0, NPI2, K1 */
 { 1, K0, K0 }, /* K0, XOR, K0 */
 { 1, K0, K0 }, /* K0, XOR, PI1 */
 { 1, K0, K0 }, /* K0, XOR, PI2 */
 { 1, K0, K0 }, /* K0, XOR, NOR */
 { 1, K0, K0 }, /* K0, XOR, NLIMP */
 { 1, K0, K0 }, /* K0, XOR, NPI1 */
 { 1, K0, K0 }, /* K0, XOR, NIMP */
 { 1, K0, K0 }, /* K0, XOR, NPI2 */
 { 1, K0, K0 }, /* K0, XOR, XOR */
 { 1, K0, K0 }, /* K0, XOR, NAND */
 { 1, K0, K0 }, /* K0, XOR, AND */
 { 1, K0, K0 }, /* K0, XOR, BIIMP */
 { 1, K0, K0 }, /* K0, XOR, IMP */
 { 1, K0, K0 }, /* K0, XOR, LIMP */
 { 1, K0, K0 }, /* K0, XOR, OR */
 { 1, K0, K0 }, /* K0, XOR, K1 */
 { 1, K0, K0 }, /* K0, NAND, K0 */
 { 1, K0, K0 }, /* K0, NAND, PI1 */
 { 1, K0, K0 }, /* K0, NAND, PI2 */
 { 1, K0, K0 }, /* K0, NAND, NOR */
 { 1, K0, K0 }, /* K0, NAND, NLIMP */
 { 1, K0, K0 }, /* K0, NAND, NPI1 */
 { 1, K0, K0 }, /* K0, NAND, NIMP */
 { 1, K0, K0 }, /* K0, NAND, NPI2 */
 { 1, K0, K0 }, /* K0, NAND, XOR */
 { 1, K0, K0 }, /* K0, NAND, NAND */
 { 1, K0, K0 }, /* K0, NAND, AND */
 { 1, K0, K0 }, /* K0, NAND, BIIMP */
 { 1, K0, K0 }, /* K0, NAND, IMP */
 { 1, K0, K0 }, /* K0, NAND, LIMP */
 { 1, K0, K0 }, /* K0, NAND, OR */
 { 1, K0, K0 }, /* K0, NAND, K1 */
 { 1, K0, K0 }, /* K0, AND, K0 */
 { 1, K0, K0 }, /* K0, AND, PI1 */
 { 1, K0, K0 }, /* K0, AND, PI2 */
 { 1, K0, K0 }, /* K0, AND, NOR */
 { 1, K0, K0 }, /* K0, AND, NLIMP */
 { 1, K0, K0 }, /* K0, AND, NPI1 */
 { 1, K0, K0 }, /* K0, AND, NIMP */
 { 1, K0, K0 }, /* K0, AND, NPI2 */
 { 1, K0, K0 }, /* K0, AND, XOR */
 { 1, K0, K0 }, /* K0, AND, NAND */
 { 1, K0, K0 }, /* K0, AND, AND */
 { 1, K0, K0 }, /* K0, AND, BIIMP */
 { 1, K0, K0 }, /* K0, AND, IMP */
 { 1, K0, K0 }, /* K0, AND, LIMP */
 { 1, K0, K0 }, /* K0, AND, OR */
 { 1, K0, K0 }, /* K0, AND, K1 */
 { 1, K0, K0 }, /* K0, BIIMP, K0 */
 { 1, K0, K0 }, /* K0, BIIMP, PI1 */
 { 1, K0, K0 }, /* K0, BIIMP, PI2 */
 { 1, K0, K0 }, /* K0, BIIMP, NOR */
 { 1, K0, K0 }, /* K0, BIIMP, NLIMP */
 { 1, K0, K0 }, /* K0, BIIMP, NPI1 */
 { 1, K0, K0 }, /* K0, BIIMP, NIMP */
 { 1, K0, K0 }, /* K0, BIIMP, NPI2 */
 { 1, K0, K0 }, /* K0, BIIMP, XOR */
 { 1, K0, K0 }, /* K0, BIIMP, NAND */
 { 1, K0, K0 }, /* K0, BIIMP, AND */
 { 1, K0, K0 }, /* K0, BIIMP, BIIMP */
 { 1, K0, K0 }, /* K0, BIIMP, IMP */
 { 1, K0, K0 }, /* K0, BIIMP, LIMP */
 { 1, K0, K0 }, /* K0, BIIMP, OR */
 { 1, K0, K0 }, /* K0, BIIMP, K1 */
 { 1, K0, K0 }, /* K0, IMP, K0 */
 { 1, K0, K0 }, /* K0, IMP, PI1 */
 { 1, K0, K0 }, /* K0, IMP, PI2 */
 { 1, K0, K0 }, /* K0, IMP, NOR */
 { 1, K0, K0 }, /* K0, IMP, NLIMP */
 { 1, K0, K0 }, /* K0, IMP, NPI1 */
 { 1, K0, K0 }, /* K0, IMP, NIMP */
 { 1, K0, K0 }, /* K0, IMP, NPI2 */
 { 1, K0, K0 }, /* K0, IMP, XOR */
 { 1, K0, K0 }, /* K0, IMP, NAND */
 { 1, K0, K0 }, /* K0, IMP, AND */
 { 1, K0, K0 }, /* K0, IMP, BIIMP */
 { 1, K0, K0 }, /* K0, IMP, IMP */
 { 1, K0, K0 }, /* K0, IMP, LIMP */
 { 1, K0, K0 }, /* K0, IMP, OR */
 { 1, K0, K0 }, /* K0, IMP, K1 */
 { 1, K0, K0 }, /* K0, LIMP, K0 */
 { 1, K0, K0 }, /* K0, LIMP, PI1 */
 { 1, K0, K0 }, /* K0, LIMP, PI2 */
 { 1, K0, K0 }, /* K0, LIMP, NOR */
 { 1, K0, K0 }, /* K0, LIMP, NLIMP */
 { 1, K0, K0 }, /* K0, LIMP, NPI1 */
 { 1, K0, K0 }, /* K0, LIMP, NIMP */
 { 1, K0, K0 }, /* K0, LIMP, NPI2 */
 { 1, K0, K0 }, /* K0, LIMP, XOR */
 { 1, K0, K0 }, /* K0, LIMP, NAND */
 { 1, K0, K0 }, /* K0, LIMP, AND */
 { 1, K0, K0 }, /* K0, LIMP, BIIMP */
 { 1, K0, K0 }, /* K0, LIMP, IMP */
 { 1, K0, K0 }, /* K0, LIMP, LIMP */
 { 1, K0, K0 }, /* K0, LIMP, OR */
 { 1, K0, K0 }, /* K0, LIMP, K1 */
 { 1, K0, K0 }, /* K0, OR, K0 */
 { 1, K0, K0 }, /* K0, OR, PI1 */
 { 1, K0, K0 }, /* K0, OR, PI2 */
 { 1, K0, K0 }, /* K0, OR, NOR */
 { 1, K0, K0 }, /* K0, OR, NLIMP */
 { 1, K0, K0 }, /* K0, OR, NPI1 */
 { 1, K0, K0 }, /* K0, OR, NIMP */
 { 1, K0, K0 }, /* K0, OR, NPI2 */
 { 1, K0, K0 }, /* K0, OR, XOR */
 { 1, K0, K0 }, /* K0, OR, NAND */
 { 1, K0, K0 }, /* K0, OR, AND */
 { 1, K0, K0 }, /* K0, OR, BIIMP */
 { 1, K0, K0 }, /* K0, OR, IMP */
 { 1, K0, K0 }, /* K0, OR, LIMP */
 { 1, K0, K0 }, /* K0, OR, OR */
 { 1, K0, K0 }, /* K0, OR, K1 */
 { 1, K0, K0 }, /* K0, K1, K0 */
 { 1, K0, K0 }, /* K0, K1, PI1 */
 { 1, K0, K0 }, /* K0, K1, PI2 */
 { 1, K0, K0 }, /* K0, K1, NOR */
 { 1, K0, K0 }, /* K0, K1, NLIMP */
 { 1, K0, K0 }, /* K0, K1, NPI1 */
 { 1, K0, K0 }, /* K0, K1, NIMP */
 { 1, K0, K0 }, /* K0, K1, NPI2 */
 { 1, K0, K0 }, /* K0, K1, XOR */
 { 1, K0, K0 }, /* K0, K1, NAND */
 { 1, K0, K0 }, /* K0, K1, AND */
 { 1, K0, K0 }, /* K0, K1, BIIMP */
 { 1, K0, K0 }, /* K0, K1, IMP */
 { 1, K0, K0 }, /* K0, K1, LIMP */
 { 1, K0, K0 }, /* K0, K1, OR */
 { 1, K0, K0 }, /* K0, K1, K1 */
 { 1, K0, K0 }, /* PI1, K0, K0 */
 { 1, K0, K0 }, /* PI1, K0, PI1 */
 { 1, K0, K0 }, /* PI1, K0, PI2 */
 { 1, K0, K0 }, /* PI1, K0, NOR */
 { 1, K0, K0 }, /* PI1, K0, NLIMP */
 { 1, K0, K0 }, /* PI1, K0, NPI1 */
 { 1, K0, K0 }, /* PI1, K0, NIMP */
 { 1, K0, K0 }, /* PI1, K0, NPI2 */
 { 1, K0, K0 }, /* PI1, K0, XOR */
 { 1, K0, K0 }, /* PI1, K0, NAND */
 { 1, K0, K0 }, /* PI1, K0, AND */
 { 1, K0, K0 }, /* PI1, K0, BIIMP */
 { 1, K0, K0 }, /* PI1, K0, IMP */
 { 1, K0, K0 }, /* PI1, K0, LIMP */
 { 1, K0, K0 }, /* PI1, K0, OR */
 { 1, K0, K0 }, /* PI1, K0, K1 */
 { 0, PI1, K0 }, /* PI1, PI1, K0 */
 { 0, PI1, K0 }, /* PI1, PI1, PI1 */
 { 0, PI1, K0 }, /* PI1, PI1, PI2 */
 { 0, PI1, K0 }, /* PI1, PI1, NOR */
 { 0, PI1, K0 }, /* PI1, PI1, NLIMP */
 { 0, PI1, K0 }, /* PI1, PI1, NPI1 */
 { 0, PI1, K0 }, /* PI1, PI1, NIMP */
 { 0, PI1, K0 }, /* PI1, PI1, NPI2 */
 { 0, PI1, K0 }, /* PI1, PI1, XOR */
 { 0, PI1, K0 }, /* PI1, PI1, NAND */
 { 0, PI1, K0 }, /* PI1, PI1, AND */
 { 0, PI1, K0 }, /* PI1, PI1, BIIMP */
 { 0, PI1, K0 }, /* PI1, PI1, IMP */
 { 0, PI1, K0 }, /* PI1, PI1, LIMP */
 { 0, PI1, K0 }, /* PI1, PI1, OR */
 { 0, PI1, K0 }, /* PI1, PI1, K1 */
 { 1, PI1, PI2 }, /* PI1, PI2, K0 */
 { 1, PI1, PI2 }, /* PI1, PI2, PI1 */
 { 1, PI1, PI2 }, /* PI1, PI2, PI2 */
 { 1, PI1, PI2 }, /* PI1, PI2, NOR */
 { 1, PI1, PI2 }, /* PI1, PI2, NLIMP */
 { 1, PI1, PI2 }, /* PI1, PI2, NPI1 */
 { 1, PI1, PI2 }, /* PI1, PI2, NIMP */
 { 1, PI1, PI2 }, /* PI1, PI2, NPI2 */
 { 1, PI1, PI2 }, /* PI1, PI2, XOR */
 { 1, PI1, PI2 }, /* PI1, PI2, NAND */
 { 1, PI1, PI2 }, /* PI1, PI2, AND */
 { 1, PI1, PI2 }, /* PI1, PI2, BIIMP */
 { 1, PI1, PI2 }, /* PI1, PI2, IMP */
 { 1, PI1, PI2 }, /* PI1, PI2, LIMP */
 { 1, PI1, PI2 }, /* PI1, PI2, OR */
 { 1, PI1, PI2 }, /* PI1, PI2, K1 */
 { 1, PI1, NOR }, /* PI1, NOR, K0 */
 { 1, PI1, NOR }, /* PI1, NOR, PI1 */
 { 1, PI1, NOR }, /* PI1, NOR, PI2 */
 { 1, PI1, NOR }, /* PI1, NOR, NOR */
 { 1, PI1, NOR }, /* PI1, NOR, NLIMP */
 { 1, PI1, NOR }, /* PI1, NOR, NPI1 */
 { 1, PI1, NOR }, /* PI1, NOR, NIMP */
 { 1, PI1, NOR }, /* PI1, NOR, NPI2 */
 { 1, PI1, NOR }, /* PI1, NOR, XOR */
 { 1, PI1, NOR }, /* PI1, NOR, NAND */
 { 1, PI1, NOR }, /* PI1, NOR, AND */
 { 1, PI1, NOR }, /* PI1, NOR, BIIMP */
 { 1, PI1, NOR }, /* PI1, NOR, IMP */
 { 1, PI1, NOR }, /* PI1, NOR, LIMP */
 { 1, PI1, NOR }, /* PI1, NOR, OR */
 { 1, PI1, NOR }, /* PI1, NOR, K1 */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, K0 */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, PI1 */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, PI2 */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, NOR */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, NLIMP */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, NPI1 */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, NIMP */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, NPI2 */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, XOR */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, NAND */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, AND */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, BIIMP */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, IMP */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, LIMP */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, OR */
 { 1, PI1, NLIMP }, /* PI1, NLIMP, K1 */
 { 0, NOR, K0 }, /* PI1, NPI1, K0 */
 { 0, NOR, K0 }, /* PI1, NPI1, PI1 */
 { 0, NOR, K0 }, /* PI1, NPI1, PI2 */
 { 0, NOR, K0 }, /* PI1, NPI1, NOR */
 { 0, NOR, K0 }, /* PI1, NPI1, NLIMP */
 { 0, NOR, K0 }, /* PI1, NPI1, NPI1 */
 { 0, NOR, K0 }, /* PI1, NPI1, NIMP */
 { 0, NOR, K0 }, /* PI1, NPI1, NPI2 */
 { 0, NOR, K0 }, /* PI1, NPI1, XOR */
 { 0, NOR, K0 }, /* PI1, NPI1, NAND */
 { 0, NOR, K0 }, /* PI1, NPI1, AND */
 { 0, NOR, K0 }, /* PI1, NPI1, BIIMP */
 { 0, NOR, K0 }, /* PI1, NPI1, IMP */
 { 0, NOR, K0 }, /* PI1, NPI1, LIMP */
 { 0, NOR, K0 }, /* PI1, NPI1, OR */
 { 0, NOR, K0 }, /* PI1, NPI1, K1 */
 { 1, PI1, NIMP }, /* PI1, NIMP, K0 */
 { 1, PI1, NIMP }, /* PI1, NIMP, PI1 */
 { 1, PI1, NIMP }, /* PI1, NIMP, PI2 */
 { 1, PI1, NIMP }, /* PI1, NIMP, NOR */
 { 1, PI1, NIMP }, /* PI1, NIMP, NLIMP */
 { 1, PI1, NIMP }, /* PI1, NIMP, NPI1 */
 { 1, PI1, NIMP }, /* PI1, NIMP, NIMP */
 { 1, PI1, NIMP }, /* PI1, NIMP, NPI2 */
 { 1, PI1, NIMP }, /* PI1, NIMP, XOR */
 { 1, PI1, NIMP }, /* PI1, NIMP, NAND */
 { 1, PI1, NIMP }, /* PI1, NIMP, AND */
 { 1, PI1, NIMP }, /* PI1, NIMP, BIIMP */
 { 1, PI1, NIMP }, /* PI1, NIMP, IMP */
 { 1, PI1, NIMP }, /* PI1, NIMP, LIMP */
 { 1, PI1, NIMP }, /* PI1, NIMP, OR */
 { 1, PI1, NIMP }, /* PI1, NIMP, K1 */
 { 1, NPI1, PI2 }, /* PI1, NPI2, K0 */
 { 1, NPI1, PI2 }, /* PI1, NPI2, PI1 */
 { 1, NPI1, PI2 }, /* PI1, NPI2, PI2 */
 { 1, NPI1, PI2 }, /* PI1, NPI2, NOR */
 { 1, NPI1, PI2 }, /* PI1, NPI2, NLIMP */
 { 1, NPI1, PI2 }, /* PI1, NPI2, NPI1 */
 { 1, NPI1, PI2 }, /* PI1, NPI2, NIMP */
 { 1, NPI1, PI2 }, /* PI1, NPI2, NPI2 */
 { 1, NPI1, PI2 }, /* PI1, NPI2, XOR */
 { 1, NPI1, PI2 }, /* PI1, NPI2, NAND */
 { 1, NPI1, PI2 }, /* PI1, NPI2, AND */
 { 1, NPI1, PI2 }, /* PI1, NPI2, BIIMP */
 { 1, NPI1, PI2 }, /* PI1, NPI2, IMP */
 { 1, NPI1, PI2 }, /* PI1, NPI2, LIMP */
 { 1, NPI1, PI2 }, /* PI1, NPI2, OR */
 { 1, NPI1, PI2 }, /* PI1, NPI2, K1 */
 { 1, PI1, XOR }, /* PI1, XOR, K0 */
 { 1, PI1, XOR }, /* PI1, XOR, PI1 */
 { 1, PI1, XOR }, /* PI1, XOR, PI2 */
 { 1, PI1, XOR }, /* PI1, XOR, NOR */
 { 1, PI1, XOR }, /* PI1, XOR, NLIMP */
 { 1, PI1, XOR }, /* PI1, XOR, NPI1 */
 { 1, PI1, XOR }, /* PI1, XOR, NIMP */
 { 1, PI1, XOR }, /* PI1, XOR, NPI2 */
 { 1, PI1, XOR }, /* PI1, XOR, XOR */
 { 1, PI1, XOR }, /* PI1, XOR, NAND */
 { 1, PI1, XOR }, /* PI1, XOR, AND */
 { 1, PI1, XOR }, /* PI1, XOR, BIIMP */
 { 1, PI1, XOR }, /* PI1, XOR, IMP */
 { 1, PI1, XOR }, /* PI1, XOR, LIMP */
 { 1, PI1, XOR }, /* PI1, XOR, OR */
 { 1, PI1, XOR }, /* PI1, XOR, K1 */
 { 1, PI1, NAND }, /* PI1, NAND, K0 */
 { 1, PI1, NAND }, /* PI1, NAND, PI1 */
 { 1, PI1, NAND }, /* PI1, NAND, PI2 */
 { 1, PI1, NAND }, /* PI1, NAND, NOR */
 { 1, PI1, NAND }, /* PI1, NAND, NLIMP */
 { 1, PI1, NAND }, /* PI1, NAND, NPI1 */
 { 1, PI1, NAND }, /* PI1, NAND, NIMP */
 { 1, PI1, NAND }, /* PI1, NAND, NPI2 */
 { 1, PI1, NAND }, /* PI1, NAND, XOR */
 { 1, PI1, NAND }, /* PI1, NAND, NAND */
 { 1, PI1, NAND }, /* PI1, NAND, AND */
 { 1, PI1, NAND }, /* PI1, NAND, BIIMP */
 { 1, PI1, NAND }, /* PI1, NAND, IMP */
 { 1, PI1, NAND }, /* PI1, NAND, LIMP */
 { 1, PI1, NAND }, /* PI1, NAND, OR */
 { 1, PI1, NAND }, /* PI1, NAND, K1 */
 { 1, PI1, AND }, /* PI1, AND, K0 */
 { 1, PI1, AND }, /* PI1, AND, PI1 */
 { 1, PI1, AND }, /* PI1, AND, PI2 */
 { 1, PI1, AND }, /* PI1, AND, NOR */
 { 1, PI1, AND }, /* PI1, AND, NLIMP */
 { 1, PI1, AND }, /* PI1, AND, NPI1 */
 { 1, PI1, AND }, /* PI1, AND, NIMP */
 { 1, PI1, AND }, /* PI1, AND, NPI2 */
 { 1, PI1, AND }, /* PI1, AND, XOR */
 { 1, PI1, AND }, /* PI1, AND, NAND */
 { 1, PI1, AND }, /* PI1, AND, AND */
 { 1, PI1, AND }, /* PI1, AND, BIIMP */
 { 1, PI1, AND }, /* PI1, AND, IMP */
 { 1, PI1, AND }, /* PI1, AND, LIMP */
 { 1, PI1, AND }, /* PI1, AND, OR */
 { 1, PI1, AND }, /* PI1, AND, K1 */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, K0 */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, PI1 */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, PI2 */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, NOR */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, NLIMP */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, NPI1 */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, NIMP */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, NPI2 */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, XOR */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, NAND */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, AND */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, BIIMP */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, IMP */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, LIMP */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, OR */
 { 1, PI1, BIIMP }, /* PI1, BIIMP, K1 */
 { 1, PI1, IMP }, /* PI1, IMP, K0 */
 { 1, PI1, IMP }, /* PI1, IMP, PI1 */
 { 1, PI1, IMP }, /* PI1, IMP, PI2 */
 { 1, PI1, IMP }, /* PI1, IMP, NOR */
 { 1, PI1, IMP }, /* PI1, IMP, NLIMP */
 { 1, PI1, IMP }, /* PI1, IMP, NPI1 */
 { 1, PI1, IMP }, /* PI1, IMP, NIMP */
 { 1, PI1, IMP }, /* PI1, IMP, NPI2 */
 { 1, PI1, IMP }, /* PI1, IMP, XOR */
 { 1, PI1, IMP }, /* PI1, IMP, NAND */
 { 1, PI1, IMP }, /* PI1, IMP, AND */
 { 1, PI1, IMP }, /* PI1, IMP, BIIMP */
 { 1, PI1, IMP }, /* PI1, IMP, IMP */
 { 1, PI1, IMP }, /* PI1, IMP, LIMP */
 { 1, PI1, IMP }, /* PI1, IMP, OR */
 { 1, PI1, IMP }, /* PI1, IMP, K1 */
 { 1, PI1, LIMP }, /* PI1, LIMP, K0 */
 { 1, PI1, LIMP }, /* PI1, LIMP, PI1 */
 { 1, PI1, LIMP }, /* PI1, LIMP, PI2 */
 { 1, PI1, LIMP }, /* PI1, LIMP, NOR */
 { 1, PI1, LIMP }, /* PI1, LIMP, NLIMP */
 { 1, PI1, LIMP }, /* PI1, LIMP, NPI1 */
 { 1, PI1, LIMP }, /* PI1, LIMP, NIMP */
 { 1, PI1, LIMP }, /* PI1, LIMP, NPI2 */
 { 1, PI1, LIMP }, /* PI1, LIMP, XOR */
 { 1, PI1, LIMP }, /* PI1, LIMP, NAND */
 { 1, PI1, LIMP }, /* PI1, LIMP, AND */
 { 1, PI1, LIMP }, /* PI1, LIMP, BIIMP */
 { 1, PI1, LIMP }, /* PI1, LIMP, IMP */
 { 1, PI1, LIMP }, /* PI1, LIMP, LIMP */
 { 1, PI1, LIMP }, /* PI1, LIMP, OR */
 { 1, PI1, LIMP }, /* PI1, LIMP, K1 */
 { 1, PI1, OR }, /* PI1, OR, K0 */
 { 1, PI1, OR }, /* PI1, OR, PI1 */
 { 1, PI1, OR }, /* PI1, OR, PI2 */
 { 1, PI1, OR }, /* PI1, OR, NOR */
 { 1, PI1, OR }, /* PI1, OR, NLIMP */
 { 1, PI1, OR }, /* PI1, OR, NPI1 */
 { 1, PI1, OR }, /* PI1, OR, NIMP */
 { 1, PI1, OR }, /* PI1, OR, NPI2 */
 { 1, PI1, OR }, /* PI1, OR, XOR */
 { 1, PI1, OR }, /* PI1, OR, NAND */
 { 1, PI1, OR }, /* PI1, OR, AND */
 { 1, PI1, OR }, /* PI1, OR, BIIMP */
 { 1, PI1, OR }, /* PI1, OR, IMP */
 { 1, PI1, OR }, /* PI1, OR, LIMP */
 { 1, PI1, OR }, /* PI1, OR, OR */
 { 1, PI1, OR }, /* PI1, OR, K1 */
 { 1, PI1, K1 }, /* PI1, K1, K0 */
 { 1, PI1, K1 }, /* PI1, K1, PI1 */
 { 1, PI1, K1 }, /* PI1, K1, PI2 */
 { 1, PI1, K1 }, /* PI1, K1, NOR */
 { 1, PI1, K1 }, /* PI1, K1, NLIMP */
 { 1, PI1, K1 }, /* PI1, K1, NPI1 */
 { 1, PI1, K1 }, /* PI1, K1, NIMP */
 { 1, PI1, K1 }, /* PI1, K1, NPI2 */
 { 1, PI1, K1 }, /* PI1, K1, XOR */
 { 1, PI1, K1 }, /* PI1, K1, NAND */
 { 1, PI1, K1 }, /* PI1, K1, AND */
 { 1, PI1, K1 }, /* PI1, K1, BIIMP */
 { 1, PI1, K1 }, /* PI1, K1, IMP */
 { 1, PI1, K1 }, /* PI1, K1, LIMP */
 { 1, PI1, K1 }, /* PI1, K1, OR */
 { 1, PI1, K1 }, /* PI1, K1, K1 */
 { 1, K0, K0 }, /* PI2, K0, K0 */
 { 1, PI2, K0 }, /* PI2, K0, PI1 */
 { 0, PI1, K0 }, /* PI2, K0, PI2 */
 { 1, NOR, PI1 }, /* PI2, K0, NOR */
 { 1, NIMP, PI1 }, /* PI2, K0, NLIMP */
 { 1, NOR, K0 }, /* PI2, K0, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, K0, NIMP */
 { 0, NOR, K0 }, /* PI2, K0, NPI2 */
 { 1, XOR, PI1 }, /* PI2, K0, XOR */
 { 1, NAND, PI1 }, /* PI2, K0, NAND */
 { 1, AND, PI1 }, /* PI2, K0, AND */
 { 1, BIIMP, PI1 }, /* PI2, K0, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, K0, IMP */
 { 1, IMP, PI1 }, /* PI2, K0, LIMP */
 { 1, OR, PI1 }, /* PI2, K0, OR */
 { 1, PI1, K1 }, /* PI2, K0, K1 */
 { 1, K0, K0 }, /* PI2, PI1, K0 */
 { 1, PI2, K0 }, /* PI2, PI1, PI1 */
 { 0, PI1, K0 }, /* PI2, PI1, PI2 */
 { 1, NOR, PI1 }, /* PI2, PI1, NOR */
 { 1, NIMP, PI1 }, /* PI2, PI1, NLIMP */
 { 1, NOR, K0 }, /* PI2, PI1, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, PI1, NIMP */
 { 0, NOR, K0 }, /* PI2, PI1, NPI2 */
 { 1, XOR, PI1 }, /* PI2, PI1, XOR */
 { 1, NAND, PI1 }, /* PI2, PI1, NAND */
 { 1, AND, PI1 }, /* PI2, PI1, AND */
 { 1, BIIMP, PI1 }, /* PI2, PI1, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, PI1, IMP */
 { 1, IMP, PI1 }, /* PI2, PI1, LIMP */
 { 1, OR, PI1 }, /* PI2, PI1, OR */
 { 1, PI1, K1 }, /* PI2, PI1, K1 */
 { 1, K0, K0 }, /* PI2, PI2, K0 */
 { 1, PI2, K0 }, /* PI2, PI2, PI1 */
 { 0, PI1, K0 }, /* PI2, PI2, PI2 */
 { 1, NOR, PI1 }, /* PI2, PI2, NOR */
 { 1, NIMP, PI1 }, /* PI2, PI2, NLIMP */
 { 1, NOR, K0 }, /* PI2, PI2, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, PI2, NIMP */
 { 0, NOR, K0 }, /* PI2, PI2, NPI2 */
 { 1, XOR, PI1 }, /* PI2, PI2, XOR */
 { 1, NAND, PI1 }, /* PI2, PI2, NAND */
 { 1, AND, PI1 }, /* PI2, PI2, AND */
 { 1, BIIMP, PI1 }, /* PI2, PI2, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, PI2, IMP */
 { 1, IMP, PI1 }, /* PI2, PI2, LIMP */
 { 1, OR, PI1 }, /* PI2, PI2, OR */
 { 1, PI1, K1 }, /* PI2, PI2, K1 */
 { 1, K0, K0 }, /* PI2, NOR, K0 */
 { 1, PI2, K0 }, /* PI2, NOR, PI1 */
 { 0, PI1, K0 }, /* PI2, NOR, PI2 */
 { 1, NOR, PI1 }, /* PI2, NOR, NOR */
 { 1, NIMP, PI1 }, /* PI2, NOR, NLIMP */
 { 1, NOR, K0 }, /* PI2, NOR, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, NOR, NIMP */
 { 0, NOR, K0 }, /* PI2, NOR, NPI2 */
 { 1, XOR, PI1 }, /* PI2, NOR, XOR */
 { 1, NAND, PI1 }, /* PI2, NOR, NAND */
 { 1, AND, PI1 }, /* PI2, NOR, AND */
 { 1, BIIMP, PI1 }, /* PI2, NOR, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, NOR, IMP */
 { 1, IMP, PI1 }, /* PI2, NOR, LIMP */
 { 1, OR, PI1 }, /* PI2, NOR, OR */
 { 1, PI1, K1 }, /* PI2, NOR, K1 */
 { 1, K0, K0 }, /* PI2, NLIMP, K0 */
 { 1, PI2, K0 }, /* PI2, NLIMP, PI1 */
 { 0, PI1, K0 }, /* PI2, NLIMP, PI2 */
 { 1, NOR, PI1 }, /* PI2, NLIMP, NOR */
 { 1, NIMP, PI1 }, /* PI2, NLIMP, NLIMP */
 { 1, NOR, K0 }, /* PI2, NLIMP, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, NLIMP, NIMP */
 { 0, NOR, K0 }, /* PI2, NLIMP, NPI2 */
 { 1, XOR, PI1 }, /* PI2, NLIMP, XOR */
 { 1, NAND, PI1 }, /* PI2, NLIMP, NAND */
 { 1, AND, PI1 }, /* PI2, NLIMP, AND */
 { 1, BIIMP, PI1 }, /* PI2, NLIMP, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, NLIMP, IMP */
 { 1, IMP, PI1 }, /* PI2, NLIMP, LIMP */
 { 1, OR, PI1 }, /* PI2, NLIMP, OR */
 { 1, PI1, K1 }, /* PI2, NLIMP, K1 */
 { 1, K0, K0 }, /* PI2, NPI1, K0 */
 { 1, PI2, K0 }, /* PI2, NPI1, PI1 */
 { 0, PI1, K0 }, /* PI2, NPI1, PI2 */
 { 1, NOR, PI1 }, /* PI2, NPI1, NOR */
 { 1, NIMP, PI1 }, /* PI2, NPI1, NLIMP */
 { 1, NOR, K0 }, /* PI2, NPI1, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, NPI1, NIMP */
 { 0, NOR, K0 }, /* PI2, NPI1, NPI2 */
 { 1, XOR, PI1 }, /* PI2, NPI1, XOR */
 { 1, NAND, PI1 }, /* PI2, NPI1, NAND */
 { 1, AND, PI1 }, /* PI2, NPI1, AND */
 { 1, BIIMP, PI1 }, /* PI2, NPI1, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, NPI1, IMP */
 { 1, IMP, PI1 }, /* PI2, NPI1, LIMP */
 { 1, OR, PI1 }, /* PI2, NPI1, OR */
 { 1, PI1, K1 }, /* PI2, NPI1, K1 */
 { 1, K0, K0 }, /* PI2, NIMP, K0 */
 { 1, PI2, K0 }, /* PI2, NIMP, PI1 */
 { 0, PI1, K0 }, /* PI2, NIMP, PI2 */
 { 1, NOR, PI1 }, /* PI2, NIMP, NOR */
 { 1, NIMP, PI1 }, /* PI2, NIMP, NLIMP */
 { 1, NOR, K0 }, /* PI2, NIMP, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, NIMP, NIMP */
 { 0, NOR, K0 }, /* PI2, NIMP, NPI2 */
 { 1, XOR, PI1 }, /* PI2, NIMP, XOR */
 { 1, NAND, PI1 }, /* PI2, NIMP, NAND */
 { 1, AND, PI1 }, /* PI2, NIMP, AND */
 { 1, BIIMP, PI1 }, /* PI2, NIMP, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, NIMP, IMP */
 { 1, IMP, PI1 }, /* PI2, NIMP, LIMP */
 { 1, OR, PI1 }, /* PI2, NIMP, OR */
 { 1, PI1, K1 }, /* PI2, NIMP, K1 */
 { 1, K0, K0 }, /* PI2, NPI2, K0 */
 { 1, PI2, K0 }, /* PI2, NPI2, PI1 */
 { 0, PI1, K0 }, /* PI2, NPI2, PI2 */
 { 1, NOR, PI1 }, /* PI2, NPI2, NOR */
 { 1, NIMP, PI1 }, /* PI2, NPI2, NLIMP */
 { 1, NOR, K0 }, /* PI2, NPI2, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, NPI2, NIMP */
 { 0, NOR, K0 }, /* PI2, NPI2, NPI2 */
 { 1, XOR, PI1 }, /* PI2, NPI2, XOR */
 { 1, NAND, PI1 }, /* PI2, NPI2, NAND */
 { 1, AND, PI1 }, /* PI2, NPI2, AND */
 { 1, BIIMP, PI1 }, /* PI2, NPI2, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, NPI2, IMP */
 { 1, IMP, PI1 }, /* PI2, NPI2, LIMP */
 { 1, OR, PI1 }, /* PI2, NPI2, OR */
 { 1, PI1, K1 }, /* PI2, NPI2, K1 */
 { 1, K0, K0 }, /* PI2, XOR, K0 */
 { 1, PI2, K0 }, /* PI2, XOR, PI1 */
 { 0, PI1, K0 }, /* PI2, XOR, PI2 */
 { 1, NOR, PI1 }, /* PI2, XOR, NOR */
 { 1, NIMP, PI1 }, /* PI2, XOR, NLIMP */
 { 1, NOR, K0 }, /* PI2, XOR, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, XOR, NIMP */
 { 0, NOR, K0 }, /* PI2, XOR, NPI2 */
 { 1, XOR, PI1 }, /* PI2, XOR, XOR */
 { 1, NAND, PI1 }, /* PI2, XOR, NAND */
 { 1, AND, PI1 }, /* PI2, XOR, AND */
 { 1, BIIMP, PI1 }, /* PI2, XOR, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, XOR, IMP */
 { 1, IMP, PI1 }, /* PI2, XOR, LIMP */
 { 1, OR, PI1 }, /* PI2, XOR, OR */
 { 1, PI1, K1 }, /* PI2, XOR, K1 */
 { 1, K0, K0 }, /* PI2, NAND, K0 */
 { 1, PI2, K0 }, /* PI2, NAND, PI1 */
 { 0, PI1, K0 }, /* PI2, NAND, PI2 */
 { 1, NOR, PI1 }, /* PI2, NAND, NOR */
 { 1, NIMP, PI1 }, /* PI2, NAND, NLIMP */
 { 1, NOR, K0 }, /* PI2, NAND, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, NAND, NIMP */
 { 0, NOR, K0 }, /* PI2, NAND, NPI2 */
 { 1, XOR, PI1 }, /* PI2, NAND, XOR */
 { 1, NAND, PI1 }, /* PI2, NAND, NAND */
 { 1, AND, PI1 }, /* PI2, NAND, AND */
 { 1, BIIMP, PI1 }, /* PI2, NAND, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, NAND, IMP */
 { 1, IMP, PI1 }, /* PI2, NAND, LIMP */
 { 1, OR, PI1 }, /* PI2, NAND, OR */
 { 1, PI1, K1 }, /* PI2, NAND, K1 */
 { 1, K0, K0 }, /* PI2, AND, K0 */
 { 1, PI2, K0 }, /* PI2, AND, PI1 */
 { 0, PI1, K0 }, /* PI2, AND, PI2 */
 { 1, NOR, PI1 }, /* PI2, AND, NOR */
 { 1, NIMP, PI1 }, /* PI2, AND, NLIMP */
 { 1, NOR, K0 }, /* PI2, AND, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, AND, NIMP */
 { 0, NOR, K0 }, /* PI2, AND, NPI2 */
 { 1, XOR, PI1 }, /* PI2, AND, XOR */
 { 1, NAND, PI1 }, /* PI2, AND, NAND */
 { 1, AND, PI1 }, /* PI2, AND, AND */
 { 1, BIIMP, PI1 }, /* PI2, AND, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, AND, IMP */
 { 1, IMP, PI1 }, /* PI2, AND, LIMP */
 { 1, OR, PI1 }, /* PI2, AND, OR */
 { 1, PI1, K1 }, /* PI2, AND, K1 */
 { 1, K0, K0 }, /* PI2, BIIMP, K0 */
 { 1, PI2, K0 }, /* PI2, BIIMP, PI1 */
 { 0, PI1, K0 }, /* PI2, BIIMP, PI2 */
 { 1, NOR, PI1 }, /* PI2, BIIMP, NOR */
 { 1, NIMP, PI1 }, /* PI2, BIIMP, NLIMP */
 { 1, NOR, K0 }, /* PI2, BIIMP, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, BIIMP, NIMP */
 { 0, NOR, K0 }, /* PI2, BIIMP, NPI2 */
 { 1, XOR, PI1 }, /* PI2, BIIMP, XOR */
 { 1, NAND, PI1 }, /* PI2, BIIMP, NAND */
 { 1, AND, PI1 }, /* PI2, BIIMP, AND */
 { 1, BIIMP, PI1 }, /* PI2, BIIMP, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, BIIMP, IMP */
 { 1, IMP, PI1 }, /* PI2, BIIMP, LIMP */
 { 1, OR, PI1 }, /* PI2, BIIMP, OR */
 { 1, PI1, K1 }, /* PI2, BIIMP, K1 */
 { 1, K0, K0 }, /* PI2, IMP, K0 */
 { 1, PI2, K0 }, /* PI2, IMP, PI1 */
 { 0, PI1, K0 }, /* PI2, IMP, PI2 */
 { 1, NOR, PI1 }, /* PI2, IMP, NOR */
 { 1, NIMP, PI1 }, /* PI2, IMP, NLIMP */
 { 1, NOR, K0 }, /* PI2, IMP, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, IMP, NIMP */
 { 0, NOR, K0 }, /* PI2, IMP, NPI2 */
 { 1, XOR, PI1 }, /* PI2, IMP, XOR */
 { 1, NAND, PI1 }, /* PI2, IMP, NAND */
 { 1, AND, PI1 }, /* PI2, IMP, AND */
 { 1, BIIMP, PI1 }, /* PI2, IMP, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, IMP, IMP */
 { 1, IMP, PI1 }, /* PI2, IMP, LIMP */
 { 1, OR, PI1 }, /* PI2, IMP, OR */
 { 1, PI1, K1 }, /* PI2, IMP, K1 */
 { 1, K0, K0 }, /* PI2, LIMP, K0 */
 { 1, PI2, K0 }, /* PI2, LIMP, PI1 */
 { 0, PI1, K0 }, /* PI2, LIMP, PI2 */
 { 1, NOR, PI1 }, /* PI2, LIMP, NOR */
 { 1, NIMP, PI1 }, /* PI2, LIMP, NLIMP */
 { 1, NOR, K0 }, /* PI2, LIMP, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, LIMP, NIMP */
 { 0, NOR, K0 }, /* PI2, LIMP, NPI2 */
 { 1, XOR, PI1 }, /* PI2, LIMP, XOR */
 { 1, NAND, PI1 }, /* PI2, LIMP, NAND */
 { 1, AND, PI1 }, /* PI2, LIMP, AND */
 { 1, BIIMP, PI1 }, /* PI2, LIMP, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, LIMP, IMP */
 { 1, IMP, PI1 }, /* PI2, LIMP, LIMP */
 { 1, OR, PI1 }, /* PI2, LIMP, OR */
 { 1, PI1, K1 }, /* PI2, LIMP, K1 */
 { 1, K0, K0 }, /* PI2, OR, K0 */
 { 1, PI2, K0 }, /* PI2, OR, PI1 */
 { 0, PI1, K0 }, /* PI2, OR, PI2 */
 { 1, NOR, PI1 }, /* PI2, OR, NOR */
 { 1, NIMP, PI1 }, /* PI2, OR, NLIMP */
 { 1, NOR, K0 }, /* PI2, OR, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, OR, NIMP */
 { 0, NOR, K0 }, /* PI2, OR, NPI2 */
 { 1, XOR, PI1 }, /* PI2, OR, XOR */
 { 1, NAND, PI1 }, /* PI2, OR, NAND */
 { 1, AND, PI1 }, /* PI2, OR, AND */
 { 1, BIIMP, PI1 }, /* PI2, OR, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, OR, IMP */
 { 1, IMP, PI1 }, /* PI2, OR, LIMP */
 { 1, OR, PI1 }, /* PI2, OR, OR */
 { 1, PI1, K1 }, /* PI2, OR, K1 */
 { 1, K0, K0 }, /* PI2, K1, K0 */
 { 1, PI2, K0 }, /* PI2, K1, PI1 */
 { 0, PI1, K0 }, /* PI2, K1, PI2 */
 { 1, NOR, PI1 }, /* PI2, K1, NOR */
 { 1, NIMP, PI1 }, /* PI2, K1, NLIMP */
 { 1, NOR, K0 }, /* PI2, K1, NPI1 */
 { 1, NLIMP, PI1 }, /* PI2, K1, NIMP */
 { 0, NOR, K0 }, /* PI2, K1, NPI2 */
 { 1, XOR, PI1 }, /* PI2, K1, XOR */
 { 1, NAND, PI1 }, /* PI2, K1, NAND */
 { 1, AND, PI1 }, /* PI2, K1, AND */
 { 1, BIIMP, PI1 }, /* PI2, K1, BIIMP */
 { 1, LIMP, PI1 }, /* PI2, K1, IMP */
 { 1, IMP, PI1 }, /* PI2, K1, LIMP */
 { 1, OR, PI1 }, /* PI2, K1, OR */
 { 1, PI1, K1 }, /* PI2, K1, K1 */
 { 1, PI1, K1 }, /* NOR, K0, K0 */
 { 1, NOR, K0 }, /* NOR, K0, PI1 */
 { 0, NOR, K0 }, /* NOR, K0, PI2 */
 { 1, OR, PI1 }, /* NOR, K0, NOR */
 { 1, IMP, PI1 }, /* NOR, K0, NLIMP */
 { 1, PI2, K0 }, /* NOR, K0, NPI1 */
 { 1, LIMP, PI1 }, /* NOR, K0, NIMP */
 { 0, PI1, K0 }, /* NOR, K0, NPI2 */
 { 1, BIIMP, PI1 }, /* NOR, K0, XOR */
 { 1, AND, PI1 }, /* NOR, K0, NAND */
 { 1, NAND, PI1 }, /* NOR, K0, AND */
 { 1, XOR, PI1 }, /* NOR, K0, BIIMP */
 { 1, NLIMP, PI1 }, /* NOR, K0, IMP */
 { 1, NIMP, PI1 }, /* NOR, K0, LIMP */
 { 1, NOR, PI1 }, /* NOR, K0, OR */
 { 1, K0, K0 }, /* NOR, K0, K1 */
 { 0, NOR, K0 }, /* NOR, PI1, K0 */
 { 1, NOR, PI1 }, /* NOR, PI1, PI1 */
 { 0, NOR, K0 }, /* NOR, PI1, PI2 */
 { 1, NLIMP, PI1 }, /* NOR, PI1, NOR */
 { 0, NOR, K0 }, /* NOR, PI1, NLIMP */
 { 1, NLIMP, PI1 }, /* NOR, PI1, NPI1 */
 { 1, NOR, PI1 }, /* NOR, PI1, NIMP */
 { 1, K0, K0 }, /* NOR, PI1, NPI2 */
 { 1, NOR, PI1 }, /* NOR, PI1, XOR */
 { 1, K0, K0 }, /* NOR, PI1, NAND */
 { 0, NOR, K0 }, /* NOR, PI1, AND */
 { 1, NLIMP, PI1 }, /* NOR, PI1, BIIMP */
 { 1, NLIMP, PI1 }, /* NOR, PI1, IMP */
 { 1, K0, K0 }, /* NOR, PI1, LIMP */
 { 1, NOR, PI1 }, /* NOR, PI1, OR */
 { 1, K0, K0 }, /* NOR, PI1, K1 */
 { 1, NPI1, PI2 }, /* NOR, PI2, K0 */
 { 0, PI2, NOR }, /* NOR, PI2, PI1 */
 { 1, PI1, NOR }, /* NOR, PI2, PI2 */
 { 0, NOP, NOP }, /* NOR, PI2, NOR */
 { 0, NOP, NOP }, /* NOR, PI2, NLIMP */
 { 0, PI2, NLIMP }, /* NOR, PI2, NPI1 */
 { 0, NOP, NOP }, /* NOR, PI2, NIMP */
 { 1, PI1, NIMP }, /* NOR, PI2, NPI2 */
 { 0, NOP, NOP }, /* NOR, PI2, XOR */
 { 1, NLIMP, IMP }, /* NOR, PI2, NAND */
 { 0, NOP, NOP }, /* NOR, PI2, AND */
 { 0, NOP, NOP }, /* NOR, PI2, BIIMP */
 { 0, NOR, LIMP }, /* NOR, PI2, IMP */
 { 1, NOR, IMP }, /* NOR, PI2, LIMP */
 { 1, NOR, OR }, /* NOR, PI2, OR */
 { 1, K0, K0 }, /* NOR, PI2, K1 */
 { 1, PI1, OR }, /* NOR, NOR, K0 */
 { 1, NOR, NOR }, /* NOR, NOR, PI1 */
 { 1, PI1, NLIMP }, /* NOR, NOR, PI2 */
 { 0, LIMP, NAND }, /* NOR, NOR, NOR */
 { 0, NOP, BIIMP }, /* NOR, NOR, NLIMP */
 { 1, NLIMP, NOR }, /* NOR, NOR, NPI1 */
 { 0, LIMP, IMP }, /* NOR, NOR, NIMP */
 { 0, PI1, K0 }, /* NOR, NOR, NPI2 */
 { 0, NOP, NOP }, /* NOR, NOR, XOR */
 { 1, AND, PI1 }, /* NOR, NOR, NAND */
 { 0, NOP, BIIMP }, /* NOR, NOR, AND */
 { 0, NOP, NOP }, /* NOR, NOR, BIIMP */
 { 0, NOR, NAND }, /* NOR, NOR, IMP */
 { 1, NIMP, PI1 }, /* NOR, NOR, LIMP */
 { 0, NOR, IMP }, /* NOR, NOR, OR */
 { 1, K0, K0 }, /* NOR, NOR, K1 */
 { 1, PI1, LIMP }, /* NOR, NLIMP, K0 */
 { 1, NOR, NLIMP }, /* NOR, NLIMP, PI1 */
 { 1, PI1, NOR }, /* NOR, NLIMP, PI2 */
 { 0, LIMP, LIMP }, /* NOR, NLIMP, NOR */
 { 0, NOP, BIIMP }, /* NOR, NLIMP, NLIMP */
 { 1, NLIMP, NLIMP }, /* NOR, NLIMP, NPI1 */
 { 0, LIMP, OR }, /* NOR, NLIMP, NIMP */
 { 0, PI1, K0 }, /* NOR, NLIMP, NPI2 */
 { 0, NOP, NOP }, /* NOR, NLIMP, XOR */
 { 1, AND, PI1 }, /* NOR, NLIMP, NAND */
 { 0, NOP, BIIMP }, /* NOR, NLIMP, AND */
 { 0, NOP, NOP }, /* NOR, NLIMP, BIIMP */
 { 0, NOR, LIMP }, /* NOR, NLIMP, IMP */
 { 1, NIMP, PI1 }, /* NOR, NLIMP, LIMP */
 { 1, NOR, OR }, /* NOR, NLIMP, OR */
 { 1, K0, K0 }, /* NOR, NLIMP, K1 */
 { 0, PI1, K0 }, /* NOR, NPI1, K0 */
 { 1, NIMP, PI1 }, /* NOR, NPI1, PI1 */
 { 1, K0, K0 }, /* NOR, NPI1, PI2 */
 { 0, PI1, K0 }, /* NOR, NPI1, NOR */
 { 1, AND, PI1 }, /* NOR, NPI1, NLIMP */
 { 1, AND, PI1 }, /* NOR, NPI1, NPI1 */
 { 0, PI1, K0 }, /* NOR, NPI1, NIMP */
 { 0, PI1, K0 }, /* NOR, NPI1, NPI2 */
 { 1, AND, PI1 }, /* NOR, NPI1, XOR */
 { 1, AND, PI1 }, /* NOR, NPI1, NAND */
 { 1, NIMP, PI1 }, /* NOR, NPI1, AND */
 { 1, NIMP, PI1 }, /* NOR, NPI1, BIIMP */
 { 1, K0, K0 }, /* NOR, NPI1, IMP */
 { 1, NIMP, PI1 }, /* NOR, NPI1, LIMP */
 { 1, K0, K0 }, /* NOR, NPI1, OR */
 { 1, K0, K0 }, /* NOR, NPI1, K1 */
 { 1, PI1, IMP }, /* NOR, NIMP, K0 */
 { 1, NOR, NIMP }, /* NOR, NIMP, PI1 */
 { 0, NOR, K0 }, /* NOR, NIMP, PI2 */
 { 0, NOP, BIIMP }, /* NOR, NIMP, NOR */
 { 0, NAND, NAND }, /* NOR, NIMP, NLIMP */
 { 1, NLIMP, NIMP }, /* NOR, NIMP, NPI1 */
 { 0, NOP, BIIMP }, /* NOR, NIMP, NIMP */
 { 1, PI1, AND }, /* NOR, NIMP, NPI2 */
 { 0, NOP, NOP }, /* NOR, NIMP, XOR */
 { 1, NLIMP, NAND }, /* NOR, NIMP, NAND */
 { 0, NAND, IMP }, /* NOR, NIMP, AND */
 { 0, NOP, NOP }, /* NOR, NIMP, BIIMP */
 { 1, NLIMP, PI1 }, /* NOR, NIMP, IMP */
 { 1, NOR, NAND }, /* NOR, NIMP, LIMP */
 { 1, NOR, PI1 }, /* NOR, NIMP, OR */
 { 1, K0, K0 }, /* NOR, NIMP, K1 */
 { 1, PI1, PI2 }, /* NOR, NPI2, K0 */
 { 0, PI2, NIMP }, /* NOR, NPI2, PI1 */
 { 1, PI1, NLIMP }, /* NOR, NPI2, PI2 */
 { 0, NOP, NOP }, /* NOR, NPI2, NOR */
 { 0, NOP, NOP }, /* NOR, NPI2, NLIMP */
 { 0, PI2, AND }, /* NOR, NPI2, NPI1 */
 { 0, NOP, NOP }, /* NOR, NPI2, NIMP */
 { 1, PI1, AND }, /* NOR, NPI2, NPI2 */
 { 0, NOP, NOP }, /* NOR, NPI2, XOR */
 { 1, NLIMP, NAND }, /* NOR, NPI2, NAND */
 { 0, NOP, NOP }, /* NOR, NPI2, AND */
 { 0, NOP, NOP }, /* NOR, NPI2, BIIMP */
 { 0, NOR, NAND }, /* NOR, NPI2, IMP */
 { 1, NOR, NAND }, /* NOR, NPI2, LIMP */
 { 0, NOR, IMP }, /* NOR, NPI2, OR */
 { 1, K0, K0 }, /* NOR, NPI2, K1 */
 { 1, PI1, BIIMP }, /* NOR, XOR, K0 */
 { 1, NOR, XOR }, /* NOR, XOR, PI1 */
 { 1, PI1, NOR }, /* NOR, XOR, PI2 */
 { 0, NOP, NOP }, /* NOR, XOR, NOR */
 { 0, NOP, NOP }, /* NOR, XOR, NLIMP */
 { 1, NLIMP, XOR }, /* NOR, XOR, NPI1 */
 { 0, NOP, NOP }, /* NOR, XOR, NIMP */
 { 1, PI1, AND }, /* NOR, XOR, NPI2 */
 { 0, NOP, NOP }, /* NOR, XOR, XOR */
 { 1, NLIMP, NAND }, /* NOR, XOR, NAND */
 { 0, NOP, NOP }, /* NOR, XOR, AND */
 { 0, NOP, NOP }, /* NOR, XOR, BIIMP */
 { 0, NOR, LIMP }, /* NOR, XOR, IMP */
 { 1, NOR, NAND }, /* NOR, XOR, LIMP */
 { 1, NOR, OR }, /* NOR, XOR, OR */
 { 1, K0, K0 }, /* NOR, XOR, K1 */
 { 1, PI1, AND }, /* NOR, NAND, K0 */
 { 1, NOR, NAND }, /* NOR, NAND, PI1 */
 { 1, K0, K0 }, /* NOR, NAND, PI2 */
 { 1, PI1, AND }, /* NOR, NAND, NOR */
 { 1, NLIMP, NAND }, /* NOR, NAND, NLIMP */
 { 1, NLIMP, NAND }, /* NOR, NAND, NPI1 */
 { 1, PI1, AND }, /* NOR, NAND, NIMP */
 { 1, PI1, AND }, /* NOR, NAND, NPI2 */
 { 1, NLIMP, NAND }, /* NOR, NAND, XOR */
 { 1, NLIMP, NAND }, /* NOR, NAND, NAND */
 { 1, NOR, NAND }, /* NOR, NAND, AND */
 { 1, NOR, NAND }, /* NOR, NAND, BIIMP */
 { 1, K0, K0 }, /* NOR, NAND, IMP */
 { 1, NOR, NAND }, /* NOR, NAND, LIMP */
 { 1, K0, K0 }, /* NOR, NAND, OR */
 { 1, K0, K0 }, /* NOR, NAND, K1 */
 { 1, PI1, NAND }, /* NOR, AND, K0 */
 { 1, NOR, AND }, /* NOR, AND, PI1 */
 { 0, NOR, K0 }, /* NOR, AND, PI2 */
 { 0, NOP, BIIMP }, /* NOR, AND, NOR */
 { 0, NAND, LIMP }, /* NOR, AND, NLIMP */
 { 1, NLIMP, AND }, /* NOR, AND, NPI1 */
 { 0, NOP, BIIMP }, /* NOR, AND, NIMP */
 { 1, PI1, NIMP }, /* NOR, AND, NPI2 */
 { 0, NOP, NOP }, /* NOR, AND, XOR */
 { 1, NLIMP, IMP }, /* NOR, AND, NAND */
 { 0, NAND, OR }, /* NOR, AND, AND */
 { 0, NOP, NOP }, /* NOR, AND, BIIMP */
 { 1, NLIMP, PI1 }, /* NOR, AND, IMP */
 { 1, NOR, IMP }, /* NOR, AND, LIMP */
 { 1, NOR, PI1 }, /* NOR, AND, OR */
 { 1, K0, K0 }, /* NOR, AND, K1 */
 { 1, PI1, XOR }, /* NOR, BIIMP, K0 */
 { 1, NOR, BIIMP }, /* NOR, BIIMP, PI1 */
 { 1, PI1, NLIMP }, /* NOR, BIIMP, PI2 */
 { 0, NOP, NOP }, /* NOR, BIIMP, NOR */
 { 0, NOP, NOP }, /* NOR, BIIMP, NLIMP */
 { 1, NLIMP, BIIMP }, /* NOR, BIIMP, NPI1 */
 { 0, NOP, NOP }, /* NOR, BIIMP, NIMP */
 { 1, PI1, NIMP }, /* NOR, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* NOR, BIIMP, XOR */
 { 1, NLIMP, IMP }, /* NOR, BIIMP, NAND */
 { 0, NOP, NOP }, /* NOR, BIIMP, AND */
 { 0, NOP, NOP }, /* NOR, BIIMP, BIIMP */
 { 0, NOR, NAND }, /* NOR, BIIMP, IMP */
 { 1, NOR, IMP }, /* NOR, BIIMP, LIMP */
 { 0, NOR, IMP }, /* NOR, BIIMP, OR */
 { 1, K0, K0 }, /* NOR, BIIMP, K1 */
 { 1, PI1, NIMP }, /* NOR, IMP, K0 */
 { 1, NOR, IMP }, /* NOR, IMP, PI1 */
 { 1, K0, K0 }, /* NOR, IMP, PI2 */
 { 1, PI1, NIMP }, /* NOR, IMP, NOR */
 { 1, NLIMP, IMP }, /* NOR, IMP, NLIMP */
 { 1, NLIMP, IMP }, /* NOR, IMP, NPI1 */
 { 1, PI1, NIMP }, /* NOR, IMP, NIMP */
 { 1, PI1, NIMP }, /* NOR, IMP, NPI2 */
 { 1, NLIMP, IMP }, /* NOR, IMP, XOR */
 { 1, NLIMP, IMP }, /* NOR, IMP, NAND */
 { 1, NOR, IMP }, /* NOR, IMP, AND */
 { 1, NOR, IMP }, /* NOR, IMP, BIIMP */
 { 1, K0, K0 }, /* NOR, IMP, IMP */
 { 1, NOR, IMP }, /* NOR, IMP, LIMP */
 { 1, K0, K0 }, /* NOR, IMP, OR */
 { 1, K0, K0 }, /* NOR, IMP, K1 */
 { 1, PI1, NLIMP }, /* NOR, LIMP, K0 */
 { 0, NOR, IMP }, /* NOR, LIMP, PI1 */
 { 1, PI1, NLIMP }, /* NOR, LIMP, PI2 */
 { 0, NOR, NAND }, /* NOR, LIMP, NOR */
 { 1, PI1, NLIMP }, /* NOR, LIMP, NLIMP */
 { 0, NOR, NAND }, /* NOR, LIMP, NPI1 */
 { 0, NOR, IMP }, /* NOR, LIMP, NIMP */
 { 1, K0, K0 }, /* NOR, LIMP, NPI2 */
 { 0, NOR, IMP }, /* NOR, LIMP, XOR */
 { 1, K0, K0 }, /* NOR, LIMP, NAND */
 { 1, PI1, NLIMP }, /* NOR, LIMP, AND */
 { 0, NOR, NAND }, /* NOR, LIMP, BIIMP */
 { 0, NOR, NAND }, /* NOR, LIMP, IMP */
 { 1, K0, K0 }, /* NOR, LIMP, LIMP */
 { 0, NOR, IMP }, /* NOR, LIMP, OR */
 { 1, K0, K0 }, /* NOR, LIMP, K1 */
 { 1, PI1, NOR }, /* NOR, OR, K0 */
 { 1, NOR, OR }, /* NOR, OR, PI1 */
 { 1, PI1, NOR }, /* NOR, OR, PI2 */
 { 0, NOR, LIMP }, /* NOR, OR, NOR */
 { 1, PI1, NOR }, /* NOR, OR, NLIMP */
 { 0, NOR, LIMP }, /* NOR, OR, NPI1 */
 { 1, NOR, OR }, /* NOR, OR, NIMP */
 { 1, K0, K0 }, /* NOR, OR, NPI2 */
 { 1, NOR, OR }, /* NOR, OR, XOR */
 { 1, K0, K0 }, /* NOR, OR, NAND */
 { 1, PI1, NOR }, /* NOR, OR, AND */
 { 0, NOR, LIMP }, /* NOR, OR, BIIMP */
 { 0, NOR, LIMP }, /* NOR, OR, IMP */
 { 1, K0, K0 }, /* NOR, OR, LIMP */
 { 1, NOR, OR }, /* NOR, OR, OR */
 { 1, K0, K0 }, /* NOR, OR, K1 */
 { 1, K0, K0 }, /* NOR, K1, K0 */
 { 1, K0, K0 }, /* NOR, K1, PI1 */
 { 1, K0, K0 }, /* NOR, K1, PI2 */
 { 1, K0, K0 }, /* NOR, K1, NOR */
 { 1, K0, K0 }, /* NOR, K1, NLIMP */
 { 1, K0, K0 }, /* NOR, K1, NPI1 */
 { 1, K0, K0 }, /* NOR, K1, NIMP */
 { 1, K0, K0 }, /* NOR, K1, NPI2 */
 { 1, K0, K0 }, /* NOR, K1, XOR */
 { 1, K0, K0 }, /* NOR, K1, NAND */
 { 1, K0, K0 }, /* NOR, K1, AND */
 { 1, K0, K0 }, /* NOR, K1, BIIMP */
 { 1, K0, K0 }, /* NOR, K1, IMP */
 { 1, K0, K0 }, /* NOR, K1, LIMP */
 { 1, K0, K0 }, /* NOR, K1, OR */
 { 1, K0, K0 }, /* NOR, K1, K1 */
 { 1, K0, K0 }, /* NLIMP, K0, K0 */
 { 1, PI2, K0 }, /* NLIMP, K0, PI1 */
 { 0, PI1, K0 }, /* NLIMP, K0, PI2 */
 { 1, NOR, PI1 }, /* NLIMP, K0, NOR */
 { 1, NIMP, PI1 }, /* NLIMP, K0, NLIMP */
 { 1, NOR, K0 }, /* NLIMP, K0, NPI1 */
 { 1, NLIMP, PI1 }, /* NLIMP, K0, NIMP */
 { 0, NOR, K0 }, /* NLIMP, K0, NPI2 */
 { 1, XOR, PI1 }, /* NLIMP, K0, XOR */
 { 1, NAND, PI1 }, /* NLIMP, K0, NAND */
 { 1, AND, PI1 }, /* NLIMP, K0, AND */
 { 1, BIIMP, PI1 }, /* NLIMP, K0, BIIMP */
 { 1, LIMP, PI1 }, /* NLIMP, K0, IMP */
 { 1, IMP, PI1 }, /* NLIMP, K0, LIMP */
 { 1, OR, PI1 }, /* NLIMP, K0, OR */
 { 1, PI1, K1 }, /* NLIMP, K0, K1 */
 { 1, K0, K0 }, /* NLIMP, PI1, K0 */
 { 1, NLIMP, PI1 }, /* NLIMP, PI1, PI1 */
 { 1, K0, K0 }, /* NLIMP, PI1, PI2 */
 { 1, NOR, PI1 }, /* NLIMP, PI1, NOR */
 { 1, K0, K0 }, /* NLIMP, PI1, NLIMP */
 { 1, NOR, PI1 }, /* NLIMP, PI1, NPI1 */
 { 1, NLIMP, PI1 }, /* NLIMP, PI1, NIMP */
 { 0, NOR, K0 }, /* NLIMP, PI1, NPI2 */
 { 1, NLIMP, PI1 }, /* NLIMP, PI1, XOR */
 { 0, NOR, K0 }, /* NLIMP, PI1, NAND */
 { 1, K0, K0 }, /* NLIMP, PI1, AND */
 { 1, NOR, PI1 }, /* NLIMP, PI1, BIIMP */
 { 1, NOR, PI1 }, /* NLIMP, PI1, IMP */
 { 0, NOR, K0 }, /* NLIMP, PI1, LIMP */
 { 1, NLIMP, PI1 }, /* NLIMP, PI1, OR */
 { 0, NOR, K0 }, /* NLIMP, PI1, K1 */
 { 1, K0, K0 }, /* NLIMP, PI2, K0 */
 { 0, PI2, NLIMP }, /* NLIMP, PI2, PI1 */
 { 1, PI1, NIMP }, /* NLIMP, PI2, PI2 */
 { 1, NOR, OR }, /* NLIMP, PI2, NOR */
 { 1, NOR, IMP }, /* NLIMP, PI2, NLIMP */
 { 0, PI2, NOR }, /* NLIMP, PI2, NPI1 */
 { 0, NOR, LIMP }, /* NLIMP, PI2, NIMP */
 { 1, PI1, NOR }, /* NLIMP, PI2, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, PI2, XOR */
 { 0, NOP, NOP }, /* NLIMP, PI2, NAND */
 { 1, NLIMP, IMP }, /* NLIMP, PI2, AND */
 { 0, NOP, NOP }, /* NLIMP, PI2, BIIMP */
 { 0, NOP, NOP }, /* NLIMP, PI2, IMP */
 { 0, NOP, NOP }, /* NLIMP, PI2, LIMP */
 { 0, NOP, NOP }, /* NLIMP, PI2, OR */
 { 1, NPI1, PI2 }, /* NLIMP, PI2, K1 */
 { 1, K0, K0 }, /* NLIMP, NOR, K0 */
 { 1, NLIMP, NOR }, /* NLIMP, NOR, PI1 */
 { 0, PI1, K0 }, /* NLIMP, NOR, PI2 */
 { 0, NOR, IMP }, /* NLIMP, NOR, NOR */
 { 1, NIMP, PI1 }, /* NLIMP, NOR, NLIMP */
 { 1, NOR, NOR }, /* NLIMP, NOR, NPI1 */
 { 0, NOR, NAND }, /* NLIMP, NOR, NIMP */
 { 1, PI1, NLIMP }, /* NLIMP, NOR, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, NOR, XOR */
 { 0, NOP, XOR }, /* NLIMP, NOR, NAND */
 { 1, AND, PI1 }, /* NLIMP, NOR, AND */
 { 0, NOP, NOP }, /* NLIMP, NOR, BIIMP */
 { 0, LIMP, IMP }, /* NLIMP, NOR, IMP */
 { 0, NOP, XOR }, /* NLIMP, NOR, LIMP */
 { 0, LIMP, NAND }, /* NLIMP, NOR, OR */
 { 1, PI1, OR }, /* NLIMP, NOR, K1 */
 { 1, K0, K0 }, /* NLIMP, NLIMP, K0 */
 { 1, NLIMP, NLIMP }, /* NLIMP, NLIMP, PI1 */
 { 0, PI1, K0 }, /* NLIMP, NLIMP, PI2 */
 { 1, NOR, OR }, /* NLIMP, NLIMP, NOR */
 { 1, NIMP, PI1 }, /* NLIMP, NLIMP, NLIMP */
 { 1, NOR, NLIMP }, /* NLIMP, NLIMP, NPI1 */
 { 0, NOR, LIMP }, /* NLIMP, NLIMP, NIMP */
 { 1, PI1, NOR }, /* NLIMP, NLIMP, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, NLIMP, XOR */
 { 0, NOP, XOR }, /* NLIMP, NLIMP, NAND */
 { 1, AND, PI1 }, /* NLIMP, NLIMP, AND */
 { 0, NOP, NOP }, /* NLIMP, NLIMP, BIIMP */
 { 0, LIMP, OR }, /* NLIMP, NLIMP, IMP */
 { 0, NOP, XOR }, /* NLIMP, NLIMP, LIMP */
 { 0, LIMP, LIMP }, /* NLIMP, NLIMP, OR */
 { 1, PI1, LIMP }, /* NLIMP, NLIMP, K1 */
 { 1, K0, K0 }, /* NLIMP, NPI1, K0 */
 { 1, AND, PI1 }, /* NLIMP, NPI1, PI1 */
 { 0, PI1, K0 }, /* NLIMP, NPI1, PI2 */
 { 1, K0, K0 }, /* NLIMP, NPI1, NOR */
 { 1, NIMP, PI1 }, /* NLIMP, NPI1, NLIMP */
 { 1, NIMP, PI1 }, /* NLIMP, NPI1, NPI1 */
 { 1, K0, K0 }, /* NLIMP, NPI1, NIMP */
 { 1, K0, K0 }, /* NLIMP, NPI1, NPI2 */
 { 1, NIMP, PI1 }, /* NLIMP, NPI1, XOR */
 { 1, NIMP, PI1 }, /* NLIMP, NPI1, NAND */
 { 1, AND, PI1 }, /* NLIMP, NPI1, AND */
 { 1, AND, PI1 }, /* NLIMP, NPI1, BIIMP */
 { 0, PI1, K0 }, /* NLIMP, NPI1, IMP */
 { 1, AND, PI1 }, /* NLIMP, NPI1, LIMP */
 { 0, PI1, K0 }, /* NLIMP, NPI1, OR */
 { 0, PI1, K0 }, /* NLIMP, NPI1, K1 */
 { 1, K0, K0 }, /* NLIMP, NIMP, K0 */
 { 1, NLIMP, NIMP }, /* NLIMP, NIMP, PI1 */
 { 1, PI1, AND }, /* NLIMP, NIMP, PI2 */
 { 1, NOR, PI1 }, /* NLIMP, NIMP, NOR */
 { 1, NOR, NAND }, /* NLIMP, NIMP, NLIMP */
 { 1, NOR, NIMP }, /* NLIMP, NIMP, NPI1 */
 { 1, NLIMP, PI1 }, /* NLIMP, NIMP, NIMP */
 { 0, NOR, K0 }, /* NLIMP, NIMP, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, NIMP, XOR */
 { 0, NAND, IMP }, /* NLIMP, NIMP, NAND */
 { 1, NLIMP, NAND }, /* NLIMP, NIMP, AND */
 { 0, NOP, NOP }, /* NLIMP, NIMP, BIIMP */
 { 0, NOP, XOR }, /* NLIMP, NIMP, IMP */
 { 0, NAND, NAND }, /* NLIMP, NIMP, LIMP */
 { 0, NOP, XOR }, /* NLIMP, NIMP, OR */
 { 1, PI1, IMP }, /* NLIMP, NIMP, K1 */
 { 1, K0, K0 }, /* NLIMP, NPI2, K0 */
 { 0, PI2, AND }, /* NLIMP, NPI2, PI1 */
 { 1, PI1, AND }, /* NLIMP, NPI2, PI2 */
 { 0, NOR, IMP }, /* NLIMP, NPI2, NOR */
 { 1, NOR, NAND }, /* NLIMP, NPI2, NLIMP */
 { 0, PI2, NIMP }, /* NLIMP, NPI2, NPI1 */
 { 0, NOR, NAND }, /* NLIMP, NPI2, NIMP */
 { 1, PI1, NLIMP }, /* NLIMP, NPI2, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, NPI2, XOR */
 { 0, NOP, NOP }, /* NLIMP, NPI2, NAND */
 { 1, NLIMP, NAND }, /* NLIMP, NPI2, AND */
 { 0, NOP, NOP }, /* NLIMP, NPI2, BIIMP */
 { 0, NOP, NOP }, /* NLIMP, NPI2, IMP */
 { 0, NOP, NOP }, /* NLIMP, NPI2, LIMP */
 { 0, NOP, NOP }, /* NLIMP, NPI2, OR */
 { 1, PI1, PI2 }, /* NLIMP, NPI2, K1 */
 { 1, K0, K0 }, /* NLIMP, XOR, K0 */
 { 1, NLIMP, XOR }, /* NLIMP, XOR, PI1 */
 { 1, PI1, AND }, /* NLIMP, XOR, PI2 */
 { 1, NOR, OR }, /* NLIMP, XOR, NOR */
 { 1, NOR, NAND }, /* NLIMP, XOR, NLIMP */
 { 1, NOR, XOR }, /* NLIMP, XOR, NPI1 */
 { 0, NOR, LIMP }, /* NLIMP, XOR, NIMP */
 { 1, PI1, NOR }, /* NLIMP, XOR, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, XOR, XOR */
 { 0, NOP, NOP }, /* NLIMP, XOR, NAND */
 { 1, NLIMP, NAND }, /* NLIMP, XOR, AND */
 { 0, NOP, NOP }, /* NLIMP, XOR, BIIMP */
 { 0, NOP, NOP }, /* NLIMP, XOR, IMP */
 { 0, NOP, NOP }, /* NLIMP, XOR, LIMP */
 { 0, NOP, NOP }, /* NLIMP, XOR, OR */
 { 1, PI1, BIIMP }, /* NLIMP, XOR, K1 */
 { 1, K0, K0 }, /* NLIMP, NAND, K0 */
 { 1, NLIMP, NAND }, /* NLIMP, NAND, PI1 */
 { 1, PI1, AND }, /* NLIMP, NAND, PI2 */
 { 1, K0, K0 }, /* NLIMP, NAND, NOR */
 { 1, NOR, NAND }, /* NLIMP, NAND, NLIMP */
 { 1, NOR, NAND }, /* NLIMP, NAND, NPI1 */
 { 1, K0, K0 }, /* NLIMP, NAND, NIMP */
 { 1, K0, K0 }, /* NLIMP, NAND, NPI2 */
 { 1, NOR, NAND }, /* NLIMP, NAND, XOR */
 { 1, NOR, NAND }, /* NLIMP, NAND, NAND */
 { 1, NLIMP, NAND }, /* NLIMP, NAND, AND */
 { 1, NLIMP, NAND }, /* NLIMP, NAND, BIIMP */
 { 1, PI1, AND }, /* NLIMP, NAND, IMP */
 { 1, NLIMP, NAND }, /* NLIMP, NAND, LIMP */
 { 1, PI1, AND }, /* NLIMP, NAND, OR */
 { 1, PI1, AND }, /* NLIMP, NAND, K1 */
 { 1, K0, K0 }, /* NLIMP, AND, K0 */
 { 1, NLIMP, AND }, /* NLIMP, AND, PI1 */
 { 1, PI1, NIMP }, /* NLIMP, AND, PI2 */
 { 1, NOR, PI1 }, /* NLIMP, AND, NOR */
 { 1, NOR, IMP }, /* NLIMP, AND, NLIMP */
 { 1, NOR, AND }, /* NLIMP, AND, NPI1 */
 { 1, NLIMP, PI1 }, /* NLIMP, AND, NIMP */
 { 0, NOR, K0 }, /* NLIMP, AND, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, AND, XOR */
 { 0, NAND, OR }, /* NLIMP, AND, NAND */
 { 1, NLIMP, IMP }, /* NLIMP, AND, AND */
 { 0, NOP, NOP }, /* NLIMP, AND, BIIMP */
 { 0, NOP, XOR }, /* NLIMP, AND, IMP */
 { 0, NAND, LIMP }, /* NLIMP, AND, LIMP */
 { 0, NOP, XOR }, /* NLIMP, AND, OR */
 { 1, PI1, NAND }, /* NLIMP, AND, K1 */
 { 1, K0, K0 }, /* NLIMP, BIIMP, K0 */
 { 1, NLIMP, BIIMP }, /* NLIMP, BIIMP, PI1 */
 { 1, PI1, NIMP }, /* NLIMP, BIIMP, PI2 */
 { 0, NOR, IMP }, /* NLIMP, BIIMP, NOR */
 { 1, NOR, IMP }, /* NLIMP, BIIMP, NLIMP */
 { 1, NOR, BIIMP }, /* NLIMP, BIIMP, NPI1 */
 { 0, NOR, NAND }, /* NLIMP, BIIMP, NIMP */
 { 1, PI1, NLIMP }, /* NLIMP, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* NLIMP, BIIMP, XOR */
 { 0, NOP, NOP }, /* NLIMP, BIIMP, NAND */
 { 1, NLIMP, IMP }, /* NLIMP, BIIMP, AND */
 { 0, NOP, NOP }, /* NLIMP, BIIMP, BIIMP */
 { 0, NOP, NOP }, /* NLIMP, BIIMP, IMP */
 { 0, NOP, NOP }, /* NLIMP, BIIMP, LIMP */
 { 0, NOP, NOP }, /* NLIMP, BIIMP, OR */
 { 1, PI1, XOR }, /* NLIMP, BIIMP, K1 */
 { 1, K0, K0 }, /* NLIMP, IMP, K0 */
 { 1, NLIMP, IMP }, /* NLIMP, IMP, PI1 */
 { 1, PI1, NIMP }, /* NLIMP, IMP, PI2 */
 { 1, K0, K0 }, /* NLIMP, IMP, NOR */
 { 1, NOR, IMP }, /* NLIMP, IMP, NLIMP */
 { 1, NOR, IMP }, /* NLIMP, IMP, NPI1 */
 { 1, K0, K0 }, /* NLIMP, IMP, NIMP */
 { 1, K0, K0 }, /* NLIMP, IMP, NPI2 */
 { 1, NOR, IMP }, /* NLIMP, IMP, XOR */
 { 1, NOR, IMP }, /* NLIMP, IMP, NAND */
 { 1, NLIMP, IMP }, /* NLIMP, IMP, AND */
 { 1, NLIMP, IMP }, /* NLIMP, IMP, BIIMP */
 { 1, PI1, NIMP }, /* NLIMP, IMP, IMP */
 { 1, NLIMP, IMP }, /* NLIMP, IMP, LIMP */
 { 1, PI1, NIMP }, /* NLIMP, IMP, OR */
 { 1, PI1, NIMP }, /* NLIMP, IMP, K1 */
 { 1, K0, K0 }, /* NLIMP, LIMP, K0 */
 { 0, NOR, NAND }, /* NLIMP, LIMP, PI1 */
 { 1, K0, K0 }, /* NLIMP, LIMP, PI2 */
 { 0, NOR, IMP }, /* NLIMP, LIMP, NOR */
 { 1, K0, K0 }, /* NLIMP, LIMP, NLIMP */
 { 0, NOR, IMP }, /* NLIMP, LIMP, NPI1 */
 { 0, NOR, NAND }, /* NLIMP, LIMP, NIMP */
 { 1, PI1, NLIMP }, /* NLIMP, LIMP, NPI2 */
 { 0, NOR, NAND }, /* NLIMP, LIMP, XOR */
 { 1, PI1, NLIMP }, /* NLIMP, LIMP, NAND */
 { 1, K0, K0 }, /* NLIMP, LIMP, AND */
 { 0, NOR, IMP }, /* NLIMP, LIMP, BIIMP */
 { 0, NOR, IMP }, /* NLIMP, LIMP, IMP */
 { 1, PI1, NLIMP }, /* NLIMP, LIMP, LIMP */
 { 0, NOR, NAND }, /* NLIMP, LIMP, OR */
 { 1, PI1, NLIMP }, /* NLIMP, LIMP, K1 */
 { 1, K0, K0 }, /* NLIMP, OR, K0 */
 { 0, NOR, LIMP }, /* NLIMP, OR, PI1 */
 { 1, K0, K0 }, /* NLIMP, OR, PI2 */
 { 1, NOR, OR }, /* NLIMP, OR, NOR */
 { 1, K0, K0 }, /* NLIMP, OR, NLIMP */
 { 1, NOR, OR }, /* NLIMP, OR, NPI1 */
 { 0, NOR, LIMP }, /* NLIMP, OR, NIMP */
 { 1, PI1, NOR }, /* NLIMP, OR, NPI2 */
 { 0, NOR, LIMP }, /* NLIMP, OR, XOR */
 { 1, PI1, NOR }, /* NLIMP, OR, NAND */
 { 1, K0, K0 }, /* NLIMP, OR, AND */
 { 1, NOR, OR }, /* NLIMP, OR, BIIMP */
 { 1, NOR, OR }, /* NLIMP, OR, IMP */
 { 1, PI1, NOR }, /* NLIMP, OR, LIMP */
 { 0, NOR, LIMP }, /* NLIMP, OR, OR */
 { 1, PI1, NOR }, /* NLIMP, OR, K1 */
 { 1, K0, K0 }, /* NLIMP, K1, K0 */
 { 1, K0, K0 }, /* NLIMP, K1, PI1 */
 { 1, K0, K0 }, /* NLIMP, K1, PI2 */
 { 1, K0, K0 }, /* NLIMP, K1, NOR */
 { 1, K0, K0 }, /* NLIMP, K1, NLIMP */
 { 1, K0, K0 }, /* NLIMP, K1, NPI1 */
 { 1, K0, K0 }, /* NLIMP, K1, NIMP */
 { 1, K0, K0 }, /* NLIMP, K1, NPI2 */
 { 1, K0, K0 }, /* NLIMP, K1, XOR */
 { 1, K0, K0 }, /* NLIMP, K1, NAND */
 { 1, K0, K0 }, /* NLIMP, K1, AND */
 { 1, K0, K0 }, /* NLIMP, K1, BIIMP */
 { 1, K0, K0 }, /* NLIMP, K1, IMP */
 { 1, K0, K0 }, /* NLIMP, K1, LIMP */
 { 1, K0, K0 }, /* NLIMP, K1, OR */
 { 1, K0, K0 }, /* NLIMP, K1, K1 */
 { 1, PI1, K1 }, /* NPI1, K0, K0 */
 { 1, PI1, K1 }, /* NPI1, K0, PI1 */
 { 1, PI1, K1 }, /* NPI1, K0, PI2 */
 { 1, PI1, K1 }, /* NPI1, K0, NOR */
 { 1, PI1, K1 }, /* NPI1, K0, NLIMP */
 { 1, PI1, K1 }, /* NPI1, K0, NPI1 */
 { 1, PI1, K1 }, /* NPI1, K0, NIMP */
 { 1, PI1, K1 }, /* NPI1, K0, NPI2 */
 { 1, PI1, K1 }, /* NPI1, K0, XOR */
 { 1, PI1, K1 }, /* NPI1, K0, NAND */
 { 1, PI1, K1 }, /* NPI1, K0, AND */
 { 1, PI1, K1 }, /* NPI1, K0, BIIMP */
 { 1, PI1, K1 }, /* NPI1, K0, IMP */
 { 1, PI1, K1 }, /* NPI1, K0, LIMP */
 { 1, PI1, K1 }, /* NPI1, K0, OR */
 { 1, PI1, K1 }, /* NPI1, K0, K1 */
 { 0, NOR, K0 }, /* NPI1, PI1, K0 */
 { 0, NOR, K0 }, /* NPI1, PI1, PI1 */
 { 0, NOR, K0 }, /* NPI1, PI1, PI2 */
 { 0, NOR, K0 }, /* NPI1, PI1, NOR */
 { 0, NOR, K0 }, /* NPI1, PI1, NLIMP */
 { 0, NOR, K0 }, /* NPI1, PI1, NPI1 */
 { 0, NOR, K0 }, /* NPI1, PI1, NIMP */
 { 0, NOR, K0 }, /* NPI1, PI1, NPI2 */
 { 0, NOR, K0 }, /* NPI1, PI1, XOR */
 { 0, NOR, K0 }, /* NPI1, PI1, NAND */
 { 0, NOR, K0 }, /* NPI1, PI1, AND */
 { 0, NOR, K0 }, /* NPI1, PI1, BIIMP */
 { 0, NOR, K0 }, /* NPI1, PI1, IMP */
 { 0, NOR, K0 }, /* NPI1, PI1, LIMP */
 { 0, NOR, K0 }, /* NPI1, PI1, OR */
 { 0, NOR, K0 }, /* NPI1, PI1, K1 */
 { 1, NPI1, PI2 }, /* NPI1, PI2, K0 */
 { 1, NPI1, PI2 }, /* NPI1, PI2, PI1 */
 { 1, NPI1, PI2 }, /* NPI1, PI2, PI2 */
 { 1, NPI1, PI2 }, /* NPI1, PI2, NOR */
 { 1, NPI1, PI2 }, /* NPI1, PI2, NLIMP */
 { 1, NPI1, PI2 }, /* NPI1, PI2, NPI1 */
 { 1, NPI1, PI2 }, /* NPI1, PI2, NIMP */
 { 1, NPI1, PI2 }, /* NPI1, PI2, NPI2 */
 { 1, NPI1, PI2 }, /* NPI1, PI2, XOR */
 { 1, NPI1, PI2 }, /* NPI1, PI2, NAND */
 { 1, NPI1, PI2 }, /* NPI1, PI2, AND */
 { 1, NPI1, PI2 }, /* NPI1, PI2, BIIMP */
 { 1, NPI1, PI2 }, /* NPI1, PI2, IMP */
 { 1, NPI1, PI2 }, /* NPI1, PI2, LIMP */
 { 1, NPI1, PI2 }, /* NPI1, PI2, OR */
 { 1, NPI1, PI2 }, /* NPI1, PI2, K1 */
 { 1, PI1, OR }, /* NPI1, NOR, K0 */
 { 1, PI1, OR }, /* NPI1, NOR, PI1 */
 { 1, PI1, OR }, /* NPI1, NOR, PI2 */
 { 1, PI1, OR }, /* NPI1, NOR, NOR */
 { 1, PI1, OR }, /* NPI1, NOR, NLIMP */
 { 1, PI1, OR }, /* NPI1, NOR, NPI1 */
 { 1, PI1, OR }, /* NPI1, NOR, NIMP */
 { 1, PI1, OR }, /* NPI1, NOR, NPI2 */
 { 1, PI1, OR }, /* NPI1, NOR, XOR */
 { 1, PI1, OR }, /* NPI1, NOR, NAND */
 { 1, PI1, OR }, /* NPI1, NOR, AND */
 { 1, PI1, OR }, /* NPI1, NOR, BIIMP */
 { 1, PI1, OR }, /* NPI1, NOR, IMP */
 { 1, PI1, OR }, /* NPI1, NOR, LIMP */
 { 1, PI1, OR }, /* NPI1, NOR, OR */
 { 1, PI1, OR }, /* NPI1, NOR, K1 */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, K0 */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, PI1 */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, PI2 */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, NOR */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, NLIMP */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, NPI1 */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, NIMP */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, NPI2 */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, XOR */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, NAND */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, AND */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, BIIMP */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, IMP */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, LIMP */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, OR */
 { 1, PI1, LIMP }, /* NPI1, NLIMP, K1 */
 { 0, PI1, K0 }, /* NPI1, NPI1, K0 */
 { 0, PI1, K0 }, /* NPI1, NPI1, PI1 */
 { 0, PI1, K0 }, /* NPI1, NPI1, PI2 */
 { 0, PI1, K0 }, /* NPI1, NPI1, NOR */
 { 0, PI1, K0 }, /* NPI1, NPI1, NLIMP */
 { 0, PI1, K0 }, /* NPI1, NPI1, NPI1 */
 { 0, PI1, K0 }, /* NPI1, NPI1, NIMP */
 { 0, PI1, K0 }, /* NPI1, NPI1, NPI2 */
 { 0, PI1, K0 }, /* NPI1, NPI1, XOR */
 { 0, PI1, K0 }, /* NPI1, NPI1, NAND */
 { 0, PI1, K0 }, /* NPI1, NPI1, AND */
 { 0, PI1, K0 }, /* NPI1, NPI1, BIIMP */
 { 0, PI1, K0 }, /* NPI1, NPI1, IMP */
 { 0, PI1, K0 }, /* NPI1, NPI1, LIMP */
 { 0, PI1, K0 }, /* NPI1, NPI1, OR */
 { 0, PI1, K0 }, /* NPI1, NPI1, K1 */
 { 1, PI1, IMP }, /* NPI1, NIMP, K0 */
 { 1, PI1, IMP }, /* NPI1, NIMP, PI1 */
 { 1, PI1, IMP }, /* NPI1, NIMP, PI2 */
 { 1, PI1, IMP }, /* NPI1, NIMP, NOR */
 { 1, PI1, IMP }, /* NPI1, NIMP, NLIMP */
 { 1, PI1, IMP }, /* NPI1, NIMP, NPI1 */
 { 1, PI1, IMP }, /* NPI1, NIMP, NIMP */
 { 1, PI1, IMP }, /* NPI1, NIMP, NPI2 */
 { 1, PI1, IMP }, /* NPI1, NIMP, XOR */
 { 1, PI1, IMP }, /* NPI1, NIMP, NAND */
 { 1, PI1, IMP }, /* NPI1, NIMP, AND */
 { 1, PI1, IMP }, /* NPI1, NIMP, BIIMP */
 { 1, PI1, IMP }, /* NPI1, NIMP, IMP */
 { 1, PI1, IMP }, /* NPI1, NIMP, LIMP */
 { 1, PI1, IMP }, /* NPI1, NIMP, OR */
 { 1, PI1, IMP }, /* NPI1, NIMP, K1 */
 { 1, PI1, PI2 }, /* NPI1, NPI2, K0 */
 { 1, PI1, PI2 }, /* NPI1, NPI2, PI1 */
 { 1, PI1, PI2 }, /* NPI1, NPI2, PI2 */
 { 1, PI1, PI2 }, /* NPI1, NPI2, NOR */
 { 1, PI1, PI2 }, /* NPI1, NPI2, NLIMP */
 { 1, PI1, PI2 }, /* NPI1, NPI2, NPI1 */
 { 1, PI1, PI2 }, /* NPI1, NPI2, NIMP */
 { 1, PI1, PI2 }, /* NPI1, NPI2, NPI2 */
 { 1, PI1, PI2 }, /* NPI1, NPI2, XOR */
 { 1, PI1, PI2 }, /* NPI1, NPI2, NAND */
 { 1, PI1, PI2 }, /* NPI1, NPI2, AND */
 { 1, PI1, PI2 }, /* NPI1, NPI2, BIIMP */
 { 1, PI1, PI2 }, /* NPI1, NPI2, IMP */
 { 1, PI1, PI2 }, /* NPI1, NPI2, LIMP */
 { 1, PI1, PI2 }, /* NPI1, NPI2, OR */
 { 1, PI1, PI2 }, /* NPI1, NPI2, K1 */
 { 1, PI1, BIIMP }, /* NPI1, XOR, K0 */
 { 1, PI1, BIIMP }, /* NPI1, XOR, PI1 */
 { 1, PI1, BIIMP }, /* NPI1, XOR, PI2 */
 { 1, PI1, BIIMP }, /* NPI1, XOR, NOR */
 { 1, PI1, BIIMP }, /* NPI1, XOR, NLIMP */
 { 1, PI1, BIIMP }, /* NPI1, XOR, NPI1 */
 { 1, PI1, BIIMP }, /* NPI1, XOR, NIMP */
 { 1, PI1, BIIMP }, /* NPI1, XOR, NPI2 */
 { 1, PI1, BIIMP }, /* NPI1, XOR, XOR */
 { 1, PI1, BIIMP }, /* NPI1, XOR, NAND */
 { 1, PI1, BIIMP }, /* NPI1, XOR, AND */
 { 1, PI1, BIIMP }, /* NPI1, XOR, BIIMP */
 { 1, PI1, BIIMP }, /* NPI1, XOR, IMP */
 { 1, PI1, BIIMP }, /* NPI1, XOR, LIMP */
 { 1, PI1, BIIMP }, /* NPI1, XOR, OR */
 { 1, PI1, BIIMP }, /* NPI1, XOR, K1 */
 { 1, PI1, AND }, /* NPI1, NAND, K0 */
 { 1, PI1, AND }, /* NPI1, NAND, PI1 */
 { 1, PI1, AND }, /* NPI1, NAND, PI2 */
 { 1, PI1, AND }, /* NPI1, NAND, NOR */
 { 1, PI1, AND }, /* NPI1, NAND, NLIMP */
 { 1, PI1, AND }, /* NPI1, NAND, NPI1 */
 { 1, PI1, AND }, /* NPI1, NAND, NIMP */
 { 1, PI1, AND }, /* NPI1, NAND, NPI2 */
 { 1, PI1, AND }, /* NPI1, NAND, XOR */
 { 1, PI1, AND }, /* NPI1, NAND, NAND */
 { 1, PI1, AND }, /* NPI1, NAND, AND */
 { 1, PI1, AND }, /* NPI1, NAND, BIIMP */
 { 1, PI1, AND }, /* NPI1, NAND, IMP */
 { 1, PI1, AND }, /* NPI1, NAND, LIMP */
 { 1, PI1, AND }, /* NPI1, NAND, OR */
 { 1, PI1, AND }, /* NPI1, NAND, K1 */
 { 1, PI1, NAND }, /* NPI1, AND, K0 */
 { 1, PI1, NAND }, /* NPI1, AND, PI1 */
 { 1, PI1, NAND }, /* NPI1, AND, PI2 */
 { 1, PI1, NAND }, /* NPI1, AND, NOR */
 { 1, PI1, NAND }, /* NPI1, AND, NLIMP */
 { 1, PI1, NAND }, /* NPI1, AND, NPI1 */
 { 1, PI1, NAND }, /* NPI1, AND, NIMP */
 { 1, PI1, NAND }, /* NPI1, AND, NPI2 */
 { 1, PI1, NAND }, /* NPI1, AND, XOR */
 { 1, PI1, NAND }, /* NPI1, AND, NAND */
 { 1, PI1, NAND }, /* NPI1, AND, AND */
 { 1, PI1, NAND }, /* NPI1, AND, BIIMP */
 { 1, PI1, NAND }, /* NPI1, AND, IMP */
 { 1, PI1, NAND }, /* NPI1, AND, LIMP */
 { 1, PI1, NAND }, /* NPI1, AND, OR */
 { 1, PI1, NAND }, /* NPI1, AND, K1 */
 { 1, PI1, XOR }, /* NPI1, BIIMP, K0 */
 { 1, PI1, XOR }, /* NPI1, BIIMP, PI1 */
 { 1, PI1, XOR }, /* NPI1, BIIMP, PI2 */
 { 1, PI1, XOR }, /* NPI1, BIIMP, NOR */
 { 1, PI1, XOR }, /* NPI1, BIIMP, NLIMP */
 { 1, PI1, XOR }, /* NPI1, BIIMP, NPI1 */
 { 1, PI1, XOR }, /* NPI1, BIIMP, NIMP */
 { 1, PI1, XOR }, /* NPI1, BIIMP, NPI2 */
 { 1, PI1, XOR }, /* NPI1, BIIMP, XOR */
 { 1, PI1, XOR }, /* NPI1, BIIMP, NAND */
 { 1, PI1, XOR }, /* NPI1, BIIMP, AND */
 { 1, PI1, XOR }, /* NPI1, BIIMP, BIIMP */
 { 1, PI1, XOR }, /* NPI1, BIIMP, IMP */
 { 1, PI1, XOR }, /* NPI1, BIIMP, LIMP */
 { 1, PI1, XOR }, /* NPI1, BIIMP, OR */
 { 1, PI1, XOR }, /* NPI1, BIIMP, K1 */
 { 1, PI1, NIMP }, /* NPI1, IMP, K0 */
 { 1, PI1, NIMP }, /* NPI1, IMP, PI1 */
 { 1, PI1, NIMP }, /* NPI1, IMP, PI2 */
 { 1, PI1, NIMP }, /* NPI1, IMP, NOR */
 { 1, PI1, NIMP }, /* NPI1, IMP, NLIMP */
 { 1, PI1, NIMP }, /* NPI1, IMP, NPI1 */
 { 1, PI1, NIMP }, /* NPI1, IMP, NIMP */
 { 1, PI1, NIMP }, /* NPI1, IMP, NPI2 */
 { 1, PI1, NIMP }, /* NPI1, IMP, XOR */
 { 1, PI1, NIMP }, /* NPI1, IMP, NAND */
 { 1, PI1, NIMP }, /* NPI1, IMP, AND */
 { 1, PI1, NIMP }, /* NPI1, IMP, BIIMP */
 { 1, PI1, NIMP }, /* NPI1, IMP, IMP */
 { 1, PI1, NIMP }, /* NPI1, IMP, LIMP */
 { 1, PI1, NIMP }, /* NPI1, IMP, OR */
 { 1, PI1, NIMP }, /* NPI1, IMP, K1 */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, K0 */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, PI1 */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, PI2 */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, NOR */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, NLIMP */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, NPI1 */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, NIMP */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, NPI2 */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, XOR */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, NAND */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, AND */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, BIIMP */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, IMP */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, LIMP */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, OR */
 { 1, PI1, NLIMP }, /* NPI1, LIMP, K1 */
 { 1, PI1, NOR }, /* NPI1, OR, K0 */
 { 1, PI1, NOR }, /* NPI1, OR, PI1 */
 { 1, PI1, NOR }, /* NPI1, OR, PI2 */
 { 1, PI1, NOR }, /* NPI1, OR, NOR */
 { 1, PI1, NOR }, /* NPI1, OR, NLIMP */
 { 1, PI1, NOR }, /* NPI1, OR, NPI1 */
 { 1, PI1, NOR }, /* NPI1, OR, NIMP */
 { 1, PI1, NOR }, /* NPI1, OR, NPI2 */
 { 1, PI1, NOR }, /* NPI1, OR, XOR */
 { 1, PI1, NOR }, /* NPI1, OR, NAND */
 { 1, PI1, NOR }, /* NPI1, OR, AND */
 { 1, PI1, NOR }, /* NPI1, OR, BIIMP */
 { 1, PI1, NOR }, /* NPI1, OR, IMP */
 { 1, PI1, NOR }, /* NPI1, OR, LIMP */
 { 1, PI1, NOR }, /* NPI1, OR, OR */
 { 1, PI1, NOR }, /* NPI1, OR, K1 */
 { 1, K0, K0 }, /* NPI1, K1, K0 */
 { 1, K0, K0 }, /* NPI1, K1, PI1 */
 { 1, K0, K0 }, /* NPI1, K1, PI2 */
 { 1, K0, K0 }, /* NPI1, K1, NOR */
 { 1, K0, K0 }, /* NPI1, K1, NLIMP */
 { 1, K0, K0 }, /* NPI1, K1, NPI1 */
 { 1, K0, K0 }, /* NPI1, K1, NIMP */
 { 1, K0, K0 }, /* NPI1, K1, NPI2 */
 { 1, K0, K0 }, /* NPI1, K1, XOR */
 { 1, K0, K0 }, /* NPI1, K1, NAND */
 { 1, K0, K0 }, /* NPI1, K1, AND */
 { 1, K0, K0 }, /* NPI1, K1, BIIMP */
 { 1, K0, K0 }, /* NPI1, K1, IMP */
 { 1, K0, K0 }, /* NPI1, K1, LIMP */
 { 1, K0, K0 }, /* NPI1, K1, OR */
 { 1, K0, K0 }, /* NPI1, K1, K1 */
 { 1, K0, K0 }, /* NIMP, K0, K0 */
 { 1, K0, K0 }, /* NIMP, K0, PI1 */
 { 1, K0, K0 }, /* NIMP, K0, PI2 */
 { 1, K0, K0 }, /* NIMP, K0, NOR */
 { 1, K0, K0 }, /* NIMP, K0, NLIMP */
 { 1, K0, K0 }, /* NIMP, K0, NPI1 */
 { 1, K0, K0 }, /* NIMP, K0, NIMP */
 { 1, K0, K0 }, /* NIMP, K0, NPI2 */
 { 1, K0, K0 }, /* NIMP, K0, XOR */
 { 1, K0, K0 }, /* NIMP, K0, NAND */
 { 1, K0, K0 }, /* NIMP, K0, AND */
 { 1, K0, K0 }, /* NIMP, K0, BIIMP */
 { 1, K0, K0 }, /* NIMP, K0, IMP */
 { 1, K0, K0 }, /* NIMP, K0, LIMP */
 { 1, K0, K0 }, /* NIMP, K0, OR */
 { 1, K0, K0 }, /* NIMP, K0, K1 */
 { 0, PI1, K0 }, /* NIMP, PI1, K0 */
 { 1, NIMP, PI1 }, /* NIMP, PI1, PI1 */
 { 1, K0, K0 }, /* NIMP, PI1, PI2 */
 { 0, PI1, K0 }, /* NIMP, PI1, NOR */
 { 1, AND, PI1 }, /* NIMP, PI1, NLIMP */
 { 1, AND, PI1 }, /* NIMP, PI1, NPI1 */
 { 0, PI1, K0 }, /* NIMP, PI1, NIMP */
 { 0, PI1, K0 }, /* NIMP, PI1, NPI2 */
 { 1, AND, PI1 }, /* NIMP, PI1, XOR */
 { 1, AND, PI1 }, /* NIMP, PI1, NAND */
 { 1, NIMP, PI1 }, /* NIMP, PI1, AND */
 { 1, NIMP, PI1 }, /* NIMP, PI1, BIIMP */
 { 1, K0, K0 }, /* NIMP, PI1, IMP */
 { 1, NIMP, PI1 }, /* NIMP, PI1, LIMP */
 { 1, K0, K0 }, /* NIMP, PI1, OR */
 { 1, K0, K0 }, /* NIMP, PI1, K1 */
 { 1, PI1, PI2 }, /* NIMP, PI2, K0 */
 { 0, PI2, NIMP }, /* NIMP, PI2, PI1 */
 { 1, PI1, NLIMP }, /* NIMP, PI2, PI2 */
 { 0, NOP, NOP }, /* NIMP, PI2, NOR */
 { 0, NOP, NOP }, /* NIMP, PI2, NLIMP */
 { 0, PI2, AND }, /* NIMP, PI2, NPI1 */
 { 0, NOP, NOP }, /* NIMP, PI2, NIMP */
 { 1, PI1, AND }, /* NIMP, PI2, NPI2 */
 { 0, NOP, NOP }, /* NIMP, PI2, XOR */
 { 1, NLIMP, NAND }, /* NIMP, PI2, NAND */
 { 0, NOP, NOP }, /* NIMP, PI2, AND */
 { 0, NOP, NOP }, /* NIMP, PI2, BIIMP */
 { 0, NOR, NAND }, /* NIMP, PI2, IMP */
 { 1, NOR, NAND }, /* NIMP, PI2, LIMP */
 { 0, NOR, IMP }, /* NIMP, PI2, OR */
 { 1, K0, K0 }, /* NIMP, PI2, K1 */
 { 1, PI1, NOR }, /* NIMP, NOR, K0 */
 { 1, NOR, OR }, /* NIMP, NOR, PI1 */
 { 1, PI1, NOR }, /* NIMP, NOR, PI2 */
 { 0, NOR, LIMP }, /* NIMP, NOR, NOR */
 { 1, PI1, NOR }, /* NIMP, NOR, NLIMP */
 { 0, NOR, LIMP }, /* NIMP, NOR, NPI1 */
 { 1, NOR, OR }, /* NIMP, NOR, NIMP */
 { 1, K0, K0 }, /* NIMP, NOR, NPI2 */
 { 1, NOR, OR }, /* NIMP, NOR, XOR */
 { 1, K0, K0 }, /* NIMP, NOR, NAND */
 { 1, PI1, NOR }, /* NIMP, NOR, AND */
 { 0, NOR, LIMP }, /* NIMP, NOR, BIIMP */
 { 0, NOR, LIMP }, /* NIMP, NOR, IMP */
 { 1, K0, K0 }, /* NIMP, NOR, LIMP */
 { 1, NOR, OR }, /* NIMP, NOR, OR */
 { 1, K0, K0 }, /* NIMP, NOR, K1 */
 { 1, PI1, NLIMP }, /* NIMP, NLIMP, K0 */
 { 0, NOR, IMP }, /* NIMP, NLIMP, PI1 */
 { 1, PI1, NLIMP }, /* NIMP, NLIMP, PI2 */
 { 0, NOR, NAND }, /* NIMP, NLIMP, NOR */
 { 1, PI1, NLIMP }, /* NIMP, NLIMP, NLIMP */
 { 0, NOR, NAND }, /* NIMP, NLIMP, NPI1 */
 { 0, NOR, IMP }, /* NIMP, NLIMP, NIMP */
 { 1, K0, K0 }, /* NIMP, NLIMP, NPI2 */
 { 0, NOR, IMP }, /* NIMP, NLIMP, XOR */
 { 1, K0, K0 }, /* NIMP, NLIMP, NAND */
 { 1, PI1, NLIMP }, /* NIMP, NLIMP, AND */
 { 0, NOR, NAND }, /* NIMP, NLIMP, BIIMP */
 { 0, NOR, NAND }, /* NIMP, NLIMP, IMP */
 { 1, K0, K0 }, /* NIMP, NLIMP, LIMP */
 { 0, NOR, IMP }, /* NIMP, NLIMP, OR */
 { 1, K0, K0 }, /* NIMP, NLIMP, K1 */
 { 0, NOR, K0 }, /* NIMP, NPI1, K0 */
 { 1, NOR, PI1 }, /* NIMP, NPI1, PI1 */
 { 0, NOR, K0 }, /* NIMP, NPI1, PI2 */
 { 1, NLIMP, PI1 }, /* NIMP, NPI1, NOR */
 { 0, NOR, K0 }, /* NIMP, NPI1, NLIMP */
 { 1, NLIMP, PI1 }, /* NIMP, NPI1, NPI1 */
 { 1, NOR, PI1 }, /* NIMP, NPI1, NIMP */
 { 1, K0, K0 }, /* NIMP, NPI1, NPI2 */
 { 1, NOR, PI1 }, /* NIMP, NPI1, XOR */
 { 1, K0, K0 }, /* NIMP, NPI1, NAND */
 { 0, NOR, K0 }, /* NIMP, NPI1, AND */
 { 1, NLIMP, PI1 }, /* NIMP, NPI1, BIIMP */
 { 1, NLIMP, PI1 }, /* NIMP, NPI1, IMP */
 { 1, K0, K0 }, /* NIMP, NPI1, LIMP */
 { 1, NOR, PI1 }, /* NIMP, NPI1, OR */
 { 1, K0, K0 }, /* NIMP, NPI1, K1 */
 { 1, PI1, NIMP }, /* NIMP, NIMP, K0 */
 { 1, NOR, IMP }, /* NIMP, NIMP, PI1 */
 { 1, K0, K0 }, /* NIMP, NIMP, PI2 */
 { 1, PI1, NIMP }, /* NIMP, NIMP, NOR */
 { 1, NLIMP, IMP }, /* NIMP, NIMP, NLIMP */
 { 1, NLIMP, IMP }, /* NIMP, NIMP, NPI1 */
 { 1, PI1, NIMP }, /* NIMP, NIMP, NIMP */
 { 1, PI1, NIMP }, /* NIMP, NIMP, NPI2 */
 { 1, NLIMP, IMP }, /* NIMP, NIMP, XOR */
 { 1, NLIMP, IMP }, /* NIMP, NIMP, NAND */
 { 1, NOR, IMP }, /* NIMP, NIMP, AND */
 { 1, NOR, IMP }, /* NIMP, NIMP, BIIMP */
 { 1, K0, K0 }, /* NIMP, NIMP, IMP */
 { 1, NOR, IMP }, /* NIMP, NIMP, LIMP */
 { 1, K0, K0 }, /* NIMP, NIMP, OR */
 { 1, K0, K0 }, /* NIMP, NIMP, K1 */
 { 1, NPI1, PI2 }, /* NIMP, NPI2, K0 */
 { 0, PI2, NOR }, /* NIMP, NPI2, PI1 */
 { 1, PI1, NOR }, /* NIMP, NPI2, PI2 */
 { 0, NOP, NOP }, /* NIMP, NPI2, NOR */
 { 0, NOP, NOP }, /* NIMP, NPI2, NLIMP */
 { 0, PI2, NLIMP }, /* NIMP, NPI2, NPI1 */
 { 0, NOP, NOP }, /* NIMP, NPI2, NIMP */
 { 1, PI1, NIMP }, /* NIMP, NPI2, NPI2 */
 { 0, NOP, NOP }, /* NIMP, NPI2, XOR */
 { 1, NLIMP, IMP }, /* NIMP, NPI2, NAND */
 { 0, NOP, NOP }, /* NIMP, NPI2, AND */
 { 0, NOP, NOP }, /* NIMP, NPI2, BIIMP */
 { 0, NOR, LIMP }, /* NIMP, NPI2, IMP */
 { 1, NOR, IMP }, /* NIMP, NPI2, LIMP */
 { 1, NOR, OR }, /* NIMP, NPI2, OR */
 { 1, K0, K0 }, /* NIMP, NPI2, K1 */
 { 1, PI1, XOR }, /* NIMP, XOR, K0 */
 { 1, NOR, BIIMP }, /* NIMP, XOR, PI1 */
 { 1, PI1, NLIMP }, /* NIMP, XOR, PI2 */
 { 0, NOP, NOP }, /* NIMP, XOR, NOR */
 { 0, NOP, NOP }, /* NIMP, XOR, NLIMP */
 { 1, NLIMP, BIIMP }, /* NIMP, XOR, NPI1 */
 { 0, NOP, NOP }, /* NIMP, XOR, NIMP */
 { 1, PI1, NIMP }, /* NIMP, XOR, NPI2 */
 { 0, NOP, NOP }, /* NIMP, XOR, XOR */
 { 1, NLIMP, IMP }, /* NIMP, XOR, NAND */
 { 0, NOP, NOP }, /* NIMP, XOR, AND */
 { 0, NOP, NOP }, /* NIMP, XOR, BIIMP */
 { 0, NOR, NAND }, /* NIMP, XOR, IMP */
 { 1, NOR, IMP }, /* NIMP, XOR, LIMP */
 { 0, NOR, IMP }, /* NIMP, XOR, OR */
 { 1, K0, K0 }, /* NIMP, XOR, K1 */
 { 1, PI1, NAND }, /* NIMP, NAND, K0 */
 { 1, NOR, AND }, /* NIMP, NAND, PI1 */
 { 0, NOR, K0 }, /* NIMP, NAND, PI2 */
 { 0, NOP, XOR }, /* NIMP, NAND, NOR */
 { 0, NAND, LIMP }, /* NIMP, NAND, NLIMP */
 { 1, NLIMP, AND }, /* NIMP, NAND, NPI1 */
 { 0, NOP, XOR }, /* NIMP, NAND, NIMP */
 { 1, PI1, NIMP }, /* NIMP, NAND, NPI2 */
 { 0, NOP, NOP }, /* NIMP, NAND, XOR */
 { 1, NLIMP, IMP }, /* NIMP, NAND, NAND */
 { 0, NAND, OR }, /* NIMP, NAND, AND */
 { 0, NOP, NOP }, /* NIMP, NAND, BIIMP */
 { 1, NLIMP, PI1 }, /* NIMP, NAND, IMP */
 { 1, NOR, IMP }, /* NIMP, NAND, LIMP */
 { 1, NOR, PI1 }, /* NIMP, NAND, OR */
 { 1, K0, K0 }, /* NIMP, NAND, K1 */
 { 1, PI1, AND }, /* NIMP, AND, K0 */
 { 1, NOR, NAND }, /* NIMP, AND, PI1 */
 { 1, K0, K0 }, /* NIMP, AND, PI2 */
 { 1, PI1, AND }, /* NIMP, AND, NOR */
 { 1, NLIMP, NAND }, /* NIMP, AND, NLIMP */
 { 1, NLIMP, NAND }, /* NIMP, AND, NPI1 */
 { 1, PI1, AND }, /* NIMP, AND, NIMP */
 { 1, PI1, AND }, /* NIMP, AND, NPI2 */
 { 1, NLIMP, NAND }, /* NIMP, AND, XOR */
 { 1, NLIMP, NAND }, /* NIMP, AND, NAND */
 { 1, NOR, NAND }, /* NIMP, AND, AND */
 { 1, NOR, NAND }, /* NIMP, AND, BIIMP */
 { 1, K0, K0 }, /* NIMP, AND, IMP */
 { 1, NOR, NAND }, /* NIMP, AND, LIMP */
 { 1, K0, K0 }, /* NIMP, AND, OR */
 { 1, K0, K0 }, /* NIMP, AND, K1 */
 { 1, PI1, BIIMP }, /* NIMP, BIIMP, K0 */
 { 1, NOR, XOR }, /* NIMP, BIIMP, PI1 */
 { 1, PI1, NOR }, /* NIMP, BIIMP, PI2 */
 { 0, NOP, NOP }, /* NIMP, BIIMP, NOR */
 { 0, NOP, NOP }, /* NIMP, BIIMP, NLIMP */
 { 1, NLIMP, XOR }, /* NIMP, BIIMP, NPI1 */
 { 0, NOP, NOP }, /* NIMP, BIIMP, NIMP */
 { 1, PI1, AND }, /* NIMP, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* NIMP, BIIMP, XOR */
 { 1, NLIMP, NAND }, /* NIMP, BIIMP, NAND */
 { 0, NOP, NOP }, /* NIMP, BIIMP, AND */
 { 0, NOP, NOP }, /* NIMP, BIIMP, BIIMP */
 { 0, NOR, LIMP }, /* NIMP, BIIMP, IMP */
 { 1, NOR, NAND }, /* NIMP, BIIMP, LIMP */
 { 1, NOR, OR }, /* NIMP, BIIMP, OR */
 { 1, K0, K0 }, /* NIMP, BIIMP, K1 */
 { 1, PI1, IMP }, /* NIMP, IMP, K0 */
 { 1, NOR, NIMP }, /* NIMP, IMP, PI1 */
 { 0, NOR, K0 }, /* NIMP, IMP, PI2 */
 { 0, NOP, XOR }, /* NIMP, IMP, NOR */
 { 0, NAND, NAND }, /* NIMP, IMP, NLIMP */
 { 1, NLIMP, NIMP }, /* NIMP, IMP, NPI1 */
 { 0, NOP, XOR }, /* NIMP, IMP, NIMP */
 { 1, PI1, AND }, /* NIMP, IMP, NPI2 */
 { 0, NOP, NOP }, /* NIMP, IMP, XOR */
 { 1, NLIMP, NAND }, /* NIMP, IMP, NAND */
 { 0, NAND, IMP }, /* NIMP, IMP, AND */
 { 0, NOP, NOP }, /* NIMP, IMP, BIIMP */
 { 1, NLIMP, PI1 }, /* NIMP, IMP, IMP */
 { 1, NOR, NAND }, /* NIMP, IMP, LIMP */
 { 1, NOR, PI1 }, /* NIMP, IMP, OR */
 { 1, K0, K0 }, /* NIMP, IMP, K1 */
 { 1, PI1, LIMP }, /* NIMP, LIMP, K0 */
 { 1, NOR, NLIMP }, /* NIMP, LIMP, PI1 */
 { 1, PI1, NOR }, /* NIMP, LIMP, PI2 */
 { 0, LIMP, LIMP }, /* NIMP, LIMP, NOR */
 { 0, NOP, XOR }, /* NIMP, LIMP, NLIMP */
 { 1, NLIMP, NLIMP }, /* NIMP, LIMP, NPI1 */
 { 0, LIMP, OR }, /* NIMP, LIMP, NIMP */
 { 0, PI1, K0 }, /* NIMP, LIMP, NPI2 */
 { 0, NOP, NOP }, /* NIMP, LIMP, XOR */
 { 1, AND, PI1 }, /* NIMP, LIMP, NAND */
 { 0, NOP, XOR }, /* NIMP, LIMP, AND */
 { 0, NOP, NOP }, /* NIMP, LIMP, BIIMP */
 { 0, NOR, LIMP }, /* NIMP, LIMP, IMP */
 { 1, NIMP, PI1 }, /* NIMP, LIMP, LIMP */
 { 1, NOR, OR }, /* NIMP, LIMP, OR */
 { 1, K0, K0 }, /* NIMP, LIMP, K1 */
 { 1, PI1, OR }, /* NIMP, OR, K0 */
 { 1, NOR, NOR }, /* NIMP, OR, PI1 */
 { 1, PI1, NLIMP }, /* NIMP, OR, PI2 */
 { 0, LIMP, NAND }, /* NIMP, OR, NOR */
 { 0, NOP, XOR }, /* NIMP, OR, NLIMP */
 { 1, NLIMP, NOR }, /* NIMP, OR, NPI1 */
 { 0, LIMP, IMP }, /* NIMP, OR, NIMP */
 { 0, PI1, K0 }, /* NIMP, OR, NPI2 */
 { 0, NOP, NOP }, /* NIMP, OR, XOR */
 { 1, AND, PI1 }, /* NIMP, OR, NAND */
 { 0, NOP, XOR }, /* NIMP, OR, AND */
 { 0, NOP, NOP }, /* NIMP, OR, BIIMP */
 { 0, NOR, NAND }, /* NIMP, OR, IMP */
 { 1, NIMP, PI1 }, /* NIMP, OR, LIMP */
 { 0, NOR, IMP }, /* NIMP, OR, OR */
 { 1, K0, K0 }, /* NIMP, OR, K1 */
 { 1, PI1, K1 }, /* NIMP, K1, K0 */
 { 1, NOR, K0 }, /* NIMP, K1, PI1 */
 { 0, NOR, K0 }, /* NIMP, K1, PI2 */
 { 1, OR, PI1 }, /* NIMP, K1, NOR */
 { 1, IMP, PI1 }, /* NIMP, K1, NLIMP */
 { 1, PI2, K0 }, /* NIMP, K1, NPI1 */
 { 1, LIMP, PI1 }, /* NIMP, K1, NIMP */
 { 0, PI1, K0 }, /* NIMP, K1, NPI2 */
 { 1, BIIMP, PI1 }, /* NIMP, K1, XOR */
 { 1, AND, PI1 }, /* NIMP, K1, NAND */
 { 1, NAND, PI1 }, /* NIMP, K1, AND */
 { 1, XOR, PI1 }, /* NIMP, K1, BIIMP */
 { 1, NLIMP, PI1 }, /* NIMP, K1, IMP */
 { 1, NIMP, PI1 }, /* NIMP, K1, LIMP */
 { 1, NOR, PI1 }, /* NIMP, K1, OR */
 { 1, K0, K0 }, /* NIMP, K1, K1 */
 { 1, PI1, K1 }, /* NPI2, K0, K0 */
 { 1, NOR, K0 }, /* NPI2, K0, PI1 */
 { 0, NOR, K0 }, /* NPI2, K0, PI2 */
 { 1, OR, PI1 }, /* NPI2, K0, NOR */
 { 1, IMP, PI1 }, /* NPI2, K0, NLIMP */
 { 1, PI2, K0 }, /* NPI2, K0, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, K0, NIMP */
 { 0, PI1, K0 }, /* NPI2, K0, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, K0, XOR */
 { 1, AND, PI1 }, /* NPI2, K0, NAND */
 { 1, NAND, PI1 }, /* NPI2, K0, AND */
 { 1, XOR, PI1 }, /* NPI2, K0, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, K0, IMP */
 { 1, NIMP, PI1 }, /* NPI2, K0, LIMP */
 { 1, NOR, PI1 }, /* NPI2, K0, OR */
 { 1, K0, K0 }, /* NPI2, K0, K1 */
 { 1, PI1, K1 }, /* NPI2, PI1, K0 */
 { 1, NOR, K0 }, /* NPI2, PI1, PI1 */
 { 0, NOR, K0 }, /* NPI2, PI1, PI2 */
 { 1, OR, PI1 }, /* NPI2, PI1, NOR */
 { 1, IMP, PI1 }, /* NPI2, PI1, NLIMP */
 { 1, PI2, K0 }, /* NPI2, PI1, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, PI1, NIMP */
 { 0, PI1, K0 }, /* NPI2, PI1, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, PI1, XOR */
 { 1, AND, PI1 }, /* NPI2, PI1, NAND */
 { 1, NAND, PI1 }, /* NPI2, PI1, AND */
 { 1, XOR, PI1 }, /* NPI2, PI1, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, PI1, IMP */
 { 1, NIMP, PI1 }, /* NPI2, PI1, LIMP */
 { 1, NOR, PI1 }, /* NPI2, PI1, OR */
 { 1, K0, K0 }, /* NPI2, PI1, K1 */
 { 1, PI1, K1 }, /* NPI2, PI2, K0 */
 { 1, NOR, K0 }, /* NPI2, PI2, PI1 */
 { 0, NOR, K0 }, /* NPI2, PI2, PI2 */
 { 1, OR, PI1 }, /* NPI2, PI2, NOR */
 { 1, IMP, PI1 }, /* NPI2, PI2, NLIMP */
 { 1, PI2, K0 }, /* NPI2, PI2, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, PI2, NIMP */
 { 0, PI1, K0 }, /* NPI2, PI2, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, PI2, XOR */
 { 1, AND, PI1 }, /* NPI2, PI2, NAND */
 { 1, NAND, PI1 }, /* NPI2, PI2, AND */
 { 1, XOR, PI1 }, /* NPI2, PI2, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, PI2, IMP */
 { 1, NIMP, PI1 }, /* NPI2, PI2, LIMP */
 { 1, NOR, PI1 }, /* NPI2, PI2, OR */
 { 1, K0, K0 }, /* NPI2, PI2, K1 */
 { 1, PI1, K1 }, /* NPI2, NOR, K0 */
 { 1, NOR, K0 }, /* NPI2, NOR, PI1 */
 { 0, NOR, K0 }, /* NPI2, NOR, PI2 */
 { 1, OR, PI1 }, /* NPI2, NOR, NOR */
 { 1, IMP, PI1 }, /* NPI2, NOR, NLIMP */
 { 1, PI2, K0 }, /* NPI2, NOR, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, NOR, NIMP */
 { 0, PI1, K0 }, /* NPI2, NOR, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, NOR, XOR */
 { 1, AND, PI1 }, /* NPI2, NOR, NAND */
 { 1, NAND, PI1 }, /* NPI2, NOR, AND */
 { 1, XOR, PI1 }, /* NPI2, NOR, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, NOR, IMP */
 { 1, NIMP, PI1 }, /* NPI2, NOR, LIMP */
 { 1, NOR, PI1 }, /* NPI2, NOR, OR */
 { 1, K0, K0 }, /* NPI2, NOR, K1 */
 { 1, PI1, K1 }, /* NPI2, NLIMP, K0 */
 { 1, NOR, K0 }, /* NPI2, NLIMP, PI1 */
 { 0, NOR, K0 }, /* NPI2, NLIMP, PI2 */
 { 1, OR, PI1 }, /* NPI2, NLIMP, NOR */
 { 1, IMP, PI1 }, /* NPI2, NLIMP, NLIMP */
 { 1, PI2, K0 }, /* NPI2, NLIMP, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, NLIMP, NIMP */
 { 0, PI1, K0 }, /* NPI2, NLIMP, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, NLIMP, XOR */
 { 1, AND, PI1 }, /* NPI2, NLIMP, NAND */
 { 1, NAND, PI1 }, /* NPI2, NLIMP, AND */
 { 1, XOR, PI1 }, /* NPI2, NLIMP, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, NLIMP, IMP */
 { 1, NIMP, PI1 }, /* NPI2, NLIMP, LIMP */
 { 1, NOR, PI1 }, /* NPI2, NLIMP, OR */
 { 1, K0, K0 }, /* NPI2, NLIMP, K1 */
 { 1, PI1, K1 }, /* NPI2, NPI1, K0 */
 { 1, NOR, K0 }, /* NPI2, NPI1, PI1 */
 { 0, NOR, K0 }, /* NPI2, NPI1, PI2 */
 { 1, OR, PI1 }, /* NPI2, NPI1, NOR */
 { 1, IMP, PI1 }, /* NPI2, NPI1, NLIMP */
 { 1, PI2, K0 }, /* NPI2, NPI1, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, NPI1, NIMP */
 { 0, PI1, K0 }, /* NPI2, NPI1, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, NPI1, XOR */
 { 1, AND, PI1 }, /* NPI2, NPI1, NAND */
 { 1, NAND, PI1 }, /* NPI2, NPI1, AND */
 { 1, XOR, PI1 }, /* NPI2, NPI1, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, NPI1, IMP */
 { 1, NIMP, PI1 }, /* NPI2, NPI1, LIMP */
 { 1, NOR, PI1 }, /* NPI2, NPI1, OR */
 { 1, K0, K0 }, /* NPI2, NPI1, K1 */
 { 1, PI1, K1 }, /* NPI2, NIMP, K0 */
 { 1, NOR, K0 }, /* NPI2, NIMP, PI1 */
 { 0, NOR, K0 }, /* NPI2, NIMP, PI2 */
 { 1, OR, PI1 }, /* NPI2, NIMP, NOR */
 { 1, IMP, PI1 }, /* NPI2, NIMP, NLIMP */
 { 1, PI2, K0 }, /* NPI2, NIMP, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, NIMP, NIMP */
 { 0, PI1, K0 }, /* NPI2, NIMP, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, NIMP, XOR */
 { 1, AND, PI1 }, /* NPI2, NIMP, NAND */
 { 1, NAND, PI1 }, /* NPI2, NIMP, AND */
 { 1, XOR, PI1 }, /* NPI2, NIMP, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, NIMP, IMP */
 { 1, NIMP, PI1 }, /* NPI2, NIMP, LIMP */
 { 1, NOR, PI1 }, /* NPI2, NIMP, OR */
 { 1, K0, K0 }, /* NPI2, NIMP, K1 */
 { 1, PI1, K1 }, /* NPI2, NPI2, K0 */
 { 1, NOR, K0 }, /* NPI2, NPI2, PI1 */
 { 0, NOR, K0 }, /* NPI2, NPI2, PI2 */
 { 1, OR, PI1 }, /* NPI2, NPI2, NOR */
 { 1, IMP, PI1 }, /* NPI2, NPI2, NLIMP */
 { 1, PI2, K0 }, /* NPI2, NPI2, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, NPI2, NIMP */
 { 0, PI1, K0 }, /* NPI2, NPI2, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, NPI2, XOR */
 { 1, AND, PI1 }, /* NPI2, NPI2, NAND */
 { 1, NAND, PI1 }, /* NPI2, NPI2, AND */
 { 1, XOR, PI1 }, /* NPI2, NPI2, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, NPI2, IMP */
 { 1, NIMP, PI1 }, /* NPI2, NPI2, LIMP */
 { 1, NOR, PI1 }, /* NPI2, NPI2, OR */
 { 1, K0, K0 }, /* NPI2, NPI2, K1 */
 { 1, PI1, K1 }, /* NPI2, XOR, K0 */
 { 1, NOR, K0 }, /* NPI2, XOR, PI1 */
 { 0, NOR, K0 }, /* NPI2, XOR, PI2 */
 { 1, OR, PI1 }, /* NPI2, XOR, NOR */
 { 1, IMP, PI1 }, /* NPI2, XOR, NLIMP */
 { 1, PI2, K0 }, /* NPI2, XOR, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, XOR, NIMP */
 { 0, PI1, K0 }, /* NPI2, XOR, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, XOR, XOR */
 { 1, AND, PI1 }, /* NPI2, XOR, NAND */
 { 1, NAND, PI1 }, /* NPI2, XOR, AND */
 { 1, XOR, PI1 }, /* NPI2, XOR, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, XOR, IMP */
 { 1, NIMP, PI1 }, /* NPI2, XOR, LIMP */
 { 1, NOR, PI1 }, /* NPI2, XOR, OR */
 { 1, K0, K0 }, /* NPI2, XOR, K1 */
 { 1, PI1, K1 }, /* NPI2, NAND, K0 */
 { 1, NOR, K0 }, /* NPI2, NAND, PI1 */
 { 0, NOR, K0 }, /* NPI2, NAND, PI2 */
 { 1, OR, PI1 }, /* NPI2, NAND, NOR */
 { 1, IMP, PI1 }, /* NPI2, NAND, NLIMP */
 { 1, PI2, K0 }, /* NPI2, NAND, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, NAND, NIMP */
 { 0, PI1, K0 }, /* NPI2, NAND, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, NAND, XOR */
 { 1, AND, PI1 }, /* NPI2, NAND, NAND */
 { 1, NAND, PI1 }, /* NPI2, NAND, AND */
 { 1, XOR, PI1 }, /* NPI2, NAND, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, NAND, IMP */
 { 1, NIMP, PI1 }, /* NPI2, NAND, LIMP */
 { 1, NOR, PI1 }, /* NPI2, NAND, OR */
 { 1, K0, K0 }, /* NPI2, NAND, K1 */
 { 1, PI1, K1 }, /* NPI2, AND, K0 */
 { 1, NOR, K0 }, /* NPI2, AND, PI1 */
 { 0, NOR, K0 }, /* NPI2, AND, PI2 */
 { 1, OR, PI1 }, /* NPI2, AND, NOR */
 { 1, IMP, PI1 }, /* NPI2, AND, NLIMP */
 { 1, PI2, K0 }, /* NPI2, AND, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, AND, NIMP */
 { 0, PI1, K0 }, /* NPI2, AND, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, AND, XOR */
 { 1, AND, PI1 }, /* NPI2, AND, NAND */
 { 1, NAND, PI1 }, /* NPI2, AND, AND */
 { 1, XOR, PI1 }, /* NPI2, AND, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, AND, IMP */
 { 1, NIMP, PI1 }, /* NPI2, AND, LIMP */
 { 1, NOR, PI1 }, /* NPI2, AND, OR */
 { 1, K0, K0 }, /* NPI2, AND, K1 */
 { 1, PI1, K1 }, /* NPI2, BIIMP, K0 */
 { 1, NOR, K0 }, /* NPI2, BIIMP, PI1 */
 { 0, NOR, K0 }, /* NPI2, BIIMP, PI2 */
 { 1, OR, PI1 }, /* NPI2, BIIMP, NOR */
 { 1, IMP, PI1 }, /* NPI2, BIIMP, NLIMP */
 { 1, PI2, K0 }, /* NPI2, BIIMP, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, BIIMP, NIMP */
 { 0, PI1, K0 }, /* NPI2, BIIMP, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, BIIMP, XOR */
 { 1, AND, PI1 }, /* NPI2, BIIMP, NAND */
 { 1, NAND, PI1 }, /* NPI2, BIIMP, AND */
 { 1, XOR, PI1 }, /* NPI2, BIIMP, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, BIIMP, IMP */
 { 1, NIMP, PI1 }, /* NPI2, BIIMP, LIMP */
 { 1, NOR, PI1 }, /* NPI2, BIIMP, OR */
 { 1, K0, K0 }, /* NPI2, BIIMP, K1 */
 { 1, PI1, K1 }, /* NPI2, IMP, K0 */
 { 1, NOR, K0 }, /* NPI2, IMP, PI1 */
 { 0, NOR, K0 }, /* NPI2, IMP, PI2 */
 { 1, OR, PI1 }, /* NPI2, IMP, NOR */
 { 1, IMP, PI1 }, /* NPI2, IMP, NLIMP */
 { 1, PI2, K0 }, /* NPI2, IMP, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, IMP, NIMP */
 { 0, PI1, K0 }, /* NPI2, IMP, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, IMP, XOR */
 { 1, AND, PI1 }, /* NPI2, IMP, NAND */
 { 1, NAND, PI1 }, /* NPI2, IMP, AND */
 { 1, XOR, PI1 }, /* NPI2, IMP, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, IMP, IMP */
 { 1, NIMP, PI1 }, /* NPI2, IMP, LIMP */
 { 1, NOR, PI1 }, /* NPI2, IMP, OR */
 { 1, K0, K0 }, /* NPI2, IMP, K1 */
 { 1, PI1, K1 }, /* NPI2, LIMP, K0 */
 { 1, NOR, K0 }, /* NPI2, LIMP, PI1 */
 { 0, NOR, K0 }, /* NPI2, LIMP, PI2 */
 { 1, OR, PI1 }, /* NPI2, LIMP, NOR */
 { 1, IMP, PI1 }, /* NPI2, LIMP, NLIMP */
 { 1, PI2, K0 }, /* NPI2, LIMP, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, LIMP, NIMP */
 { 0, PI1, K0 }, /* NPI2, LIMP, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, LIMP, XOR */
 { 1, AND, PI1 }, /* NPI2, LIMP, NAND */
 { 1, NAND, PI1 }, /* NPI2, LIMP, AND */
 { 1, XOR, PI1 }, /* NPI2, LIMP, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, LIMP, IMP */
 { 1, NIMP, PI1 }, /* NPI2, LIMP, LIMP */
 { 1, NOR, PI1 }, /* NPI2, LIMP, OR */
 { 1, K0, K0 }, /* NPI2, LIMP, K1 */
 { 1, PI1, K1 }, /* NPI2, OR, K0 */
 { 1, NOR, K0 }, /* NPI2, OR, PI1 */
 { 0, NOR, K0 }, /* NPI2, OR, PI2 */
 { 1, OR, PI1 }, /* NPI2, OR, NOR */
 { 1, IMP, PI1 }, /* NPI2, OR, NLIMP */
 { 1, PI2, K0 }, /* NPI2, OR, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, OR, NIMP */
 { 0, PI1, K0 }, /* NPI2, OR, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, OR, XOR */
 { 1, AND, PI1 }, /* NPI2, OR, NAND */
 { 1, NAND, PI1 }, /* NPI2, OR, AND */
 { 1, XOR, PI1 }, /* NPI2, OR, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, OR, IMP */
 { 1, NIMP, PI1 }, /* NPI2, OR, LIMP */
 { 1, NOR, PI1 }, /* NPI2, OR, OR */
 { 1, K0, K0 }, /* NPI2, OR, K1 */
 { 1, PI1, K1 }, /* NPI2, K1, K0 */
 { 1, NOR, K0 }, /* NPI2, K1, PI1 */
 { 0, NOR, K0 }, /* NPI2, K1, PI2 */
 { 1, OR, PI1 }, /* NPI2, K1, NOR */
 { 1, IMP, PI1 }, /* NPI2, K1, NLIMP */
 { 1, PI2, K0 }, /* NPI2, K1, NPI1 */
 { 1, LIMP, PI1 }, /* NPI2, K1, NIMP */
 { 0, PI1, K0 }, /* NPI2, K1, NPI2 */
 { 1, BIIMP, PI1 }, /* NPI2, K1, XOR */
 { 1, AND, PI1 }, /* NPI2, K1, NAND */
 { 1, NAND, PI1 }, /* NPI2, K1, AND */
 { 1, XOR, PI1 }, /* NPI2, K1, BIIMP */
 { 1, NLIMP, PI1 }, /* NPI2, K1, IMP */
 { 1, NIMP, PI1 }, /* NPI2, K1, LIMP */
 { 1, NOR, PI1 }, /* NPI2, K1, OR */
 { 1, K0, K0 }, /* NPI2, K1, K1 */
 { 1, K0, K0 }, /* XOR, K0, K0 */
 { 1, PI2, K0 }, /* XOR, K0, PI1 */
 { 0, PI1, K0 }, /* XOR, K0, PI2 */
 { 1, NOR, PI1 }, /* XOR, K0, NOR */
 { 1, NIMP, PI1 }, /* XOR, K0, NLIMP */
 { 1, NOR, K0 }, /* XOR, K0, NPI1 */
 { 1, NLIMP, PI1 }, /* XOR, K0, NIMP */
 { 0, NOR, K0 }, /* XOR, K0, NPI2 */
 { 1, XOR, PI1 }, /* XOR, K0, XOR */
 { 1, NAND, PI1 }, /* XOR, K0, NAND */
 { 1, AND, PI1 }, /* XOR, K0, AND */
 { 1, BIIMP, PI1 }, /* XOR, K0, BIIMP */
 { 1, LIMP, PI1 }, /* XOR, K0, IMP */
 { 1, IMP, PI1 }, /* XOR, K0, LIMP */
 { 1, OR, PI1 }, /* XOR, K0, OR */
 { 1, PI1, K1 }, /* XOR, K0, K1 */
 { 0, PI1, K0 }, /* XOR, PI1, K0 */
 { 1, XOR, PI1 }, /* XOR, PI1, PI1 */
 { 1, K0, K0 }, /* XOR, PI1, PI2 */
 { 1, LIMP, PI1 }, /* XOR, PI1, NOR */
 { 1, AND, PI1 }, /* XOR, PI1, NLIMP */
 { 1, BIIMP, PI1 }, /* XOR, PI1, NPI1 */
 { 1, OR, PI1 }, /* XOR, PI1, NIMP */
 { 1, PI1, K1 }, /* XOR, PI1, NPI2 */
 { 1, PI2, K0 }, /* XOR, PI1, XOR */
 { 1, IMP, PI1 }, /* XOR, PI1, NAND */
 { 1, NIMP, PI1 }, /* XOR, PI1, AND */
 { 1, NOR, K0 }, /* XOR, PI1, BIIMP */
 { 1, NOR, PI1 }, /* XOR, PI1, IMP */
 { 1, NAND, PI1 }, /* XOR, PI1, LIMP */
 { 1, NLIMP, PI1 }, /* XOR, PI1, OR */
 { 0, NOR, K0 }, /* XOR, PI1, K1 */
 { 1, PI1, PI2 }, /* XOR, PI2, K0 */
 { 0, PI2, XOR }, /* XOR, PI2, PI1 */
 { 1, PI1, XOR }, /* XOR, PI2, PI2 */
 { 0, NOP, NOP }, /* XOR, PI2, NOR */
 { 0, NOP, NOP }, /* XOR, PI2, NLIMP */
 { 0, PI2, BIIMP }, /* XOR, PI2, NPI1 */
 { 0, NOP, NOP }, /* XOR, PI2, NIMP */
 { 1, PI1, BIIMP }, /* XOR, PI2, NPI2 */
 { 1, XOR, XOR }, /* XOR, PI2, XOR */
 { 0, NOP, NOP }, /* XOR, PI2, NAND */
 { 0, NOP, NOP }, /* XOR, PI2, AND */
 { 1, XOR, BIIMP }, /* XOR, PI2, BIIMP */
 { 0, NOP, NOP }, /* XOR, PI2, IMP */
 { 0, NOP, NOP }, /* XOR, PI2, LIMP */
 { 0, NOP, NOP }, /* XOR, PI2, OR */
 { 1, NPI1, PI2 }, /* XOR, PI2, K1 */
 { 1, PI1, NOR }, /* XOR, NOR, K0 */
 { 1, XOR, NOR }, /* XOR, NOR, PI1 */
 { 1, PI1, LIMP }, /* XOR, NOR, PI2 */
 { 0, NOR, BIIMP }, /* XOR, NOR, NOR */
 { 0, NOP, OR }, /* XOR, NOR, NLIMP */
 { 1, XOR, OR }, /* XOR, NOR, NPI1 */
 { 0, NOR, XOR }, /* XOR, NOR, NIMP */
 { 1, PI1, NLIMP }, /* XOR, NOR, NPI2 */
 { 1, XOR, LIMP }, /* XOR, NOR, XOR */
 { 0, NOP, NLIMP }, /* XOR, NOR, NAND */
 { 0, NOP, OR }, /* XOR, NOR, AND */
 { 1, XOR, NLIMP }, /* XOR, NOR, BIIMP */
 { 0, LIMP, BIIMP }, /* XOR, NOR, IMP */
 { 0, NOP, NLIMP }, /* XOR, NOR, LIMP */
 { 0, LIMP, XOR }, /* XOR, NOR, OR */
 { 1, PI1, OR }, /* XOR, NOR, K1 */
 { 1, PI1, NLIMP }, /* XOR, NLIMP, K0 */
 { 1, XOR, NLIMP }, /* XOR, NLIMP, PI1 */
 { 1, PI1, OR }, /* XOR, NLIMP, PI2 */
 { 0, NOR, XOR }, /* XOR, NLIMP, NOR */
 { 0, NOP, OR }, /* XOR, NLIMP, NLIMP */
 { 1, XOR, LIMP }, /* XOR, NLIMP, NPI1 */
 { 0, NOR, BIIMP }, /* XOR, NLIMP, NIMP */
 { 1, PI1, NOR }, /* XOR, NLIMP, NPI2 */
 { 1, XOR, OR }, /* XOR, NLIMP, XOR */
 { 0, NOP, NLIMP }, /* XOR, NLIMP, NAND */
 { 0, NOP, OR }, /* XOR, NLIMP, AND */
 { 1, XOR, NOR }, /* XOR, NLIMP, BIIMP */
 { 0, LIMP, XOR }, /* XOR, NLIMP, IMP */
 { 0, NOP, NLIMP }, /* XOR, NLIMP, LIMP */
 { 0, LIMP, BIIMP }, /* XOR, NLIMP, OR */
 { 1, PI1, LIMP }, /* XOR, NLIMP, K1 */
 { 0, NOR, K0 }, /* XOR, NPI1, K0 */
 { 1, BIIMP, PI1 }, /* XOR, NPI1, PI1 */
 { 1, PI1, K1 }, /* XOR, NPI1, PI2 */
 { 1, NLIMP, PI1 }, /* XOR, NPI1, NOR */
 { 1, NAND, PI1 }, /* XOR, NPI1, NLIMP */
 { 1, XOR, PI1 }, /* XOR, NPI1, NPI1 */
 { 1, NOR, PI1 }, /* XOR, NPI1, NIMP */
 { 1, K0, K0 }, /* XOR, NPI1, NPI2 */
 { 1, NOR, K0 }, /* XOR, NPI1, XOR */
 { 1, NIMP, PI1 }, /* XOR, NPI1, NAND */
 { 1, IMP, PI1 }, /* XOR, NPI1, AND */
 { 1, PI2, K0 }, /* XOR, NPI1, BIIMP */
 { 1, OR, PI1 }, /* XOR, NPI1, IMP */
 { 1, AND, PI1 }, /* XOR, NPI1, LIMP */
 { 1, LIMP, PI1 }, /* XOR, NPI1, OR */
 { 0, PI1, K0 }, /* XOR, NPI1, K1 */
 { 1, PI1, NIMP }, /* XOR, NIMP, K0 */
 { 1, XOR, NIMP }, /* XOR, NIMP, PI1 */
 { 1, PI1, AND }, /* XOR, NIMP, PI2 */
 { 0, NOP, OR }, /* XOR, NIMP, NOR */
 { 0, NIMP, BIIMP }, /* XOR, NIMP, NLIMP */
 { 1, XOR, IMP }, /* XOR, NIMP, NPI1 */
 { 0, NOP, OR }, /* XOR, NIMP, NIMP */
 { 1, PI1, NAND }, /* XOR, NIMP, NPI2 */
 { 1, XOR, AND }, /* XOR, NIMP, XOR */
 { 0, NAND, BIIMP }, /* XOR, NIMP, NAND */
 { 0, NIMP, XOR }, /* XOR, NIMP, AND */
 { 1, XOR, NAND }, /* XOR, NIMP, BIIMP */
 { 0, NOP, NLIMP }, /* XOR, NIMP, IMP */
 { 0, NAND, XOR }, /* XOR, NIMP, LIMP */
 { 0, NOP, NLIMP }, /* XOR, NIMP, OR */
 { 1, PI1, IMP }, /* XOR, NIMP, K1 */
 { 1, NPI1, PI2 }, /* XOR, NPI2, K0 */
 { 0, PI2, BIIMP }, /* XOR, NPI2, PI1 */
 { 1, PI1, BIIMP }, /* XOR, NPI2, PI2 */
 { 0, NOP, NOP }, /* XOR, NPI2, NOR */
 { 0, NOP, NOP }, /* XOR, NPI2, NLIMP */
 { 0, PI2, XOR }, /* XOR, NPI2, NPI1 */
 { 0, NOP, NOP }, /* XOR, NPI2, NIMP */
 { 1, PI1, XOR }, /* XOR, NPI2, NPI2 */
 { 1, XOR, BIIMP }, /* XOR, NPI2, XOR */
 { 0, NOP, NOP }, /* XOR, NPI2, NAND */
 { 0, NOP, NOP }, /* XOR, NPI2, AND */
 { 1, XOR, XOR }, /* XOR, NPI2, BIIMP */
 { 0, NOP, NOP }, /* XOR, NPI2, IMP */
 { 0, NOP, NOP }, /* XOR, NPI2, LIMP */
 { 0, NOP, NOP }, /* XOR, NPI2, OR */
 { 1, PI1, PI2 }, /* XOR, NPI2, K1 */
 { 1, PI1, XOR }, /* XOR, XOR, K0 */
 { 1, XOR, XOR }, /* XOR, XOR, PI1 */
 { 1, PI1, PI2 }, /* XOR, XOR, PI2 */
 { 0, NOP, NOP }, /* XOR, XOR, NOR */
 { 0, NOP, NOP }, /* XOR, XOR, NLIMP */
 { 1, XOR, BIIMP }, /* XOR, XOR, NPI1 */
 { 0, NOP, NOP }, /* XOR, XOR, NIMP */
 { 1, NPI1, PI2 }, /* XOR, XOR, NPI2 */
 { 0, PI2, XOR }, /* XOR, XOR, XOR */
 { 0, NOP, NOP }, /* XOR, XOR, NAND */
 { 0, NOP, NOP }, /* XOR, XOR, AND */
 { 0, PI2, BIIMP }, /* XOR, XOR, BIIMP */
 { 0, NOP, NOP }, /* XOR, XOR, IMP */
 { 0, NOP, NOP }, /* XOR, XOR, LIMP */
 { 0, NOP, NOP }, /* XOR, XOR, OR */
 { 1, PI1, BIIMP }, /* XOR, XOR, K1 */
 { 1, PI1, NAND }, /* XOR, NAND, K0 */
 { 1, XOR, NAND }, /* XOR, NAND, PI1 */
 { 1, PI1, IMP }, /* XOR, NAND, PI2 */
 { 0, NOP, NIMP }, /* XOR, NAND, NOR */
 { 0, NAND, BIIMP }, /* XOR, NAND, NLIMP */
 { 1, XOR, AND }, /* XOR, NAND, NPI1 */
 { 0, NOP, NIMP }, /* XOR, NAND, NIMP */
 { 1, PI1, NIMP }, /* XOR, NAND, NPI2 */
 { 1, XOR, IMP }, /* XOR, NAND, XOR */
 { 0, NIMP, BIIMP }, /* XOR, NAND, NAND */
 { 0, NAND, XOR }, /* XOR, NAND, AND */
 { 1, XOR, NIMP }, /* XOR, NAND, BIIMP */
 { 0, NOP, NAND }, /* XOR, NAND, IMP */
 { 0, NIMP, XOR }, /* XOR, NAND, LIMP */
 { 0, NOP, NAND }, /* XOR, NAND, OR */
 { 1, PI1, AND }, /* XOR, NAND, K1 */
 { 1, PI1, AND }, /* XOR, AND, K0 */
 { 1, XOR, AND }, /* XOR, AND, PI1 */
 { 1, PI1, NIMP }, /* XOR, AND, PI2 */
 { 0, NOP, OR }, /* XOR, AND, NOR */
 { 0, NIMP, XOR }, /* XOR, AND, NLIMP */
 { 1, XOR, NAND }, /* XOR, AND, NPI1 */
 { 0, NOP, OR }, /* XOR, AND, NIMP */
 { 1, PI1, IMP }, /* XOR, AND, NPI2 */
 { 1, XOR, NIMP }, /* XOR, AND, XOR */
 { 0, NAND, XOR }, /* XOR, AND, NAND */
 { 0, NIMP, BIIMP }, /* XOR, AND, AND */
 { 1, XOR, IMP }, /* XOR, AND, BIIMP */
 { 0, NOP, NLIMP }, /* XOR, AND, IMP */
 { 0, NAND, BIIMP }, /* XOR, AND, LIMP */
 { 0, NOP, NLIMP }, /* XOR, AND, OR */
 { 1, PI1, NAND }, /* XOR, AND, K1 */
 { 1, PI1, BIIMP }, /* XOR, BIIMP, K0 */
 { 1, XOR, BIIMP }, /* XOR, BIIMP, PI1 */
 { 1, NPI1, PI2 }, /* XOR, BIIMP, PI2 */
 { 0, NOP, NOP }, /* XOR, BIIMP, NOR */
 { 0, NOP, NOP }, /* XOR, BIIMP, NLIMP */
 { 1, XOR, XOR }, /* XOR, BIIMP, NPI1 */
 { 0, NOP, NOP }, /* XOR, BIIMP, NIMP */
 { 1, PI1, PI2 }, /* XOR, BIIMP, NPI2 */
 { 0, PI2, BIIMP }, /* XOR, BIIMP, XOR */
 { 0, NOP, NOP }, /* XOR, BIIMP, NAND */
 { 0, NOP, NOP }, /* XOR, BIIMP, AND */
 { 0, PI2, XOR }, /* XOR, BIIMP, BIIMP */
 { 0, NOP, NOP }, /* XOR, BIIMP, IMP */
 { 0, NOP, NOP }, /* XOR, BIIMP, LIMP */
 { 0, NOP, NOP }, /* XOR, BIIMP, OR */
 { 1, PI1, XOR }, /* XOR, BIIMP, K1 */
 { 1, PI1, IMP }, /* XOR, IMP, K0 */
 { 1, XOR, IMP }, /* XOR, IMP, PI1 */
 { 1, PI1, NAND }, /* XOR, IMP, PI2 */
 { 0, NOP, NIMP }, /* XOR, IMP, NOR */
 { 0, NAND, XOR }, /* XOR, IMP, NLIMP */
 { 1, XOR, NIMP }, /* XOR, IMP, NPI1 */
 { 0, NOP, NIMP }, /* XOR, IMP, NIMP */
 { 1, PI1, AND }, /* XOR, IMP, NPI2 */
 { 1, XOR, NAND }, /* XOR, IMP, XOR */
 { 0, NIMP, XOR }, /* XOR, IMP, NAND */
 { 0, NAND, BIIMP }, /* XOR, IMP, AND */
 { 1, XOR, AND }, /* XOR, IMP, BIIMP */
 { 0, NOP, NAND }, /* XOR, IMP, IMP */
 { 0, NIMP, BIIMP }, /* XOR, IMP, LIMP */
 { 0, NOP, NAND }, /* XOR, IMP, OR */
 { 1, PI1, NIMP }, /* XOR, IMP, K1 */
 { 1, PI1, LIMP }, /* XOR, LIMP, K0 */
 { 1, XOR, LIMP }, /* XOR, LIMP, PI1 */
 { 1, PI1, NOR }, /* XOR, LIMP, PI2 */
 { 0, LIMP, BIIMP }, /* XOR, LIMP, NOR */
 { 0, NOP, NIMP }, /* XOR, LIMP, NLIMP */
 { 1, XOR, NLIMP }, /* XOR, LIMP, NPI1 */
 { 0, LIMP, XOR }, /* XOR, LIMP, NIMP */
 { 1, PI1, OR }, /* XOR, LIMP, NPI2 */
 { 1, XOR, NOR }, /* XOR, LIMP, XOR */
 { 0, NOP, NAND }, /* XOR, LIMP, NAND */
 { 0, NOP, NIMP }, /* XOR, LIMP, AND */
 { 1, XOR, OR }, /* XOR, LIMP, BIIMP */
 { 0, NOR, BIIMP }, /* XOR, LIMP, IMP */
 { 0, NOP, NAND }, /* XOR, LIMP, LIMP */
 { 0, NOR, XOR }, /* XOR, LIMP, OR */
 { 1, PI1, NLIMP }, /* XOR, LIMP, K1 */
 { 1, PI1, OR }, /* XOR, OR, K0 */
 { 1, XOR, OR }, /* XOR, OR, PI1 */
 { 1, PI1, NLIMP }, /* XOR, OR, PI2 */
 { 0, LIMP, XOR }, /* XOR, OR, NOR */
 { 0, NOP, NIMP }, /* XOR, OR, NLIMP */
 { 1, XOR, NOR }, /* XOR, OR, NPI1 */
 { 0, LIMP, BIIMP }, /* XOR, OR, NIMP */
 { 1, PI1, LIMP }, /* XOR, OR, NPI2 */
 { 1, XOR, NLIMP }, /* XOR, OR, XOR */
 { 0, NOP, NAND }, /* XOR, OR, NAND */
 { 0, NOP, NIMP }, /* XOR, OR, AND */
 { 1, XOR, LIMP }, /* XOR, OR, BIIMP */
 { 0, NOR, XOR }, /* XOR, OR, IMP */
 { 0, NOP, NAND }, /* XOR, OR, LIMP */
 { 0, NOR, BIIMP }, /* XOR, OR, OR */
 { 1, PI1, NOR }, /* XOR, OR, K1 */
 { 1, PI1, K1 }, /* XOR, K1, K0 */
 { 1, NOR, K0 }, /* XOR, K1, PI1 */
 { 0, NOR, K0 }, /* XOR, K1, PI2 */
 { 1, OR, PI1 }, /* XOR, K1, NOR */
 { 1, IMP, PI1 }, /* XOR, K1, NLIMP */
 { 1, PI2, K0 }, /* XOR, K1, NPI1 */
 { 1, LIMP, PI1 }, /* XOR, K1, NIMP */
 { 0, PI1, K0 }, /* XOR, K1, NPI2 */
 { 1, BIIMP, PI1 }, /* XOR, K1, XOR */
 { 1, AND, PI1 }, /* XOR, K1, NAND */
 { 1, NAND, PI1 }, /* XOR, K1, AND */
 { 1, XOR, PI1 }, /* XOR, K1, BIIMP */
 { 1, NLIMP, PI1 }, /* XOR, K1, IMP */
 { 1, NIMP, PI1 }, /* XOR, K1, LIMP */
 { 1, NOR, PI1 }, /* XOR, K1, OR */
 { 1, K0, K0 }, /* XOR, K1, K1 */
 { 1, PI1, K1 }, /* NAND, K0, K0 */
 { 1, PI1, K1 }, /* NAND, K0, PI1 */
 { 1, PI1, K1 }, /* NAND, K0, PI2 */
 { 1, PI1, K1 }, /* NAND, K0, NOR */
 { 1, PI1, K1 }, /* NAND, K0, NLIMP */
 { 1, PI1, K1 }, /* NAND, K0, NPI1 */
 { 1, PI1, K1 }, /* NAND, K0, NIMP */
 { 1, PI1, K1 }, /* NAND, K0, NPI2 */
 { 1, PI1, K1 }, /* NAND, K0, XOR */
 { 1, PI1, K1 }, /* NAND, K0, NAND */
 { 1, PI1, K1 }, /* NAND, K0, AND */
 { 1, PI1, K1 }, /* NAND, K0, BIIMP */
 { 1, PI1, K1 }, /* NAND, K0, IMP */
 { 1, PI1, K1 }, /* NAND, K0, LIMP */
 { 1, PI1, K1 }, /* NAND, K0, OR */
 { 1, PI1, K1 }, /* NAND, K0, K1 */
 { 1, PI1, K1 }, /* NAND, PI1, K0 */
 { 1, NAND, PI1 }, /* NAND, PI1, PI1 */
 { 0, NOR, K0 }, /* NAND, PI1, PI2 */
 { 1, PI1, K1 }, /* NAND, PI1, NOR */
 { 1, IMP, PI1 }, /* NAND, PI1, NLIMP */
 { 1, IMP, PI1 }, /* NAND, PI1, NPI1 */
 { 1, PI1, K1 }, /* NAND, PI1, NIMP */
 { 1, PI1, K1 }, /* NAND, PI1, NPI2 */
 { 1, IMP, PI1 }, /* NAND, PI1, XOR */
 { 1, IMP, PI1 }, /* NAND, PI1, NAND */
 { 1, NAND, PI1 }, /* NAND, PI1, AND */
 { 1, NAND, PI1 }, /* NAND, PI1, BIIMP */
 { 0, NOR, K0 }, /* NAND, PI1, IMP */
 { 1, NAND, PI1 }, /* NAND, PI1, LIMP */
 { 0, NOR, K0 }, /* NAND, PI1, OR */
 { 0, NOR, K0 }, /* NAND, PI1, K1 */
 { 1, PI1, K1 }, /* NAND, PI2, K0 */
 { 0, PI2, NAND }, /* NAND, PI2, PI1 */
 { 1, PI1, NAND }, /* NAND, PI2, PI2 */
 { 1, IMP, NLIMP }, /* NAND, PI2, NOR */
 { 0, NAND, NIMP }, /* NAND, PI2, NLIMP */
 { 0, PI2, IMP }, /* NAND, PI2, NPI1 */
 { 1, NAND, NLIMP }, /* NAND, PI2, NIMP */
 { 1, PI1, LIMP }, /* NAND, PI2, NPI2 */
 { 0, NOP, NOP }, /* NAND, PI2, XOR */
 { 0, NOP, NOP }, /* NAND, PI2, NAND */
 { 1, NAND, AND }, /* NAND, PI2, AND */
 { 0, NOP, NOP }, /* NAND, PI2, BIIMP */
 { 0, NOP, NOP }, /* NAND, PI2, IMP */
 { 0, NOP, NOP }, /* NAND, PI2, LIMP */
 { 0, NOP, NOP }, /* NAND, PI2, OR */
 { 1, NPI1, PI2 }, /* NAND, PI2, K1 */
 { 1, PI1, K1 }, /* NAND, NOR, K0 */
 { 1, NAND, NOR }, /* NAND, NOR, PI1 */
 { 1, PI1, K1 }, /* NAND, NOR, PI2 */
 { 1, IMP, NOR }, /* NAND, NOR, NOR */
 { 1, PI1, K1 }, /* NAND, NOR, NLIMP */
 { 1, IMP, NOR }, /* NAND, NOR, NPI1 */
 { 1, NAND, NOR }, /* NAND, NOR, NIMP */
 { 1, PI1, OR }, /* NAND, NOR, NPI2 */
 { 1, NAND, NOR }, /* NAND, NOR, XOR */
 { 1, PI1, OR }, /* NAND, NOR, NAND */
 { 1, PI1, K1 }, /* NAND, NOR, AND */
 { 1, IMP, NOR }, /* NAND, NOR, BIIMP */
 { 1, IMP, NOR }, /* NAND, NOR, IMP */
 { 1, PI1, OR }, /* NAND, NOR, LIMP */
 { 1, NAND, NOR }, /* NAND, NOR, OR */
 { 1, PI1, OR }, /* NAND, NOR, K1 */
 { 1, PI1, K1 }, /* NAND, NLIMP, K0 */
 { 1, NAND, NLIMP }, /* NAND, NLIMP, PI1 */
 { 1, PI1, K1 }, /* NAND, NLIMP, PI2 */
 { 1, IMP, NLIMP }, /* NAND, NLIMP, NOR */
 { 1, PI1, K1 }, /* NAND, NLIMP, NLIMP */
 { 1, IMP, NLIMP }, /* NAND, NLIMP, NPI1 */
 { 1, NAND, NLIMP }, /* NAND, NLIMP, NIMP */
 { 1, PI1, LIMP }, /* NAND, NLIMP, NPI2 */
 { 1, NAND, NLIMP }, /* NAND, NLIMP, XOR */
 { 1, PI1, LIMP }, /* NAND, NLIMP, NAND */
 { 1, PI1, K1 }, /* NAND, NLIMP, AND */
 { 1, IMP, NLIMP }, /* NAND, NLIMP, BIIMP */
 { 1, IMP, NLIMP }, /* NAND, NLIMP, IMP */
 { 1, PI1, LIMP }, /* NAND, NLIMP, LIMP */
 { 1, NAND, NLIMP }, /* NAND, NLIMP, OR */
 { 1, PI1, LIMP }, /* NAND, NLIMP, K1 */
 { 1, PI1, K1 }, /* NAND, NPI1, K0 */
 { 1, LIMP, PI1 }, /* NAND, NPI1, PI1 */
 { 1, PI1, K1 }, /* NAND, NPI1, PI2 */
 { 1, OR, PI1 }, /* NAND, NPI1, NOR */
 { 1, PI1, K1 }, /* NAND, NPI1, NLIMP */
 { 1, OR, PI1 }, /* NAND, NPI1, NPI1 */
 { 1, LIMP, PI1 }, /* NAND, NPI1, NIMP */
 { 0, PI1, K0 }, /* NAND, NPI1, NPI2 */
 { 1, LIMP, PI1 }, /* NAND, NPI1, XOR */
 { 0, PI1, K0 }, /* NAND, NPI1, NAND */
 { 1, PI1, K1 }, /* NAND, NPI1, AND */
 { 1, OR, PI1 }, /* NAND, NPI1, BIIMP */
 { 1, OR, PI1 }, /* NAND, NPI1, IMP */
 { 0, PI1, K0 }, /* NAND, NPI1, LIMP */
 { 1, LIMP, PI1 }, /* NAND, NPI1, OR */
 { 0, PI1, K0 }, /* NAND, NPI1, K1 */
 { 1, PI1, K1 }, /* NAND, NIMP, K0 */
 { 0, NAND, NLIMP }, /* NAND, NIMP, PI1 */
 { 1, PI1, IMP }, /* NAND, NIMP, PI2 */
 { 1, PI1, K1 }, /* NAND, NIMP, NOR */
 { 0, NAND, NOR }, /* NAND, NIMP, NLIMP */
 { 0, NAND, NOR }, /* NAND, NIMP, NPI1 */
 { 1, PI1, K1 }, /* NAND, NIMP, NIMP */
 { 1, PI1, K1 }, /* NAND, NIMP, NPI2 */
 { 0, NAND, NOR }, /* NAND, NIMP, XOR */
 { 0, NAND, NOR }, /* NAND, NIMP, NAND */
 { 0, NAND, NLIMP }, /* NAND, NIMP, AND */
 { 0, NAND, NLIMP }, /* NAND, NIMP, BIIMP */
 { 1, PI1, IMP }, /* NAND, NIMP, IMP */
 { 0, NAND, NLIMP }, /* NAND, NIMP, LIMP */
 { 1, PI1, IMP }, /* NAND, NIMP, OR */
 { 1, PI1, IMP }, /* NAND, NIMP, K1 */
 { 1, PI1, K1 }, /* NAND, NPI2, K0 */
 { 0, PI2, LIMP }, /* NAND, NPI2, PI1 */
 { 1, PI1, IMP }, /* NAND, NPI2, PI2 */
 { 1, IMP, NOR }, /* NAND, NPI2, NOR */
 { 0, NAND, NOR }, /* NAND, NPI2, NLIMP */
 { 0, PI2, OR }, /* NAND, NPI2, NPI1 */
 { 1, NAND, NOR }, /* NAND, NPI2, NIMP */
 { 1, PI1, OR }, /* NAND, NPI2, NPI2 */
 { 0, NOP, NOP }, /* NAND, NPI2, XOR */
 { 0, NOP, NOP }, /* NAND, NPI2, NAND */
 { 0, NAND, NLIMP }, /* NAND, NPI2, AND */
 { 0, NOP, NOP }, /* NAND, NPI2, BIIMP */
 { 0, NOP, NOP }, /* NAND, NPI2, IMP */
 { 0, NOP, NOP }, /* NAND, NPI2, LIMP */
 { 0, NOP, NOP }, /* NAND, NPI2, OR */
 { 1, PI1, PI2 }, /* NAND, NPI2, K1 */
 { 1, PI1, K1 }, /* NAND, XOR, K0 */
 { 1, NAND, XOR }, /* NAND, XOR, PI1 */
 { 1, PI1, IMP }, /* NAND, XOR, PI2 */
 { 1, IMP, NLIMP }, /* NAND, XOR, NOR */
 { 0, NAND, NOR }, /* NAND, XOR, NLIMP */
 { 1, IMP, XOR }, /* NAND, XOR, NPI1 */
 { 1, NAND, NLIMP }, /* NAND, XOR, NIMP */
 { 1, PI1, LIMP }, /* NAND, XOR, NPI2 */
 { 0, NOP, NOP }, /* NAND, XOR, XOR */
 { 0, NOP, NOP }, /* NAND, XOR, NAND */
 { 0, NAND, NLIMP }, /* NAND, XOR, AND */
 { 0, NOP, NOP }, /* NAND, XOR, BIIMP */
 { 0, NOP, NOP }, /* NAND, XOR, IMP */
 { 0, NOP, NOP }, /* NAND, XOR, LIMP */
 { 0, NOP, NOP }, /* NAND, XOR, OR */
 { 1, PI1, BIIMP }, /* NAND, XOR, K1 */
 { 1, PI1, K1 }, /* NAND, NAND, K0 */
 { 1, NAND, NAND }, /* NAND, NAND, PI1 */
 { 1, PI1, IMP }, /* NAND, NAND, PI2 */
 { 1, OR, PI1 }, /* NAND, NAND, NOR */
 { 0, NAND, NOR }, /* NAND, NAND, NLIMP */
 { 1, IMP, NAND }, /* NAND, NAND, NPI1 */
 { 1, LIMP, PI1 }, /* NAND, NAND, NIMP */
 { 0, PI1, K0 }, /* NAND, NAND, NPI2 */
 { 0, NOP, NOP }, /* NAND, NAND, XOR */
 { 0, NIMP, NOR }, /* NAND, NAND, NAND */
 { 0, NAND, NLIMP }, /* NAND, NAND, AND */
 { 0, NOP, NOP }, /* NAND, NAND, BIIMP */
 { 0, NOP, XOR }, /* NAND, NAND, IMP */
 { 0, NIMP, NLIMP }, /* NAND, NAND, LIMP */
 { 0, NOP, XOR }, /* NAND, NAND, OR */
 { 1, PI1, AND }, /* NAND, NAND, K1 */
 { 1, PI1, K1 }, /* NAND, AND, K0 */
 { 1, NAND, AND }, /* NAND, AND, PI1 */
 { 1, PI1, NAND }, /* NAND, AND, PI2 */
 { 1, PI1, K1 }, /* NAND, AND, NOR */
 { 0, NAND, NIMP }, /* NAND, AND, NLIMP */
 { 0, NAND, NIMP }, /* NAND, AND, NPI1 */
 { 1, PI1, K1 }, /* NAND, AND, NIMP */
 { 1, PI1, K1 }, /* NAND, AND, NPI2 */
 { 0, NAND, NIMP }, /* NAND, AND, XOR */
 { 0, NAND, NIMP }, /* NAND, AND, NAND */
 { 1, NAND, AND }, /* NAND, AND, AND */
 { 1, NAND, AND }, /* NAND, AND, BIIMP */
 { 1, PI1, NAND }, /* NAND, AND, IMP */
 { 1, NAND, AND }, /* NAND, AND, LIMP */
 { 1, PI1, NAND }, /* NAND, AND, OR */
 { 1, PI1, NAND }, /* NAND, AND, K1 */
 { 1, PI1, K1 }, /* NAND, BIIMP, K0 */
 { 1, NAND, BIIMP }, /* NAND, BIIMP, PI1 */
 { 1, PI1, NAND }, /* NAND, BIIMP, PI2 */
 { 1, IMP, NOR }, /* NAND, BIIMP, NOR */
 { 0, NAND, NIMP }, /* NAND, BIIMP, NLIMP */
 { 1, IMP, BIIMP }, /* NAND, BIIMP, NPI1 */
 { 1, NAND, NOR }, /* NAND, BIIMP, NIMP */
 { 1, PI1, OR }, /* NAND, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* NAND, BIIMP, XOR */
 { 0, NOP, NOP }, /* NAND, BIIMP, NAND */
 { 1, NAND, AND }, /* NAND, BIIMP, AND */
 { 0, NOP, NOP }, /* NAND, BIIMP, BIIMP */
 { 0, NOP, NOP }, /* NAND, BIIMP, IMP */
 { 0, NOP, NOP }, /* NAND, BIIMP, LIMP */
 { 0, NOP, NOP }, /* NAND, BIIMP, OR */
 { 1, PI1, XOR }, /* NAND, BIIMP, K1 */
 { 1, PI1, K1 }, /* NAND, IMP, K0 */
 { 1, NAND, IMP }, /* NAND, IMP, PI1 */
 { 1, PI1, NAND }, /* NAND, IMP, PI2 */
 { 1, OR, PI1 }, /* NAND, IMP, NOR */
 { 0, NAND, NIMP }, /* NAND, IMP, NLIMP */
 { 1, IMP, IMP }, /* NAND, IMP, NPI1 */
 { 1, LIMP, PI1 }, /* NAND, IMP, NIMP */
 { 0, PI1, K0 }, /* NAND, IMP, NPI2 */
 { 0, NOP, NOP }, /* NAND, IMP, XOR */
 { 0, NIMP, NIMP }, /* NAND, IMP, NAND */
 { 1, NAND, AND }, /* NAND, IMP, AND */
 { 0, NOP, NOP }, /* NAND, IMP, BIIMP */
 { 0, NOP, XOR }, /* NAND, IMP, IMP */
 { 0, NIMP, AND }, /* NAND, IMP, LIMP */
 { 0, NOP, XOR }, /* NAND, IMP, OR */
 { 1, PI1, NIMP }, /* NAND, IMP, K1 */
 { 1, PI1, K1 }, /* NAND, LIMP, K0 */
 { 1, NAND, LIMP }, /* NAND, LIMP, PI1 */
 { 0, NOR, K0 }, /* NAND, LIMP, PI2 */
 { 1, IMP, NOR }, /* NAND, LIMP, NOR */
 { 1, IMP, PI1 }, /* NAND, LIMP, NLIMP */
 { 1, IMP, LIMP }, /* NAND, LIMP, NPI1 */
 { 1, NAND, NOR }, /* NAND, LIMP, NIMP */
 { 1, PI1, OR }, /* NAND, LIMP, NPI2 */
 { 0, NOP, NOP }, /* NAND, LIMP, XOR */
 { 0, NOP, XOR }, /* NAND, LIMP, NAND */
 { 1, NAND, PI1 }, /* NAND, LIMP, AND */
 { 0, NOP, NOP }, /* NAND, LIMP, BIIMP */
 { 0, NOR, NOR }, /* NAND, LIMP, IMP */
 { 0, NOP, XOR }, /* NAND, LIMP, LIMP */
 { 0, NOR, NLIMP }, /* NAND, LIMP, OR */
 { 1, PI1, NLIMP }, /* NAND, LIMP, K1 */
 { 1, PI1, K1 }, /* NAND, OR, K0 */
 { 1, NAND, OR }, /* NAND, OR, PI1 */
 { 0, NOR, K0 }, /* NAND, OR, PI2 */
 { 1, IMP, NLIMP }, /* NAND, OR, NOR */
 { 1, IMP, PI1 }, /* NAND, OR, NLIMP */
 { 1, IMP, OR }, /* NAND, OR, NPI1 */
 { 1, NAND, NLIMP }, /* NAND, OR, NIMP */
 { 1, PI1, LIMP }, /* NAND, OR, NPI2 */
 { 0, NOP, NOP }, /* NAND, OR, XOR */
 { 0, NOP, XOR }, /* NAND, OR, NAND */
 { 1, NAND, PI1 }, /* NAND, OR, AND */
 { 0, NOP, NOP }, /* NAND, OR, BIIMP */
 { 0, NOR, NIMP }, /* NAND, OR, IMP */
 { 0, NOP, XOR }, /* NAND, OR, LIMP */
 { 0, NOR, AND }, /* NAND, OR, OR */
 { 1, PI1, NOR }, /* NAND, OR, K1 */
 { 1, PI1, K1 }, /* NAND, K1, K0 */
 { 1, NOR, K0 }, /* NAND, K1, PI1 */
 { 0, NOR, K0 }, /* NAND, K1, PI2 */
 { 1, OR, PI1 }, /* NAND, K1, NOR */
 { 1, IMP, PI1 }, /* NAND, K1, NLIMP */
 { 1, PI2, K0 }, /* NAND, K1, NPI1 */
 { 1, LIMP, PI1 }, /* NAND, K1, NIMP */
 { 0, PI1, K0 }, /* NAND, K1, NPI2 */
 { 1, BIIMP, PI1 }, /* NAND, K1, XOR */
 { 1, AND, PI1 }, /* NAND, K1, NAND */
 { 1, NAND, PI1 }, /* NAND, K1, AND */
 { 1, XOR, PI1 }, /* NAND, K1, BIIMP */
 { 1, NLIMP, PI1 }, /* NAND, K1, IMP */
 { 1, NIMP, PI1 }, /* NAND, K1, LIMP */
 { 1, NOR, PI1 }, /* NAND, K1, OR */
 { 1, K0, K0 }, /* NAND, K1, K1 */
 { 1, K0, K0 }, /* AND, K0, K0 */
 { 1, K0, K0 }, /* AND, K0, PI1 */
 { 1, K0, K0 }, /* AND, K0, PI2 */
 { 1, K0, K0 }, /* AND, K0, NOR */
 { 1, K0, K0 }, /* AND, K0, NLIMP */
 { 1, K0, K0 }, /* AND, K0, NPI1 */
 { 1, K0, K0 }, /* AND, K0, NIMP */
 { 1, K0, K0 }, /* AND, K0, NPI2 */
 { 1, K0, K0 }, /* AND, K0, XOR */
 { 1, K0, K0 }, /* AND, K0, NAND */
 { 1, K0, K0 }, /* AND, K0, AND */
 { 1, K0, K0 }, /* AND, K0, BIIMP */
 { 1, K0, K0 }, /* AND, K0, IMP */
 { 1, K0, K0 }, /* AND, K0, LIMP */
 { 1, K0, K0 }, /* AND, K0, OR */
 { 1, K0, K0 }, /* AND, K0, K1 */
 { 1, K0, K0 }, /* AND, PI1, K0 */
 { 1, AND, PI1 }, /* AND, PI1, PI1 */
 { 0, PI1, K0 }, /* AND, PI1, PI2 */
 { 1, K0, K0 }, /* AND, PI1, NOR */
 { 1, NIMP, PI1 }, /* AND, PI1, NLIMP */
 { 1, NIMP, PI1 }, /* AND, PI1, NPI1 */
 { 1, K0, K0 }, /* AND, PI1, NIMP */
 { 1, K0, K0 }, /* AND, PI1, NPI2 */
 { 1, NIMP, PI1 }, /* AND, PI1, XOR */
 { 1, NIMP, PI1 }, /* AND, PI1, NAND */
 { 1, AND, PI1 }, /* AND, PI1, AND */
 { 1, AND, PI1 }, /* AND, PI1, BIIMP */
 { 0, PI1, K0 }, /* AND, PI1, IMP */
 { 1, AND, PI1 }, /* AND, PI1, LIMP */
 { 0, PI1, K0 }, /* AND, PI1, OR */
 { 0, PI1, K0 }, /* AND, PI1, K1 */
 { 1, K0, K0 }, /* AND, PI2, K0 */
 { 0, PI2, AND }, /* AND, PI2, PI1 */
 { 1, PI1, AND }, /* AND, PI2, PI2 */
 { 0, NOR, IMP }, /* AND, PI2, NOR */
 { 1, NOR, NAND }, /* AND, PI2, NLIMP */
 { 0, PI2, NIMP }, /* AND, PI2, NPI1 */
 { 0, NOR, NAND }, /* AND, PI2, NIMP */
 { 1, PI1, NLIMP }, /* AND, PI2, NPI2 */
 { 0, NOP, NOP }, /* AND, PI2, XOR */
 { 0, NOP, NOP }, /* AND, PI2, NAND */
 { 1, NLIMP, NAND }, /* AND, PI2, AND */
 { 0, NOP, NOP }, /* AND, PI2, BIIMP */
 { 0, NOP, NOP }, /* AND, PI2, IMP */
 { 0, NOP, NOP }, /* AND, PI2, LIMP */
 { 0, NOP, NOP }, /* AND, PI2, OR */
 { 1, PI1, PI2 }, /* AND, PI2, K1 */
 { 1, K0, K0 }, /* AND, NOR, K0 */
 { 0, NOR, LIMP }, /* AND, NOR, PI1 */
 { 1, K0, K0 }, /* AND, NOR, PI2 */
 { 1, NOR, OR }, /* AND, NOR, NOR */
 { 1, K0, K0 }, /* AND, NOR, NLIMP */
 { 1, NOR, OR }, /* AND, NOR, NPI1 */
 { 0, NOR, LIMP }, /* AND, NOR, NIMP */
 { 1, PI1, NOR }, /* AND, NOR, NPI2 */
 { 0, NOR, LIMP }, /* AND, NOR, XOR */
 { 1, PI1, NOR }, /* AND, NOR, NAND */
 { 1, K0, K0 }, /* AND, NOR, AND */
 { 1, NOR, OR }, /* AND, NOR, BIIMP */
 { 1, NOR, OR }, /* AND, NOR, IMP */
 { 1, PI1, NOR }, /* AND, NOR, LIMP */
 { 0, NOR, LIMP }, /* AND, NOR, OR */
 { 1, PI1, NOR }, /* AND, NOR, K1 */
 { 1, K0, K0 }, /* AND, NLIMP, K0 */
 { 0, NOR, NAND }, /* AND, NLIMP, PI1 */
 { 1, K0, K0 }, /* AND, NLIMP, PI2 */
 { 0, NOR, IMP }, /* AND, NLIMP, NOR */
 { 1, K0, K0 }, /* AND, NLIMP, NLIMP */
 { 0, NOR, IMP }, /* AND, NLIMP, NPI1 */
 { 0, NOR, NAND }, /* AND, NLIMP, NIMP */
 { 1, PI1, NLIMP }, /* AND, NLIMP, NPI2 */
 { 0, NOR, NAND }, /* AND, NLIMP, XOR */
 { 1, PI1, NLIMP }, /* AND, NLIMP, NAND */
 { 1, K0, K0 }, /* AND, NLIMP, AND */
 { 0, NOR, IMP }, /* AND, NLIMP, BIIMP */
 { 0, NOR, IMP }, /* AND, NLIMP, IMP */
 { 1, PI1, NLIMP }, /* AND, NLIMP, LIMP */
 { 0, NOR, NAND }, /* AND, NLIMP, OR */
 { 1, PI1, NLIMP }, /* AND, NLIMP, K1 */
 { 1, K0, K0 }, /* AND, NPI1, K0 */
 { 1, NLIMP, PI1 }, /* AND, NPI1, PI1 */
 { 1, K0, K0 }, /* AND, NPI1, PI2 */
 { 1, NOR, PI1 }, /* AND, NPI1, NOR */
 { 1, K0, K0 }, /* AND, NPI1, NLIMP */
 { 1, NOR, PI1 }, /* AND, NPI1, NPI1 */
 { 1, NLIMP, PI1 }, /* AND, NPI1, NIMP */
 { 0, NOR, K0 }, /* AND, NPI1, NPI2 */
 { 1, NLIMP, PI1 }, /* AND, NPI1, XOR */
 { 0, NOR, K0 }, /* AND, NPI1, NAND */
 { 1, K0, K0 }, /* AND, NPI1, AND */
 { 1, NOR, PI1 }, /* AND, NPI1, BIIMP */
 { 1, NOR, PI1 }, /* AND, NPI1, IMP */
 { 0, NOR, K0 }, /* AND, NPI1, LIMP */
 { 1, NLIMP, PI1 }, /* AND, NPI1, OR */
 { 0, NOR, K0 }, /* AND, NPI1, K1 */
 { 1, K0, K0 }, /* AND, NIMP, K0 */
 { 1, NLIMP, IMP }, /* AND, NIMP, PI1 */
 { 1, PI1, NIMP }, /* AND, NIMP, PI2 */
 { 1, K0, K0 }, /* AND, NIMP, NOR */
 { 1, NOR, IMP }, /* AND, NIMP, NLIMP */
 { 1, NOR, IMP }, /* AND, NIMP, NPI1 */
 { 1, K0, K0 }, /* AND, NIMP, NIMP */
 { 1, K0, K0 }, /* AND, NIMP, NPI2 */
 { 1, NOR, IMP }, /* AND, NIMP, XOR */
 { 1, NOR, IMP }, /* AND, NIMP, NAND */
 { 1, NLIMP, IMP }, /* AND, NIMP, AND */
 { 1, NLIMP, IMP }, /* AND, NIMP, BIIMP */
 { 1, PI1, NIMP }, /* AND, NIMP, IMP */
 { 1, NLIMP, IMP }, /* AND, NIMP, LIMP */
 { 1, PI1, NIMP }, /* AND, NIMP, OR */
 { 1, PI1, NIMP }, /* AND, NIMP, K1 */
 { 1, K0, K0 }, /* AND, NPI2, K0 */
 { 0, PI2, NLIMP }, /* AND, NPI2, PI1 */
 { 1, PI1, NIMP }, /* AND, NPI2, PI2 */
 { 1, NOR, OR }, /* AND, NPI2, NOR */
 { 1, NOR, IMP }, /* AND, NPI2, NLIMP */
 { 0, PI2, NOR }, /* AND, NPI2, NPI1 */
 { 0, NOR, LIMP }, /* AND, NPI2, NIMP */
 { 1, PI1, NOR }, /* AND, NPI2, NPI2 */
 { 0, NOP, NOP }, /* AND, NPI2, XOR */
 { 0, NOP, NOP }, /* AND, NPI2, NAND */
 { 1, NLIMP, IMP }, /* AND, NPI2, AND */
 { 0, NOP, NOP }, /* AND, NPI2, BIIMP */
 { 0, NOP, NOP }, /* AND, NPI2, IMP */
 { 0, NOP, NOP }, /* AND, NPI2, LIMP */
 { 0, NOP, NOP }, /* AND, NPI2, OR */
 { 1, NPI1, PI2 }, /* AND, NPI2, K1 */
 { 1, K0, K0 }, /* AND, XOR, K0 */
 { 1, NLIMP, BIIMP }, /* AND, XOR, PI1 */
 { 1, PI1, NIMP }, /* AND, XOR, PI2 */
 { 0, NOR, IMP }, /* AND, XOR, NOR */
 { 1, NOR, IMP }, /* AND, XOR, NLIMP */
 { 1, NOR, BIIMP }, /* AND, XOR, NPI1 */
 { 0, NOR, NAND }, /* AND, XOR, NIMP */
 { 1, PI1, NLIMP }, /* AND, XOR, NPI2 */
 { 0, NOP, NOP }, /* AND, XOR, XOR */
 { 0, NOP, NOP }, /* AND, XOR, NAND */
 { 1, NLIMP, IMP }, /* AND, XOR, AND */
 { 0, NOP, NOP }, /* AND, XOR, BIIMP */
 { 0, NOP, NOP }, /* AND, XOR, IMP */
 { 0, NOP, NOP }, /* AND, XOR, LIMP */
 { 0, NOP, NOP }, /* AND, XOR, OR */
 { 1, PI1, XOR }, /* AND, XOR, K1 */
 { 1, K0, K0 }, /* AND, NAND, K0 */
 { 1, NLIMP, AND }, /* AND, NAND, PI1 */
 { 1, PI1, NIMP }, /* AND, NAND, PI2 */
 { 1, NOR, PI1 }, /* AND, NAND, NOR */
 { 1, NOR, IMP }, /* AND, NAND, NLIMP */
 { 1, NOR, AND }, /* AND, NAND, NPI1 */
 { 1, NLIMP, PI1 }, /* AND, NAND, NIMP */
 { 0, NOR, K0 }, /* AND, NAND, NPI2 */
 { 0, NOP, NOP }, /* AND, NAND, XOR */
 { 0, NAND, OR }, /* AND, NAND, NAND */
 { 1, NLIMP, IMP }, /* AND, NAND, AND */
 { 0, NOP, NOP }, /* AND, NAND, BIIMP */
 { 0, NOP, BIIMP }, /* AND, NAND, IMP */
 { 0, NAND, LIMP }, /* AND, NAND, LIMP */
 { 0, NOP, BIIMP }, /* AND, NAND, OR */
 { 1, PI1, NAND }, /* AND, NAND, K1 */
 { 1, K0, K0 }, /* AND, AND, K0 */
 { 1, NLIMP, NAND }, /* AND, AND, PI1 */
 { 1, PI1, AND }, /* AND, AND, PI2 */
 { 1, K0, K0 }, /* AND, AND, NOR */
 { 1, NOR, NAND }, /* AND, AND, NLIMP */
 { 1, NOR, NAND }, /* AND, AND, NPI1 */
 { 1, K0, K0 }, /* AND, AND, NIMP */
 { 1, K0, K0 }, /* AND, AND, NPI2 */
 { 1, NOR, NAND }, /* AND, AND, XOR */
 { 1, NOR, NAND }, /* AND, AND, NAND */
 { 1, NLIMP, NAND }, /* AND, AND, AND */
 { 1, NLIMP, NAND }, /* AND, AND, BIIMP */
 { 1, PI1, AND }, /* AND, AND, IMP */
 { 1, NLIMP, NAND }, /* AND, AND, LIMP */
 { 1, PI1, AND }, /* AND, AND, OR */
 { 1, PI1, AND }, /* AND, AND, K1 */
 { 1, K0, K0 }, /* AND, BIIMP, K0 */
 { 1, NLIMP, XOR }, /* AND, BIIMP, PI1 */
 { 1, PI1, AND }, /* AND, BIIMP, PI2 */
 { 1, NOR, OR }, /* AND, BIIMP, NOR */
 { 1, NOR, NAND }, /* AND, BIIMP, NLIMP */
 { 1, NOR, XOR }, /* AND, BIIMP, NPI1 */
 { 0, NOR, LIMP }, /* AND, BIIMP, NIMP */
 { 1, PI1, NOR }, /* AND, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* AND, BIIMP, XOR */
 { 0, NOP, NOP }, /* AND, BIIMP, NAND */
 { 1, NLIMP, NAND }, /* AND, BIIMP, AND */
 { 0, NOP, NOP }, /* AND, BIIMP, BIIMP */
 { 0, NOP, NOP }, /* AND, BIIMP, IMP */
 { 0, NOP, NOP }, /* AND, BIIMP, LIMP */
 { 0, NOP, NOP }, /* AND, BIIMP, OR */
 { 1, PI1, BIIMP }, /* AND, BIIMP, K1 */
 { 1, K0, K0 }, /* AND, IMP, K0 */
 { 1, NLIMP, NIMP }, /* AND, IMP, PI1 */
 { 1, PI1, AND }, /* AND, IMP, PI2 */
 { 1, NOR, PI1 }, /* AND, IMP, NOR */
 { 1, NOR, NAND }, /* AND, IMP, NLIMP */
 { 1, NOR, NIMP }, /* AND, IMP, NPI1 */
 { 1, NLIMP, PI1 }, /* AND, IMP, NIMP */
 { 0, NOR, K0 }, /* AND, IMP, NPI2 */
 { 0, NOP, NOP }, /* AND, IMP, XOR */
 { 0, NAND, IMP }, /* AND, IMP, NAND */
 { 1, NLIMP, NAND }, /* AND, IMP, AND */
 { 0, NOP, NOP }, /* AND, IMP, BIIMP */
 { 0, NOP, BIIMP }, /* AND, IMP, IMP */
 { 0, NAND, NAND }, /* AND, IMP, LIMP */
 { 0, NOP, BIIMP }, /* AND, IMP, OR */
 { 1, PI1, IMP }, /* AND, IMP, K1 */
 { 1, K0, K0 }, /* AND, LIMP, K0 */
 { 1, NLIMP, NLIMP }, /* AND, LIMP, PI1 */
 { 0, PI1, K0 }, /* AND, LIMP, PI2 */
 { 1, NOR, OR }, /* AND, LIMP, NOR */
 { 1, NIMP, PI1 }, /* AND, LIMP, NLIMP */
 { 1, NOR, NLIMP }, /* AND, LIMP, NPI1 */
 { 0, NOR, LIMP }, /* AND, LIMP, NIMP */
 { 1, PI1, NOR }, /* AND, LIMP, NPI2 */
 { 0, NOP, NOP }, /* AND, LIMP, XOR */
 { 0, NOP, BIIMP }, /* AND, LIMP, NAND */
 { 1, AND, PI1 }, /* AND, LIMP, AND */
 { 0, NOP, NOP }, /* AND, LIMP, BIIMP */
 { 0, LIMP, OR }, /* AND, LIMP, IMP */
 { 0, NOP, BIIMP }, /* AND, LIMP, LIMP */
 { 0, LIMP, LIMP }, /* AND, LIMP, OR */
 { 1, PI1, LIMP }, /* AND, LIMP, K1 */
 { 1, K0, K0 }, /* AND, OR, K0 */
 { 1, NLIMP, NOR }, /* AND, OR, PI1 */
 { 0, PI1, K0 }, /* AND, OR, PI2 */
 { 0, NOR, IMP }, /* AND, OR, NOR */
 { 1, NIMP, PI1 }, /* AND, OR, NLIMP */
 { 1, NOR, NOR }, /* AND, OR, NPI1 */
 { 0, NOR, NAND }, /* AND, OR, NIMP */
 { 1, PI1, NLIMP }, /* AND, OR, NPI2 */
 { 0, NOP, NOP }, /* AND, OR, XOR */
 { 0, NOP, BIIMP }, /* AND, OR, NAND */
 { 1, AND, PI1 }, /* AND, OR, AND */
 { 0, NOP, NOP }, /* AND, OR, BIIMP */
 { 0, LIMP, IMP }, /* AND, OR, IMP */
 { 0, NOP, BIIMP }, /* AND, OR, LIMP */
 { 0, LIMP, NAND }, /* AND, OR, OR */
 { 1, PI1, OR }, /* AND, OR, K1 */
 { 1, K0, K0 }, /* AND, K1, K0 */
 { 1, PI2, K0 }, /* AND, K1, PI1 */
 { 0, PI1, K0 }, /* AND, K1, PI2 */
 { 1, NOR, PI1 }, /* AND, K1, NOR */
 { 1, NIMP, PI1 }, /* AND, K1, NLIMP */
 { 1, NOR, K0 }, /* AND, K1, NPI1 */
 { 1, NLIMP, PI1 }, /* AND, K1, NIMP */
 { 0, NOR, K0 }, /* AND, K1, NPI2 */
 { 1, XOR, PI1 }, /* AND, K1, XOR */
 { 1, NAND, PI1 }, /* AND, K1, NAND */
 { 1, AND, PI1 }, /* AND, K1, AND */
 { 1, BIIMP, PI1 }, /* AND, K1, BIIMP */
 { 1, LIMP, PI1 }, /* AND, K1, IMP */
 { 1, IMP, PI1 }, /* AND, K1, LIMP */
 { 1, OR, PI1 }, /* AND, K1, OR */
 { 1, PI1, K1 }, /* AND, K1, K1 */
 { 1, PI1, K1 }, /* BIIMP, K0, K0 */
 { 1, NOR, K0 }, /* BIIMP, K0, PI1 */
 { 0, NOR, K0 }, /* BIIMP, K0, PI2 */
 { 1, OR, PI1 }, /* BIIMP, K0, NOR */
 { 1, IMP, PI1 }, /* BIIMP, K0, NLIMP */
 { 1, PI2, K0 }, /* BIIMP, K0, NPI1 */
 { 1, LIMP, PI1 }, /* BIIMP, K0, NIMP */
 { 0, PI1, K0 }, /* BIIMP, K0, NPI2 */
 { 1, BIIMP, PI1 }, /* BIIMP, K0, XOR */
 { 1, AND, PI1 }, /* BIIMP, K0, NAND */
 { 1, NAND, PI1 }, /* BIIMP, K0, AND */
 { 1, XOR, PI1 }, /* BIIMP, K0, BIIMP */
 { 1, NLIMP, PI1 }, /* BIIMP, K0, IMP */
 { 1, NIMP, PI1 }, /* BIIMP, K0, LIMP */
 { 1, NOR, PI1 }, /* BIIMP, K0, OR */
 { 1, K0, K0 }, /* BIIMP, K0, K1 */
 { 0, NOR, K0 }, /* BIIMP, PI1, K0 */
 { 1, BIIMP, PI1 }, /* BIIMP, PI1, PI1 */
 { 1, PI1, K1 }, /* BIIMP, PI1, PI2 */
 { 1, NLIMP, PI1 }, /* BIIMP, PI1, NOR */
 { 1, NAND, PI1 }, /* BIIMP, PI1, NLIMP */
 { 1, XOR, PI1 }, /* BIIMP, PI1, NPI1 */
 { 1, NOR, PI1 }, /* BIIMP, PI1, NIMP */
 { 1, K0, K0 }, /* BIIMP, PI1, NPI2 */
 { 1, NOR, K0 }, /* BIIMP, PI1, XOR */
 { 1, NIMP, PI1 }, /* BIIMP, PI1, NAND */
 { 1, IMP, PI1 }, /* BIIMP, PI1, AND */
 { 1, PI2, K0 }, /* BIIMP, PI1, BIIMP */
 { 1, OR, PI1 }, /* BIIMP, PI1, IMP */
 { 1, AND, PI1 }, /* BIIMP, PI1, LIMP */
 { 1, LIMP, PI1 }, /* BIIMP, PI1, OR */
 { 0, PI1, K0 }, /* BIIMP, PI1, K1 */
 { 1, NPI1, PI2 }, /* BIIMP, PI2, K0 */
 { 0, PI2, BIIMP }, /* BIIMP, PI2, PI1 */
 { 1, PI1, BIIMP }, /* BIIMP, PI2, PI2 */
 { 0, NOP, NOP }, /* BIIMP, PI2, NOR */
 { 0, NOP, NOP }, /* BIIMP, PI2, NLIMP */
 { 0, PI2, XOR }, /* BIIMP, PI2, NPI1 */
 { 0, NOP, NOP }, /* BIIMP, PI2, NIMP */
 { 1, PI1, XOR }, /* BIIMP, PI2, NPI2 */
 { 1, XOR, BIIMP }, /* BIIMP, PI2, XOR */
 { 0, NOP, NOP }, /* BIIMP, PI2, NAND */
 { 0, NOP, NOP }, /* BIIMP, PI2, AND */
 { 1, XOR, XOR }, /* BIIMP, PI2, BIIMP */
 { 0, NOP, NOP }, /* BIIMP, PI2, IMP */
 { 0, NOP, NOP }, /* BIIMP, PI2, LIMP */
 { 0, NOP, NOP }, /* BIIMP, PI2, OR */
 { 1, PI1, PI2 }, /* BIIMP, PI2, K1 */
 { 1, PI1, OR }, /* BIIMP, NOR, K0 */
 { 1, XOR, OR }, /* BIIMP, NOR, PI1 */
 { 1, PI1, NLIMP }, /* BIIMP, NOR, PI2 */
 { 0, LIMP, XOR }, /* BIIMP, NOR, NOR */
 { 0, NOP, NOR }, /* BIIMP, NOR, NLIMP */
 { 1, XOR, NOR }, /* BIIMP, NOR, NPI1 */
 { 0, LIMP, BIIMP }, /* BIIMP, NOR, NIMP */
 { 1, PI1, LIMP }, /* BIIMP, NOR, NPI2 */
 { 1, XOR, NLIMP }, /* BIIMP, NOR, XOR */
 { 0, NOP, LIMP }, /* BIIMP, NOR, NAND */
 { 0, NOP, NOR }, /* BIIMP, NOR, AND */
 { 1, XOR, LIMP }, /* BIIMP, NOR, BIIMP */
 { 0, NOR, XOR }, /* BIIMP, NOR, IMP */
 { 0, NOP, LIMP }, /* BIIMP, NOR, LIMP */
 { 0, NOR, BIIMP }, /* BIIMP, NOR, OR */
 { 1, PI1, NOR }, /* BIIMP, NOR, K1 */
 { 1, PI1, LIMP }, /* BIIMP, NLIMP, K0 */
 { 1, XOR, LIMP }, /* BIIMP, NLIMP, PI1 */
 { 1, PI1, NOR }, /* BIIMP, NLIMP, PI2 */
 { 0, LIMP, BIIMP }, /* BIIMP, NLIMP, NOR */
 { 0, NOP, NOR }, /* BIIMP, NLIMP, NLIMP */
 { 1, XOR, NLIMP }, /* BIIMP, NLIMP, NPI1 */
 { 0, LIMP, XOR }, /* BIIMP, NLIMP, NIMP */
 { 1, PI1, OR }, /* BIIMP, NLIMP, NPI2 */
 { 1, XOR, NOR }, /* BIIMP, NLIMP, XOR */
 { 0, NOP, LIMP }, /* BIIMP, NLIMP, NAND */
 { 0, NOP, NOR }, /* BIIMP, NLIMP, AND */
 { 1, XOR, OR }, /* BIIMP, NLIMP, BIIMP */
 { 0, NOR, BIIMP }, /* BIIMP, NLIMP, IMP */
 { 0, NOP, LIMP }, /* BIIMP, NLIMP, LIMP */
 { 0, NOR, XOR }, /* BIIMP, NLIMP, OR */
 { 1, PI1, NLIMP }, /* BIIMP, NLIMP, K1 */
 { 0, PI1, K0 }, /* BIIMP, NPI1, K0 */
 { 1, XOR, PI1 }, /* BIIMP, NPI1, PI1 */
 { 1, K0, K0 }, /* BIIMP, NPI1, PI2 */
 { 1, LIMP, PI1 }, /* BIIMP, NPI1, NOR */
 { 1, AND, PI1 }, /* BIIMP, NPI1, NLIMP */
 { 1, BIIMP, PI1 }, /* BIIMP, NPI1, NPI1 */
 { 1, OR, PI1 }, /* BIIMP, NPI1, NIMP */
 { 1, PI1, K1 }, /* BIIMP, NPI1, NPI2 */
 { 1, PI2, K0 }, /* BIIMP, NPI1, XOR */
 { 1, IMP, PI1 }, /* BIIMP, NPI1, NAND */
 { 1, NIMP, PI1 }, /* BIIMP, NPI1, AND */
 { 1, NOR, K0 }, /* BIIMP, NPI1, BIIMP */
 { 1, NOR, PI1 }, /* BIIMP, NPI1, IMP */
 { 1, NAND, PI1 }, /* BIIMP, NPI1, LIMP */
 { 1, NLIMP, PI1 }, /* BIIMP, NPI1, OR */
 { 0, NOR, K0 }, /* BIIMP, NPI1, K1 */
 { 1, PI1, IMP }, /* BIIMP, NIMP, K0 */
 { 1, XOR, IMP }, /* BIIMP, NIMP, PI1 */
 { 1, PI1, NAND }, /* BIIMP, NIMP, PI2 */
 { 0, NOP, NOR }, /* BIIMP, NIMP, NOR */
 { 0, NAND, XOR }, /* BIIMP, NIMP, NLIMP */
 { 1, XOR, NIMP }, /* BIIMP, NIMP, NPI1 */
 { 0, NOP, NOR }, /* BIIMP, NIMP, NIMP */
 { 1, PI1, AND }, /* BIIMP, NIMP, NPI2 */
 { 1, XOR, NAND }, /* BIIMP, NIMP, XOR */
 { 0, NIMP, XOR }, /* BIIMP, NIMP, NAND */
 { 0, NAND, BIIMP }, /* BIIMP, NIMP, AND */
 { 1, XOR, AND }, /* BIIMP, NIMP, BIIMP */
 { 0, NOP, LIMP }, /* BIIMP, NIMP, IMP */
 { 0, NIMP, BIIMP }, /* BIIMP, NIMP, LIMP */
 { 0, NOP, LIMP }, /* BIIMP, NIMP, OR */
 { 1, PI1, NIMP }, /* BIIMP, NIMP, K1 */
 { 1, PI1, PI2 }, /* BIIMP, NPI2, K0 */
 { 0, PI2, XOR }, /* BIIMP, NPI2, PI1 */
 { 1, PI1, XOR }, /* BIIMP, NPI2, PI2 */
 { 0, NOP, NOP }, /* BIIMP, NPI2, NOR */
 { 0, NOP, NOP }, /* BIIMP, NPI2, NLIMP */
 { 0, PI2, BIIMP }, /* BIIMP, NPI2, NPI1 */
 { 0, NOP, NOP }, /* BIIMP, NPI2, NIMP */
 { 1, PI1, BIIMP }, /* BIIMP, NPI2, NPI2 */
 { 1, XOR, XOR }, /* BIIMP, NPI2, XOR */
 { 0, NOP, NOP }, /* BIIMP, NPI2, NAND */
 { 0, NOP, NOP }, /* BIIMP, NPI2, AND */
 { 1, XOR, BIIMP }, /* BIIMP, NPI2, BIIMP */
 { 0, NOP, NOP }, /* BIIMP, NPI2, IMP */
 { 0, NOP, NOP }, /* BIIMP, NPI2, LIMP */
 { 0, NOP, NOP }, /* BIIMP, NPI2, OR */
 { 1, NPI1, PI2 }, /* BIIMP, NPI2, K1 */
 { 1, PI1, BIIMP }, /* BIIMP, XOR, K0 */
 { 1, XOR, BIIMP }, /* BIIMP, XOR, PI1 */
 { 1, NPI1, PI2 }, /* BIIMP, XOR, PI2 */
 { 0, NOP, NOP }, /* BIIMP, XOR, NOR */
 { 0, NOP, NOP }, /* BIIMP, XOR, NLIMP */
 { 1, XOR, XOR }, /* BIIMP, XOR, NPI1 */
 { 0, NOP, NOP }, /* BIIMP, XOR, NIMP */
 { 1, PI1, PI2 }, /* BIIMP, XOR, NPI2 */
 { 0, PI2, BIIMP }, /* BIIMP, XOR, XOR */
 { 0, NOP, NOP }, /* BIIMP, XOR, NAND */
 { 0, NOP, NOP }, /* BIIMP, XOR, AND */
 { 0, PI2, XOR }, /* BIIMP, XOR, BIIMP */
 { 0, NOP, NOP }, /* BIIMP, XOR, IMP */
 { 0, NOP, NOP }, /* BIIMP, XOR, LIMP */
 { 0, NOP, NOP }, /* BIIMP, XOR, OR */
 { 1, PI1, XOR }, /* BIIMP, XOR, K1 */
 { 1, PI1, AND }, /* BIIMP, NAND, K0 */
 { 1, XOR, AND }, /* BIIMP, NAND, PI1 */
 { 1, PI1, NIMP }, /* BIIMP, NAND, PI2 */
 { 0, NOP, IMP }, /* BIIMP, NAND, NOR */
 { 0, NIMP, XOR }, /* BIIMP, NAND, NLIMP */
 { 1, XOR, NAND }, /* BIIMP, NAND, NPI1 */
 { 0, NOP, IMP }, /* BIIMP, NAND, NIMP */
 { 1, PI1, IMP }, /* BIIMP, NAND, NPI2 */
 { 1, XOR, NIMP }, /* BIIMP, NAND, XOR */
 { 0, NAND, XOR }, /* BIIMP, NAND, NAND */
 { 0, NIMP, BIIMP }, /* BIIMP, NAND, AND */
 { 1, XOR, IMP }, /* BIIMP, NAND, BIIMP */
 { 0, NOP, AND }, /* BIIMP, NAND, IMP */
 { 0, NAND, BIIMP }, /* BIIMP, NAND, LIMP */
 { 0, NOP, AND }, /* BIIMP, NAND, OR */
 { 1, PI1, NAND }, /* BIIMP, NAND, K1 */
 { 1, PI1, NAND }, /* BIIMP, AND, K0 */
 { 1, XOR, NAND }, /* BIIMP, AND, PI1 */
 { 1, PI1, IMP }, /* BIIMP, AND, PI2 */
 { 0, NOP, NOR }, /* BIIMP, AND, NOR */
 { 0, NAND, BIIMP }, /* BIIMP, AND, NLIMP */
 { 1, XOR, AND }, /* BIIMP, AND, NPI1 */
 { 0, NOP, NOR }, /* BIIMP, AND, NIMP */
 { 1, PI1, NIMP }, /* BIIMP, AND, NPI2 */
 { 1, XOR, IMP }, /* BIIMP, AND, XOR */
 { 0, NIMP, BIIMP }, /* BIIMP, AND, NAND */
 { 0, NAND, XOR }, /* BIIMP, AND, AND */
 { 1, XOR, NIMP }, /* BIIMP, AND, BIIMP */
 { 0, NOP, LIMP }, /* BIIMP, AND, IMP */
 { 0, NIMP, XOR }, /* BIIMP, AND, LIMP */
 { 0, NOP, LIMP }, /* BIIMP, AND, OR */
 { 1, PI1, AND }, /* BIIMP, AND, K1 */
 { 1, PI1, XOR }, /* BIIMP, BIIMP, K0 */
 { 1, XOR, XOR }, /* BIIMP, BIIMP, PI1 */
 { 1, PI1, PI2 }, /* BIIMP, BIIMP, PI2 */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, NOR */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, NLIMP */
 { 1, XOR, BIIMP }, /* BIIMP, BIIMP, NPI1 */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, NIMP */
 { 1, NPI1, PI2 }, /* BIIMP, BIIMP, NPI2 */
 { 0, PI2, XOR }, /* BIIMP, BIIMP, XOR */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, NAND */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, AND */
 { 0, PI2, BIIMP }, /* BIIMP, BIIMP, BIIMP */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, IMP */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, LIMP */
 { 0, NOP, NOP }, /* BIIMP, BIIMP, OR */
 { 1, PI1, BIIMP }, /* BIIMP, BIIMP, K1 */
 { 1, PI1, NIMP }, /* BIIMP, IMP, K0 */
 { 1, XOR, NIMP }, /* BIIMP, IMP, PI1 */
 { 1, PI1, AND }, /* BIIMP, IMP, PI2 */
 { 0, NOP, IMP }, /* BIIMP, IMP, NOR */
 { 0, NIMP, BIIMP }, /* BIIMP, IMP, NLIMP */
 { 1, XOR, IMP }, /* BIIMP, IMP, NPI1 */
 { 0, NOP, IMP }, /* BIIMP, IMP, NIMP */
 { 1, PI1, NAND }, /* BIIMP, IMP, NPI2 */
 { 1, XOR, AND }, /* BIIMP, IMP, XOR */
 { 0, NAND, BIIMP }, /* BIIMP, IMP, NAND */
 { 0, NIMP, XOR }, /* BIIMP, IMP, AND */
 { 1, XOR, NAND }, /* BIIMP, IMP, BIIMP */
 { 0, NOP, AND }, /* BIIMP, IMP, IMP */
 { 0, NAND, XOR }, /* BIIMP, IMP, LIMP */
 { 0, NOP, AND }, /* BIIMP, IMP, OR */
 { 1, PI1, IMP }, /* BIIMP, IMP, K1 */
 { 1, PI1, NLIMP }, /* BIIMP, LIMP, K0 */
 { 1, XOR, NLIMP }, /* BIIMP, LIMP, PI1 */
 { 1, PI1, OR }, /* BIIMP, LIMP, PI2 */
 { 0, NOR, XOR }, /* BIIMP, LIMP, NOR */
 { 0, NOP, IMP }, /* BIIMP, LIMP, NLIMP */
 { 1, XOR, LIMP }, /* BIIMP, LIMP, NPI1 */
 { 0, NOR, BIIMP }, /* BIIMP, LIMP, NIMP */
 { 1, PI1, NOR }, /* BIIMP, LIMP, NPI2 */
 { 1, XOR, OR }, /* BIIMP, LIMP, XOR */
 { 0, NOP, AND }, /* BIIMP, LIMP, NAND */
 { 0, NOP, IMP }, /* BIIMP, LIMP, AND */
 { 1, XOR, NOR }, /* BIIMP, LIMP, BIIMP */
 { 0, LIMP, XOR }, /* BIIMP, LIMP, IMP */
 { 0, NOP, AND }, /* BIIMP, LIMP, LIMP */
 { 0, LIMP, BIIMP }, /* BIIMP, LIMP, OR */
 { 1, PI1, LIMP }, /* BIIMP, LIMP, K1 */
 { 1, PI1, NOR }, /* BIIMP, OR, K0 */
 { 1, XOR, NOR }, /* BIIMP, OR, PI1 */
 { 1, PI1, LIMP }, /* BIIMP, OR, PI2 */
 { 0, NOR, BIIMP }, /* BIIMP, OR, NOR */
 { 0, NOP, IMP }, /* BIIMP, OR, NLIMP */
 { 1, XOR, OR }, /* BIIMP, OR, NPI1 */
 { 0, NOR, XOR }, /* BIIMP, OR, NIMP */
 { 1, PI1, NLIMP }, /* BIIMP, OR, NPI2 */
 { 1, XOR, LIMP }, /* BIIMP, OR, XOR */
 { 0, NOP, AND }, /* BIIMP, OR, NAND */
 { 0, NOP, IMP }, /* BIIMP, OR, AND */
 { 1, XOR, NLIMP }, /* BIIMP, OR, BIIMP */
 { 0, LIMP, BIIMP }, /* BIIMP, OR, IMP */
 { 0, NOP, AND }, /* BIIMP, OR, LIMP */
 { 0, LIMP, XOR }, /* BIIMP, OR, OR */
 { 1, PI1, OR }, /* BIIMP, OR, K1 */
 { 1, K0, K0 }, /* BIIMP, K1, K0 */
 { 1, PI2, K0 }, /* BIIMP, K1, PI1 */
 { 0, PI1, K0 }, /* BIIMP, K1, PI2 */
 { 1, NOR, PI1 }, /* BIIMP, K1, NOR */
 { 1, NIMP, PI1 }, /* BIIMP, K1, NLIMP */
 { 1, NOR, K0 }, /* BIIMP, K1, NPI1 */
 { 1, NLIMP, PI1 }, /* BIIMP, K1, NIMP */
 { 0, NOR, K0 }, /* BIIMP, K1, NPI2 */
 { 1, XOR, PI1 }, /* BIIMP, K1, XOR */
 { 1, NAND, PI1 }, /* BIIMP, K1, NAND */
 { 1, AND, PI1 }, /* BIIMP, K1, AND */
 { 1, BIIMP, PI1 }, /* BIIMP, K1, BIIMP */
 { 1, LIMP, PI1 }, /* BIIMP, K1, IMP */
 { 1, IMP, PI1 }, /* BIIMP, K1, LIMP */
 { 1, OR, PI1 }, /* BIIMP, K1, OR */
 { 1, PI1, K1 }, /* BIIMP, K1, K1 */
 { 1, PI1, K1 }, /* IMP, K0, K0 */
 { 1, PI1, K1 }, /* IMP, K0, PI1 */
 { 1, PI1, K1 }, /* IMP, K0, PI2 */
 { 1, PI1, K1 }, /* IMP, K0, NOR */
 { 1, PI1, K1 }, /* IMP, K0, NLIMP */
 { 1, PI1, K1 }, /* IMP, K0, NPI1 */
 { 1, PI1, K1 }, /* IMP, K0, NIMP */
 { 1, PI1, K1 }, /* IMP, K0, NPI2 */
 { 1, PI1, K1 }, /* IMP, K0, XOR */
 { 1, PI1, K1 }, /* IMP, K0, NAND */
 { 1, PI1, K1 }, /* IMP, K0, AND */
 { 1, PI1, K1 }, /* IMP, K0, BIIMP */
 { 1, PI1, K1 }, /* IMP, K0, IMP */
 { 1, PI1, K1 }, /* IMP, K0, LIMP */
 { 1, PI1, K1 }, /* IMP, K0, OR */
 { 1, PI1, K1 }, /* IMP, K0, K1 */
 { 0, NOR, K0 }, /* IMP, PI1, K0 */
 { 1, IMP, PI1 }, /* IMP, PI1, PI1 */
 { 1, PI1, K1 }, /* IMP, PI1, PI2 */
 { 0, NOR, K0 }, /* IMP, PI1, NOR */
 { 1, NAND, PI1 }, /* IMP, PI1, NLIMP */
 { 1, NAND, PI1 }, /* IMP, PI1, NPI1 */
 { 0, NOR, K0 }, /* IMP, PI1, NIMP */
 { 0, NOR, K0 }, /* IMP, PI1, NPI2 */
 { 1, NAND, PI1 }, /* IMP, PI1, XOR */
 { 1, NAND, PI1 }, /* IMP, PI1, NAND */
 { 1, IMP, PI1 }, /* IMP, PI1, AND */
 { 1, IMP, PI1 }, /* IMP, PI1, BIIMP */
 { 1, PI1, K1 }, /* IMP, PI1, IMP */
 { 1, IMP, PI1 }, /* IMP, PI1, LIMP */
 { 1, PI1, K1 }, /* IMP, PI1, OR */
 { 1, PI1, K1 }, /* IMP, PI1, K1 */
 { 1, NPI1, PI2 }, /* IMP, PI2, K0 */
 { 0, PI2, IMP }, /* IMP, PI2, PI1 */
 { 1, PI1, LIMP }, /* IMP, PI2, PI2 */
 { 0, NOP, NOP }, /* IMP, PI2, NOR */
 { 0, NOP, NOP }, /* IMP, PI2, NLIMP */
 { 0, PI2, NAND }, /* IMP, PI2, NPI1 */
 { 0, NOP, NOP }, /* IMP, PI2, NIMP */
 { 1, PI1, NAND }, /* IMP, PI2, NPI2 */
 { 0, NOP, NOP }, /* IMP, PI2, XOR */
 { 1, NAND, AND }, /* IMP, PI2, NAND */
 { 0, NOP, NOP }, /* IMP, PI2, AND */
 { 0, NOP, NOP }, /* IMP, PI2, BIIMP */
 { 1, NAND, NLIMP }, /* IMP, PI2, IMP */
 { 0, NAND, NIMP }, /* IMP, PI2, LIMP */
 { 1, IMP, NLIMP }, /* IMP, PI2, OR */
 { 1, PI1, K1 }, /* IMP, PI2, K1 */
 { 1, PI1, OR }, /* IMP, NOR, K0 */
 { 1, IMP, NOR }, /* IMP, NOR, PI1 */
 { 1, PI1, OR }, /* IMP, NOR, PI2 */
 { 1, NAND, NOR }, /* IMP, NOR, NOR */
 { 1, PI1, OR }, /* IMP, NOR, NLIMP */
 { 1, NAND, NOR }, /* IMP, NOR, NPI1 */
 { 1, IMP, NOR }, /* IMP, NOR, NIMP */
 { 1, PI1, K1 }, /* IMP, NOR, NPI2 */
 { 1, IMP, NOR }, /* IMP, NOR, XOR */
 { 1, PI1, K1 }, /* IMP, NOR, NAND */
 { 1, PI1, OR }, /* IMP, NOR, AND */
 { 1, NAND, NOR }, /* IMP, NOR, BIIMP */
 { 1, NAND, NOR }, /* IMP, NOR, IMP */
 { 1, PI1, K1 }, /* IMP, NOR, LIMP */
 { 1, IMP, NOR }, /* IMP, NOR, OR */
 { 1, PI1, K1 }, /* IMP, NOR, K1 */
 { 1, PI1, LIMP }, /* IMP, NLIMP, K0 */
 { 1, IMP, NLIMP }, /* IMP, NLIMP, PI1 */
 { 1, PI1, LIMP }, /* IMP, NLIMP, PI2 */
 { 1, NAND, NLIMP }, /* IMP, NLIMP, NOR */
 { 1, PI1, LIMP }, /* IMP, NLIMP, NLIMP */
 { 1, NAND, NLIMP }, /* IMP, NLIMP, NPI1 */
 { 1, IMP, NLIMP }, /* IMP, NLIMP, NIMP */
 { 1, PI1, K1 }, /* IMP, NLIMP, NPI2 */
 { 1, IMP, NLIMP }, /* IMP, NLIMP, XOR */
 { 1, PI1, K1 }, /* IMP, NLIMP, NAND */
 { 1, PI1, LIMP }, /* IMP, NLIMP, AND */
 { 1, NAND, NLIMP }, /* IMP, NLIMP, BIIMP */
 { 1, NAND, NLIMP }, /* IMP, NLIMP, IMP */
 { 1, PI1, K1 }, /* IMP, NLIMP, LIMP */
 { 1, IMP, NLIMP }, /* IMP, NLIMP, OR */
 { 1, PI1, K1 }, /* IMP, NLIMP, K1 */
 { 0, PI1, K0 }, /* IMP, NPI1, K0 */
 { 1, OR, PI1 }, /* IMP, NPI1, PI1 */
 { 0, PI1, K0 }, /* IMP, NPI1, PI2 */
 { 1, LIMP, PI1 }, /* IMP, NPI1, NOR */
 { 0, PI1, K0 }, /* IMP, NPI1, NLIMP */
 { 1, LIMP, PI1 }, /* IMP, NPI1, NPI1 */
 { 1, OR, PI1 }, /* IMP, NPI1, NIMP */
 { 1, PI1, K1 }, /* IMP, NPI1, NPI2 */
 { 1, OR, PI1 }, /* IMP, NPI1, XOR */
 { 1, PI1, K1 }, /* IMP, NPI1, NAND */
 { 0, PI1, K0 }, /* IMP, NPI1, AND */
 { 1, LIMP, PI1 }, /* IMP, NPI1, BIIMP */
 { 1, LIMP, PI1 }, /* IMP, NPI1, IMP */
 { 1, PI1, K1 }, /* IMP, NPI1, LIMP */
 { 1, OR, PI1 }, /* IMP, NPI1, OR */
 { 1, PI1, K1 }, /* IMP, NPI1, K1 */
 { 1, PI1, IMP }, /* IMP, NIMP, K0 */
 { 0, NAND, NOR }, /* IMP, NIMP, PI1 */
 { 1, PI1, K1 }, /* IMP, NIMP, PI2 */
 { 1, PI1, IMP }, /* IMP, NIMP, NOR */
 { 0, NAND, NLIMP }, /* IMP, NIMP, NLIMP */
 { 0, NAND, NLIMP }, /* IMP, NIMP, NPI1 */
 { 1, PI1, IMP }, /* IMP, NIMP, NIMP */
 { 1, PI1, IMP }, /* IMP, NIMP, NPI2 */
 { 0, NAND, NLIMP }, /* IMP, NIMP, XOR */
 { 0, NAND, NLIMP }, /* IMP, NIMP, NAND */
 { 0, NAND, NOR }, /* IMP, NIMP, AND */
 { 0, NAND, NOR }, /* IMP, NIMP, BIIMP */
 { 1, PI1, K1 }, /* IMP, NIMP, IMP */
 { 0, NAND, NOR }, /* IMP, NIMP, LIMP */
 { 1, PI1, K1 }, /* IMP, NIMP, OR */
 { 1, PI1, K1 }, /* IMP, NIMP, K1 */
 { 1, PI1, PI2 }, /* IMP, NPI2, K0 */
 { 0, PI2, OR }, /* IMP, NPI2, PI1 */
 { 1, PI1, OR }, /* IMP, NPI2, PI2 */
 { 0, NOP, NOP }, /* IMP, NPI2, NOR */
 { 0, NOP, NOP }, /* IMP, NPI2, NLIMP */
 { 0, PI2, LIMP }, /* IMP, NPI2, NPI1 */
 { 0, NOP, NOP }, /* IMP, NPI2, NIMP */
 { 1, PI1, IMP }, /* IMP, NPI2, NPI2 */
 { 0, NOP, NOP }, /* IMP, NPI2, XOR */
 { 0, NAND, NLIMP }, /* IMP, NPI2, NAND */
 { 0, NOP, NOP }, /* IMP, NPI2, AND */
 { 0, NOP, NOP }, /* IMP, NPI2, BIIMP */
 { 1, NAND, NOR }, /* IMP, NPI2, IMP */
 { 0, NAND, NOR }, /* IMP, NPI2, LIMP */
 { 1, IMP, NOR }, /* IMP, NPI2, OR */
 { 1, PI1, K1 }, /* IMP, NPI2, K1 */
 { 1, PI1, BIIMP }, /* IMP, XOR, K0 */
 { 1, IMP, XOR }, /* IMP, XOR, PI1 */
 { 1, PI1, LIMP }, /* IMP, XOR, PI2 */
 { 0, NOP, NOP }, /* IMP, XOR, NOR */
 { 0, NOP, NOP }, /* IMP, XOR, NLIMP */
 { 1, NAND, XOR }, /* IMP, XOR, NPI1 */
 { 0, NOP, NOP }, /* IMP, XOR, NIMP */
 { 1, PI1, IMP }, /* IMP, XOR, NPI2 */
 { 0, NOP, NOP }, /* IMP, XOR, XOR */
 { 0, NAND, NLIMP }, /* IMP, XOR, NAND */
 { 0, NOP, NOP }, /* IMP, XOR, AND */
 { 0, NOP, NOP }, /* IMP, XOR, BIIMP */
 { 1, NAND, NLIMP }, /* IMP, XOR, IMP */
 { 0, NAND, NOR }, /* IMP, XOR, LIMP */
 { 1, IMP, NLIMP }, /* IMP, XOR, OR */
 { 1, PI1, K1 }, /* IMP, XOR, K1 */
 { 1, PI1, AND }, /* IMP, NAND, K0 */
 { 1, IMP, NAND }, /* IMP, NAND, PI1 */
 { 0, PI1, K0 }, /* IMP, NAND, PI2 */
 { 0, NOP, BIIMP }, /* IMP, NAND, NOR */
 { 0, NIMP, NLIMP }, /* IMP, NAND, NLIMP */
 { 1, NAND, NAND }, /* IMP, NAND, NPI1 */
 { 0, NOP, BIIMP }, /* IMP, NAND, NIMP */
 { 1, PI1, IMP }, /* IMP, NAND, NPI2 */
 { 0, NOP, NOP }, /* IMP, NAND, XOR */
 { 0, NAND, NLIMP }, /* IMP, NAND, NAND */
 { 0, NIMP, NOR }, /* IMP, NAND, AND */
 { 0, NOP, NOP }, /* IMP, NAND, BIIMP */
 { 1, LIMP, PI1 }, /* IMP, NAND, IMP */
 { 0, NAND, NOR }, /* IMP, NAND, LIMP */
 { 1, OR, PI1 }, /* IMP, NAND, OR */
 { 1, PI1, K1 }, /* IMP, NAND, K1 */
 { 1, PI1, NAND }, /* IMP, AND, K0 */
 { 0, NAND, NIMP }, /* IMP, AND, PI1 */
 { 1, PI1, K1 }, /* IMP, AND, PI2 */
 { 1, PI1, NAND }, /* IMP, AND, NOR */
 { 1, NAND, AND }, /* IMP, AND, NLIMP */
 { 1, NAND, AND }, /* IMP, AND, NPI1 */
 { 1, PI1, NAND }, /* IMP, AND, NIMP */
 { 1, PI1, NAND }, /* IMP, AND, NPI2 */
 { 1, NAND, AND }, /* IMP, AND, XOR */
 { 1, NAND, AND }, /* IMP, AND, NAND */
 { 0, NAND, NIMP }, /* IMP, AND, AND */
 { 0, NAND, NIMP }, /* IMP, AND, BIIMP */
 { 1, PI1, K1 }, /* IMP, AND, IMP */
 { 0, NAND, NIMP }, /* IMP, AND, LIMP */
 { 1, PI1, K1 }, /* IMP, AND, OR */
 { 1, PI1, K1 }, /* IMP, AND, K1 */
 { 1, PI1, XOR }, /* IMP, BIIMP, K0 */
 { 1, IMP, BIIMP }, /* IMP, BIIMP, PI1 */
 { 1, PI1, OR }, /* IMP, BIIMP, PI2 */
 { 0, NOP, NOP }, /* IMP, BIIMP, NOR */
 { 0, NOP, NOP }, /* IMP, BIIMP, NLIMP */
 { 1, NAND, BIIMP }, /* IMP, BIIMP, NPI1 */
 { 0, NOP, NOP }, /* IMP, BIIMP, NIMP */
 { 1, PI1, NAND }, /* IMP, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* IMP, BIIMP, XOR */
 { 1, NAND, AND }, /* IMP, BIIMP, NAND */
 { 0, NOP, NOP }, /* IMP, BIIMP, AND */
 { 0, NOP, NOP }, /* IMP, BIIMP, BIIMP */
 { 1, NAND, NOR }, /* IMP, BIIMP, IMP */
 { 0, NAND, NIMP }, /* IMP, BIIMP, LIMP */
 { 1, IMP, NOR }, /* IMP, BIIMP, OR */
 { 1, PI1, K1 }, /* IMP, BIIMP, K1 */
 { 1, PI1, NIMP }, /* IMP, IMP, K0 */
 { 1, IMP, IMP }, /* IMP, IMP, PI1 */
 { 0, PI1, K0 }, /* IMP, IMP, PI2 */
 { 0, NOP, BIIMP }, /* IMP, IMP, NOR */
 { 0, NIMP, AND }, /* IMP, IMP, NLIMP */
 { 1, NAND, IMP }, /* IMP, IMP, NPI1 */
 { 0, NOP, BIIMP }, /* IMP, IMP, NIMP */
 { 1, PI1, NAND }, /* IMP, IMP, NPI2 */
 { 0, NOP, NOP }, /* IMP, IMP, XOR */
 { 1, NAND, AND }, /* IMP, IMP, NAND */
 { 0, NIMP, NIMP }, /* IMP, IMP, AND */
 { 0, NOP, NOP }, /* IMP, IMP, BIIMP */
 { 1, LIMP, PI1 }, /* IMP, IMP, IMP */
 { 0, NAND, NIMP }, /* IMP, IMP, LIMP */
 { 1, OR, PI1 }, /* IMP, IMP, OR */
 { 1, PI1, K1 }, /* IMP, IMP, K1 */
 { 1, PI1, NLIMP }, /* IMP, LIMP, K0 */
 { 1, IMP, LIMP }, /* IMP, LIMP, PI1 */
 { 1, PI1, OR }, /* IMP, LIMP, PI2 */
 { 0, NOR, NLIMP }, /* IMP, LIMP, NOR */
 { 0, NOP, BIIMP }, /* IMP, LIMP, NLIMP */
 { 1, NAND, LIMP }, /* IMP, LIMP, NPI1 */
 { 0, NOR, NOR }, /* IMP, LIMP, NIMP */
 { 0, NOR, K0 }, /* IMP, LIMP, NPI2 */
 { 0, NOP, NOP }, /* IMP, LIMP, XOR */
 { 1, NAND, PI1 }, /* IMP, LIMP, NAND */
 { 0, NOP, BIIMP }, /* IMP, LIMP, AND */
 { 0, NOP, NOP }, /* IMP, LIMP, BIIMP */
 { 1, NAND, NOR }, /* IMP, LIMP, IMP */
 { 1, IMP, PI1 }, /* IMP, LIMP, LIMP */
 { 1, IMP, NOR }, /* IMP, LIMP, OR */
 { 1, PI1, K1 }, /* IMP, LIMP, K1 */
 { 1, PI1, NOR }, /* IMP, OR, K0 */
 { 1, IMP, OR }, /* IMP, OR, PI1 */
 { 1, PI1, LIMP }, /* IMP, OR, PI2 */
 { 0, NOR, AND }, /* IMP, OR, NOR */
 { 0, NOP, BIIMP }, /* IMP, OR, NLIMP */
 { 1, NAND, OR }, /* IMP, OR, NPI1 */
 { 0, NOR, NIMP }, /* IMP, OR, NIMP */
 { 0, NOR, K0 }, /* IMP, OR, NPI2 */
 { 0, NOP, NOP }, /* IMP, OR, XOR */
 { 1, NAND, PI1 }, /* IMP, OR, NAND */
 { 0, NOP, BIIMP }, /* IMP, OR, AND */
 { 0, NOP, NOP }, /* IMP, OR, BIIMP */
 { 1, NAND, NLIMP }, /* IMP, OR, IMP */
 { 1, IMP, PI1 }, /* IMP, OR, LIMP */
 { 1, IMP, NLIMP }, /* IMP, OR, OR */
 { 1, PI1, K1 }, /* IMP, OR, K1 */
 { 1, K0, K0 }, /* IMP, K1, K0 */
 { 1, PI2, K0 }, /* IMP, K1, PI1 */
 { 0, PI1, K0 }, /* IMP, K1, PI2 */
 { 1, NOR, PI1 }, /* IMP, K1, NOR */
 { 1, NIMP, PI1 }, /* IMP, K1, NLIMP */
 { 1, NOR, K0 }, /* IMP, K1, NPI1 */
 { 1, NLIMP, PI1 }, /* IMP, K1, NIMP */
 { 0, NOR, K0 }, /* IMP, K1, NPI2 */
 { 1, XOR, PI1 }, /* IMP, K1, XOR */
 { 1, NAND, PI1 }, /* IMP, K1, NAND */
 { 1, AND, PI1 }, /* IMP, K1, AND */
 { 1, BIIMP, PI1 }, /* IMP, K1, BIIMP */
 { 1, LIMP, PI1 }, /* IMP, K1, IMP */
 { 1, IMP, PI1 }, /* IMP, K1, LIMP */
 { 1, OR, PI1 }, /* IMP, K1, OR */
 { 1, PI1, K1 }, /* IMP, K1, K1 */
 { 1, PI1, K1 }, /* LIMP, K0, K0 */
 { 1, NOR, K0 }, /* LIMP, K0, PI1 */
 { 0, NOR, K0 }, /* LIMP, K0, PI2 */
 { 1, OR, PI1 }, /* LIMP, K0, NOR */
 { 1, IMP, PI1 }, /* LIMP, K0, NLIMP */
 { 1, PI2, K0 }, /* LIMP, K0, NPI1 */
 { 1, LIMP, PI1 }, /* LIMP, K0, NIMP */
 { 0, PI1, K0 }, /* LIMP, K0, NPI2 */
 { 1, BIIMP, PI1 }, /* LIMP, K0, XOR */
 { 1, AND, PI1 }, /* LIMP, K0, NAND */
 { 1, NAND, PI1 }, /* LIMP, K0, AND */
 { 1, XOR, PI1 }, /* LIMP, K0, BIIMP */
 { 1, NLIMP, PI1 }, /* LIMP, K0, IMP */
 { 1, NIMP, PI1 }, /* LIMP, K0, LIMP */
 { 1, NOR, PI1 }, /* LIMP, K0, OR */
 { 1, K0, K0 }, /* LIMP, K0, K1 */
 { 1, PI1, K1 }, /* LIMP, PI1, K0 */
 { 1, LIMP, PI1 }, /* LIMP, PI1, PI1 */
 { 1, PI1, K1 }, /* LIMP, PI1, PI2 */
 { 1, OR, PI1 }, /* LIMP, PI1, NOR */
 { 1, PI1, K1 }, /* LIMP, PI1, NLIMP */
 { 1, OR, PI1 }, /* LIMP, PI1, NPI1 */
 { 1, LIMP, PI1 }, /* LIMP, PI1, NIMP */
 { 0, PI1, K0 }, /* LIMP, PI1, NPI2 */
 { 1, LIMP, PI1 }, /* LIMP, PI1, XOR */
 { 0, PI1, K0 }, /* LIMP, PI1, NAND */
 { 1, PI1, K1 }, /* LIMP, PI1, AND */
 { 1, OR, PI1 }, /* LIMP, PI1, BIIMP */
 { 1, OR, PI1 }, /* LIMP, PI1, IMP */
 { 0, PI1, K0 }, /* LIMP, PI1, LIMP */
 { 1, LIMP, PI1 }, /* LIMP, PI1, OR */
 { 0, PI1, K0 }, /* LIMP, PI1, K1 */
 { 1, PI1, K1 }, /* LIMP, PI2, K0 */
 { 0, PI2, LIMP }, /* LIMP, PI2, PI1 */
 { 1, PI1, IMP }, /* LIMP, PI2, PI2 */
 { 1, IMP, NOR }, /* LIMP, PI2, NOR */
 { 0, NAND, NOR }, /* LIMP, PI2, NLIMP */
 { 0, PI2, OR }, /* LIMP, PI2, NPI1 */
 { 1, NAND, NOR }, /* LIMP, PI2, NIMP */
 { 1, PI1, OR }, /* LIMP, PI2, NPI2 */
 { 0, NOP, NOP }, /* LIMP, PI2, XOR */
 { 0, NOP, NOP }, /* LIMP, PI2, NAND */
 { 0, NAND, NLIMP }, /* LIMP, PI2, AND */
 { 0, NOP, NOP }, /* LIMP, PI2, BIIMP */
 { 0, NOP, NOP }, /* LIMP, PI2, IMP */
 { 0, NOP, NOP }, /* LIMP, PI2, LIMP */
 { 0, NOP, NOP }, /* LIMP, PI2, OR */
 { 1, PI1, PI2 }, /* LIMP, PI2, K1 */
 { 1, PI1, K1 }, /* LIMP, NOR, K0 */
 { 1, NAND, OR }, /* LIMP, NOR, PI1 */
 { 0, NOR, K0 }, /* LIMP, NOR, PI2 */
 { 1, IMP, NLIMP }, /* LIMP, NOR, NOR */
 { 1, IMP, PI1 }, /* LIMP, NOR, NLIMP */
 { 1, IMP, OR }, /* LIMP, NOR, NPI1 */
 { 1, NAND, NLIMP }, /* LIMP, NOR, NIMP */
 { 1, PI1, LIMP }, /* LIMP, NOR, NPI2 */
 { 0, NOP, NOP }, /* LIMP, NOR, XOR */
 { 0, NOP, BIIMP }, /* LIMP, NOR, NAND */
 { 1, NAND, PI1 }, /* LIMP, NOR, AND */
 { 0, NOP, NOP }, /* LIMP, NOR, BIIMP */
 { 0, NOR, NIMP }, /* LIMP, NOR, IMP */
 { 0, NOP, BIIMP }, /* LIMP, NOR, LIMP */
 { 0, NOR, AND }, /* LIMP, NOR, OR */
 { 1, PI1, NOR }, /* LIMP, NOR, K1 */
 { 1, PI1, K1 }, /* LIMP, NLIMP, K0 */
 { 1, NAND, LIMP }, /* LIMP, NLIMP, PI1 */
 { 0, NOR, K0 }, /* LIMP, NLIMP, PI2 */
 { 1, IMP, NOR }, /* LIMP, NLIMP, NOR */
 { 1, IMP, PI1 }, /* LIMP, NLIMP, NLIMP */
 { 1, IMP, LIMP }, /* LIMP, NLIMP, NPI1 */
 { 1, NAND, NOR }, /* LIMP, NLIMP, NIMP */
 { 1, PI1, OR }, /* LIMP, NLIMP, NPI2 */
 { 0, NOP, NOP }, /* LIMP, NLIMP, XOR */
 { 0, NOP, BIIMP }, /* LIMP, NLIMP, NAND */
 { 1, NAND, PI1 }, /* LIMP, NLIMP, AND */
 { 0, NOP, NOP }, /* LIMP, NLIMP, BIIMP */
 { 0, NOR, NOR }, /* LIMP, NLIMP, IMP */
 { 0, NOP, BIIMP }, /* LIMP, NLIMP, LIMP */
 { 0, NOR, NLIMP }, /* LIMP, NLIMP, OR */
 { 1, PI1, NLIMP }, /* LIMP, NLIMP, K1 */
 { 1, PI1, K1 }, /* LIMP, NPI1, K0 */
 { 1, NAND, PI1 }, /* LIMP, NPI1, PI1 */
 { 0, NOR, K0 }, /* LIMP, NPI1, PI2 */
 { 1, PI1, K1 }, /* LIMP, NPI1, NOR */
 { 1, IMP, PI1 }, /* LIMP, NPI1, NLIMP */
 { 1, IMP, PI1 }, /* LIMP, NPI1, NPI1 */
 { 1, PI1, K1 }, /* LIMP, NPI1, NIMP */
 { 1, PI1, K1 }, /* LIMP, NPI1, NPI2 */
 { 1, IMP, PI1 }, /* LIMP, NPI1, XOR */
 { 1, IMP, PI1 }, /* LIMP, NPI1, NAND */
 { 1, NAND, PI1 }, /* LIMP, NPI1, AND */
 { 1, NAND, PI1 }, /* LIMP, NPI1, BIIMP */
 { 0, NOR, K0 }, /* LIMP, NPI1, IMP */
 { 1, NAND, PI1 }, /* LIMP, NPI1, LIMP */
 { 0, NOR, K0 }, /* LIMP, NPI1, OR */
 { 0, NOR, K0 }, /* LIMP, NPI1, K1 */
 { 1, PI1, K1 }, /* LIMP, NIMP, K0 */
 { 1, NAND, IMP }, /* LIMP, NIMP, PI1 */
 { 1, PI1, NAND }, /* LIMP, NIMP, PI2 */
 { 1, OR, PI1 }, /* LIMP, NIMP, NOR */
 { 0, NAND, NIMP }, /* LIMP, NIMP, NLIMP */
 { 1, IMP, IMP }, /* LIMP, NIMP, NPI1 */
 { 1, LIMP, PI1 }, /* LIMP, NIMP, NIMP */
 { 0, PI1, K0 }, /* LIMP, NIMP, NPI2 */
 { 0, NOP, NOP }, /* LIMP, NIMP, XOR */
 { 0, NIMP, NIMP }, /* LIMP, NIMP, NAND */
 { 1, NAND, AND }, /* LIMP, NIMP, AND */
 { 0, NOP, NOP }, /* LIMP, NIMP, BIIMP */
 { 0, NOP, BIIMP }, /* LIMP, NIMP, IMP */
 { 0, NIMP, AND }, /* LIMP, NIMP, LIMP */
 { 0, NOP, BIIMP }, /* LIMP, NIMP, OR */
 { 1, PI1, NIMP }, /* LIMP, NIMP, K1 */
 { 1, PI1, K1 }, /* LIMP, NPI2, K0 */
 { 0, PI2, NAND }, /* LIMP, NPI2, PI1 */
 { 1, PI1, NAND }, /* LIMP, NPI2, PI2 */
 { 1, IMP, NLIMP }, /* LIMP, NPI2, NOR */
 { 0, NAND, NIMP }, /* LIMP, NPI2, NLIMP */
 { 0, PI2, IMP }, /* LIMP, NPI2, NPI1 */
 { 1, NAND, NLIMP }, /* LIMP, NPI2, NIMP */
 { 1, PI1, LIMP }, /* LIMP, NPI2, NPI2 */
 { 0, NOP, NOP }, /* LIMP, NPI2, XOR */
 { 0, NOP, NOP }, /* LIMP, NPI2, NAND */
 { 1, NAND, AND }, /* LIMP, NPI2, AND */
 { 0, NOP, NOP }, /* LIMP, NPI2, BIIMP */
 { 0, NOP, NOP }, /* LIMP, NPI2, IMP */
 { 0, NOP, NOP }, /* LIMP, NPI2, LIMP */
 { 0, NOP, NOP }, /* LIMP, NPI2, OR */
 { 1, NPI1, PI2 }, /* LIMP, NPI2, K1 */
 { 1, PI1, K1 }, /* LIMP, XOR, K0 */
 { 1, NAND, BIIMP }, /* LIMP, XOR, PI1 */
 { 1, PI1, NAND }, /* LIMP, XOR, PI2 */
 { 1, IMP, NOR }, /* LIMP, XOR, NOR */
 { 0, NAND, NIMP }, /* LIMP, XOR, NLIMP */
 { 1, IMP, BIIMP }, /* LIMP, XOR, NPI1 */
 { 1, NAND, NOR }, /* LIMP, XOR, NIMP */
 { 1, PI1, OR }, /* LIMP, XOR, NPI2 */
 { 0, NOP, NOP }, /* LIMP, XOR, XOR */
 { 0, NOP, NOP }, /* LIMP, XOR, NAND */
 { 1, NAND, AND }, /* LIMP, XOR, AND */
 { 0, NOP, NOP }, /* LIMP, XOR, BIIMP */
 { 0, NOP, NOP }, /* LIMP, XOR, IMP */
 { 0, NOP, NOP }, /* LIMP, XOR, LIMP */
 { 0, NOP, NOP }, /* LIMP, XOR, OR */
 { 1, PI1, XOR }, /* LIMP, XOR, K1 */
 { 1, PI1, K1 }, /* LIMP, NAND, K0 */
 { 1, NAND, AND }, /* LIMP, NAND, PI1 */
 { 1, PI1, NAND }, /* LIMP, NAND, PI2 */
 { 1, PI1, K1 }, /* LIMP, NAND, NOR */
 { 0, NAND, NIMP }, /* LIMP, NAND, NLIMP */
 { 0, NAND, NIMP }, /* LIMP, NAND, NPI1 */
 { 1, PI1, K1 }, /* LIMP, NAND, NIMP */
 { 1, PI1, K1 }, /* LIMP, NAND, NPI2 */
 { 0, NAND, NIMP }, /* LIMP, NAND, XOR */
 { 0, NAND, NIMP }, /* LIMP, NAND, NAND */
 { 1, NAND, AND }, /* LIMP, NAND, AND */
 { 1, NAND, AND }, /* LIMP, NAND, BIIMP */
 { 1, PI1, NAND }, /* LIMP, NAND, IMP */
 { 1, NAND, AND }, /* LIMP, NAND, LIMP */
 { 1, PI1, NAND }, /* LIMP, NAND, OR */
 { 1, PI1, NAND }, /* LIMP, NAND, K1 */
 { 1, PI1, K1 }, /* LIMP, AND, K0 */
 { 1, NAND, NAND }, /* LIMP, AND, PI1 */
 { 1, PI1, IMP }, /* LIMP, AND, PI2 */
 { 1, OR, PI1 }, /* LIMP, AND, NOR */
 { 0, NAND, NOR }, /* LIMP, AND, NLIMP */
 { 1, IMP, NAND }, /* LIMP, AND, NPI1 */
 { 1, LIMP, PI1 }, /* LIMP, AND, NIMP */
 { 0, PI1, K0 }, /* LIMP, AND, NPI2 */
 { 0, NOP, NOP }, /* LIMP, AND, XOR */
 { 0, NIMP, NOR }, /* LIMP, AND, NAND */
 { 0, NAND, NLIMP }, /* LIMP, AND, AND */
 { 0, NOP, NOP }, /* LIMP, AND, BIIMP */
 { 0, NOP, BIIMP }, /* LIMP, AND, IMP */
 { 0, NIMP, NLIMP }, /* LIMP, AND, LIMP */
 { 0, NOP, BIIMP }, /* LIMP, AND, OR */
 { 1, PI1, AND }, /* LIMP, AND, K1 */
 { 1, PI1, K1 }, /* LIMP, BIIMP, K0 */
 { 1, NAND, XOR }, /* LIMP, BIIMP, PI1 */
 { 1, PI1, IMP }, /* LIMP, BIIMP, PI2 */
 { 1, IMP, NLIMP }, /* LIMP, BIIMP, NOR */
 { 0, NAND, NOR }, /* LIMP, BIIMP, NLIMP */
 { 1, IMP, XOR }, /* LIMP, BIIMP, NPI1 */
 { 1, NAND, NLIMP }, /* LIMP, BIIMP, NIMP */
 { 1, PI1, LIMP }, /* LIMP, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* LIMP, BIIMP, XOR */
 { 0, NOP, NOP }, /* LIMP, BIIMP, NAND */
 { 0, NAND, NLIMP }, /* LIMP, BIIMP, AND */
 { 0, NOP, NOP }, /* LIMP, BIIMP, BIIMP */
 { 0, NOP, NOP }, /* LIMP, BIIMP, IMP */
 { 0, NOP, NOP }, /* LIMP, BIIMP, LIMP */
 { 0, NOP, NOP }, /* LIMP, BIIMP, OR */
 { 1, PI1, BIIMP }, /* LIMP, BIIMP, K1 */
 { 1, PI1, K1 }, /* LIMP, IMP, K0 */
 { 0, NAND, NLIMP }, /* LIMP, IMP, PI1 */
 { 1, PI1, IMP }, /* LIMP, IMP, PI2 */
 { 1, PI1, K1 }, /* LIMP, IMP, NOR */
 { 0, NAND, NOR }, /* LIMP, IMP, NLIMP */
 { 0, NAND, NOR }, /* LIMP, IMP, NPI1 */
 { 1, PI1, K1 }, /* LIMP, IMP, NIMP */
 { 1, PI1, K1 }, /* LIMP, IMP, NPI2 */
 { 0, NAND, NOR }, /* LIMP, IMP, XOR */
 { 0, NAND, NOR }, /* LIMP, IMP, NAND */
 { 0, NAND, NLIMP }, /* LIMP, IMP, AND */
 { 0, NAND, NLIMP }, /* LIMP, IMP, BIIMP */
 { 1, PI1, IMP }, /* LIMP, IMP, IMP */
 { 0, NAND, NLIMP }, /* LIMP, IMP, LIMP */
 { 1, PI1, IMP }, /* LIMP, IMP, OR */
 { 1, PI1, IMP }, /* LIMP, IMP, K1 */
 { 1, PI1, K1 }, /* LIMP, LIMP, K0 */
 { 1, NAND, NLIMP }, /* LIMP, LIMP, PI1 */
 { 1, PI1, K1 }, /* LIMP, LIMP, PI2 */
 { 1, IMP, NLIMP }, /* LIMP, LIMP, NOR */
 { 1, PI1, K1 }, /* LIMP, LIMP, NLIMP */
 { 1, IMP, NLIMP }, /* LIMP, LIMP, NPI1 */
 { 1, NAND, NLIMP }, /* LIMP, LIMP, NIMP */
 { 1, PI1, LIMP }, /* LIMP, LIMP, NPI2 */
 { 1, NAND, NLIMP }, /* LIMP, LIMP, XOR */
 { 1, PI1, LIMP }, /* LIMP, LIMP, NAND */
 { 1, PI1, K1 }, /* LIMP, LIMP, AND */
 { 1, IMP, NLIMP }, /* LIMP, LIMP, BIIMP */
 { 1, IMP, NLIMP }, /* LIMP, LIMP, IMP */
 { 1, PI1, LIMP }, /* LIMP, LIMP, LIMP */
 { 1, NAND, NLIMP }, /* LIMP, LIMP, OR */
 { 1, PI1, LIMP }, /* LIMP, LIMP, K1 */
 { 1, PI1, K1 }, /* LIMP, OR, K0 */
 { 1, NAND, NOR }, /* LIMP, OR, PI1 */
 { 1, PI1, K1 }, /* LIMP, OR, PI2 */
 { 1, IMP, NOR }, /* LIMP, OR, NOR */
 { 1, PI1, K1 }, /* LIMP, OR, NLIMP */
 { 1, IMP, NOR }, /* LIMP, OR, NPI1 */
 { 1, NAND, NOR }, /* LIMP, OR, NIMP */
 { 1, PI1, OR }, /* LIMP, OR, NPI2 */
 { 1, NAND, NOR }, /* LIMP, OR, XOR */
 { 1, PI1, OR }, /* LIMP, OR, NAND */
 { 1, PI1, K1 }, /* LIMP, OR, AND */
 { 1, IMP, NOR }, /* LIMP, OR, BIIMP */
 { 1, IMP, NOR }, /* LIMP, OR, IMP */
 { 1, PI1, OR }, /* LIMP, OR, LIMP */
 { 1, NAND, NOR }, /* LIMP, OR, OR */
 { 1, PI1, OR }, /* LIMP, OR, K1 */
 { 1, PI1, K1 }, /* LIMP, K1, K0 */
 { 1, PI1, K1 }, /* LIMP, K1, PI1 */
 { 1, PI1, K1 }, /* LIMP, K1, PI2 */
 { 1, PI1, K1 }, /* LIMP, K1, NOR */
 { 1, PI1, K1 }, /* LIMP, K1, NLIMP */
 { 1, PI1, K1 }, /* LIMP, K1, NPI1 */
 { 1, PI1, K1 }, /* LIMP, K1, NIMP */
 { 1, PI1, K1 }, /* LIMP, K1, NPI2 */
 { 1, PI1, K1 }, /* LIMP, K1, XOR */
 { 1, PI1, K1 }, /* LIMP, K1, NAND */
 { 1, PI1, K1 }, /* LIMP, K1, AND */
 { 1, PI1, K1 }, /* LIMP, K1, BIIMP */
 { 1, PI1, K1 }, /* LIMP, K1, IMP */
 { 1, PI1, K1 }, /* LIMP, K1, LIMP */
 { 1, PI1, K1 }, /* LIMP, K1, OR */
 { 1, PI1, K1 }, /* LIMP, K1, K1 */
 { 1, K0, K0 }, /* OR, K0, K0 */
 { 1, PI2, K0 }, /* OR, K0, PI1 */
 { 0, PI1, K0 }, /* OR, K0, PI2 */
 { 1, NOR, PI1 }, /* OR, K0, NOR */
 { 1, NIMP, PI1 }, /* OR, K0, NLIMP */
 { 1, NOR, K0 }, /* OR, K0, NPI1 */
 { 1, NLIMP, PI1 }, /* OR, K0, NIMP */
 { 0, NOR, K0 }, /* OR, K0, NPI2 */
 { 1, XOR, PI1 }, /* OR, K0, XOR */
 { 1, NAND, PI1 }, /* OR, K0, NAND */
 { 1, AND, PI1 }, /* OR, K0, AND */
 { 1, BIIMP, PI1 }, /* OR, K0, BIIMP */
 { 1, LIMP, PI1 }, /* OR, K0, IMP */
 { 1, IMP, PI1 }, /* OR, K0, LIMP */
 { 1, OR, PI1 }, /* OR, K0, OR */
 { 1, PI1, K1 }, /* OR, K0, K1 */
 { 0, PI1, K0 }, /* OR, PI1, K0 */
 { 1, OR, PI1 }, /* OR, PI1, PI1 */
 { 0, PI1, K0 }, /* OR, PI1, PI2 */
 { 1, LIMP, PI1 }, /* OR, PI1, NOR */
 { 0, PI1, K0 }, /* OR, PI1, NLIMP */
 { 1, LIMP, PI1 }, /* OR, PI1, NPI1 */
 { 1, OR, PI1 }, /* OR, PI1, NIMP */
 { 1, PI1, K1 }, /* OR, PI1, NPI2 */
 { 1, OR, PI1 }, /* OR, PI1, XOR */
 { 1, PI1, K1 }, /* OR, PI1, NAND */
 { 0, PI1, K0 }, /* OR, PI1, AND */
 { 1, LIMP, PI1 }, /* OR, PI1, BIIMP */
 { 1, LIMP, PI1 }, /* OR, PI1, IMP */
 { 1, PI1, K1 }, /* OR, PI1, LIMP */
 { 1, OR, PI1 }, /* OR, PI1, OR */
 { 1, PI1, K1 }, /* OR, PI1, K1 */
 { 1, PI1, PI2 }, /* OR, PI2, K0 */
 { 0, PI2, OR }, /* OR, PI2, PI1 */
 { 1, PI1, OR }, /* OR, PI2, PI2 */
 { 0, NOP, NOP }, /* OR, PI2, NOR */
 { 0, NOP, NOP }, /* OR, PI2, NLIMP */
 { 0, PI2, LIMP }, /* OR, PI2, NPI1 */
 { 0, NOP, NOP }, /* OR, PI2, NIMP */
 { 1, PI1, IMP }, /* OR, PI2, NPI2 */
 { 0, NOP, NOP }, /* OR, PI2, XOR */
 { 0, NAND, NLIMP }, /* OR, PI2, NAND */
 { 0, NOP, NOP }, /* OR, PI2, AND */
 { 0, NOP, NOP }, /* OR, PI2, BIIMP */
 { 1, NAND, NOR }, /* OR, PI2, IMP */
 { 0, NAND, NOR }, /* OR, PI2, LIMP */
 { 1, IMP, NOR }, /* OR, PI2, OR */
 { 1, PI1, K1 }, /* OR, PI2, K1 */
 { 1, PI1, NOR }, /* OR, NOR, K0 */
 { 1, IMP, OR }, /* OR, NOR, PI1 */
 { 1, PI1, LIMP }, /* OR, NOR, PI2 */
 { 0, NOR, AND }, /* OR, NOR, NOR */
 { 0, NOP, XOR }, /* OR, NOR, NLIMP */
 { 1, NAND, OR }, /* OR, NOR, NPI1 */
 { 0, NOR, NIMP }, /* OR, NOR, NIMP */
 { 0, NOR, K0 }, /* OR, NOR, NPI2 */
 { 0, NOP, NOP }, /* OR, NOR, XOR */
 { 1, NAND, PI1 }, /* OR, NOR, NAND */
 { 0, NOP, XOR }, /* OR, NOR, AND */
 { 0, NOP, NOP }, /* OR, NOR, BIIMP */
 { 1, NAND, NLIMP }, /* OR, NOR, IMP */
 { 1, IMP, PI1 }, /* OR, NOR, LIMP */
 { 1, IMP, NLIMP }, /* OR, NOR, OR */
 { 1, PI1, K1 }, /* OR, NOR, K1 */
 { 1, PI1, NLIMP }, /* OR, NLIMP, K0 */
 { 1, IMP, LIMP }, /* OR, NLIMP, PI1 */
 { 1, PI1, OR }, /* OR, NLIMP, PI2 */
 { 0, NOR, NLIMP }, /* OR, NLIMP, NOR */
 { 0, NOP, XOR }, /* OR, NLIMP, NLIMP */
 { 1, NAND, LIMP }, /* OR, NLIMP, NPI1 */
 { 0, NOR, NOR }, /* OR, NLIMP, NIMP */
 { 0, NOR, K0 }, /* OR, NLIMP, NPI2 */
 { 0, NOP, NOP }, /* OR, NLIMP, XOR */
 { 1, NAND, PI1 }, /* OR, NLIMP, NAND */
 { 0, NOP, XOR }, /* OR, NLIMP, AND */
 { 0, NOP, NOP }, /* OR, NLIMP, BIIMP */
 { 1, NAND, NOR }, /* OR, NLIMP, IMP */
 { 1, IMP, PI1 }, /* OR, NLIMP, LIMP */
 { 1, IMP, NOR }, /* OR, NLIMP, OR */
 { 1, PI1, K1 }, /* OR, NLIMP, K1 */
 { 0, NOR, K0 }, /* OR, NPI1, K0 */
 { 1, IMP, PI1 }, /* OR, NPI1, PI1 */
 { 1, PI1, K1 }, /* OR, NPI1, PI2 */
 { 0, NOR, K0 }, /* OR, NPI1, NOR */
 { 1, NAND, PI1 }, /* OR, NPI1, NLIMP */
 { 1, NAND, PI1 }, /* OR, NPI1, NPI1 */
 { 0, NOR, K0 }, /* OR, NPI1, NIMP */
 { 0, NOR, K0 }, /* OR, NPI1, NPI2 */
 { 1, NAND, PI1 }, /* OR, NPI1, XOR */
 { 1, NAND, PI1 }, /* OR, NPI1, NAND */
 { 1, IMP, PI1 }, /* OR, NPI1, AND */
 { 1, IMP, PI1 }, /* OR, NPI1, BIIMP */
 { 1, PI1, K1 }, /* OR, NPI1, IMP */
 { 1, IMP, PI1 }, /* OR, NPI1, LIMP */
 { 1, PI1, K1 }, /* OR, NPI1, OR */
 { 1, PI1, K1 }, /* OR, NPI1, K1 */
 { 1, PI1, NIMP }, /* OR, NIMP, K0 */
 { 1, IMP, IMP }, /* OR, NIMP, PI1 */
 { 0, PI1, K0 }, /* OR, NIMP, PI2 */
 { 0, NOP, XOR }, /* OR, NIMP, NOR */
 { 0, NIMP, AND }, /* OR, NIMP, NLIMP */
 { 1, NAND, IMP }, /* OR, NIMP, NPI1 */
 { 0, NOP, XOR }, /* OR, NIMP, NIMP */
 { 1, PI1, NAND }, /* OR, NIMP, NPI2 */
 { 0, NOP, NOP }, /* OR, NIMP, XOR */
 { 1, NAND, AND }, /* OR, NIMP, NAND */
 { 0, NIMP, NIMP }, /* OR, NIMP, AND */
 { 0, NOP, NOP }, /* OR, NIMP, BIIMP */
 { 1, LIMP, PI1 }, /* OR, NIMP, IMP */
 { 0, NAND, NIMP }, /* OR, NIMP, LIMP */
 { 1, OR, PI1 }, /* OR, NIMP, OR */
 { 1, PI1, K1 }, /* OR, NIMP, K1 */
 { 1, NPI1, PI2 }, /* OR, NPI2, K0 */
 { 0, PI2, IMP }, /* OR, NPI2, PI1 */
 { 1, PI1, LIMP }, /* OR, NPI2, PI2 */
 { 0, NOP, NOP }, /* OR, NPI2, NOR */
 { 0, NOP, NOP }, /* OR, NPI2, NLIMP */
 { 0, PI2, NAND }, /* OR, NPI2, NPI1 */
 { 0, NOP, NOP }, /* OR, NPI2, NIMP */
 { 1, PI1, NAND }, /* OR, NPI2, NPI2 */
 { 0, NOP, NOP }, /* OR, NPI2, XOR */
 { 1, NAND, AND }, /* OR, NPI2, NAND */
 { 0, NOP, NOP }, /* OR, NPI2, AND */
 { 0, NOP, NOP }, /* OR, NPI2, BIIMP */
 { 1, NAND, NLIMP }, /* OR, NPI2, IMP */
 { 0, NAND, NIMP }, /* OR, NPI2, LIMP */
 { 1, IMP, NLIMP }, /* OR, NPI2, OR */
 { 1, PI1, K1 }, /* OR, NPI2, K1 */
 { 1, PI1, XOR }, /* OR, XOR, K0 */
 { 1, IMP, BIIMP }, /* OR, XOR, PI1 */
 { 1, PI1, OR }, /* OR, XOR, PI2 */
 { 0, NOP, NOP }, /* OR, XOR, NOR */
 { 0, NOP, NOP }, /* OR, XOR, NLIMP */
 { 1, NAND, BIIMP }, /* OR, XOR, NPI1 */
 { 0, NOP, NOP }, /* OR, XOR, NIMP */
 { 1, PI1, NAND }, /* OR, XOR, NPI2 */
 { 0, NOP, NOP }, /* OR, XOR, XOR */
 { 1, NAND, AND }, /* OR, XOR, NAND */
 { 0, NOP, NOP }, /* OR, XOR, AND */
 { 0, NOP, NOP }, /* OR, XOR, BIIMP */
 { 1, NAND, NOR }, /* OR, XOR, IMP */
 { 0, NAND, NIMP }, /* OR, XOR, LIMP */
 { 1, IMP, NOR }, /* OR, XOR, OR */
 { 1, PI1, K1 }, /* OR, XOR, K1 */
 { 1, PI1, NAND }, /* OR, NAND, K0 */
 { 0, NAND, NIMP }, /* OR, NAND, PI1 */
 { 1, PI1, K1 }, /* OR, NAND, PI2 */
 { 1, PI1, NAND }, /* OR, NAND, NOR */
 { 1, NAND, AND }, /* OR, NAND, NLIMP */
 { 1, NAND, AND }, /* OR, NAND, NPI1 */
 { 1, PI1, NAND }, /* OR, NAND, NIMP */
 { 1, PI1, NAND }, /* OR, NAND, NPI2 */
 { 1, NAND, AND }, /* OR, NAND, XOR */
 { 1, NAND, AND }, /* OR, NAND, NAND */
 { 0, NAND, NIMP }, /* OR, NAND, AND */
 { 0, NAND, NIMP }, /* OR, NAND, BIIMP */
 { 1, PI1, K1 }, /* OR, NAND, IMP */
 { 0, NAND, NIMP }, /* OR, NAND, LIMP */
 { 1, PI1, K1 }, /* OR, NAND, OR */
 { 1, PI1, K1 }, /* OR, NAND, K1 */
 { 1, PI1, AND }, /* OR, AND, K0 */
 { 1, IMP, NAND }, /* OR, AND, PI1 */
 { 0, PI1, K0 }, /* OR, AND, PI2 */
 { 0, NOP, XOR }, /* OR, AND, NOR */
 { 0, NIMP, NLIMP }, /* OR, AND, NLIMP */
 { 1, NAND, NAND }, /* OR, AND, NPI1 */
 { 0, NOP, XOR }, /* OR, AND, NIMP */
 { 1, PI1, IMP }, /* OR, AND, NPI2 */
 { 0, NOP, NOP }, /* OR, AND, XOR */
 { 0, NAND, NLIMP }, /* OR, AND, NAND */
 { 0, NIMP, NOR }, /* OR, AND, AND */
 { 0, NOP, NOP }, /* OR, AND, BIIMP */
 { 1, LIMP, PI1 }, /* OR, AND, IMP */
 { 0, NAND, NOR }, /* OR, AND, LIMP */
 { 1, OR, PI1 }, /* OR, AND, OR */
 { 1, PI1, K1 }, /* OR, AND, K1 */
 { 1, PI1, BIIMP }, /* OR, BIIMP, K0 */
 { 1, IMP, XOR }, /* OR, BIIMP, PI1 */
 { 1, PI1, LIMP }, /* OR, BIIMP, PI2 */
 { 0, NOP, NOP }, /* OR, BIIMP, NOR */
 { 0, NOP, NOP }, /* OR, BIIMP, NLIMP */
 { 1, NAND, XOR }, /* OR, BIIMP, NPI1 */
 { 0, NOP, NOP }, /* OR, BIIMP, NIMP */
 { 1, PI1, IMP }, /* OR, BIIMP, NPI2 */
 { 0, NOP, NOP }, /* OR, BIIMP, XOR */
 { 0, NAND, NLIMP }, /* OR, BIIMP, NAND */
 { 0, NOP, NOP }, /* OR, BIIMP, AND */
 { 0, NOP, NOP }, /* OR, BIIMP, BIIMP */
 { 1, NAND, NLIMP }, /* OR, BIIMP, IMP */
 { 0, NAND, NOR }, /* OR, BIIMP, LIMP */
 { 1, IMP, NLIMP }, /* OR, BIIMP, OR */
 { 1, PI1, K1 }, /* OR, BIIMP, K1 */
 { 1, PI1, IMP }, /* OR, IMP, K0 */
 { 0, NAND, NOR }, /* OR, IMP, PI1 */
 { 1, PI1, K1 }, /* OR, IMP, PI2 */
 { 1, PI1, IMP }, /* OR, IMP, NOR */
 { 0, NAND, NLIMP }, /* OR, IMP, NLIMP */
 { 0, NAND, NLIMP }, /* OR, IMP, NPI1 */
 { 1, PI1, IMP }, /* OR, IMP, NIMP */
 { 1, PI1, IMP }, /* OR, IMP, NPI2 */
 { 0, NAND, NLIMP }, /* OR, IMP, XOR */
 { 0, NAND, NLIMP }, /* OR, IMP, NAND */
 { 0, NAND, NOR }, /* OR, IMP, AND */
 { 0, NAND, NOR }, /* OR, IMP, BIIMP */
 { 1, PI1, K1 }, /* OR, IMP, IMP */
 { 0, NAND, NOR }, /* OR, IMP, LIMP */
 { 1, PI1, K1 }, /* OR, IMP, OR */
 { 1, PI1, K1 }, /* OR, IMP, K1 */
 { 1, PI1, LIMP }, /* OR, LIMP, K0 */
 { 1, IMP, NLIMP }, /* OR, LIMP, PI1 */
 { 1, PI1, LIMP }, /* OR, LIMP, PI2 */
 { 1, NAND, NLIMP }, /* OR, LIMP, NOR */
 { 1, PI1, LIMP }, /* OR, LIMP, NLIMP */
 { 1, NAND, NLIMP }, /* OR, LIMP, NPI1 */
 { 1, IMP, NLIMP }, /* OR, LIMP, NIMP */
 { 1, PI1, K1 }, /* OR, LIMP, NPI2 */
 { 1, IMP, NLIMP }, /* OR, LIMP, XOR */
 { 1, PI1, K1 }, /* OR, LIMP, NAND */
 { 1, PI1, LIMP }, /* OR, LIMP, AND */
 { 1, NAND, NLIMP }, /* OR, LIMP, BIIMP */
 { 1, NAND, NLIMP }, /* OR, LIMP, IMP */
 { 1, PI1, K1 }, /* OR, LIMP, LIMP */
 { 1, IMP, NLIMP }, /* OR, LIMP, OR */
 { 1, PI1, K1 }, /* OR, LIMP, K1 */
 { 1, PI1, OR }, /* OR, OR, K0 */
 { 1, IMP, NOR }, /* OR, OR, PI1 */
 { 1, PI1, OR }, /* OR, OR, PI2 */
 { 1, NAND, NOR }, /* OR, OR, NOR */
 { 1, PI1, OR }, /* OR, OR, NLIMP */
 { 1, NAND, NOR }, /* OR, OR, NPI1 */
 { 1, IMP, NOR }, /* OR, OR, NIMP */
 { 1, PI1, K1 }, /* OR, OR, NPI2 */
 { 1, IMP, NOR }, /* OR, OR, XOR */
 { 1, PI1, K1 }, /* OR, OR, NAND */
 { 1, PI1, OR }, /* OR, OR, AND */
 { 1, NAND, NOR }, /* OR, OR, BIIMP */
 { 1, NAND, NOR }, /* OR, OR, IMP */
 { 1, PI1, K1 }, /* OR, OR, LIMP */
 { 1, IMP, NOR }, /* OR, OR, OR */
 { 1, PI1, K1 }, /* OR, OR, K1 */
 { 1, PI1, K1 }, /* OR, K1, K0 */
 { 1, PI1, K1 }, /* OR, K1, PI1 */
 { 1, PI1, K1 }, /* OR, K1, PI2 */
 { 1, PI1, K1 }, /* OR, K1, NOR */
 { 1, PI1, K1 }, /* OR, K1, NLIMP */
 { 1, PI1, K1 }, /* OR, K1, NPI1 */
 { 1, PI1, K1 }, /* OR, K1, NIMP */
 { 1, PI1, K1 }, /* OR, K1, NPI2 */
 { 1, PI1, K1 }, /* OR, K1, XOR */
 { 1, PI1, K1 }, /* OR, K1, NAND */
 { 1, PI1, K1 }, /* OR, K1, AND */
 { 1, PI1, K1 }, /* OR, K1, BIIMP */
 { 1, PI1, K1 }, /* OR, K1, IMP */
 { 1, PI1, K1 }, /* OR, K1, LIMP */
 { 1, PI1, K1 }, /* OR, K1, OR */
 { 1, PI1, K1 }, /* OR, K1, K1 */
 { 1, PI1, K1 }, /* K1, K0, K0 */
 { 1, PI1, K1 }, /* K1, K0, PI1 */
 { 1, PI1, K1 }, /* K1, K0, PI2 */
 { 1, PI1, K1 }, /* K1, K0, NOR */
 { 1, PI1, K1 }, /* K1, K0, NLIMP */
 { 1, PI1, K1 }, /* K1, K0, NPI1 */
 { 1, PI1, K1 }, /* K1, K0, NIMP */
 { 1, PI1, K1 }, /* K1, K0, NPI2 */
 { 1, PI1, K1 }, /* K1, K0, XOR */
 { 1, PI1, K1 }, /* K1, K0, NAND */
 { 1, PI1, K1 }, /* K1, K0, AND */
 { 1, PI1, K1 }, /* K1, K0, BIIMP */
 { 1, PI1, K1 }, /* K1, K0, IMP */
 { 1, PI1, K1 }, /* K1, K0, LIMP */
 { 1, PI1, K1 }, /* K1, K0, OR */
 { 1, PI1, K1 }, /* K1, K0, K1 */
 { 1, PI1, K1 }, /* K1, PI1, K0 */
 { 1, PI1, K1 }, /* K1, PI1, PI1 */
 { 1, PI1, K1 }, /* K1, PI1, PI2 */
 { 1, PI1, K1 }, /* K1, PI1, NOR */
 { 1, PI1, K1 }, /* K1, PI1, NLIMP */
 { 1, PI1, K1 }, /* K1, PI1, NPI1 */
 { 1, PI1, K1 }, /* K1, PI1, NIMP */
 { 1, PI1, K1 }, /* K1, PI1, NPI2 */
 { 1, PI1, K1 }, /* K1, PI1, XOR */
 { 1, PI1, K1 }, /* K1, PI1, NAND */
 { 1, PI1, K1 }, /* K1, PI1, AND */
 { 1, PI1, K1 }, /* K1, PI1, BIIMP */
 { 1, PI1, K1 }, /* K1, PI1, IMP */
 { 1, PI1, K1 }, /* K1, PI1, LIMP */
 { 1, PI1, K1 }, /* K1, PI1, OR */
 { 1, PI1, K1 }, /* K1, PI1, K1 */
 { 1, PI1, K1 }, /* K1, PI2, K0 */
 { 1, PI1, K1 }, /* K1, PI2, PI1 */
 { 1, PI1, K1 }, /* K1, PI2, PI2 */
 { 1, PI1, K1 }, /* K1, PI2, NOR */
 { 1, PI1, K1 }, /* K1, PI2, NLIMP */
 { 1, PI1, K1 }, /* K1, PI2, NPI1 */
 { 1, PI1, K1 }, /* K1, PI2, NIMP */
 { 1, PI1, K1 }, /* K1, PI2, NPI2 */
 { 1, PI1, K1 }, /* K1, PI2, XOR */
 { 1, PI1, K1 }, /* K1, PI2, NAND */
 { 1, PI1, K1 }, /* K1, PI2, AND */
 { 1, PI1, K1 }, /* K1, PI2, BIIMP */
 { 1, PI1, K1 }, /* K1, PI2, IMP */
 { 1, PI1, K1 }, /* K1, PI2, LIMP */
 { 1, PI1, K1 }, /* K1, PI2, OR */
 { 1, PI1, K1 }, /* K1, PI2, K1 */
 { 1, PI1, K1 }, /* K1, NOR, K0 */
 { 1, PI1, K1 }, /* K1, NOR, PI1 */
 { 1, PI1, K1 }, /* K1, NOR, PI2 */
 { 1, PI1, K1 }, /* K1, NOR, NOR */
 { 1, PI1, K1 }, /* K1, NOR, NLIMP */
 { 1, PI1, K1 }, /* K1, NOR, NPI1 */
 { 1, PI1, K1 }, /* K1, NOR, NIMP */
 { 1, PI1, K1 }, /* K1, NOR, NPI2 */
 { 1, PI1, K1 }, /* K1, NOR, XOR */
 { 1, PI1, K1 }, /* K1, NOR, NAND */
 { 1, PI1, K1 }, /* K1, NOR, AND */
 { 1, PI1, K1 }, /* K1, NOR, BIIMP */
 { 1, PI1, K1 }, /* K1, NOR, IMP */
 { 1, PI1, K1 }, /* K1, NOR, LIMP */
 { 1, PI1, K1 }, /* K1, NOR, OR */
 { 1, PI1, K1 }, /* K1, NOR, K1 */
 { 1, PI1, K1 }, /* K1, NLIMP, K0 */
 { 1, PI1, K1 }, /* K1, NLIMP, PI1 */
 { 1, PI1, K1 }, /* K1, NLIMP, PI2 */
 { 1, PI1, K1 }, /* K1, NLIMP, NOR */
 { 1, PI1, K1 }, /* K1, NLIMP, NLIMP */
 { 1, PI1, K1 }, /* K1, NLIMP, NPI1 */
 { 1, PI1, K1 }, /* K1, NLIMP, NIMP */
 { 1, PI1, K1 }, /* K1, NLIMP, NPI2 */
 { 1, PI1, K1 }, /* K1, NLIMP, XOR */
 { 1, PI1, K1 }, /* K1, NLIMP, NAND */
 { 1, PI1, K1 }, /* K1, NLIMP, AND */
 { 1, PI1, K1 }, /* K1, NLIMP, BIIMP */
 { 1, PI1, K1 }, /* K1, NLIMP, IMP */
 { 1, PI1, K1 }, /* K1, NLIMP, LIMP */
 { 1, PI1, K1 }, /* K1, NLIMP, OR */
 { 1, PI1, K1 }, /* K1, NLIMP, K1 */
 { 1, PI1, K1 }, /* K1, NPI1, K0 */
 { 1, PI1, K1 }, /* K1, NPI1, PI1 */
 { 1, PI1, K1 }, /* K1, NPI1, PI2 */
 { 1, PI1, K1 }, /* K1, NPI1, NOR */
 { 1, PI1, K1 }, /* K1, NPI1, NLIMP */
 { 1, PI1, K1 }, /* K1, NPI1, NPI1 */
 { 1, PI1, K1 }, /* K1, NPI1, NIMP */
 { 1, PI1, K1 }, /* K1, NPI1, NPI2 */
 { 1, PI1, K1 }, /* K1, NPI1, XOR */
 { 1, PI1, K1 }, /* K1, NPI1, NAND */
 { 1, PI1, K1 }, /* K1, NPI1, AND */
 { 1, PI1, K1 }, /* K1, NPI1, BIIMP */
 { 1, PI1, K1 }, /* K1, NPI1, IMP */
 { 1, PI1, K1 }, /* K1, NPI1, LIMP */
 { 1, PI1, K1 }, /* K1, NPI1, OR */
 { 1, PI1, K1 }, /* K1, NPI1, K1 */
 { 1, PI1, K1 }, /* K1, NIMP, K0 */
 { 1, PI1, K1 }, /* K1, NIMP, PI1 */
 { 1, PI1, K1 }, /* K1, NIMP, PI2 */
 { 1, PI1, K1 }, /* K1, NIMP, NOR */
 { 1, PI1, K1 }, /* K1, NIMP, NLIMP */
 { 1, PI1, K1 }, /* K1, NIMP, NPI1 */
 { 1, PI1, K1 }, /* K1, NIMP, NIMP */
 { 1, PI1, K1 }, /* K1, NIMP, NPI2 */
 { 1, PI1, K1 }, /* K1, NIMP, XOR */
 { 1, PI1, K1 }, /* K1, NIMP, NAND */
 { 1, PI1, K1 }, /* K1, NIMP, AND */
 { 1, PI1, K1 }, /* K1, NIMP, BIIMP */
 { 1, PI1, K1 }, /* K1, NIMP, IMP */
 { 1, PI1, K1 }, /* K1, NIMP, LIMP */
 { 1, PI1, K1 }, /* K1, NIMP, OR */
 { 1, PI1, K1 }, /* K1, NIMP, K1 */
 { 1, PI1, K1 }, /* K1, NPI2, K0 */
 { 1, PI1, K1 }, /* K1, NPI2, PI1 */
 { 1, PI1, K1 }, /* K1, NPI2, PI2 */
 { 1, PI1, K1 }, /* K1, NPI2, NOR */
 { 1, PI1, K1 }, /* K1, NPI2, NLIMP */
 { 1, PI1, K1 }, /* K1, NPI2, NPI1 */
 { 1, PI1, K1 }, /* K1, NPI2, NIMP */
 { 1, PI1, K1 }, /* K1, NPI2, NPI2 */
 { 1, PI1, K1 }, /* K1, NPI2, XOR */
 { 1, PI1, K1 }, /* K1, NPI2, NAND */
 { 1, PI1, K1 }, /* K1, NPI2, AND */
 { 1, PI1, K1 }, /* K1, NPI2, BIIMP */
 { 1, PI1, K1 }, /* K1, NPI2, IMP */
 { 1, PI1, K1 }, /* K1, NPI2, LIMP */
 { 1, PI1, K1 }, /* K1, NPI2, OR */
 { 1, PI1, K1 }, /* K1, NPI2, K1 */
 { 1, PI1, K1 }, /* K1, XOR, K0 */
 { 1, PI1, K1 }, /* K1, XOR, PI1 */
 { 1, PI1, K1 }, /* K1, XOR, PI2 */
 { 1, PI1, K1 }, /* K1, XOR, NOR */
 { 1, PI1, K1 }, /* K1, XOR, NLIMP */
 { 1, PI1, K1 }, /* K1, XOR, NPI1 */
 { 1, PI1, K1 }, /* K1, XOR, NIMP */
 { 1, PI1, K1 }, /* K1, XOR, NPI2 */
 { 1, PI1, K1 }, /* K1, XOR, XOR */
 { 1, PI1, K1 }, /* K1, XOR, NAND */
 { 1, PI1, K1 }, /* K1, XOR, AND */
 { 1, PI1, K1 }, /* K1, XOR, BIIMP */
 { 1, PI1, K1 }, /* K1, XOR, IMP */
 { 1, PI1, K1 }, /* K1, XOR, LIMP */
 { 1, PI1, K1 }, /* K1, XOR, OR */
 { 1, PI1, K1 }, /* K1, XOR, K1 */
 { 1, PI1, K1 }, /* K1, NAND, K0 */
 { 1, PI1, K1 }, /* K1, NAND, PI1 */
 { 1, PI1, K1 }, /* K1, NAND, PI2 */
 { 1, PI1, K1 }, /* K1, NAND, NOR */
 { 1, PI1, K1 }, /* K1, NAND, NLIMP */
 { 1, PI1, K1 }, /* K1, NAND, NPI1 */
 { 1, PI1, K1 }, /* K1, NAND, NIMP */
 { 1, PI1, K1 }, /* K1, NAND, NPI2 */
 { 1, PI1, K1 }, /* K1, NAND, XOR */
 { 1, PI1, K1 }, /* K1, NAND, NAND */
 { 1, PI1, K1 }, /* K1, NAND, AND */
 { 1, PI1, K1 }, /* K1, NAND, BIIMP */
 { 1, PI1, K1 }, /* K1, NAND, IMP */
 { 1, PI1, K1 }, /* K1, NAND, LIMP */
 { 1, PI1, K1 }, /* K1, NAND, OR */
 { 1, PI1, K1 }, /* K1, NAND, K1 */
 { 1, PI1, K1 }, /* K1, AND, K0 */
 { 1, PI1, K1 }, /* K1, AND, PI1 */
 { 1, PI1, K1 }, /* K1, AND, PI2 */
 { 1, PI1, K1 }, /* K1, AND, NOR */
 { 1, PI1, K1 }, /* K1, AND, NLIMP */
 { 1, PI1, K1 }, /* K1, AND, NPI1 */
 { 1, PI1, K1 }, /* K1, AND, NIMP */
 { 1, PI1, K1 }, /* K1, AND, NPI2 */
 { 1, PI1, K1 }, /* K1, AND, XOR */
 { 1, PI1, K1 }, /* K1, AND, NAND */
 { 1, PI1, K1 }, /* K1, AND, AND */
 { 1, PI1, K1 }, /* K1, AND, BIIMP */
 { 1, PI1, K1 }, /* K1, AND, IMP */
 { 1, PI1, K1 }, /* K1, AND, LIMP */
 { 1, PI1, K1 }, /* K1, AND, OR */
 { 1, PI1, K1 }, /* K1, AND, K1 */
 { 1, PI1, K1 }, /* K1, BIIMP, K0 */
 { 1, PI1, K1 }, /* K1, BIIMP, PI1 */
 { 1, PI1, K1 }, /* K1, BIIMP, PI2 */
 { 1, PI1, K1 }, /* K1, BIIMP, NOR */
 { 1, PI1, K1 }, /* K1, BIIMP, NLIMP */
 { 1, PI1, K1 }, /* K1, BIIMP, NPI1 */
 { 1, PI1, K1 }, /* K1, BIIMP, NIMP */
 { 1, PI1, K1 }, /* K1, BIIMP, NPI2 */
 { 1, PI1, K1 }, /* K1, BIIMP, XOR */
 { 1, PI1, K1 }, /* K1, BIIMP, NAND */
 { 1, PI1, K1 }, /* K1, BIIMP, AND */
 { 1, PI1, K1 }, /* K1, BIIMP, BIIMP */
 { 1, PI1, K1 }, /* K1, BIIMP, IMP */
 { 1, PI1, K1 }, /* K1, BIIMP, LIMP */
 { 1, PI1, K1 }, /* K1, BIIMP, OR */
 { 1, PI1, K1 }, /* K1, BIIMP, K1 */
 { 1, PI1, K1 }, /* K1, IMP, K0 */
 { 1, PI1, K1 }, /* K1, IMP, PI1 */
 { 1, PI1, K1 }, /* K1, IMP, PI2 */
 { 1, PI1, K1 }, /* K1, IMP, NOR */
 { 1, PI1, K1 }, /* K1, IMP, NLIMP */
 { 1, PI1, K1 }, /* K1, IMP, NPI1 */
 { 1, PI1, K1 }, /* K1, IMP, NIMP */
 { 1, PI1, K1 }, /* K1, IMP, NPI2 */
 { 1, PI1, K1 }, /* K1, IMP, XOR */
 { 1, PI1, K1 }, /* K1, IMP, NAND */
 { 1, PI1, K1 }, /* K1, IMP, AND */
 { 1, PI1, K1 }, /* K1, IMP, BIIMP */
 { 1, PI1, K1 }, /* K1, IMP, IMP */
 { 1, PI1, K1 }, /* K1, IMP, LIMP */
 { 1, PI1, K1 }, /* K1, IMP, OR */
 { 1, PI1, K1 }, /* K1, IMP, K1 */
 { 1, PI1, K1 }, /* K1, LIMP, K0 */
 { 1, PI1, K1 }, /* K1, LIMP, PI1 */
 { 1, PI1, K1 }, /* K1, LIMP, PI2 */
 { 1, PI1, K1 }, /* K1, LIMP, NOR */
 { 1, PI1, K1 }, /* K1, LIMP, NLIMP */
 { 1, PI1, K1 }, /* K1, LIMP, NPI1 */
 { 1, PI1, K1 }, /* K1, LIMP, NIMP */
 { 1, PI1, K1 }, /* K1, LIMP, NPI2 */
 { 1, PI1, K1 }, /* K1, LIMP, XOR */
 { 1, PI1, K1 }, /* K1, LIMP, NAND */
 { 1, PI1, K1 }, /* K1, LIMP, AND */
 { 1, PI1, K1 }, /* K1, LIMP, BIIMP */
 { 1, PI1, K1 }, /* K1, LIMP, IMP */
 { 1, PI1, K1 }, /* K1, LIMP, LIMP */
 { 1, PI1, K1 }, /* K1, LIMP, OR */
 { 1, PI1, K1 }, /* K1, LIMP, K1 */
 { 1, PI1, K1 }, /* K1, OR, K0 */
 { 1, PI1, K1 }, /* K1, OR, PI1 */
 { 1, PI1, K1 }, /* K1, OR, PI2 */
 { 1, PI1, K1 }, /* K1, OR, NOR */
 { 1, PI1, K1 }, /* K1, OR, NLIMP */
 { 1, PI1, K1 }, /* K1, OR, NPI1 */
 { 1, PI1, K1 }, /* K1, OR, NIMP */
 { 1, PI1, K1 }, /* K1, OR, NPI2 */
 { 1, PI1, K1 }, /* K1, OR, XOR */
 { 1, PI1, K1 }, /* K1, OR, NAND */
 { 1, PI1, K1 }, /* K1, OR, AND */
 { 1, PI1, K1 }, /* K1, OR, BIIMP */
 { 1, PI1, K1 }, /* K1, OR, IMP */
 { 1, PI1, K1 }, /* K1, OR, LIMP */
 { 1, PI1, K1 }, /* K1, OR, OR */
 { 1, PI1, K1 }, /* K1, OR, K1 */
 { 1, PI1, K1 }, /* K1, K1, K0 */
 { 1, PI1, K1 }, /* K1, K1, PI1 */
 { 1, PI1, K1 }, /* K1, K1, PI2 */
 { 1, PI1, K1 }, /* K1, K1, NOR */
 { 1, PI1, K1 }, /* K1, K1, NLIMP */
 { 1, PI1, K1 }, /* K1, K1, NPI1 */
 { 1, PI1, K1 }, /* K1, K1, NIMP */
 { 1, PI1, K1 }, /* K1, K1, NPI2 */
 { 1, PI1, K1 }, /* K1, K1, XOR */
 { 1, PI1, K1 }, /* K1, K1, NAND */
 { 1, PI1, K1 }, /* K1, K1, AND */
 { 1, PI1, K1 }, /* K1, K1, BIIMP */
 { 1, PI1, K1 }, /* K1, K1, IMP */
 { 1, PI1, K1 }, /* K1, K1, LIMP */
 { 1, PI1, K1 }, /* K1, K1, OR */
 { 1, PI1, K1 }, /* K1, K1, K1 */
 { 0, 0, 0 }   /* Dummy row */
};

Op three_nodes_two_grandchildren_reduction_array[] = {
 K0, /* K0, K0, K0 */
 K0, /* K0, K0, PI1 */
 K0, /* K0, K0, PI2 */
 K0, /* K0, K0, NOR */
 K0, /* K0, K0, NLIMP */
 K0, /* K0, K0, NPI1 */
 K0, /* K0, K0, NIMP */
 K0, /* K0, K0, NPI2 */
 K0, /* K0, K0, XOR */
 K0, /* K0, K0, NAND */
 K0, /* K0, K0, AND */
 K0, /* K0, K0, BIIMP */
 K0, /* K0, K0, IMP */
 K0, /* K0, K0, LIMP */
 K0, /* K0, K0, OR */
 K0, /* K0, K0, K1 */
 K0, /* K0, PI1, K0 */
 K0, /* K0, PI1, PI1 */
 K0, /* K0, PI1, PI2 */
 K0, /* K0, PI1, NOR */
 K0, /* K0, PI1, NLIMP */
 K0, /* K0, PI1, NPI1 */
 K0, /* K0, PI1, NIMP */
 K0, /* K0, PI1, NPI2 */
 K0, /* K0, PI1, XOR */
 K0, /* K0, PI1, NAND */
 K0, /* K0, PI1, AND */
 K0, /* K0, PI1, BIIMP */
 K0, /* K0, PI1, IMP */
 K0, /* K0, PI1, LIMP */
 K0, /* K0, PI1, OR */
 K0, /* K0, PI1, K1 */
 K0, /* K0, PI2, K0 */
 K0, /* K0, PI2, PI1 */
 K0, /* K0, PI2, PI2 */
 K0, /* K0, PI2, NOR */
 K0, /* K0, PI2, NLIMP */
 K0, /* K0, PI2, NPI1 */
 K0, /* K0, PI2, NIMP */
 K0, /* K0, PI2, NPI2 */
 K0, /* K0, PI2, XOR */
 K0, /* K0, PI2, NAND */
 K0, /* K0, PI2, AND */
 K0, /* K0, PI2, BIIMP */
 K0, /* K0, PI2, IMP */
 K0, /* K0, PI2, LIMP */
 K0, /* K0, PI2, OR */
 K0, /* K0, PI2, K1 */
 K0, /* K0, NOR, K0 */
 K0, /* K0, NOR, PI1 */
 K0, /* K0, NOR, PI2 */
 K0, /* K0, NOR, NOR */
 K0, /* K0, NOR, NLIMP */
 K0, /* K0, NOR, NPI1 */
 K0, /* K0, NOR, NIMP */
 K0, /* K0, NOR, NPI2 */
 K0, /* K0, NOR, XOR */
 K0, /* K0, NOR, NAND */
 K0, /* K0, NOR, AND */
 K0, /* K0, NOR, BIIMP */
 K0, /* K0, NOR, IMP */
 K0, /* K0, NOR, LIMP */
 K0, /* K0, NOR, OR */
 K0, /* K0, NOR, K1 */
 K0, /* K0, NLIMP, K0 */
 K0, /* K0, NLIMP, PI1 */
 K0, /* K0, NLIMP, PI2 */
 K0, /* K0, NLIMP, NOR */
 K0, /* K0, NLIMP, NLIMP */
 K0, /* K0, NLIMP, NPI1 */
 K0, /* K0, NLIMP, NIMP */
 K0, /* K0, NLIMP, NPI2 */
 K0, /* K0, NLIMP, XOR */
 K0, /* K0, NLIMP, NAND */
 K0, /* K0, NLIMP, AND */
 K0, /* K0, NLIMP, BIIMP */
 K0, /* K0, NLIMP, IMP */
 K0, /* K0, NLIMP, LIMP */
 K0, /* K0, NLIMP, OR */
 K0, /* K0, NLIMP, K1 */
 K0, /* K0, NPI1, K0 */
 K0, /* K0, NPI1, PI1 */
 K0, /* K0, NPI1, PI2 */
 K0, /* K0, NPI1, NOR */
 K0, /* K0, NPI1, NLIMP */
 K0, /* K0, NPI1, NPI1 */
 K0, /* K0, NPI1, NIMP */
 K0, /* K0, NPI1, NPI2 */
 K0, /* K0, NPI1, XOR */
 K0, /* K0, NPI1, NAND */
 K0, /* K0, NPI1, AND */
 K0, /* K0, NPI1, BIIMP */
 K0, /* K0, NPI1, IMP */
 K0, /* K0, NPI1, LIMP */
 K0, /* K0, NPI1, OR */
 K0, /* K0, NPI1, K1 */
 K0, /* K0, NIMP, K0 */
 K0, /* K0, NIMP, PI1 */
 K0, /* K0, NIMP, PI2 */
 K0, /* K0, NIMP, NOR */
 K0, /* K0, NIMP, NLIMP */
 K0, /* K0, NIMP, NPI1 */
 K0, /* K0, NIMP, NIMP */
 K0, /* K0, NIMP, NPI2 */
 K0, /* K0, NIMP, XOR */
 K0, /* K0, NIMP, NAND */
 K0, /* K0, NIMP, AND */
 K0, /* K0, NIMP, BIIMP */
 K0, /* K0, NIMP, IMP */
 K0, /* K0, NIMP, LIMP */
 K0, /* K0, NIMP, OR */
 K0, /* K0, NIMP, K1 */
 K0, /* K0, NPI2, K0 */
 K0, /* K0, NPI2, PI1 */
 K0, /* K0, NPI2, PI2 */
 K0, /* K0, NPI2, NOR */
 K0, /* K0, NPI2, NLIMP */
 K0, /* K0, NPI2, NPI1 */
 K0, /* K0, NPI2, NIMP */
 K0, /* K0, NPI2, NPI2 */
 K0, /* K0, NPI2, XOR */
 K0, /* K0, NPI2, NAND */
 K0, /* K0, NPI2, AND */
 K0, /* K0, NPI2, BIIMP */
 K0, /* K0, NPI2, IMP */
 K0, /* K0, NPI2, LIMP */
 K0, /* K0, NPI2, OR */
 K0, /* K0, NPI2, K1 */
 K0, /* K0, XOR, K0 */
 K0, /* K0, XOR, PI1 */
 K0, /* K0, XOR, PI2 */
 K0, /* K0, XOR, NOR */
 K0, /* K0, XOR, NLIMP */
 K0, /* K0, XOR, NPI1 */
 K0, /* K0, XOR, NIMP */
 K0, /* K0, XOR, NPI2 */
 K0, /* K0, XOR, XOR */
 K0, /* K0, XOR, NAND */
 K0, /* K0, XOR, AND */
 K0, /* K0, XOR, BIIMP */
 K0, /* K0, XOR, IMP */
 K0, /* K0, XOR, LIMP */
 K0, /* K0, XOR, OR */
 K0, /* K0, XOR, K1 */
 K0, /* K0, NAND, K0 */
 K0, /* K0, NAND, PI1 */
 K0, /* K0, NAND, PI2 */
 K0, /* K0, NAND, NOR */
 K0, /* K0, NAND, NLIMP */
 K0, /* K0, NAND, NPI1 */
 K0, /* K0, NAND, NIMP */
 K0, /* K0, NAND, NPI2 */
 K0, /* K0, NAND, XOR */
 K0, /* K0, NAND, NAND */
 K0, /* K0, NAND, AND */
 K0, /* K0, NAND, BIIMP */
 K0, /* K0, NAND, IMP */
 K0, /* K0, NAND, LIMP */
 K0, /* K0, NAND, OR */
 K0, /* K0, NAND, K1 */
 K0, /* K0, AND, K0 */
 K0, /* K0, AND, PI1 */
 K0, /* K0, AND, PI2 */
 K0, /* K0, AND, NOR */
 K0, /* K0, AND, NLIMP */
 K0, /* K0, AND, NPI1 */
 K0, /* K0, AND, NIMP */
 K0, /* K0, AND, NPI2 */
 K0, /* K0, AND, XOR */
 K0, /* K0, AND, NAND */
 K0, /* K0, AND, AND */
 K0, /* K0, AND, BIIMP */
 K0, /* K0, AND, IMP */
 K0, /* K0, AND, LIMP */
 K0, /* K0, AND, OR */
 K0, /* K0, AND, K1 */
 K0, /* K0, BIIMP, K0 */
 K0, /* K0, BIIMP, PI1 */
 K0, /* K0, BIIMP, PI2 */
 K0, /* K0, BIIMP, NOR */
 K0, /* K0, BIIMP, NLIMP */
 K0, /* K0, BIIMP, NPI1 */
 K0, /* K0, BIIMP, NIMP */
 K0, /* K0, BIIMP, NPI2 */
 K0, /* K0, BIIMP, XOR */
 K0, /* K0, BIIMP, NAND */
 K0, /* K0, BIIMP, AND */
 K0, /* K0, BIIMP, BIIMP */
 K0, /* K0, BIIMP, IMP */
 K0, /* K0, BIIMP, LIMP */
 K0, /* K0, BIIMP, OR */
 K0, /* K0, BIIMP, K1 */
 K0, /* K0, IMP, K0 */
 K0, /* K0, IMP, PI1 */
 K0, /* K0, IMP, PI2 */
 K0, /* K0, IMP, NOR */
 K0, /* K0, IMP, NLIMP */
 K0, /* K0, IMP, NPI1 */
 K0, /* K0, IMP, NIMP */
 K0, /* K0, IMP, NPI2 */
 K0, /* K0, IMP, XOR */
 K0, /* K0, IMP, NAND */
 K0, /* K0, IMP, AND */
 K0, /* K0, IMP, BIIMP */
 K0, /* K0, IMP, IMP */
 K0, /* K0, IMP, LIMP */
 K0, /* K0, IMP, OR */
 K0, /* K0, IMP, K1 */
 K0, /* K0, LIMP, K0 */
 K0, /* K0, LIMP, PI1 */
 K0, /* K0, LIMP, PI2 */
 K0, /* K0, LIMP, NOR */
 K0, /* K0, LIMP, NLIMP */
 K0, /* K0, LIMP, NPI1 */
 K0, /* K0, LIMP, NIMP */
 K0, /* K0, LIMP, NPI2 */
 K0, /* K0, LIMP, XOR */
 K0, /* K0, LIMP, NAND */
 K0, /* K0, LIMP, AND */
 K0, /* K0, LIMP, BIIMP */
 K0, /* K0, LIMP, IMP */
 K0, /* K0, LIMP, LIMP */
 K0, /* K0, LIMP, OR */
 K0, /* K0, LIMP, K1 */
 K0, /* K0, OR, K0 */
 K0, /* K0, OR, PI1 */
 K0, /* K0, OR, PI2 */
 K0, /* K0, OR, NOR */
 K0, /* K0, OR, NLIMP */
 K0, /* K0, OR, NPI1 */
 K0, /* K0, OR, NIMP */
 K0, /* K0, OR, NPI2 */
 K0, /* K0, OR, XOR */
 K0, /* K0, OR, NAND */
 K0, /* K0, OR, AND */
 K0, /* K0, OR, BIIMP */
 K0, /* K0, OR, IMP */
 K0, /* K0, OR, LIMP */
 K0, /* K0, OR, OR */
 K0, /* K0, OR, K1 */
 K0, /* K0, K1, K0 */
 K0, /* K0, K1, PI1 */
 K0, /* K0, K1, PI2 */
 K0, /* K0, K1, NOR */
 K0, /* K0, K1, NLIMP */
 K0, /* K0, K1, NPI1 */
 K0, /* K0, K1, NIMP */
 K0, /* K0, K1, NPI2 */
 K0, /* K0, K1, XOR */
 K0, /* K0, K1, NAND */
 K0, /* K0, K1, AND */
 K0, /* K0, K1, BIIMP */
 K0, /* K0, K1, IMP */
 K0, /* K0, K1, LIMP */
 K0, /* K0, K1, OR */
 K0, /* K0, K1, K1 */
 K0, /* PI1, K0, K0 */
 K0, /* PI1, K0, PI1 */
 K0, /* PI1, K0, PI2 */
 K0, /* PI1, K0, NOR */
 K0, /* PI1, K0, NLIMP */
 K0, /* PI1, K0, NPI1 */
 K0, /* PI1, K0, NIMP */
 K0, /* PI1, K0, NPI2 */
 K0, /* PI1, K0, XOR */
 K0, /* PI1, K0, NAND */
 K0, /* PI1, K0, AND */
 K0, /* PI1, K0, BIIMP */
 K0, /* PI1, K0, IMP */
 K0, /* PI1, K0, LIMP */
 K0, /* PI1, K0, OR */
 K0, /* PI1, K0, K1 */
 PI1, /* PI1, PI1, K0 */
 PI1, /* PI1, PI1, PI1 */
 PI1, /* PI1, PI1, PI2 */
 PI1, /* PI1, PI1, NOR */
 PI1, /* PI1, PI1, NLIMP */
 PI1, /* PI1, PI1, NPI1 */
 PI1, /* PI1, PI1, NIMP */
 PI1, /* PI1, PI1, NPI2 */
 PI1, /* PI1, PI1, XOR */
 PI1, /* PI1, PI1, NAND */
 PI1, /* PI1, PI1, AND */
 PI1, /* PI1, PI1, BIIMP */
 PI1, /* PI1, PI1, IMP */
 PI1, /* PI1, PI1, LIMP */
 PI1, /* PI1, PI1, OR */
 PI1, /* PI1, PI1, K1 */
 PI2, /* PI1, PI2, K0 */
 PI2, /* PI1, PI2, PI1 */
 PI2, /* PI1, PI2, PI2 */
 PI2, /* PI1, PI2, NOR */
 PI2, /* PI1, PI2, NLIMP */
 PI2, /* PI1, PI2, NPI1 */
 PI2, /* PI1, PI2, NIMP */
 PI2, /* PI1, PI2, NPI2 */
 PI2, /* PI1, PI2, XOR */
 PI2, /* PI1, PI2, NAND */
 PI2, /* PI1, PI2, AND */
 PI2, /* PI1, PI2, BIIMP */
 PI2, /* PI1, PI2, IMP */
 PI2, /* PI1, PI2, LIMP */
 PI2, /* PI1, PI2, OR */
 PI2, /* PI1, PI2, K1 */
 NOR, /* PI1, NOR, K0 */
 NOR, /* PI1, NOR, PI1 */
 NOR, /* PI1, NOR, PI2 */
 NOR, /* PI1, NOR, NOR */
 NOR, /* PI1, NOR, NLIMP */
 NOR, /* PI1, NOR, NPI1 */
 NOR, /* PI1, NOR, NIMP */
 NOR, /* PI1, NOR, NPI2 */
 NOR, /* PI1, NOR, XOR */
 NOR, /* PI1, NOR, NAND */
 NOR, /* PI1, NOR, AND */
 NOR, /* PI1, NOR, BIIMP */
 NOR, /* PI1, NOR, IMP */
 NOR, /* PI1, NOR, LIMP */
 NOR, /* PI1, NOR, OR */
 NOR, /* PI1, NOR, K1 */
 NLIMP, /* PI1, NLIMP, K0 */
 NLIMP, /* PI1, NLIMP, PI1 */
 NLIMP, /* PI1, NLIMP, PI2 */
 NLIMP, /* PI1, NLIMP, NOR */
 NLIMP, /* PI1, NLIMP, NLIMP */
 NLIMP, /* PI1, NLIMP, NPI1 */
 NLIMP, /* PI1, NLIMP, NIMP */
 NLIMP, /* PI1, NLIMP, NPI2 */
 NLIMP, /* PI1, NLIMP, XOR */
 NLIMP, /* PI1, NLIMP, NAND */
 NLIMP, /* PI1, NLIMP, AND */
 NLIMP, /* PI1, NLIMP, BIIMP */
 NLIMP, /* PI1, NLIMP, IMP */
 NLIMP, /* PI1, NLIMP, LIMP */
 NLIMP, /* PI1, NLIMP, OR */
 NLIMP, /* PI1, NLIMP, K1 */
 NPI1, /* PI1, NPI1, K0 */
 NPI1, /* PI1, NPI1, PI1 */
 NPI1, /* PI1, NPI1, PI2 */
 NPI1, /* PI1, NPI1, NOR */
 NPI1, /* PI1, NPI1, NLIMP */
 NPI1, /* PI1, NPI1, NPI1 */
 NPI1, /* PI1, NPI1, NIMP */
 NPI1, /* PI1, NPI1, NPI2 */
 NPI1, /* PI1, NPI1, XOR */
 NPI1, /* PI1, NPI1, NAND */
 NPI1, /* PI1, NPI1, AND */
 NPI1, /* PI1, NPI1, BIIMP */
 NPI1, /* PI1, NPI1, IMP */
 NPI1, /* PI1, NPI1, LIMP */
 NPI1, /* PI1, NPI1, OR */
 NPI1, /* PI1, NPI1, K1 */
 NIMP, /* PI1, NIMP, K0 */
 NIMP, /* PI1, NIMP, PI1 */
 NIMP, /* PI1, NIMP, PI2 */
 NIMP, /* PI1, NIMP, NOR */
 NIMP, /* PI1, NIMP, NLIMP */
 NIMP, /* PI1, NIMP, NPI1 */
 NIMP, /* PI1, NIMP, NIMP */
 NIMP, /* PI1, NIMP, NPI2 */
 NIMP, /* PI1, NIMP, XOR */
 NIMP, /* PI1, NIMP, NAND */
 NIMP, /* PI1, NIMP, AND */
 NIMP, /* PI1, NIMP, BIIMP */
 NIMP, /* PI1, NIMP, IMP */
 NIMP, /* PI1, NIMP, LIMP */
 NIMP, /* PI1, NIMP, OR */
 NIMP, /* PI1, NIMP, K1 */
 NPI2, /* PI1, NPI2, K0 */
 NPI2, /* PI1, NPI2, PI1 */
 NPI2, /* PI1, NPI2, PI2 */
 NPI2, /* PI1, NPI2, NOR */
 NPI2, /* PI1, NPI2, NLIMP */
 NPI2, /* PI1, NPI2, NPI1 */
 NPI2, /* PI1, NPI2, NIMP */
 NPI2, /* PI1, NPI2, NPI2 */
 NPI2, /* PI1, NPI2, XOR */
 NPI2, /* PI1, NPI2, NAND */
 NPI2, /* PI1, NPI2, AND */
 NPI2, /* PI1, NPI2, BIIMP */
 NPI2, /* PI1, NPI2, IMP */
 NPI2, /* PI1, NPI2, LIMP */
 NPI2, /* PI1, NPI2, OR */
 NPI2, /* PI1, NPI2, K1 */
 XOR, /* PI1, XOR, K0 */
 XOR, /* PI1, XOR, PI1 */
 XOR, /* PI1, XOR, PI2 */
 XOR, /* PI1, XOR, NOR */
 XOR, /* PI1, XOR, NLIMP */
 XOR, /* PI1, XOR, NPI1 */
 XOR, /* PI1, XOR, NIMP */
 XOR, /* PI1, XOR, NPI2 */
 XOR, /* PI1, XOR, XOR */
 XOR, /* PI1, XOR, NAND */
 XOR, /* PI1, XOR, AND */
 XOR, /* PI1, XOR, BIIMP */
 XOR, /* PI1, XOR, IMP */
 XOR, /* PI1, XOR, LIMP */
 XOR, /* PI1, XOR, OR */
 XOR, /* PI1, XOR, K1 */
 NAND, /* PI1, NAND, K0 */
 NAND, /* PI1, NAND, PI1 */
 NAND, /* PI1, NAND, PI2 */
 NAND, /* PI1, NAND, NOR */
 NAND, /* PI1, NAND, NLIMP */
 NAND, /* PI1, NAND, NPI1 */
 NAND, /* PI1, NAND, NIMP */
 NAND, /* PI1, NAND, NPI2 */
 NAND, /* PI1, NAND, XOR */
 NAND, /* PI1, NAND, NAND */
 NAND, /* PI1, NAND, AND */
 NAND, /* PI1, NAND, BIIMP */
 NAND, /* PI1, NAND, IMP */
 NAND, /* PI1, NAND, LIMP */
 NAND, /* PI1, NAND, OR */
 NAND, /* PI1, NAND, K1 */
 AND, /* PI1, AND, K0 */
 AND, /* PI1, AND, PI1 */
 AND, /* PI1, AND, PI2 */
 AND, /* PI1, AND, NOR */
 AND, /* PI1, AND, NLIMP */
 AND, /* PI1, AND, NPI1 */
 AND, /* PI1, AND, NIMP */
 AND, /* PI1, AND, NPI2 */
 AND, /* PI1, AND, XOR */
 AND, /* PI1, AND, NAND */
 AND, /* PI1, AND, AND */
 AND, /* PI1, AND, BIIMP */
 AND, /* PI1, AND, IMP */
 AND, /* PI1, AND, LIMP */
 AND, /* PI1, AND, OR */
 AND, /* PI1, AND, K1 */
 BIIMP, /* PI1, BIIMP, K0 */
 BIIMP, /* PI1, BIIMP, PI1 */
 BIIMP, /* PI1, BIIMP, PI2 */
 BIIMP, /* PI1, BIIMP, NOR */
 BIIMP, /* PI1, BIIMP, NLIMP */
 BIIMP, /* PI1, BIIMP, NPI1 */
 BIIMP, /* PI1, BIIMP, NIMP */
 BIIMP, /* PI1, BIIMP, NPI2 */
 BIIMP, /* PI1, BIIMP, XOR */
 BIIMP, /* PI1, BIIMP, NAND */
 BIIMP, /* PI1, BIIMP, AND */
 BIIMP, /* PI1, BIIMP, BIIMP */
 BIIMP, /* PI1, BIIMP, IMP */
 BIIMP, /* PI1, BIIMP, LIMP */
 BIIMP, /* PI1, BIIMP, OR */
 BIIMP, /* PI1, BIIMP, K1 */
 IMP, /* PI1, IMP, K0 */
 IMP, /* PI1, IMP, PI1 */
 IMP, /* PI1, IMP, PI2 */
 IMP, /* PI1, IMP, NOR */
 IMP, /* PI1, IMP, NLIMP */
 IMP, /* PI1, IMP, NPI1 */
 IMP, /* PI1, IMP, NIMP */
 IMP, /* PI1, IMP, NPI2 */
 IMP, /* PI1, IMP, XOR */
 IMP, /* PI1, IMP, NAND */
 IMP, /* PI1, IMP, AND */
 IMP, /* PI1, IMP, BIIMP */
 IMP, /* PI1, IMP, IMP */
 IMP, /* PI1, IMP, LIMP */
 IMP, /* PI1, IMP, OR */
 IMP, /* PI1, IMP, K1 */
 LIMP, /* PI1, LIMP, K0 */
 LIMP, /* PI1, LIMP, PI1 */
 LIMP, /* PI1, LIMP, PI2 */
 LIMP, /* PI1, LIMP, NOR */
 LIMP, /* PI1, LIMP, NLIMP */
 LIMP, /* PI1, LIMP, NPI1 */
 LIMP, /* PI1, LIMP, NIMP */
 LIMP, /* PI1, LIMP, NPI2 */
 LIMP, /* PI1, LIMP, XOR */
 LIMP, /* PI1, LIMP, NAND */
 LIMP, /* PI1, LIMP, AND */
 LIMP, /* PI1, LIMP, BIIMP */
 LIMP, /* PI1, LIMP, IMP */
 LIMP, /* PI1, LIMP, LIMP */
 LIMP, /* PI1, LIMP, OR */
 LIMP, /* PI1, LIMP, K1 */
 OR, /* PI1, OR, K0 */
 OR, /* PI1, OR, PI1 */
 OR, /* PI1, OR, PI2 */
 OR, /* PI1, OR, NOR */
 OR, /* PI1, OR, NLIMP */
 OR, /* PI1, OR, NPI1 */
 OR, /* PI1, OR, NIMP */
 OR, /* PI1, OR, NPI2 */
 OR, /* PI1, OR, XOR */
 OR, /* PI1, OR, NAND */
 OR, /* PI1, OR, AND */
 OR, /* PI1, OR, BIIMP */
 OR, /* PI1, OR, IMP */
 OR, /* PI1, OR, LIMP */
 OR, /* PI1, OR, OR */
 OR, /* PI1, OR, K1 */
 K1, /* PI1, K1, K0 */
 K1, /* PI1, K1, PI1 */
 K1, /* PI1, K1, PI2 */
 K1, /* PI1, K1, NOR */
 K1, /* PI1, K1, NLIMP */
 K1, /* PI1, K1, NPI1 */
 K1, /* PI1, K1, NIMP */
 K1, /* PI1, K1, NPI2 */
 K1, /* PI1, K1, XOR */
 K1, /* PI1, K1, NAND */
 K1, /* PI1, K1, AND */
 K1, /* PI1, K1, BIIMP */
 K1, /* PI1, K1, IMP */
 K1, /* PI1, K1, LIMP */
 K1, /* PI1, K1, OR */
 K1, /* PI1, K1, K1 */
 K0, /* PI2, K0, K0 */
 PI1, /* PI2, K0, PI1 */
 PI2, /* PI2, K0, PI2 */
 NOR, /* PI2, K0, NOR */
 NLIMP, /* PI2, K0, NLIMP */
 NPI1, /* PI2, K0, NPI1 */
 NIMP, /* PI2, K0, NIMP */
 NPI2, /* PI2, K0, NPI2 */
 XOR, /* PI2, K0, XOR */
 NAND, /* PI2, K0, NAND */
 AND, /* PI2, K0, AND */
 BIIMP, /* PI2, K0, BIIMP */
 IMP, /* PI2, K0, IMP */
 LIMP, /* PI2, K0, LIMP */
 OR, /* PI2, K0, OR */
 K1, /* PI2, K0, K1 */
 K0, /* PI2, PI1, K0 */
 PI1, /* PI2, PI1, PI1 */
 PI2, /* PI2, PI1, PI2 */
 NOR, /* PI2, PI1, NOR */
 NLIMP, /* PI2, PI1, NLIMP */
 NPI1, /* PI2, PI1, NPI1 */
 NIMP, /* PI2, PI1, NIMP */
 NPI2, /* PI2, PI1, NPI2 */
 XOR, /* PI2, PI1, XOR */
 NAND, /* PI2, PI1, NAND */
 AND, /* PI2, PI1, AND */
 BIIMP, /* PI2, PI1, BIIMP */
 IMP, /* PI2, PI1, IMP */
 LIMP, /* PI2, PI1, LIMP */
 OR, /* PI2, PI1, OR */
 K1, /* PI2, PI1, K1 */
 K0, /* PI2, PI2, K0 */
 PI1, /* PI2, PI2, PI1 */
 PI2, /* PI2, PI2, PI2 */
 NOR, /* PI2, PI2, NOR */
 NLIMP, /* PI2, PI2, NLIMP */
 NPI1, /* PI2, PI2, NPI1 */
 NIMP, /* PI2, PI2, NIMP */
 NPI2, /* PI2, PI2, NPI2 */
 XOR, /* PI2, PI2, XOR */
 NAND, /* PI2, PI2, NAND */
 AND, /* PI2, PI2, AND */
 BIIMP, /* PI2, PI2, BIIMP */
 IMP, /* PI2, PI2, IMP */
 LIMP, /* PI2, PI2, LIMP */
 OR, /* PI2, PI2, OR */
 K1, /* PI2, PI2, K1 */
 K0, /* PI2, NOR, K0 */
 PI1, /* PI2, NOR, PI1 */
 PI2, /* PI2, NOR, PI2 */
 NOR, /* PI2, NOR, NOR */
 NLIMP, /* PI2, NOR, NLIMP */
 NPI1, /* PI2, NOR, NPI1 */
 NIMP, /* PI2, NOR, NIMP */
 NPI2, /* PI2, NOR, NPI2 */
 XOR, /* PI2, NOR, XOR */
 NAND, /* PI2, NOR, NAND */
 AND, /* PI2, NOR, AND */
 BIIMP, /* PI2, NOR, BIIMP */
 IMP, /* PI2, NOR, IMP */
 LIMP, /* PI2, NOR, LIMP */
 OR, /* PI2, NOR, OR */
 K1, /* PI2, NOR, K1 */
 K0, /* PI2, NLIMP, K0 */
 PI1, /* PI2, NLIMP, PI1 */
 PI2, /* PI2, NLIMP, PI2 */
 NOR, /* PI2, NLIMP, NOR */
 NLIMP, /* PI2, NLIMP, NLIMP */
 NPI1, /* PI2, NLIMP, NPI1 */
 NIMP, /* PI2, NLIMP, NIMP */
 NPI2, /* PI2, NLIMP, NPI2 */
 XOR, /* PI2, NLIMP, XOR */
 NAND, /* PI2, NLIMP, NAND */
 AND, /* PI2, NLIMP, AND */
 BIIMP, /* PI2, NLIMP, BIIMP */
 IMP, /* PI2, NLIMP, IMP */
 LIMP, /* PI2, NLIMP, LIMP */
 OR, /* PI2, NLIMP, OR */
 K1, /* PI2, NLIMP, K1 */
 K0, /* PI2, NPI1, K0 */
 PI1, /* PI2, NPI1, PI1 */
 PI2, /* PI2, NPI1, PI2 */
 NOR, /* PI2, NPI1, NOR */
 NLIMP, /* PI2, NPI1, NLIMP */
 NPI1, /* PI2, NPI1, NPI1 */
 NIMP, /* PI2, NPI1, NIMP */
 NPI2, /* PI2, NPI1, NPI2 */
 XOR, /* PI2, NPI1, XOR */
 NAND, /* PI2, NPI1, NAND */
 AND, /* PI2, NPI1, AND */
 BIIMP, /* PI2, NPI1, BIIMP */
 IMP, /* PI2, NPI1, IMP */
 LIMP, /* PI2, NPI1, LIMP */
 OR, /* PI2, NPI1, OR */
 K1, /* PI2, NPI1, K1 */
 K0, /* PI2, NIMP, K0 */
 PI1, /* PI2, NIMP, PI1 */
 PI2, /* PI2, NIMP, PI2 */
 NOR, /* PI2, NIMP, NOR */
 NLIMP, /* PI2, NIMP, NLIMP */
 NPI1, /* PI2, NIMP, NPI1 */
 NIMP, /* PI2, NIMP, NIMP */
 NPI2, /* PI2, NIMP, NPI2 */
 XOR, /* PI2, NIMP, XOR */
 NAND, /* PI2, NIMP, NAND */
 AND, /* PI2, NIMP, AND */
 BIIMP, /* PI2, NIMP, BIIMP */
 IMP, /* PI2, NIMP, IMP */
 LIMP, /* PI2, NIMP, LIMP */
 OR, /* PI2, NIMP, OR */
 K1, /* PI2, NIMP, K1 */
 K0, /* PI2, NPI2, K0 */
 PI1, /* PI2, NPI2, PI1 */
 PI2, /* PI2, NPI2, PI2 */
 NOR, /* PI2, NPI2, NOR */
 NLIMP, /* PI2, NPI2, NLIMP */
 NPI1, /* PI2, NPI2, NPI1 */
 NIMP, /* PI2, NPI2, NIMP */
 NPI2, /* PI2, NPI2, NPI2 */
 XOR, /* PI2, NPI2, XOR */
 NAND, /* PI2, NPI2, NAND */
 AND, /* PI2, NPI2, AND */
 BIIMP, /* PI2, NPI2, BIIMP */
 IMP, /* PI2, NPI2, IMP */
 LIMP, /* PI2, NPI2, LIMP */
 OR, /* PI2, NPI2, OR */
 K1, /* PI2, NPI2, K1 */
 K0, /* PI2, XOR, K0 */
 PI1, /* PI2, XOR, PI1 */
 PI2, /* PI2, XOR, PI2 */
 NOR, /* PI2, XOR, NOR */
 NLIMP, /* PI2, XOR, NLIMP */
 NPI1, /* PI2, XOR, NPI1 */
 NIMP, /* PI2, XOR, NIMP */
 NPI2, /* PI2, XOR, NPI2 */
 XOR, /* PI2, XOR, XOR */
 NAND, /* PI2, XOR, NAND */
 AND, /* PI2, XOR, AND */
 BIIMP, /* PI2, XOR, BIIMP */
 IMP, /* PI2, XOR, IMP */
 LIMP, /* PI2, XOR, LIMP */
 OR, /* PI2, XOR, OR */
 K1, /* PI2, XOR, K1 */
 K0, /* PI2, NAND, K0 */
 PI1, /* PI2, NAND, PI1 */
 PI2, /* PI2, NAND, PI2 */
 NOR, /* PI2, NAND, NOR */
 NLIMP, /* PI2, NAND, NLIMP */
 NPI1, /* PI2, NAND, NPI1 */
 NIMP, /* PI2, NAND, NIMP */
 NPI2, /* PI2, NAND, NPI2 */
 XOR, /* PI2, NAND, XOR */
 NAND, /* PI2, NAND, NAND */
 AND, /* PI2, NAND, AND */
 BIIMP, /* PI2, NAND, BIIMP */
 IMP, /* PI2, NAND, IMP */
 LIMP, /* PI2, NAND, LIMP */
 OR, /* PI2, NAND, OR */
 K1, /* PI2, NAND, K1 */
 K0, /* PI2, AND, K0 */
 PI1, /* PI2, AND, PI1 */
 PI2, /* PI2, AND, PI2 */
 NOR, /* PI2, AND, NOR */
 NLIMP, /* PI2, AND, NLIMP */
 NPI1, /* PI2, AND, NPI1 */
 NIMP, /* PI2, AND, NIMP */
 NPI2, /* PI2, AND, NPI2 */
 XOR, /* PI2, AND, XOR */
 NAND, /* PI2, AND, NAND */
 AND, /* PI2, AND, AND */
 BIIMP, /* PI2, AND, BIIMP */
 IMP, /* PI2, AND, IMP */
 LIMP, /* PI2, AND, LIMP */
 OR, /* PI2, AND, OR */
 K1, /* PI2, AND, K1 */
 K0, /* PI2, BIIMP, K0 */
 PI1, /* PI2, BIIMP, PI1 */
 PI2, /* PI2, BIIMP, PI2 */
 NOR, /* PI2, BIIMP, NOR */
 NLIMP, /* PI2, BIIMP, NLIMP */
 NPI1, /* PI2, BIIMP, NPI1 */
 NIMP, /* PI2, BIIMP, NIMP */
 NPI2, /* PI2, BIIMP, NPI2 */
 XOR, /* PI2, BIIMP, XOR */
 NAND, /* PI2, BIIMP, NAND */
 AND, /* PI2, BIIMP, AND */
 BIIMP, /* PI2, BIIMP, BIIMP */
 IMP, /* PI2, BIIMP, IMP */
 LIMP, /* PI2, BIIMP, LIMP */
 OR, /* PI2, BIIMP, OR */
 K1, /* PI2, BIIMP, K1 */
 K0, /* PI2, IMP, K0 */
 PI1, /* PI2, IMP, PI1 */
 PI2, /* PI2, IMP, PI2 */
 NOR, /* PI2, IMP, NOR */
 NLIMP, /* PI2, IMP, NLIMP */
 NPI1, /* PI2, IMP, NPI1 */
 NIMP, /* PI2, IMP, NIMP */
 NPI2, /* PI2, IMP, NPI2 */
 XOR, /* PI2, IMP, XOR */
 NAND, /* PI2, IMP, NAND */
 AND, /* PI2, IMP, AND */
 BIIMP, /* PI2, IMP, BIIMP */
 IMP, /* PI2, IMP, IMP */
 LIMP, /* PI2, IMP, LIMP */
 OR, /* PI2, IMP, OR */
 K1, /* PI2, IMP, K1 */
 K0, /* PI2, LIMP, K0 */
 PI1, /* PI2, LIMP, PI1 */
 PI2, /* PI2, LIMP, PI2 */
 NOR, /* PI2, LIMP, NOR */
 NLIMP, /* PI2, LIMP, NLIMP */
 NPI1, /* PI2, LIMP, NPI1 */
 NIMP, /* PI2, LIMP, NIMP */
 NPI2, /* PI2, LIMP, NPI2 */
 XOR, /* PI2, LIMP, XOR */
 NAND, /* PI2, LIMP, NAND */
 AND, /* PI2, LIMP, AND */
 BIIMP, /* PI2, LIMP, BIIMP */
 IMP, /* PI2, LIMP, IMP */
 LIMP, /* PI2, LIMP, LIMP */
 OR, /* PI2, LIMP, OR */
 K1, /* PI2, LIMP, K1 */
 K0, /* PI2, OR, K0 */
 PI1, /* PI2, OR, PI1 */
 PI2, /* PI2, OR, PI2 */
 NOR, /* PI2, OR, NOR */
 NLIMP, /* PI2, OR, NLIMP */
 NPI1, /* PI2, OR, NPI1 */
 NIMP, /* PI2, OR, NIMP */
 NPI2, /* PI2, OR, NPI2 */
 XOR, /* PI2, OR, XOR */
 NAND, /* PI2, OR, NAND */
 AND, /* PI2, OR, AND */
 BIIMP, /* PI2, OR, BIIMP */
 IMP, /* PI2, OR, IMP */
 LIMP, /* PI2, OR, LIMP */
 OR, /* PI2, OR, OR */
 K1, /* PI2, OR, K1 */
 K0, /* PI2, K1, K0 */
 PI1, /* PI2, K1, PI1 */
 PI2, /* PI2, K1, PI2 */
 NOR, /* PI2, K1, NOR */
 NLIMP, /* PI2, K1, NLIMP */
 NPI1, /* PI2, K1, NPI1 */
 NIMP, /* PI2, K1, NIMP */
 NPI2, /* PI2, K1, NPI2 */
 XOR, /* PI2, K1, XOR */
 NAND, /* PI2, K1, NAND */
 AND, /* PI2, K1, AND */
 BIIMP, /* PI2, K1, BIIMP */
 IMP, /* PI2, K1, IMP */
 LIMP, /* PI2, K1, LIMP */
 OR, /* PI2, K1, OR */
 K1, /* PI2, K1, K1 */
 K1, /* NOR, K0, K0 */
 NPI1, /* NOR, K0, PI1 */
 NPI2, /* NOR, K0, PI2 */
 OR, /* NOR, K0, NOR */
 LIMP, /* NOR, K0, NLIMP */
 PI1, /* NOR, K0, NPI1 */
 IMP, /* NOR, K0, NIMP */
 PI2, /* NOR, K0, NPI2 */
 BIIMP, /* NOR, K0, XOR */
 AND, /* NOR, K0, NAND */
 NAND, /* NOR, K0, AND */
 XOR, /* NOR, K0, BIIMP */
 NIMP, /* NOR, K0, IMP */
 NLIMP, /* NOR, K0, LIMP */
 NOR, /* NOR, K0, OR */
 K0, /* NOR, K0, K1 */
 NPI1, /* NOR, PI1, K0 */
 NPI1, /* NOR, PI1, PI1 */
 NOR, /* NOR, PI1, PI2 */
 NLIMP, /* NOR, PI1, NOR */
 NOR, /* NOR, PI1, NLIMP */
 K0, /* NOR, PI1, NPI1 */
 NPI1, /* NOR, PI1, NIMP */
 NLIMP, /* NOR, PI1, NPI2 */
 NOR, /* NOR, PI1, XOR */
 K0, /* NOR, PI1, NAND */
 NPI1, /* NOR, PI1, AND */
 NLIMP, /* NOR, PI1, BIIMP */
 K0, /* NOR, PI1, IMP */
 NLIMP, /* NOR, PI1, LIMP */
 NOR, /* NOR, PI1, OR */
 K0, /* NOR, PI1, K1 */
 NPI2, /* NOR, PI2, K0 */
 NOR, /* NOR, PI2, PI1 */
 NPI2, /* NOR, PI2, PI2 */
 NIMP, /* NOR, PI2, NOR */
 NPI2, /* NOR, PI2, NLIMP */
 NIMP, /* NOR, PI2, NPI1 */
 NOR, /* NOR, PI2, NIMP */
 K0, /* NOR, PI2, NPI2 */
 NOR, /* NOR, PI2, XOR */
 K0, /* NOR, PI2, NAND */
 NPI2, /* NOR, PI2, AND */
 NIMP, /* NOR, PI2, BIIMP */
 NIMP, /* NOR, PI2, IMP */
 K0, /* NOR, PI2, LIMP */
 NOR, /* NOR, PI2, OR */
 K0, /* NOR, PI2, K1 */
 OR, /* NOR, NOR, K0 */
 NLIMP, /* NOR, NOR, PI1 */
 NIMP, /* NOR, NOR, PI2 */
 OR, /* NOR, NOR, NOR */
 PI1, /* NOR, NOR, NLIMP */
 PI1, /* NOR, NOR, NPI1 */
 PI2, /* NOR, NOR, NIMP */
 PI2, /* NOR, NOR, NPI2 */
 AND, /* NOR, NOR, XOR */
 AND, /* NOR, NOR, NAND */
 XOR, /* NOR, NOR, AND */
 XOR, /* NOR, NOR, BIIMP */
 NIMP, /* NOR, NOR, IMP */
 NLIMP, /* NOR, NOR, LIMP */
 K0, /* NOR, NOR, OR */
 K0, /* NOR, NOR, K1 */
 LIMP, /* NOR, NLIMP, K0 */
 NOR, /* NOR, NLIMP, PI1 */
 NPI2, /* NOR, NLIMP, PI2 */
 PI1, /* NOR, NLIMP, NOR */
 LIMP, /* NOR, NLIMP, NLIMP */
 PI1, /* NOR, NLIMP, NPI1 */
 BIIMP, /* NOR, NLIMP, NIMP */
 AND, /* NOR, NLIMP, NPI2 */
 BIIMP, /* NOR, NLIMP, XOR */
 AND, /* NOR, NLIMP, NAND */
 NPI2, /* NOR, NLIMP, AND */
 NIMP, /* NOR, NLIMP, BIIMP */
 NIMP, /* NOR, NLIMP, IMP */
 K0, /* NOR, NLIMP, LIMP */
 NOR, /* NOR, NLIMP, OR */
 K0, /* NOR, NLIMP, K1 */
 PI1, /* NOR, NPI1, K0 */
 K0, /* NOR, NPI1, PI1 */
 NIMP, /* NOR, NPI1, PI2 */
 PI1, /* NOR, NPI1, NOR */
 PI1, /* NOR, NPI1, NLIMP */
 PI1, /* NOR, NPI1, NPI1 */
 AND, /* NOR, NPI1, NIMP */
 AND, /* NOR, NPI1, NPI2 */
 AND, /* NOR, NPI1, XOR */
 AND, /* NOR, NPI1, NAND */
 NIMP, /* NOR, NPI1, AND */
 NIMP, /* NOR, NPI1, BIIMP */
 NIMP, /* NOR, NPI1, IMP */
 K0, /* NOR, NPI1, LIMP */
 K0, /* NOR, NPI1, OR */
 K0, /* NOR, NPI1, K1 */
 IMP, /* NOR, NIMP, K0 */
 NPI1, /* NOR, NIMP, PI1 */
 NOR, /* NOR, NIMP, PI2 */
 PI2, /* NOR, NIMP, NOR */
 BIIMP, /* NOR, NIMP, NLIMP */
 AND, /* NOR, NIMP, NPI1 */
 IMP, /* NOR, NIMP, NIMP */
 PI2, /* NOR, NIMP, NPI2 */
 BIIMP, /* NOR, NIMP, XOR */
 AND, /* NOR, NIMP, NAND */
 NPI1, /* NOR, NIMP, AND */
 NLIMP, /* NOR, NIMP, BIIMP */
 K0, /* NOR, NIMP, IMP */
 NLIMP, /* NOR, NIMP, LIMP */
 NOR, /* NOR, NIMP, OR */
 K0, /* NOR, NIMP, K1 */
 PI2, /* NOR, NPI2, K0 */
 NLIMP, /* NOR, NPI2, PI1 */
 K0, /* NOR, NPI2, PI2 */
 PI2, /* NOR, NPI2, NOR */
 AND, /* NOR, NPI2, NLIMP */
 AND, /* NOR, NPI2, NPI1 */
 PI2, /* NOR, NPI2, NIMP */
 PI2, /* NOR, NPI2, NPI2 */
 AND, /* NOR, NPI2, XOR */
 AND, /* NOR, NPI2, NAND */
 NLIMP, /* NOR, NPI2, AND */
 NLIMP, /* NOR, NPI2, BIIMP */
 K0, /* NOR, NPI2, IMP */
 NLIMP, /* NOR, NPI2, LIMP */
 K0, /* NOR, NPI2, OR */
 K0, /* NOR, NPI2, K1 */
 BIIMP, /* NOR, XOR, K0 */
 NOR, /* NOR, XOR, PI1 */
 NOR, /* NOR, XOR, PI2 */
 AND, /* NOR, XOR, NOR */
 BIIMP, /* NOR, XOR, NLIMP */
 AND, /* NOR, XOR, NPI1 */
 BIIMP, /* NOR, XOR, NIMP */
 AND, /* NOR, XOR, NPI2 */
 BIIMP, /* NOR, XOR, XOR */
 AND, /* NOR, XOR, NAND */
 NOR, /* NOR, XOR, AND */
 K0, /* NOR, XOR, BIIMP */
 K0, /* NOR, XOR, IMP */
 K0, /* NOR, XOR, LIMP */
 NOR, /* NOR, XOR, OR */
 K0, /* NOR, XOR, K1 */
 AND, /* NOR, NAND, K0 */
 K0, /* NOR, NAND, PI1 */
 K0, /* NOR, NAND, PI2 */
 AND, /* NOR, NAND, NOR */
 AND, /* NOR, NAND, NLIMP */
 AND, /* NOR, NAND, NPI1 */
 AND, /* NOR, NAND, NIMP */
 AND, /* NOR, NAND, NPI2 */
 AND, /* NOR, NAND, XOR */
 AND, /* NOR, NAND, NAND */
 K0, /* NOR, NAND, AND */
 K0, /* NOR, NAND, BIIMP */
 K0, /* NOR, NAND, IMP */
 K0, /* NOR, NAND, LIMP */
 K0, /* NOR, NAND, OR */
 K0, /* NOR, NAND, K1 */
 NAND, /* NOR, AND, K0 */
 NPI1, /* NOR, AND, PI1 */
 NPI2, /* NOR, AND, PI2 */
 XOR, /* NOR, AND, NOR */
 NPI2, /* NOR, AND, NLIMP */
 NIMP, /* NOR, AND, NPI1 */
 NPI1, /* NOR, AND, NIMP */
 NLIMP, /* NOR, AND, NPI2 */
 NOR, /* NOR, AND, XOR */
 K0, /* NOR, AND, NAND */
 NAND, /* NOR, AND, AND */
 XOR, /* NOR, AND, BIIMP */
 NIMP, /* NOR, AND, IMP */
 NLIMP, /* NOR, AND, LIMP */
 NOR, /* NOR, AND, OR */
 K0, /* NOR, AND, K1 */
 XOR, /* NOR, BIIMP, K0 */
 NLIMP, /* NOR, BIIMP, PI1 */
 NIMP, /* NOR, BIIMP, PI2 */
 XOR, /* NOR, BIIMP, NOR */
 NIMP, /* NOR, BIIMP, NLIMP */
 NIMP, /* NOR, BIIMP, NPI1 */
 NLIMP, /* NOR, BIIMP, NIMP */
 NLIMP, /* NOR, BIIMP, NPI2 */
 K0, /* NOR, BIIMP, XOR */
 K0, /* NOR, BIIMP, NAND */
 XOR, /* NOR, BIIMP, AND */
 XOR, /* NOR, BIIMP, BIIMP */
 NIMP, /* NOR, BIIMP, IMP */
 NLIMP, /* NOR, BIIMP, LIMP */
 K0, /* NOR, BIIMP, OR */
 K0, /* NOR, BIIMP, K1 */
 NIMP, /* NOR, IMP, K0 */
 K0, /* NOR, IMP, PI1 */
 NIMP, /* NOR, IMP, PI2 */
 NIMP, /* NOR, IMP, NOR */
 NIMP, /* NOR, IMP, NLIMP */
 NIMP, /* NOR, IMP, NPI1 */
 K0, /* NOR, IMP, NIMP */
 K0, /* NOR, IMP, NPI2 */
 K0, /* NOR, IMP, XOR */
 K0, /* NOR, IMP, NAND */
 NIMP, /* NOR, IMP, AND */
 NIMP, /* NOR, IMP, BIIMP */
 NIMP, /* NOR, IMP, IMP */
 K0, /* NOR, IMP, LIMP */
 K0, /* NOR, IMP, OR */
 K0, /* NOR, IMP, K1 */
 NLIMP, /* NOR, LIMP, K0 */
 NLIMP, /* NOR, LIMP, PI1 */
 K0, /* NOR, LIMP, PI2 */
 NLIMP, /* NOR, LIMP, NOR */
 K0, /* NOR, LIMP, NLIMP */
 K0, /* NOR, LIMP, NPI1 */
 NLIMP, /* NOR, LIMP, NIMP */
 NLIMP, /* NOR, LIMP, NPI2 */
 K0, /* NOR, LIMP, XOR */
 K0, /* NOR, LIMP, NAND */
 NLIMP, /* NOR, LIMP, AND */
 NLIMP, /* NOR, LIMP, BIIMP */
 K0, /* NOR, LIMP, IMP */
 NLIMP, /* NOR, LIMP, LIMP */
 K0, /* NOR, LIMP, OR */
 K0, /* NOR, LIMP, K1 */
 NOR, /* NOR, OR, K0 */
 NOR, /* NOR, OR, PI1 */
 NOR, /* NOR, OR, PI2 */
 K0, /* NOR, OR, NOR */
 NOR, /* NOR, OR, NLIMP */
 K0, /* NOR, OR, NPI1 */
 NOR, /* NOR, OR, NIMP */
 K0, /* NOR, OR, NPI2 */
 NOR, /* NOR, OR, XOR */
 K0, /* NOR, OR, NAND */
 NOR, /* NOR, OR, AND */
 K0, /* NOR, OR, BIIMP */
 K0, /* NOR, OR, IMP */
 K0, /* NOR, OR, LIMP */
 NOR, /* NOR, OR, OR */
 K0, /* NOR, OR, K1 */
 K0, /* NOR, K1, K0 */
 K0, /* NOR, K1, PI1 */
 K0, /* NOR, K1, PI2 */
 K0, /* NOR, K1, NOR */
 K0, /* NOR, K1, NLIMP */
 K0, /* NOR, K1, NPI1 */
 K0, /* NOR, K1, NIMP */
 K0, /* NOR, K1, NPI2 */
 K0, /* NOR, K1, XOR */
 K0, /* NOR, K1, NAND */
 K0, /* NOR, K1, AND */
 K0, /* NOR, K1, BIIMP */
 K0, /* NOR, K1, IMP */
 K0, /* NOR, K1, LIMP */
 K0, /* NOR, K1, OR */
 K0, /* NOR, K1, K1 */
 K0, /* NLIMP, K0, K0 */
 PI1, /* NLIMP, K0, PI1 */
 PI2, /* NLIMP, K0, PI2 */
 NOR, /* NLIMP, K0, NOR */
 NLIMP, /* NLIMP, K0, NLIMP */
 NPI1, /* NLIMP, K0, NPI1 */
 NIMP, /* NLIMP, K0, NIMP */
 NPI2, /* NLIMP, K0, NPI2 */
 XOR, /* NLIMP, K0, XOR */
 NAND, /* NLIMP, K0, NAND */
 AND, /* NLIMP, K0, AND */
 BIIMP, /* NLIMP, K0, BIIMP */
 IMP, /* NLIMP, K0, IMP */
 LIMP, /* NLIMP, K0, LIMP */
 OR, /* NLIMP, K0, OR */
 K1, /* NLIMP, K0, K1 */
 K0, /* NLIMP, PI1, K0 */
 K0, /* NLIMP, PI1, PI1 */
 NLIMP, /* NLIMP, PI1, PI2 */
 NOR, /* NLIMP, PI1, NOR */
 NLIMP, /* NLIMP, PI1, NLIMP */
 NPI1, /* NLIMP, PI1, NPI1 */
 K0, /* NLIMP, PI1, NIMP */
 NOR, /* NLIMP, PI1, NPI2 */
 NLIMP, /* NLIMP, PI1, XOR */
 NPI1, /* NLIMP, PI1, NAND */
 K0, /* NLIMP, PI1, AND */
 NOR, /* NLIMP, PI1, BIIMP */
 NPI1, /* NLIMP, PI1, IMP */
 NOR, /* NLIMP, PI1, LIMP */
 NLIMP, /* NLIMP, PI1, OR */
 NPI1, /* NLIMP, PI1, K1 */
 K0, /* NLIMP, PI2, K0 */
 NIMP, /* NLIMP, PI2, PI1 */
 K0, /* NLIMP, PI2, PI2 */
 NOR, /* NLIMP, PI2, NOR */
 K0, /* NLIMP, PI2, NLIMP */
 NOR, /* NLIMP, PI2, NPI1 */
 NIMP, /* NLIMP, PI2, NIMP */
 NPI2, /* NLIMP, PI2, NPI2 */
 NIMP, /* NLIMP, PI2, XOR */
 NPI2, /* NLIMP, PI2, NAND */
 K0, /* NLIMP, PI2, AND */
 NOR, /* NLIMP, PI2, BIIMP */
 NOR, /* NLIMP, PI2, IMP */
 NPI2, /* NLIMP, PI2, LIMP */
 NIMP, /* NLIMP, PI2, OR */
 NPI2, /* NLIMP, PI2, K1 */
 K0, /* NLIMP, NOR, K0 */
 PI1, /* NLIMP, NOR, PI1 */
 PI2, /* NLIMP, NOR, PI2 */
 K0, /* NLIMP, NOR, NOR */
 NLIMP, /* NLIMP, NOR, NLIMP */
 NLIMP, /* NLIMP, NOR, NPI1 */
 NIMP, /* NLIMP, NOR, NIMP */
 NIMP, /* NLIMP, NOR, NPI2 */
 XOR, /* NLIMP, NOR, XOR */
 XOR, /* NLIMP, NOR, NAND */
 AND, /* NLIMP, NOR, AND */
 AND, /* NLIMP, NOR, BIIMP */
 PI2, /* NLIMP, NOR, IMP */
 PI1, /* NLIMP, NOR, LIMP */
 OR, /* NLIMP, NOR, OR */
 OR, /* NLIMP, NOR, K1 */
 K0, /* NLIMP, NLIMP, K0 */
 PI1, /* NLIMP, NLIMP, PI1 */
 AND, /* NLIMP, NLIMP, PI2 */
 NOR, /* NLIMP, NLIMP, NOR */
 K0, /* NLIMP, NLIMP, NLIMP */
 NOR, /* NLIMP, NLIMP, NPI1 */
 NIMP, /* NLIMP, NLIMP, NIMP */
 NPI2, /* NLIMP, NLIMP, NPI2 */
 NIMP, /* NLIMP, NLIMP, XOR */
 NPI2, /* NLIMP, NLIMP, NAND */
 AND, /* NLIMP, NLIMP, AND */
 BIIMP, /* NLIMP, NLIMP, BIIMP */
 BIIMP, /* NLIMP, NLIMP, IMP */
 LIMP, /* NLIMP, NLIMP, LIMP */
 PI1, /* NLIMP, NLIMP, OR */
 LIMP, /* NLIMP, NLIMP, K1 */
 K0, /* NLIMP, NPI1, K0 */
 PI1, /* NLIMP, NPI1, PI1 */
 AND, /* NLIMP, NPI1, PI2 */
 K0, /* NLIMP, NPI1, NOR */
 K0, /* NLIMP, NPI1, NLIMP */
 K0, /* NLIMP, NPI1, NPI1 */
 NIMP, /* NLIMP, NPI1, NIMP */
 NIMP, /* NLIMP, NPI1, NPI2 */
 NIMP, /* NLIMP, NPI1, XOR */
 NIMP, /* NLIMP, NPI1, NAND */
 AND, /* NLIMP, NPI1, AND */
 AND, /* NLIMP, NPI1, BIIMP */
 AND, /* NLIMP, NPI1, IMP */
 PI1, /* NLIMP, NPI1, LIMP */
 PI1, /* NLIMP, NPI1, OR */
 PI1, /* NLIMP, NPI1, K1 */
 K0, /* NLIMP, NIMP, K0 */
 AND, /* NLIMP, NIMP, PI1 */
 PI2, /* NLIMP, NIMP, PI2 */
 NOR, /* NLIMP, NIMP, NOR */
 NLIMP, /* NLIMP, NIMP, NLIMP */
 NPI1, /* NLIMP, NIMP, NPI1 */
 K0, /* NLIMP, NIMP, NIMP */
 NOR, /* NLIMP, NIMP, NPI2 */
 NLIMP, /* NLIMP, NIMP, XOR */
 NPI1, /* NLIMP, NIMP, NAND */
 AND, /* NLIMP, NIMP, AND */
 BIIMP, /* NLIMP, NIMP, BIIMP */
 IMP, /* NLIMP, NIMP, IMP */
 BIIMP, /* NLIMP, NIMP, LIMP */
 PI2, /* NLIMP, NIMP, OR */
 IMP, /* NLIMP, NIMP, K1 */
 K0, /* NLIMP, NPI2, K0 */
 AND, /* NLIMP, NPI2, PI1 */
 PI2, /* NLIMP, NPI2, PI2 */
 K0, /* NLIMP, NPI2, NOR */
 NLIMP, /* NLIMP, NPI2, NLIMP */
 NLIMP, /* NLIMP, NPI2, NPI1 */
 K0, /* NLIMP, NPI2, NIMP */
 K0, /* NLIMP, NPI2, NPI2 */
 NLIMP, /* NLIMP, NPI2, XOR */
 NLIMP, /* NLIMP, NPI2, NAND */
 AND, /* NLIMP, NPI2, AND */
 AND, /* NLIMP, NPI2, BIIMP */
 PI2, /* NLIMP, NPI2, IMP */
 AND, /* NLIMP, NPI2, LIMP */
 PI2, /* NLIMP, NPI2, OR */
 PI2, /* NLIMP, NPI2, K1 */
 K0, /* NLIMP, XOR, K0 */
 AND, /* NLIMP, XOR, PI1 */
 AND, /* NLIMP, XOR, PI2 */
 NOR, /* NLIMP, XOR, NOR */
 K0, /* NLIMP, XOR, NLIMP */
 NOR, /* NLIMP, XOR, NPI1 */
 K0, /* NLIMP, XOR, NIMP */
 NOR, /* NLIMP, XOR, NPI2 */
 K0, /* NLIMP, XOR, XOR */
 NOR, /* NLIMP, XOR, NAND */
 AND, /* NLIMP, XOR, AND */
 BIIMP, /* NLIMP, XOR, BIIMP */
 BIIMP, /* NLIMP, XOR, IMP */
 BIIMP, /* NLIMP, XOR, LIMP */
 AND, /* NLIMP, XOR, OR */
 BIIMP, /* NLIMP, XOR, K1 */
 K0, /* NLIMP, NAND, K0 */
 AND, /* NLIMP, NAND, PI1 */
 AND, /* NLIMP, NAND, PI2 */
 K0, /* NLIMP, NAND, NOR */
 K0, /* NLIMP, NAND, NLIMP */
 K0, /* NLIMP, NAND, NPI1 */
 K0, /* NLIMP, NAND, NIMP */
 K0, /* NLIMP, NAND, NPI2 */
 K0, /* NLIMP, NAND, XOR */
 K0, /* NLIMP, NAND, NAND */
 AND, /* NLIMP, NAND, AND */
 AND, /* NLIMP, NAND, BIIMP */
 AND, /* NLIMP, NAND, IMP */
 AND, /* NLIMP, NAND, LIMP */
 AND, /* NLIMP, NAND, OR */
 AND, /* NLIMP, NAND, K1 */
 K0, /* NLIMP, AND, K0 */
 NIMP, /* NLIMP, AND, PI1 */
 NLIMP, /* NLIMP, AND, PI2 */
 NOR, /* NLIMP, AND, NOR */
 NLIMP, /* NLIMP, AND, NLIMP */
 NPI1, /* NLIMP, AND, NPI1 */
 NIMP, /* NLIMP, AND, NIMP */
 NPI2, /* NLIMP, AND, NPI2 */
 XOR, /* NLIMP, AND, XOR */
 NAND, /* NLIMP, AND, NAND */
 K0, /* NLIMP, AND, AND */
 NOR, /* NLIMP, AND, BIIMP */
 NPI1, /* NLIMP, AND, IMP */
 NPI2, /* NLIMP, AND, LIMP */
 XOR, /* NLIMP, AND, OR */
 NAND, /* NLIMP, AND, K1 */
 K0, /* NLIMP, BIIMP, K0 */
 NIMP, /* NLIMP, BIIMP, PI1 */
 NLIMP, /* NLIMP, BIIMP, PI2 */
 K0, /* NLIMP, BIIMP, NOR */
 NLIMP, /* NLIMP, BIIMP, NLIMP */
 NLIMP, /* NLIMP, BIIMP, NPI1 */
 NIMP, /* NLIMP, BIIMP, NIMP */
 NIMP, /* NLIMP, BIIMP, NPI2 */
 XOR, /* NLIMP, BIIMP, XOR */
 XOR, /* NLIMP, BIIMP, NAND */
 K0, /* NLIMP, BIIMP, AND */
 K0, /* NLIMP, BIIMP, BIIMP */
 NLIMP, /* NLIMP, BIIMP, IMP */
 NIMP, /* NLIMP, BIIMP, LIMP */
 XOR, /* NLIMP, BIIMP, OR */
 XOR, /* NLIMP, BIIMP, K1 */
 K0, /* NLIMP, IMP, K0 */
 NIMP, /* NLIMP, IMP, PI1 */
 K0, /* NLIMP, IMP, PI2 */
 K0, /* NLIMP, IMP, NOR */
 K0, /* NLIMP, IMP, NLIMP */
 K0, /* NLIMP, IMP, NPI1 */
 NIMP, /* NLIMP, IMP, NIMP */
 NIMP, /* NLIMP, IMP, NPI2 */
 NIMP, /* NLIMP, IMP, XOR */
 NIMP, /* NLIMP, IMP, NAND */
 K0, /* NLIMP, IMP, AND */
 K0, /* NLIMP, IMP, BIIMP */
 K0, /* NLIMP, IMP, IMP */
 NIMP, /* NLIMP, IMP, LIMP */
 NIMP, /* NLIMP, IMP, OR */
 NIMP, /* NLIMP, IMP, K1 */
 K0, /* NLIMP, LIMP, K0 */
 K0, /* NLIMP, LIMP, PI1 */
 NLIMP, /* NLIMP, LIMP, PI2 */
 K0, /* NLIMP, LIMP, NOR */
 NLIMP, /* NLIMP, LIMP, NLIMP */
 NLIMP, /* NLIMP, LIMP, NPI1 */
 K0, /* NLIMP, LIMP, NIMP */
 K0, /* NLIMP, LIMP, NPI2 */
 NLIMP, /* NLIMP, LIMP, XOR */
 NLIMP, /* NLIMP, LIMP, NAND */
 K0, /* NLIMP, LIMP, AND */
 K0, /* NLIMP, LIMP, BIIMP */
 NLIMP, /* NLIMP, LIMP, IMP */
 K0, /* NLIMP, LIMP, LIMP */
 NLIMP, /* NLIMP, LIMP, OR */
 NLIMP, /* NLIMP, LIMP, K1 */
 K0, /* NLIMP, OR, K0 */
 K0, /* NLIMP, OR, PI1 */
 K0, /* NLIMP, OR, PI2 */
 NOR, /* NLIMP, OR, NOR */
 K0, /* NLIMP, OR, NLIMP */
 NOR, /* NLIMP, OR, NPI1 */
 K0, /* NLIMP, OR, NIMP */
 NOR, /* NLIMP, OR, NPI2 */
 K0, /* NLIMP, OR, XOR */
 NOR, /* NLIMP, OR, NAND */
 K0, /* NLIMP, OR, AND */
 NOR, /* NLIMP, OR, BIIMP */
 NOR, /* NLIMP, OR, IMP */
 NOR, /* NLIMP, OR, LIMP */
 K0, /* NLIMP, OR, OR */
 NOR, /* NLIMP, OR, K1 */
 K0, /* NLIMP, K1, K0 */
 K0, /* NLIMP, K1, PI1 */
 K0, /* NLIMP, K1, PI2 */
 K0, /* NLIMP, K1, NOR */
 K0, /* NLIMP, K1, NLIMP */
 K0, /* NLIMP, K1, NPI1 */
 K0, /* NLIMP, K1, NIMP */
 K0, /* NLIMP, K1, NPI2 */
 K0, /* NLIMP, K1, XOR */
 K0, /* NLIMP, K1, NAND */
 K0, /* NLIMP, K1, AND */
 K0, /* NLIMP, K1, BIIMP */
 K0, /* NLIMP, K1, IMP */
 K0, /* NLIMP, K1, LIMP */
 K0, /* NLIMP, K1, OR */
 K0, /* NLIMP, K1, K1 */
 K1, /* NPI1, K0, K0 */
 K1, /* NPI1, K0, PI1 */
 K1, /* NPI1, K0, PI2 */
 K1, /* NPI1, K0, NOR */
 K1, /* NPI1, K0, NLIMP */
 K1, /* NPI1, K0, NPI1 */
 K1, /* NPI1, K0, NIMP */
 K1, /* NPI1, K0, NPI2 */
 K1, /* NPI1, K0, XOR */
 K1, /* NPI1, K0, NAND */
 K1, /* NPI1, K0, AND */
 K1, /* NPI1, K0, BIIMP */
 K1, /* NPI1, K0, IMP */
 K1, /* NPI1, K0, LIMP */
 K1, /* NPI1, K0, OR */
 K1, /* NPI1, K0, K1 */
 NPI1, /* NPI1, PI1, K0 */
 NPI1, /* NPI1, PI1, PI1 */
 NPI1, /* NPI1, PI1, PI2 */
 NPI1, /* NPI1, PI1, NOR */
 NPI1, /* NPI1, PI1, NLIMP */
 NPI1, /* NPI1, PI1, NPI1 */
 NPI1, /* NPI1, PI1, NIMP */
 NPI1, /* NPI1, PI1, NPI2 */
 NPI1, /* NPI1, PI1, XOR */
 NPI1, /* NPI1, PI1, NAND */
 NPI1, /* NPI1, PI1, AND */
 NPI1, /* NPI1, PI1, BIIMP */
 NPI1, /* NPI1, PI1, IMP */
 NPI1, /* NPI1, PI1, LIMP */
 NPI1, /* NPI1, PI1, OR */
 NPI1, /* NPI1, PI1, K1 */
 NPI2, /* NPI1, PI2, K0 */
 NPI2, /* NPI1, PI2, PI1 */
 NPI2, /* NPI1, PI2, PI2 */
 NPI2, /* NPI1, PI2, NOR */
 NPI2, /* NPI1, PI2, NLIMP */
 NPI2, /* NPI1, PI2, NPI1 */
 NPI2, /* NPI1, PI2, NIMP */
 NPI2, /* NPI1, PI2, NPI2 */
 NPI2, /* NPI1, PI2, XOR */
 NPI2, /* NPI1, PI2, NAND */
 NPI2, /* NPI1, PI2, AND */
 NPI2, /* NPI1, PI2, BIIMP */
 NPI2, /* NPI1, PI2, IMP */
 NPI2, /* NPI1, PI2, LIMP */
 NPI2, /* NPI1, PI2, OR */
 NPI2, /* NPI1, PI2, K1 */
 OR, /* NPI1, NOR, K0 */
 OR, /* NPI1, NOR, PI1 */
 OR, /* NPI1, NOR, PI2 */
 OR, /* NPI1, NOR, NOR */
 OR, /* NPI1, NOR, NLIMP */
 OR, /* NPI1, NOR, NPI1 */
 OR, /* NPI1, NOR, NIMP */
 OR, /* NPI1, NOR, NPI2 */
 OR, /* NPI1, NOR, XOR */
 OR, /* NPI1, NOR, NAND */
 OR, /* NPI1, NOR, AND */
 OR, /* NPI1, NOR, BIIMP */
 OR, /* NPI1, NOR, IMP */
 OR, /* NPI1, NOR, LIMP */
 OR, /* NPI1, NOR, OR */
 OR, /* NPI1, NOR, K1 */
 LIMP, /* NPI1, NLIMP, K0 */
 LIMP, /* NPI1, NLIMP, PI1 */
 LIMP, /* NPI1, NLIMP, PI2 */
 LIMP, /* NPI1, NLIMP, NOR */
 LIMP, /* NPI1, NLIMP, NLIMP */
 LIMP, /* NPI1, NLIMP, NPI1 */
 LIMP, /* NPI1, NLIMP, NIMP */
 LIMP, /* NPI1, NLIMP, NPI2 */
 LIMP, /* NPI1, NLIMP, XOR */
 LIMP, /* NPI1, NLIMP, NAND */
 LIMP, /* NPI1, NLIMP, AND */
 LIMP, /* NPI1, NLIMP, BIIMP */
 LIMP, /* NPI1, NLIMP, IMP */
 LIMP, /* NPI1, NLIMP, LIMP */
 LIMP, /* NPI1, NLIMP, OR */
 LIMP, /* NPI1, NLIMP, K1 */
 PI1, /* NPI1, NPI1, K0 */
 PI1, /* NPI1, NPI1, PI1 */
 PI1, /* NPI1, NPI1, PI2 */
 PI1, /* NPI1, NPI1, NOR */
 PI1, /* NPI1, NPI1, NLIMP */
 PI1, /* NPI1, NPI1, NPI1 */
 PI1, /* NPI1, NPI1, NIMP */
 PI1, /* NPI1, NPI1, NPI2 */
 PI1, /* NPI1, NPI1, XOR */
 PI1, /* NPI1, NPI1, NAND */
 PI1, /* NPI1, NPI1, AND */
 PI1, /* NPI1, NPI1, BIIMP */
 PI1, /* NPI1, NPI1, IMP */
 PI1, /* NPI1, NPI1, LIMP */
 PI1, /* NPI1, NPI1, OR */
 PI1, /* NPI1, NPI1, K1 */
 IMP, /* NPI1, NIMP, K0 */
 IMP, /* NPI1, NIMP, PI1 */
 IMP, /* NPI1, NIMP, PI2 */
 IMP, /* NPI1, NIMP, NOR */
 IMP, /* NPI1, NIMP, NLIMP */
 IMP, /* NPI1, NIMP, NPI1 */
 IMP, /* NPI1, NIMP, NIMP */
 IMP, /* NPI1, NIMP, NPI2 */
 IMP, /* NPI1, NIMP, XOR */
 IMP, /* NPI1, NIMP, NAND */
 IMP, /* NPI1, NIMP, AND */
 IMP, /* NPI1, NIMP, BIIMP */
 IMP, /* NPI1, NIMP, IMP */
 IMP, /* NPI1, NIMP, LIMP */
 IMP, /* NPI1, NIMP, OR */
 IMP, /* NPI1, NIMP, K1 */
 PI2, /* NPI1, NPI2, K0 */
 PI2, /* NPI1, NPI2, PI1 */
 PI2, /* NPI1, NPI2, PI2 */
 PI2, /* NPI1, NPI2, NOR */
 PI2, /* NPI1, NPI2, NLIMP */
 PI2, /* NPI1, NPI2, NPI1 */
 PI2, /* NPI1, NPI2, NIMP */
 PI2, /* NPI1, NPI2, NPI2 */
 PI2, /* NPI1, NPI2, XOR */
 PI2, /* NPI1, NPI2, NAND */
 PI2, /* NPI1, NPI2, AND */
 PI2, /* NPI1, NPI2, BIIMP */
 PI2, /* NPI1, NPI2, IMP */
 PI2, /* NPI1, NPI2, LIMP */
 PI2, /* NPI1, NPI2, OR */
 PI2, /* NPI1, NPI2, K1 */
 BIIMP, /* NPI1, XOR, K0 */
 BIIMP, /* NPI1, XOR, PI1 */
 BIIMP, /* NPI1, XOR, PI2 */
 BIIMP, /* NPI1, XOR, NOR */
 BIIMP, /* NPI1, XOR, NLIMP */
 BIIMP, /* NPI1, XOR, NPI1 */
 BIIMP, /* NPI1, XOR, NIMP */
 BIIMP, /* NPI1, XOR, NPI2 */
 BIIMP, /* NPI1, XOR, XOR */
 BIIMP, /* NPI1, XOR, NAND */
 BIIMP, /* NPI1, XOR, AND */
 BIIMP, /* NPI1, XOR, BIIMP */
 BIIMP, /* NPI1, XOR, IMP */
 BIIMP, /* NPI1, XOR, LIMP */
 BIIMP, /* NPI1, XOR, OR */
 BIIMP, /* NPI1, XOR, K1 */
 AND, /* NPI1, NAND, K0 */
 AND, /* NPI1, NAND, PI1 */
 AND, /* NPI1, NAND, PI2 */
 AND, /* NPI1, NAND, NOR */
 AND, /* NPI1, NAND, NLIMP */
 AND, /* NPI1, NAND, NPI1 */
 AND, /* NPI1, NAND, NIMP */
 AND, /* NPI1, NAND, NPI2 */
 AND, /* NPI1, NAND, XOR */
 AND, /* NPI1, NAND, NAND */
 AND, /* NPI1, NAND, AND */
 AND, /* NPI1, NAND, BIIMP */
 AND, /* NPI1, NAND, IMP */
 AND, /* NPI1, NAND, LIMP */
 AND, /* NPI1, NAND, OR */
 AND, /* NPI1, NAND, K1 */
 NAND, /* NPI1, AND, K0 */
 NAND, /* NPI1, AND, PI1 */
 NAND, /* NPI1, AND, PI2 */
 NAND, /* NPI1, AND, NOR */
 NAND, /* NPI1, AND, NLIMP */
 NAND, /* NPI1, AND, NPI1 */
 NAND, /* NPI1, AND, NIMP */
 NAND, /* NPI1, AND, NPI2 */
 NAND, /* NPI1, AND, XOR */
 NAND, /* NPI1, AND, NAND */
 NAND, /* NPI1, AND, AND */
 NAND, /* NPI1, AND, BIIMP */
 NAND, /* NPI1, AND, IMP */
 NAND, /* NPI1, AND, LIMP */
 NAND, /* NPI1, AND, OR */
 NAND, /* NPI1, AND, K1 */
 XOR, /* NPI1, BIIMP, K0 */
 XOR, /* NPI1, BIIMP, PI1 */
 XOR, /* NPI1, BIIMP, PI2 */
 XOR, /* NPI1, BIIMP, NOR */
 XOR, /* NPI1, BIIMP, NLIMP */
 XOR, /* NPI1, BIIMP, NPI1 */
 XOR, /* NPI1, BIIMP, NIMP */
 XOR, /* NPI1, BIIMP, NPI2 */
 XOR, /* NPI1, BIIMP, XOR */
 XOR, /* NPI1, BIIMP, NAND */
 XOR, /* NPI1, BIIMP, AND */
 XOR, /* NPI1, BIIMP, BIIMP */
 XOR, /* NPI1, BIIMP, IMP */
 XOR, /* NPI1, BIIMP, LIMP */
 XOR, /* NPI1, BIIMP, OR */
 XOR, /* NPI1, BIIMP, K1 */
 NIMP, /* NPI1, IMP, K0 */
 NIMP, /* NPI1, IMP, PI1 */
 NIMP, /* NPI1, IMP, PI2 */
 NIMP, /* NPI1, IMP, NOR */
 NIMP, /* NPI1, IMP, NLIMP */
 NIMP, /* NPI1, IMP, NPI1 */
 NIMP, /* NPI1, IMP, NIMP */
 NIMP, /* NPI1, IMP, NPI2 */
 NIMP, /* NPI1, IMP, XOR */
 NIMP, /* NPI1, IMP, NAND */
 NIMP, /* NPI1, IMP, AND */
 NIMP, /* NPI1, IMP, BIIMP */
 NIMP, /* NPI1, IMP, IMP */
 NIMP, /* NPI1, IMP, LIMP */
 NIMP, /* NPI1, IMP, OR */
 NIMP, /* NPI1, IMP, K1 */
 NLIMP, /* NPI1, LIMP, K0 */
 NLIMP, /* NPI1, LIMP, PI1 */
 NLIMP, /* NPI1, LIMP, PI2 */
 NLIMP, /* NPI1, LIMP, NOR */
 NLIMP, /* NPI1, LIMP, NLIMP */
 NLIMP, /* NPI1, LIMP, NPI1 */
 NLIMP, /* NPI1, LIMP, NIMP */
 NLIMP, /* NPI1, LIMP, NPI2 */
 NLIMP, /* NPI1, LIMP, XOR */
 NLIMP, /* NPI1, LIMP, NAND */
 NLIMP, /* NPI1, LIMP, AND */
 NLIMP, /* NPI1, LIMP, BIIMP */
 NLIMP, /* NPI1, LIMP, IMP */
 NLIMP, /* NPI1, LIMP, LIMP */
 NLIMP, /* NPI1, LIMP, OR */
 NLIMP, /* NPI1, LIMP, K1 */
 NOR, /* NPI1, OR, K0 */
 NOR, /* NPI1, OR, PI1 */
 NOR, /* NPI1, OR, PI2 */
 NOR, /* NPI1, OR, NOR */
 NOR, /* NPI1, OR, NLIMP */
 NOR, /* NPI1, OR, NPI1 */
 NOR, /* NPI1, OR, NIMP */
 NOR, /* NPI1, OR, NPI2 */
 NOR, /* NPI1, OR, XOR */
 NOR, /* NPI1, OR, NAND */
 NOR, /* NPI1, OR, AND */
 NOR, /* NPI1, OR, BIIMP */
 NOR, /* NPI1, OR, IMP */
 NOR, /* NPI1, OR, LIMP */
 NOR, /* NPI1, OR, OR */
 NOR, /* NPI1, OR, K1 */
 K0, /* NPI1, K1, K0 */
 K0, /* NPI1, K1, PI1 */
 K0, /* NPI1, K1, PI2 */
 K0, /* NPI1, K1, NOR */
 K0, /* NPI1, K1, NLIMP */
 K0, /* NPI1, K1, NPI1 */
 K0, /* NPI1, K1, NIMP */
 K0, /* NPI1, K1, NPI2 */
 K0, /* NPI1, K1, XOR */
 K0, /* NPI1, K1, NAND */
 K0, /* NPI1, K1, AND */
 K0, /* NPI1, K1, BIIMP */
 K0, /* NPI1, K1, IMP */
 K0, /* NPI1, K1, LIMP */
 K0, /* NPI1, K1, OR */
 K0, /* NPI1, K1, K1 */
 K0, /* NIMP, K0, K0 */
 K0, /* NIMP, K0, PI1 */
 K0, /* NIMP, K0, PI2 */
 K0, /* NIMP, K0, NOR */
 K0, /* NIMP, K0, NLIMP */
 K0, /* NIMP, K0, NPI1 */
 K0, /* NIMP, K0, NIMP */
 K0, /* NIMP, K0, NPI2 */
 K0, /* NIMP, K0, XOR */
 K0, /* NIMP, K0, NAND */
 K0, /* NIMP, K0, AND */
 K0, /* NIMP, K0, BIIMP */
 K0, /* NIMP, K0, IMP */
 K0, /* NIMP, K0, LIMP */
 K0, /* NIMP, K0, OR */
 K0, /* NIMP, K0, K1 */
 PI1, /* NIMP, PI1, K0 */
 K0, /* NIMP, PI1, PI1 */
 NIMP, /* NIMP, PI1, PI2 */
 PI1, /* NIMP, PI1, NOR */
 PI1, /* NIMP, PI1, NLIMP */
 PI1, /* NIMP, PI1, NPI1 */
 AND, /* NIMP, PI1, NIMP */
 AND, /* NIMP, PI1, NPI2 */
 AND, /* NIMP, PI1, XOR */
 AND, /* NIMP, PI1, NAND */
 NIMP, /* NIMP, PI1, AND */
 NIMP, /* NIMP, PI1, BIIMP */
 NIMP, /* NIMP, PI1, IMP */
 K0, /* NIMP, PI1, LIMP */
 K0, /* NIMP, PI1, OR */
 K0, /* NIMP, PI1, K1 */
 PI2, /* NIMP, PI2, K0 */
 NLIMP, /* NIMP, PI2, PI1 */
 K0, /* NIMP, PI2, PI2 */
 PI2, /* NIMP, PI2, NOR */
 AND, /* NIMP, PI2, NLIMP */
 AND, /* NIMP, PI2, NPI1 */
 PI2, /* NIMP, PI2, NIMP */
 PI2, /* NIMP, PI2, NPI2 */
 AND, /* NIMP, PI2, XOR */
 AND, /* NIMP, PI2, NAND */
 NLIMP, /* NIMP, PI2, AND */
 NLIMP, /* NIMP, PI2, BIIMP */
 K0, /* NIMP, PI2, IMP */
 NLIMP, /* NIMP, PI2, LIMP */
 K0, /* NIMP, PI2, OR */
 K0, /* NIMP, PI2, K1 */
 NOR, /* NIMP, NOR, K0 */
 NOR, /* NIMP, NOR, PI1 */
 NOR, /* NIMP, NOR, PI2 */
 K0, /* NIMP, NOR, NOR */
 NOR, /* NIMP, NOR, NLIMP */
 K0, /* NIMP, NOR, NPI1 */
 NOR, /* NIMP, NOR, NIMP */
 K0, /* NIMP, NOR, NPI2 */
 NOR, /* NIMP, NOR, XOR */
 K0, /* NIMP, NOR, NAND */
 NOR, /* NIMP, NOR, AND */
 K0, /* NIMP, NOR, BIIMP */
 K0, /* NIMP, NOR, IMP */
 K0, /* NIMP, NOR, LIMP */
 NOR, /* NIMP, NOR, OR */
 K0, /* NIMP, NOR, K1 */
 NLIMP, /* NIMP, NLIMP, K0 */
 NLIMP, /* NIMP, NLIMP, PI1 */
 K0, /* NIMP, NLIMP, PI2 */
 NLIMP, /* NIMP, NLIMP, NOR */
 K0, /* NIMP, NLIMP, NLIMP */
 K0, /* NIMP, NLIMP, NPI1 */
 NLIMP, /* NIMP, NLIMP, NIMP */
 NLIMP, /* NIMP, NLIMP, NPI2 */
 K0, /* NIMP, NLIMP, XOR */
 K0, /* NIMP, NLIMP, NAND */
 NLIMP, /* NIMP, NLIMP, AND */
 NLIMP, /* NIMP, NLIMP, BIIMP */
 K0, /* NIMP, NLIMP, IMP */
 NLIMP, /* NIMP, NLIMP, LIMP */
 K0, /* NIMP, NLIMP, OR */
 K0, /* NIMP, NLIMP, K1 */
 NPI1, /* NIMP, NPI1, K0 */
 NPI1, /* NIMP, NPI1, PI1 */
 NOR, /* NIMP, NPI1, PI2 */
 NLIMP, /* NIMP, NPI1, NOR */
 NOR, /* NIMP, NPI1, NLIMP */
 K0, /* NIMP, NPI1, NPI1 */
 NPI1, /* NIMP, NPI1, NIMP */
 NLIMP, /* NIMP, NPI1, NPI2 */
 NOR, /* NIMP, NPI1, XOR */
 K0, /* NIMP, NPI1, NAND */
 NPI1, /* NIMP, NPI1, AND */
 NLIMP, /* NIMP, NPI1, BIIMP */
 K0, /* NIMP, NPI1, IMP */
 NLIMP, /* NIMP, NPI1, LIMP */
 NOR, /* NIMP, NPI1, OR */
 K0, /* NIMP, NPI1, K1 */
 NIMP, /* NIMP, NIMP, K0 */
 K0, /* NIMP, NIMP, PI1 */
 NIMP, /* NIMP, NIMP, PI2 */
 NIMP, /* NIMP, NIMP, NOR */
 NIMP, /* NIMP, NIMP, NLIMP */
 NIMP, /* NIMP, NIMP, NPI1 */
 K0, /* NIMP, NIMP, NIMP */
 K0, /* NIMP, NIMP, NPI2 */
 K0, /* NIMP, NIMP, XOR */
 K0, /* NIMP, NIMP, NAND */
 NIMP, /* NIMP, NIMP, AND */
 NIMP, /* NIMP, NIMP, BIIMP */
 NIMP, /* NIMP, NIMP, IMP */
 K0, /* NIMP, NIMP, LIMP */
 K0, /* NIMP, NIMP, OR */
 K0, /* NIMP, NIMP, K1 */
 NPI2, /* NIMP, NPI2, K0 */
 NOR, /* NIMP, NPI2, PI1 */
 NPI2, /* NIMP, NPI2, PI2 */
 NIMP, /* NIMP, NPI2, NOR */
 NPI2, /* NIMP, NPI2, NLIMP */
 NIMP, /* NIMP, NPI2, NPI1 */
 NOR, /* NIMP, NPI2, NIMP */
 K0, /* NIMP, NPI2, NPI2 */
 NOR, /* NIMP, NPI2, XOR */
 K0, /* NIMP, NPI2, NAND */
 NPI2, /* NIMP, NPI2, AND */
 NIMP, /* NIMP, NPI2, BIIMP */
 NIMP, /* NIMP, NPI2, IMP */
 K0, /* NIMP, NPI2, LIMP */
 NOR, /* NIMP, NPI2, OR */
 K0, /* NIMP, NPI2, K1 */
 XOR, /* NIMP, XOR, K0 */
 NLIMP, /* NIMP, XOR, PI1 */
 NIMP, /* NIMP, XOR, PI2 */
 XOR, /* NIMP, XOR, NOR */
 NIMP, /* NIMP, XOR, NLIMP */
 NIMP, /* NIMP, XOR, NPI1 */
 NLIMP, /* NIMP, XOR, NIMP */
 NLIMP, /* NIMP, XOR, NPI2 */
 K0, /* NIMP, XOR, XOR */
 K0, /* NIMP, XOR, NAND */
 XOR, /* NIMP, XOR, AND */
 XOR, /* NIMP, XOR, BIIMP */
 NIMP, /* NIMP, XOR, IMP */
 NLIMP, /* NIMP, XOR, LIMP */
 K0, /* NIMP, XOR, OR */
 K0, /* NIMP, XOR, K1 */
 NAND, /* NIMP, NAND, K0 */
 NPI1, /* NIMP, NAND, PI1 */
 NPI2, /* NIMP, NAND, PI2 */
 XOR, /* NIMP, NAND, NOR */
 NPI2, /* NIMP, NAND, NLIMP */
 NIMP, /* NIMP, NAND, NPI1 */
 NPI1, /* NIMP, NAND, NIMP */
 NLIMP, /* NIMP, NAND, NPI2 */
 NOR, /* NIMP, NAND, XOR */
 K0, /* NIMP, NAND, NAND */
 NAND, /* NIMP, NAND, AND */
 XOR, /* NIMP, NAND, BIIMP */
 NIMP, /* NIMP, NAND, IMP */
 NLIMP, /* NIMP, NAND, LIMP */
 NOR, /* NIMP, NAND, OR */
 K0, /* NIMP, NAND, K1 */
 AND, /* NIMP, AND, K0 */
 K0, /* NIMP, AND, PI1 */
 K0, /* NIMP, AND, PI2 */
 AND, /* NIMP, AND, NOR */
 AND, /* NIMP, AND, NLIMP */
 AND, /* NIMP, AND, NPI1 */
 AND, /* NIMP, AND, NIMP */
 AND, /* NIMP, AND, NPI2 */
 AND, /* NIMP, AND, XOR */
 AND, /* NIMP, AND, NAND */
 K0, /* NIMP, AND, AND */
 K0, /* NIMP, AND, BIIMP */
 K0, /* NIMP, AND, IMP */
 K0, /* NIMP, AND, LIMP */
 K0, /* NIMP, AND, OR */
 K0, /* NIMP, AND, K1 */
 BIIMP, /* NIMP, BIIMP, K0 */
 NOR, /* NIMP, BIIMP, PI1 */
 NOR, /* NIMP, BIIMP, PI2 */
 AND, /* NIMP, BIIMP, NOR */
 BIIMP, /* NIMP, BIIMP, NLIMP */
 AND, /* NIMP, BIIMP, NPI1 */
 BIIMP, /* NIMP, BIIMP, NIMP */
 AND, /* NIMP, BIIMP, NPI2 */
 BIIMP, /* NIMP, BIIMP, XOR */
 AND, /* NIMP, BIIMP, NAND */
 NOR, /* NIMP, BIIMP, AND */
 K0, /* NIMP, BIIMP, BIIMP */
 K0, /* NIMP, BIIMP, IMP */
 K0, /* NIMP, BIIMP, LIMP */
 NOR, /* NIMP, BIIMP, OR */
 K0, /* NIMP, BIIMP, K1 */
 IMP, /* NIMP, IMP, K0 */
 NPI1, /* NIMP, IMP, PI1 */
 NOR, /* NIMP, IMP, PI2 */
 PI2, /* NIMP, IMP, NOR */
 BIIMP, /* NIMP, IMP, NLIMP */
 AND, /* NIMP, IMP, NPI1 */
 IMP, /* NIMP, IMP, NIMP */
 PI2, /* NIMP, IMP, NPI2 */
 BIIMP, /* NIMP, IMP, XOR */
 AND, /* NIMP, IMP, NAND */
 NPI1, /* NIMP, IMP, AND */
 NLIMP, /* NIMP, IMP, BIIMP */
 K0, /* NIMP, IMP, IMP */
 NLIMP, /* NIMP, IMP, LIMP */
 NOR, /* NIMP, IMP, OR */
 K0, /* NIMP, IMP, K1 */
 LIMP, /* NIMP, LIMP, K0 */
 NOR, /* NIMP, LIMP, PI1 */
 NPI2, /* NIMP, LIMP, PI2 */
 PI1, /* NIMP, LIMP, NOR */
 LIMP, /* NIMP, LIMP, NLIMP */
 PI1, /* NIMP, LIMP, NPI1 */
 BIIMP, /* NIMP, LIMP, NIMP */
 AND, /* NIMP, LIMP, NPI2 */
 BIIMP, /* NIMP, LIMP, XOR */
 AND, /* NIMP, LIMP, NAND */
 NPI2, /* NIMP, LIMP, AND */
 NIMP, /* NIMP, LIMP, BIIMP */
 NIMP, /* NIMP, LIMP, IMP */
 K0, /* NIMP, LIMP, LIMP */
 NOR, /* NIMP, LIMP, OR */
 K0, /* NIMP, LIMP, K1 */
 OR, /* NIMP, OR, K0 */
 NLIMP, /* NIMP, OR, PI1 */
 NIMP, /* NIMP, OR, PI2 */
 OR, /* NIMP, OR, NOR */
 PI1, /* NIMP, OR, NLIMP */
 PI1, /* NIMP, OR, NPI1 */
 PI2, /* NIMP, OR, NIMP */
 PI2, /* NIMP, OR, NPI2 */
 AND, /* NIMP, OR, XOR */
 AND, /* NIMP, OR, NAND */
 XOR, /* NIMP, OR, AND */
 XOR, /* NIMP, OR, BIIMP */
 NIMP, /* NIMP, OR, IMP */
 NLIMP, /* NIMP, OR, LIMP */
 K0, /* NIMP, OR, OR */
 K0, /* NIMP, OR, K1 */
 K1, /* NIMP, K1, K0 */
 NPI1, /* NIMP, K1, PI1 */
 NPI2, /* NIMP, K1, PI2 */
 OR, /* NIMP, K1, NOR */
 LIMP, /* NIMP, K1, NLIMP */
 PI1, /* NIMP, K1, NPI1 */
 IMP, /* NIMP, K1, NIMP */
 PI2, /* NIMP, K1, NPI2 */
 BIIMP, /* NIMP, K1, XOR */
 AND, /* NIMP, K1, NAND */
 NAND, /* NIMP, K1, AND */
 XOR, /* NIMP, K1, BIIMP */
 NIMP, /* NIMP, K1, IMP */
 NLIMP, /* NIMP, K1, LIMP */
 NOR, /* NIMP, K1, OR */
 K0, /* NIMP, K1, K1 */
 K1, /* NPI2, K0, K0 */
 NPI1, /* NPI2, K0, PI1 */
 NPI2, /* NPI2, K0, PI2 */
 OR, /* NPI2, K0, NOR */
 LIMP, /* NPI2, K0, NLIMP */
 PI1, /* NPI2, K0, NPI1 */
 IMP, /* NPI2, K0, NIMP */
 PI2, /* NPI2, K0, NPI2 */
 BIIMP, /* NPI2, K0, XOR */
 AND, /* NPI2, K0, NAND */
 NAND, /* NPI2, K0, AND */
 XOR, /* NPI2, K0, BIIMP */
 NIMP, /* NPI2, K0, IMP */
 NLIMP, /* NPI2, K0, LIMP */
 NOR, /* NPI2, K0, OR */
 K0, /* NPI2, K0, K1 */
 K1, /* NPI2, PI1, K0 */
 NPI1, /* NPI2, PI1, PI1 */
 NPI2, /* NPI2, PI1, PI2 */
 OR, /* NPI2, PI1, NOR */
 LIMP, /* NPI2, PI1, NLIMP */
 PI1, /* NPI2, PI1, NPI1 */
 IMP, /* NPI2, PI1, NIMP */
 PI2, /* NPI2, PI1, NPI2 */
 BIIMP, /* NPI2, PI1, XOR */
 AND, /* NPI2, PI1, NAND */
 NAND, /* NPI2, PI1, AND */
 XOR, /* NPI2, PI1, BIIMP */
 NIMP, /* NPI2, PI1, IMP */
 NLIMP, /* NPI2, PI1, LIMP */
 NOR, /* NPI2, PI1, OR */
 K0, /* NPI2, PI1, K1 */
 K1, /* NPI2, PI2, K0 */
 NPI1, /* NPI2, PI2, PI1 */
 NPI2, /* NPI2, PI2, PI2 */
 OR, /* NPI2, PI2, NOR */
 LIMP, /* NPI2, PI2, NLIMP */
 PI1, /* NPI2, PI2, NPI1 */
 IMP, /* NPI2, PI2, NIMP */
 PI2, /* NPI2, PI2, NPI2 */
 BIIMP, /* NPI2, PI2, XOR */
 AND, /* NPI2, PI2, NAND */
 NAND, /* NPI2, PI2, AND */
 XOR, /* NPI2, PI2, BIIMP */
 NIMP, /* NPI2, PI2, IMP */
 NLIMP, /* NPI2, PI2, LIMP */
 NOR, /* NPI2, PI2, OR */
 K0, /* NPI2, PI2, K1 */
 K1, /* NPI2, NOR, K0 */
 NPI1, /* NPI2, NOR, PI1 */
 NPI2, /* NPI2, NOR, PI2 */
 OR, /* NPI2, NOR, NOR */
 LIMP, /* NPI2, NOR, NLIMP */
 PI1, /* NPI2, NOR, NPI1 */
 IMP, /* NPI2, NOR, NIMP */
 PI2, /* NPI2, NOR, NPI2 */
 BIIMP, /* NPI2, NOR, XOR */
 AND, /* NPI2, NOR, NAND */
 NAND, /* NPI2, NOR, AND */
 XOR, /* NPI2, NOR, BIIMP */
 NIMP, /* NPI2, NOR, IMP */
 NLIMP, /* NPI2, NOR, LIMP */
 NOR, /* NPI2, NOR, OR */
 K0, /* NPI2, NOR, K1 */
 K1, /* NPI2, NLIMP, K0 */
 NPI1, /* NPI2, NLIMP, PI1 */
 NPI2, /* NPI2, NLIMP, PI2 */
 OR, /* NPI2, NLIMP, NOR */
 LIMP, /* NPI2, NLIMP, NLIMP */
 PI1, /* NPI2, NLIMP, NPI1 */
 IMP, /* NPI2, NLIMP, NIMP */
 PI2, /* NPI2, NLIMP, NPI2 */
 BIIMP, /* NPI2, NLIMP, XOR */
 AND, /* NPI2, NLIMP, NAND */
 NAND, /* NPI2, NLIMP, AND */
 XOR, /* NPI2, NLIMP, BIIMP */
 NIMP, /* NPI2, NLIMP, IMP */
 NLIMP, /* NPI2, NLIMP, LIMP */
 NOR, /* NPI2, NLIMP, OR */
 K0, /* NPI2, NLIMP, K1 */
 K1, /* NPI2, NPI1, K0 */
 NPI1, /* NPI2, NPI1, PI1 */
 NPI2, /* NPI2, NPI1, PI2 */
 OR, /* NPI2, NPI1, NOR */
 LIMP, /* NPI2, NPI1, NLIMP */
 PI1, /* NPI2, NPI1, NPI1 */
 IMP, /* NPI2, NPI1, NIMP */
 PI2, /* NPI2, NPI1, NPI2 */
 BIIMP, /* NPI2, NPI1, XOR */
 AND, /* NPI2, NPI1, NAND */
 NAND, /* NPI2, NPI1, AND */
 XOR, /* NPI2, NPI1, BIIMP */
 NIMP, /* NPI2, NPI1, IMP */
 NLIMP, /* NPI2, NPI1, LIMP */
 NOR, /* NPI2, NPI1, OR */
 K0, /* NPI2, NPI1, K1 */
 K1, /* NPI2, NIMP, K0 */
 NPI1, /* NPI2, NIMP, PI1 */
 NPI2, /* NPI2, NIMP, PI2 */
 OR, /* NPI2, NIMP, NOR */
 LIMP, /* NPI2, NIMP, NLIMP */
 PI1, /* NPI2, NIMP, NPI1 */
 IMP, /* NPI2, NIMP, NIMP */
 PI2, /* NPI2, NIMP, NPI2 */
 BIIMP, /* NPI2, NIMP, XOR */
 AND, /* NPI2, NIMP, NAND */
 NAND, /* NPI2, NIMP, AND */
 XOR, /* NPI2, NIMP, BIIMP */
 NIMP, /* NPI2, NIMP, IMP */
 NLIMP, /* NPI2, NIMP, LIMP */
 NOR, /* NPI2, NIMP, OR */
 K0, /* NPI2, NIMP, K1 */
 K1, /* NPI2, NPI2, K0 */
 NPI1, /* NPI2, NPI2, PI1 */
 NPI2, /* NPI2, NPI2, PI2 */
 OR, /* NPI2, NPI2, NOR */
 LIMP, /* NPI2, NPI2, NLIMP */
 PI1, /* NPI2, NPI2, NPI1 */
 IMP, /* NPI2, NPI2, NIMP */
 PI2, /* NPI2, NPI2, NPI2 */
 BIIMP, /* NPI2, NPI2, XOR */
 AND, /* NPI2, NPI2, NAND */
 NAND, /* NPI2, NPI2, AND */
 XOR, /* NPI2, NPI2, BIIMP */
 NIMP, /* NPI2, NPI2, IMP */
 NLIMP, /* NPI2, NPI2, LIMP */
 NOR, /* NPI2, NPI2, OR */
 K0, /* NPI2, NPI2, K1 */
 K1, /* NPI2, XOR, K0 */
 NPI1, /* NPI2, XOR, PI1 */
 NPI2, /* NPI2, XOR, PI2 */
 OR, /* NPI2, XOR, NOR */
 LIMP, /* NPI2, XOR, NLIMP */
 PI1, /* NPI2, XOR, NPI1 */
 IMP, /* NPI2, XOR, NIMP */
 PI2, /* NPI2, XOR, NPI2 */
 BIIMP, /* NPI2, XOR, XOR */
 AND, /* NPI2, XOR, NAND */
 NAND, /* NPI2, XOR, AND */
 XOR, /* NPI2, XOR, BIIMP */
 NIMP, /* NPI2, XOR, IMP */
 NLIMP, /* NPI2, XOR, LIMP */
 NOR, /* NPI2, XOR, OR */
 K0, /* NPI2, XOR, K1 */
 K1, /* NPI2, NAND, K0 */
 NPI1, /* NPI2, NAND, PI1 */
 NPI2, /* NPI2, NAND, PI2 */
 OR, /* NPI2, NAND, NOR */
 LIMP, /* NPI2, NAND, NLIMP */
 PI1, /* NPI2, NAND, NPI1 */
 IMP, /* NPI2, NAND, NIMP */
 PI2, /* NPI2, NAND, NPI2 */
 BIIMP, /* NPI2, NAND, XOR */
 AND, /* NPI2, NAND, NAND */
 NAND, /* NPI2, NAND, AND */
 XOR, /* NPI2, NAND, BIIMP */
 NIMP, /* NPI2, NAND, IMP */
 NLIMP, /* NPI2, NAND, LIMP */
 NOR, /* NPI2, NAND, OR */
 K0, /* NPI2, NAND, K1 */
 K1, /* NPI2, AND, K0 */
 NPI1, /* NPI2, AND, PI1 */
 NPI2, /* NPI2, AND, PI2 */
 OR, /* NPI2, AND, NOR */
 LIMP, /* NPI2, AND, NLIMP */
 PI1, /* NPI2, AND, NPI1 */
 IMP, /* NPI2, AND, NIMP */
 PI2, /* NPI2, AND, NPI2 */
 BIIMP, /* NPI2, AND, XOR */
 AND, /* NPI2, AND, NAND */
 NAND, /* NPI2, AND, AND */
 XOR, /* NPI2, AND, BIIMP */
 NIMP, /* NPI2, AND, IMP */
 NLIMP, /* NPI2, AND, LIMP */
 NOR, /* NPI2, AND, OR */
 K0, /* NPI2, AND, K1 */
 K1, /* NPI2, BIIMP, K0 */
 NPI1, /* NPI2, BIIMP, PI1 */
 NPI2, /* NPI2, BIIMP, PI2 */
 OR, /* NPI2, BIIMP, NOR */
 LIMP, /* NPI2, BIIMP, NLIMP */
 PI1, /* NPI2, BIIMP, NPI1 */
 IMP, /* NPI2, BIIMP, NIMP */
 PI2, /* NPI2, BIIMP, NPI2 */
 BIIMP, /* NPI2, BIIMP, XOR */
 AND, /* NPI2, BIIMP, NAND */
 NAND, /* NPI2, BIIMP, AND */
 XOR, /* NPI2, BIIMP, BIIMP */
 NIMP, /* NPI2, BIIMP, IMP */
 NLIMP, /* NPI2, BIIMP, LIMP */
 NOR, /* NPI2, BIIMP, OR */
 K0, /* NPI2, BIIMP, K1 */
 K1, /* NPI2, IMP, K0 */
 NPI1, /* NPI2, IMP, PI1 */
 NPI2, /* NPI2, IMP, PI2 */
 OR, /* NPI2, IMP, NOR */
 LIMP, /* NPI2, IMP, NLIMP */
 PI1, /* NPI2, IMP, NPI1 */
 IMP, /* NPI2, IMP, NIMP */
 PI2, /* NPI2, IMP, NPI2 */
 BIIMP, /* NPI2, IMP, XOR */
 AND, /* NPI2, IMP, NAND */
 NAND, /* NPI2, IMP, AND */
 XOR, /* NPI2, IMP, BIIMP */
 NIMP, /* NPI2, IMP, IMP */
 NLIMP, /* NPI2, IMP, LIMP */
 NOR, /* NPI2, IMP, OR */
 K0, /* NPI2, IMP, K1 */
 K1, /* NPI2, LIMP, K0 */
 NPI1, /* NPI2, LIMP, PI1 */
 NPI2, /* NPI2, LIMP, PI2 */
 OR, /* NPI2, LIMP, NOR */
 LIMP, /* NPI2, LIMP, NLIMP */
 PI1, /* NPI2, LIMP, NPI1 */
 IMP, /* NPI2, LIMP, NIMP */
 PI2, /* NPI2, LIMP, NPI2 */
 BIIMP, /* NPI2, LIMP, XOR */
 AND, /* NPI2, LIMP, NAND */
 NAND, /* NPI2, LIMP, AND */
 XOR, /* NPI2, LIMP, BIIMP */
 NIMP, /* NPI2, LIMP, IMP */
 NLIMP, /* NPI2, LIMP, LIMP */
 NOR, /* NPI2, LIMP, OR */
 K0, /* NPI2, LIMP, K1 */
 K1, /* NPI2, OR, K0 */
 NPI1, /* NPI2, OR, PI1 */
 NPI2, /* NPI2, OR, PI2 */
 OR, /* NPI2, OR, NOR */
 LIMP, /* NPI2, OR, NLIMP */
 PI1, /* NPI2, OR, NPI1 */
 IMP, /* NPI2, OR, NIMP */
 PI2, /* NPI2, OR, NPI2 */
 BIIMP, /* NPI2, OR, XOR */
 AND, /* NPI2, OR, NAND */
 NAND, /* NPI2, OR, AND */
 XOR, /* NPI2, OR, BIIMP */
 NIMP, /* NPI2, OR, IMP */
 NLIMP, /* NPI2, OR, LIMP */
 NOR, /* NPI2, OR, OR */
 K0, /* NPI2, OR, K1 */
 K1, /* NPI2, K1, K0 */
 NPI1, /* NPI2, K1, PI1 */
 NPI2, /* NPI2, K1, PI2 */
 OR, /* NPI2, K1, NOR */
 LIMP, /* NPI2, K1, NLIMP */
 PI1, /* NPI2, K1, NPI1 */
 IMP, /* NPI2, K1, NIMP */
 PI2, /* NPI2, K1, NPI2 */
 BIIMP, /* NPI2, K1, XOR */
 AND, /* NPI2, K1, NAND */
 NAND, /* NPI2, K1, AND */
 XOR, /* NPI2, K1, BIIMP */
 NIMP, /* NPI2, K1, IMP */
 NLIMP, /* NPI2, K1, LIMP */
 NOR, /* NPI2, K1, OR */
 K0, /* NPI2, K1, K1 */
 K0, /* XOR, K0, K0 */
 PI1, /* XOR, K0, PI1 */
 PI2, /* XOR, K0, PI2 */
 NOR, /* XOR, K0, NOR */
 NLIMP, /* XOR, K0, NLIMP */
 NPI1, /* XOR, K0, NPI1 */
 NIMP, /* XOR, K0, NIMP */
 NPI2, /* XOR, K0, NPI2 */
 XOR, /* XOR, K0, XOR */
 NAND, /* XOR, K0, NAND */
 AND, /* XOR, K0, AND */
 BIIMP, /* XOR, K0, BIIMP */
 IMP, /* XOR, K0, IMP */
 LIMP, /* XOR, K0, LIMP */
 OR, /* XOR, K0, OR */
 K1, /* XOR, K0, K1 */
 PI1, /* XOR, PI1, K0 */
 K0, /* XOR, PI1, PI1 */
 XOR, /* XOR, PI1, PI2 */
 LIMP, /* XOR, PI1, NOR */
 OR, /* XOR, PI1, NLIMP */
 K1, /* XOR, PI1, NPI1 */
 AND, /* XOR, PI1, NIMP */
 BIIMP, /* XOR, PI1, NPI2 */
 PI2, /* XOR, PI1, XOR */
 IMP, /* XOR, PI1, NAND */
 NIMP, /* XOR, PI1, AND */
 NPI2, /* XOR, PI1, BIIMP */
 NAND, /* XOR, PI1, IMP */
 NOR, /* XOR, PI1, LIMP */
 NLIMP, /* XOR, PI1, OR */
 NPI1, /* XOR, PI1, K1 */
 PI2, /* XOR, PI2, K0 */
 XOR, /* XOR, PI2, PI1 */
 K0, /* XOR, PI2, PI2 */
 IMP, /* XOR, PI2, NOR */
 AND, /* XOR, PI2, NLIMP */
 BIIMP, /* XOR, PI2, NPI1 */
 OR, /* XOR, PI2, NIMP */
 K1, /* XOR, PI2, NPI2 */
 PI1, /* XOR, PI2, XOR */
 LIMP, /* XOR, PI2, NAND */
 NLIMP, /* XOR, PI2, AND */
 NPI1, /* XOR, PI2, BIIMP */
 NOR, /* XOR, PI2, IMP */
 NAND, /* XOR, PI2, LIMP */
 NIMP, /* XOR, PI2, OR */
 NPI2, /* XOR, PI2, K1 */
 NOR, /* XOR, NOR, K0 */
 LIMP, /* XOR, NOR, PI1 */
 IMP, /* XOR, NOR, PI2 */
 K0, /* XOR, NOR, NOR */
 NPI1, /* XOR, NOR, NLIMP */
 NLIMP, /* XOR, NOR, NPI1 */
 NPI2, /* XOR, NOR, NIMP */
 NIMP, /* XOR, NOR, NPI2 */
 NAND, /* XOR, NOR, XOR */
 XOR, /* XOR, NOR, NAND */
 BIIMP, /* XOR, NOR, AND */
 AND, /* XOR, NOR, BIIMP */
 PI2, /* XOR, NOR, IMP */
 PI1, /* XOR, NOR, LIMP */
 K1, /* XOR, NOR, OR */
 OR, /* XOR, NOR, K1 */
 NLIMP, /* XOR, NLIMP, K0 */
 OR, /* XOR, NLIMP, PI1 */
 AND, /* XOR, NLIMP, PI2 */
 NPI1, /* XOR, NLIMP, NOR */
 K0, /* XOR, NLIMP, NLIMP */
 NOR, /* XOR, NLIMP, NPI1 */
 XOR, /* XOR, NLIMP, NIMP */
 NAND, /* XOR, NLIMP, NPI2 */
 NIMP, /* XOR, NLIMP, XOR */
 NPI2, /* XOR, NLIMP, NAND */
 PI2, /* XOR, NLIMP, AND */
 IMP, /* XOR, NLIMP, BIIMP */
 BIIMP, /* XOR, NLIMP, IMP */
 K1, /* XOR, NLIMP, LIMP */
 PI1, /* XOR, NLIMP, OR */
 LIMP, /* XOR, NLIMP, K1 */
 NPI1, /* XOR, NPI1, K0 */
 K1, /* XOR, NPI1, PI1 */
 BIIMP, /* XOR, NPI1, PI2 */
 NLIMP, /* XOR, NPI1, NOR */
 NOR, /* XOR, NPI1, NLIMP */
 K0, /* XOR, NPI1, NPI1 */
 NAND, /* XOR, NPI1, NIMP */
 XOR, /* XOR, NPI1, NPI2 */
 NPI2, /* XOR, NPI1, XOR */
 NIMP, /* XOR, NPI1, NAND */
 IMP, /* XOR, NPI1, AND */
 PI2, /* XOR, NPI1, BIIMP */
 AND, /* XOR, NPI1, IMP */
 OR, /* XOR, NPI1, LIMP */
 LIMP, /* XOR, NPI1, OR */
 PI1, /* XOR, NPI1, K1 */
 NIMP, /* XOR, NIMP, K0 */
 AND, /* XOR, NIMP, PI1 */
 OR, /* XOR, NIMP, PI2 */
 NPI2, /* XOR, NIMP, NOR */
 XOR, /* XOR, NIMP, NLIMP */
 NAND, /* XOR, NIMP, NPI1 */
 K0, /* XOR, NIMP, NIMP */
 NOR, /* XOR, NIMP, NPI2 */
 NLIMP, /* XOR, NIMP, XOR */
 NPI1, /* XOR, NIMP, NAND */
 PI1, /* XOR, NIMP, AND */
 LIMP, /* XOR, NIMP, BIIMP */
 K1, /* XOR, NIMP, IMP */
 BIIMP, /* XOR, NIMP, LIMP */
 PI2, /* XOR, NIMP, OR */
 IMP, /* XOR, NIMP, K1 */
 NPI2, /* XOR, NPI2, K0 */
 BIIMP, /* XOR, NPI2, PI1 */
 K1, /* XOR, NPI2, PI2 */
 NIMP, /* XOR, NPI2, NOR */
 NAND, /* XOR, NPI2, NLIMP */
 XOR, /* XOR, NPI2, NPI1 */
 NOR, /* XOR, NPI2, NIMP */
 K0, /* XOR, NPI2, NPI2 */
 NPI1, /* XOR, NPI2, XOR */
 NLIMP, /* XOR, NPI2, NAND */
 LIMP, /* XOR, NPI2, AND */
 PI1, /* XOR, NPI2, BIIMP */
 OR, /* XOR, NPI2, IMP */
 AND, /* XOR, NPI2, LIMP */
 IMP, /* XOR, NPI2, OR */
 PI2, /* XOR, NPI2, K1 */
 XOR, /* XOR, XOR, K0 */
 PI2, /* XOR, XOR, PI1 */
 PI1, /* XOR, XOR, PI2 */
 NAND, /* XOR, XOR, NOR */
 NIMP, /* XOR, XOR, NLIMP */
 NPI2, /* XOR, XOR, NPI1 */
 NLIMP, /* XOR, XOR, NIMP */
 NPI1, /* XOR, XOR, NPI2 */
 K0, /* XOR, XOR, XOR */
 NOR, /* XOR, XOR, NAND */
 OR, /* XOR, XOR, AND */
 K1, /* XOR, XOR, BIIMP */
 LIMP, /* XOR, XOR, IMP */
 IMP, /* XOR, XOR, LIMP */
 AND, /* XOR, XOR, OR */
 BIIMP, /* XOR, XOR, K1 */
 NAND, /* XOR, NAND, K0 */
 IMP, /* XOR, NAND, PI1 */
 LIMP, /* XOR, NAND, PI2 */
 XOR, /* XOR, NAND, NOR */
 NPI2, /* XOR, NAND, NLIMP */
 NIMP, /* XOR, NAND, NPI1 */
 NPI1, /* XOR, NAND, NIMP */
 NLIMP, /* XOR, NAND, NPI2 */
 NOR, /* XOR, NAND, XOR */
 K0, /* XOR, NAND, NAND */
 K1, /* XOR, NAND, AND */
 OR, /* XOR, NAND, BIIMP */
 PI1, /* XOR, NAND, IMP */
 PI2, /* XOR, NAND, LIMP */
 BIIMP, /* XOR, NAND, OR */
 AND, /* XOR, NAND, K1 */
 AND, /* XOR, AND, K0 */
 NIMP, /* XOR, AND, PI1 */
 NLIMP, /* XOR, AND, PI2 */
 BIIMP, /* XOR, AND, NOR */
 PI2, /* XOR, AND, NLIMP */
 IMP, /* XOR, AND, NPI1 */
 PI1, /* XOR, AND, NIMP */
 LIMP, /* XOR, AND, NPI2 */
 OR, /* XOR, AND, XOR */
 K1, /* XOR, AND, NAND */
 K0, /* XOR, AND, AND */
 NOR, /* XOR, AND, BIIMP */
 NPI1, /* XOR, AND, IMP */
 NPI2, /* XOR, AND, LIMP */
 XOR, /* XOR, AND, OR */
 NAND, /* XOR, AND, K1 */
 BIIMP, /* XOR, BIIMP, K0 */
 NPI2, /* XOR, BIIMP, PI1 */
 NPI1, /* XOR, BIIMP, PI2 */
 AND, /* XOR, BIIMP, NOR */
 IMP, /* XOR, BIIMP, NLIMP */
 PI2, /* XOR, BIIMP, NPI1 */
 LIMP, /* XOR, BIIMP, NIMP */
 PI1, /* XOR, BIIMP, NPI2 */
 K1, /* XOR, BIIMP, XOR */
 OR, /* XOR, BIIMP, NAND */
 NOR, /* XOR, BIIMP, AND */
 K0, /* XOR, BIIMP, BIIMP */
 NLIMP, /* XOR, BIIMP, IMP */
 NIMP, /* XOR, BIIMP, LIMP */
 NAND, /* XOR, BIIMP, OR */
 XOR, /* XOR, BIIMP, K1 */
 IMP, /* XOR, IMP, K0 */
 NAND, /* XOR, IMP, PI1 */
 NOR, /* XOR, IMP, PI2 */
 PI2, /* XOR, IMP, NOR */
 BIIMP, /* XOR, IMP, NLIMP */
 AND, /* XOR, IMP, NPI1 */
 K1, /* XOR, IMP, NIMP */
 OR, /* XOR, IMP, NPI2 */
 LIMP, /* XOR, IMP, XOR */
 PI1, /* XOR, IMP, NAND */
 NPI1, /* XOR, IMP, AND */
 NLIMP, /* XOR, IMP, BIIMP */
 K0, /* XOR, IMP, IMP */
 XOR, /* XOR, IMP, LIMP */
 NPI2, /* XOR, IMP, OR */
 NIMP, /* XOR, IMP, K1 */
 LIMP, /* XOR, LIMP, K0 */
 NOR, /* XOR, LIMP, PI1 */
 NAND, /* XOR, LIMP, PI2 */
 PI1, /* XOR, LIMP, NOR */
 K1, /* XOR, LIMP, NLIMP */
 OR, /* XOR, LIMP, NPI1 */
 BIIMP, /* XOR, LIMP, NIMP */
 AND, /* XOR, LIMP, NPI2 */
 IMP, /* XOR, LIMP, XOR */
 PI2, /* XOR, LIMP, NAND */
 NPI2, /* XOR, LIMP, AND */
 NIMP, /* XOR, LIMP, BIIMP */
 XOR, /* XOR, LIMP, IMP */
 K0, /* XOR, LIMP, LIMP */
 NPI1, /* XOR, LIMP, OR */
 NLIMP, /* XOR, LIMP, K1 */
 OR, /* XOR, OR, K0 */
 NLIMP, /* XOR, OR, PI1 */
 NIMP, /* XOR, OR, PI2 */
 K1, /* XOR, OR, NOR */
 PI1, /* XOR, OR, NLIMP */
 LIMP, /* XOR, OR, NPI1 */
 PI2, /* XOR, OR, NIMP */
 IMP, /* XOR, OR, NPI2 */
 AND, /* XOR, OR, XOR */
 BIIMP, /* XOR, OR, NAND */
 XOR, /* XOR, OR, AND */
 NAND, /* XOR, OR, BIIMP */
 NPI2, /* XOR, OR, IMP */
 NPI1, /* XOR, OR, LIMP */
 K0, /* XOR, OR, OR */
 NOR, /* XOR, OR, K1 */
 K1, /* XOR, K1, K0 */
 NPI1, /* XOR, K1, PI1 */
 NPI2, /* XOR, K1, PI2 */
 OR, /* XOR, K1, NOR */
 LIMP, /* XOR, K1, NLIMP */
 PI1, /* XOR, K1, NPI1 */
 IMP, /* XOR, K1, NIMP */
 PI2, /* XOR, K1, NPI2 */
 BIIMP, /* XOR, K1, XOR */
 AND, /* XOR, K1, NAND */
 NAND, /* XOR, K1, AND */
 XOR, /* XOR, K1, BIIMP */
 NIMP, /* XOR, K1, IMP */
 NLIMP, /* XOR, K1, LIMP */
 NOR, /* XOR, K1, OR */
 K0, /* XOR, K1, K1 */
 K1, /* NAND, K0, K0 */
 K1, /* NAND, K0, PI1 */
 K1, /* NAND, K0, PI2 */
 K1, /* NAND, K0, NOR */
 K1, /* NAND, K0, NLIMP */
 K1, /* NAND, K0, NPI1 */
 K1, /* NAND, K0, NIMP */
 K1, /* NAND, K0, NPI2 */
 K1, /* NAND, K0, XOR */
 K1, /* NAND, K0, NAND */
 K1, /* NAND, K0, AND */
 K1, /* NAND, K0, BIIMP */
 K1, /* NAND, K0, IMP */
 K1, /* NAND, K0, LIMP */
 K1, /* NAND, K0, OR */
 K1, /* NAND, K0, K1 */
 K1, /* NAND, PI1, K0 */
 NPI1, /* NAND, PI1, PI1 */
 NAND, /* NAND, PI1, PI2 */
 K1, /* NAND, PI1, NOR */
 K1, /* NAND, PI1, NLIMP */
 K1, /* NAND, PI1, NPI1 */
 IMP, /* NAND, PI1, NIMP */
 IMP, /* NAND, PI1, NPI2 */
 IMP, /* NAND, PI1, XOR */
 IMP, /* NAND, PI1, NAND */
 NAND, /* NAND, PI1, AND */
 NAND, /* NAND, PI1, BIIMP */
 NAND, /* NAND, PI1, IMP */
 NPI1, /* NAND, PI1, LIMP */
 NPI1, /* NAND, PI1, OR */
 NPI1, /* NAND, PI1, K1 */
 K1, /* NAND, PI2, K0 */
 NAND, /* NAND, PI2, PI1 */
 NPI2, /* NAND, PI2, PI2 */
 K1, /* NAND, PI2, NOR */
 LIMP, /* NAND, PI2, NLIMP */
 LIMP, /* NAND, PI2, NPI1 */
 K1, /* NAND, PI2, NIMP */
 K1, /* NAND, PI2, NPI2 */
 LIMP, /* NAND, PI2, XOR */
 LIMP, /* NAND, PI2, NAND */
 NAND, /* NAND, PI2, AND */
 NAND, /* NAND, PI2, BIIMP */
 NPI2, /* NAND, PI2, IMP */
 NAND, /* NAND, PI2, LIMP */
 NPI2, /* NAND, PI2, OR */
 NPI2, /* NAND, PI2, K1 */
 K1, /* NAND, NOR, K0 */
 K1, /* NAND, NOR, PI1 */
 K1, /* NAND, NOR, PI2 */
 OR, /* NAND, NOR, NOR */
 K1, /* NAND, NOR, NLIMP */
 OR, /* NAND, NOR, NPI1 */
 K1, /* NAND, NOR, NIMP */
 OR, /* NAND, NOR, NPI2 */
 K1, /* NAND, NOR, XOR */
 OR, /* NAND, NOR, NAND */
 K1, /* NAND, NOR, AND */
 OR, /* NAND, NOR, BIIMP */
 OR, /* NAND, NOR, IMP */
 OR, /* NAND, NOR, LIMP */
 K1, /* NAND, NOR, OR */
 OR, /* NAND, NOR, K1 */
 K1, /* NAND, NLIMP, K0 */
 K1, /* NAND, NLIMP, PI1 */
 LIMP, /* NAND, NLIMP, PI2 */
 K1, /* NAND, NLIMP, NOR */
 LIMP, /* NAND, NLIMP, NLIMP */
 LIMP, /* NAND, NLIMP, NPI1 */
 K1, /* NAND, NLIMP, NIMP */
 K1, /* NAND, NLIMP, NPI2 */
 LIMP, /* NAND, NLIMP, XOR */
 LIMP, /* NAND, NLIMP, NAND */
 K1, /* NAND, NLIMP, AND */
 K1, /* NAND, NLIMP, BIIMP */
 LIMP, /* NAND, NLIMP, IMP */
 K1, /* NAND, NLIMP, LIMP */
 LIMP, /* NAND, NLIMP, OR */
 LIMP, /* NAND, NLIMP, K1 */
 K1, /* NAND, NPI1, K0 */
 K1, /* NAND, NPI1, PI1 */
 LIMP, /* NAND, NPI1, PI2 */
 OR, /* NAND, NPI1, NOR */
 LIMP, /* NAND, NPI1, NLIMP */
 PI1, /* NAND, NPI1, NPI1 */
 K1, /* NAND, NPI1, NIMP */
 OR, /* NAND, NPI1, NPI2 */
 LIMP, /* NAND, NPI1, XOR */
 PI1, /* NAND, NPI1, NAND */
 K1, /* NAND, NPI1, AND */
 OR, /* NAND, NPI1, BIIMP */
 PI1, /* NAND, NPI1, IMP */
 OR, /* NAND, NPI1, LIMP */
 LIMP, /* NAND, NPI1, OR */
 PI1, /* NAND, NPI1, K1 */
 K1, /* NAND, NIMP, K0 */
 IMP, /* NAND, NIMP, PI1 */
 K1, /* NAND, NIMP, PI2 */
 K1, /* NAND, NIMP, NOR */
 K1, /* NAND, NIMP, NLIMP */
 K1, /* NAND, NIMP, NPI1 */
 IMP, /* NAND, NIMP, NIMP */
 IMP, /* NAND, NIMP, NPI2 */
 IMP, /* NAND, NIMP, XOR */
 IMP, /* NAND, NIMP, NAND */
 K1, /* NAND, NIMP, AND */
 K1, /* NAND, NIMP, BIIMP */
 K1, /* NAND, NIMP, IMP */
 IMP, /* NAND, NIMP, LIMP */
 IMP, /* NAND, NIMP, OR */
 IMP, /* NAND, NIMP, K1 */
 K1, /* NAND, NPI2, K0 */
 IMP, /* NAND, NPI2, PI1 */
 K1, /* NAND, NPI2, PI2 */
 OR, /* NAND, NPI2, NOR */
 K1, /* NAND, NPI2, NLIMP */
 OR, /* NAND, NPI2, NPI1 */
 IMP, /* NAND, NPI2, NIMP */
 PI2, /* NAND, NPI2, NPI2 */
 IMP, /* NAND, NPI2, XOR */
 PI2, /* NAND, NPI2, NAND */
 K1, /* NAND, NPI2, AND */
 OR, /* NAND, NPI2, BIIMP */
 OR, /* NAND, NPI2, IMP */
 PI2, /* NAND, NPI2, LIMP */
 IMP, /* NAND, NPI2, OR */
 PI2, /* NAND, NPI2, K1 */
 K1, /* NAND, XOR, K0 */
 IMP, /* NAND, XOR, PI1 */
 LIMP, /* NAND, XOR, PI2 */
 K1, /* NAND, XOR, NOR */
 LIMP, /* NAND, XOR, NLIMP */
 LIMP, /* NAND, XOR, NPI1 */
 IMP, /* NAND, XOR, NIMP */
 IMP, /* NAND, XOR, NPI2 */
 BIIMP, /* NAND, XOR, XOR */
 BIIMP, /* NAND, XOR, NAND */
 K1, /* NAND, XOR, AND */
 K1, /* NAND, XOR, BIIMP */
 LIMP, /* NAND, XOR, IMP */
 IMP, /* NAND, XOR, LIMP */
 BIIMP, /* NAND, XOR, OR */
 BIIMP, /* NAND, XOR, K1 */
 K1, /* NAND, NAND, K0 */
 IMP, /* NAND, NAND, PI1 */
 LIMP, /* NAND, NAND, PI2 */
 OR, /* NAND, NAND, NOR */
 LIMP, /* NAND, NAND, NLIMP */
 PI1, /* NAND, NAND, NPI1 */
 IMP, /* NAND, NAND, NIMP */
 PI2, /* NAND, NAND, NPI2 */
 BIIMP, /* NAND, NAND, XOR */
 AND, /* NAND, NAND, NAND */
 K1, /* NAND, NAND, AND */
 OR, /* NAND, NAND, BIIMP */
 PI1, /* NAND, NAND, IMP */
 PI2, /* NAND, NAND, LIMP */
 BIIMP, /* NAND, NAND, OR */
 AND, /* NAND, NAND, K1 */
 K1, /* NAND, AND, K0 */
 NAND, /* NAND, AND, PI1 */
 NAND, /* NAND, AND, PI2 */
 K1, /* NAND, AND, NOR */
 K1, /* NAND, AND, NLIMP */
 K1, /* NAND, AND, NPI1 */
 K1, /* NAND, AND, NIMP */
 K1, /* NAND, AND, NPI2 */
 K1, /* NAND, AND, XOR */
 K1, /* NAND, AND, NAND */
 NAND, /* NAND, AND, AND */
 NAND, /* NAND, AND, BIIMP */
 NAND, /* NAND, AND, IMP */
 NAND, /* NAND, AND, LIMP */
 NAND, /* NAND, AND, OR */
 NAND, /* NAND, AND, K1 */
 K1, /* NAND, BIIMP, K0 */
 NAND, /* NAND, BIIMP, PI1 */
 NAND, /* NAND, BIIMP, PI2 */
 OR, /* NAND, BIIMP, NOR */
 K1, /* NAND, BIIMP, NLIMP */
 OR, /* NAND, BIIMP, NPI1 */
 K1, /* NAND, BIIMP, NIMP */
 OR, /* NAND, BIIMP, NPI2 */
 K1, /* NAND, BIIMP, XOR */
 OR, /* NAND, BIIMP, NAND */
 NAND, /* NAND, BIIMP, AND */
 XOR, /* NAND, BIIMP, BIIMP */
 XOR, /* NAND, BIIMP, IMP */
 XOR, /* NAND, BIIMP, LIMP */
 NAND, /* NAND, BIIMP, OR */
 XOR, /* NAND, BIIMP, K1 */
 K1, /* NAND, IMP, K0 */
 NAND, /* NAND, IMP, PI1 */
 NPI2, /* NAND, IMP, PI2 */
 OR, /* NAND, IMP, NOR */
 LIMP, /* NAND, IMP, NLIMP */
 PI1, /* NAND, IMP, NPI1 */
 K1, /* NAND, IMP, NIMP */
 OR, /* NAND, IMP, NPI2 */
 LIMP, /* NAND, IMP, XOR */
 PI1, /* NAND, IMP, NAND */
 NAND, /* NAND, IMP, AND */
 XOR, /* NAND, IMP, BIIMP */
 NIMP, /* NAND, IMP, IMP */
 XOR, /* NAND, IMP, LIMP */
 NPI2, /* NAND, IMP, OR */
 NIMP, /* NAND, IMP, K1 */
 K1, /* NAND, LIMP, K0 */
 NPI1, /* NAND, LIMP, PI1 */
 NAND, /* NAND, LIMP, PI2 */
 OR, /* NAND, LIMP, NOR */
 K1, /* NAND, LIMP, NLIMP */
 OR, /* NAND, LIMP, NPI1 */
 IMP, /* NAND, LIMP, NIMP */
 PI2, /* NAND, LIMP, NPI2 */
 IMP, /* NAND, LIMP, XOR */
 PI2, /* NAND, LIMP, NAND */
 NAND, /* NAND, LIMP, AND */
 XOR, /* NAND, LIMP, BIIMP */
 XOR, /* NAND, LIMP, IMP */
 NLIMP, /* NAND, LIMP, LIMP */
 NPI1, /* NAND, LIMP, OR */
 NLIMP, /* NAND, LIMP, K1 */
 K1, /* NAND, OR, K0 */
 NPI1, /* NAND, OR, PI1 */
 NPI2, /* NAND, OR, PI2 */
 K1, /* NAND, OR, NOR */
 LIMP, /* NAND, OR, NLIMP */
 LIMP, /* NAND, OR, NPI1 */
 IMP, /* NAND, OR, NIMP */
 IMP, /* NAND, OR, NPI2 */
 BIIMP, /* NAND, OR, XOR */
 BIIMP, /* NAND, OR, NAND */
 NAND, /* NAND, OR, AND */
 NAND, /* NAND, OR, BIIMP */
 NPI2, /* NAND, OR, IMP */
 NPI1, /* NAND, OR, LIMP */
 NOR, /* NAND, OR, OR */
 NOR, /* NAND, OR, K1 */
 K1, /* NAND, K1, K0 */
 NPI1, /* NAND, K1, PI1 */
 NPI2, /* NAND, K1, PI2 */
 OR, /* NAND, K1, NOR */
 LIMP, /* NAND, K1, NLIMP */
 PI1, /* NAND, K1, NPI1 */
 IMP, /* NAND, K1, NIMP */
 PI2, /* NAND, K1, NPI2 */
 BIIMP, /* NAND, K1, XOR */
 AND, /* NAND, K1, NAND */
 NAND, /* NAND, K1, AND */
 XOR, /* NAND, K1, BIIMP */
 NIMP, /* NAND, K1, IMP */
 NLIMP, /* NAND, K1, LIMP */
 NOR, /* NAND, K1, OR */
 K0, /* NAND, K1, K1 */
 K0, /* AND, K0, K0 */
 K0, /* AND, K0, PI1 */
 K0, /* AND, K0, PI2 */
 K0, /* AND, K0, NOR */
 K0, /* AND, K0, NLIMP */
 K0, /* AND, K0, NPI1 */
 K0, /* AND, K0, NIMP */
 K0, /* AND, K0, NPI2 */
 K0, /* AND, K0, XOR */
 K0, /* AND, K0, NAND */
 K0, /* AND, K0, AND */
 K0, /* AND, K0, BIIMP */
 K0, /* AND, K0, IMP */
 K0, /* AND, K0, LIMP */
 K0, /* AND, K0, OR */
 K0, /* AND, K0, K1 */
 K0, /* AND, PI1, K0 */
 PI1, /* AND, PI1, PI1 */
 AND, /* AND, PI1, PI2 */
 K0, /* AND, PI1, NOR */
 K0, /* AND, PI1, NLIMP */
 K0, /* AND, PI1, NPI1 */
 NIMP, /* AND, PI1, NIMP */
 NIMP, /* AND, PI1, NPI2 */
 NIMP, /* AND, PI1, XOR */
 NIMP, /* AND, PI1, NAND */
 AND, /* AND, PI1, AND */
 AND, /* AND, PI1, BIIMP */
 AND, /* AND, PI1, IMP */
 PI1, /* AND, PI1, LIMP */
 PI1, /* AND, PI1, OR */
 PI1, /* AND, PI1, K1 */
 K0, /* AND, PI2, K0 */
 AND, /* AND, PI2, PI1 */
 PI2, /* AND, PI2, PI2 */
 K0, /* AND, PI2, NOR */
 NLIMP, /* AND, PI2, NLIMP */
 NLIMP, /* AND, PI2, NPI1 */
 K0, /* AND, PI2, NIMP */
 K0, /* AND, PI2, NPI2 */
 NLIMP, /* AND, PI2, XOR */
 NLIMP, /* AND, PI2, NAND */
 AND, /* AND, PI2, AND */
 AND, /* AND, PI2, BIIMP */
 PI2, /* AND, PI2, IMP */
 AND, /* AND, PI2, LIMP */
 PI2, /* AND, PI2, OR */
 PI2, /* AND, PI2, K1 */
 K0, /* AND, NOR, K0 */
 K0, /* AND, NOR, PI1 */
 K0, /* AND, NOR, PI2 */
 NOR, /* AND, NOR, NOR */
 K0, /* AND, NOR, NLIMP */
 NOR, /* AND, NOR, NPI1 */
 K0, /* AND, NOR, NIMP */
 NOR, /* AND, NOR, NPI2 */
 K0, /* AND, NOR, XOR */
 NOR, /* AND, NOR, NAND */
 K0, /* AND, NOR, AND */
 NOR, /* AND, NOR, BIIMP */
 NOR, /* AND, NOR, IMP */
 NOR, /* AND, NOR, LIMP */
 K0, /* AND, NOR, OR */
 NOR, /* AND, NOR, K1 */
 K0, /* AND, NLIMP, K0 */
 K0, /* AND, NLIMP, PI1 */
 NLIMP, /* AND, NLIMP, PI2 */
 K0, /* AND, NLIMP, NOR */
 NLIMP, /* AND, NLIMP, NLIMP */
 NLIMP, /* AND, NLIMP, NPI1 */
 K0, /* AND, NLIMP, NIMP */
 K0, /* AND, NLIMP, NPI2 */
 NLIMP, /* AND, NLIMP, XOR */
 NLIMP, /* AND, NLIMP, NAND */
 K0, /* AND, NLIMP, AND */
 K0, /* AND, NLIMP, BIIMP */
 NLIMP, /* AND, NLIMP, IMP */
 K0, /* AND, NLIMP, LIMP */
 NLIMP, /* AND, NLIMP, OR */
 NLIMP, /* AND, NLIMP, K1 */
 K0, /* AND, NPI1, K0 */
 K0, /* AND, NPI1, PI1 */
 NLIMP, /* AND, NPI1, PI2 */
 NOR, /* AND, NPI1, NOR */
 NLIMP, /* AND, NPI1, NLIMP */
 NPI1, /* AND, NPI1, NPI1 */
 K0, /* AND, NPI1, NIMP */
 NOR, /* AND, NPI1, NPI2 */
 NLIMP, /* AND, NPI1, XOR */
 NPI1, /* AND, NPI1, NAND */
 K0, /* AND, NPI1, AND */
 NOR, /* AND, NPI1, BIIMP */
 NPI1, /* AND, NPI1, IMP */
 NOR, /* AND, NPI1, LIMP */
 NLIMP, /* AND, NPI1, OR */
 NPI1, /* AND, NPI1, K1 */
 K0, /* AND, NIMP, K0 */
 NIMP, /* AND, NIMP, PI1 */
 K0, /* AND, NIMP, PI2 */
 K0, /* AND, NIMP, NOR */
 K0, /* AND, NIMP, NLIMP */
 K0, /* AND, NIMP, NPI1 */
 NIMP, /* AND, NIMP, NIMP */
 NIMP, /* AND, NIMP, NPI2 */
 NIMP, /* AND, NIMP, XOR */
 NIMP, /* AND, NIMP, NAND */
 K0, /* AND, NIMP, AND */
 K0, /* AND, NIMP, BIIMP */
 K0, /* AND, NIMP, IMP */
 NIMP, /* AND, NIMP, LIMP */
 NIMP, /* AND, NIMP, OR */
 NIMP, /* AND, NIMP, K1 */
 K0, /* AND, NPI2, K0 */
 NIMP, /* AND, NPI2, PI1 */
 K0, /* AND, NPI2, PI2 */
 NOR, /* AND, NPI2, NOR */
 K0, /* AND, NPI2, NLIMP */
 NOR, /* AND, NPI2, NPI1 */
 NIMP, /* AND, NPI2, NIMP */
 NPI2, /* AND, NPI2, NPI2 */
 NIMP, /* AND, NPI2, XOR */
 NPI2, /* AND, NPI2, NAND */
 K0, /* AND, NPI2, AND */
 NOR, /* AND, NPI2, BIIMP */
 NOR, /* AND, NPI2, IMP */
 NPI2, /* AND, NPI2, LIMP */
 NIMP, /* AND, NPI2, OR */
 NPI2, /* AND, NPI2, K1 */
 K0, /* AND, XOR, K0 */
 NIMP, /* AND, XOR, PI1 */
 NLIMP, /* AND, XOR, PI2 */
 K0, /* AND, XOR, NOR */
 NLIMP, /* AND, XOR, NLIMP */
 NLIMP, /* AND, XOR, NPI1 */
 NIMP, /* AND, XOR, NIMP */
 NIMP, /* AND, XOR, NPI2 */
 XOR, /* AND, XOR, XOR */
 XOR, /* AND, XOR, NAND */
 K0, /* AND, XOR, AND */
 K0, /* AND, XOR, BIIMP */
 NLIMP, /* AND, XOR, IMP */
 NIMP, /* AND, XOR, LIMP */
 XOR, /* AND, XOR, OR */
 XOR, /* AND, XOR, K1 */
 K0, /* AND, NAND, K0 */
 NIMP, /* AND, NAND, PI1 */
 NLIMP, /* AND, NAND, PI2 */
 NOR, /* AND, NAND, NOR */
 NLIMP, /* AND, NAND, NLIMP */
 NPI1, /* AND, NAND, NPI1 */
 NIMP, /* AND, NAND, NIMP */
 NPI2, /* AND, NAND, NPI2 */
 XOR, /* AND, NAND, XOR */
 NAND, /* AND, NAND, NAND */
 K0, /* AND, NAND, AND */
 NOR, /* AND, NAND, BIIMP */
 NPI1, /* AND, NAND, IMP */
 NPI2, /* AND, NAND, LIMP */
 XOR, /* AND, NAND, OR */
 NAND, /* AND, NAND, K1 */
 K0, /* AND, AND, K0 */
 AND, /* AND, AND, PI1 */
 AND, /* AND, AND, PI2 */
 K0, /* AND, AND, NOR */
 K0, /* AND, AND, NLIMP */
 K0, /* AND, AND, NPI1 */
 K0, /* AND, AND, NIMP */
 K0, /* AND, AND, NPI2 */
 K0, /* AND, AND, XOR */
 K0, /* AND, AND, NAND */
 AND, /* AND, AND, AND */
 AND, /* AND, AND, BIIMP */
 AND, /* AND, AND, IMP */
 AND, /* AND, AND, LIMP */
 AND, /* AND, AND, OR */
 AND, /* AND, AND, K1 */
 K0, /* AND, BIIMP, K0 */
 AND, /* AND, BIIMP, PI1 */
 AND, /* AND, BIIMP, PI2 */
 NOR, /* AND, BIIMP, NOR */
 K0, /* AND, BIIMP, NLIMP */
 NOR, /* AND, BIIMP, NPI1 */
 K0, /* AND, BIIMP, NIMP */
 NOR, /* AND, BIIMP, NPI2 */
 K0, /* AND, BIIMP, XOR */
 NOR, /* AND, BIIMP, NAND */
 AND, /* AND, BIIMP, AND */
 BIIMP, /* AND, BIIMP, BIIMP */
 BIIMP, /* AND, BIIMP, IMP */
 BIIMP, /* AND, BIIMP, LIMP */
 AND, /* AND, BIIMP, OR */
 BIIMP, /* AND, BIIMP, K1 */
 K0, /* AND, IMP, K0 */
 AND, /* AND, IMP, PI1 */
 PI2, /* AND, IMP, PI2 */
 NOR, /* AND, IMP, NOR */
 NLIMP, /* AND, IMP, NLIMP */
 NPI1, /* AND, IMP, NPI1 */
 K0, /* AND, IMP, NIMP */
 NOR, /* AND, IMP, NPI2 */
 NLIMP, /* AND, IMP, XOR */
 NPI1, /* AND, IMP, NAND */
 AND, /* AND, IMP, AND */
 BIIMP, /* AND, IMP, BIIMP */
 IMP, /* AND, IMP, IMP */
 BIIMP, /* AND, IMP, LIMP */
 PI2, /* AND, IMP, OR */
 IMP, /* AND, IMP, K1 */
 K0, /* AND, LIMP, K0 */
 PI1, /* AND, LIMP, PI1 */
 AND, /* AND, LIMP, PI2 */
 NOR, /* AND, LIMP, NOR */
 K0, /* AND, LIMP, NLIMP */
 NOR, /* AND, LIMP, NPI1 */
 NIMP, /* AND, LIMP, NIMP */
 NPI2, /* AND, LIMP, NPI2 */
 NIMP, /* AND, LIMP, XOR */
 NPI2, /* AND, LIMP, NAND */
 AND, /* AND, LIMP, AND */
 BIIMP, /* AND, LIMP, BIIMP */
 BIIMP, /* AND, LIMP, IMP */
 LIMP, /* AND, LIMP, LIMP */
 PI1, /* AND, LIMP, OR */
 LIMP, /* AND, LIMP, K1 */
 K0, /* AND, OR, K0 */
 PI1, /* AND, OR, PI1 */
 PI2, /* AND, OR, PI2 */
 K0, /* AND, OR, NOR */
 NLIMP, /* AND, OR, NLIMP */
 NLIMP, /* AND, OR, NPI1 */
 NIMP, /* AND, OR, NIMP */
 NIMP, /* AND, OR, NPI2 */
 XOR, /* AND, OR, XOR */
 XOR, /* AND, OR, NAND */
 AND, /* AND, OR, AND */
 AND, /* AND, OR, BIIMP */
 PI2, /* AND, OR, IMP */
 PI1, /* AND, OR, LIMP */
 OR, /* AND, OR, OR */
 OR, /* AND, OR, K1 */
 K0, /* AND, K1, K0 */
 PI1, /* AND, K1, PI1 */
 PI2, /* AND, K1, PI2 */
 NOR, /* AND, K1, NOR */
 NLIMP, /* AND, K1, NLIMP */
 NPI1, /* AND, K1, NPI1 */
 NIMP, /* AND, K1, NIMP */
 NPI2, /* AND, K1, NPI2 */
 XOR, /* AND, K1, XOR */
 NAND, /* AND, K1, NAND */
 AND, /* AND, K1, AND */
 BIIMP, /* AND, K1, BIIMP */
 IMP, /* AND, K1, IMP */
 LIMP, /* AND, K1, LIMP */
 OR, /* AND, K1, OR */
 K1, /* AND, K1, K1 */
 K1, /* BIIMP, K0, K0 */
 NPI1, /* BIIMP, K0, PI1 */
 NPI2, /* BIIMP, K0, PI2 */
 OR, /* BIIMP, K0, NOR */
 LIMP, /* BIIMP, K0, NLIMP */
 PI1, /* BIIMP, K0, NPI1 */
 IMP, /* BIIMP, K0, NIMP */
 PI2, /* BIIMP, K0, NPI2 */
 BIIMP, /* BIIMP, K0, XOR */
 AND, /* BIIMP, K0, NAND */
 NAND, /* BIIMP, K0, AND */
 XOR, /* BIIMP, K0, BIIMP */
 NIMP, /* BIIMP, K0, IMP */
 NLIMP, /* BIIMP, K0, LIMP */
 NOR, /* BIIMP, K0, OR */
 K0, /* BIIMP, K0, K1 */
 NPI1, /* BIIMP, PI1, K0 */
 K1, /* BIIMP, PI1, PI1 */
 BIIMP, /* BIIMP, PI1, PI2 */
 NLIMP, /* BIIMP, PI1, NOR */
 NOR, /* BIIMP, PI1, NLIMP */
 K0, /* BIIMP, PI1, NPI1 */
 NAND, /* BIIMP, PI1, NIMP */
 XOR, /* BIIMP, PI1, NPI2 */
 NPI2, /* BIIMP, PI1, XOR */
 NIMP, /* BIIMP, PI1, NAND */
 IMP, /* BIIMP, PI1, AND */
 PI2, /* BIIMP, PI1, BIIMP */
 AND, /* BIIMP, PI1, IMP */
 OR, /* BIIMP, PI1, LIMP */
 LIMP, /* BIIMP, PI1, OR */
 PI1, /* BIIMP, PI1, K1 */
 NPI2, /* BIIMP, PI2, K0 */
 BIIMP, /* BIIMP, PI2, PI1 */
 K1, /* BIIMP, PI2, PI2 */
 NIMP, /* BIIMP, PI2, NOR */
 NAND, /* BIIMP, PI2, NLIMP */
 XOR, /* BIIMP, PI2, NPI1 */
 NOR, /* BIIMP, PI2, NIMP */
 K0, /* BIIMP, PI2, NPI2 */
 NPI1, /* BIIMP, PI2, XOR */
 NLIMP, /* BIIMP, PI2, NAND */
 LIMP, /* BIIMP, PI2, AND */
 PI1, /* BIIMP, PI2, BIIMP */
 OR, /* BIIMP, PI2, IMP */
 AND, /* BIIMP, PI2, LIMP */
 IMP, /* BIIMP, PI2, OR */
 PI2, /* BIIMP, PI2, K1 */
 OR, /* BIIMP, NOR, K0 */
 NLIMP, /* BIIMP, NOR, PI1 */
 NIMP, /* BIIMP, NOR, PI2 */
 K1, /* BIIMP, NOR, NOR */
 PI1, /* BIIMP, NOR, NLIMP */
 LIMP, /* BIIMP, NOR, NPI1 */
 PI2, /* BIIMP, NOR, NIMP */
 IMP, /* BIIMP, NOR, NPI2 */
 AND, /* BIIMP, NOR, XOR */
 BIIMP, /* BIIMP, NOR, NAND */
 XOR, /* BIIMP, NOR, AND */
 NAND, /* BIIMP, NOR, BIIMP */
 NPI2, /* BIIMP, NOR, IMP */
 NPI1, /* BIIMP, NOR, LIMP */
 K0, /* BIIMP, NOR, OR */
 NOR, /* BIIMP, NOR, K1 */
 LIMP, /* BIIMP, NLIMP, K0 */
 NOR, /* BIIMP, NLIMP, PI1 */
 NAND, /* BIIMP, NLIMP, PI2 */
 PI1, /* BIIMP, NLIMP, NOR */
 K1, /* BIIMP, NLIMP, NLIMP */
 OR, /* BIIMP, NLIMP, NPI1 */
 BIIMP, /* BIIMP, NLIMP, NIMP */
 AND, /* BIIMP, NLIMP, NPI2 */
 IMP, /* BIIMP, NLIMP, XOR */
 PI2, /* BIIMP, NLIMP, NAND */
 NPI2, /* BIIMP, NLIMP, AND */
 NIMP, /* BIIMP, NLIMP, BIIMP */
 XOR, /* BIIMP, NLIMP, IMP */
 K0, /* BIIMP, NLIMP, LIMP */
 NPI1, /* BIIMP, NLIMP, OR */
 NLIMP, /* BIIMP, NLIMP, K1 */
 PI1, /* BIIMP, NPI1, K0 */
 K0, /* BIIMP, NPI1, PI1 */
 XOR, /* BIIMP, NPI1, PI2 */
 LIMP, /* BIIMP, NPI1, NOR */
 OR, /* BIIMP, NPI1, NLIMP */
 K1, /* BIIMP, NPI1, NPI1 */
 AND, /* BIIMP, NPI1, NIMP */
 BIIMP, /* BIIMP, NPI1, NPI2 */
 PI2, /* BIIMP, NPI1, XOR */
 IMP, /* BIIMP, NPI1, NAND */
 NIMP, /* BIIMP, NPI1, AND */
 NPI2, /* BIIMP, NPI1, BIIMP */
 NAND, /* BIIMP, NPI1, IMP */
 NOR, /* BIIMP, NPI1, LIMP */
 NLIMP, /* BIIMP, NPI1, OR */
 NPI1, /* BIIMP, NPI1, K1 */
 IMP, /* BIIMP, NIMP, K0 */
 NAND, /* BIIMP, NIMP, PI1 */
 NOR, /* BIIMP, NIMP, PI2 */
 PI2, /* BIIMP, NIMP, NOR */
 BIIMP, /* BIIMP, NIMP, NLIMP */
 AND, /* BIIMP, NIMP, NPI1 */
 K1, /* BIIMP, NIMP, NIMP */
 OR, /* BIIMP, NIMP, NPI2 */
 LIMP, /* BIIMP, NIMP, XOR */
 PI1, /* BIIMP, NIMP, NAND */
 NPI1, /* BIIMP, NIMP, AND */
 NLIMP, /* BIIMP, NIMP, BIIMP */
 K0, /* BIIMP, NIMP, IMP */
 XOR, /* BIIMP, NIMP, LIMP */
 NPI2, /* BIIMP, NIMP, OR */
 NIMP, /* BIIMP, NIMP, K1 */
 PI2, /* BIIMP, NPI2, K0 */
 XOR, /* BIIMP, NPI2, PI1 */
 K0, /* BIIMP, NPI2, PI2 */
 IMP, /* BIIMP, NPI2, NOR */
 AND, /* BIIMP, NPI2, NLIMP */
 BIIMP, /* BIIMP, NPI2, NPI1 */
 OR, /* BIIMP, NPI2, NIMP */
 K1, /* BIIMP, NPI2, NPI2 */
 PI1, /* BIIMP, NPI2, XOR */
 LIMP, /* BIIMP, NPI2, NAND */
 NLIMP, /* BIIMP, NPI2, AND */
 NPI1, /* BIIMP, NPI2, BIIMP */
 NOR, /* BIIMP, NPI2, IMP */
 NAND, /* BIIMP, NPI2, LIMP */
 NIMP, /* BIIMP, NPI2, OR */
 NPI2, /* BIIMP, NPI2, K1 */
 BIIMP, /* BIIMP, XOR, K0 */
 NPI2, /* BIIMP, XOR, PI1 */
 NPI1, /* BIIMP, XOR, PI2 */
 AND, /* BIIMP, XOR, NOR */
 IMP, /* BIIMP, XOR, NLIMP */
 PI2, /* BIIMP, XOR, NPI1 */
 LIMP, /* BIIMP, XOR, NIMP */
 PI1, /* BIIMP, XOR, NPI2 */
 K1, /* BIIMP, XOR, XOR */
 OR, /* BIIMP, XOR, NAND */
 NOR, /* BIIMP, XOR, AND */
 K0, /* BIIMP, XOR, BIIMP */
 NLIMP, /* BIIMP, XOR, IMP */
 NIMP, /* BIIMP, XOR, LIMP */
 NAND, /* BIIMP, XOR, OR */
 XOR, /* BIIMP, XOR, K1 */
 AND, /* BIIMP, NAND, K0 */
 NIMP, /* BIIMP, NAND, PI1 */
 NLIMP, /* BIIMP, NAND, PI2 */
 BIIMP, /* BIIMP, NAND, NOR */
 PI2, /* BIIMP, NAND, NLIMP */
 IMP, /* BIIMP, NAND, NPI1 */
 PI1, /* BIIMP, NAND, NIMP */
 LIMP, /* BIIMP, NAND, NPI2 */
 OR, /* BIIMP, NAND, XOR */
 K1, /* BIIMP, NAND, NAND */
 K0, /* BIIMP, NAND, AND */
 NOR, /* BIIMP, NAND, BIIMP */
 NPI1, /* BIIMP, NAND, IMP */
 NPI2, /* BIIMP, NAND, LIMP */
 XOR, /* BIIMP, NAND, OR */
 NAND, /* BIIMP, NAND, K1 */
 NAND, /* BIIMP, AND, K0 */
 IMP, /* BIIMP, AND, PI1 */
 LIMP, /* BIIMP, AND, PI2 */
 XOR, /* BIIMP, AND, NOR */
 NPI2, /* BIIMP, AND, NLIMP */
 NIMP, /* BIIMP, AND, NPI1 */
 NPI1, /* BIIMP, AND, NIMP */
 NLIMP, /* BIIMP, AND, NPI2 */
 NOR, /* BIIMP, AND, XOR */
 K0, /* BIIMP, AND, NAND */
 K1, /* BIIMP, AND, AND */
 OR, /* BIIMP, AND, BIIMP */
 PI1, /* BIIMP, AND, IMP */
 PI2, /* BIIMP, AND, LIMP */
 BIIMP, /* BIIMP, AND, OR */
 AND, /* BIIMP, AND, K1 */
 XOR, /* BIIMP, BIIMP, K0 */
 PI2, /* BIIMP, BIIMP, PI1 */
 PI1, /* BIIMP, BIIMP, PI2 */
 NAND, /* BIIMP, BIIMP, NOR */
 NIMP, /* BIIMP, BIIMP, NLIMP */
 NPI2, /* BIIMP, BIIMP, NPI1 */
 NLIMP, /* BIIMP, BIIMP, NIMP */
 NPI1, /* BIIMP, BIIMP, NPI2 */
 K0, /* BIIMP, BIIMP, XOR */
 NOR, /* BIIMP, BIIMP, NAND */
 OR, /* BIIMP, BIIMP, AND */
 K1, /* BIIMP, BIIMP, BIIMP */
 LIMP, /* BIIMP, BIIMP, IMP */
 IMP, /* BIIMP, BIIMP, LIMP */
 AND, /* BIIMP, BIIMP, OR */
 BIIMP, /* BIIMP, BIIMP, K1 */
 NIMP, /* BIIMP, IMP, K0 */
 AND, /* BIIMP, IMP, PI1 */
 OR, /* BIIMP, IMP, PI2 */
 NPI2, /* BIIMP, IMP, NOR */
 XOR, /* BIIMP, IMP, NLIMP */
 NAND, /* BIIMP, IMP, NPI1 */
 K0, /* BIIMP, IMP, NIMP */
 NOR, /* BIIMP, IMP, NPI2 */
 NLIMP, /* BIIMP, IMP, XOR */
 NPI1, /* BIIMP, IMP, NAND */
 PI1, /* BIIMP, IMP, AND */
 LIMP, /* BIIMP, IMP, BIIMP */
 K1, /* BIIMP, IMP, IMP */
 BIIMP, /* BIIMP, IMP, LIMP */
 PI2, /* BIIMP, IMP, OR */
 IMP, /* BIIMP, IMP, K1 */
 NLIMP, /* BIIMP, LIMP, K0 */
 OR, /* BIIMP, LIMP, PI1 */
 AND, /* BIIMP, LIMP, PI2 */
 NPI1, /* BIIMP, LIMP, NOR */
 K0, /* BIIMP, LIMP, NLIMP */
 NOR, /* BIIMP, LIMP, NPI1 */
 XOR, /* BIIMP, LIMP, NIMP */
 NAND, /* BIIMP, LIMP, NPI2 */
 NIMP, /* BIIMP, LIMP, XOR */
 NPI2, /* BIIMP, LIMP, NAND */
 PI2, /* BIIMP, LIMP, AND */
 IMP, /* BIIMP, LIMP, BIIMP */
 BIIMP, /* BIIMP, LIMP, IMP */
 K1, /* BIIMP, LIMP, LIMP */
 PI1, /* BIIMP, LIMP, OR */
 LIMP, /* BIIMP, LIMP, K1 */
 NOR, /* BIIMP, OR, K0 */
 LIMP, /* BIIMP, OR, PI1 */
 IMP, /* BIIMP, OR, PI2 */
 K0, /* BIIMP, OR, NOR */
 NPI1, /* BIIMP, OR, NLIMP */
 NLIMP, /* BIIMP, OR, NPI1 */
 NPI2, /* BIIMP, OR, NIMP */
 NIMP, /* BIIMP, OR, NPI2 */
 NAND, /* BIIMP, OR, XOR */
 XOR, /* BIIMP, OR, NAND */
 BIIMP, /* BIIMP, OR, AND */
 AND, /* BIIMP, OR, BIIMP */
 PI2, /* BIIMP, OR, IMP */
 PI1, /* BIIMP, OR, LIMP */
 K1, /* BIIMP, OR, OR */
 OR, /* BIIMP, OR, K1 */
 K0, /* BIIMP, K1, K0 */
 PI1, /* BIIMP, K1, PI1 */
 PI2, /* BIIMP, K1, PI2 */
 NOR, /* BIIMP, K1, NOR */
 NLIMP, /* BIIMP, K1, NLIMP */
 NPI1, /* BIIMP, K1, NPI1 */
 NIMP, /* BIIMP, K1, NIMP */
 NPI2, /* BIIMP, K1, NPI2 */
 XOR, /* BIIMP, K1, XOR */
 NAND, /* BIIMP, K1, NAND */
 AND, /* BIIMP, K1, AND */
 BIIMP, /* BIIMP, K1, BIIMP */
 IMP, /* BIIMP, K1, IMP */
 LIMP, /* BIIMP, K1, LIMP */
 OR, /* BIIMP, K1, OR */
 K1, /* BIIMP, K1, K1 */
 K1, /* IMP, K0, K0 */
 K1, /* IMP, K0, PI1 */
 K1, /* IMP, K0, PI2 */
 K1, /* IMP, K0, NOR */
 K1, /* IMP, K0, NLIMP */
 K1, /* IMP, K0, NPI1 */
 K1, /* IMP, K0, NIMP */
 K1, /* IMP, K0, NPI2 */
 K1, /* IMP, K0, XOR */
 K1, /* IMP, K0, NAND */
 K1, /* IMP, K0, AND */
 K1, /* IMP, K0, BIIMP */
 K1, /* IMP, K0, IMP */
 K1, /* IMP, K0, LIMP */
 K1, /* IMP, K0, OR */
 K1, /* IMP, K0, K1 */
 NPI1, /* IMP, PI1, K0 */
 K1, /* IMP, PI1, PI1 */
 IMP, /* IMP, PI1, PI2 */
 NPI1, /* IMP, PI1, NOR */
 NPI1, /* IMP, PI1, NLIMP */
 NPI1, /* IMP, PI1, NPI1 */
 NAND, /* IMP, PI1, NIMP */
 NAND, /* IMP, PI1, NPI2 */
 NAND, /* IMP, PI1, XOR */
 NAND, /* IMP, PI1, NAND */
 IMP, /* IMP, PI1, AND */
 IMP, /* IMP, PI1, BIIMP */
 IMP, /* IMP, PI1, IMP */
 K1, /* IMP, PI1, LIMP */
 K1, /* IMP, PI1, OR */
 K1, /* IMP, PI1, K1 */
 NPI2, /* IMP, PI2, K0 */
 LIMP, /* IMP, PI2, PI1 */
 K1, /* IMP, PI2, PI2 */
 NPI2, /* IMP, PI2, NOR */
 NAND, /* IMP, PI2, NLIMP */
 NAND, /* IMP, PI2, NPI1 */
 NPI2, /* IMP, PI2, NIMP */
 NPI2, /* IMP, PI2, NPI2 */
 NAND, /* IMP, PI2, XOR */
 NAND, /* IMP, PI2, NAND */
 LIMP, /* IMP, PI2, AND */
 LIMP, /* IMP, PI2, BIIMP */
 K1, /* IMP, PI2, IMP */
 LIMP, /* IMP, PI2, LIMP */
 K1, /* IMP, PI2, OR */
 K1, /* IMP, PI2, K1 */
 OR, /* IMP, NOR, K0 */
 OR, /* IMP, NOR, PI1 */
 OR, /* IMP, NOR, PI2 */
 K1, /* IMP, NOR, NOR */
 OR, /* IMP, NOR, NLIMP */
 K1, /* IMP, NOR, NPI1 */
 OR, /* IMP, NOR, NIMP */
 K1, /* IMP, NOR, NPI2 */
 OR, /* IMP, NOR, XOR */
 K1, /* IMP, NOR, NAND */
 OR, /* IMP, NOR, AND */
 K1, /* IMP, NOR, BIIMP */
 K1, /* IMP, NOR, IMP */
 K1, /* IMP, NOR, LIMP */
 OR, /* IMP, NOR, OR */
 K1, /* IMP, NOR, K1 */
 LIMP, /* IMP, NLIMP, K0 */
 LIMP, /* IMP, NLIMP, PI1 */
 K1, /* IMP, NLIMP, PI2 */
 LIMP, /* IMP, NLIMP, NOR */
 K1, /* IMP, NLIMP, NLIMP */
 K1, /* IMP, NLIMP, NPI1 */
 LIMP, /* IMP, NLIMP, NIMP */
 LIMP, /* IMP, NLIMP, NPI2 */
 K1, /* IMP, NLIMP, XOR */
 K1, /* IMP, NLIMP, NAND */
 LIMP, /* IMP, NLIMP, AND */
 LIMP, /* IMP, NLIMP, BIIMP */
 K1, /* IMP, NLIMP, IMP */
 LIMP, /* IMP, NLIMP, LIMP */
 K1, /* IMP, NLIMP, OR */
 K1, /* IMP, NLIMP, K1 */
 PI1, /* IMP, NPI1, K0 */
 PI1, /* IMP, NPI1, PI1 */
 OR, /* IMP, NPI1, PI2 */
 LIMP, /* IMP, NPI1, NOR */
 OR, /* IMP, NPI1, NLIMP */
 K1, /* IMP, NPI1, NPI1 */
 PI1, /* IMP, NPI1, NIMP */
 LIMP, /* IMP, NPI1, NPI2 */
 OR, /* IMP, NPI1, XOR */
 K1, /* IMP, NPI1, NAND */
 PI1, /* IMP, NPI1, AND */
 LIMP, /* IMP, NPI1, BIIMP */
 K1, /* IMP, NPI1, IMP */
 LIMP, /* IMP, NPI1, LIMP */
 OR, /* IMP, NPI1, OR */
 K1, /* IMP, NPI1, K1 */
 IMP, /* IMP, NIMP, K0 */
 K1, /* IMP, NIMP, PI1 */
 IMP, /* IMP, NIMP, PI2 */
 IMP, /* IMP, NIMP, NOR */
 IMP, /* IMP, NIMP, NLIMP */
 IMP, /* IMP, NIMP, NPI1 */
 K1, /* IMP, NIMP, NIMP */
 K1, /* IMP, NIMP, NPI2 */
 K1, /* IMP, NIMP, XOR */
 K1, /* IMP, NIMP, NAND */
 IMP, /* IMP, NIMP, AND */
 IMP, /* IMP, NIMP, BIIMP */
 IMP, /* IMP, NIMP, IMP */
 K1, /* IMP, NIMP, LIMP */
 K1, /* IMP, NIMP, OR */
 K1, /* IMP, NIMP, K1 */
 PI2, /* IMP, NPI2, K0 */
 OR, /* IMP, NPI2, PI1 */
 PI2, /* IMP, NPI2, PI2 */
 IMP, /* IMP, NPI2, NOR */
 PI2, /* IMP, NPI2, NLIMP */
 IMP, /* IMP, NPI2, NPI1 */
 OR, /* IMP, NPI2, NIMP */
 K1, /* IMP, NPI2, NPI2 */
 OR, /* IMP, NPI2, XOR */
 K1, /* IMP, NPI2, NAND */
 PI2, /* IMP, NPI2, AND */
 IMP, /* IMP, NPI2, BIIMP */
 IMP, /* IMP, NPI2, IMP */
 K1, /* IMP, NPI2, LIMP */
 OR, /* IMP, NPI2, OR */
 K1, /* IMP, NPI2, K1 */
 BIIMP, /* IMP, XOR, K0 */
 LIMP, /* IMP, XOR, PI1 */
 IMP, /* IMP, XOR, PI2 */
 BIIMP, /* IMP, XOR, NOR */
 IMP, /* IMP, XOR, NLIMP */
 IMP, /* IMP, XOR, NPI1 */
 LIMP, /* IMP, XOR, NIMP */
 LIMP, /* IMP, XOR, NPI2 */
 K1, /* IMP, XOR, XOR */
 K1, /* IMP, XOR, NAND */
 BIIMP, /* IMP, XOR, AND */
 BIIMP, /* IMP, XOR, BIIMP */
 IMP, /* IMP, XOR, IMP */
 LIMP, /* IMP, XOR, LIMP */
 K1, /* IMP, XOR, OR */
 K1, /* IMP, XOR, K1 */
 AND, /* IMP, NAND, K0 */
 PI1, /* IMP, NAND, PI1 */
 PI2, /* IMP, NAND, PI2 */
 BIIMP, /* IMP, NAND, NOR */
 PI2, /* IMP, NAND, NLIMP */
 IMP, /* IMP, NAND, NPI1 */
 PI1, /* IMP, NAND, NIMP */
 LIMP, /* IMP, NAND, NPI2 */
 OR, /* IMP, NAND, XOR */
 K1, /* IMP, NAND, NAND */
 AND, /* IMP, NAND, AND */
 BIIMP, /* IMP, NAND, BIIMP */
 IMP, /* IMP, NAND, IMP */
 LIMP, /* IMP, NAND, LIMP */
 OR, /* IMP, NAND, OR */
 K1, /* IMP, NAND, K1 */
 NAND, /* IMP, AND, K0 */
 K1, /* IMP, AND, PI1 */
 K1, /* IMP, AND, PI2 */
 NAND, /* IMP, AND, NOR */
 NAND, /* IMP, AND, NLIMP */
 NAND, /* IMP, AND, NPI1 */
 NAND, /* IMP, AND, NIMP */
 NAND, /* IMP, AND, NPI2 */
 NAND, /* IMP, AND, XOR */
 NAND, /* IMP, AND, NAND */
 K1, /* IMP, AND, AND */
 K1, /* IMP, AND, BIIMP */
 K1, /* IMP, AND, IMP */
 K1, /* IMP, AND, LIMP */
 K1, /* IMP, AND, OR */
 K1, /* IMP, AND, K1 */
 XOR, /* IMP, BIIMP, K0 */
 OR, /* IMP, BIIMP, PI1 */
 OR, /* IMP, BIIMP, PI2 */
 NAND, /* IMP, BIIMP, NOR */
 XOR, /* IMP, BIIMP, NLIMP */
 NAND, /* IMP, BIIMP, NPI1 */
 XOR, /* IMP, BIIMP, NIMP */
 NAND, /* IMP, BIIMP, NPI2 */
 XOR, /* IMP, BIIMP, XOR */
 NAND, /* IMP, BIIMP, NAND */
 OR, /* IMP, BIIMP, AND */
 K1, /* IMP, BIIMP, BIIMP */
 K1, /* IMP, BIIMP, IMP */
 K1, /* IMP, BIIMP, LIMP */
 OR, /* IMP, BIIMP, OR */
 K1, /* IMP, BIIMP, K1 */
 NIMP, /* IMP, IMP, K0 */
 PI1, /* IMP, IMP, PI1 */
 OR, /* IMP, IMP, PI2 */
 NPI2, /* IMP, IMP, NOR */
 XOR, /* IMP, IMP, NLIMP */
 NAND, /* IMP, IMP, NPI1 */
 NIMP, /* IMP, IMP, NIMP */
 NPI2, /* IMP, IMP, NPI2 */
 XOR, /* IMP, IMP, XOR */
 NAND, /* IMP, IMP, NAND */
 PI1, /* IMP, IMP, AND */
 LIMP, /* IMP, IMP, BIIMP */
 K1, /* IMP, IMP, IMP */
 LIMP, /* IMP, IMP, LIMP */
 OR, /* IMP, IMP, OR */
 K1, /* IMP, IMP, K1 */
 NLIMP, /* IMP, LIMP, K0 */
 OR, /* IMP, LIMP, PI1 */
 PI2, /* IMP, LIMP, PI2 */
 NPI1, /* IMP, LIMP, NOR */
 NLIMP, /* IMP, LIMP, NLIMP */
 NPI1, /* IMP, LIMP, NPI1 */
 XOR, /* IMP, LIMP, NIMP */
 NAND, /* IMP, LIMP, NPI2 */
 XOR, /* IMP, LIMP, XOR */
 NAND, /* IMP, LIMP, NAND */
 PI2, /* IMP, LIMP, AND */
 IMP, /* IMP, LIMP, BIIMP */
 IMP, /* IMP, LIMP, IMP */
 K1, /* IMP, LIMP, LIMP */
 OR, /* IMP, LIMP, OR */
 K1, /* IMP, LIMP, K1 */
 NOR, /* IMP, OR, K0 */
 LIMP, /* IMP, OR, PI1 */
 IMP, /* IMP, OR, PI2 */
 NOR, /* IMP, OR, NOR */
 NPI1, /* IMP, OR, NLIMP */
 NPI1, /* IMP, OR, NPI1 */
 NPI2, /* IMP, OR, NIMP */
 NPI2, /* IMP, OR, NPI2 */
 NAND, /* IMP, OR, XOR */
 NAND, /* IMP, OR, NAND */
 BIIMP, /* IMP, OR, AND */
 BIIMP, /* IMP, OR, BIIMP */
 IMP, /* IMP, OR, IMP */
 LIMP, /* IMP, OR, LIMP */
 K1, /* IMP, OR, OR */
 K1, /* IMP, OR, K1 */
 K0, /* IMP, K1, K0 */
 PI1, /* IMP, K1, PI1 */
 PI2, /* IMP, K1, PI2 */
 NOR, /* IMP, K1, NOR */
 NLIMP, /* IMP, K1, NLIMP */
 NPI1, /* IMP, K1, NPI1 */
 NIMP, /* IMP, K1, NIMP */
 NPI2, /* IMP, K1, NPI2 */
 XOR, /* IMP, K1, XOR */
 NAND, /* IMP, K1, NAND */
 AND, /* IMP, K1, AND */
 BIIMP, /* IMP, K1, BIIMP */
 IMP, /* IMP, K1, IMP */
 LIMP, /* IMP, K1, LIMP */
 OR, /* IMP, K1, OR */
 K1, /* IMP, K1, K1 */
 K1, /* LIMP, K0, K0 */
 NPI1, /* LIMP, K0, PI1 */
 NPI2, /* LIMP, K0, PI2 */
 OR, /* LIMP, K0, NOR */
 LIMP, /* LIMP, K0, NLIMP */
 PI1, /* LIMP, K0, NPI1 */
 IMP, /* LIMP, K0, NIMP */
 PI2, /* LIMP, K0, NPI2 */
 BIIMP, /* LIMP, K0, XOR */
 AND, /* LIMP, K0, NAND */
 NAND, /* LIMP, K0, AND */
 XOR, /* LIMP, K0, BIIMP */
 NIMP, /* LIMP, K0, IMP */
 NLIMP, /* LIMP, K0, LIMP */
 NOR, /* LIMP, K0, OR */
 K0, /* LIMP, K0, K1 */
 K1, /* LIMP, PI1, K0 */
 K1, /* LIMP, PI1, PI1 */
 LIMP, /* LIMP, PI1, PI2 */
 OR, /* LIMP, PI1, NOR */
 LIMP, /* LIMP, PI1, NLIMP */
 PI1, /* LIMP, PI1, NPI1 */
 K1, /* LIMP, PI1, NIMP */
 OR, /* LIMP, PI1, NPI2 */
 LIMP, /* LIMP, PI1, XOR */
 PI1, /* LIMP, PI1, NAND */
 K1, /* LIMP, PI1, AND */
 OR, /* LIMP, PI1, BIIMP */
 PI1, /* LIMP, PI1, IMP */
 OR, /* LIMP, PI1, LIMP */
 LIMP, /* LIMP, PI1, OR */
 PI1, /* LIMP, PI1, K1 */
 K1, /* LIMP, PI2, K0 */
 IMP, /* LIMP, PI2, PI1 */
 K1, /* LIMP, PI2, PI2 */
 OR, /* LIMP, PI2, NOR */
 K1, /* LIMP, PI2, NLIMP */
 OR, /* LIMP, PI2, NPI1 */
 IMP, /* LIMP, PI2, NIMP */
 PI2, /* LIMP, PI2, NPI2 */
 IMP, /* LIMP, PI2, XOR */
 PI2, /* LIMP, PI2, NAND */
 K1, /* LIMP, PI2, AND */
 OR, /* LIMP, PI2, BIIMP */
 OR, /* LIMP, PI2, IMP */
 PI2, /* LIMP, PI2, LIMP */
 IMP, /* LIMP, PI2, OR */
 PI2, /* LIMP, PI2, K1 */
 K1, /* LIMP, NOR, K0 */
 NPI1, /* LIMP, NOR, PI1 */
 NPI2, /* LIMP, NOR, PI2 */
 K1, /* LIMP, NOR, NOR */
 LIMP, /* LIMP, NOR, NLIMP */
 LIMP, /* LIMP, NOR, NPI1 */
 IMP, /* LIMP, NOR, NIMP */
 IMP, /* LIMP, NOR, NPI2 */
 BIIMP, /* LIMP, NOR, XOR */
 BIIMP, /* LIMP, NOR, NAND */
 NAND, /* LIMP, NOR, AND */
 NAND, /* LIMP, NOR, BIIMP */
 NPI2, /* LIMP, NOR, IMP */
 NPI1, /* LIMP, NOR, LIMP */
 NOR, /* LIMP, NOR, OR */
 NOR, /* LIMP, NOR, K1 */
 K1, /* LIMP, NLIMP, K0 */
 NPI1, /* LIMP, NLIMP, PI1 */
 NAND, /* LIMP, NLIMP, PI2 */
 OR, /* LIMP, NLIMP, NOR */
 K1, /* LIMP, NLIMP, NLIMP */
 OR, /* LIMP, NLIMP, NPI1 */
 IMP, /* LIMP, NLIMP, NIMP */
 PI2, /* LIMP, NLIMP, NPI2 */
 IMP, /* LIMP, NLIMP, XOR */
 PI2, /* LIMP, NLIMP, NAND */
 NAND, /* LIMP, NLIMP, AND */
 XOR, /* LIMP, NLIMP, BIIMP */
 XOR, /* LIMP, NLIMP, IMP */
 NLIMP, /* LIMP, NLIMP, LIMP */
 NPI1, /* LIMP, NLIMP, OR */
 NLIMP, /* LIMP, NLIMP, K1 */
 K1, /* LIMP, NPI1, K0 */
 NPI1, /* LIMP, NPI1, PI1 */
 NAND, /* LIMP, NPI1, PI2 */
 K1, /* LIMP, NPI1, NOR */
 K1, /* LIMP, NPI1, NLIMP */
 K1, /* LIMP, NPI1, NPI1 */
 IMP, /* LIMP, NPI1, NIMP */
 IMP, /* LIMP, NPI1, NPI2 */
 IMP, /* LIMP, NPI1, XOR */
 IMP, /* LIMP, NPI1, NAND */
 NAND, /* LIMP, NPI1, AND */
 NAND, /* LIMP, NPI1, BIIMP */
 NAND, /* LIMP, NPI1, IMP */
 NPI1, /* LIMP, NPI1, LIMP */
 NPI1, /* LIMP, NPI1, OR */
 NPI1, /* LIMP, NPI1, K1 */
 K1, /* LIMP, NIMP, K0 */
 NAND, /* LIMP, NIMP, PI1 */
 NPI2, /* LIMP, NIMP, PI2 */
 OR, /* LIMP, NIMP, NOR */
 LIMP, /* LIMP, NIMP, NLIMP */
 PI1, /* LIMP, NIMP, NPI1 */
 K1, /* LIMP, NIMP, NIMP */
 OR, /* LIMP, NIMP, NPI2 */
 LIMP, /* LIMP, NIMP, XOR */
 PI1, /* LIMP, NIMP, NAND */
 NAND, /* LIMP, NIMP, AND */
 XOR, /* LIMP, NIMP, BIIMP */
 NIMP, /* LIMP, NIMP, IMP */
 XOR, /* LIMP, NIMP, LIMP */
 NPI2, /* LIMP, NIMP, OR */
 NIMP, /* LIMP, NIMP, K1 */
 K1, /* LIMP, NPI2, K0 */
 NAND, /* LIMP, NPI2, PI1 */
 NPI2, /* LIMP, NPI2, PI2 */
 K1, /* LIMP, NPI2, NOR */
 LIMP, /* LIMP, NPI2, NLIMP */
 LIMP, /* LIMP, NPI2, NPI1 */
 K1, /* LIMP, NPI2, NIMP */
 K1, /* LIMP, NPI2, NPI2 */
 LIMP, /* LIMP, NPI2, XOR */
 LIMP, /* LIMP, NPI2, NAND */
 NAND, /* LIMP, NPI2, AND */
 NAND, /* LIMP, NPI2, BIIMP */
 NPI2, /* LIMP, NPI2, IMP */
 NAND, /* LIMP, NPI2, LIMP */
 NPI2, /* LIMP, NPI2, OR */
 NPI2, /* LIMP, NPI2, K1 */
 K1, /* LIMP, XOR, K0 */
 NAND, /* LIMP, XOR, PI1 */
 NAND, /* LIMP, XOR, PI2 */
 OR, /* LIMP, XOR, NOR */
 K1, /* LIMP, XOR, NLIMP */
 OR, /* LIMP, XOR, NPI1 */
 K1, /* LIMP, XOR, NIMP */
 OR, /* LIMP, XOR, NPI2 */
 K1, /* LIMP, XOR, XOR */
 OR, /* LIMP, XOR, NAND */
 NAND, /* LIMP, XOR, AND */
 XOR, /* LIMP, XOR, BIIMP */
 XOR, /* LIMP, XOR, IMP */
 XOR, /* LIMP, XOR, LIMP */
 NAND, /* LIMP, XOR, OR */
 XOR, /* LIMP, XOR, K1 */
 K1, /* LIMP, NAND, K0 */
 NAND, /* LIMP, NAND, PI1 */
 NAND, /* LIMP, NAND, PI2 */
 K1, /* LIMP, NAND, NOR */
 K1, /* LIMP, NAND, NLIMP */
 K1, /* LIMP, NAND, NPI1 */
 K1, /* LIMP, NAND, NIMP */
 K1, /* LIMP, NAND, NPI2 */
 K1, /* LIMP, NAND, XOR */
 K1, /* LIMP, NAND, NAND */
 NAND, /* LIMP, NAND, AND */
 NAND, /* LIMP, NAND, BIIMP */
 NAND, /* LIMP, NAND, IMP */
 NAND, /* LIMP, NAND, LIMP */
 NAND, /* LIMP, NAND, OR */
 NAND, /* LIMP, NAND, K1 */
 K1, /* LIMP, AND, K0 */
 IMP, /* LIMP, AND, PI1 */
 LIMP, /* LIMP, AND, PI2 */
 OR, /* LIMP, AND, NOR */
 LIMP, /* LIMP, AND, NLIMP */
 PI1, /* LIMP, AND, NPI1 */
 IMP, /* LIMP, AND, NIMP */
 PI2, /* LIMP, AND, NPI2 */
 BIIMP, /* LIMP, AND, XOR */
 AND, /* LIMP, AND, NAND */
 K1, /* LIMP, AND, AND */
 OR, /* LIMP, AND, BIIMP */
 PI1, /* LIMP, AND, IMP */
 PI2, /* LIMP, AND, LIMP */
 BIIMP, /* LIMP, AND, OR */
 AND, /* LIMP, AND, K1 */
 K1, /* LIMP, BIIMP, K0 */
 IMP, /* LIMP, BIIMP, PI1 */
 LIMP, /* LIMP, BIIMP, PI2 */
 K1, /* LIMP, BIIMP, NOR */
 LIMP, /* LIMP, BIIMP, NLIMP */
 LIMP, /* LIMP, BIIMP, NPI1 */
 IMP, /* LIMP, BIIMP, NIMP */
 IMP, /* LIMP, BIIMP, NPI2 */
 BIIMP, /* LIMP, BIIMP, XOR */
 BIIMP, /* LIMP, BIIMP, NAND */
 K1, /* LIMP, BIIMP, AND */
 K1, /* LIMP, BIIMP, BIIMP */
 LIMP, /* LIMP, BIIMP, IMP */
 IMP, /* LIMP, BIIMP, LIMP */
 BIIMP, /* LIMP, BIIMP, OR */
 BIIMP, /* LIMP, BIIMP, K1 */
 K1, /* LIMP, IMP, K0 */
 IMP, /* LIMP, IMP, PI1 */
 K1, /* LIMP, IMP, PI2 */
 K1, /* LIMP, IMP, NOR */
 K1, /* LIMP, IMP, NLIMP */
 K1, /* LIMP, IMP, NPI1 */
 IMP, /* LIMP, IMP, NIMP */
 IMP, /* LIMP, IMP, NPI2 */
 IMP, /* LIMP, IMP, XOR */
 IMP, /* LIMP, IMP, NAND */
 K1, /* LIMP, IMP, AND */
 K1, /* LIMP, IMP, BIIMP */
 K1, /* LIMP, IMP, IMP */
 IMP, /* LIMP, IMP, LIMP */
 IMP, /* LIMP, IMP, OR */
 IMP, /* LIMP, IMP, K1 */
 K1, /* LIMP, LIMP, K0 */
 K1, /* LIMP, LIMP, PI1 */
 LIMP, /* LIMP, LIMP, PI2 */
 K1, /* LIMP, LIMP, NOR */
 LIMP, /* LIMP, LIMP, NLIMP */
 LIMP, /* LIMP, LIMP, NPI1 */
 K1, /* LIMP, LIMP, NIMP */
 K1, /* LIMP, LIMP, NPI2 */
 LIMP, /* LIMP, LIMP, XOR */
 LIMP, /* LIMP, LIMP, NAND */
 K1, /* LIMP, LIMP, AND */
 K1, /* LIMP, LIMP, BIIMP */
 LIMP, /* LIMP, LIMP, IMP */
 K1, /* LIMP, LIMP, LIMP */
 LIMP, /* LIMP, LIMP, OR */
 LIMP, /* LIMP, LIMP, K1 */
 K1, /* LIMP, OR, K0 */
 K1, /* LIMP, OR, PI1 */
 K1, /* LIMP, OR, PI2 */
 OR, /* LIMP, OR, NOR */
 K1, /* LIMP, OR, NLIMP */
 OR, /* LIMP, OR, NPI1 */
 K1, /* LIMP, OR, NIMP */
 OR, /* LIMP, OR, NPI2 */
 K1, /* LIMP, OR, XOR */
 OR, /* LIMP, OR, NAND */
 K1, /* LIMP, OR, AND */
 OR, /* LIMP, OR, BIIMP */
 OR, /* LIMP, OR, IMP */
 OR, /* LIMP, OR, LIMP */
 K1, /* LIMP, OR, OR */
 OR, /* LIMP, OR, K1 */
 K1, /* LIMP, K1, K0 */
 K1, /* LIMP, K1, PI1 */
 K1, /* LIMP, K1, PI2 */
 K1, /* LIMP, K1, NOR */
 K1, /* LIMP, K1, NLIMP */
 K1, /* LIMP, K1, NPI1 */
 K1, /* LIMP, K1, NIMP */
 K1, /* LIMP, K1, NPI2 */
 K1, /* LIMP, K1, XOR */
 K1, /* LIMP, K1, NAND */
 K1, /* LIMP, K1, AND */
 K1, /* LIMP, K1, BIIMP */
 K1, /* LIMP, K1, IMP */
 K1, /* LIMP, K1, LIMP */
 K1, /* LIMP, K1, OR */
 K1, /* LIMP, K1, K1 */
 K0, /* OR, K0, K0 */
 PI1, /* OR, K0, PI1 */
 PI2, /* OR, K0, PI2 */
 NOR, /* OR, K0, NOR */
 NLIMP, /* OR, K0, NLIMP */
 NPI1, /* OR, K0, NPI1 */
 NIMP, /* OR, K0, NIMP */
 NPI2, /* OR, K0, NPI2 */
 XOR, /* OR, K0, XOR */
 NAND, /* OR, K0, NAND */
 AND, /* OR, K0, AND */
 BIIMP, /* OR, K0, BIIMP */
 IMP, /* OR, K0, IMP */
 LIMP, /* OR, K0, LIMP */
 OR, /* OR, K0, OR */
 K1, /* OR, K0, K1 */
 PI1, /* OR, PI1, K0 */
 PI1, /* OR, PI1, PI1 */
 OR, /* OR, PI1, PI2 */
 LIMP, /* OR, PI1, NOR */
 OR, /* OR, PI1, NLIMP */
 K1, /* OR, PI1, NPI1 */
 PI1, /* OR, PI1, NIMP */
 LIMP, /* OR, PI1, NPI2 */
 OR, /* OR, PI1, XOR */
 K1, /* OR, PI1, NAND */
 PI1, /* OR, PI1, AND */
 LIMP, /* OR, PI1, BIIMP */
 K1, /* OR, PI1, IMP */
 LIMP, /* OR, PI1, LIMP */
 OR, /* OR, PI1, OR */
 K1, /* OR, PI1, K1 */
 PI2, /* OR, PI2, K0 */
 OR, /* OR, PI2, PI1 */
 PI2, /* OR, PI2, PI2 */
 IMP, /* OR, PI2, NOR */
 PI2, /* OR, PI2, NLIMP */
 IMP, /* OR, PI2, NPI1 */
 OR, /* OR, PI2, NIMP */
 K1, /* OR, PI2, NPI2 */
 OR, /* OR, PI2, XOR */
 K1, /* OR, PI2, NAND */
 PI2, /* OR, PI2, AND */
 IMP, /* OR, PI2, BIIMP */
 IMP, /* OR, PI2, IMP */
 K1, /* OR, PI2, LIMP */
 OR, /* OR, PI2, OR */
 K1, /* OR, PI2, K1 */
 NOR, /* OR, NOR, K0 */
 LIMP, /* OR, NOR, PI1 */
 IMP, /* OR, NOR, PI2 */
 NOR, /* OR, NOR, NOR */
 NPI1, /* OR, NOR, NLIMP */
 NPI1, /* OR, NOR, NPI1 */
 NPI2, /* OR, NOR, NIMP */
 NPI2, /* OR, NOR, NPI2 */
 NAND, /* OR, NOR, XOR */
 NAND, /* OR, NOR, NAND */
 BIIMP, /* OR, NOR, AND */
 BIIMP, /* OR, NOR, BIIMP */
 IMP, /* OR, NOR, IMP */
 LIMP, /* OR, NOR, LIMP */
 K1, /* OR, NOR, OR */
 K1, /* OR, NOR, K1 */
 NLIMP, /* OR, NLIMP, K0 */
 OR, /* OR, NLIMP, PI1 */
 PI2, /* OR, NLIMP, PI2 */
 NPI1, /* OR, NLIMP, NOR */
 NLIMP, /* OR, NLIMP, NLIMP */
 NPI1, /* OR, NLIMP, NPI1 */
 XOR, /* OR, NLIMP, NIMP */
 NAND, /* OR, NLIMP, NPI2 */
 XOR, /* OR, NLIMP, XOR */
 NAND, /* OR, NLIMP, NAND */
 PI2, /* OR, NLIMP, AND */
 IMP, /* OR, NLIMP, BIIMP */
 IMP, /* OR, NLIMP, IMP */
 K1, /* OR, NLIMP, LIMP */
 OR, /* OR, NLIMP, OR */
 K1, /* OR, NLIMP, K1 */
 NPI1, /* OR, NPI1, K0 */
 K1, /* OR, NPI1, PI1 */
 IMP, /* OR, NPI1, PI2 */
 NPI1, /* OR, NPI1, NOR */
 NPI1, /* OR, NPI1, NLIMP */
 NPI1, /* OR, NPI1, NPI1 */
 NAND, /* OR, NPI1, NIMP */
 NAND, /* OR, NPI1, NPI2 */
 NAND, /* OR, NPI1, XOR */
 NAND, /* OR, NPI1, NAND */
 IMP, /* OR, NPI1, AND */
 IMP, /* OR, NPI1, BIIMP */
 IMP, /* OR, NPI1, IMP */
 K1, /* OR, NPI1, LIMP */
 K1, /* OR, NPI1, OR */
 K1, /* OR, NPI1, K1 */
 NIMP, /* OR, NIMP, K0 */
 PI1, /* OR, NIMP, PI1 */
 OR, /* OR, NIMP, PI2 */
 NPI2, /* OR, NIMP, NOR */
 XOR, /* OR, NIMP, NLIMP */
 NAND, /* OR, NIMP, NPI1 */
 NIMP, /* OR, NIMP, NIMP */
 NPI2, /* OR, NIMP, NPI2 */
 XOR, /* OR, NIMP, XOR */
 NAND, /* OR, NIMP, NAND */
 PI1, /* OR, NIMP, AND */
 LIMP, /* OR, NIMP, BIIMP */
 K1, /* OR, NIMP, IMP */
 LIMP, /* OR, NIMP, LIMP */
 OR, /* OR, NIMP, OR */
 K1, /* OR, NIMP, K1 */
 NPI2, /* OR, NPI2, K0 */
 LIMP, /* OR, NPI2, PI1 */
 K1, /* OR, NPI2, PI2 */
 NPI2, /* OR, NPI2, NOR */
 NAND, /* OR, NPI2, NLIMP */
 NAND, /* OR, NPI2, NPI1 */
 NPI2, /* OR, NPI2, NIMP */
 NPI2, /* OR, NPI2, NPI2 */
 NAND, /* OR, NPI2, XOR */
 NAND, /* OR, NPI2, NAND */
 LIMP, /* OR, NPI2, AND */
 LIMP, /* OR, NPI2, BIIMP */
 K1, /* OR, NPI2, IMP */
 LIMP, /* OR, NPI2, LIMP */
 K1, /* OR, NPI2, OR */
 K1, /* OR, NPI2, K1 */
 XOR, /* OR, XOR, K0 */
 OR, /* OR, XOR, PI1 */
 OR, /* OR, XOR, PI2 */
 NAND, /* OR, XOR, NOR */
 XOR, /* OR, XOR, NLIMP */
 NAND, /* OR, XOR, NPI1 */
 XOR, /* OR, XOR, NIMP */
 NAND, /* OR, XOR, NPI2 */
 XOR, /* OR, XOR, XOR */
 NAND, /* OR, XOR, NAND */
 OR, /* OR, XOR, AND */
 K1, /* OR, XOR, BIIMP */
 K1, /* OR, XOR, IMP */
 K1, /* OR, XOR, LIMP */
 OR, /* OR, XOR, OR */
 K1, /* OR, XOR, K1 */
 NAND, /* OR, NAND, K0 */
 K1, /* OR, NAND, PI1 */
 K1, /* OR, NAND, PI2 */
 NAND, /* OR, NAND, NOR */
 NAND, /* OR, NAND, NLIMP */
 NAND, /* OR, NAND, NPI1 */
 NAND, /* OR, NAND, NIMP */
 NAND, /* OR, NAND, NPI2 */
 NAND, /* OR, NAND, XOR */
 NAND, /* OR, NAND, NAND */
 K1, /* OR, NAND, AND */
 K1, /* OR, NAND, BIIMP */
 K1, /* OR, NAND, IMP */
 K1, /* OR, NAND, LIMP */
 K1, /* OR, NAND, OR */
 K1, /* OR, NAND, K1 */
 AND, /* OR, AND, K0 */
 PI1, /* OR, AND, PI1 */
 PI2, /* OR, AND, PI2 */
 BIIMP, /* OR, AND, NOR */
 PI2, /* OR, AND, NLIMP */
 IMP, /* OR, AND, NPI1 */
 PI1, /* OR, AND, NIMP */
 LIMP, /* OR, AND, NPI2 */
 OR, /* OR, AND, XOR */
 K1, /* OR, AND, NAND */
 AND, /* OR, AND, AND */
 BIIMP, /* OR, AND, BIIMP */
 IMP, /* OR, AND, IMP */
 LIMP, /* OR, AND, LIMP */
 OR, /* OR, AND, OR */
 K1, /* OR, AND, K1 */
 BIIMP, /* OR, BIIMP, K0 */
 LIMP, /* OR, BIIMP, PI1 */
 IMP, /* OR, BIIMP, PI2 */
 BIIMP, /* OR, BIIMP, NOR */
 IMP, /* OR, BIIMP, NLIMP */
 IMP, /* OR, BIIMP, NPI1 */
 LIMP, /* OR, BIIMP, NIMP */
 LIMP, /* OR, BIIMP, NPI2 */
 K1, /* OR, BIIMP, XOR */
 K1, /* OR, BIIMP, NAND */
 BIIMP, /* OR, BIIMP, AND */
 BIIMP, /* OR, BIIMP, BIIMP */
 IMP, /* OR, BIIMP, IMP */
 LIMP, /* OR, BIIMP, LIMP */
 K1, /* OR, BIIMP, OR */
 K1, /* OR, BIIMP, K1 */
 IMP, /* OR, IMP, K0 */
 K1, /* OR, IMP, PI1 */
 IMP, /* OR, IMP, PI2 */
 IMP, /* OR, IMP, NOR */
 IMP, /* OR, IMP, NLIMP */
 IMP, /* OR, IMP, NPI1 */
 K1, /* OR, IMP, NIMP */
 K1, /* OR, IMP, NPI2 */
 K1, /* OR, IMP, XOR */
 K1, /* OR, IMP, NAND */
 IMP, /* OR, IMP, AND */
 IMP, /* OR, IMP, BIIMP */
 IMP, /* OR, IMP, IMP */
 K1, /* OR, IMP, LIMP */
 K1, /* OR, IMP, OR */
 K1, /* OR, IMP, K1 */
 LIMP, /* OR, LIMP, K0 */
 LIMP, /* OR, LIMP, PI1 */
 K1, /* OR, LIMP, PI2 */
 LIMP, /* OR, LIMP, NOR */
 K1, /* OR, LIMP, NLIMP */
 K1, /* OR, LIMP, NPI1 */
 LIMP, /* OR, LIMP, NIMP */
 LIMP, /* OR, LIMP, NPI2 */
 K1, /* OR, LIMP, XOR */
 K1, /* OR, LIMP, NAND */
 LIMP, /* OR, LIMP, AND */
 LIMP, /* OR, LIMP, BIIMP */
 K1, /* OR, LIMP, IMP */
 LIMP, /* OR, LIMP, LIMP */
 K1, /* OR, LIMP, OR */
 K1, /* OR, LIMP, K1 */
 OR, /* OR, OR, K0 */
 OR, /* OR, OR, PI1 */
 OR, /* OR, OR, PI2 */
 K1, /* OR, OR, NOR */
 OR, /* OR, OR, NLIMP */
 K1, /* OR, OR, NPI1 */
 OR, /* OR, OR, NIMP */
 K1, /* OR, OR, NPI2 */
 OR, /* OR, OR, XOR */
 K1, /* OR, OR, NAND */
 OR, /* OR, OR, AND */
 K1, /* OR, OR, BIIMP */
 K1, /* OR, OR, IMP */
 K1, /* OR, OR, LIMP */
 OR, /* OR, OR, OR */
 K1, /* OR, OR, K1 */
 K1, /* OR, K1, K0 */
 K1, /* OR, K1, PI1 */
 K1, /* OR, K1, PI2 */
 K1, /* OR, K1, NOR */
 K1, /* OR, K1, NLIMP */
 K1, /* OR, K1, NPI1 */
 K1, /* OR, K1, NIMP */
 K1, /* OR, K1, NPI2 */
 K1, /* OR, K1, XOR */
 K1, /* OR, K1, NAND */
 K1, /* OR, K1, AND */
 K1, /* OR, K1, BIIMP */
 K1, /* OR, K1, IMP */
 K1, /* OR, K1, LIMP */
 K1, /* OR, K1, OR */
 K1, /* OR, K1, K1 */
 K1, /* K1, K0, K0 */
 K1, /* K1, K0, PI1 */
 K1, /* K1, K0, PI2 */
 K1, /* K1, K0, NOR */
 K1, /* K1, K0, NLIMP */
 K1, /* K1, K0, NPI1 */
 K1, /* K1, K0, NIMP */
 K1, /* K1, K0, NPI2 */
 K1, /* K1, K0, XOR */
 K1, /* K1, K0, NAND */
 K1, /* K1, K0, AND */
 K1, /* K1, K0, BIIMP */
 K1, /* K1, K0, IMP */
 K1, /* K1, K0, LIMP */
 K1, /* K1, K0, OR */
 K1, /* K1, K0, K1 */
 K1, /* K1, PI1, K0 */
 K1, /* K1, PI1, PI1 */
 K1, /* K1, PI1, PI2 */
 K1, /* K1, PI1, NOR */
 K1, /* K1, PI1, NLIMP */
 K1, /* K1, PI1, NPI1 */
 K1, /* K1, PI1, NIMP */
 K1, /* K1, PI1, NPI2 */
 K1, /* K1, PI1, XOR */
 K1, /* K1, PI1, NAND */
 K1, /* K1, PI1, AND */
 K1, /* K1, PI1, BIIMP */
 K1, /* K1, PI1, IMP */
 K1, /* K1, PI1, LIMP */
 K1, /* K1, PI1, OR */
 K1, /* K1, PI1, K1 */
 K1, /* K1, PI2, K0 */
 K1, /* K1, PI2, PI1 */
 K1, /* K1, PI2, PI2 */
 K1, /* K1, PI2, NOR */
 K1, /* K1, PI2, NLIMP */
 K1, /* K1, PI2, NPI1 */
 K1, /* K1, PI2, NIMP */
 K1, /* K1, PI2, NPI2 */
 K1, /* K1, PI2, XOR */
 K1, /* K1, PI2, NAND */
 K1, /* K1, PI2, AND */
 K1, /* K1, PI2, BIIMP */
 K1, /* K1, PI2, IMP */
 K1, /* K1, PI2, LIMP */
 K1, /* K1, PI2, OR */
 K1, /* K1, PI2, K1 */
 K1, /* K1, NOR, K0 */
 K1, /* K1, NOR, PI1 */
 K1, /* K1, NOR, PI2 */
 K1, /* K1, NOR, NOR */
 K1, /* K1, NOR, NLIMP */
 K1, /* K1, NOR, NPI1 */
 K1, /* K1, NOR, NIMP */
 K1, /* K1, NOR, NPI2 */
 K1, /* K1, NOR, XOR */
 K1, /* K1, NOR, NAND */
 K1, /* K1, NOR, AND */
 K1, /* K1, NOR, BIIMP */
 K1, /* K1, NOR, IMP */
 K1, /* K1, NOR, LIMP */
 K1, /* K1, NOR, OR */
 K1, /* K1, NOR, K1 */
 K1, /* K1, NLIMP, K0 */
 K1, /* K1, NLIMP, PI1 */
 K1, /* K1, NLIMP, PI2 */
 K1, /* K1, NLIMP, NOR */
 K1, /* K1, NLIMP, NLIMP */
 K1, /* K1, NLIMP, NPI1 */
 K1, /* K1, NLIMP, NIMP */
 K1, /* K1, NLIMP, NPI2 */
 K1, /* K1, NLIMP, XOR */
 K1, /* K1, NLIMP, NAND */
 K1, /* K1, NLIMP, AND */
 K1, /* K1, NLIMP, BIIMP */
 K1, /* K1, NLIMP, IMP */
 K1, /* K1, NLIMP, LIMP */
 K1, /* K1, NLIMP, OR */
 K1, /* K1, NLIMP, K1 */
 K1, /* K1, NPI1, K0 */
 K1, /* K1, NPI1, PI1 */
 K1, /* K1, NPI1, PI2 */
 K1, /* K1, NPI1, NOR */
 K1, /* K1, NPI1, NLIMP */
 K1, /* K1, NPI1, NPI1 */
 K1, /* K1, NPI1, NIMP */
 K1, /* K1, NPI1, NPI2 */
 K1, /* K1, NPI1, XOR */
 K1, /* K1, NPI1, NAND */
 K1, /* K1, NPI1, AND */
 K1, /* K1, NPI1, BIIMP */
 K1, /* K1, NPI1, IMP */
 K1, /* K1, NPI1, LIMP */
 K1, /* K1, NPI1, OR */
 K1, /* K1, NPI1, K1 */
 K1, /* K1, NIMP, K0 */
 K1, /* K1, NIMP, PI1 */
 K1, /* K1, NIMP, PI2 */
 K1, /* K1, NIMP, NOR */
 K1, /* K1, NIMP, NLIMP */
 K1, /* K1, NIMP, NPI1 */
 K1, /* K1, NIMP, NIMP */
 K1, /* K1, NIMP, NPI2 */
 K1, /* K1, NIMP, XOR */
 K1, /* K1, NIMP, NAND */
 K1, /* K1, NIMP, AND */
 K1, /* K1, NIMP, BIIMP */
 K1, /* K1, NIMP, IMP */
 K1, /* K1, NIMP, LIMP */
 K1, /* K1, NIMP, OR */
 K1, /* K1, NIMP, K1 */
 K1, /* K1, NPI2, K0 */
 K1, /* K1, NPI2, PI1 */
 K1, /* K1, NPI2, PI2 */
 K1, /* K1, NPI2, NOR */
 K1, /* K1, NPI2, NLIMP */
 K1, /* K1, NPI2, NPI1 */
 K1, /* K1, NPI2, NIMP */
 K1, /* K1, NPI2, NPI2 */
 K1, /* K1, NPI2, XOR */
 K1, /* K1, NPI2, NAND */
 K1, /* K1, NPI2, AND */
 K1, /* K1, NPI2, BIIMP */
 K1, /* K1, NPI2, IMP */
 K1, /* K1, NPI2, LIMP */
 K1, /* K1, NPI2, OR */
 K1, /* K1, NPI2, K1 */
 K1, /* K1, XOR, K0 */
 K1, /* K1, XOR, PI1 */
 K1, /* K1, XOR, PI2 */
 K1, /* K1, XOR, NOR */
 K1, /* K1, XOR, NLIMP */
 K1, /* K1, XOR, NPI1 */
 K1, /* K1, XOR, NIMP */
 K1, /* K1, XOR, NPI2 */
 K1, /* K1, XOR, XOR */
 K1, /* K1, XOR, NAND */
 K1, /* K1, XOR, AND */
 K1, /* K1, XOR, BIIMP */
 K1, /* K1, XOR, IMP */
 K1, /* K1, XOR, LIMP */
 K1, /* K1, XOR, OR */
 K1, /* K1, XOR, K1 */
 K1, /* K1, NAND, K0 */
 K1, /* K1, NAND, PI1 */
 K1, /* K1, NAND, PI2 */
 K1, /* K1, NAND, NOR */
 K1, /* K1, NAND, NLIMP */
 K1, /* K1, NAND, NPI1 */
 K1, /* K1, NAND, NIMP */
 K1, /* K1, NAND, NPI2 */
 K1, /* K1, NAND, XOR */
 K1, /* K1, NAND, NAND */
 K1, /* K1, NAND, AND */
 K1, /* K1, NAND, BIIMP */
 K1, /* K1, NAND, IMP */
 K1, /* K1, NAND, LIMP */
 K1, /* K1, NAND, OR */
 K1, /* K1, NAND, K1 */
 K1, /* K1, AND, K0 */
 K1, /* K1, AND, PI1 */
 K1, /* K1, AND, PI2 */
 K1, /* K1, AND, NOR */
 K1, /* K1, AND, NLIMP */
 K1, /* K1, AND, NPI1 */
 K1, /* K1, AND, NIMP */
 K1, /* K1, AND, NPI2 */
 K1, /* K1, AND, XOR */
 K1, /* K1, AND, NAND */
 K1, /* K1, AND, AND */
 K1, /* K1, AND, BIIMP */
 K1, /* K1, AND, IMP */
 K1, /* K1, AND, LIMP */
 K1, /* K1, AND, OR */
 K1, /* K1, AND, K1 */
 K1, /* K1, BIIMP, K0 */
 K1, /* K1, BIIMP, PI1 */
 K1, /* K1, BIIMP, PI2 */
 K1, /* K1, BIIMP, NOR */
 K1, /* K1, BIIMP, NLIMP */
 K1, /* K1, BIIMP, NPI1 */
 K1, /* K1, BIIMP, NIMP */
 K1, /* K1, BIIMP, NPI2 */
 K1, /* K1, BIIMP, XOR */
 K1, /* K1, BIIMP, NAND */
 K1, /* K1, BIIMP, AND */
 K1, /* K1, BIIMP, BIIMP */
 K1, /* K1, BIIMP, IMP */
 K1, /* K1, BIIMP, LIMP */
 K1, /* K1, BIIMP, OR */
 K1, /* K1, BIIMP, K1 */
 K1, /* K1, IMP, K0 */
 K1, /* K1, IMP, PI1 */
 K1, /* K1, IMP, PI2 */
 K1, /* K1, IMP, NOR */
 K1, /* K1, IMP, NLIMP */
 K1, /* K1, IMP, NPI1 */
 K1, /* K1, IMP, NIMP */
 K1, /* K1, IMP, NPI2 */
 K1, /* K1, IMP, XOR */
 K1, /* K1, IMP, NAND */
 K1, /* K1, IMP, AND */
 K1, /* K1, IMP, BIIMP */
 K1, /* K1, IMP, IMP */
 K1, /* K1, IMP, LIMP */
 K1, /* K1, IMP, OR */
 K1, /* K1, IMP, K1 */
 K1, /* K1, LIMP, K0 */
 K1, /* K1, LIMP, PI1 */
 K1, /* K1, LIMP, PI2 */
 K1, /* K1, LIMP, NOR */
 K1, /* K1, LIMP, NLIMP */
 K1, /* K1, LIMP, NPI1 */
 K1, /* K1, LIMP, NIMP */
 K1, /* K1, LIMP, NPI2 */
 K1, /* K1, LIMP, XOR */
 K1, /* K1, LIMP, NAND */
 K1, /* K1, LIMP, AND */
 K1, /* K1, LIMP, BIIMP */
 K1, /* K1, LIMP, IMP */
 K1, /* K1, LIMP, LIMP */
 K1, /* K1, LIMP, OR */
 K1, /* K1, LIMP, K1 */
 K1, /* K1, OR, K0 */
 K1, /* K1, OR, PI1 */
 K1, /* K1, OR, PI2 */
 K1, /* K1, OR, NOR */
 K1, /* K1, OR, NLIMP */
 K1, /* K1, OR, NPI1 */
 K1, /* K1, OR, NIMP */
 K1, /* K1, OR, NPI2 */
 K1, /* K1, OR, XOR */
 K1, /* K1, OR, NAND */
 K1, /* K1, OR, AND */
 K1, /* K1, OR, BIIMP */
 K1, /* K1, OR, IMP */
 K1, /* K1, OR, LIMP */
 K1, /* K1, OR, OR */
 K1, /* K1, OR, K1 */
 K1, /* K1, K1, K0 */
 K1, /* K1, K1, PI1 */
 K1, /* K1, K1, PI2 */
 K1, /* K1, K1, NOR */
 K1, /* K1, K1, NLIMP */
 K1, /* K1, K1, NPI1 */
 K1, /* K1, K1, NIMP */
 K1, /* K1, K1, NPI2 */
 K1, /* K1, K1, XOR */
 K1, /* K1, K1, NAND */
 K1, /* K1, K1, AND */
 K1, /* K1, K1, BIIMP */
 K1, /* K1, K1, IMP */
 K1, /* K1, K1, LIMP */
 K1, /* K1, K1, OR */
 K1, /* K1, K1, K1 */
 0   /* Dummy row */
};

