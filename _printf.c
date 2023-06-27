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

	if (format == NULL)
		return (-1);
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
			_pucha(va_arg(var, int));
			n++;
			count++;
		}
		else if (format[n + 1] == 's')
		{
			char *str = va_arg(var, char *);
			int i = 0;

			while (str[i] != '\0')
			{
				_pucha(str[i]);
				i++;
				count++;
			}
			n++;
		}
		else if (format[n] == '%')
		{
			_pucha('%');
			count++;
		}
	}
	va_end(var);
	return (count);
}
