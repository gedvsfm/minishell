<<<<<<< HEAD
#include<stdio.h>
#include "init.h"
#include "parse.h"
#include "def.h"

char cmdline[MAXLINE+1];
char avline[MAXLINE+1];
char *lineptr;
char *avptr;
char infile[MAXLINE+1];
char outfile[MAXLINE+1];

COMMAND cmd[PIPELINE];

int cmd_count;
int backgnd;
int append;
int lastpid;
int main()
{
	//��װ�ź�
	setup();
	//����shellѭ��
	shell_loop();
	return 0;
}


=======
#include "parse.h"

int main(void)
{
	shell_loop();
	return 0;
}
>>>>>>> f45601bf0c043f4bf38953fd6a39650096daa65d
