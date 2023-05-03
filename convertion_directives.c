#include "main.h"

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

/**
 * octal - function
 * @ptr: The list of arguments passed
 *
 * Prints decimal in octal
 *
 * Return: Number of digits
 *
 */
int octal(va_list ptr)
{
	unsigned int num, n_temp;
	int i, count = 0;
	char *p_temp;

	num = va_arg(ptr, unsigned int);
	n_temp = num;
	if (n_temp == 0)
	{
		_putchar(n_temp + '0');
		return (1);
	}
	if (n_temp == 0)
	{
		_putchar(n_temp + '0');
		return (1);
	}
	while (n_temp)
	{
		n_temp /= 8;
		count++;
	}
	p_temp = malloc(count + 1);
	if (!p_temp)
		return (0);

	i = 0;
	while (num)
	{
		*(p_temp + i) = (num % 8) + '0';
		num /= 8;
		i++;
	}
	*(p_temp + i) = '\0';
	_print_rev_chars(p_temp);
	free(p_temp);
	return (count);
}

/**
 * hexa_lower - function
 * @ptr: The list of arguments passed
 *
 * Prints decimal in hexa lowercase
 *
 * Return: Number of digits
 *
 */
int hexa_lower(va_list ptr)
{
	unsigned int temp, num;
	int a, count = 0;
	char *p_temp;

	temp = va_arg(ptr, unsigned int);
	num = temp;
	if (num == 0)
	{
		_putchar(num + '0');
		return (1);
	}
	while (num)
	{
		num /= 16;
		count++;
	}
	p_temp = malloc(count + 1);
	if (!p_temp)
		return (0);
	a = 0;
	while (temp)
	{
		if (temp % 16 < 10)
			*(p_temp + a) = (temp % 16) + 48;
		else if (temp % 16 > 9)
			*(p_temp + a) = (temp % 16) + 87;
		temp /= 16;
		a++;
	}
	*(p_temp + a) = '\0';
	_print_rev_chars(p_temp);
	free(p_temp);
	return (count);
}

/**
 * hexa_upper - function
 * @ptr: The list of arguments passed
 *
 * Prints decimal in hexa uppercase
 *
 * Return: Number of digits
 *
 */
int hexa_upper(va_list ptr)
{
	unsigned int temp, num;
	int a, count = 0;
	char *p_temp;

	temp = va_arg(ptr, unsigned int);
	num = temp;
	if (temp == 0)
	{
		_putchar(temp + '0');
		return (1);
	}
	while (num)
	{
		num /= 16;
		count++;
	}
	p_temp = malloc(count + 1);
	if (!p_temp)
		return (0);
	a = 0;
	while (temp)
	{
		if (temp % 16 < 10)
			*(p_temp + a) = (temp % 16) + 48;
		else if (temp % 16 > 9)
			*(p_temp + a) = (temp % 16) + 55;
		temp /= 16;
		a++;
	}
	*(p_temp + a) = '\0';
	_print_rev_chars(p_temp);
	free(p_temp);
	return (count);
}
