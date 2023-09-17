#include "shell.h"
/**
 * execmd - execute the command with execve
 * @argv: argument value
 *
 * Return: void
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_pathname = NULL;
	int id = fork();

	if (argv)
	{
		command = argv[0];
		actual_pathname = get_location(command);
	}
	if (id == 0)
	{
		if (execve(actual_pathname, argv, NULL) == -1)
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
		wait(NULL);
	}
}
