/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that can draw all the images of a scene
*/

#include "my_rpg.h"

void draw_scene_sprites(game_t *game, scene_t *scene)
{
    int i = 0;

    while (scene->sprites[i] != NULL) {
        sfRenderWindow_drawSprite(game->render_info->window,
                                scene->sprites[i]->sprite, NULL);
        i++;
    }
}