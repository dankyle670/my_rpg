/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** initstruct_t
*/

#ifndef INITSTRUCT_T_H_
    #define INITSTRUCT_T_H_

    #include <stdlib.h>
    #include <time.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_struct.h"

sfSprite *create_sprite(sfVector2f pos, sfVector2f size, char *path);
pixel_t *create_framebuffer(unsigned int x, unsigned int y);
sfSprite *sprite_perso(void);
sfText *create_text(char *text_input, sfVector2f my_pos, char *path, int size);
void options(rpg_t *t);
int get_rand(int max);
sfRenderWindow *create_window(int res1, int res2);

#endif/* !INITSTRUCT_T_H_ */
