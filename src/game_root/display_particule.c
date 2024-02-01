/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** display_particule
*/

#include <stdlib.h>
#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "my_struct.h"

pixel_t *create_framebuffer(unsigned int x, unsigned int y)
{
    pixel_t *pix;
    sfUint8 *buf_pixel;
    int i = 0;
    int tmp = 0;

    pix = malloc(sizeof(pixel_t));
    pix->width = x;
    pix->height = y;
    tmp = x * y * 4;
    buf_pixel = malloc(sizeof(sfUint8) * tmp);
    pix->pixels = buf_pixel;
    for (; i < tmp; i += 4) {
        pix->pixels[i] = 0;
        pix->pixels[i + 1] = 0;
        pix->pixels[i + 2] = 0;
        pix->pixels[i + 3] = 255;
    }
    return pix;
}

static void draw_pixel(pixel_t *pix)
{
    sfColor color;
    unsigned int x = rand() % 1920;
    unsigned int y = rand() % 1080;

    color.r = (sfUint8) {255};
    color.b = (sfUint8) {255};
    color.g = (sfUint8) {255};
    if (x < 1920) {
        if (y < 1080) {
            x *= 4;
            y *= 4;
            pix->pixels[pix->width * y + x] = color.r;
            pix->pixels[pix->width * y + x + 1] = color.g;
            pix->pixels[pix->width * y + x + 2] = color.b;
        }
    }
    return;
}

void display_particules(rpg_t *t)
{
    if (t->binare_particule == 1) {
        sfTexture_updateFromPixels(t->pix->texture, \
        t->pix->pixels, 1920, 1080, 0, 0);
        sfSprite_setTexture(t->pix->sprite, t->pix->texture, sfTrue);
        sfRenderWindow_drawSprite(t->window, t->pix->sprite, NULL);
        draw_pixel(t->pix);
        if (sfKeyboard_isKeyPressed(sfKeyP) == sfTrue) {
            t->binare_particule = 0;
        }
    }
    return;
}
