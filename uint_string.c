#include "main.h"
/**
* uint_to_string - convert unsigned interger to string
* @num: unsigned number arguement
* Return: ptr to string/NULL
*/
char *uint_to_string(unsigned long int num)
{
	unsigned int i = 0;
	char *ptr_ss;
	char store_num1[20] = {'\0'};

	if (num == 0)
	{
		ptr_ss = malloc(sizeof(char) * 2);
		_strcpy(ptr_ss, "0");
		return (ptr_ss);
	}
	while (num != 0 && (i < sizeof(store_num1) - 1))
	{
		store_num1[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	rev_string(store_num1, _strlen(store_num1));
	ptr_ss = malloc(sizeof(char) * (_strlen(store_num1)  + 1));
	if (ptr_ss == NULL)
		return (NULL);
	_strcpy(ptr_ss, store_num1);
	return (ptr_ss);
}
