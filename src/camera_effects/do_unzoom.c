/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** funciton that unzoom a sprite
*/

#include "my_rpg.h"

void do_unzoom(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2f scale = sfSprite_getScale(sprite);
    int i = 0;

    while (i <=  50) {
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfSprite_setScale(sprite, scale);
        sfRenderWindow_display(window);
        scale.x -= 0.2;
        scale.y -= 0.2;
        i++;
    }
    scale.x = 1;
    scale.y = 1;
    sfSprite_setScale(sprite, scale);
}