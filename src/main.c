/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** main
*/

#include "my.h"

int menu(void);

static int display_help(void)
{
    my_printf("\n-------------------------------- POKEMON \
--------------------------------\
\n\t\t\t\t\t\t\tcreated with CSFML.\n\n\tUSAGE\n");
    my_printf("\t\t./my_rpg \n\n\n");
    my_printf("\tUSER INTERACTIONS\n");
    my_printf("\t\tLeft arrow\n");
    my_printf("\t\tRight arrow\n");
    my_printf("\t\tUp arrow\n");
    my_printf("\t\tDown arrow\n\n");
    return 0;
}

int main(int ac, __attribute__ ((unused))char **av)
{
    if (ac != 1) {
        display_help();
        return 0;
    }
    menu();
    return 0;
}
