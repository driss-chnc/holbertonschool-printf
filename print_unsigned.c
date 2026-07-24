#include "main.h"

/**
 * print_unsign - Prints an integer in base 10
 * @args: va_list containing the integer to print
 * Return: Number of characters printed
 */
int print_unsign(va_list args)
{
int n;
unsigned int num;
unsigned int div;
int count;

n = va_arg(args, int);
count = 0;
num = n;
div = 1;

while (num / div >= 10)
{
div *= 10;
}

while (div != 0)
{
_putchar((num / div) % 10 + '0');
count++;
div /= 10;
}

return (count);
}
