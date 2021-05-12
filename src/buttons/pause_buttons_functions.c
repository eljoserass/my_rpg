/*
** EPITECH PROJECT, 2021
** menu functions
** File description:
** menu functions
*/

#include "my_rpg.h"

void return_first_scene(game_t *game)
{
    game->current = 0;
}

void  return_to_scene(game_t *game)
{
    game->current = game->before_pause;
}