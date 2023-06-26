#include "main.h"

/**
 * _printf - function that prints characters and strings.
 * @format: input character.
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
		}
		else if (format[n + 1] == 'c')
		{
			_pucha(va_arg(var, int);
			n++;
		}
		else if (format[n + 1] == 's')
		{
			int r_val = _put(va_arg(var, char *));

			n++;
			count += (r_val - 1);
		}
		else if (format[n + 1] == '%')
		{
			_pucha('%');
			n++;
		}
		else
		{
			_pucha(format[n]);
		}
		count += 1;
	}
	va_end(var);
	return (count);
}
