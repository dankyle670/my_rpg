/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** game_root
*/

#ifndef GAME_ROOT_H_
    #define GAME_ROOT_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_struct.h"

void manage_input(rpg_t *t);
void event_append(rpg_t *t);
void map_colisions(rpg_t *t);
void display_perso(rpg_t *t);
void display_pokemon(rpg_t *t);
void start_quests(rpg_t *t);
void display_battle(rpg_t *t);
void pause_menu(rpg_t *t);
void display_particules(rpg_t *t);
void loading_menu(rpg_t *t, menu_t *b);

#endif/* !GAME_ROOT_H_ */
