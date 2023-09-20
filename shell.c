#include "shell.h"
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
	int num_char_readed, ex_arg = EXIT_SUCCESS, command_num;

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
		command_num = increase_command_num();
		if (num_char_readed == 1)
		{
			continue;
		}
		argv = Split_line(linestr);
		if (strcmp(argv[0], "exit") == 0)
		{
			if (argv[1] != NULL)
				ex_arg = atoi(argv[1]);
			free(linestr);
			free_grid(argv);
			exit(ex_arg);
		}
		if (strcmp(argv[0], "env") == 0)
			print_env(env);
		else
			execmd(argv, command_num, env);
		free_grid(argv);
	}
	return (0);
}



/**
 * increase_command_num - increase num command 1
 *
 * Return: num of running command
*/
int increase_command_num(void)
{
	static int command_num;

	command_num++;
	return (command_num);
}

