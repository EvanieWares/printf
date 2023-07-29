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
	len = _puts(str);
	return (len);
}
