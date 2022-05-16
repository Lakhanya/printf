#include "main.h"
#include <unistd.h>
#include <stdio.h>
/**
 * print_char - writes the character c to stdout
 * @arg: argument
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list arg)
{
		return (_putchar(va_arg(arg, int)));
}

/**
 * print_str - prints a string with a `s` (lower case) specifier
 * @arg: argument
 *
 * Return: number of character printed
 */

int print_str(va_list arg)
{
	int i;
	char *str = va_arg(arg, char*);

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
			_putchar(str[i]);

	return (i);
}
