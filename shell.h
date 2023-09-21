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
#include <ctype.h>

void free_grid(char **grid);
char **Split_line(char *linestr);
void execmd(char **argv, char **env, char *linestr);
char *get_location(char *command);
char *_strdup(char *src);
void print_env(char **envp);
void signal_handler(int sig);
void increase_command_num(void);
int command_num(void);
int isNumber(char *str);
int exit_fun(char **argv, char *linestr);
int is_buildin_command(char **argv, char *linestr);

#endif /*SHELL_H*/
