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
	int id = fork();

	if (argv)
	{
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
		wait();
	}
}
