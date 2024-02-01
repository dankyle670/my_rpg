/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** colisions
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_struct.h"

int check_objcolision(rpg_t *t, bot_t *bot, int val)
{
    bot->pos = sfSprite_getPosition(bot->sprt);
    if ((bot->pos.x + bot->rect.width + val) > (t->perso_stats->pos.x) &&
    (bot->pos.x - val) < (t->perso_stats->pos.x + t->perso_stats->rect.width))
        if ((bot->pos.y + bot->rect.height + val) >\
        (t->perso_stats->pos.y) && (bot->pos.y - val) <\
        (t->perso_stats->pos.y + t->perso_stats->rect.height))
            return 1;
    return 0;
}

static int check_pos1(rpg_t *t, bot_t *bot)
{
    if ((bot->pos.x + bot->rect.width + 100) >\
    (t->perso_stats->pos.x) && (bot->pos.x - 100) <\
    (t->perso_stats->pos.x + t->perso_stats->rect.width))
        if ((bot->pos.y + bot->rect.height + 100) >\
        (t->perso_stats->pos.y) && (bot->pos.y - 100) <\
        (t->perso_stats->pos.y + t->perso_stats->rect.height)) {
            t->pokemon->poke_memory = 1;
            return 1;
        }
    return 0;
}

static int check_pos2(rpg_t *t, bot_t *bot, int val)
{
    if ((bot->pos2.x + bot->rect2.width + val) >\
    (t->perso_stats->pos.x) && (bot->pos2.x - val) <\
    (t->perso_stats->pos.x + t->perso_stats->rect.width))
        if ((bot->pos2.y + bot->rect2.height + val) >\
        (t->perso_stats->pos.y) && (bot->pos2.y - val) <\
        (t->perso_stats->pos.y + t->perso_stats->rect.height)) {
            t->pokemon->poke_memory = 2;
            return 1;
        }
    return 0;
}

static int check_pos3(rpg_t *t, bot_t *bot, int val)
{
    if ((bot->pos3.x + bot->rect3.width + val) >\
    (t->perso_stats->pos.x) && (bot->pos3.x - val) <\
    (t->perso_stats->pos.x + t->perso_stats->rect.width))
        if ((bot->pos3.y + bot->rect3.height + val) >\
        (t->perso_stats->pos.y) && (bot->pos3.y - val) <\
        (t->perso_stats->pos.y + t->perso_stats->rect.height)) {
            t->pokemon->poke_memory = 3;
            return 1;
        }
    return 0;
}

int check_poke_colision(rpg_t *t, bot_t *bot, int val)
{
    bot->pos = sfSprite_getPosition(bot->sprt);
    bot->pos2 = sfSprite_getPosition(bot->sprt2);
    bot->pos3 = sfSprite_getPosition(bot->sprt3);
    if (check_pos1(t, bot) == 1)
        return 1;
    if (check_pos2(t, bot, val) == 1)
        return 1;
    if (check_pos3(t, bot, val) == 1)
        return 1;
    return 0;
}
