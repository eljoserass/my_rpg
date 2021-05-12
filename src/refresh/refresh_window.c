/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that calls the refresh for the scenes
*/

#include "my_rpg.h"

void refresh_window(game_t *game, scene_t **scenes)
{
    void (*function[4])(game_t *, scene_t *) = {refresh_menu, refresh_game, refresh_pause, refresh_settings};
    
    function[game->current](game, scenes[game->current]);
}