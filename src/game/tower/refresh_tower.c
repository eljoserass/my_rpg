/*
** EPITECH PROJECT, 2021
** refresh tower
** File description:
** refreshes tower
*/

#include "my_rpg.h"

void refresh_tower(game_t *game)
{
    if (game->tower->floor == 25 && game->tower->enemies[0]->health > 0)
        refresh_boss(game);
    else
        refresh_enemies(game);
    refresh_e_projectiles(game);
}