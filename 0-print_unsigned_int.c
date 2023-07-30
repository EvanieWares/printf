#include "main.h"

/**
 * print_unsigned_int - prints unsigned integers with specified base
 * @number: number to print
 * @base: the base in the number will be printed in
 * @specifier: format specifier
 *
 * Return: number of digits printed
 */
int print_unsigned_int(unsigned int number, int base, char specifier)
{
	char *buffer;
	int digitCount = 0;

	if (number == 0)
	{
		return (_putchar('0'));
	}
	buffer = malloc(33 * sizeof(char));
	if (buffer == NULL)
	{
		return (-1);
	}
	if (number < 16 && base == 16 && (specifier == 'x' || specifier == 'X'))
	{
		digitCount += _putchar('0');
	}
	while (number > 0)
	{
		int digit = (number % base);

		if (base == 16 && digit > 9)
		{
			buffer[digitCount++] = get_hex(digit, specifier);
		}
		else
		{
			(void) specifier;
			buffer[digitCount++] = (number % base) + '0';
		}
		number /= base;
	}
	buffer[digitCount] = '\0';
	reverse_string(buffer, digitCount);
	_puts(buffer);
	free(buffer);
	return (digitCount);
}

/**
 * print_octal - prints an unsigned integer using an octal representation
 * @args: va_list containing the number
 *
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	int number, digits;

	number = va_arg(args, int);
	digits = print_unsigned_int(number, 8, 'o');
	return (digits);
}

/**
 * print_binary - prints an unsigned integer using an binary representation
 * @args: va_list containing the number to print
 *
 * Return: number of digits printed
 */
int print_binary(va_list args)
{
	int number, digits;

	number = va_arg(args, int);
	digits = print_unsigned_int(number, 2, 'b');
	return (digits);
}

/**
 * print_decimal - prints an unsigned integer as a decimal number
 * @args: va_list containing the number to print
 *
 * Return: number of digits printed
 */
int print_decimal(va_list args)
{
	int number, digits;

	number = va_arg(args, int);
	digits = print_unsigned_int(number, 10, 'u');
	return (digits);
}
