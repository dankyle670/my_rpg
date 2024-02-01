/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** pause_menu
*/

#include "pause_menu.h"

int is_clicked(rpg_t *d, int lowx, int highx, int lowy, int highy)
{
    if (d->menu_evt.mouseButton.x >= lowx && \
    d->menu_evt.mouseButton.x <= highx )
        if (d->menu_evt.mouseButton.y >= lowy && \
        d->menu_evt.mouseButton.y <= highy)
            return 1;
    return 0;
}

void pause_menu(rpg_t *t)
{
    menu_pause_t *d = init_menu_button();
    if (t->binare_menupause == 1) {
        sfMusic_pause(t->music.main_music);
        sfRenderWindow_drawSprite(t->window, t->pause->bg_sprite, NULL);
        sfRenderWindow_drawRectangleShape(t->window, d->pause_butt1, NULL);
        sfRenderWindow_drawRectangleShape(t->window, d->pause_butt2, NULL);
        sfRenderWindow_drawRectangleShape(t->window, d->pause_butt3, NULL);
        sfText_setString(t->profesor->text,
        "But du jeu : tuer tout les pokemons !");
        sfText_setColor(t->profesor->text, (sfColor) {255, 255, 255, 255});
        sfRenderWindow_drawText(t->window, t->profesor->text, NULL);
        if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
            sfRenderWindow_close(t->window);
        cursor(t);
    }
    if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue) {
        t->binare_menupause = 0;
    }
}
