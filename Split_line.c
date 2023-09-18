#include "shell.h"
/**
 * Split_line - split line of string
 * @linestr: line string
 * @num_char_readed: num of charcter of line string
 *
 * Return: array contain list_of_words
*/
char **Split_line(char *linestr, int num_char_readed)
{
	char *linestrCopy = NULL, *word, **argv;
	int num_words = 0, i;
	const char *delim = " \n";

	linestrCopy = malloc(sizeof(char) * num_char_readed);
	if (linestrCopy == NULL)
	{
		perror("Memory allocated error"), exit(1);
	}
	strcpy(linestrCopy, linestr);
	word = strtok(linestrCopy, delim);
	while (word != NULL)
	{
		num_words++;
		word = strtok(NULL, delim);
	}
	num_words++;
	argv = malloc(sizeof(char *) * num_words);
	if (argv == NULL)
	{
		free(linestrCopy);
		perror("Memory allocated error"), exit(1);
	}
	word = strtok(linestr, delim);
	for (i = 0; word != 0; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(word));
		if (argv[i] == NULL)
		{
			free(linestrCopy);
			free_grid(argv);
			perror("Memory allocated error");
			exit(1);
		}
		strcpy(argv[i], word);
		word = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(linestrCopy);
	return (argv);
}
