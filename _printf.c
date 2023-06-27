#include "main.h"

/**
 * _printf - function that prints characters and strings.
 * @format: input character.
 * Return: value of the printout.
 */

int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, count = 0;

	if (!format)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			else if (format[i + 1] == '%')
			{
				_pucha('%');
				count++;
				i++;
			}
			else if (cmp_func(format[i + 1]) != NULL)
			{
				count += (cmp_func(format[i + 1]))(args);
				i++;
			}
			else
			{
				_pucha(format[i]);
				count++;
			}
		}
		else
		{
			_pucha(format[i]);
			count++;
		}
	}
	va_end(args);
	return (count);
}
