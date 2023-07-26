#include "main.h"
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
int if_id(const char **pointerr,va_list ll)
{
	int len = 0;
	char *str_variable;

	(*pointerr)++;
	if (**pointerr == '%')
	{
		len++;
		_putchar(**pointerr);

	}
	{
		str_variable = check_and_alloc(**pointerr, ll);
		len += _strlen(str_variable);
		while (*str_variable != '\0')
		{
			write(1,str_variable,1);
			str_variable++;
		}
	}
	(*pointerr)++;
	return (len);
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

	va_start(my_print, string);
	while (*string != '\0')
	{
		if (*string == '%')
		{
			str_len+=if_id(&string,my_print);
		}
		else
		write(1, string, 1);
		string++;
	}
	va_end(my_print);
	return (str_len);
}
