#include "main.h"

/**
 * handle_specifier - Handles format specifiers
 * @spec: The format specifier character
 * @args: The va_list with the arguments
 *
 * Return: Number of characters printed for this specifier
 */
int handle_specifier(char spec, va_list args)
{
int count = 0;

if (spec == 'c')
count += print_char(args);
else if (spec == 'i' || spec == 'd')
count += print_integer(args);
else if (spec == 'u')
count += print_unsign(args);
else if (spec == '%')
count += print_modulo(args);
else if (spec == 's')
count += print_string(args);
else if (spec == 'o')
count += print_unsigned_octal(args);
else if (spec == 'x')
count += print_hexadecimal(args);
else if (spec == 'X')
count += print_hexadecimal_maj(args);
else if (spec == 'b')
count += print_binary(args);
else
{
count += _putchar('%');
count += _putchar(spec);
}
return (count);
}
