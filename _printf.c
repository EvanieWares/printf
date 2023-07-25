#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include "main.h"

int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);

/**
 * get_func - Get the function corresponding to the conversion specifier.
 * @specifier: The conversion specifier character.
 *
 * Return: A function pointer corresponding to the specifier.
 */
int (*get_func(const char *specifier))(va_list)
{
	switch (*specifier)
	{
		case 'c':
			return (&print_char);
		case 's':
			return (&print_string);
		case '%':
			return (&print_percent);
		default:
			return (NULL);
	}
}

/**
 * _printf - Produces output according to a format.
 * @format: A character string containing zero or more directives.
 *
 * Return: The number of characters printed (excluding the null byte).
 *         -1 if an error occurs.
 */
int _printf(const char *format, ...)
{
	int (*m)(va_list);
	va_list args;
	int count;

	va_start(args, format);

	count = 0; /* Number of characters printed */

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /* Move past the '%' */

			/* Check if it's a valid specifier */
			if (*format == '\0')
				return (-1); /* Invalid format string */

			m = get_func(format);
			if (m != NULL)
			{
				count += m(args);
				format++;
				continue;
			}
		}

		putchar(*format);
		count++;
		format++;
	}

	va_end(args);
	return (count);
}

/**
 * print_char - Print a single character.
 * @args: The va_list containing the character to print.
 *
 * Return: The number of characters printed (always 1).
 */
int print_char(va_list args)
{
	char c = (char)va_arg(args, int);

	putchar(c);
	return (1);
}

/**
 * print_string - Print a string.
 * @args: The va_list containing the string to print.
 *
 * Return: The number of characters printed.
 */
int print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int count = 0;

	while (*str != '\0')
	{
		putchar(*str);
		str++;
		count++;
	}

	return (count);
}

/**
 * print_percent - Print a percent character.
 * @args: The va_list (not used here).
 *
 * Return: The number of characters printed (always 1).
 */
int print_percent(va_list args)
{
	(void)args; /* Unused parameter */
	putchar('%');
	return (1);
}

