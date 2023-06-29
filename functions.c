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
	_pucha(va_arg(args, int));
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
		for (u = 0; str[u] != '\0'; u++)
		{
			_pucha(str[u]);
		}
	}
	return (u);
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

/**
 * print_binary - Prints an unsigned number in binary format.
 * @types: List of arguments.
 * Return: Number of characters printed.
 */
int print_binary(va_list types)
{
	unsigned int n = va_arg(types, unsigned int);
	unsigned int m = 2147483648; /* 2^31 */
	unsigned int a[32];
	int count = 0;
	int sum = 0;

	/* Convert decimal number to binary representation */
	unsigned int i;
	for (i = 0; i < 32; i++)
	{
		a[i] = n / m;
		n %= m;
		m /= 2;
	}

	/* Print the binary representation */
	i = 0;
	while (i < 32)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char binary_digit = '0' + a[i];
			_pucha(binary_digit);
			count++;
		}
		i++;
	}

	return count;
}

/**
 * print_number - Prints a number of given base.
 * @num: The number to be printed.
 * @base: The base of the number.
 * @uppercase: Flag indicating whether to use uppercase letters for hexadecimal.
 * Return: The number of characters printed.
 */
int print_number(unsigned int num, int base, int uppercase)
{
	char buffer[BUFF_SIZE];
	int count = 0;
	int index = 0;
	int i;

	if (num == 0)
	{
		_pucha('0');
		return 1;
	}

	while (num != 0)
	{
		unsigned int remainder = num % base;
		buffer[index++] = (remainder < 10) ? ('0' + remainder) : (uppercase ? 'A' + remainder - 10 : 'a' + remainder - 10);
		num /= base;
	}

	for (i = index - 1; i >= 0; i--)
		count += _pucha(buffer[i]);

	return count;
}

/**
 * print_assigned - Prints an unsigned number
 * @args: List of arguments.
 * Return: Number of characters printed.
 */

int print_unsigned(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
		int count = 0;
	count += print_number(num, 10, 0);

	return count;
}
/**
 * print_octal - Prints a number in octal format.
 * @args: List of arguments.
 * Return: Number of characters printed
 */

int print_octal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	count += print_number(num, 8,0);
	
	return count;
}
/**
 * print_hexadecimal - Prints a number in lowercase hexadecimal format.
 * @args: List of arguments.
 * Return: Number of characters printed.
 */
int print_hexidecimal(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	count += print_number(num, 16, 0);

	return count;
}

/**
 * print_hexadecimal_upper - Prints a number in uppercase hexadecimal format.
 * @args: List of arguments.
 * Return: Number of characters printed.
 */
int print_hexadecimal_upper(va_list args)
{
	unsigned int num = va_arg(args, unsigned int);
	int count = 0;

	count += print_number(num, 16,1);

	return count;
}
