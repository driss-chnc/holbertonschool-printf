#include "main.h"

/**
 * _putchar - write char c
 * @c: character to print
 * Return: on success 1 , -1 error
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}