/* 
 *  Copyright (c) 1996 - 2000 Technical University of Denmark
 *  Copyright (c) 1999 - 2000 IT University of Copenhagen
 *
 * by Poul Frederick Williams, Henrik Hulgaard, Henrik Reif Andersen
 * IT University of Copenhagen
 * Glentevej 67
 * DK-2400 Copenhagen NV, Denmark
 * 
 * e-mail: {pfw,henrik,hra}@it-c.dk
 */


#ifndef bed_h_
#define bed_h_

#ifdef __cplusplus
#define CPLUSPLUS
#endif

#ifdef CPLUSPLUS
extern "C" {
#endif

#include "bool.h"
#include "ilist.h"

#ifdef CPLUSPLUS
}
#endif


/*=== BED types ===================================================*/


typedef unsigned int	bed_var;
typedef unsigned int	bed_node;

#ifndef CPLUSPLUS
typedef bed_node bed;
#endif /* CPLUSPLUS */

typedef enum { 
  BED_NOP	= 0,		/* No ( binary Boolean ) operator */
  BED_VAR	= 0,		/* Variable ( same as BED_NOP ) */
  BED_ITE	= 0,		/* If-Then-Else ( same as BED_NOP ) */
  BED_K0  	= 1, 		/* Constant 0 */
  BED_PI1	= 2,		/* left-child */
  BED_PI2	= 3,		/* right-child */
  BED_NOR 	= 4,
  BED_NLIMP	= 5, 		/* Not left-imply */
  BED_NPI1 	= 6, 		/* Not left-child */
  BED_NIMP 	= 7, 		/* Not imply */
  BED_NPI2 	= 8, 		/* Not right-child */
  BED_XOR	= 9,
  BED_NAND	= 10,
  BED_AND	= 11,
  BED_BIIMP	= 12,		/* Logical equality */
  BED_IMP	= 13,		/* Imply */
  BED_LIMP	= 14,		/* left-imply */
  BED_OR	= 15,		
  BED_K1	= 16,		/* Constant 1 */
  BED_EXISTS	= 17,		/* Existential quantifier */
  BED_FORALL	= 18,		/* Universal quantifier */
  BED_SUBST	= 19,		/* Substitution */
  BED_ESUB	= 20		/* Exists & Subst of all variables */
} bed_op;

typedef iList		bed_var_list;
typedef iList		bed_node_list;

typedef struct {
  unsigned int		node_count;		/* #nodes in use right now */
  unsigned int		highest_node_count;	/* highest #nodes in use   */
  unsigned int		number_of_variables;	/* #variables declared	   */
  unsigned int		number_of_nodes;	/* #nodes declared	   */
  unsigned int		number_of_gc;		/* #garbage collections	   */
  unsigned long		gc_time;		/* Total GC time in msec   */
} bed_info;


#ifndef CPLUSPLUS
#define			BED_UNDEFINED		( (unsigned int) -1 )
#else
class bed;
extern const bed	BED_UNDEFINED;
#endif

#define BED_UPONE_MODE_ORDER	1
#define BED_UPONE_MODE_STRICT	2


/*=== Global variables =========================================*/

extern const bed_node	bed_zero;
extern const bed_node	bed_one;

#define			bed_true		bed_one
#define			bed_false		bed_zero

extern Boolean		bed_do_reductions;	/* Default: true */


/*=== BED interface prototypes =========================================*/

#ifdef CPLUSPLUS
extern "C" {
#endif

/* Initialization, clearing, and freeing of BEDs */

void		bed_init( unsigned long n, unsigned long c );
void		bed_clear(void);
void		bed_done(void);
void		bed_clear_cache(void);
Boolean		bed_is_running(void);


/* Building and manipulating BEDs */

bed_var		bed_new_variables( unsigned int number );

bed_node	bed_mk( bed_var var, bed_op op, bed_node low, bed_node high );

#define bed_ith_var( var )		bed_mk( var, BED_VAR, bed_false, bed_true )
#define	bed_mk_var( var, low, high )	bed_mk( var, BED_VAR, low, high )
#define	bed_mk_op( op, low, high )	bed_mk( 0, op, low, high )
#define	bed_mk_not( node )		bed_mk( 0, BED_NPI1, node, node )
#define	bed_mk_exists( var, node )	bed_mk( var, BED_EXISTS, node, node )
#define	bed_mk_forall( var, node )	bed_mk( var, BED_FORALL, node, node )
#define	bed_mk_subst( var, in_node, with_node ) \
			bed_mk( var, BED_SUBST, in_node, with_node )
#define	bed_mk_esub( node )		bed_mk( 0, BED_ESUB, node, node )

bed_node	bed_upall( bed_node node );
bed_node	bed_upone( bed_var var, bed_node node );
bed_node	bed_upone_iter( bed_node node );
bed_node	bed_upsome( bed_var_list *vars, bed_node node );

bed_node	bed_apply( bed_op op, bed_node low, bed_node high );
bed_node	bed_restrict( bed_node u, bed_var var, Boolean val );
bed_node	bed_simplify( bed_node u, bed_node c );
bed_node	bed_quantdown( bed_node u );


/* Reference counting */

bed_node	bed_ref( bed_node node );
void		bed_deref( bed_node node );


/* Ordering */

void		bed_set_ordering( bed_var_list *var_list );
bed_var_list*	bed_get_ordering( void );


/* Garbage collection */

void		bed_gc();
extern void	(*bed_external_gc)();		/* Function which is called */
						/* before garbage collection */
extern void	(*bed_external_gc_post)();	/* Function which is called */
						/* after garbage collection */


/* Examining BEDs */

Boolean         bed_is_reachable( bed_node node, bed_node from_node );
Boolean		bed_is_bdd( bed_node node );

double		bed_sat_count( bed_node node );

bed_var_list*	bed_any_sat( bed_node node );
bed_var_list*	bed_any_nonsat( bed_node node );
Boolean		bed_evaluate( bed_node node, bed_var_list *assignment);

unsigned int	bed_node_count( bed_node node );
bed_var_list*	bed_support( bed_node node );


/* Mappings */

extern char*	(*bed_var2name)( bed_var );	/* Mappings of bed_vars & */
extern char*	(*bed_node2name)( bed_node );	/* bed_nodes to names     */
char*		bed_op2name( bed_op op );	/* bed_op to names	  */


/* Functions for traversing BEDs */

bed_node	bed_get_low( bed_node node );
bed_node	bed_get_high( bed_node node );
bed_var		bed_get_var( bed_node node );
bed_op		bed_get_op( bed_node node );


/* Functions for reading, writing, & viewing BEDs */

/*
 *	Refer to "bedio.h"
 */

void		bed_io_view( bed_node node );


/* Internal settings */

void		bed_set_upone_mode( unsigned char tag );
unsigned char	bed_get_upone_mode();


/* Info */

bed_info	bed_get_info();

const char*	bed_version();
const char*	bed_author();
const char*	bed_addr();
const char*	bed_copyright();

#ifdef CPLUSPLUS
}
#endif



/*************************************************************************
  C++ part
*************************************************************************/

#ifdef CPLUSPLUS


/*=== BED class ===================================================*/

class bed
{
 public:

   bed(void)         { root=0; }
   bed(const bed &r) { bed_ref(root=r.root); }
   ~bed(void)        { bed_deref(root); }

   int id(void) const;
   
   bed operator=(const bed &r);
   
   bed operator&(const bed &r) const;
   bed operator&=(const bed &r);
   bed operator^(const bed &r) const;
   bed operator^=(const bed &r);
   bed operator|(const bed &r) const;
   bed operator|=(const bed &r);
   bed operator!(void) const;
   bed operator>>(const bed &r) const;
   bed operator>>=(const bed &r);
   bed operator-(const bed &r) const;
   bed operator-=(const bed &r);
   bed operator>(const bed &r) const;
   bed operator<(const bed &r) const;
   bed operator<<(const bed &r) const;
   bed operator<<=(const bed &r);
   int operator==(const bed &r) const;
   int operator!=(const bed &r) const;

private:
   bed_node root;

   /* Construct bed from bed_node */
   bed(bed_node r) { bed_ref(root=r); }
   bed operator=(bed_node r);


   /* Building and manipulating BEDs */

   friend bed	bed_mk_true(void);
   friend bed	bed_mk_false(void);
   friend bed	bed_mk_undefined(void);

   friend bed	bed_mk( bed_var var, bed_op op,
			const bed &low, const bed &high );

   friend bed	bed_upall( const bed &node );
   friend bed	bed_upone( bed_var var, const bed &node );
   friend bed	bed_upone_iter( const bed &node );
   friend bed	bed_upsome( bed_var_list *vars, const bed &node );

   friend bed	bed_apply( bed_op op, const bed &low, const bed &high );
   friend bed	bed_restrict( const bed &u, bed_var var, Boolean val );
   friend bed	bed_simplify( const bed &u, const bed &c );
   friend bed	bed_quantdown( const bed &u );


   /* Examining BEDs */

   friend Boolean	bed_is_reachable( const bed &node, const bed &from );
   friend Boolean	bed_is_bdd( const bed &node );

   friend double	bed_sat_count( const bed &node );

   friend bed_var_list*	bed_any_sat( const bed &node );
   friend bed_var_list*	bed_any_nonsat( const bed &node );
   friend Boolean	bed_evaluate( const bed &node, bed_var_list *assignment);

   friend unsigned int	bed_node_count( const bed &node );
   friend bed_var_list*	bed_support( const bed &node );


   /* Functions for traversing BEDs */

   friend bed		bed_get_low( const bed &node );
   friend bed		bed_get_high( const bed &node );
   friend bed_var	bed_get_var( const bed &node );
   friend bed_op	bed_get_op( const bed &node );


   /* Functions for viewing BEDs */

   friend void		bed_io_view( const bed &node );


   /* Hacks -- don't use unless you know what you are doing */

   friend bed		bed_from_int( bed_node r );
};


/*=== BED constants ====================================================*/

extern const bed bed_zero_pp;
extern const bed bed_one_pp;

#undef bed_true
#undef bed_false

#define bed_true	bed_one_pp
#define bed_false	bed_zero_pp
#define bed_one		bed_one_pp
#define	bed_zero	bed_zero_pp


/*=== C++ interface ====================================================*/


inline bed bed_mk_true(void)
{ return 1; }

inline bed bed_mk_false(void)
{ return 0; }

inline bed bed_mk_undefined(void)
{ return (bed_node)-1; }

inline bed bed_mk( bed_var var, bed_op op, const bed &low, const bed &high )
{ return bed_mk( var, op, low.root, high.root ); }

inline bed bed_upall( const bed &node )
{ return bed_upall( node.root ); }

inline bed bed_upone( bed_var var, const bed &node )
{ return bed_upone( var, node.root ); }

inline bed bed_upone_iter( const bed &node )
{ return bed_upone_iter( node.root ); }

inline bed bed_upsome( bed_var_list *vars, const bed &node )
{ return bed_upsome( vars, node.root ); }

inline bed bed_apply( bed_op op, const bed &low, const bed &high )
{ return bed_apply( op, low.root, high.root ); }

inline bed bed_restrict( const bed &u, bed_var var, Boolean val )
{ return bed_restrict( u.root, var, val ); }

inline bed bed_simplify( const bed &u, const bed &c )
{ return bed_simplify( u.root, c.root ); }

inline bed bed_quantdown( const bed &u )
{ return bed_quantdown( u.root ); }

inline Boolean bed_is_reachable( const bed &node, const bed &from )
{ return bed_is_reachable( node.root, from.root ); }

inline Boolean bed_is_bdd( const bed &node )
{ return bed_is_bdd( node.root ); }

inline double bed_sat_count( const bed &node )
{ return bed_sat_count( node.root ); }

inline bed_var_list* bed_any_sat( const bed &node )
{ return bed_any_sat( node.root ); }

inline bed_var_list* bed_any_nonsat( const bed &node )
{ return bed_any_nonsat( node.root ); }

inline Boolean bed_evaluate( const bed &node, bed_var_list *assignment)
{ return bed_evaluate( node.root, assignment ); }

inline unsigned int bed_node_count( const bed &node )
{ return bed_node_count( node.root ); }

inline bed_var_list* bed_support( const bed &node )
{ return bed_support( node.root ); }

inline bed bed_get_low( const bed &node )
{ return bed_get_low( node.root ); }

inline bed bed_get_high( const bed &node )
{ return bed_get_high( node.root ); }

inline bed_var bed_get_var( const bed &node )
{ return bed_get_var( node.root ); }

inline bed_op bed_get_op( const bed &node )
{ return bed_get_op( node.root ); }

inline void bed_io_view( const bed &node )
{ bed_io_view( node.root ); }


/*=== Inline C++ functions =============================================*/

inline int bed::id(void) const
{ return root; }

inline bed bed::operator&(const bed &r) const
{ return bed_mk_op(BED_AND,*this,r); }

inline bed bed::operator&=(const bed &r)
{ return (*this=bed_mk_op(BED_AND,*this,r)); }

inline bed bed::operator^(const bed &r) const
{ return bed_mk_op(BED_XOR,*this,r); }

inline bed bed::operator^=(const bed &r)
{ return (*this=bed_mk_op(BED_XOR,*this,r)); }

inline bed bed::operator|(const bed &r) const
{ return bed_mk_op(BED_OR,*this,r); }

inline bed bed::operator|=(const bed &r)
{ return (*this=bed_mk_op(BED_OR,*this,r)); }

inline bed bed::operator!(void) const
{ return bed_mk_not(*this);}

inline bed bed::operator>>(const bed &r) const
{ return bed_mk_op(BED_IMP,*this,r); }

inline bed bed::operator>>=(const bed &r)
{ return (*this=bed_mk_op(BED_IMP,*this,r)); }

inline bed bed::operator-(const bed &r) const
{ return bed_mk_op(BED_NIMP,*this,r); }

inline bed bed::operator-=(const bed &r)
{ return (*this=bed_mk_op(BED_NIMP,*this,r)); }

inline bed bed::operator>(const bed &r) const
{ return bed_mk_op(BED_NIMP,*this,r); }

inline bed bed::operator<(const bed &r) const
{ return bed_mk_op(BED_NLIMP,*this,r); }

inline bed bed::operator<<(const bed &r) const
{ return bed_mk_op(BED_LIMP,*this,r); }

inline bed bed::operator<<=(const bed &r)
{ return (*this=bed_mk_op(BED_LIMP,*this,r)); }

inline int bed::operator==(const bed &r) const
{ return r.root==root; }

inline int bed::operator!=(const bed &r) const
{ return r.root!=root; }


#endif /* CPLUSPLUS */

#endif /* bed_h_ */
