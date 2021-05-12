/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that refresh the pause
*/

#include "my_rpg.h"

void refresh_pause(game_t *game, scene_t *scene)
{
    game->render_info->time_refresh = sfClock_getElapsedTime(game->render_info->clock_refresh);
    game->render_info->seconds = game->render_info->time_refresh.microseconds / 1000000.0;

    if (game->current == 2 )
        refresh_button(scene, game);
    if (game->render_info->seconds > 0.05) {
        sfClock_restart(game->render_info->clock_refresh);
    }
}