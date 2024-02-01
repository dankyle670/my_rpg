/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** demake_colision
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_struct.h"

void de_make_colision(rpg_t *t)
{
    if (t->colision->right_mem == 0)
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue)
            t->colision->right_mem = 1;
    if (t->colision->top_mem == 0)
        if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue)
            t->colision->top_mem = 1;
    if (t->colision->left_mem == 0)
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue)
            t->colision->left_mem = 1;
    if (t->colision->down_mem == 0)
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue)
            t->colision->down_mem = 1;
}
