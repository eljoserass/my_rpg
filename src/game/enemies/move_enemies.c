/*
** EPITECH PROJECT, 2021
** move enemies
** File description:
** moves enemies
*/

#include "my_rpg.h"

void chase(game_t *game, enemy_t *enemy, sfIntRect rect)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->seconds = enemy->time.microseconds / 1000000.0;
    if (enemy->seconds > 0.03) {
        enemy->dir = enemy_chase_dir(game, enemy->pos);
        enemy->pos.x += enemy->dir.x * enemy->spd;
        enemy->pos.y += enemy->dir.y * enemy->spd;
        sfClock_restart(enemy->clock);
    }
}

void roam(game_t *game, enemy_t *enemy, sfIntRect rect)
{
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->seconds = enemy->time.microseconds / 1000000.0;
    enemy->dir = enemy_roam_dir(enemy->pos);
    if (enemy->seconds > 0.20) {
        if (((enemy->pos.x + rect.width) <= 1484 - 30) &&
        ((enemy->pos.y + rect.height) <= 1080 - 130) &&
        (enemy->pos.x >= 30) && (enemy->pos.y >= 130) ){
            enemy->pos.x += enemy->dir.x * enemy->spd;
            enemy->pos.y += enemy->dir.y * enemy->spd;
        } else {
            enemy->dir = enemy_chase_dir(game, enemy->pos);
            enemy->pos.x += enemy->dir.x * enemy->spd;
            enemy->pos.y += enemy->dir.y * enemy->spd;
        }
        sfClock_restart(enemy->clock);
    }
}

void move_enemy(game_t *game, enemy_t *enemy, sfIntRect rect)
{
    if (enemy->type == 1 || enemy->type == 3)
        roam(game, enemy, rect);
    if (enemy->type == 2)
        chase(game, enemy, rect);
}