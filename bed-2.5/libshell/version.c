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

#include <stdio.h>

static const char *VER         = "Shell v. 2.5";
static const char *AUTHOR      = "By Poul Frederick Williams, Henrik Hulgaard, Henrik Reif Andersen ({pfw,henrik,hra}@it-c.dk)";
static const char *ADDR        = "IT University of Copenhagen, Denmark.";
static const char *COPYRIGHT   = "Copyright (c) 1996 - 2000 Technical University of Denmark. Copyright (c) 1999 - 2000 IT University of Copenhagen.";


/*
 * Returns the date in a brief format.
 */

static char *proc_date()
{
  static char result[25];

#ifdef __DATE__
  (void) sprintf(result, "%s at %s", __DATE__, __TIME__ );
  return result;
#else
#ifdef CUR_DATE
  char day[10], month[10], zone1[10], zone2[10];
  int date, hour, minute, second, year;

  if ((sscanf(CUR_DATE, "%s %s %2d %2d:%2d:%2d %s %4d",
	      day, month, &date, &hour, &minute, &second, zone1, &year) == 8) ||
      (sscanf(CUR_DATE, "%s %s %2d %2d:%2d:%2d %s %s %4d",
	      day, month, &date, &hour, &minute, &second, zone1, zone2, &year) == 9)) {

    (void) sprintf(result, "%d-%3s-%02d at %d:%02d", 
		   date, month, year % 100, hour, minute);
    return result;
  } else {
    return CUR_DATE;
  }
#else
  return "<compile date not supplied>";
#endif /* CUR_DATE */
#endif /* __DATE__ */
}

/*
 * Returns the current BED version string to the caller.
 */

const char *bed_libshell_version()
{
  static char version[1024];

  (void) sprintf(version, "%s (compiled %s)", VER, proc_date());
  return version;
}

const char *bed_libshell_author()
{
  return AUTHOR;
}

const char *bed_libshell_addr()
{
  return ADDR;
}

const char *bed_libshell_copyright() 
{
  return COPYRIGHT;
}

