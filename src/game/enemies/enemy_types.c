/*
** EPITECH PROJECT, 2021
** enemy types
** File description:
** different enemies
*/

#include "my_rpg.h"

void enemy_goblin(enemy_t *enemy)
{
    enemy->health = 100;
    enemy->dir = (sfVector2f){0, 0};
    enemy->projectiles = projectile_array(2, 1);
    enemy->spd = 10;
}

void enemy_orc(enemy_t *enemy)
{
    enemy->health = 200;
    enemy->dir = (sfVector2f){0, 0};
    enemy->projectiles = projectile_array(3, 2);
    enemy->spd = 7;
}

void enemy_ogre(enemy_t *enemy)
{
    enemy->health = 1200;
    enemy->dir = (sfVector2f){0, 0};
    enemy->projectiles = projectile_array(5, 3);
    enemy->spd = 13;
}

void enemy_health_buff(tower_t *tower)
{
    for (int i = 0; tower->enemies[i] != NULL; i++)
        tower->enemies[i]->health += tower->enemies[i]->health;
}