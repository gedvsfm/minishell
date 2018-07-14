#ifndef _EXTERNS_H_
#define _EXTERNS_H_

#include "def.h"
extern char cmdline[MAXLINE+1];
extern COMMAND cmd[PIPELINE];
extern char avline[MAXLINE+1];
extern char *lineptr;
extern char *avptr;
extern char infile[MAXLINE+1];
extern char outfile[MAXLINE+1];

extern int cmd_count;
extern int backgnd;
extern int append;
extern int lastpid;
#endif /*_EXTERNS_H_*/