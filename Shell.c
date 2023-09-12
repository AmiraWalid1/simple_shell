#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	char *linestr = NULL, *linestrCopy = NULL;
	size_t n = 0;
	int num_char;
	char delim = ' ';


	while (1)
	{
		printf("%s", prompat);
		num_char = getline(&linestr, &n, stdin);
		linestrCopy = malloc(sizeof(char) * num_char);
		strcpy(linestrCopy, linestr);
		printf("%s", linestrCopy);
		if (num_char == -1)
		{
			break;
		}
	}
	return (0);
}
