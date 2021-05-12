/*
** EPITECH PROJECT, 2021
** refresh e projectiles
** File description:
** refreshing
*/

#include "my_rpg.h"

void check_e_collisions(game_t *game, e_projectile_t *projectile)
{
    int w = game->tower->p_sprites[projectile->type - 1]->rect.width / 4;
    int h = game->tower->p_sprites[projectile->type - 1]->rect.height / 4;
    int p_w = 48 / 4;
    int p_h = 96 / 4;
    int dmg = projectile->dmg;

    if (projectile->pos.x - w < game->player->pos.x + p_w &&
        projectile->pos.x + w > game->player->pos.x - p_w &&
        projectile->pos.y - h < game->player->pos.y + p_h &&
        projectile->pos.y + h > game->player->pos.y - p_h) {
        game->player->health -=  dmg * dmg / (dmg + game->player->defense);
        projectile->travelling = 0;
    }
}

void refresh_e_projectiles(game_t *game)
{
    int type = 0;

    for (int i = 0; game->tower->enemies[i] != NULL; i++) {
        for (int j = 0; game->tower->enemies[i]->projectiles[j] != NULL; j++) {
            if (game->tower->enemies[i]->projectiles[j]->travelling == 1) {
                type = game->tower->enemies[i]->projectiles[j]->type - 1;
                move_e_projectile(game->tower->enemies[i]->projectiles[j], game->tower->p_sprites[type]->rect);
                check_e_collisions(game, game->tower->enemies[i]->projectiles[j]);
            }
        }
    }
}