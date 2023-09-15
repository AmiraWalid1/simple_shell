#include "shell.h"
/**
 * Split_line - split line of string
 * @linestr: line string
 * @num_char: num of charcter of line string
 *
 * Return: array contain list_of_words
*/
char **Split_line(char *linestr, int num_char)
{
	char *linestrCopy = NULL, *word, **list_of_words;
	int num_words = 0, i;
	const char *delim = " \n";

	linestrCopy = malloc(sizeof(char) * num_char);
	if (linestrCopy == NULL)
	{
		perror("Memory allocated error");
		exit(1);
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
		exit(1);
	}
	word = strtok(linestr, delim);
	for (i = 0; word != 0; i++)
	{
		list_of_words[i] = malloc(sizeof(char) * strlen(word));
		if (list_of_words[i] == NULL)
		{
			perror("Memory allocated error");
			exit(1);
		}
		strcpy(list_of_words[i], word);
		word = strtok(NULL, delim);
	}
	list_of_words[i] = NULL;
	free(linestrCopy);
	return (list_of_words);
}
