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

/*execute command*/
char **Split_line(char *linestr);
int execmd(char **argv, char **env, char *linestr);
char *get_location(char *command);
void signal_handler(int sig);
int command_num(void);
int get_status(void);

/*free allocated memory*/
void free_grid(char **grid);

/*string function*/
char *_strdup(char *src);
int isNumber(char *str);
int is_spaces(char *str);

/*buildin command*/
int is_buildin_command(char **argv, char **env, char *linestr);
void exit_fun(char **argv, char *linestr);
void cd_fun(char **argv, char *linestr);
void cd_home(char **argv);
void cd_oldpwd(char **argv);
void print_env(char **envp, char *linestr);

#endif /*SHELL_H*/

