#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <limits.h>

int _putchar(char c);
int _puts(char *str);
char get_hex(int, char);
void reverse_string(char *, int);
int _printf(const char *format, ...);
int (*get_func(const char specifier))(va_list);

/* Output to stdout */
int print_percent(va_list);
int print_string(va_list);
int print_char(va_list);
int print_int(va_list);

/* Print unsigned integers */
int print_binary(va_list);
int print_octal(va_list);
int print_decimal(va_list);
int print_hex(va_list);
int print_heX(va_list);
int print_unsigned_int(unsigned int, int, char);
int print_S(va_list);

#endif /* MAIN_H */
