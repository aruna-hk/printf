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
* append_to_buffer -- strip of print --gets appropriate function
* and append characters to buffer
* @buffer_s: buffer to store character before writing to the screen
* @ss: argument list
* @p:format specifier
*/
void append_to_buffer(char *buffer_s, va_list ss, char p)
{
	int (*func_ptr)(char *, va_list);

	func_ptr = get_op_func(p);
	if (func_ptr == NULL)
	{
		_strcat(buffer_s, "%");
		continue;
	}
	func_ptr(buffer_s, ss);
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
					append_to_buffer(mybuffer, print, *format);
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
