#include "main.h"
/**
* handle - manage buffer
* @buffer: pointer to buffer
*/
void handle(char *buffer)
{
	write(1,buffer,_strlen(buffer));
	buffer[0] = '\0';
}
