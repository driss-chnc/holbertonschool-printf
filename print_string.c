#include "main.h"

/**
 * print_string - print a string
 * @args: va_list containing the string to print
 * Return: number of characters to print
 */
int print_string(va_list args)
{
char *str;
int count;

str = va_arg(args, char *);
count = 0;

if (str == NULL)
{
str = "(nil)";
}

while (str[count] != '\0')
{
_putchar(str[count]);
count++;
}

return (count);
}
