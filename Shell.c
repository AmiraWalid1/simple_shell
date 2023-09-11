#include <stdio.h>
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
	char *linestr = NULL;
	size_t n = 0;
	int num_char;

	while (1)
	{
		printf("%s", prompat);
		num_char = getline(&linestr, &n, stdin);
		if (num_char == -1)
		{
			break;
		}
	}
	return (0);
}
