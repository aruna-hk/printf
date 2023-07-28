#include "main.h"
#include <limits.h>
/**
* _memset - function fills the first n bytes destination with char provided
* @s:to be filled by b--bytes
* @b:to fill s
* @n: bytes to be filled
* Return:ptr to str s inserting b ntimes
*/
void _memset(char *s, char b, unsigned int n)
{
    unsigned int i = 0;
    char *init_pointer = s;

    while (i < n)
    {
        *s = b;
        s++;
        i++;
    }
    *s = '\0'; // Null-terminate the string
}
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
        return (ptr_ss);
}
/**
* float_to_string -- convert float to string and set precision
* @precision: how many decimal points to include
* @
*/
/*char *float_to_string(float *i,unsigned int precision)
{
        int float_*numnumber = (int)*i;
        char float_point_int[20];
	char *dc;
        char *default_zero = "000000";
        int default_precision = 6;
        char *my_*numnum_part = int_to_string(&float_*numnumber);
	
        strcat(my_*numnum_part, ".");
        default_precision = precision;
        int dec_part = (*i - (float)float_*numnumber) * 1000000;
        if (dec_part == 0)
        {
                strcat(my_*numnum_part,default_zero);
        }
	else
	{
       		dc = int_to_string(&dec_part);
        	strncat(my_*numnum_part,dc,precision);
	}
	return (my_*numnum_part);
}	
******/
/**
* check_and_alloc - va_arg variable and allocte oit space
* 
*/
void cpy(char *dest, char *src, va_list *args) {
    int dest_index = 0;
    int p_index = 0;

    while (*src != '\0') {
        if (*src == '%') {
            src++;
            char c = *src;
            switch (c) {
		case 'u':
                case 'd':
                {
        	         src++;
        		 int num = va_arg(*args, int);
       			 int len = _strlen(int_to_string(num));
       			 strcat(dest, int_to_string(num));
        		 dest_index += len;
                	  break;
                }
                case 's':
                {
                    char *str = va_arg(*args, char*);
                    int len = _strlen(str);
                    strcat(dest,str);
                    dest_index += len;
                    break;
                }
                default:
                    dest[dest_index++] = *src;
            }
            src++;
        } else {
            dest[dest_index++] = *src;
            src++;
        }
    }

    dest[dest_index] = '\0'; // Null-terminate the destination string
}

int simple_print(char *string, ...)
{
	va_list args;
	va_start(args,string);
	char *max_buffer = malloc(sizeof(char) * BUFFER_SIZE);
	_memset(max_buffer, '\0', strlen(string));
	char *str = malloc(sizeof(char) *(strlen(string) + 1));
	strcpy(str,string);
//	printf("---str%s\n",str);
	cpy(max_buffer,string,&args);
//	printf("--max_buffer--%s\n",max_buffer);
	write(1,max_buffer,strlen(max_buffer));
	va_end(args);
	free(max_buffer);
	free(str);
	return (strlen(max_buffer));
}
int main()
{
	int age = -225;
	char *dog = "sam";
	char *name2 = "varun";
	int p = 23;
//	simple_print("%d kiptoo age %d %s %s\n",p,age,dog,name2);
        int len;
        int len2;
        unsigned int ui;
        void *addr;

        len = simple_print("Let's try to printf a simple sentence.\n");
        len2 = printf("Let's try to printf a simple sentence.\n");

//    ui = (unsigned int)INT_MAX + 1024;
  //  addr = (void *)0x7ffe637541f0;
    simple_print("Length:[%d, %i]\n", len, len);
    /*printf("Length:[%d, %i]\n", len2, len2);
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
