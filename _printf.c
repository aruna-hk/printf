#include "main.h"
/**
* buffer_set - set buffer
* @arr: array 2
* @buffer:hg
* @s:tst
*/
void buffer_set(char *arr, char *buffer, char s)
{
	arr[0] = s;
	arr[1] = '\0';

	_strcat(buffer, arr);
}
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
	if (format != NULL)
	{
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
						_strcat(mybuffer, "%");
						continue;
					}
					func_ptr(mybuffer, print);
				}
				format++;
			}
			else
			{
				 buffer_set(ar, mybuffer, *format);
				format++;
			}
		}
		len = _strlen(mybuffer);
		write(1, mybuffer, strlen(mybuffer));
		free(mybuffer);
	}
	else
		return (-1);
	return (len);
}
