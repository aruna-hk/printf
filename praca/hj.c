#include "main.h"
#include <limits.h>
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
//	printf("strlen = %d %s\n",_strlen(store_num),store_num);
	char *ptr_ss = malloc(sizeof(char) * (strlen(store_num)  + 1));
	strcpy(ptr_ss,store_num);
}
char *check_and_alloc(char s, va_list args) {
	char *ptr;
    if (s == 'c') {
        char c = va_arg(args, int);
        char str[2] = {c, '\0'};:wq
        strcat(dest, str);
    } else if (s == 's') {
        char *string_ = va_arg(args, char *); 
        strcat(dest, string_);
        *index_insert += strlen(string_);
    } else if (s == 'd' || s == 'u') {
        int integer = va_arg(args, int);
        char int_s[20];
        sprintf(int_s, "%d", integer);
        strcat(dest, int_s);
        *index_insert += strlen(int_s);
    }   
}


int simple_print(char *string, ...)
{
	va_list args;
	va_start(args,string);
	while (*string ! = '\0')
	{
		if (*string == '%')
		{
			string++;
			char *ptr = get_funct
			while (*ptr != '\0')
			{
				write(1,ptr,1);
				ptr++;
			}
			string++;
		}
		write(1,string,1);
		string++;
	}		
	return (strlen(max_buffer));
}
int main()
{
	int age = -225;
	char *dog = "sam";
	char *name2 = "varun";
	int p = 23;
	simple_print("%d kiptoo age %d %s %s\n",p,age,dog,name2);
        int len;
        int len2;
        unsigned int ui;
        void *addr;

        len = simple_print("Let's try to printf a simple sentence.\n");
        len2 = printf("Let's try to printf a simple sentence.\n");

    ui = (unsigned int)INT_MAX + 1024;
    addr = (void *)0x7ffe637541f0;
    simple_print("Length:[%d, %i]\n", len, len);
    printf("Length:[%d, %i]\n", len2, len2);
    simple_print("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    simple_print("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    simple_print("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    simple_print("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    simple_print("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    simple_print("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    simple_print("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);
    len = simple_print("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    simple_print("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    simple_print("Unknown:[%r]\n");
//    printf("Unknown:[%r]\n");*/
	return (0);
}
