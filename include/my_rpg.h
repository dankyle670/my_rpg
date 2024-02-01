/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** my_deffender
*/

#ifndef MY_DEFENDER_H_
    #define MY_DEFENDER_H_

    #include <SFML/Graphics.h>
    #include <SFML/System/Export.h>
    #include <SFML/Graphics/Rect.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/System/Types.h>
    #include <SFML/Audio.h>
    #include "my.h"
    #include "my_struct.h"
    #define CREATE (sfRenderWindow_create)
    #define ITOC(x) (x + '0')

// menu.c
void display_menu(rpg_t *t, menu_t *b);
int menu(void);
void main_menu(menu_t *b);

//decollision.c
void de_make_colision(rpg_t *t);

//collision/*
void map_colisions(rpg_t *t);
void map_colisions6(rpg_t *t);
int check_objcolision(rpg_t *t, bot_t *bot, int val);
int check_poke_colision(rpg_t *t, bot_t *bot, int val);
void make_colision(rpg_t *t, sfVector2f pos1, sfVector2f pos2);

//menu_pause.c
void pause_menu(rpg_t *t);

//loading_menu.c
char *random_path(void);
void loading_menu(rpg_t *t, menu_t *b);

//display_battle.c
void display_battle(rpg_t *t);

//event.c
void event_append(rpg_t *t);

//manage_input.c
void manage_input(rpg_t *t);
void manage_input2(rpg_t *t);

//particules.c
void display_particules(rpg_t *t);
pixel_t *create_framebuffer(unsigned int x, unsigned int y);

//options.c
void options(rpg_t *t);

// game_root.c
void game_root(rpg_t *t);
void display_game(rpg_t *t, menu_t *b);

//start_quests.c
void start_quests(rpg_t *t);

//diplay_perso.c
void display_perso(rpg_t *t);

//pause_menu.C
void pause_menu(rpg_t *t);
int is_clicked(rpg_t *t, int lowx, int highx, int lowy, int highy);

//pokemons.c
void display_pokemon(rpg_t *t);
int get_rand(int max);

// initstruct.c
int init_clock(rpg_t *t);
rpg_t *init_rpg(void);
menu_t *init_menu(void);
battle_t *init_battle(void);
menu_pause_t *init_menu_button(void);

// sounds.c
sfMusic *start_music(rpg_t *t);
void start_music_all(rpg_t *t);

// sprite_menu.c
sfRenderWindow *create_window(int res1, int res2);
sfSprite *sprite_menu(void);
sfText *text_menu(void);
sfText *text_menu2(void);
sfText *text_menu3(void);

//event.c
void event_append(rpg_t *t);

// cursor.c
int cursor(rpg_t *t);

// create_sprite/*.c
sfSprite *sprite_cursor(void);
sfSprite *sprite_menu(void);
sfSprite *sprite_perso(void);
sfSound *create_sound(char const *path);
sfSprite *create_sprite(sfVector2f pos, sfVector2f size, char *path);
sfText *create_text(char *text_input, sfVector2f my_pos, char *path, int size);
sfRectangleShape *create_my_button(float pos1_x, float pos1_y, sfColor color);

//check_button.c
void check_button(menu_t *b, rpg_t *t);

//destroy_all.c
int destroy_all(rpg_t *t, menu_t *b);

#endif/* !MY_DEFENDER_H_ */
