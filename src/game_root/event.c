/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** event
*/

#include "event.h"

static void key_pressed(rpg_t *t)
{
    if (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
        t->binare_particule = 1;
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        t->binare_menupause = 1;
}

void is_clicked_root_fonctions(rpg_t *t)
{
    if (t->menu_evt.type == sfEvtMouseButtonPressed && \
    is_clicked(t, 890, 1119, 187, 312) == 1)
        t->binare_menupause = 0;
    if (t->menu_evt.type == sfEvtMouseButtonPressed && \
    is_clicked(t, 890, 1119, 387, 512) == 1) {
        t->binare_particule = 1;
    }
    if (t->menu_evt.type == sfEvtMouseButtonPressed && \
    is_clicked(t, 890, 1119, 587, 720) == 1)
        sfRenderWindow_close(t->window);
}

void event_append(rpg_t *t)
{
    sfEvent ev;

    while (sfRenderWindow_pollEvent(t->window, &ev)) {
        if (ev.type == sfEvtClosed)
            sfRenderWindow_close(t->window);
        t->menu_evt = ev;
        is_clicked_root_fonctions(t);
        while (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            key_pressed(t);
        if (t->binare_menupause == 1 && \
        sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(t->window);
        while (sfKeyboard_isKeyPressed(sfKeyA) == sfTrue)
            key_pressed(t);
    }
}
