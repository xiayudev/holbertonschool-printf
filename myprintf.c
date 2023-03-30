#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stddef.h>
#include "main.h"

/**
 * m_modulo - function
 * @format: The value passed
 * @i: Pointer to the iterator
 * @total_chars: Pointer to the count of chars
 * Prints an integer recursively
 *
 * Return: Void
 *
 */
void m_modulo(const char *format, int *i, int *total_chars)
{
	if (*(format + *i + 1) == '%')
	{
		_putchar('%');
		*total_chars += 1;
		*i += 1;
	}
	else
	{
		_putchar(*(format + *i));
		*total_chars += 1;
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
	int i, j, count_chars, total_chars = 0;
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
	while (*(format + i))
	{
		if (*(format + i) == '%')
		{
			j = 0;
			while ((ops + j)->op)
			{
				if (*((ops + j)->op) == *(format + i + 1))
				{
					count_chars = (ops + j)->f(ptr);
					total_chars += count_chars;
					i += 2;
					break;
				}
				j++;
			}
			m_modulo(format, &i, &total_chars);
		}
		else
		{
			_putchar(*(format + i));
			total_chars++;
		}
		i++;
	}
	return (total_chars);
}
