/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that refresh the settings window
*/

#include "my_rpg.h"

void refresh_settings(game_t *game, scene_t *scene)
{
    int i = 0;
    game->render_info->time_refresh = sfClock_getElapsedTime(game->render_info->clock_refresh);
    game->render_info->seconds = game->render_info->time_refresh.microseconds / 1000000.0;

    if (game->current == SETTINGS && game->render_info->seconds > 0.2)
        refresh_button(scene, game);
    while (scene->buttons[i] != NULL) {
        if (scene->buttons[i]->is_clicked == 1){
            sfClock_restart(game->render_info->clock_refresh);
            scene->buttons[i]->is_clicked = 0;
        }
        i++;
    }
}