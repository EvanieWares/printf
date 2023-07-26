#include "main.h"

/**
 * print_char - prints a single character
 * @args: va_list containing the character to print
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}
