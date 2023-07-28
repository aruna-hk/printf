#include "main.h"
/**
* uint_to_octal - convert unsigned int to octal
* @number: takes unsigned interger
* Return: pointer to string of octal
*/
char *uint_to_octal(unsigned int number)
{
	int i = 0;
	char *_ptr_ = malloc(sizeof(char) * 1024);

	if (_ptr_ == NULL)
		return (NULL);
	while (number > 0)
	{
		_ptr_[i] = (number % 8) + '0';
		number = number / 8;
		i++;
	}
	_ptr_[i] = '\0';
	rev_string(_ptr_, _strlen(_ptr_));
	return (_ptr_);
}
