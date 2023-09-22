#include "shell.h"
/**
 * execmd - execute the command with execve
 * @argv: argument value
 * @env: environment
 * @linestr: line string
 *
 * Return: void
 */


void execmd(char **argv, char **env, char *linestr)
{
	char *command = NULL, *actual_pathname = NULL;
	pid_t id;

	if (argv)
	{
		command = argv[0];
		if (is_buildin_command(argv, linestr) == 0)
			return;
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
			fprintf(stderr, "./hsh: %d: %s: not found\n", command_num(), command);
	}
	else
		perror("./shell");
}

/**
 * is_buildin_command - check if command is buildin or not
 * @argv: argument value
 * @linestr: linestr pointer
 *
 * Return: (0)sucess | (1)failed
 */
int is_buildin_command(char **argv, char *linestr)
{
	int numOFbuildin, i;
	char *buildin_command[] = {
		"exit",
		"cd",
		"help"
	};
	int (*buildin_fun[]) (char **, char *) = {
		&exit_fun,
		&cd_fun,
		&help_fun
	};
	numOFbuildin = sizeof(buildin_command) / sizeof(char *);
	for (i = 0 ; i < numOFbuildin ; i++)
	{
		if (strcmp(argv[0], buildin_command[i]) == 0)
		{
			(*buildin_fun[i])(argv, linestr);
			return (0);
		}
	}
	return (1);
}
