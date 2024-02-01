/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** quests
*/

#include "quests.h"

static void quest1_profesor_part4(rpg_t *t)
{
    sfRenderWindow_drawSprite(t->window, t->box , NULL);
    sfText_setString(t->profesor->text, "... Attrapes ton premier pokemon!");
    sfRenderWindow_drawText(t->window, t->profesor->text, NULL);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        t->profesor->tmp_left = 4;
}

static void quest1_profesor_part3(rpg_t *t)
{
    sfRenderWindow_drawSprite(t->window, t->box , NULL);
    sfText_setString(t->profesor->text, "... Je suis el Profesor!   ...(E)");
    sfRenderWindow_drawText(t->window, t->profesor->text, NULL);
    if (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
        t->profesor->tmp_left = 3;
}

static void quest1_profesor_part2(rpg_t *t)
{
    sfRenderWindow_drawSprite(t->window, t->box , NULL);
    sfText_setString(t->profesor->text, "Bonjour jeune joueur !  ...(E)");
    sfRenderWindow_drawText(t->window, t->profesor->text, NULL);
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        t->profesor->tmp_left = 2;
}

void quest1_profesor(rpg_t *t)
{
    if (check_objcolision(t, t->profesor, 70) == 1) {
        sfText_setString(t->profesor->text, "Press (E) to start the quest!");
        sfRenderWindow_drawSprite(t->window, t->box , NULL);
        sfText_setColor(t->profesor->text, (sfColor) {0, 0, 0, 255});
        sfRenderWindow_drawText(t->window, t->profesor->text, NULL);
        while (sfKeyboard_isKeyPressed(sfKeyE) == sfTrue)
            t->profesor->tmp_left = 1;
    }
    return;
}

void start_quests(rpg_t *t)
{
    if (t->profesor->tmp_left < 4) {
        t->profesor->rect = (sfIntRect) {430, 7, 18, 23};
        sfSprite_setTextureRect(t->profesor->sprt, t->profesor->rect);
        sfRenderWindow_drawSprite(t->window, t->profesor->sprt, NULL);
        if (t->profesor->tmp_left == 0)
            quest1_profesor(t);
        if (t->profesor->tmp_left == 1)
            quest1_profesor_part2(t);
        if (t->profesor->tmp_left == 2)
            quest1_profesor_part3(t);
        if (t->profesor->tmp_left == 3)
            quest1_profesor_part4(t);
    } else if (t->profesor->tmp_left == 4) {
        sfText_setString(t->profesor->text, "Quest 1: Attraper Florizarre");
        sfRenderWindow_drawText(t->window, t->profesor->text, NULL);
    }
}
