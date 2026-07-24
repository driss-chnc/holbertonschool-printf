#include "main.h"

/**
 * print_binary - print a binary number
 * @args: va_list containing a binary number
 * Return: the number of characters print
 */

int print_binary(va_list args)
{
int n;
char buffer[32];
unsigned int num;
int count;
int bit;

num = va_arg(args, unsigned int);

if (num == 0)
return (_putchar('0'));

n = 0;
while (num > 0)
{
bit = num % 2;
buffer[n] = bit + '0';
num /= 2;
n++;
}
count = 0;
while (n > 0)
{
n--;
_putchar(buffer[n]);
count++;
}
return (count);
}
