#include "main.h"

/**
 * print_string - prints string to stdout
 * @args: va_list containing the string to print
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	int len = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (*str != '\0')
	{
		_putchar(*str);
		len++;
		str++;
	}
	return (len);
}
