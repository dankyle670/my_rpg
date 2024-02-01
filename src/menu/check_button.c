/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** check_button
*/

#include "check_button.h"

void check_button(menu_t *b, rpg_t *t)
{
    sfEvent ev;

    while (sfRenderWindow_pollEvent(t->window, &ev)) {
        if (ev.type == sfEvtClosed)
            sfRenderWindow_close(t->window);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue)
            main_menu(b);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            b->game_changer = 2;
        if (ev.type == sfEvtMouseButtonPressed) {
            sfTexture *my_texture = sfTexture_createFromFile\
                ("textures/objct_png/cursor.png", NULL);
            sfSprite_setTexture(t->cursor, my_texture, sfFalse);
        } else {
            sfTexture *my_texture = sfTexture_createFromFile\
                ("textures/objct_png/cursor2.png", NULL);
            sfSprite_setTexture(t->cursor, my_texture, sfFalse);
        }
    }
}
