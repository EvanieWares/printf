#include "main.h"

/**
 * get_func - get function corresponding to the format specifiers
 * @specifier: format specifier
 *
 * Return: a function pointer corresponding to the specifier
 */
int (*get_func(const char specifier))(va_list)
{
	switch (specifier)
	{
		case 'c':
			return (&print_char);
		case 's':
			return (&print_string);
		case 'i':
		case 'd':
			return (&print_int);
		case '%':
			return (&print_percent);
		default:
			{
				_putchar('%');
				return (NULL);
			}
	}
}
