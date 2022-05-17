#include "main.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * print_unsigned - prints an unsigned int.
 * @arg: argument
 * Return: 0
 */
int print_unsigned(va_list arg)
{
	int divisor = 1, i, resp;
	unsigned int n = va_arg(arg, unsigned int);

	for (i = 0; n / divisor > 9; i++, divisor *= 10)
		;

	for (; divisor >= 1; n %= divisor, divisor /= 10)
	{
			resp = n / divisor;
				_putchar('0' + resp);
	}
	return (i + 1);
}

/**
 * print_oct - prints number in octal base.
 * @arg: list containing octal number to be printed
 * Return: number of octals printed
 */
int print_oct(va_list arg)
{
	unsigned int num = va_arg(arg, unsigned int);
	unsigned int copy;
	char *octa;
	int i, j, charPrinted = 0;

	if (num == 0)
		return (_putchar('0'));
	for (copy = num; copy != 0; j++)
	{
		copy = copy / 8;
	}
	octa = malloc(j);
	if (!octa)
		return (-1);

	for (i = j - 1; i >= 0; i--)
	{
		octa[i] = num % 8 + '0';
		num = num / 8;
	}

	for (i = 0; i < j && octa[i] == '0'; i++)
		;
	for (; i < j; i++)
	{
		_putchar(octa[i]);
		charPrinted++;
	}
	free(octa);
	return (charPrinted);
}

/**
 * print_hex_base - base function for printing hexadecimal numbers
 * @arg: argument list containing hexadecimal
 * @_case: a  in caps on lower, printing the hex number in caps in lower
 * Return: number of digits printed
 */
int print_hex_base(va_list arg, char _case)
{
	unsigned int num = va_arg(arg, unsigned int);
	int nbrCharacters;

	if (num == 0)
		return (_putchar('0'));
	nbrCharacters = print_unsignedIntToHex(num, _case);

	return (nbrCharacters);
}

/**
 * print_hex - prints a hexadecimal in lower case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */
int print_hex(va_list arg)
{
	return (print_hex_base(arg, 'a'));
}

/**
 * print_HEX - prints a hexadecimal in upper case
 * @arg: list that contains hexadecimal to print
 * Return: number of digits printed
 */
int print_HEX(va_list arg)
{
		return (print_hex_base(arg, 'A'));
}
