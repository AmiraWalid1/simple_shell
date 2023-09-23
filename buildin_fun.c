#include "shell.h"
/**
 * exit_fun - handle exit function
 * @argv: argument value
 * @linestr: linestr pointer
 *
 * Return: void
 */
void exit_fun(char **argv, char *linestr)
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
				ex_arg = 2;
			}
		}
		free(linestr);
		free_grid(argv);
		exit(ex_arg);
	}
	else
	{
		perror("./hsh");
	}
}

/**
 * cd_fun - handle cd function
 * @argv: argument value
 * @linestr: linestr pointer
 * Return: void
 */
void cd_fun(char **argv, char *linestr)
{
	char buf[1024], *oldpwd;

	(void)linestr;
	if (argv)
	{
		if (argv[1] == NULL || strcmp(argv[1], "~") == 0)
		{
			if (getenv("HOME") != NULL)
			{
				if (chdir(getenv("HOME")) != 0)
				{
					fprintf(stderr, "./hsh: %d: %s: ", command_num(), argv[0]);
					fprintf(stderr, "can't cd to %s\n", "HOME");
				}
				else
				{
					setenv("OLDPWD", getenv("PWD"), 1);
					setenv("PWD", getenv("HOME"), 1);
				}
			}
		}
		else if (strcmp(argv[1], "-") == 0)
		{
			if (getenv("OLDPWD") != NULL)
			{
				if (chdir(getenv("OLDPWD")) != 0)
				{
					fprintf(stderr, "./hsh: %d: %s: ", command_num(), argv[0]);
					fprintf(stderr, "can't cd to %s\n", argv[1]);
				}
				else
				{
					oldpwd = getenv("OLDPWD");
					setenv("OLDPWD", getenv("PWD"), 1);
					setenv("PWD", oldpwd, 1);
					printf("%s\n", getenv("PWD"));
				}
			}
			else
			{
				printf("%s\n", getenv("PWD"));
			}
		}
		else
		{
			if (chdir(argv[1]) != 0)
			{
				fprintf(stderr, "./hsh: %d: %s: ", command_num(), argv[0]);
				fprintf(stderr, "can't cd to %s\n", argv[1]);
			}
			else
			{
				setenv("OLDPWD", getenv("PWD"), 1);
				getcwd(buf, 1024);
				setenv("PWD", buf, 1);
			}
		}
	}
	else
		perror("./hsh");
}

/**
 * print_env - print enironment
 * @envp: environment
 * @linestr: linestr pointer
 *
 * Return: void
 */
void print_env(char **envp, char *linestr)
{
	int i;

	(void)linestr;
	if (envp)
	{
		for (i = 0; envp[i]; i++)
		{
			printf("%s\n", envp[i]);
		}
	}
}
