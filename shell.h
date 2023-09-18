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
void execmd(char **argv);
char *get_location(char *command);
#endif /*SHELL_H*/
 