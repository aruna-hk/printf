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
}

