#include "main.h"
/**
* uint_to_octal - convert unsigned int to octal
* @number: takes unsigned interger
* Return: pointer to string of octal
*/
char *uint_to_octal(unsigned long int number)
{
	char *_ptr_;
	char *store_space = malloc(sizeof(char) * 1025);

	if (store_space == NULL)
		return (NULL);
	_ptr_ = store_space;
	while (number > 0)
	{
		*store_space = (number % 8) + '0';
		number = number / 8;
		store_space++;
	}
	*store_space = '\0';
	rev_string(_ptr_, _strlen(_ptr_));
	return (_ptr_);
}
