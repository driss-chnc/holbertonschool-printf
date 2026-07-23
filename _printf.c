#include "main.h"

/**
 * _printf - function to print characters
 * @format: the format of the char or int we want to print
 * Return: print the char or int wanted
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i;
    int count;

    if (format == NULL)
    {                       //verifie directly if the pointer format is null and return -1 error if true
        return (-1);
    }

    va_start(args, format);
    i = 0;
    count = 0;

    while (format[i] != '\0')
    {
        if (format[i] != '%')
        {
            count += _pucthar(format[i]);
            i++;
        }
        if (format[i] == '%')
        {
            i++;
            if (format[i] == 'c')
            {
                count += print_char(args);
            }
            i++;
        }
    }

    va_end(args);
    return (count);
}
