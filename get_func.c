#include "main.h"
/**
* get_op_func -- find and return pointer to
* respective function to getting necessary value with va_arg-
* @s: sign character
* Return: pointer to operators function/NULL
*/
int (*get_op_func(char s))(char *, va_list)
{
	char arr_s[2];
	int i = 0;
	op_t ops[] = {
		{"d", identifier_d},
		{"i", identifier_d},
		{"u", identifier_u},
		{"c", identifier_c},
		{"s", identifier_s},
		{"x", identifier_x},
		{"X", identifier_X},
		{"o", identifier_o},
		{"p", identifier_p},
		{'\0', NULL},
	};

	arr_s[0] = s;
	arr_s[1] = '\0';

	while (ops[i].op != NULL)
	{
		if (strcmp(arr_s, ops[i].op) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	return (NULL);
}
