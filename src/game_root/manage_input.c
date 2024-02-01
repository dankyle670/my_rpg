/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** manage_input
*/

#include "manage_input.h"

static void move_right(rpg_t *t)
{
    if (t->colision->right_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){-6, 0});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){-6, 0});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){-6, 0});
            sfSprite_move(t->main_bg, (sfVector2f){-6, 0});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){-6, 0});
            sfSprite_move(t->profesor->sprt, (sfVector2f){-6, 0});
            t->perso_stats->real_pos.x += 6;
        }
    }
}

static void move_left(rpg_t *t)
{
    if (t->colision->left_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){6, 0});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){6, 0});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){6, 0});
            sfSprite_move(t->main_bg, (sfVector2f){6, 0});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){6, 0});
            sfSprite_move(t->profesor->sprt, (sfVector2f){6, 0});
            t->perso_stats->real_pos.x -= 6;
        }
    }
}

static void move_up(rpg_t *t)
{
    if (t->colision->top_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){0, 6});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){0, 6});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){0, 6});
            sfSprite_move(t->main_bg, (sfVector2f){0, 6});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){0, 6});
            sfSprite_move(t->profesor->sprt, (sfVector2f){0, 6});
            t->perso_stats->real_pos.y -= 6;
        }
    }
}

static void move_down(rpg_t *t)
{
    if (t->colision->down_mem == 1) {
        if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
            sfSprite_move(t->pokemon->sprt, (sfVector2f){0, -6});
            sfSprite_move(t->pokemon->sprt2, (sfVector2f){0, -6});
            sfSprite_move(t->pokemon->sprt3, (sfVector2f){0, -6});
            sfSprite_move(t->main_bg, (sfVector2f){0, -6});
            sfSprite_move(t->main_bgsurcouche, (sfVector2f){0, -6});
            sfSprite_move(t->profesor->sprt, (sfVector2f){0, -6});
            t->perso_stats->real_pos.y += 6;
        }
    }
}

void manage_input(rpg_t *t)
{
    if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue) {
        move_right(t);
        move_left(t);
        move_up(t);
        move_down(t);
    } else
        manage_input2(t);
}
