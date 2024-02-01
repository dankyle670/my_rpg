/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** destroy_all
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_struct.h"

int free_all(rpg_t *t, menu_t *b)
{
    free(t->profesor);
    free(t->opt);
    free(t->pokemon);
    free(t->perso_stats);
    free(t->colision);
    free(t->pause);
    free(b->pokeball);
    free(b->loading_bg);
    free(b->menu);
    free(b->intro);
    free(t->pix->pixels);
    free(t->pix);
    free(t);
    free(b);
    return 0;
}

int destroy_all(rpg_t *t, menu_t *b)
{
    sfSprite_destroy(t->main_bg);
    sfSprite_destroy(t->cursor);
    sfSprite_destroy(t->perso);
    sfSprite_destroy(t->pokemon->sprt2);
    sfSprite_destroy(t->pokemon->sprt3);
    sfSprite_destroy(t->pix->sprite);
    sfClock_destroy(t->clock);
    sfMusic_destroy(t->music.main_music);
    sfTexture_destroy(t->pix->texture);
    sfRenderWindow_destroy(t->window);
    free_all(t, b);
    return 0;
}
