/*************************************************************************
  $Header: /cvsroot/bed/libbed/ref.c,v 1.1 2000/05/04 11:11:48 pfw Exp $
  FILE:  ref.c ( was: hash.c )
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
#include <stdlib.h>
#include <string.h>
#include "ref.h"

static HashtblItem* Hashtbl_get(Hashtbl*, int);
static HashtblItem* Hashtbl_getprev(Hashtbl*, int, HashtblItem **);
static void         Hashtbl_add(Hashtbl*, HashtblItem *);
static void         Hashtbl_del(Hashtbl*, HashtblItem *, HashtblItem *);
static HashtblItem* Hashtbl_makenode(Hashtbl*, int);

#define NIL 0x7FFFFFFF
#define MAX_PRIME 45

static int primes[] =
{
  13,
  23,
  59,
  113,
  241,
  503,
  1019,
  2039,
  4091,
  8179,
  11587,
  16369,
  23143,
  32749,
  46349,
  65521,
  92683,
  131063,
  185363,
  262139,
  330287,
  416147,
  524269,
  660557,
  832253,
  1048571,
  1321109,
  1664501,
  2097143,
  2642201,
  3328979,
  4194287,
  5284393,
  6657919,
  8388593,
  10568797,
  13315831,
  16777199,
  33554393,
  67108859,
  134217689,
  268435399,
  536870879,
  1073741789,
  2147483629
};

/*************************************************************************
  User interface
*************************************************************************/

int Hashtbl_init(Hashtbl* table)
{
   int n;

   table->prime = 0;
   table->size = primes[table->prime];
   if ((table->data =
	(HashtblItem*)malloc(sizeof(HashtblItem)*table->size)) == NULL)
       return -1; /* bdd_error(BDE_MEMORY); */

   table->freepos = 0;

   for (n=0 ; n<table->size ; n++)
   {
      table->data[n].next = n+1;
      table->data[n].first = NIL;
      table->data[n].empty = 1;
   }

   table->data[table->size-1].next = NIL;

   return 0;
}


void Hashtbl_done(Hashtbl* table)
{
   free(table->data);
   table->data = NULL;
   table->size = 0;
}


void Hashtbl_addref(Hashtbl* table, int root)
{
   HashtblItem *node = Hashtbl_get(table, root);

   if (node == NULL)
   {
      node = Hashtbl_makenode(table, root);
      Hashtbl_add(table, node);
   }
   else
      node->count++;
}


void Hashtbl_delref(Hashtbl* table, int root)
{
   HashtblItem *prev = NULL;
   HashtblItem *node = Hashtbl_getprev(table, root, &prev);

   if (node != NULL)
   {
      node->count--;

      if (node->count == 0)
	 Hashtbl_del(table, node, prev);
   }
#ifdef RUNTIMECHECK   
   else
      assert( 0 ); /* bdd_error(BDE_DEREF); */
#endif
}


int* Hashtbl_first(Hashtbl* table)
{
   table->current = 0;
   return Hashtbl_next(table);
}


int* Hashtbl_next(Hashtbl* table)
{
   while (table->current < table->size)
   {
      if (!table->data[table->current].empty)
	 return &table->data[table->current++].root;
      table->current++;
   }

   return NULL;
}


/*************************************************************************
  Internals
*************************************************************************/

static HashtblItem* Hashtbl_get(Hashtbl* table, int root)
{
   int h = table->data[(unsigned int)root % table->size].first;
   
   while (h != NIL)
   {
      if (table->data[h].root == root)
	 return &table->data[h];

      h = table->data[h].next;
   }

   return NULL;
}


static HashtblItem* Hashtbl_getprev(Hashtbl* table, int root,
				    HashtblItem **prev)
{
   int h = table->data[(unsigned int)root % table->size].first;
   
   while (h != NIL)
   {
      if (table->data[h].root == root)
	 return &table->data[h];

      *prev = &table->data[h];
      h = table->data[h].next;
   }

   return NULL;
}


static void Hashtbl_add(Hashtbl* table, HashtblItem *node)
{
   HashtblItem *h = &table->data[(unsigned int)node->root % table->size];

   node->next = h->first;
   h->first = node-table->data;
}


static void Hashtbl_del(Hashtbl* table, HashtblItem *node, HashtblItem *prev)
{
   HashtblItem *start = &table->data[(unsigned int)node->root % table->size];
   
   if (prev == NULL)
      start->first = node->next;
   else
      prev->next = node->next;

   node->empty = 1;
   node->next = table->freepos;
   table->freepos = node - table->data;
}


static HashtblItem* Hashtbl_makenode(Hashtbl* table, int root)
{
   HashtblItem *newtable;
   int n, oldsize;
   HashtblItem *res;

   if (table->freepos == NIL)
   {
      oldsize = table->size;
      table->prime++;
      if (table->prime == MAX_PRIME)
         return NULL;
      table->size = primes[table->prime];
      if ((newtable =
	   (HashtblItem*)malloc(sizeof(HashtblItem)*table->size)) == NULL)
	 return NULL;

      memcpy(newtable, table->data, sizeof(HashtblItem)*oldsize);

      for (n=0 ; n<oldsize ; n++)
	 newtable[n].first = NIL;

      for (n=oldsize ; n<table->size ; n++)
      {
	 newtable[n].empty = 1;
	 newtable[n].next = n+1;
	 newtable[n].first = NIL;
      }
      newtable[table->size-1].next = NIL;

      free(table->data);
      table->data = newtable;

      for (n=0 ; n<oldsize ; n++)
	 Hashtbl_add(table, &table->data[n]);
      table->freepos = oldsize;
   }

   res = &table->data[table->freepos];
   
   table->freepos = table->data[table->freepos].next;
   res->root = root;
   res->count = 1;
   res->empty = 0;
   res->next = NIL;

   return res;
}


/* EOF */
