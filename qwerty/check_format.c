#include "main.h"
/**
* check_and_alloc - va_arg variable and allocte oit space
* @s: format character
* @l: va_list
* Return: ptr to allocated space
*/
char *check_and_alloc(char s, va_list l)
{
	char *ptr = NULL;
	char c, *string_, str[2];

	if (s == 'c')
	{
		c = va_arg(l, int);
		str[0] = c;
		str[1] = '\0';
		ptr = malloc(sizeof(char) * (_strlen(str) + 1));
		_strcpy(ptr, str);
		return (ptr);
	}
	else if (s == 's')
	{
		string_ = va_arg(l, char *);
		ptr = malloc(sizeof(char) * (_strlen(string_) + 1));
		if (ptr == NULL)
			return (NULL);
		_strcpy(ptr, string_);
		return (ptr);
	}
	else if (s == 'd' || s == 'i')
		return (int_to_string(va_arg(l, int)));
	else if (s == 'u')
		return (uint_to_string(va_arg(l, unsigned int)));
	else if (s == 'o')
		return (uint_to_octal(va_arg(l, unsigned int)));
	else if (s == 'p')
		return (convert_to_hex(va_arg(l, unsigned long)));
	return (NULL);
}
