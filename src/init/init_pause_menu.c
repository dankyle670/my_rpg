/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** init_pause_menu
*/

#include <stdlib.h>
#include "my_rpg.h"

menu_pause_t *init_menu_button(void)
{
    menu_pause_t *d = malloc(sizeof(menu_pause_t));
    d->pause_butt1 = create_my_button(900, 200, sfBlack);
    d->pause_butt2 = create_my_button(900, 400, sfBlack);
    d->pause_butt3 = create_my_button(900, 600, sfBlack);
    return d;
}
