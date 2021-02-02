#include <stdio.h>
#include "holberton.h"

int main(int argc, char **argv)
{
    int i, y;
    int len, len2;
    

    if (argc != 3)
        _print_error();

    len = _strlen(argv[1]);
    len2 = _strlen(argv[2]);
    
    for (y = 1; y <= 2; y++)
    {
        i = 0;
        while (argv[y][i] != '\0')
        {
            if ((_isDigit(argv[y][i]) == 0) || 
            (_isDigit(argv[y][i]) == 2 && i != 0) ||
            (_isDigit(argv[y][i]) == 2 && _strlen(argv[y]) == 1))
                _print_error();
            i++;
        }
    }

    _mul(argv[1], argv[2], len, len2);
    return (1);
}

/**
 * _STRLEN - Calculates the length of a string
 * @str: String to calculate
 * Return: length of a string
**/
int _strlen(char *str)
{
    int i = 0;
    while (str[i] != '\0')
        i++;

    return (i);    
}

/**
 * _mul - Multiply two numbers and return the res as a string
**/
void _mul(char *nb, char *nb2, int nblength, int nb2length){
    char *res = NULL;
    int a = 0, b = 0;
    int counter = 0, counter2 = 0;
    int _nb = 0, _nb2 = 0;
    int len = 0;
    int sum = 0;
    int next = 0;
    int length = 0;
    int tmp = 0;
    
    res = malloc(sizeof(char) * (nblength + nb2length));

    a = nblength - 1;
    b = nb2length - 1;
    counter = 0;
    counter2 = 0;
    while (a >= 0)
    {
        b = nb2length - 1;
        _nb = nb[a] - '0';
        
        while (b >= 0)
        {
            tmp = 0;
            _nb2 = nb2[b] - '0';

            if (res[counter + counter2])
                tmp = res[counter + counter2] - '0';
            sum = _nb * _nb2 + next + tmp;
            next = sum / 10;
            printf("_nb: [%d] AND _nb2: [%d] AND sum is [%d] AND res is [%d] AND next is [%d]\n", _nb, _nb2, sum, res[counter + counter2], next);
            printf("Counter is [%d]\n ", (counter + counter2));
            
           
            printf("TMP IS %d\n", tmp);
            res[counter + counter2] = (sum % 10 + '0');
            printf("Stored %d\n", (sum % 10) );

            counter2++;
            b--;
        }


        if (next > 0)
            res[counter + counter2] += next + '0';
        counter2 = 0;
        a--;
        counter++;
        
    }

    printf("\n");

    length = _strlen(res);

    int i = length;

    for (; i >= 0; i--)
        _putchar(res[i]);
    _putchar('\n');
    
}
/**
 * _isDigit - Checks if the character is a digit.
 * @c: Character to check
 * Return: 1 if the character is a digit otherwise 0
**/
int _isDigit(char c)
{
    if (c >= 48 && c <= 57)
        return (1);
    if (c == 45)
        return (2);
    return (0);
}
/**
 * _print_error - Prints a default error message when an error occurs.
**/
void _print_error()
{
    int i = 0;
    char *msg = "Error";

    while (msg[i] != '\0')
    {
        _putchar(msg[i]);
        i++;
    }

    _putchar('\n');
    exit(98);
}