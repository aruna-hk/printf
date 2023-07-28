#include "main.h"
/**
* convert_to_hex - convert unsigned int to string
* @value unsigned int value
* Return:ptr to hex string/NULL;
*/
char *convert_to_hex(unsigned long num_v)
{
	int lower = 0;
	char hex_digits[] = "0123456789ABCDEF";
	int num_digits = sizeof(num_v) * 2;
	int i = 0;
	char *hex_string = (char *)malloc((num_digits + 1) * sizeof(char));

	if (hex_string == NULL)
		return (NULL);

	for (i = num_digits - 1; i >= 0; i--)
	{
		int digit = (num_v >> (i * 4)) & 0xF;
		hex_string[num_digits - 1 - i] = lower ? hex_digits[digit] : hex_digits[digit + 10];
	}
	hex_string[num_digits] = '\0';
	return (hex_string);
}
