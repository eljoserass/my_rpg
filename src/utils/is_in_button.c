/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** funciton that check i f the buton is clicked
*/

#include "my_rpg.h"

int is_in_button(button *button, sfVector2i pos)
{
    int on_x = 0;
    int on_y = 0;

    if ((pos.x >= button->pos.x) &&
    (pos.x <= button->pos.x + button->size.x))
        on_x = 1;
    if ((pos.y >= button->pos.y) &&
    (pos.y <= button->pos.y + button->size.y))
        on_y = 1;
    if ((on_x == 1) && (on_y == 1))
        return (1);
    return (0);
}