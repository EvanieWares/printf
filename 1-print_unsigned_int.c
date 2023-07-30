#include "main.h"

/**
 * get_hex - replace numbers greater than 9 with hexadecimal character
 * @n: number to replace
 * @specifier: format specifier
 *
 * Return: corresponding hexadecimal character
 */
char get_hex(int n, char specifier)
{
	if (specifier == 'x')
	{
		switch (n)
		{
			case 10:
				return ('a');
			case 11:
				return ('b');
			case 12:
				return ('c');
			case 13:
				return ('d');
			case 14:
				return ('e');
			default:
				return ('f');
		}
	}
	switch (n)
	{
		case 10:
			return ('A');
		case 11:
			return ('B');
		case 12:
			return ('C');
		case 13:
			return ('D');
		case 14:
			return ('E');
		default:
			return ('F');
	}
}

/**
 * print_hex - prints an unsigned integer using an hexadecimal representation
 * @args: va_list containing the number to print
 *
 * Return: number of digits printed
 */
int print_hex(va_list args)
{
	int number, digits;

	number = va_arg(args, int);
	digits = print_unsigned_int(number, 16, 'x');
	return (digits);
}

/**
 * print_heX - prints an unsigned integer using an hexadecimal representation
 * @args: va_list containing the number to print
 *
 * Return: number of digits printed
 */
int print_heX(va_list args)
{
	int number, digits;

	number = va_arg(args, int);
	digits = print_unsigned_int(number, 16, 'X');
	return (digits);
}
