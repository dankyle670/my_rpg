/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** init_battle
*/

#include <stdlib.h>
#include "my_rpg.h"

static battle_t *init_battle2(battle_t *battle)
{
    battle->pokemon = create_sprite((sfVector2f) {1170, 400},\
    (sfVector2f) {7, 7}, "textures/pokemons/poke.png");
    battle->perso = create_sprite((sfVector2f) {370, 513},\
    (sfVector2f) {7, 7}, "textures/persos/perso_battle.png");
    battle->count_down = create_sprite((sfVector2f) {480, 100},\
    (sfVector2f) {2, 2}, "textures/battle/count_down.png");
    battle->type = create_sprite((sfVector2f) {480, 100},\
    (sfVector2f) {5, 5}, "textures/pokemons/type_pokemon.png");
    battle->tmp_left = 0;
    battle->tmp_top = 0;
    battle->counter = 0;
    return battle;
}

battle_t *init_battle(void)
{
    battle_t *battle = malloc(sizeof(battle_t));
    battle->clock = sfClock_create();
    battle->battle_sprt = create_sprite((sfVector2f) {230, 170},\
    (sfVector2f) {6, 6.5}, "textures/battle/arenas.png");
    battle->bg_sprt = create_sprite((sfVector2f) {-60, 0},\
    (sfVector2f) {2.2, 2}, "textures/battle/bg.jpg");
    battle->bg_sprtblack = create_sprite((sfVector2f) {0, -400},\
    (sfVector2f) {7, 4}, "textures/battle/bg.jpg");
    battle->pokemon_logo = create_sprite((sfVector2f) {750, 10},\
    (sfVector2f) {0.2, 0.2}, "textures/objct_png/pokemon_logo.png");
    init_battle2(battle);
    return battle;
}
