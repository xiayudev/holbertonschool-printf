#include "main.h"

/**
 * character - function
 * @ptr: The list of arguments passed
 *
 * Prints character
 *
 * Return: Number of characters
 *
 */
int character(va_list ptr)
{
	int c;

	c = va_arg(ptr, int);
	if (!c)
	{
		_putchar('\0');
		return (1);
	}
	_putchar(c);
	return (1);
}

/**
 * string - function
 * @ptr: The list of arguments passed
 *
 * Prints strings
 *
 * Return: Number of characters
 *
 */
int string(va_list ptr)
{
	char *s, **grid;
	int count, len1, len2, i, j, k;

	s = va_arg(ptr, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	count = _strlen(s);
	len1 = count / SIZE_OF_BUFF;
	len2 = count % SIZE_OF_BUFF;

	if (len2)
		len1++;
	grid = alloc_grid(SIZE_OF_BUFF, len1);
	if (!grid)
		return (0);
	i = 0;
	k = 0;
	while (i < len1)
	{
		j = 0;
		while (j < SIZE_OF_BUFF && *(s + k))
		{
			*(*(grid + i) + j) = *(s + k);
			j++;
			k++;
		}
		i++;
	}

	i = 0;
	while (i < len1)
	{
		write(1, grid[i], _strlen(grid[i]));
		i++;
	}
	free_grid(grid, len1);
	return (count);
}

/**
 * no_printable_chars - function
 * @ptr: The list of arguments passed
 *
 * Prints string with no printables characters in upper hexadecimal
 *
 * Return: Number of digits
 *
 */
int no_printable_chars(va_list ptr)
{
	char *s, c;
	int count = 0, spec, i;

	s = va_arg(ptr, char *);
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	i = 0;
	while (*(s + i))
	{
		c = *(s + i);
		if ((c > 0 && c < 32) || c >= 127)
		{
			write(1, "\\x", 2);
			spec = c;
			print_hexa(spec);
			count += 4;
		}
		else
		{
			_putchar(*(s + i));
			count++;
		}
		i++;
	}
	return (count);
}
