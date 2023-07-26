#include "main.h"
 void print_all(char *s,char *buffer,va_list hk,unsigned int precision)
 {    
         switch (s) 
         {
                 case "c":
                         char c = va_arg(hk, int);
                        char str[2] = {c,'\0'};
                         strcat(buffer,str);
                         break;
		 case "ld":
                 case "i":
                        int insert1 = va_arg(hk, int);
                        void (*ptr1)(int *,char *) = int_to_string;
                        ptr1(&insert1,buffer);
                         printf("%d", va_arg(hk, int));
                        break;
		 case "lf":
                 case "f":
                        float insert2 = va_arg(hk, double);
                        void (*ptr2)(float *,char *,unsigned int) = float_to_string;
                        ptr2(&insert2,buffer,precision);
                        break;
                 case 'd':
                        float insert3 = va_arg(hk, double);
                        void (*ptr3)(float *,char *,unsigned int) = float_to_string;
                        ptr3(&insert3,buffer,precision);
                         break;

                 case 's':
                        char *cj = va_arg(hk, char *); 
                        strcat(buffer,cj);
                        break;
                 default:
                         char *buffer_op  = "invalid identifier";
			 write(1,buffer_op,strlen(buffer_op));
         }    
}
