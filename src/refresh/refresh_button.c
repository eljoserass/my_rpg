/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** refresh buttonss
*/

#include "my_rpg.h"

void refresh_button(scene_t *scene, game_t *game)
{
    int i = 0;
    sfVector2f temp;

    while (scene->buttons[i] != NULL) {
        if ((is_in_button(scene->buttons[i], game->render_info->pos_click) == 1)) {
            temp.x = 1.05;
            temp.y = 1.05;
            sfSprite_setScale(scene->buttons[i]->hover->sprite, temp);
            scene->buttons[i]->fn(game);
            scene->buttons[i]->is_clicked = 1;
        }
        else {
            temp.x = 1;
            temp.y = 1;
            sfSprite_setScale(scene->buttons[i]->hover->sprite, temp);
            scene->buttons[i]->is_clicked = 0;
        }
        i++;
    }
}