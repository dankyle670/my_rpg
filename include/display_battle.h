/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** display_battle
*/

#ifndef DISPLAY_BATTLE_H_
    #define DISPLAY_BATTLE_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <stdlib.h>
    #include "my_struct.h"

sfSprite *create_sprite(sfVector2f pos, sfVector2f size, char *path);
battle_t *init_battle(void);
int cursor(rpg_t *t);
int get_rand(int max);

#endif/* !DISPLAY_BATTLE_H_ */
