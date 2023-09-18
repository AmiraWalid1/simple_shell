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
	pid_t id = fork();

	if (argv)
	{
		if (strcmp(argv[0], "exit") == 0)
		{
			if (id > 0)
				printf("exits the shell\n");
			kill(id, SIGTERM);
			exit(0);
		}
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
