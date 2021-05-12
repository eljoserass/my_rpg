/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** file with the main draw calls
*/

#include "my_rpg.h"

void draw_window(game_t *game, scene_t **scenes)
{
    void (*function[4])(game_t *, scene_t *) = {draw_menu, draw_game, draw_pause, draw_settings};
    
    function[game->current](game, scenes[game->current]);
}