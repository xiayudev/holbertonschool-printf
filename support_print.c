#include "main.h"

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
 * recursive_print - function
 * @n: Integer
 * Prints an integer recursively
 *
 * Return: Void
 *
 */
void recursive_print(unsigned int n)
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

/**
 * print_hexa - function
 * @n: The integer to be converted
 *
 * Prints decimal in hexa uppercase
 *
 * Return: void
 *
 */
int print_hexa(int n)
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
