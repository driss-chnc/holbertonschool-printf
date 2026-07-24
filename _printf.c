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
{
return (-1);
}

va_start(args, format);
i = 0;
count = 0;

while (format[i] != '\0')
{
if (format[i] != '%')
{
count += _putchar(format[i]);
i++;
}
if (format[i] == '%')
{
i++;
if (format[i] == 'c')
{
count += print_char(args);
}
else if ((format[i] == 'i') || (format[i] == 'd'))
{
count += print_integer(args);
}
else if (format[i] == 'u')
{
count += print_unsigned(args);
}
else if (format[i] == '%')
{
count += print_modulo(args);
}
else if (format[i] == 's')
{
count += print_string(args);
}
else if (format[i] == 'o')
{
count += print_unsigned_octal(args);
}
else if (format[i] == 'x')
{
count += print_hexadecimal(args);
}
else if (format[i] == 'X')
{
count += print_hexadecimal_maj(args);
}
else if (format[i] == 'b')
{
count += print_binary(args);
}
i++;
}
}

va_end(args);
return (count);
}
