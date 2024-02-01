/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** my_menu
*/

#ifndef MY_MENU_H_
    #define MY_MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_struct.h"

int cursor(rpg_t *t);
void check_button(menu_t *b, rpg_t *t);
rpg_t *init_rpg(void);
menu_t *init_menu(void);
void display_game(rpg_t *t, menu_t *b);
int destroy_all(rpg_t *t, menu_t *b);

#endif/* !MY_MENU_H_ */
