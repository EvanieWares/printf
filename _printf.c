#include "main.h"

/**
 * _printf - prints formatted output
 * @format: the output format
 * @...: optional arguments that correspond to the format specifiers
 * in the format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int (*func)(va_list);
	int printed = 0;
	va_list args;

	va_start(args, format);

	if (format == NULL)
	{
		return (-1);
	}

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;

			if (*format == '\0')
			{
				return (-1);
			}

			func = get_func(*format);

			if (func != NULL)
			{
				printed += func(args);
				format++;
				continue;
			}
		}
		printed += _putchar(*format);
		format++;
	}

	va_end(args);
	return (printed);
}
