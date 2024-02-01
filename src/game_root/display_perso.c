/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** display_perso
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_struct.h"

static void static_perso(rpg_t *t)
{
    if (t->perso_stats->direction_memory == 1)
        t->perso_stats->rect.left = 18 * 3;
    if (t->perso_stats->direction_memory == 2)
        t->perso_stats->rect.left = 17.6 * 9 + t->perso_stats->rect_left;
    if (t->perso_stats->direction_memory == 3)
        t->perso_stats->rect.left = 2;
    if (t->perso_stats->direction_memory == 4)
        t->perso_stats->rect.left =  17.6 * 6 + t->perso_stats->rect_left;
}

static void eventbutton_perso2(rpg_t *t)
{
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        t->perso_stats->rect.left = 54 + t->perso_stats->counter2;
        t->perso_stats->direction_memory = 1;
        t->perso_stats->counter2 += 18;
        if (t->perso_stats->rect.left >= 108) {
            t->perso_stats->rect.left = 54;
            t->perso_stats->counter2 = 18;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        t->perso_stats->rect.left = 2 + t->perso_stats->counter2;
        t->perso_stats->direction_memory = 3;
        t->perso_stats->counter2 += 18;
        if (t->perso_stats->rect.left >= 52.8) {
            t->perso_stats->rect.left = 2;
            t->perso_stats->counter2 = 18;
        }
    }
    t->perso_stats->counter = 0;
}

static void eventbutton_perso(rpg_t *t)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) == sfTrue) {
        t->perso_stats->rect.left = 106 + t->perso_stats->counter2;
        t->perso_stats->direction_memory = 4;
        t->perso_stats->counter2 += 18;
        if (t->perso_stats->rect.left >= 150) {
            t->perso_stats->rect.left = 106;
            t->perso_stats->counter2 = 18;
        }
    }
    if (sfKeyboard_isKeyPressed(sfKeyLeft) == sfTrue) {
        t->perso_stats->rect.left = 160 + t->perso_stats->counter2;
        t->perso_stats->direction_memory = 2;
        t->perso_stats->counter2 += 18;
        if (t->perso_stats->rect.left >= 204) {
            t->perso_stats->rect.left = 160;
            t->perso_stats->counter2 = 18;
        }
    }
    eventbutton_perso2(t);
}

static void run_perso(rpg_t *t)
{
    if (sfKeyboard_isKeyPressed(sfKeyRight) || \
    sfKeyboard_isKeyPressed(sfKeyDown) || \
    sfKeyboard_isKeyPressed(sfKeyUp) || \
    sfKeyboard_isKeyPressed(sfKeyLeft)) {
        if (t->perso_stats->counter > 0) {
            eventbutton_perso(t);
        }
    } else
        static_perso(t);
    if (sfKeyboard_isKeyPressed(sfKeyLShift) == sfTrue)
        t->perso_stats->rect.top = 30;
    else
        t->perso_stats->rect.top = 3;
}

void display_perso(rpg_t *t)
{
    t->perso_stats->pos = sfSprite_getPosition(t->perso);
    run_perso(t);
    sfSprite_setTextureRect(t->perso, t->perso_stats->rect);
    sfRenderWindow_drawSprite(t->window, t->perso, NULL);
}
