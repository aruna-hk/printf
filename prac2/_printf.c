#include "main.h"

/**
* _printf - print the arguement to stdout
* @string: 1st string
* Return: string len
*/
int  _printf(const char *string, ...)
{
	int str_len = 0;
	unsigned int lm;
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
				str_len++;
				_putchar(*string);
			}
			str_variable = check_and_alloc(*string, my_print);
			len_ = _strlen(str_variable);
			str_len += len_;
			while (*str_variable != '\0')
			{
				write(1, str_variable, 1);
				str_variable++;
			}
			str_variable -= len_;
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
