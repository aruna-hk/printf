#include "main.h"
/**
 * _sstrcat - append string to a string-while inserting
 * \x
 * @dest: -destination string
 * @src: -source string
 * Return: pointer to dest
 */
void _sstrcat(char *dest, char *src)
{

	char *ptr = dest;
	char ch_num[2];
	char *char_num;

	while (*ptr != '\0')
	{
		ptr++;
	}

	while (*src != '\0')
	{
		if (((int) *src >= 0 && (int) *src <= 31) || (int) *src >= 127)
		{
			_strcat(dest, "\\x0");
			char_num = hex_convert((unsigned int) *src);
			change_caps_small(char_num);
			_strcat(dest, char_num);
		}
		ch_num[0] = *src;
		ch_num[1] = '\0';
		_strcat(ptr, ch_num);
		src++;
	}
	*ptr = '\0';
}
/**
* identifier_S - handles insertion of intergers
* @buffer: to copy string to
* @list: variable list
* Return: 1 if sucess or 0 failure
*/
int identifier_S(char *buffer, va_list list)
{
	char *from_v = va_arg(list, char *);

	if (from_v == NULL)
		_strcat(buffer, "(null)");
	else
		_sstrcat(buffer, from_v);
	return (0);
}

