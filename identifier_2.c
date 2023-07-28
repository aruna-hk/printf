#include "main.h"
/**
* identifier_p - handles hexadecimal
* print memory adress
* @buffer: --fo flush to screen
* @list: variadic func variable list
* Return: 1-- sucess -0 -- failure
*/
int identifier_p(char *buffer, va_list list)
{
	char *_start;
	char *extension;
	unsigned int address_;

	address_ = va_arg(list, unsigned int);
	if (address_ == 0)
	{
		_strcat(buffer, "(nil)");
		return (1);
	}
	_start = "0x7fff";
	_strcat(buffer, _start);
	extension = hex_convert(address_);
	change_caps_small(extension);
	_strcat(buffer, extension);
	free(extension);
	return (1);
}

