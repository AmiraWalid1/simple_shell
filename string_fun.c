#include "shell.h"
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

/**
 * isNumber - check str is number or not
 * @str: string
 *
 * Return: (0) true | (1) false
*/
int isNumber(char *str)
{
	while (*str != '\0')
	{
		if (!isdigit(*str))
		{
			return (0);
		}
		str++;
	}
	return (1);
}
/**
 * is_spaces - check if string is only spaces
 * @str: string
 * Return: (1) success | (0) failed
*/
int is_spaces(char *str)
{
	int i, sz = strlen(str);

	for (i = 0 ; i < sz - 1 ; i++)
	{
		if (str[i] != ' ')
		{
			return (0);
		}
	}
	return (1);
}
