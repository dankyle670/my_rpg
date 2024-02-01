/*
** EPITECH PROJECT, 2021
** mypoke
** File description:
** my_put_nbr_positive
*/

#include <unistd.h>
#include "my.h"

int my_put_nbr_positive(int nb)
{
    int start;
    int end;

    if (nb < 0) {
        return 0;
    } else {
        end = nb % 10;
        start = nb / 10;
        if (start != 0)
            my_put_nbr(start);
        my_putchar(end + '0');
    }
    return (end);
}
