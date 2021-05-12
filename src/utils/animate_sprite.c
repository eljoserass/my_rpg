/*
** EPITECH PROJECT, 2021
** move rect
** File description:
** moves rects
*/

#include "my_rpg.h"

void animate_sprite(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}