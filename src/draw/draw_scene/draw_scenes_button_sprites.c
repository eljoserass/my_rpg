/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function taht draws the buttons
*/

#include "my_rpg.h"

void draw_scenes_button_sprites(game_t *game, scene_t *scene)
{
    int i = 0;

    while (scene->buttons[i] != NULL) {
        if ((is_in_button(scene->buttons[i], game->render_info->pos_mouse) == 1) &&
        scene->buttons[i]->is_clicked == 0)
            sfRenderWindow_drawSprite(game->render_info->window,
                                    scene->buttons[i]->hover->sprite, NULL);
        else
            sfRenderWindow_drawSprite(game->render_info->window,
                                    scene->buttons[i]->unpressed->sprite, NULL);
        i++;
    }
}