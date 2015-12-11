/*************************************************************************
  $Header: /cvsroot/bed/libbed/ref.h,v 1.1 2000/05/04 11:11:48 pfw Exp $
  FILE:  ref.h ( was: hash.h )
  DESCR: Hash table of externally referenced nodes in BDD package
  AUTH:  Jorn Lind
  DATE:  (C) june 1997

  MODIFICATIONS:
        Gerd Behrmann, Aalborg University
                - Limitation on number of items removed
                * Add function simplified
                * Table resize does now use primes
	Poul Frederick Williams, DTU
	        * Modified for use in the BED package
*************************************************************************/

#ifndef REF_H_
#define REF_H_

typedef struct s_HashtblItem
{
   int root;

   unsigned int first;
   unsigned int next;
   unsigned int count: 31;
   unsigned int empty : 1;
} HashtblItem;

typedef struct s_Hashtbl
{
   int size;
   int prime;
   HashtblItem *data;
   int freepos;
   int current;
} Hashtbl;

int  Hashtbl_init(Hashtbl*);
void Hashtbl_done(Hashtbl*);
void Hashtbl_addref(Hashtbl*, int);
void Hashtbl_delref(Hashtbl*, int);
int* Hashtbl_first(Hashtbl*);
int* Hashtbl_next(Hashtbl*);


#endif /* _HASH_H */


/* EOF */
