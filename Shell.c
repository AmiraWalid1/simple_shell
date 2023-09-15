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
	char *linestr = NULL, **list_of_words;
	size_t n = 0;
	int num_char;

	while (1)
	{
		printf("%s", prompat);
		num_char = getline(&linestr, &n, stdin);
		if (num_char == -1)
		{
			return (-1);
		}
		list_of_words = Split_line(linestr, num_char);
		free_grid(list_of_words);
		
	}
	return (0);
}
