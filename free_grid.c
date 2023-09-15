#include "shell.h"
/**
 * free_grid - frees a 2 dimensional grid previously created by
 * alloc_grid function.
 * @grid: 2 dimensional grid
 *
 * Return: void
 */
void free_grid(char **grid)
{
	int i;

	if (grid == NULL)
	{
		return;
	}
	for (i = 0 ; grid[i] ; i++)
	{
		free(grid[i]);
	}	
	free(grid);
}
