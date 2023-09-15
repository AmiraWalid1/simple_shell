#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void free_grid(char **grid);
char **Split_line(char *linestr, int num_char);
#endif /*SHELL_H*/