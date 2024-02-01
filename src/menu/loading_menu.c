/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** pause_menu
*/

#include "loading_menu.h"

char *random_path(void)
{
    int rdm = get_rand(4);
    char *path;

    if (rdm == 0)
        path = "textures/layers/bg1.jpg";
    if (rdm == 1)
        path = "textures/layers/bg2.jpg";
    if (rdm == 2)
        path = "textures/layers/bg3.jpg";
    if (rdm == 3)
        path = "textures/layers/bg4.png";
    if (rdm == 4)
        path = "textures/layers/bg5.jpg";
    return path;
}

static void init_clockmenu(menu_t *b)
{
    sfTime time = sfClock_getElapsedTime(b->clock);

    b->seconds = time.microseconds / 10000;
    if (b->seconds > 2) {
        sfClock_restart(b->clock);
        b->pokeball->rect.left += 800;
    }
    if (b->pokeball->rect.left > 3201) {
        b->pokeball->rect.left = 0;
        b->pokeball->rect.top += 600;
    }
}

static void skip_loading(rpg_t *t, menu_t *b)
{
    b->pokeball->rect.top = 0;
    t->binare_loadingmenu *= -1;
    sfSprite_destroy(b->loading_bg->sprt);
    sfSprite_destroy(b->pokeball->sprt);
}

static void skip_root(rpg_t *t, menu_t *b)
{
    if (b->pokeball->rect.top > 1200) {
        if (sfKeyboard_isKeyPressed(sfKeyReturn) == sfTrue)
            skip_loading(t, b);
        if (b->pokeball->rect.top > 13001)
            skip_loading(t, b);
    }
    if (sfKeyboard_isKeyPressed(sfKeySpace) == sfTrue)
        skip_loading(t, b);
}

void loading_menu(rpg_t *t, menu_t *b)
{
    event_append(t);
    init_clockmenu(b);
    sfRenderWindow_drawSprite(t->window, b->loading_bg->sprt, NULL);
    sfSprite_setTextureRect(b->pokeball->sprt, b->pokeball->rect);
    sfRenderWindow_drawSprite(t->window, b->pokeball->sprt, NULL);
    sfRenderWindow_display(t->window);
    skip_root(t, b);
}
