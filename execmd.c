#include "shell.h"
/**
 * execmd - execute the command with execve
 * @argv: argument value
 * @command_num: number of running command
 * @env: environment
 *
 * Return: void
 */
void execmd(char **argv, int command_num, char **env)
{
	char *command = NULL, *actual_pathname = NULL;
	pid_t id;

	if (argv)
	{
		command = argv[0];
		actual_pathname = get_location(command);
		if (actual_pathname)
		{
			id = fork();
			if (id == 0)
			{
				if (execve(actual_pathname, argv, env) == -1)
				{
					perror("./shell");
				}
			}
			else if (id < 0)
			{
				free_grid(argv);
				free(actual_pathname);
				perror("./shell");
				exit(EXIT_FAILURE);
			}
			else
			{
				wait(NULL);
				if (command != actual_pathname)
				{
					free(actual_pathname);
				}
			}
		}
		else
			fprintf(stderr, "sh: %d: %s: not found\n", command_num, command);
	}
	else
		perror("./shell");
}
