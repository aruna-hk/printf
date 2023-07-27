#include "main.h"
/**
* identifier_b - bit conversion
* @buffer: fflush buffer
* @list: variable arg list
* Return: 1 -sucess 0 -failure
*/
int identifier_b(char *buffer, va_list list)
{
	unsigned int i = 0;
	long int number = va_arg(list, unsigned int);
	char *bit_space = malloc(sizeof(char) * 64);

	if (bit_space == NULL)
		return (0);
	if (number == 0)
	{
		_strcat(buffer, "0");
		return (1);
	}

	while (number != 0)
	{
		bit_space[i] = number % 2 + '0';
		number = number / 2;
		i++;
	}

	bit_space[i] = '\0';
	rev_string(bit_space, i);
	_strcat(buffer, bit_space);

	return (1);
}
