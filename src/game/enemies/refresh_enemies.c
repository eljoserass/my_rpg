/*
** EPITECH PROJECT, 2021
** refresh enemies
** File description:
** refreshes enemies
*/

#include "my_rpg.h"

void refresh_enemy(game_t *game, enemy_t *enemy, sfIntRect rect)
{
    move_enemy(game, enemy, rect);
    shooting_patterns(game, enemy);
}

void refresh_enemies(game_t *game)
{
    int type = 0;

    for (int i = 0; game->tower->enemies[i] != NULL; i++) {
            if (game->tower->enemies[i]->health > 0) {
            type = game->tower->enemies[i]->type - 1;
            refresh_enemy(game, game->tower->enemies[i], game->tower->e_sprites[type]->rect);
        }
    }
}