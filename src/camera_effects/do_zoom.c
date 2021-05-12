/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that zoom in the sprite
*/

#include "my_rpg.h"

void do_zoom(sfRenderWindow *window, sfSprite *sprite)
{
    int  i = 0;
    sfVector2f scale = sfSprite_getScale(sprite);

    while (i <= 50) {
        scale.x += 0.2;
        scale.y += 0.2;
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window , sprite, NULL);
        sfSprite_setScale(sprite, scale);
        sfRenderWindow_display(window);
        i += 1;
    }
}