/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** create_sprite
*/

// #include "my_rpg.h"

#include <SFML/Graphics.h>

sfSprite *create_sprite(sfVector2f pos, sfVector2f size, char *path)
{
    sfSprite *my_sprite = sfSprite_create();
    sfTexture *my_texture = sfTexture_createFromFile(path, NULL);

    sfSprite_setScale(my_sprite, size);
    sfSprite_setPosition(my_sprite, pos);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    return my_sprite;
}

sfSprite *sprite_perso(void)
{
    sfTexture *my_texture = sfTexture_createFromFile\
    ("textures/persos/perso.png", NULL);
    sfSprite *my_sprite = sfSprite_create();
    sfVector2f my_pos = {850, 450};
    sfVector2f scale = {5, 5};

    sfSprite_setScale(my_sprite, scale);
    sfSprite_setPosition(my_sprite, my_pos);
    sfSprite_setTexture(my_sprite, my_texture, sfFalse);
    return my_sprite;
}
