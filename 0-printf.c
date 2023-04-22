#include "main.h"
#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - function that produces output according to a format
 * @format: a character string  composed of zero or more directives
 */
int _printf(const char *format, ...)
{
	va_list args;
	int counter = 0;

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
				char *s = va_arg(args, char *);

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
				putchar(u);
				counter++;
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
