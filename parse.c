#include "parse.h"
#include <stdio.h>

/*
 * shell��ѭ��
 */
void shell_loop(void)
{
	while (1)
	{
		printf("[minishell]$ ");
		fflush(stdout);
		if (read_command() == -1)
			break;
		parse_command();
		execute_command();
	}
	
	printf("\nexit\n");
}

/*
 * ��ȡ����
 * �ɹ�����0��ʧ�ܻ��߶�ȡ���ļ�������(EOF)����-1
 */
int read_command(void)
{
	char buf[1024+1];
	if (fgets(buf, 1024, stdin) == NULL)
		return -1;
	return 0;
}

/*
 * ��������
 * �ɹ����ؽ����������������ʧ�ܷ���-1
 */
int parse_command(void)
{
	return 0;
}

/*
 * ִ������
 * �ɹ�����0��ʧ�ܷ���-1
 */
int execute_command(void)
{
	return 0;
}
