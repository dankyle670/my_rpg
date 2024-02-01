/*
** EPITECH PROJECT, 2022
** mypoke
** File description:
** options
*/

// #include "my.h"
// #include "my_struct.h"
// #include "my_rpg.h"

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "my.h"
#include "my_struct.h"

static int fs_open_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return 84;
    return fd;
}

static char *char_file_memory(char *fp)
{
    int fd = fs_open_file(fp);
    struct stat info;
    char *buffer = NULL;

    if (stat(fp, &info) == -1 || !S_ISREG(info.st_mode))
        return NULL;
    buffer = malloc(sizeof(char) * (info.st_size + 1));
    if (read(fd, buffer, info.st_size) == 0)
        return NULL;
    buffer[info.st_size] = '\0';
    close(fd);
    return buffer;
}

char **option_intoarray(void)
{
    char *tmp_map = char_file_memory("options/option.conf");
    char **map_array;

    map_array = my_str_to_word_array(tmp_map, " ");
    free(tmp_map);
    return map_array;
}

int my_getnbr(char const *str)
{
    int nbr = 0;
    int is_neg = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-') {
            is_neg = is_neg * -1;
        } else if ((str[i] >= '0' && str[i] <= '9')
        && (str[i + 1] < '0' || str[i + 1] > '9')) {
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
            nbr = nbr * is_neg;
            return (nbr);
        } else if (str[i] >= '0' && str[i] <= '9') {
            nbr = nbr * 10;
            nbr = nbr + str[i] - '0';
        }
    }
    return (nbr * is_neg);
}

void options(rpg_t *t)
{
    char **array = option_intoarray();
    t->opt->resolution1 = my_getnbr(array[2]);
    t->opt->resolution2 = my_getnbr(array[4]);
    t->opt->volume = my_getnbr(array[7]);
    t->opt->difficulty = my_getnbr(array[9]);
    t->opt->godmod = my_getnbr(array[11]);
}