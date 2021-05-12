/*
** EPITECH PROJECT, 2021
** free char array
** File description:
** frees an array of characters
*/

#include "my_rpg.h"

void free_char_array(char **array)
{
    for (int i = 0; array[i] != NULL; i++)
        free(array[i]);
    free(array);
}