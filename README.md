# My Own Printf Project
This is a project to create a clone of printf function.

## Description
+ The `_printf` is a function from the C language. It prints data from a character string and arguments that we give it.
+ The prototype is as follows: `int _printf(const char*format, ...);`.
	+ Here, format is a character string which includes format specifiers such as `%c`, `%s`, etc.
	+ The elipsis `...` means the arguments to be passed in order to 'fill' the format specifiers.

## Example
Some examples to illustrate the use of `_printf` in C.

```c
#include "main.h"

const char* name = "Jul";
_printf("Hello %s\n", name);

/**
 * Expected output: Hello, Jul
 */
```
