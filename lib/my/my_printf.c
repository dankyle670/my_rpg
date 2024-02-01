/*
** EPITECH PROJECT, 2021
** mypoke
** File description:
** my_printf
*/

#include "my.h"
#include <stdio.h>
#include <stdarg.h>

void flags(char *s, va_list list, int i)
{
    if (s[i] == 'i' || s[i] == 'd')
        my_put_nbr(va_arg(list, int));
    if (s[i] == 'u')
        my_put_nbr_positive(va_arg(list, int));
    if (s[i] == 'c')
        my_putchar(va_arg(list, int));
    if (s[i] == 's')
        my_putstr(va_arg(list, char *));
    if (s[i] == 'x' || s[i] == 'X')
        my_put_nbr_base(va_arg(list, int), 16);
    if (s[i] == 'b')
        my_put_nbr_base(va_arg(list, int), 2);
    if (s[i] == 'o')
        my_put_nbr_base(va_arg(list, int), 8);
    if (s[i] == '%')
        my_putchar('%');
}

void my_printf(char *s, ...)
{
    va_list list;

    va_start(list, s);
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '%') {
            i += 1;
            flags(s, list, i);
            i += 1;
        }
        my_putchar(s[i]);
    }
    va_end(list);
}
