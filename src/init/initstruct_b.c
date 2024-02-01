/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** initiation
*/

#include "initstruct_b.h"

menu_t *init_menu2(menu_t *b)
{
    b->seconds = 0;
    b->game_changer = 0;
    b->pokeball->rect = (sfIntRect) {0, 0, 800, 600};
    b->intro->rect = (sfIntRect) {0, 0, 640, 360};
    b->menu->rect = (sfIntRect) {0, 0, 500, 333};
    b->pokeball->sprt = create_sprite((sfVector2f) {1600, 750},\
    (sfVector2f) {0.4, 0.4}, "textures/gif_to_sprite/pokeball_png.png");
    b->intro->sprt = create_sprite((sfVector2f) {0, 0},\
    (sfVector2f) {3, 3}, "textures/gif_to_sprite/intro.png");
    b->dark = create_sprite((sfVector2f) {0, 0},\
    (sfVector2f) {1, 1}, "textures/layers/dark.jpg");
    b->loading_bg->sprt = create_sprite((sfVector2f) {0, 0},\
    (sfVector2f) {1, 1}, random_path());
    return b;
}

menu_t *init_menu(void)
{
    menu_t *b = malloc(sizeof(menu_t));
    b->pokeball = malloc(sizeof(gif_t));
    b->loading_bg = malloc(sizeof(gif_t));
    b->menu = malloc(sizeof(gif_t));
    b->intro = malloc(sizeof(gif_t));
    b->menu->sprt = sprite_menu();
    b->button1 = sfRectangleShape_create();
    b->button2 = sfRectangleShape_create();
    b->clock = sfClock_create();
    b->clock2 = sfClock_create();
    b->display_startmenu = 0;
    b->pos1.x = 450;
    b->pos1.y = 500;
    b->pos2.x = 1140;
    b->pos2.y = 500;
    init_menu2(b);
    return b;
}
