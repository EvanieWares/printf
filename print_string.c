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

/**
 * print_S - prints the string
 * @args: va_list that contains the string to print
 *
 * Return: number of digits printed
 */
int print_S(va_list args)
{
	int len = 0, i = 0;
	char *buffer = va_arg(args, char *);

	while (buffer[i] != '\0')
	{
		char c = buffer[i];

		if ((c > 0 && c < 32) || c >= 127)
		{
			len += _putchar(92);
			len += _putchar('x');
			len += print_unsigned_int(c, 16, 'X');
		}
		else
		{
			len += _putchar(c);
		}
		i++;
	}
	return (len);
	}
