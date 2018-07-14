#include"execute.h"
#include"def.h"
#include"extern.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>
void execute_disk_command(void)
{
	if(infile[0]!='\0')
		cmd[0].infd=open(infile,O_RDONLY);
	if(outfile[0]!='\0')
	{
		if(append)
			cmd[cmd_count-1].outfd=open(outfile,O_WRONLY |O_CREAT| O_APPEND,0666);
		else
			cmd[cmd_count-1].outfd=open(outfile,O_WRONLY |O_CREAT| O_TRUNC,0666);
	}
	//��Ϊ��̨��ҵ�������wait,������Ҫ����ʬ����
	if(backgnd==1)
		signal(SIGCHLD,SIG_IGN);
	else
		signal(SIGCHLD,SIG_DFL);
	int i;
	int fds[2];
	int fd;
	for(i=0;i<cmd_count;++i)
	{
		//�������һ����������ܵ�
		if(i<cmd_count-1)
		{
			pipe(fds);
			cmd[i].outfd=fds[1];
			cmd[i+1].infd=fds[0];
		}

		forkexec(i);
		if((fd=cmd[i].infd)!=0)
			close(fd);
		if((fd=cmd[i].outfd)!=1)
			close(fd);
	}
	if(backgnd==0&&i!=0)
	{
		//ǰ̨��ҵ��Ҫ�ȴ��ܵ����һ�������˳�
		while(wait(NULL)!=lastpid);	
	}
}
void forkexec(int i)
{
	pid_t pid;
	pid=fork();
	if(pid==-1)
		ERR_EXIT("fork");
	if(pid>0)
	{
		if(backgnd==1)
			printf("%d\n",pid);
		lastpid=pid;
	}
	else if(pid==0)
	{
		//backgnd=1,����һ�������infd�ض��򵽿��ļ������ù�����ҵ����
		if(cmd[i].infd==0&&backgnd==1)
			cmd[i].infd=open("/dev/null",O_RDONLY);
		//����һ�������������Ϊ�������鳤
		if(i==0)
			setpgid(0,0);
		if(cmd[i].infd!=0)
		{
			close(0);
			dup(cmd[i].infd);
		}
		if(cmd[i].outfd!=1)
		{
			close(1);
			dup(cmd[i].outfd);
		}
		int j;
		for(j=3;j<1024;++j)//�ر�3���ϵ��ļ�������
			close(j);

		if(backgnd==0)
		{
			signal(SIGINT,SIG_DFL);
			signal(SIGQUIT,SIG_DFL);		
		}
		execvp(cmd[i].args[0],cmd[i].args);
		exit(EXIT_FAILURE);
	}
}