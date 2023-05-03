#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

#define TYPE_ALLOC char
#define SIZE_OF_BUFF 1024

int _putchar(char c);
int _printf(const char *format, ...);
int _strlen(char *);
int print_hexa(int);

/* DIRECTIVES BEGIN */
int character(va_list);
int string(va_list);
int integer(va_list);
int u_integer(va_list);
int binary(va_list);
int octal(va_list);
int hexa_lower(va_list);
int hexa_upper(va_list);
int no_printable_chars(va_list);
/* DIRECTIVES END */

int num_digits(unsigned int);
void _print_rev_chars(char *);
void recursive_print(unsigned int);
TYPE_ALLOC **alloc_grid(int width, int height);
void free_grid(TYPE_ALLOC **grid, int height);

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(va_list);
} op_t;

#endif /*MAIN_H*/
