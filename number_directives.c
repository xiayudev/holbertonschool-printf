#include "main.h"

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

