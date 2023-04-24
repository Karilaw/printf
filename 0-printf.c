#include "main.h"

/**
 * _printf - function that produces output according to a format
 * @format: a character string  composed of zero or more directives
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;
	char *s;
	int i;

	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			putchar(*format);
			counter++;
		}
		else
		{
			format++;
			if (*format == 'c')
			{
				char c = (char) va_arg(args, int);
				putchar(c);
				counter++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);

				while (*s)
				{
					putchar(*s);
					counter++;
					s++;

				}
			}
			else if (*format == '%')
			{
				putchar('%');
				counter++;
			}
			else if(*format == 'u')
			{
				unsigned int u = va_arg(args, unsigned int);
				s = _uitoa(u);
				for (i = 0; s[i]; i++)
				{
					putchar(s[i]);
					counter++;
				}
				free(s);
			}
			else if (*format == 'd' || *format == 'i')			{
				int d = va_arg(args, int);
				s = _itoa(d);
				for (i = 0; s[i]; i++)
				{
					putchar(s[i]);
					counter++;
				}
				free(s);
			}
			else if (*format == 'o')
			{
				unsigned int o = va_arg(args, unsigned int);
				char *octal = _uitoa_base(o, 8);
				for (i = 0; octal[i]; i++)
				{
					putchar(octal[i]);
					counter++;
				}
				free(octal);
			}
			else if (*format == 'x')
			{
				unsigned int x = va_arg(args, unsigned int);
				char *hex = _uitoa_base(x, 16);

				for (i = 0; hex[i]; i++)
				{
					putchar(hex[i]);
					counter++;
				}
				free(hex);
			}
			else if (*format == 'X')
			{
				unsigned int X = va_arg(args, unsigned int);
				char *HEX = _uitoa_base(X, 16);

				for (i = 0; HEX[i]; i++)
				{
					putchar(HEX[i] >= 'a' && HEX[i] <= 'f' ? HEX[i] - 32 : HEX[i]);
					counter++;
				}
				free(HEX);
			}
			else if (*format == 'p')
			{
				void *ptr = va_arg(args, void *);
				char *mem_add = _uitoa_base((unsigned long int)ptr, 16);

				putchar('0');
				putchar('x');
				counter += 2;
				for (i = 0; mem_add[i]; i++)
				{
					putchar(mem_add[i]);
					counter++;
				}
			}

			else if (*format == 'b')
			{
				unsigned int b = va_arg(args, unsigned int);
				char *binary_num = conv_to_binary(b);
				
				for (i = 0; binary_num[i]; i++)
				{
					putchar(binary_num[i]);
					counter++;
				}
				free(binary_num);
			}
			else
			{	putchar('%');
				putchar(*format);
				counter += 2;
			}
	}
		format++;
	}
	va_end(args);
	return (counter);
}
/**
 * _itoa - converts an integer to a string
 * @n: integer to convert
 *
 * Return: pointer to the resulting string
 */

char *_itoa(int n)
{
	char *str;
	int neg = 0, len;
	unsigned int num;
	int i;

	if (n == 0)
		return ("0");
	if (n < 0)
	{
		neg = 1;
		num = -n;
	}
	else
		num = n;
	len = neg;
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (neg  == 1)
		str[0] = '-';
	if (n < 0)
		num = -n;
	else
		num = n;
	i = len - 1;
	while (num > 0)
	{
		str[--len] = (num % 10) + '0';
		num /=10;
		i++;
	}
	return (str);
}
/**
 * _uitoa - converts an unsigned integer to a string
 * @n: unsigned integer to convert
 *
 * Return: pointer to the resulting string
 */
char *_uitoa(unsigned int n)
{
	char *str;
	int len = 0;
	unsigned int num;
	int i;

	if (n == 0)
	    return ("0");
	num = n;
	while (num > 0)
	{
	    num /= 10;
	    len++;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
	    return (NULL);
	str[len] = '\0';
	num = n;
	i = len - 1;
	while (num > 0)
	{
	    str[i--] = (num % 10) + '0';
	    num /= 10;
	}
	return (str);
}
/**
 * _uitoa_base - converts an unsigned integer to a string in a specified base
 * @n: unsigned integer to convert
 * @base: base to use for conversion
 *
 * Return: pointer to the resulting string
 */
char *_uitoa_base(unsigned long n, unsigned int base)
{
	char *str;
	int len = 0;
	unsigned int tmp = n;
	char *digits = "0123456789abcdefghijklmnopqrstuvwxyz";

	if (n == 0)
		len = 1;
	while (tmp > 0)
	{
		len++;
		tmp /= base;
	}
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
		str[0] = '0';
	while (n > 0)
	{
		str[--len] = digits[n % base];
		n /= base;
	}
	return (str);
}
