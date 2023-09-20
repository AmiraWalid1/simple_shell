#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>


void free_grid(char **grid);
char **Split_line(char *linestr, int num_char);
void execmd(char **, int command_num, char **env);
char *get_location(char *command);
char *_strdup(char *src);
void print_env(char **envp);
void signal_handler(int sig);
int increase_command_num(void);
#endif /*SHELL_H*/
