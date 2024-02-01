/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** menu
*/

#include "my_menu.h"

void main_menu(menu_t *b)
{
    if (b->display_startmenu != 1) {
        while (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue)
            b->display_startmenu = 1;
    } else
        b->game_changer = 1;
}

static void init_clockmenu2(menu_t *b)
{
    sfTime time = sfClock_getElapsedTime(b->clock2);

    b->seconds2 = time.microseconds / 10000;
    if (b->seconds2 > 4) {
        if (b->intro->rect.top <= 14000) {
            sfClock_restart(b->clock2);
            b->intro->rect.left += 640;
        }
    }
    if (b->intro->rect.left > 2560) {
        b->intro->rect.left = 0;
        b->intro->rect.top += 360;
    }
    if (b->intro->rect.top > 14000) {
        b->intro->rect.left = 0;
        b->pokeball->rect.top = 0;
        b->display_startmenu = 1;
    }
}

static void init_clockmenu3(menu_t *b)
{
    sfTime time = sfClock_getElapsedTime(b->clock2);

    b->seconds2 = time.microseconds / 10000;
    if (b->seconds2 > 6) {
        sfClock_restart(b->clock2);
        b->menu->rect.left += 500;
    }
    if (b->menu->rect.left > 2000) {
        b->menu->rect.left = 0;
        b->menu->rect.top += 333;
    }
    if (b->menu->rect.top >= 2997) {
        b->menu->rect.left = 0;
        b->menu->rect.top = 0;
    }
}

void display_menu(rpg_t *t, menu_t *b)
{
    sfBool bool = 0;

    if (b->display_startmenu != 1) {
        init_clockmenu2(b);
        sfRenderWindow_setMouseCursorVisible(t->window, bool);
        sfSprite_setTextureRect(b->intro->sprt, b->intro->rect);
        sfRenderWindow_drawSprite(t->window, b->intro->sprt, NULL);
    } else {
        init_clockmenu3(b);
        sfRenderWindow_drawSprite(t->window, b->dark, NULL);
        sfSprite_setTextureRect(b->menu->sprt, b->menu->rect);
        sfRenderWindow_drawSprite(t->window, b->menu->sprt, NULL);
        cursor(t);
    }
    check_button(b, t);
    sfRenderWindow_display(t->window);
    if (b->game_changer == 2)
        sfRenderWindow_close(t->window);
}

int menu(void)
{
    rpg_t *t = init_rpg();
    menu_t *b = init_menu();

    if (!t->window)
        return 84;
    sfMusic_play(t->music.main_music);
    while (sfRenderWindow_isOpen(t->window)) {
        if (b->game_changer == 0)
            display_menu(t, b);
        if (b->game_changer == 1)
            display_game(t, b);
    }
    destroy_all(t, b);
    return 0;
}
