/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** manage_input2
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_struct.h"

static void move_right(rpg_t *t)
{
    if (t->colision->right_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){-3, 0});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){-3, 0});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){-3, 0});
            sfSprite_move(t->main_bg, (sfVector2f){-3, 0});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){-3, 0});
            sfSprite_move(t->profesor->sprt, (sfVector2f){-3, 0});
            t->perso_stats->real_pos.x += 3;
        }
    }
}

static void move_left(rpg_t *t)
{
    if (t->colision->left_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){3, 0});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){3, 0});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){3, 0});
            sfSprite_move(t->main_bg, (sfVector2f){3, 0});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){3, 0});
            sfSprite_move(t->profesor->sprt, (sfVector2f){3, 0});
            t->perso_stats->real_pos.x -= 3;
        }
    }
}

static void move_top(rpg_t *t)
{
    if (t->colision->top_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){0, 3});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){0, 3});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){0, 3});
            sfSprite_move(t->main_bg, (sfVector2f){0, 3});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){0, 3});
            sfSprite_move(t->profesor->sprt, (sfVector2f){0, 3});
            t->perso_stats->real_pos.y -= 3;
        }
    }
}

static void move_down(rpg_t *t)
{
    if (t->colision->down_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){0, -3});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){0, -3});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){0, -3});
            sfSprite_move(t->main_bg, (sfVector2f){0, -3});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){0, -3});
            sfSprite_move(t->profesor->sprt, (sfVector2f){0, -3});
            t->perso_stats->real_pos.y += 3;
        }
    }
}

void manage_input2(rpg_t *t)
{
    move_right(t);
    move_left(t);
    move_top(t);
    move_down(t);
}
