#include "main.h"
/**
* _strlen - check string legthn
* @s: pointer to array of chaacters
* Return: len-length of the string
*/
int _strlen(const char *s)
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
*  _strcpy - copy string to another
* @dest: reipient
* @src: source
* Return: dest
*/
void _strcpy(char *dest, char *src)
{

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
/**
 * _strcmp - compare string
 * @s1: sting1
 * @s2: string2
 * Return: difference
*/
int _strcmp(char *s1, char *s2)
{
	int difference;

	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	difference = (int)*s1 - (int)*s2;
	return (difference);
}
/**
 * _strcat - append string to a string
 * @dest: -destination string
 * @src: -source string
 * Return: pointer to dest
 */
void _strcat(char *dest, char *src)
{

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
}
