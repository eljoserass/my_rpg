/*
** EPITECH PROJECT, 2021
** macro 2 path
** File description:
** transforms a makro into a path
*/

#include "my_rpg.h"

char *macro_to_path(char *macro, int n)
{
    char *path = my_itoa(n, 3, 10);
    path = my_strcat(macro, path);
    path = my_strcat(path, ".conf");
    return (path);
}