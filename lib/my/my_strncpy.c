/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** my_strncpy
*/

char *my_strncpy(char *dest, char const *src, int nb)
{
    int i = 0;

    while (i < nb && src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
