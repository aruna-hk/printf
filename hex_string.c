#include "main.h"
char id = 'x';
/**
* _memset - function fills the first n bytes destination with char provided
* @s:to be filled by b--bytes
* @b:to fill s
* @n: bytes to be filled
* Return:ptr to str s inserting b ntimes
*/
char *_memset(char *s, char b, unsigned int n)
{
	unsigned int i = 0;
	char *init_pointer = s;

	while (i < n)
	{
		*s = b;
		s++;
		i++;
	}
	return (init_pointer);
}
/**
* change_caps_small - changes small letters to capital letter
* @point:pointer to string
*/
void change_caps_small(char *point)
{
	char c;

	while (*point != '\0')
	{
		c = *point;

		if (c >= 'A' && c <= 'Z')
		{
			*point = c + ('a' - 'A');
		}
		point++;
	}
}
/**
* hex_convert - changes unsigne int to hex;
* @num: takes unsgned int
* @id: character specifier x/X
* Return: ptr to string of hexadecimal
*/
char *hex_convert(unsigned int num)
{
	int flag_s = 0;
	char *hex_string;
	int i, remainder;
	unsigned int temp = num;
	int num_digits = 0;

	if ((int) id >= 97 && (int) id <= 122)
		flag_s = 1;

	do {
		num_digits++;
		temp /= 16;
	} while (temp != 0);
	hex_string = malloc((num_digits + 1) * sizeof(char));
	if (hex_string == NULL)
	{
		return (NULL);
	}
	for (i = num_digits - 1; i >= 0; i--)
	{
		remainder = num % 16;
		if (remainder < 10)
			hex_string[i] = remainder + '0';
		else
			hex_string[i] = remainder - 10 + 'A';
		num /= 16;
	}
	hex_string[num_digits] = '\0';
	if (flag_s == 1)
		change_caps_small(hex_string);
	return (hex_string);
}
/**
* identifier_x -- handles hexadecimal--
* @buffer: destin buffer
* @list: varible list
* Return: 1- sucess ,0 -failure
*/
int identifier_x(char *buffer, va_list list)
{
	unsigned int oct;
	char *oct_buff;

	oct = va_arg(list, unsigned int);
	oct_buff = hex_convert(oct);
	_strcat(buffer, oct_buff);
	free(oct_buff);
	return (1);
}
/**
* identifier_X - caps hexadecimal
* @buffer: buffer to wite to the scree
* @list: variable lis
* Return: 1 -sucess 0- failure
*/
int identifier_X(char *buffer, va_list list)
{
	char *p_str;
	unsigned int _caps;

	id = 'X';
	_caps = va_arg(list, unsigned int);
	p_str = hex_convert(_caps);
	_strcat(buffer, p_str);
	free(p_str);
	return (1);
}
