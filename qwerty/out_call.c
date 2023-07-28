#include "main.h"
/**
* out_caller - handle x/X and p identifiers
* @v: - identifier
* @vv:variable list
* Return:ptr/null
*/
char *out_call(char v, va_list vv)
{
	unsigned int lm;

	if (v == 'x' || v == 'X')
	{
		lm = va_arg(vv, unsigned int);
		return(hex_convert(lm, v));
	}
	else
		return (NULL);
}
