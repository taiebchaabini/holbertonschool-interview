#include "holberton.h"
#include <stdio.h>
/**
 * wildcmp - Function that compares two string
 * @s1: String 1 to be compared
 * @s2: String 2 to be compared - May contain the wildcard "*"
 * Return: returns 1 if the strings can be considered identical,
 * otherwise return 0.
 **/
int wildcmp(char *s1, char *s2)
{
	if (!s1 || !s2)
		return (0);
	if (*s1 == '\0' && *s2 == '\0')
		return (1);

	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	if (s2[0] == '*')
	{
		if (s2[1] == '*')
			return (wildcmp(s1, s2 + 1));
		if (s1[0] != s2[1])
			return (wildcmp(s1 + 1, s2));
		else
			return (wildcmp(s1, s2 + 1));
	}
	return (0);
}
