#include "main.h"

/**
 * print_positive_binary - prints binary numbers > 0
 * @buffer: numbers to print
 * @size: number of bits
 */
void print_positive_binary(char *buffer, int size)
{
	int i;

	for (i = size - 1; i >= 0; i--)
	{
		_putchar(buffer[i]);
	}
}

/**
 * print_negative_binary - prints binary numbers < 0
 * @buffer: numbers to print
 * @size: number of bits
 */
void print_negative_binary(char *buffer, int size)
{
	char buf[33];
	int i, j;

	for (i = 0; i < 32 - size; i++)
		buf[i] = '0';
	for (j = size - 1; j >= 0; j--)
	{
		buf[i] = buffer[j];
		i++;
	}
	/* Flip the bits */
	for (i = 0; i < 32; i++)
	{
		if (buf[i] == '0')
			buf[i] = '1';
		else
			buf[i] = '0';
	}
	/* Add 1 */
	j = 1;
	i = 31;
	while (i >= 0 && j == 1)
	{
		int result = (buf[i] - '0') + j;

		if (result < 2)
		{
			buf[i] = result + '0';
			j = 0;
		}
		else
		{
			buf[i] = '0';
			j = 1;
		}
		i--;
	}
	for (i = 0; i < 32; i++)
		_putchar(buf[i]);
}

/**
 * print_binary - prints binary numbers
 *@args: va_list containing the number to print
 *
 *Return: number of digits printed
 */
int print_binary(va_list args)
{
	int isPositive;
	char buffer[33];
	int digitCount = 0;
	unsigned int number;
	int n = va_arg(args, int);

	if (n == 0)
	{
		return (_putchar('0'));
	}
	if (n > 0)
	{
		number = n;
		isPositive = 1;
	}
	else
	{
		number = -n;
		isPositive = 0;
	}
	while (number > 0)
	{
		int digit = number % 2;

		buffer[digitCount++] = digit + '0';
		number /= 2;
	}
	if (isPositive)
	{
		print_positive_binary(buffer, digitCount);
		return (digitCount);
	}
	print_negative_binary(buffer, digitCount);
	return (32);
}
