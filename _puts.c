#include "main.h"

/**
 * _puts - prints a string to stdout
 * @str: string to print
 *
 * Return: the number of characters printed
*/
int _puts(char *str)
{
	int len = 0;

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
