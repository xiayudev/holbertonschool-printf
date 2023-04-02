#include "main.h"
#include <stdlib.h>

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

/**
 * hexa_upper2 - function
 * @n: The integer to be converted
 *
 * Prints decimal in hexa uppercase
 *
 * Return: void
 *
 */
int hexa_upper2(int n)
{
	int a, num, num2, flag = 0, count = 0;
	char *p_temp;

	if (!n)
		return (0);
	num = n;
	num2 = n;
	while (num)
	{
		num /= 16;
		count++;
	}
	if (count == 1)
		count++;
	p_temp = malloc(count + 1);
	if (!p_temp)
		return (0);
	a = 0;
	while (n)
	{
		if (num2 < 16 && flag == 0)
		{
			*(p_temp + 1) = '0';
			flag = 1;
		}
		if (n % 16 < 10)
			*(p_temp + a) = (n % 16) + 48;
		else if (n % 16 > 9)
			*(p_temp + a) = (n % 16) + 55;
		n /= 16;
		a++;
	}
	*(p_temp + 2) = '\0';
	_print_rev_chars(p_temp);
	free(p_temp);
	return (0);
}
