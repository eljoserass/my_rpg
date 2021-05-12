/*
** EPITECH PROJECT, 2021
** shooting patterns
** File description:
** shooting patterns for different enemies
*/

#include "my_rpg.h"

void shoot_dagger(game_t *game, enemy_t *enemy)
{
    int i = 0;
    int j = 0;

    if (count_e_active(enemy) < 2)
        return;
    while (j < 2) {
        while (enemy->projectiles[i] != NULL && enemy->projectiles[i]->travelling == 1)
            i++;
        if (enemy->projectiles[i] != NULL && enemy->projectiles[i]->travelling == 0) {
            enemy->projectiles[i]->travelling = 1;
            enemy->projectiles[i]->pos.x = enemy->pos.x;
            enemy->projectiles[i]->pos.y = enemy->pos.y;
            e_projectile_dir(game, enemy, i);
        }
        if (j == 0)
            angle_e_projectile(enemy, 0.3, i);
        if (j == 1)
            angle_e_projectile(enemy, -0.3, i);
        j++;
        i++;
    }
}

void shoot_mace(game_t *game, enemy_t *enemy)
{
    int i = 0;
    int j = 0;

    if (count_e_active(enemy) < 3)
        return;
    while (j < 3) {
        while (enemy->projectiles[i] != NULL && enemy->projectiles[i]->travelling == 1)
            i++;
        if (enemy->projectiles[i] != NULL && enemy->projectiles[i]->travelling == 0) {
            enemy->projectiles[i]->travelling = 1;
            enemy->projectiles[i]->pos.x = enemy->pos.x;
            enemy->projectiles[i]->pos.y = enemy->pos.y;
            e_projectile_dir(game, enemy, i);
        }
        if (j == 0)
            angle_e_projectile(enemy, 0.15, i);
        if (j == 1)
            angle_e_projectile(enemy, -0.15, i);
        j++;
        i++;
    }
}

void shoot_hammer(game_t *game, enemy_t *enemy)
{
    int i = 0;
    int j = 0;

    if (count_e_active(enemy) < 5)
        return;
    while (j < 5) {
        while (enemy->projectiles[i] != NULL && enemy->projectiles[i]->travelling == 1)
            i++;
        if (enemy->projectiles[i] != NULL && enemy->projectiles[i]->travelling == 0) {
            enemy->projectiles[i]->travelling = 1;
            enemy->projectiles[i]->pos.x = enemy->pos.x;
            enemy->projectiles[i]->pos.y = enemy->pos.y;
            e_projectile_dir(game, enemy, i);
        }
        if (j == 1 || j == 2)
            angle_e_projectile(enemy, 0.15 * j, i);
        if (j == 3 || j == 4)
            angle_e_projectile(enemy, -0.15 * (j - 2), i);
        j++;
        i++;
    }
}

void shooting_patterns(game_t *game, enemy_t *enemy)
{
    if (enemy->type == 1)
        shoot_dagger(game, enemy);
    if (enemy->type == 2)
        shoot_mace(game, enemy);
    if (enemy->type == 3)
        shoot_hammer(game, enemy);
}