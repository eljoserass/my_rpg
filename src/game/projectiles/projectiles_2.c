/*
** EPITECH PROJECT, 2021
** projectiles 2
** File description:
** continuation of projectiles
*/

#include "my_rpg.h"

int count_active(game_t *game)
{
    int i = 0;
    int active = 0;

    while (game->player->projectiles[i] != NULL) {
        if (game->player->projectiles[i]->travelling == 0)
            active++;
        i++;
    }
    return (active);
}

void check_proj_collision(game_t *game, enemy_t **enemies, projectile_t *projectile)
{
    int w = game->player->proj_sprite->rect.width / 2;
    int h = game->player->proj_sprite->rect.height / 2;
    int e_w = 0;
    int e_h = 0;

    if (game->tower->enemies == NULL)
        return;
    for (int i = 0; enemies[i] != NULL; i++) {
        if (enemies[i]->health > 0) {
            e_w = (game->tower->e_sprites[enemies[i]->type - 1]->rect.width / 6);
            e_h = (game->tower->e_sprites[enemies[i]->type - 1]->rect.height / 6);
            if (projectile->pos.x - w <= enemies[i]->pos.x + e_w &&
                projectile->pos.x + w >= enemies[i]->pos.x - e_w &&
                projectile->pos.y - h <= enemies[i]->pos.y + e_h &&
                projectile->pos.y + h >= enemies[i]->pos.y - e_h) {
                enemies[i]->health -= projectile->damage + game->player->attack;
                projectile->travelling = 0;
            }
        }
    }
}