/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** sprite_menu
*/

#include "sprite_menu.h"

sfRenderWindow *create_window(int res1, int res2)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {res1, res2, 64};

    window = CREATE(video_mode, "Pokemon", sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    return window;
}

sfSprite *sprite_menu(void)
{
    sfTexture *my_texture = sfTexture_createFromFile\
    ("textures/gif_to_sprite/menu.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfVector2f my_pos = {190, 0};
    sfVector2f scale = {3.1, 3.1};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    return my_sprite;
}

sfText *text_menu(void)
{
    sfVector2f my_pos = {455, 520};
    sfFont* font = sfFont_createFromFile\
    ("textures/police/good_timing.ttf");
    sfText* text = sfText_create();

    sfText_setString(text, "START");
    sfText_setFont(text, font);
    sfText_setPosition(text, my_pos);
    sfText_setCharacterSize(text, 58);
    return text;
}

sfText *text_menu2(void)
{
    sfVector2f my_pos = {1185, 520};
    sfFont* font = sfFont_createFromFile\
    ("textures/police/good_timing.ttf");
    sfText* text = sfText_create();

    sfText_setString(text, "EXIT");
    sfText_setFont(text, font);
    sfText_setPosition(text, my_pos);
    sfText_setCharacterSize(text, 58);
    return text;
}

sfText *text_menu3(void)
{
    sfVector2f my_pos = {570, 400};
    sfFont* font = sfFont_createFromFile("textures/police/good_timing.ttf");
    sfText* text = sfText_create();

    sfText_setString(text, "Defender");
    sfText_setFont(text, font);
    sfText_setPosition(text, my_pos);
    sfText_setCharacterSize(text, 90);
    return text;
}
