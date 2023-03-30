#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>

int _putchar(char c);
int _printf(const char *format, ...);
int _strlen(char *);

/* DIRECTIVES */
int character(va_list *);
int string(va_list *);
int integer(va_list *);
int u_integer(va_list *);
int binary(va_list *);
int octal(va_list *);
int hexa_lower(va_list *);
int hexa_upper(va_list *);
/* DIRECTIVES */
int num_digits(int);
void _print_rev_chars(char *);
void recursive_print(int);

/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */
typedef struct op
{
	char *op;
	int (*f)(va_list *);
} op_t;
#endif /*MAIN_H*/
