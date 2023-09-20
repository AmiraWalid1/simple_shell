#include "shell.h"
/**
 * execmd - execute the command with execve
 * @argv: argument value
 *
 * Return: void
 */
void execmd(char **argv)
{
	char *pathname = NULL;
	int id = fork(), wpid, status;

	if (argv)
	{
		if (argv[0] == "exit")
		{
			exit(0);
		}
		pathname = argv[0];
	}
	if (id == 0)
	{
		if (execve(pathname, argv, NULL) == -1)
		{
			perror("./shell");
		}
	}
	else if (id < 0)
	{
		perror("./shell");
	}
	else
	{
		wait(NULL );
	}
}

