#include "shell.h"
/**
 * get_location - get path name of command
 * @command: command
 *
 * Return: actual path name
*/
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *path_file;
	char delmiter[] = ":";
	size_t command_len, path_token_len;
	struct stat buf;

	if (stat(command, &buf) == 0)
	{
		return (command);
	}
	command_len = strlen(command);
	path = getenv("PATH");
	path_copy = _strdup(path);
	path_token = strtok(path_copy, delmiter);
	while (path_token != NULL)
	{
		path_token_len = strlen(path_token);
		path_file = malloc(path_token_len + command_len + 2);
		if (path_file == NULL)
		{
			free(path_copy);
			perror("Memory allocated error"), exit(1);
		}
		strcpy(path_file, path_token);
		strcat(path_file, "/");
		strcat(path_file, command);
		strcat(path_file, "\0");
		if (stat(path_file, &buf) == 0)
		{
			free(path_copy);
			return (path_file);
		}
		else
		{
			free(path_file);
			path_token = strtok(NULL, delmiter);
		}
	}
	free(path_copy);
	return (NULL);
}
/**
 * _strdup - function returns a pointer to a new string
 * which is a duplicate of the string src.
 * @src: string
 *
 * Return: pointer to string
*/
char *_strdup(char *src)
{
	char *dst;

	if (src == NULL)
	{
		return (NULL);
	}
	dst = malloc(strlen(src) + 1);
	if (dst == NULL)
	{
		perror("Memory allocated error"), exit(1);
	}
	strcpy(dst, src);
	return (dst);
}
