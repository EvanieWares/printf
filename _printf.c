#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: a character string
 *
 * Return: number of characters printed,
 * excluding the null byte used to end output to strings
 */
int _printf(const char *format, ...)
{
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
			switch (*format)
			{
				case 'c':
					printed += printf("%c", va_arg(args, int));
					break;
				case 's':
					printed += printf("%s", va_arg(args, char*));
					break;
				case '%':
					printed += printf("%c", '%');
					break;
				default:
					printed += printf("%c", *format);
			}
		}
		else
		{
			printed += printf("%c", *format);
		}
		format++;
	}

	va_end(args);
	return (printed);
}
