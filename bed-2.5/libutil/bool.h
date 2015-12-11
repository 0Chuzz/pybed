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


#ifndef _bool_h
#define _bool_h

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __GNUG__
  /* Booleans are build into g++ v. 2.6.0+ */

typedef bool Boolean;

#else	/* !__GNUG__ */

typedef int Boolean;

#ifndef false
#define false 0
#endif

#ifndef true
#define true (!false)
#endif

#endif	/* __GNUC__ */

#ifdef __cplusplus
}
#endif

#endif	/* _bool_h */
