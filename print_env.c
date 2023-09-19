#include "shell.h"
/**
 * print_env - print enironment
 * @envp: environment
 *
 * Return: void
*/
void print_env(char **envp)
{
	int i;

	if (envp)
	{
		for (i = 0 ; envp[i] ; i++)
		{
			printf("%s\n", envp[i]);
		}
	}
}
