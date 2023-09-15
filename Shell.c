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
	char *linestr = NULL, *linestrCopy = NULL, *word, **list_of_words;
	size_t n = 0;
	int num_char, num_words = 0, i;
	const char *delim = " ";

	while (1)
	{
		printf("%s", prompat);
		num_char = getline(&linestr, &n, stdin);
		if (num_char == -1)
		{
			return (-1);
		}
		linestrCopy = malloc(sizeof(char) * num_char);
		if (linestrCopy == NULL)
		{
			perror("Memory allocated error");
			return (-1);
		}
		strcpy(linestrCopy, linestr);
		word = strtok(linestrCopy, delim);
		while (word != NULL)
		{
			num_words++;
			word = strtok(NULL, delim);
		}
		num_words++;
		list_of_words = malloc(sizeof(char *) * num_words);
		if (list_of_words == NULL)
		{
			perror("Memory allocated error");
			return (-1);
		}
		word = strtok(linestr, delim);
		for (i = 0; word != 0; i++)
		{
			list_of_words[i] = malloc(sizeof(char) * strlen(word));
			if (list_of_words[i] == NULL)
			{
				perror("Memory allocated error");
				return (-1);
			}
			strcpy(list_of_words[i], word);
			word = strtok(NULL, delim);
		}
		list_of_words[i] = NULL;
	}
	return (0);
}
