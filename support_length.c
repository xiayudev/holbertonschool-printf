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
 * num_digits - function
 * @i: The number to be evaluated
 *
 * Count the number of digits
 * Return: The number of digits.
 */
int num_digits(unsigned int i)
{
	int count;
	unsigned int temp;

	temp = i;
	count = 0;
	while (temp)
	{
		temp /= 10;
		count++;
	}
	return (count);
}
