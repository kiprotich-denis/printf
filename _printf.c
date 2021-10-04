#include "main.h"
#include <stdlib.h>

/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 * Return: the number of characters printed
 */
int (*specifier(const char *format))(va_list)
{
        int i = 0;
        op_t ops[] = {
		{"c", op_c},
		{"s", op_s},
		{NULL, NULL}
	};
	
	while (ops[i].op != NULL)
	{
		if(*(ops[i].op) == *format)
		{
			break;
		}
		i++;
	}
	return (ops[i].f);
}
/**
 * _printf - produces output according to a format
 * @format: character string composed of zero or more directives
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	int i, count;
	va_list args;
	int (*f)(va_list);

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		for (; format[i] != '%' && format[i]; i++)
		{
			_putchar(format[i]);
			count++;
		}
		if (!(format[i]))
		{
			return (count);
		}
		f = specifier(&format[i + 1]);
		if (f != NULL)
		{
			count += f(args);
			i += 2;
			continue;
		}
		if (!(format[i + 1]))
		{
			return (-1);
		}
		_putchar(format[i]);
		count++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(args);
	return (count);
}
