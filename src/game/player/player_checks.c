/*
** EPITECH PROJECT, 2021
** player checks
** File description:
** checks player stuff
*/

#include "my_rpg.h"

int player_in_stairs(game_t *game)
{
    int w = 80;
    int h = 80;

    if (game->player->pos.x - w < 300 + w &&
        game->player->pos.x + w > 300 - w &&
        game->player->pos.y - h < 850 + h &&
        game->player->pos.y + h > 850 - h)
        return (1);
    return (0);
}

void enemy_killall(tower_t *tower)
{
    if (tower->enemies == NULL)
        return;
    for (int i = 0; tower->enemies[i] != NULL; i++)
        tower->enemies[i]->health = 0;
}

void is_player_dead(game_t *game)
{
    if (game->player->health <= 0) {
        enemy_killall(game->tower);
        game->player->health = 200;
        change_tower_floor(game, 0);
    }
}