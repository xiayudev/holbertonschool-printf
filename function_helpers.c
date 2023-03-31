#include <unistd.h>
#include "main.h"

/**
 * _strlen - function
 * @s: The string to be evaluated
 * Swap values of two integers
 *
 * Return: Length of a string
 *
 */
int _strlen(char *s)
{
	int length;

	length = 0;
	while (*(s + length))
	{
		length++;
	}
	return (length);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * num_digits - function
 * @i: The number to be evaluated
 *
 * Count the number of digits
 * Return: The number of digits.
 */
int num_digits(int i)
{
	int count, temp;

	temp = i;
	count = 0;
	while (temp / 10)
	{
		temp /= 10;
		count++;
	}
	count++;
	return (count);
}

/**
 * recursive_print - function
 * @n: Integer
 * Prints an integer recursively
 *
 * Return: Void
 *
 */
void recursive_print(int n)
{
	if (n / 10)
		recursive_print(n / 10);
	_putchar((n % 10) + '0');
}

/**
 * _print_rev_chars - function
 * @s: The character to be evaluated
 * Prints a string
 *
 * Return: Void
 *
 */
void _print_rev_chars(char *s)
{
	if (*s)
	{
		_print_rev_chars(s + 1);
		_putchar(*s);
	}
}
