#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#define SIZE_OF_BUFF 1024

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
 * integer - function
 * @ptr: The list of arguments passed
 *
 * Prints integer
 *
 * Return: Void
 *
 */
int integer(va_list ptr)
{
	int temp;
	int num_chars;

	temp = va_arg(ptr, int);
	if (!temp)
	{
		_putchar('0');
		return (1);
	}
	num_chars = num_digits((temp < 0)
			? ((unsigned int)temp * -1)
			: (unsigned int)temp);
	if (temp < 0)
	{
		_putchar('-');
		recursive_print((unsigned int)temp * -1);
		return (num_chars + 1);
	}
	else
	{
		recursive_print((unsigned int)temp);
		return (num_chars);
	}
}

/**
 * u_integer - function
 * @ptr: The list of arguments passed
 *
 * Prints u_integer
 *
 * Return: Number of digits
 *
 */
int u_integer(va_list ptr)
{
	int num_chars;
	unsigned int temp;

	temp = va_arg(ptr, unsigned int);
	if (temp == 0)
	{
		_putchar(temp + '0');
		return (1);
	}
	if (!temp)
	{
		_putchar('\0');
		return (0);
	}

	num_chars = num_digits(temp);
	recursive_print(temp);
	return (num_chars);
}

/**
 * binary - function
 * @ptr: The list of arguments passed
 *
 * Prints decimal in binary
 *
 * Return: Number of digits
 *
 */
int binary(va_list ptr)
{
	int num, i, n_temp, count = 0, flag = 0;
	char *p_temp;

	num = va_arg(ptr, int);
	n_temp = num;
	p_temp = calloc(33, 1);
	if (!p_temp)
		return (0);
	if (num == 0)
	{
		putchar(num + '0');
		return (1);
	}
	i = 31;
	while (num)
	{
		*(p_temp + i) = (num % 2) + '0';
		num /= 2;
		if (!num && n_temp < 0)
		{
			flag = 1;
			while (i >= 0)
			{
				*(p_temp + i) = '1';
				count++;
				i--;
			}
		}
		if (flag)
			break;
		count++;
		i--;
	}
	*(p_temp + 32) = '\0';
	if (n_temp < 0)
		write(1, p_temp, count);
	else
		write(1, (p_temp + i + 1), count);
	free(p_temp);
	return (count);
}
