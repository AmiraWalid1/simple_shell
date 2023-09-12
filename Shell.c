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
	char *linestr = NULL, *linestrCopy = NULL, *word;
	size_t n = 0;
	int num_char, num_words = 0;
	const char *delim = " ";


	while (1)
	{
		printf("%s", prompat);
		num_char = getline(&linestr, &n, stdin);
		linestrCopy = malloc(sizeof(char) * num_char);
		strcpy(linestrCopy, linestr);
		word = strtok(linestrCopy, delim);
		while(word != NULL)
		{
			num_words++;
			printf("%s", word);
			word = strtok(NULL, delim);
		}
		printf("%d", num_words);
		if (num_char == -1)
		{
			break;
		}
	}
	return (0);
}
