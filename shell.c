#include "shell.h"
static int num_command;
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
		increase_command_num();
		if (num_char_readed == 1)
		{
			continue;
		}
		argv = Split_line(linestr);
		if (strcmp(argv[0], "env") == 0)
			print_env(env);
		else
			execmd(argv, env, linestr);
		free_grid(argv);
	}
	return (0);
}
/**
 * increase_command_num - increase number of command
 *
 * Return: void
*/
void increase_command_num(void)
{
	num_command++;
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

