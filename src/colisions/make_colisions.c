/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** make_colisions
*/

#include "make_colisions.h"

static void colision_down(rpg_t *t, sfVector2f pos1, sfVector2f pos2)
{
    if ((t->perso_stats->real_pos.y + t->perso_stats->rect.height > pos2.y) &&
    (t->perso_stats->real_pos.y + t->perso_stats->rect.height < pos2.y + 10) &&
    (t->perso_stats->real_pos.x + t->perso_stats->rect.width > pos1.x) &&
    (t->perso_stats->real_pos.x <= pos2.x))
        t->colision->down_mem = 0;
    return;
}

static void colision_left(rpg_t *t, sfVector2f pos1, sfVector2f pos2)
{
    if ((t->perso_stats->real_pos.x < pos2.x) &&
    (t->perso_stats->real_pos.x > pos2.x - 10) &&
    (t->perso_stats->real_pos.y + t->perso_stats->rect.height >= pos2.y) &&
    (t->perso_stats->real_pos.y <= pos1.y))
        t->colision->left_mem = 0;
    return;
}

static void colision_right(rpg_t *t, sfVector2f pos1, sfVector2f pos2)
{
    if ((t->perso_stats->real_pos.x + t->perso_stats->rect.width > pos1.x) &&
    (t->perso_stats->real_pos.x + t->perso_stats->rect.width < pos1.x + 10) &&
    (t->perso_stats->real_pos.y + t->perso_stats->rect.height >= pos2.y) &&
    (t->perso_stats->real_pos.y <= pos1.y))
        t->colision->right_mem = 0;
    return;
}

static void colision_top(rpg_t *t, sfVector2f pos1, sfVector2f pos2)
{
    if ((t->perso_stats->real_pos.y < pos1.y) &&
    (t->perso_stats->real_pos.y > pos1.y - 10) &&
    (t->perso_stats->real_pos.x + t->perso_stats->rect.width >= pos1.x) &&
    (t->perso_stats->real_pos.x <= pos2.x))
        t->colision->top_mem = 0;
    return;
}

void make_colision(rpg_t *t, sfVector2f pos1, sfVector2f pos2)
{
    colision_top(t, pos1, pos2);
    colision_right(t, pos1, pos2);
    colision_left(t, pos1, pos2);
    colision_down(t, pos1, pos2);
    de_make_colision(t);
}
