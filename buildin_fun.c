#include "shell.h"
/**
 * exit_fun - handle exit function
 * @argv: argument value
 * @linestr: linestr pointer
 *
 * Return: (1)failed | exit if success
 */
int exit_fun(char **argv, char *linestr)
{
	int ex_arg = EXIT_SUCCESS;

	if (argv)
	{
		if (argv[1] != NULL)
		{
			if (isNumber(argv[1]))
			{
				ex_arg = atoi(argv[1]);
			}
			else
			{
				fprintf(stderr, "./hsh: %d: %s: ", command_num(), argv[0]);
				fprintf(stderr, "Illegal number: %s\n", argv[1]);
				return (1);
			}
		}
		free(linestr);
		free_grid(argv);
		exit(ex_arg);
	}
	return (1);
}

/**
 * cd_fun - handle cd function
 * @argv: argument value
 * @linestr: linestr pointer
 * Return: (1)failed | exit if success
 */
int cd_fun(char **argv, char *linestr)
{
	if (argv)
	{
		if (argv[1] == NULL)
		{
			fprintf(stderr, "./hsh: expected argument to \"cd\"\n");
		}
		else
		{
			if (chdir(argv[1]) != 0)
			{
				perror("./hsh");
			}
		}
	}
	return (1);
}

/**
 * numOFbuildin - number of buildin
 * @built_in_string: argument value
 *
 * Return: (0)sucess | (1)failed
 */
int numOFbuildin(char **built_in_string)
{
	return (sizeof(built_in_string) / sizeof(char *));
}

/**
 * help_fun - handle cd function
 * @argv: argument value
 * @linestr: linestr pointer
 *
 * Return: (1)failed | exit if success
 */
int help_fun(char **argv, char *linestr)
{
	int i;
	char *buildin_command[] = {
		"exit",
		"cd",
		"help"
	};

	printf("These shell commands are defined internally.\n");
	printf("Type `help' to see this list.\n");
	printf("Type program names and arguments, and hit enter.\n");
	printf("The following are built in:\n");

	for (i = 0; i < numOFbuildin(buildin_command); i++)
	{
		printf(" %s\n", buildin_command[i]);
	}

	printf("Use the man command for information on other programs.\n");
	return (1);
}
