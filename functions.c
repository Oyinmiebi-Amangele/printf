#include "main.h"
/**
 * _pucha - function that writes a character.
 * @t: variable.
 *
 * Return: character to the standard output.
 */

int _pucha(char t)
{
	return (write(1, &t, 1));
}

/**
 * printc - function that prints character.
 * @args: variable va_list.
 *
 * Return: 1 (nbyte)
 */

int printc(va_list args)
{
	_pucha(va_arg(list, int));
	return (1);
}

/**
 * print_str - function that prints string.
 * @s: variable va_list.
 *
 * Return: u (nbytes) 6 (NULL)
 */

int print_str(va_list s)
{
	char *str;
	int u;

	str = va_arg(s, char*);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		for (n = 0; str[n] != '\0'; n++)
		{
			_pucha(str[n]);
		}
	}
	return (k);
}

/**
 * print_n - function that prints numbers.
 * @n: variable va_list
 *
 * Return: count (nbytes)
 */

int print_n(va_list n)
{
	long int num;
	int count, aux_var, base;

	count = 0;
	num = va_arg(n, int);

	if (num < 0)
	{
		num *= -1;
		_pucha(45);
		count++;
	}
	if (num >= 0 && num <= 9)
	{
		_pucha(num + 48);
		count++;
	}
	if (num > 9)
	{
		base = 10;

		while (num / base > 9)
		{
			base *= 10;
		}
		while (base > 0)
		{
			aux_var = num / base;
			num = num % base;
			_pucha(aux_var + 48);
			base = base / 10;
			count++;
		}
	}
	return (count);
}
