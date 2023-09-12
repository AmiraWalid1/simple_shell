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
	char *linestr = NULL, *linestrCopy = NULL, *word, *list_of_words;
	size_t n = 0;
	int num_char, num_words = 0, i;
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
			word = strtok(NULL, delim);
		}
		num_words++;
		list_of_words = malloc(sizeof(char *) * num_words);
		word = strtok(linestr, delim);
		for (i = 0; word != 0; i++)
		{
			list_of_words[i] = malloc(sizeof(char) * strlen(word));
			strcpy(list_of_words[i], word);
			word = strtok(NULL, delim);
		}
		list_of_words[i] = NULL;
		if (num_char == -1)
		{
			break;
		}
		free(linestr);
	}
	return (0);
}
