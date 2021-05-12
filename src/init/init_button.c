/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
**  initial the buttons
*/
 
#include "my_rpg.h"

button *init_button(sfVector2f pos, sfVector2f size)
{
    button *buttons = malloc(sizeof(button));

    buttons->pos = pos;
    buttons->size = size;
    buttons->is_clicked = 0;
    buttons->unpressed = NULL;
    buttons->hover = NULL;
    return (buttons);
}
