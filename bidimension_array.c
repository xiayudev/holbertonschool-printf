#include "main.h"

#define TYPE_ALLOC char

/**
 * alloc_grid - function
 * @width: The width of the array
 * @height: The height of the array
 * Create a 2d array
 *
 * Return: Pointer to a 2d array of integers
 *
 */
TYPE_ALLOC **alloc_grid(int width, int height)
{
	int i, j;
	TYPE_ALLOC **array2d = malloc(sizeof(TYPE_ALLOC *) * height);

	if (width <= 0 || height <= 0 || array2d == NULL)
	{
		free(array2d);
		return (NULL);
	}

	i = 0;
	while (i < height)
	{
		*(array2d + i) = malloc(sizeof(TYPE_ALLOC) * width);
		if (*(array2d + i) == NULL)
		{
			j = 0;
			while (j <= i)
			{
				free(*(array2d + j));
				j++;
			}
			free(array2d);
			return (NULL);
		}
		i++;
	}

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width)
		{
			*(*(array2d + i) + j) = '\0';
			j++;
		}
		i++;
	}
	return (array2d);
}

/**
 * free_grid - function
 * @grid: The 2d array to be freed
 * @height: The colum of the array
 * Free a 2d array
 *
 * Return: Void
 *
 */
void free_grid(TYPE_ALLOC **grid, int height)
{
	int i;

	i = 0;
	while (i < height)
	{
		free(*(grid + i));
		i++;
	}
	free(grid);
}
