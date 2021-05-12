/*
** EPITECH PROJECT, 2021
** projectiles
** File description:
** projectiles related functions
*/

#include "my_rpg.h"

void get_direction(game_t *game, int i)
{
    float x = 0;
    float y = 0;
    float mod = 0;

    x = game->render_info->pos_click.x - game->player->pos.x;
    y = game->render_info->pos_click.y - game->player->pos.y;
    mod = sqrt(pow(x, 2) + pow(y , 2));
    x = x / mod;
    y = y / mod;
    game->player->projectiles[i]->direction = (sfVector2f){x, y};
}

void move_projectile(projectile_t *projectile, sfIntRect rect)
{
    if (((projectile->pos.x + rect.width) <= 1484 - 10) &&
    ((projectile->pos.y + rect.height) <= 1080 - 130) &&
    (projectile->pos.x >= 10) && (projectile->pos.y >= 130)) {
        projectile->pos.x += projectile->direction.x * projectile->speed;
        projectile->pos.y += projectile->direction.y * projectile->speed;
    } else
        projectile->travelling = 0;
}

void angle_projectile(game_t *game, float angle, int i)
{
    float x = 0;
    float y = 0;

    y = (sin(angle) * game->player->projectiles[i]->direction.x) + (cos(angle) * game->player->projectiles[i]->direction.y);
    x = (cos(angle) * game->player->projectiles[i]->direction.x) - (sin(angle) * game->player->projectiles[i]->direction.y);
    game->player->projectiles[i]->direction = (sfVector2f){x, y};
}

void shoot_projectile_2(game_t *game)
{
    int i = 0;
    int j = 0;

    if (count_active(game) < 3)
        return;
    while (j < 3) {
        while (game->player->projectiles[i] != NULL && game->player->projectiles[i]->travelling == 1)
            i++;
        if (game->player->projectiles[i] != NULL && game->player->projectiles[i]->travelling == 0) {
            game->player->projectiles[i]->travelling = 1;
            game->player->projectiles[i]->pos.y = game->player->pos.y;
            game->player->projectiles[i]->pos.x = game->player->pos.x;
            get_direction(game, i);
        }
        if (j == 0)
            angle_projectile(game, 0.10, i);
        if (j == 1)
            angle_projectile(game, -0.10, i);
        j++;
        i++;
    }
}

void shoot_projectile(game_t *game)
{
    int i = 0;
    while (game->player->projectiles[i] != NULL && game->player->projectiles[i]->travelling == 1)
        i++;
    if (game->player->projectiles[i] != NULL && game->player->projectiles[i]->travelling == 0) {
        game->player->projectiles[i]->travelling = 1;
        game->player->projectiles[i]->pos = game->player->pos;
        get_direction(game, i);
    }
}
