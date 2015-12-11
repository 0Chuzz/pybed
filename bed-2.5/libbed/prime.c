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

#include <assert.h>
#include <stdlib.h>
#include "bool.h"

#define WORDSIZE	32		/* Change to 64 on architectures where 
					 * an unsigned int fits in 64 bits.
					 */

#define ODD(n)		((n)&1)
#define EVEN(n)		(!ODD(n))
#define TESTBIT(x,n)	((x) & (1<<(n)))

#define HI(x)	( ((x) & 0xffff0000) >> 16 )
#define LO(x)	  ((x) & 0x0000ffff)

#ifndef min
#define min(a,b)	((a) < (b) ? (a) : (b))
#endif

#ifndef max
#define max(a,b)	((a) > (b) ? (a) : (b))
#endif

static void dp_mul( unsigned a, unsigned b, unsigned *x1, unsigned *x0 )
{
  unsigned a_hi = HI(a);
  unsigned a_lo = LO(a);

  unsigned b_hi = HI(b);
  unsigned b_lo = LO(b);
  
  unsigned ab_hh = a_hi * b_hi;
  unsigned ab_hl = a_hi * b_lo;
  unsigned ab_lh = a_lo * b_hi;
  unsigned ab_ll = a_lo * b_lo;

  unsigned ab_hl_h = (ab_hl >> 16);
  unsigned ab_hl_l = ((ab_hl & 0x0000ffff) << 16);

  unsigned ab_lh_h = (ab_lh >> 16);
  unsigned ab_lh_l = ((ab_lh & 0x0000ffff) << 16);

  unsigned carry = 0;

  /* a + b produces a carry iff (a+b) < max(a,b)  */
  unsigned tmp = ab_hl_l + ab_lh_l; 
  carry += (tmp < max( ab_hl_l, ab_lh_l ) ? 1 : 0);

  *x0 = tmp + ab_ll;
  carry += ( *x0 < max( tmp, ab_ll ) ? 1 : 0);
 
  *x1  = ab_hh + ab_hl_h + ab_lh_h + carry;
}


static long state1[32] = {
  3,
  0x9a319039, 0x32d9c024, 0x9b663182, 0x5da1f342,
  0x7449e56b, 0xbeb1dbb0, 0xab5c5918, 0x946554fd,
  0x8c2e680f, 0xeb3d799f, 0xb11ee0b7, 0x2d436b86,
  0xda672e2a, 0x1588ca88, 0xe369735d, 0x904f35f7,
  0xd7158fd6, 0x6fa6f051, 0x616e6b96, 0xac94efdc,
  0xde3b81e0, 0xdf0a6fb5, 0xf103bc02, 0x48f340fb,
  0x36413f93, 0xc622c298, 0xf5a42ab8, 0x8a88d77b,
  0xf5ad9d0e, 0x8999220b, 0x27fb47b9
};

static void random_init(unsigned seed)
{
  int n = 128;

  initstate( seed, (char *) state1, n);
  setstate( (char *) state1 );
}

static inline long lrandom( long l, long u )
{
  return (random() % (u-l+1)) + l;
}

static inline unsigned number_bits( unsigned x )
{
  int k = (sizeof( unsigned ) * 8) - 1;

  while ( k && !TESTBIT( x, k ))
    k--;

  if ( k == 0 ) 
    return (TESTBIT( x, k ) ? 1 : 0);
  else
    return k+1;
}

static inline unsigned select_bits( unsigned x1, unsigned x0, unsigned i )
{
  return (x0 >> i) + (i ? (x1 << (32-i)) : 0);
}

static inline void subtract( unsigned x1, unsigned x0, unsigned yn, unsigned i, unsigned *X1, unsigned *X0 )
{
  /* subtract (n << i) from (x1,x0) */
  unsigned x = select_bits( x1, x0, i ) - yn;

  *X1  = i ? (x >> (32-i)) : 0;
  *X0  = (x << i) + (x0 & ((1 << i) - 1));		/* 0b0000111..11 */
}

static unsigned reminder( unsigned x1, unsigned x0, unsigned n )
{
  int i;

  for ( i = number_bits( x1 ); i >= 0; i-- ) {
    unsigned k = select_bits( x1, x0, i );	
    unsigned y = k/n;    

    subtract( x1, x0, y*n, i, &x1, &x0 );
  }    

  assert( x1 == 0 );

  return x0;
}

#if WORDSIZE==32
static unsigned mul_mod( unsigned a, unsigned b, unsigned n )
{
  unsigned x0, x1;
  dp_mul( a, b, &x1, &x0 );

  return reminder( x1, x0, n );
}
#else
static inline unsigned mul_mod( unsigned a, unsigned b, unsigned n )
{
  return (a*b) % n;
}
#endif

static Boolean witness( unsigned a, unsigned n )
{
  unsigned b = n - 1;
  unsigned d = 1;
  unsigned k = number_bits( b ) - 1;

  int i;
  
  for ( i = k; i >= 0; i-- ) {
    unsigned x = d;

    d = mul_mod( d, d, n );

    if ( (d == 1) && (x != 1) && (x != b))
      return true;

    if ( TESTBIT( b, i ) )
      d = mul_mod( d, a, n );
  }

  return ( d != 1 );
}


static Boolean miller_rabin_check_prime( unsigned x, int s )
{
  int j;

  for ( j = 0; j < s; j++ ) {
    unsigned a = lrandom( 1, x-1 );

    if ( witness( a, x ))
      return false;
  }
  return true;
}


/* fast_check_composite --
 * 	checks if 3, 5, 7, 11 or 13 divides n.
 */

static inline Boolean is_factor( unsigned x, unsigned n )
{
  return ((x!=n) && (x%n == 0));
}

static Boolean fast_check_composite( unsigned  x )
{
  return ( is_factor( x, 3 ) ||
	   is_factor( x, 5 ) ||
	   is_factor( x, 7 ) ||
	   is_factor( x, 11 ) ||
	   is_factor( x, 13 ));
}

/* is_prime -- return whether x is prime. 
 */

Boolean is_prime( unsigned x, unsigned s )
{
  if ( fast_check_composite( x ) )
    return false;

  return miller_rabin_check_prime( x, s );
}

/* prime_ge -- returns the next prime after x.
 */

unsigned prime_ge( unsigned x, unsigned s )
{
  assert( sizeof( unsigned ) == 4 );	/* This code makes this assumption.  */

  random_init( 1 );
  
  if ( EVEN(x) )	  /* make sure x is odd. */
    x++;

  while ( !is_prime( x, 10 ))
    x += 2;

  return x; 
}

#ifdef TEST
void main( int argc, char *argv[] )
{ 
  if ( argc > 1 ) {
    unsigned x = atoi( argv[1] );
    printf( "prime >= %u: %u\n", x, prime_ge( x, 10 ));
  }
}
#endif
