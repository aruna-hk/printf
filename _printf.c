#include "main.h"
#include <stdio.h>
#include <string.h>

/**
* _printf - printf formatted data to standard output
* @format: 1st arguemnt
* Return: string len;
*/
int _printf(const char *format, ...)
{
	char *mybuffer = malloc(sizeof(char) * 1024);
	va_list print;
	char ar[2];
	int (*func_ptr)(char *, va_list);
	unsigned int len;

	mybuffer[0] = '\0';
	va_start(print, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				_strcat(mybuffer, "%");
			else
			{
				func_ptr = get_op_func(*format);
				if (func_ptr == NULL)
				{
					exit(0);
				}
				func_ptr(mybuffer, print);
			}
			format++;
		}
		else
		{
			ar[0] = *format;
			ar[1] = '\0';
			_strcat(mybuffer, ar);
			format++;
		}
	}

	len = _strlen(mybuffer);
	write(1, mybuffer, strlen(mybuffer));
	free(mybuffer);
	return (len);
}
