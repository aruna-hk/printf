#include "main.h"
/**
* rev_string - reverse string--*numnumber case
* @s: pointer to the string literal to operate on--
*/
void rev_string(char *start)
{
	char swap;
	int len = strlen(start);
	char *end = start+ (len - 1);

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
* _strlen - check string legthn
* @s: pointer to array of chaacters
* Return: len-length of the string
*/
int _strlen(char *s)
{
int len = 0;

	while (*s != '\0')
	{
		len = len + 1;
		s++;
	}
	return (len);
}

/**
* int_to_string -- convert interger to string
* to append to buffer to flush to stdout
* @*numnum: take *numnumber as arguemen
*/
char *int_to_string(int num)
{
	int flag;

	if (num < 0)
	{
		flag = 1;
		num = -num;
	}
	int i = 0;
	char store_num[20];

	while (num != 0 && i < 20)
	{
		store_num[i] = (num % 10) + '0';
		num = num / 10;
		i++;
	}
	if (flag == 1)
	{
		store_num[i] = '-';
	}
	rev_string(store_num);
	char *ptr_ss = malloc(sizeof(char) * (strlen(store_num)  + 1));
	strcpy(ptr_ss,store_num);
	 return (ptr_ss);
}
char *float_to_string(float *i, unsigned int precision) {
int intPart = (int)(*i); // Extract integer part of the float
    char intPart_str[20];
    char *decimalPart_str;
    char *default_zero = "000000";
    int default_precision = 6;

    char *intPart_str_ptr = int_to_string(intPart);

    strcat(intPart_str_ptr, ".");
    default_precision = precision;
    float decimalPart = (*i - intPart) * 1000000; // Extract decimal part of the float

    if (decimalPart == 0) {
        strcat(intPart_str_ptr, default_zero);
    } else {
        intPart_str_ptr[strlen(intPart_str_ptr) - 1] = '\0'; // Remove the '.' before appending decimal part
        decimalPart_str = int_to_string((int)decimalPart);
        strncat(intPart_str_ptr, decimalPart_str, precision);
    }

    return intPart_str_ptr;
}
int main()
{
	int man = 678;
	float kk= 89760.3578;
	char *nm = int_to_string(man);
	printf("%s\n",nm);
	char *k = float_to_string(&kk, 0);	
	printf("%s\n",k);
	return (0);
}
