/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** initstruct_t
*/

#include "initstruct_t.h"

static rpg_t *init_sprites2(rpg_t *t)
{
    t->pokemon->sprt = create_sprite((sfVector2f)\
    {900 + get_rand(700), 700 + get_rand(500)},\
    (sfVector2f) {5, 5}, "textures/pokemons/poke.png");
    t->pokemon->sprt2 = create_sprite((sfVector2f) {-40, -770},\
    (sfVector2f) {5, 5}, "textures/pokemons/poke.png");
    t->pokemon->sprt3 = create_sprite((sfVector2f) {700, -3700},\
    (sfVector2f) {5, 5}, "textures/pokemons/poke.png");
    t->pause->sprite = create_sprite((sfVector2f) {650, 200},\
    (sfVector2f) {0.5, 0.5}, "textures/menu_pause/menu_pause.png");
    t->pause->bg_sprite = create_sprite((sfVector2f) {0, 0},
    (sfVector2f) {1, 1}, "textures/menu_pause/bg_menu.jpg");
    t->pix = create_framebuffer(1920, 1080);
    t->pix->sprite = sfSprite_create();
    t->pix->texture = sfTexture_create(1920, 1080);
    return t;
}

static rpg_t *init_sprites(rpg_t *t)
{
    t->rect = (sfIntRect) {get_rand(4) * 243 + 1, 21, 242, 114};
    t->main_bg = create_sprite((sfVector2f) {-7000, -4800},\
    (sfVector2f) {5.5, 5.5}, "textures/maps/map_totale.png");
    t->main_bgsurcouche = create_sprite((sfVector2f) {-7000, -4800},\
    (sfVector2f) {5.5, 5.5}, "textures/maps/map_surcouche.png");
    t->cursor = create_sprite((sfVector2f) {0, 0},\
    (sfVector2f) {0.1, 0.1}, "textures/objct_png/cursor2.png");
    t->music.main_music = sfMusic_createFromFile("musics/menu_pokpok.ogg");
    sfMusic_setVolume(t->music.main_music, t->opt->volume);
    t->perso = sprite_perso();
    t->box = create_sprite((sfVector2f) {500, 680},\
    (sfVector2f) {0.6, 0.6}, "textures/dialogues/dialogues.png");
    t->profesor->sprt = create_sprite((sfVector2f) {700, 600},\
    (sfVector2f) {5, 5}, "textures/persos/pnj2.png");
    init_sprites2(t);
    return t;
}

static void init_var2(rpg_t *t)
{
    t->tmp_leftbattle = 0;
    t->tmp_topbattle = 0;
    t->binare_loadingmenu = 1;
    t->profesor->tmp_left = 0;
    t->pokemon->tmp_left = get_rand(28) * 32;
    t->pokemon->tmp_top = get_rand(17) * 32;
    t->pokemon->tmp_left2 = 1 * 32;
    t->pokemon->tmp_top3 = 9 * 32;
    t->pokemon->tmp_left3 = 27 * 32;
    t->pokemon->tmp_top3 = 10 * 32;
    t->binare_particule = 0;
    return;
}

static void init_var(rpg_t *t)
{
    t->perso_stats->real_pos = (sfVector2f) {1250, 900};
    t->perso_stats->money = 0;
    t->perso_stats->counter = 0;
    t->perso_stats->counter2 = 0;
    t->perso_stats->direction_memory = 0;
    t->colision->down_mem = 1;
    t->colision->top_mem = 1;
    t->colision->right_mem = 1;
    t->colision->left_mem = 1;
    t->binare_lose = 0;
    t->pokemon->poke_memory = 0;
    t->binare_menupause = 0;
    t->pokemon->text = create_text("Fight ! Press (E)",\
    (sfVector2f) {650, 900}, "textures/police/Pokemon Solid.ttf", 70);
    t->profesor->text = create_text("Press (E) to start the quest!",\
    (sfVector2f) {620, 810}, "textures/police/Pokemon Solid.ttf", 40);
    init_var2(t);
    return;
}

rpg_t *init_rpg(void)
{
    rpg_t *t = malloc(sizeof(rpg_t));
    t->perso_stats = malloc(sizeof(perso_t));
    t->opt = malloc(sizeof(option_t));
    t->profesor = malloc(sizeof(bot_t));
    t->pokemon = malloc(sizeof(bot_t));
    t->colision = malloc(sizeof(colision_t));
    t->pause = malloc(sizeof(menu_pause_t));
    t->clock = sfClock_create();
    options(t);
    init_sprites(t);
    t->window = create_window(t->opt->resolution1, t->opt->resolution2);
    t->perso_stats->rect_left = 0;
    t->perso_stats->rect = (sfIntRect) {0, 3, 17.6, 27};
    init_var(t);
    return t;
}
