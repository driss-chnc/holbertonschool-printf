#include "main.h"

/**
 * print_hexadecimal - print an unsigned hexadecimal
 * @args: va_list containing an unsigned hexadecimal
 * Return numbers of characters print
 */

 int print_hexadecimal_maj(va_list args)
{
    int n;
    char buffer[32];
    unsigned int num;
    int count;
    int digit;

    num = va_arg(args, unsigned int);

    if (num == 0)
        return (_putchar('0'));

    n = 0;
    while (num > 0)
    {
        digit = num % 16;
        if (digit < 10)
            buffer[n] = digit + '0';
        else
            buffer[n] = (digit - 10) + 'A';
        num /= 16;
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