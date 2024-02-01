/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** my_struct
*/

#ifndef MY_STRUCT_H_
    #define MY_STRUCT_H_

typedef struct bot_s {
    sfSprite *sprt;
    sfIntRect rect;
    sfVector2f pos;
    sfText *text;
    sfSprite *sprt2;
    sfSprite *sprt3;
    sfIntRect rect2;
    sfIntRect rect3;
    sfVector2f pos2;
    sfVector2f pos3;
    int tmp_left2;
    int tmp_top2;
    int tmp_left3;
    int tmp_top3;
    int tmp_left;
    int tmp_top;
    int poke_memory;
}bot_t;

typedef struct pixel_s {
    int height;
    int width;
    sfTexture *texture;
    sfSprite *sprite;
    sfUint8 *pixels;
}pixel_t;

typedef struct battle_s {
    sfClock *clock;
    sfSprite *battle_sprt;
    sfSprite *bg_sprt;
    sfSprite *bg_sprtblack;
    sfSprite *pokemon_logo;
    sfSprite *pokemon;
    sfSprite *perso;
    sfSprite *barre1;
    sfSprite *barre2;
    sfSprite *count_down;
    sfSprite *type;
    sfIntRect rect;
    int seconds;
    int tmp_left;
    int tmp_top;
    int counter;
}battle_t;

typedef struct perso_s {
    sfVector2f pos;
    sfVector2f real_pos;
    sfIntRect rect;
    int rect_left;
    int counter;
    int counter2;
    int direction_memory;
    int score;
    int money;
}perso_t;

typedef struct music_s {
    sfMusic *main_music;
}music_t;

typedef struct gif_s {
    sfSprite *sprt;
    sfIntRect rect;
    int leftrect;
    int toprect;
}gif_t;

typedef struct menu_pause_s {
    sfSprite *sprite;
    sfSprite *bg_sprite;
    sfRectangleShape *pause_butt1;
    sfRectangleShape *pause_butt2;
    sfRectangleShape *pause_butt3;
    sfText *play;
    sfText *resume;
    sfText *quit;
}menu_pause_t;

typedef struct menu_s {
    sfSprite *dark;
    sfClock *clock;
    sfClock *clock2;
    sfRectangleShape *button1;
    sfRectangleShape *button2;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2i mousepos;
    sfFont *font;
    sfText *text;
    sfText *text2;
    gif_t *menu;
    gif_t *loading_bg;
    gif_t *pokeball;
    gif_t *intro;
    int display_startmenu;
    int game_changer;
    int seconds;
    int seconds2;
}menu_t;

typedef struct option_s {
    int resolution1;
    int resolution2;
    int volume;
    int difficulty;
    int godmod;
}option_t;

typedef struct colision_s {
    int right_mem;
    int left_mem;
    int top_mem;
    int down_mem;
}colision_t;

typedef struct rpg_s {
    sfRenderWindow *window;
    sfSprite *main_bg;
    sfSprite *main_bgsurcouche;
    sfSprite *cursor;
    sfSprite *perso;
    sfVector2i mousepos;
    sfVector2f pos_cursor;
    sfIntRect rect;
    sfClock *clock;
    bot_t *pokemon;
    option_t *opt;
    menu_t *button;
    perso_t *perso_stats;
    music_t music;
    bot_t *profesor;
    sfSprite *box;
    colision_t *colision;
    menu_pause_t *pause;
    sfVector2i menu_mouse;
    sfEvent menu_evt;
    pixel_t *pix;
    int binare_menupause;
    int binare_lose;
    int binare_battle;
    int binare_loadingmenu;
    int binare_particule;
    int tmp_leftbattle;
    int tmp_topbattle;
    float seconds;
}rpg_t;

#endif/* !MY_STRUCT_H_ */
