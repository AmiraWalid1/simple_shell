#include "shell.h"
static int num_command, status;
/**
 * signal_handler - handle signal
 * @sig: signal number
 *
 * Return: void
*/
void signal_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
/**
 * main - Entry point
 * @ac: argument number
 * @av: argument value
 * @env: environment
 * Description: Simple shell
 *
 * Return: Always 0 (Success)
 */
int main(int ac, char **av, char **env)
{
	char prompat[] = "$ ";
	char *linestr = NULL, **argv;
	size_t n = 0;
	int num_char_readed;

	(void)ac, (void)av;
	while (1)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("%s", prompat);
		}
		signal(SIGINT, signal_handler);
		num_char_readed = getline(&linestr, &n, stdin);
		if (num_char_readed == -1)
		{
			free(linestr);
			break;
		}
		num_command++;
		if (num_char_readed == 1 || is_spaces(linestr))
		{
			continue;
		}
		argv = Split_line(linestr);
		status = execmd(argv, env, linestr);
		free_grid(argv);
	}
	exit(status);
	return (0);
}

/**
 * command_num - return num of command running
 *
 * Return: return num of command running
*/
int command_num(void)
{
	return (num_command);
}
int get_status(void)
{
	return (status);
}

