# My Own Printf Project
This is a project to create a clone of printf function.

## Description
+ The `_printf` is a function from the C language. It prints data from a character string and arguments that we give it.
+ The prototype is as follows: `int _printf(const char*format, ...);`.
	+ Here, format is a character string which includes format specifiers such as `%c`, `%s`, etc.
	+ The elipsis `...` means the arguments to be passed in order to 'fill' the format specifiers.

## Flowchart
![](https://res.cloudinary.com/djvwjnzxw/image/upload/v1680482415/_PRINTF.drawio_jlqukt.png)

## Example
Some examples to illustrate the use of `_printf` in C.

```c
#include "main.h"

const char* name = "Jul";

// %c character format specifier
_printf("%c.%c means 'Holberton School'\n", 'H', 'S');

// %s string format specifier
_printf("Hello %s\n", name);

// %% modulo format specifier
_printf("99 %% of your code comes from stackoverflow\n");

// %d decimal format specifier
_printf("I am %d years old\n", 22);

// %b binary format specifier
_printf("The binary representation of 1024 is: %b\n", 1024);

// %o octal format specifier
_printf("The octal representation of 45 is: %o\n", 45);

// %x hexadecimal format specifier
_printf("The hexadecimal representation of -1024 is: %x\n", -1024);

/**
 * Expected output for %c: H.S means 'Holberton School'
 * Expected output for %s: Hello Jul
 * Expected output for %%: 99 % of your code comes from stackoverflow 
 * Expected output for %d: I am 22 years old
 * Expected output for %b: The binary representation of 1024 is: 10000000000
 * Expected output for %o: The octal representation of 45 is: 55
 * Expected output for %x: The hexadecimal representation of -1024 is: fffffc00
 */
```

## Author
xiayudev - Junior Developer
