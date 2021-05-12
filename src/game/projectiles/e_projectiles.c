/*
** EPITECH PROJECT, 2021
** e projectiles
** File description:
** projetiles for enemies
*/

#include "my_rpg.h"

int count_e_active(enemy_t *enemy)
{
    int i = 0;
    int active = 0;

    while (enemy->projectiles[i] != NULL) {
        if (enemy->projectiles[i]->travelling == 0)
            active++;
        i++;
    }
    return (active);
}

void angle_e_projectile(enemy_t *enemy, float angle, int i)
{
    float x = 0;
    float y = 0;

    y = (sin(angle) * enemy->projectiles[i]->dir.x) + (cos(angle) * enemy->projectiles[i]->dir.y);
    x = (cos(angle) * enemy->projectiles[i]->dir.x) - (sin(angle) * enemy->projectiles[i]->dir.y);
    enemy->projectiles[i]->dir = (sfVector2f){x, y};
}

void e_projectile_dir(game_t *game, enemy_t *enemy, int i)
{
    float x = 0;
    float y = 0;
    float mod = 0;

    x = game->player->pos.x - enemy->pos.x;
    y = game->player->pos.y - enemy->pos.y;
    mod = sqrt(pow(x, 2) + pow(y , 2));
    x = x / mod;
    y = y / mod;
    enemy->projectiles[i]->dir = (sfVector2f){x, y};
}

e_projectile_t **projectile_array(int n, int type)
{
    int i = 0;

    e_projectile_t **projectiles = malloc(sizeof(e_projectile_t *) * (n + 1));
    if (!projectiles)
        return (NULL);
    for (i = 0; i < n; i++) {
        projectiles[i] = malloc(sizeof(e_projectile_t));
        if (!projectiles[i])
            return (NULL);
        projectiles[i]->dir = (sfVector2f){0, 0};
        projectiles[i]->pos = (sfVector2f){-10, -10};
        projectiles[i]->type = type;
        projectiles[i]->travelling = 0;
        projectile_types(projectiles[i], type);
        projectiles[i]->clock = sfClock_create();
        projectiles[i]->time = sfClock_getElapsedTime(projectiles[i]->clock);
        projectiles[i]->seconds = 0;
    }
    projectiles[i] = NULL;
    return (projectiles);
}