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
void signal_handler(int sig);
int command_num(void);
int isNumber(char *str);
void exit_fun(char **argv, char *linestr);
void cd_fun(char **argv, char *linestr);
void print_env(char **envp, char *linestr);
int is_buildin_command(char **argv, char **env, char *linestr);
int is_spaces(char *str);
#endif /*SHELL_H*/

