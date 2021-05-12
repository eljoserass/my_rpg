/*
** EPITECH PROJECT, 2020
** my_pustr.c
** File description:
** print string
*/

#include "my_rpg.h"

void my_putstr(char const *str)
{
    write(1, str, my_strlen(str));
}