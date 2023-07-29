#include "main.h"

/**
 * print_int - prints a number to stdout
 * @args: va_list containing the number to print
 *
 * Return: the number of digits printed
*/
int print_int(va_list args)
{
	int i, isNegative = 0, digitCount = 0;
	int number = va_arg(args, int);
	char buffer[10];

	/* Check if the the number is zero and print it */
	if (number == 0)
	{
		_putchar('0');
	}

	/* Check if the number is negative and print a negative sign */
	if (number < 0)
	{
		_putchar('-');
		isNegative = 1;
		number = -number;
	}

	/* Print cast the number to a string */
	while (number > 0)
	{
		int digit = number % 10;

		buffer[digitCount++] = digit + '0';
		number /= 10;
	}

	/* Print the numbers */
	for (i = digitCount - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}

	return (digitCount + isNegative);
}
