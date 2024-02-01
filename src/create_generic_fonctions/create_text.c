/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** create_text
*/

#include <SFML/Graphics.h>

sfText *create_text(char *text_input, sfVector2f my_pos, char *path, int size)
{
    sfFont* font = sfFont_createFromFile(path);
    sfText* text = sfText_create();

    sfText_setString(text, text_input);
    sfText_setFont(text, font);
    sfText_setPosition(text, my_pos);
    sfText_setCharacterSize(text, size);
    return text;
}
