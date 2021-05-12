/*
** EPITECH PROJECT, 2020
** size_of_bytes
** File description:
** get size of a file in bytes
*/

#include "my_rpg.h"

int get_size(char *file)
{
    struct stat buf;

    if (stat(file, &buf) == -1) {
        my_putstr("f(stat) failed\n");
        return (-1);
    }
    return (buf.st_size);
}