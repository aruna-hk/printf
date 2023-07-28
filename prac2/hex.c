#include "main.h"
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
* uint_to_hex - changes unsigne int to hex;
* @num: takes unsgned int
* @id: character specifier x/X
* Return: ptr to string of hexadecimal
*/
char *hex_convert(unsigned int num, char id)
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
		printf("Memory allocation failed.\n");
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
