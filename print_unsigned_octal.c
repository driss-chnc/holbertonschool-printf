#include "main.h"

/**
 * print_unsigned_octal - print an unsigned octal
 * @args: va_list containing an unsigned octal
 * Return: numbers of characters print
 */
int print_unsigned_octal(va_list args)
{
int n;
unsigned int num;
unsigned int div;
int count;

n = va_arg(args, int);
count = 0;
if (n == 0)
{
_putchar('0');
return (1);
}
else
{
num = n;
}
div = 1;
while (num / div >= 8)
{
div *= 8;
}
while (div != 0)
{
_putchar((num / div) % 8 + '0');
count++;
div /= 8;
}
return (count);
} 
