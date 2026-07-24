#include "main.h"

/**
 * _printf - Produces output according to a format
 * @format: Format string with directives
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
va_list args;
int i;
int count;

if (format == NULL)
return (-1);

va_start(args, format);
i = 0;
count = 0;

while (format[i] != '\0')
{
if (format[i] == '%')
{
i++;
if (format[i] == '\0')
break;
count += handle_specifier(format[i], args);
}
else
{
count += _putchar(format[i]);
}
i++;
}
va_end(args);
return (count);
}
