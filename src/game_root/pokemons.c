/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** pokemons
*/

#include "pokemons.h"

int get_rand(int max)
{
    int rand_n = 0;

    srand(time(NULL));
    rand_n = rand() % max;
    return rand_n;
}

void display_pokemon(rpg_t *t)
{
    if (check_poke_colision(t, t->pokemon, 70) == 1) {
        sfRenderWindow_drawText(t->window, t->pokemon->text, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            t->binare_battle = 1;
    }
    t->pokemon->rect = (sfIntRect)\
    {t->pokemon->tmp_left, t->pokemon->tmp_top, 32, 32};
    t->pokemon->rect2 = (sfIntRect)\
    {t->pokemon->tmp_left2, t->pokemon->tmp_top2, 32, 32};
    t->pokemon->rect3 = (sfIntRect)\
    {t->pokemon->tmp_left3, t->pokemon->tmp_top3, 32, 32};
    sfSprite_setTextureRect(t->pokemon->sprt, t->pokemon->rect);
    sfSprite_setTextureRect(t->pokemon->sprt2, t->pokemon->rect2);
    sfSprite_setTextureRect(t->pokemon->sprt3, t->pokemon->rect3);
    sfRenderWindow_drawSprite(t->window, t->pokemon->sprt, NULL);
    sfRenderWindow_drawSprite(t->window, t->pokemon->sprt2, NULL);
    sfRenderWindow_drawSprite(t->window, t->pokemon->sprt3, NULL);
    return;
}
