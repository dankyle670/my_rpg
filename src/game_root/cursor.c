/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** cursor
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_struct.h"

int cursor(rpg_t *t)
{
    sfBool bool = 0;
    t->mousepos = sfMouse_getPositionRenderWindow(t->window);
    sfRenderWindow_setMouseCursorVisible(t->window, bool);
    t->pos_cursor.x = t->mousepos.x;
    t->pos_cursor.y = t->mousepos.y;
    sfSprite_setPosition(t->cursor, t->pos_cursor);
    sfRenderWindow_drawSprite(t->window, t->cursor, NULL);
    return 0;
}
