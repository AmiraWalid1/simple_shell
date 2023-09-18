#include "shell.h"
/**
 * main - Entry point
 *
 * Description: Simple shell
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
	char prompat[] = "shell $ ";
	char *linestr = NULL, **argv;
	size_t n = 0;
	int num_char_readed;

	while (1)
	{
		printf("%s", prompat);
		num_char_readed = getline(&linestr, &n, stdin);
		if (num_char_readed == -1)
		{
			free(linestr);
			return (-1);
		}
		argv = Split_line(linestr, num_char_readed);
		if (strcmp(argv[0], "exit") == 0)
		{
			free(linestr);
			free_grid(argv);
			exit(EXIT_SUCCESS);
		}
		execmd(argv);
		free_grid(argv);
	}
	return (0);
}
