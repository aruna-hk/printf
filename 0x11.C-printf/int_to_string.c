#include "main.h"
/**
* rev_string - reverse string--*numnumber case
* @start: pointer to the string literal to operate on--
*/
void rev_string(char *start, int st_len)
{
	char swap;
	char *end = start + st_len - 1;

	while (start < end)
	{
		swap = *start;
		*start = *end;
		*end = swap;
		start++;
		end--;
	}
}
/**
* int_to_string -- convert interger to string
* to append to buffer to flush to stdout
* @num: take *numnumber as arguemen
* Return: ptr to string of number /NULL
*/
char *int_to_string(int num)
{
	int flag = 0;
	unsigned int i = 0;
	char *ptr_ss;
	char store_num[20] = { '\0' };

	if (num == 0)
	{
		ptr_ss = malloc(sizeof(char) * 2);
		_strcpy(ptr_ss, "0");
		return (ptr_ss);
	}
	if (num < 0)
	{
		flag = 1;
		num = -num;
	}

	while (num != 0 && i < (sizeof(store_num) - 1))
	{
		store_num[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	if (flag == 1)
	{
		store_num[i] = '-';
	}
	rev_string(store_num, _strlen(store_num));
	ptr_ss = malloc(sizeof(char) * (_strlen(store_num)  + 1));
	if (ptr_ss == NULL)
	{
		free(ptr_ss);
		return (NULL);
	}
	_strcpy(ptr_ss, store_num);
	return (ptr_ss);
}
