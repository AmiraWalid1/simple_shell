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
void execmd(char **argv, int command_num, char **env, char *linestr);
char *get_location(char *command);
char *_strdup(char *src);
void print_env(char **envp);
void signal_handler(int sig);
int increase_command_num(void);
int isNumber(char *str);
int exit_fun(char **argv, int command_num, char *linestr);
int is_buildin_command(char **argv, int command_num, char *linestr);

#endif /*SHELL_H*/
