/*
** EPITECH PROJECT, 2020
** my_strcpy
** File description:
** Copy string
*/

#include "my_rpg.h"

char *my_strcpy(char *dest, char const *str)
{
    int i = 0;

    while (str[i]) {
        dest[i] = str[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
