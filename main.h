#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

/**
 * struct type - specifier structure for printf
 * @ptr: pointer to characters specifiers.
 * @func: function pointer to print function.
 */
typedef struct type
{
	char ptr;
	int (*func)(va_list);
} print_f;



/*Prototypes of the printf functions*/
int _pucha(char t);
int _printf(const char *format, ...);
int printc(va_list args);
int print_str(va_list s);
int print_n(va_list n);
int (*cmp_func(const char b))(va_list);

#endif
