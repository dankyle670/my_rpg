/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** battle
*/

#include "display_battle.h"

static void init_battleclock(battle_t *battle, rpg_t *t)
{
    sfTime time = sfClock_getElapsedTime(battle->clock);

    battle->seconds = time.microseconds / 100;
    if (battle->seconds > 5) {
        sfClock_restart(battle->clock);
        t->tmp_leftbattle += 480;
    }
    if (t->tmp_leftbattle >= 2400) {
        t->tmp_leftbattle = 0;
        t->tmp_topbattle += 451;
    }
}

void display_arena(rpg_t *t, battle_t *battle)
{
    sfRenderWindow_drawSprite(t->window, battle->bg_sprt, NULL);
    sfRenderWindow_drawSprite(t->window, battle->pokemon_logo, NULL);
    sfSprite_setTextureRect(battle->battle_sprt, t->rect);
    sfRenderWindow_drawSprite(t->window, battle->battle_sprt, NULL);
    if (t->pokemon->poke_memory == 1)
        sfSprite_setTextureRect(battle->pokemon, t->pokemon->rect);
    if (t->pokemon->poke_memory == 2)
        sfSprite_setTextureRect(battle->pokemon, t->pokemon->rect2);
    if (t->pokemon->poke_memory == 3)
        sfSprite_setTextureRect(battle->pokemon, t->pokemon->rect3);
    sfRenderWindow_drawSprite(t->window, battle->pokemon, NULL);
    sfSprite_setTextureRect(battle->perso, (sfIntRect) {19, 410, 50, 60});
    sfRenderWindow_drawSprite(t->window, battle->perso, NULL);
}

void start_battle(rpg_t *t, battle_t *battle)
{
    sfEvent ev;

    t->mousepos = sfMouse_getPositionRenderWindow(t->window);
    display_arena(t, battle);
    sfSprite_setTextureRect(battle->type, (sfIntRect) {0, 0, 32, 16});

    while (sfRenderWindow_pollEvent(t->window, &ev))
        while (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
            if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue) {
                sfSprite_setPosition(battle->type, (sfVector2f)\
                {get_rand(1700), get_rand(900)});
                sfRenderWindow_drawSprite(t->window, battle->type, NULL);
                battle->counter += 1;
            }
            if (battle->counter >= 7000)
                t->binare_battle = 0;
        }
    cursor(t);
}

void display_count_down(rpg_t *t, battle_t *battle)
{
    sfRenderWindow_drawSprite(t->window, battle->bg_sprtblack, NULL);
    sfRenderWindow_drawSprite(t->window, battle->pokemon_logo, NULL);
    sfSprite_setTextureRect(battle->count_down,
    (sfIntRect) {t->tmp_leftbattle, t->tmp_topbattle, 480, 451});
    sfRenderWindow_drawSprite(t->window, battle->count_down, NULL);
    sfText_setColor(t->profesor->text, (sfColor) {255, 255, 255, 255});
    sfText_setPosition(t->profesor->text, (sfVector2f) {450, 950});
    sfText_setString(t->profesor->text, \
    "Clique sur le plus de type de pokemon pour l'attraper !");
    sfRenderWindow_drawText(t->window, t->profesor->text, NULL);
}

void display_battle(rpg_t *t)
{
    if (t->binare_battle == 1) {
        battle_t *battle = init_battle();
        init_battleclock(battle, t);
        sfMusic_pause(t->music.main_music);
        display_count_down(t, battle);
        if (t->tmp_topbattle >= 3157)
            start_battle(t, battle);
        if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
            sfMusic_play(t->music.main_music);
            t->binare_battle = 2;
        }
        if (t->binare_battle == 2)
            free(battle);
    }
}
