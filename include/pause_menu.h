/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** pause_menu
*/

#ifndef PAUSE_MENU_H_
    #define PAUSE_MENU_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_struct.h"
    #include "my.h"

int cursor(rpg_t *t);
menu_pause_t *init_menu_button(void);

#endif/* !PAUSE_MENU_H_ */
