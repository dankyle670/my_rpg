/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** create_button
*/

#include <SFML/Graphics.h>

sfRectangleShape *create_button(float posx, float posy, \
sfColor color, sfTexture *kirby)
{
    sfRectangleShape *button = sfRectangleShape_create();
    float pos1_x = posx;
    float pos1_y = posy;
    sfRectangleShape_setPosition(button, (sfVector2f) {pos1_x, pos1_y});
    sfRectangleShape_setSize(button, (sfVector2f) {225, 125});
    sfRectangleShape_setOutlineColor(button, color);
    sfRectangleShape_setOutlineThickness(button, 10);
    sfRectangleShape_setTexture(button, kirby, sfTrue);
    return button;
}

sfRectangleShape *create_my_button(float pos1_x, float pos1_y, sfColor color)
{
    sfRectangleShape *button = sfRectangleShape_create();
    sfRectangleShape_setPosition(button, (sfVector2f) {pos1_x, pos1_y});
    sfRectangleShape_setSize(button, (sfVector2f) {225, 125});
    sfRectangleShape_setOutlineColor(button, color);
    sfRectangleShape_setOutlineThickness(button, 10);
    return button;
}
