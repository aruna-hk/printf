#include "main.h"
/**
* _print_percent - print%
* @strpp: ptr to len
*/
void percent(const char *string)
{
	_putchar(*string);
}
/**
* write_f - write-all
* @ptre:ptr to buffer
*/
void write_f(char *buf)
{
	while (*buf != '\0')
	{
		write(1, buf, 1);
		buf++;
	}
}
/**
* _isalpha - lowecase
* @c: ascii num
* Return: 1 if tue 0 if false
*/
int _isalpha(int c)
{
	if ((c > 97 && c <= 122) || (c > 64 && c <= 90))
		return (1);
	else
		return (0);
}
/**
* _printf - print the arguement to stdout
* @string: 1st string
* Return: string len
*/
int  _printf(const char *string, ...)
{
	int str_len = 0;
	va_list my_print;
	char *str_variable = NULL;
	int len_ = 0;

	va_start(my_print, string);
	while (*string != '\0')
	{
		if (*string == '%')
		{
			string++;
			if (*string == '%')
			{
				percent(string);
				str_len++;
			}
			else if (*string == 'x' || *string == 'X')
			{
				str_variable = hex_convert(va_arg(my_print, unsigned int), *string);
				len_ = _strlen(str_variable);
				str_len += len_;
				write_f(str_variable);
			}
			else
			{
				str_variable = check_and_alloc(*string, my_print);
				len_ = _strlen(str_variable);
				str_len += len_;
				write_f(str_variable);
			}
			string++;
		}
		str_len++;
		write(1, string, 1);
		string++;
	}
	free(str_variable);
	return (str_len);
}
