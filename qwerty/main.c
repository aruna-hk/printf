#include "main.h"
int main(void)
{
    int age= 56; 
    int len;
    int len2;
    unsigned int ui = 2147484671; 

    len = _printf("Let's %% try to printf a simple sentence.\n");
    len2 = printf("Let's %% try to rintf a simple sentence.\n");
    _printf("Length:[%d, %i]\n", len, len);
    _printf("my age is %d kiptoo",age);
    printf("Length:[%d, %i]\n", len2, len2);
    _printf("Negative:[%d]\n", -762534);
    printf("Negative:[%d]\n", -762534);
    _printf("Unsigned:[%u]\n", ui);
    printf("Unsigned:[%u]\n", ui);
    _printf("Unsigned octal:[%o]\n", ui);
    printf("Unsigned octal:[%o]\n", ui);
    _printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    printf("Unsigned hexadecimal:[%x, %X]\n", ui, ui);
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
/*    _printf("Address:[%p]\n", addr);
    printf("Address:[%p]\n", addr);*/
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    _printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
   /*_printf("Unknown:[%r]\n");
    printf("Unknown:[%r]\n");*/

        return (0);
}

