#include "main.h"

/**
 * _printf - function that prints characters
 * to the standard output.
 * @format: input character.
 *
 * Return: value of the printout.
 */

int _printf(const char *format, ...)
{
	unsigned int n;
	int count = 0;
	va_list var;

	va_start(var, format);

	for (n = 0; format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			_pucha(format[n]);
			count++;
		}
		else if (format[n + 1] == 'c')
		{
			int x = va_arg(var, int);

			_pucha(x);
			count++;
			n++;
		}
		else if (format[n + 1] == 's')
		{
			char *str = va_arg(var, char *);
			int i = 0;

			while (str[i] != '\0')
			{
				_pucha(str[i]);
				count++;
				i++;
			}
			n++;
		}
	}
	va_end(var);
	return (count);
}
