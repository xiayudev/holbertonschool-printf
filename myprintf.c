#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * operation - function
 * @format: The value passed
 * @i: Pointer to the iterator
 * @total: Pointer to the count of chars
 * @ops: Array of structures
 * @ptr: Argumnets passed
 * @flag: Flag to know if a specifiers is found
 *
 * Makes operation according to specifiers
 *
 * Return: Void
 *
 */
void operation(const char *format, int *i, int *total, op_t ops[],
		va_list ptr, int *flag)
{
	int j, count_chars;

	if (*(format + *i + 1) == '%')
	{
		_putchar('%');
		*total += 1;
		*flag = 1;
		*i += 1;
	}
	else
	{
		j = 0;
		while ((ops + j)->op)
		{
			if (*((ops + j)->op) == *(format + *i + 1))
			{
				count_chars = (ops + j)->f(ptr);
				*total += count_chars;
				*flag = 1;
				*i += 1;
				break;
			}
			j++;
		}

	}

}

/**
 * _printf - function
 * @format: The value passed
 * Prints everything
 *
 * Return: Number of characters
 *
 */
int _printf(const char *format, ...)
{
	va_list ptr;
	int i, total = 0, flag = 0;
	op_t ops[] = {
		{"c", character}, {"s", string}, {"d", integer},
		{"i", integer},	{"u", u_integer}, {"b", binary},
		{"o", octal}, {"x", hexa_lower}, {"X", hexa_upper},
		{NULL, NULL}
	};
	va_start(ptr, format);
	if (!format)
		return (-1);
	i = 0;
	while (*(format + i) && _strlen((char *)format) > 2)
	{
		flag = 0;
		if (*(format + i) == '%')
		{
			operation(format, &i, &total, ops, ptr, &flag);

			if (!flag)
			{
				_putchar(*(format + i));
				total++;
			}
		}
		else
		{
			_putchar(*(format + i));
			total++;
		}
		i++;
	}
	return (total);
}
