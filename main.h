#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list args);
int print_integer(va_list args);
int print_unsign(va_list args);
int print_modulo(va_list args);
int print_string(va_list args);
int print_unsigned_octal(va_list args);
int print_hexadecimal(va_list args);
int print_hexadecimal_maj(va_list args);
int print_binary(va_list args);
int handle_specifier(char spec, va_list args);

#endif