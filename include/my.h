/*
** EPITECH PROJECT, 2021
** mypoke
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

void my_putchar(char c);
void my_putstr(char const *str);
int my_put_nbr(int nb);
int my_strlen(char const *str);
void my_put_nbr_base(int nb, int base);
int my_put_nbr_positive(int nb);
void my_printf(char *s, ...);
char **my_str_to_word_array(char *str, char *delim);
char *my_strndup(char const *src, int n);
char *my_strncpy(char *dest, char const *src, int nb);

#endif/* !MY_H_ */
