/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** sprite
*/

#include <SFML/Graphics.h>

sfSprite *sprite_cursor(void)
{
    sfTexture *my_texture = sfTexture_createFromFile\
    ("textures/objct_png/cursor2.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfVector2f my_pos = {500, 400};
    sfVector2f scale = {0.1, 0.1};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    return my_sprite;
}
