/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_

    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include "my_struct.h"

int is_clicked(rpg_t *d, int lowx, int highx, int lowy, int highy);

#endif/* !EVENT_H_ */
