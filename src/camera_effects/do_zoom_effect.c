/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that do a zoom an unzoom effect
*/

#include "my_rpg.h"

void do_zoom_effect(sfRenderWindow *window, sfSprite *sprite)
{
    do_zoom(window, sprite);
    do_unzoom(window, sprite);
}
