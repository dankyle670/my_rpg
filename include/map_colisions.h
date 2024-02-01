/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** map_colisions
*/

#ifndef MAP_COLISIONS_H_
    #define MAP_COLISIONS_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_struct.h"

void make_colision(rpg_t *t, sfVector2f pos1, sfVector2f pos2);
void map_colisions6(rpg_t *t);

#endif/* !MAP_COLISIONS_H_ */
