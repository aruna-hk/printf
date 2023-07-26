#include "main.h"
/**
* out_side_call - handle x and p
* @s:character identifier
* @v:variable list
* Return:ptr or NULL
*/
char *out_side_call(char s, va_list v)
{
	unsigned int d;

	if (s == 'x' || s == 'X')
	{
		d = va_arg(v, unsigned int);
		return (hex_convert(d, s));
	}
	else
		return(NULL);
}

