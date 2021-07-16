#include "regex.h"
/**
 * regex_match - function that checks whether
 * a given pattern matches a given string.
 * @str: is the string to scan
 * @pattern: is the regular expression
 * Return: must return 1 if the pattern matches
 * the string, or 0 if it doesn’t
 **/
int regex_match(char const *str, char const *pattern)
{
	int i = 0;
	int b = 0;

	while (pattern[b])
	{
		if (pattern[b] == str[i])
		{
			i++;
			b++;
		}
		else if (pattern[b] == '.')
		{
			b++;
			if (pattern[b] != '*')
				i++;
			if (str[i] == pattern[b + 1] && str[i + 1] == pattern[b + 2])
				b++;
			while (pattern[b] && pattern[b] == '*')
			{
				i++;
				if (pattern[b + 1] == str[i])
					break;
			}
		}
		else if (pattern[b] == '*' || (pattern[b + 1] && pattern[b + 1] == '*'))
		{
			while (str[i] == str[i - 1])
				i++;
			b++;
		}
		else
			return (0);
	}

	return (strlen(str) == (unsigned int)i);
}
