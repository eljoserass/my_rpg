/*
** EPITECH PROJECT, 2021
** animate tower
** File description:
** animates enemies and projectiles
*/

#include "my_rpg.h"

void animate_tower(game_t *game) {
    animate_enemies(game, game->tower->clocks);
    animate_e_projectiles(game, game->tower->clocks);
}