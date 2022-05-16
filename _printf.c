#include "main.h"
#include <stdarg.h>
/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 * 
 * Return: the number of characters printed
 * (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	int state, length;

	va_list list;
	va_start(list, format);
	
	state = 0;
	length = 0;

	while(*format)
	{
		if (state == 0)
		{
			if (*format == '%')
				state = 1;
			else
			{
				_putchar(*format);
				length++;
			}

		}
		else if (state == 1)
		{
			switch(*format)
			{
				case 'c':
					print_char(list);
					length++;
					break;
				case 's':
					print_str(list);
					length = length + print_str(list);
					break;
				case '%':
					_putchar('%');
					length++;
					break;
				default:
					break;
			}
			state = 0;
		}
		format++;
	}
	va_end(list);
	return (length);

}
