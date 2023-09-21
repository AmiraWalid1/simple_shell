#include "shell.h"
/**
 * exit_fun - handle exit function
 * @argv: argument value
 * @command_num: command_num
 * @linestr: linestr pointer
 *
 * Return: (1)failed | exit if success
*/
int exit_fun(char **argv, int command_num, char *linestr)
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
				fprintf(stderr, "./hsh: %d: %s: ", command_num, argv[0]);
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
