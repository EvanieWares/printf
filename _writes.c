#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

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

/**
 * reverse_string - reverses the string
 * @str: string to reverse
 * @len: length of the string
 */
void reverse_string(char *str, int len)
{
	int i;

	for (i = 0; i < len / 2; i++)
	{
		char temp = str[i];

		str[i] = str[len - i - 1];
		str[len - i - 1] = temp;
	}
}

/**
 * get_hex - replace numbers greater than 9 with hexadecimal character
 * @n: number to replace
 * Return: corresponding hexadecimal character
 */
char get_hex(int n)
{
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
