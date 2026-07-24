#include "main.h"

/**
 * print_char - print a character
 * @args: va_list containing the character to print
 * Return: the character to print in c variable
 */
int print_char(va_list args)
{
char c;

c = (char)va_arg(args, int);
return (_putchar(c));
}
