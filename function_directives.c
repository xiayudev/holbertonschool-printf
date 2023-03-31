#include "main.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/**
 * character - function
 * @ptr: The list of arguments passed
 *
 * Prints character
 *
 * Return: Number of characters
 *
 */
int character(va_list *ptr)
{
	int i = 1, c;

	c = va_arg(*(ptr), int) != 0;
	if (!c)
	{
		_putchar('\0');
		return (0);
	}
	_putchar(c);
	return (i);
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
int string(va_list *ptr)
{
	char *s;
	int count;

	s = va_arg(*(ptr), char *);
	if (!s)
	{
		write(1, '\0', 1);
		return (0);
	}
	count = _strlen(s);
	write(1, s, count);
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
int integer(va_list *ptr)
{
	int temp, num_chars;

	temp = va_arg(*(ptr), int);
	if (!temp)
	{
		_putchar('0');
		return (0);
	}
	num_chars = num_digits((temp < 0) ? (temp * -1) : temp);
	if (temp < 0)
	{
		_putchar('-');
		recursive_print(temp * -1);
	}
	else
		recursive_print(temp);
	return (num_chars);
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
int u_integer(va_list *ptr)
{
	int num_chars;
	unsigned int temp;

	temp = va_arg(*(ptr), unsigned int);
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
int binary(va_list *ptr)
{
	int num, n_temp, i, count = 0;
	char *p_temp;

	num = va_arg(*(ptr), int);
	n_temp = num;
	while (n_temp > 1)
	{
		n_temp /= 2;
		count++;
	}
	p_temp = malloc(count + 1);
	if (!p_temp)
		return (0);

	i = 0;
	while (num != 0)
	{
		*(p_temp + i) = (num % 2) + '0';
		num /= 2;
		i++;
	}
	*(p_temp + i) = '\0';
	_print_rev_chars(p_temp);
	free(p_temp);
	return (count);
}
