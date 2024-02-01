/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** game_root
*/

#include "game_root.h"

int init_clock(rpg_t *t)
{
    sfTime time = sfClock_getElapsedTime(t->clock);

    t->seconds = time.microseconds / 10000;
    if (t->seconds > 1)
        manage_input(t);
    if (t->seconds > 10) {
        sfClock_restart(t->clock);
        if (sfKeyboard_isKeyPressed(sfKeyRight) || \
        sfKeyboard_isKeyPressed(sfKeyDown) || \
        sfKeyboard_isKeyPressed(sfKeyUp) || \
        sfKeyboard_isKeyPressed(sfKeyLeft))
            t->perso_stats->counter += 1;
    }
    return 0;
}

void game_root(rpg_t *t)
{
    init_clock(t);
    event_append(t);
    map_colisions(t);
    sfRenderWindow_drawSprite(t->window, t->main_bg, NULL);
    display_perso(t);
    sfRenderWindow_drawSprite(t->window, t->main_bgsurcouche, NULL);
    display_pokemon(t);
    start_quests(t);
    display_battle(t);
    pause_menu(t);
    display_particules(t);
    sfRenderWindow_display(t->window);
}

void display_game(rpg_t *t, menu_t *b)
{
    if (t->binare_loadingmenu == 1)
        loading_menu(t, b);
    else
        game_root(t);
}