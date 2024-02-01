/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** initstruct_b
*/

#ifndef INITSTRUCT_B_H_
    #define INITSTRUCT_B_H_

    #include <stdlib.h>
    #include <time.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_struct.h"

sfSprite *create_sprite(sfVector2f pos, sfVector2f size, char *path);
char *random_path(void);
sfSprite *sprite_menu(void);

#endif/* !INITSTRUCT_B_H_ */
