/*
** EPITECH PROJECT, 2022
** my_strndup.c
** File description:
** my_strndup
*/

#include <stdlib.h>
#include "my.h"

char *my_strncpy(char *dest, char const *src, int nb);

char *my_strndup(char const *src, int n)
{
    char *str;

    str = malloc(sizeof(char) * (n + 1));
    if (str == NULL)
        return NULL;
    return my_strncpy(str, src, n);
}
