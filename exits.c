#include "shell.h"

/**
 **_strncp - copies a string
 *@destination: the destinationination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *_strncp(char *destination, char *src, int n)
{
	int i, j;
	char *s = destination;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		destination[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			destination[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strcat - concatenates two strings
 *@destination: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strcat(char *destination, char *src, int n)
{
	int i, j;
	char *s = destination;

	i = 0;
	j = 0;
	while (destination[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		destination[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		destination[i] = '\0';
	return (s);
}

/**
 **_strch - locates a character in a string
 *@s: the string to be parsed
 *@ch: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strch(char *s, char ch)
{
	do {
		if (*s == ch)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
