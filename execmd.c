#include "shell.h"
/**
 * execmd - execute the command with execve
 * @argv: argument value
 * @env: environment
 * @linestr: line string
 *
 * Return: (0)success | (127)failed
 */


int execmd(char **argv, char **env, char *linestr)
{
	char *command = NULL, *actual_pathname = NULL;
	pid_t id;

	if (argv)
	{
		command = argv[0];
		if (is_buildin_command(argv, env, linestr) == 0)
			return (0);
		actual_pathname = get_location(command);
		if (actual_pathname)
		{
			id = fork();
			if (id == 0)
			{
				execve(actual_pathname, argv, env);
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
		{
			fprintf(stderr, "./hsh: %d: %s: not found\n", command_num(), command);
			return (127);
		}	
	}
	else
	{
		perror("./shell");
		return (127);
	}	
	return (0);
}

/**
 * is_buildin_command - check if command is buildin or not
 * @argv: argument value
 * @env: environment
 * @linestr: linestr pointer
 *
 * Return: (0)sucess | (1)failed
 */
int is_buildin_command(char **argv, char **env, char *linestr)
{
	int numOFbuildin, i;
	char *buildin_command[] = {
		"exit",
		"cd",
		"env"
	};
	void (*buildin_fun[]) (char **, char *) = {
		&exit_fun,
		&cd_fun,
		&print_env
	};
	numOFbuildin = sizeof(buildin_command) / sizeof(char *);
	for (i = 0 ; i < numOFbuildin ; i++)
	{
		if (strcmp(argv[0], buildin_command[i]) == 0)
		{
			if (i == 2)
				(*buildin_fun[i])(env, linestr);
			else
				(*buildin_fun[i])(argv, linestr);
			return (0);
		}
	}
	return (1);
}

