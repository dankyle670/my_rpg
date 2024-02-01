/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** create_sound
*/

#include <SFML/Audio.h>

sfSound *create_sound(char const *path)
{
    sfSound *sound = sfSound_create();
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(path);

    sfSound_setVolume(sound, 200);
    sfSound_setBuffer(sound, buffer);
    return sound;
}
