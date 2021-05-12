/*
** EPITECH PROJECT, 2021
** e projectiles
** File description:
** projectiles for enemies
*/

#include "my_rpg.h"

void move_e_projectile(e_projectile_t *projectile, sfIntRect rect)
{
    if (((projectile->pos.x + rect.width) <= 1484 - 30) &&
    ((projectile->pos.y + rect.height) <= 1080 - 130) &&
    (projectile->pos.x >= 30) && (projectile->pos.y >= 130)) {
        projectile->pos.x += projectile->dir.x * projectile->spd;
        projectile->pos.y += projectile->dir.y * projectile->spd;
    } else
        projectile->travelling = 0;
}