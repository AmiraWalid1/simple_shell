#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void free_grid(char **grid);
char **Split_line(char *linestr, int num_char);
void execmd(char **argv);

#endif /*SHELL_H*/
