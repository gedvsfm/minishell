#include "parse.h"
#include <stdio.h>

/*
 * shell主循环
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
 * 读取命令
 * 成功返回0，失败或者读取到文件结束符(EOF)返回-1
 */
int read_command(void)
{
	char buf[1024+1];
	if (fgets(buf, 1024, stdin) == NULL)
		return -1;
	return 0;
}

/*
 * 解析命令
 * 成功返回解析到的命令个数，失败返回-1
 */
int parse_command(void)
{
	return 0;
}

/*
 * 执行命令
 * 成功返回0，失败返回-1
 */
int execute_command(void)
{
	return 0;
}
