/*
** EPITECH PROJECT, 2021
** boss phases
** File description:
** different boss phases
*/

#include "my_rpg.h"

void boss_shoot(game_t *game, enemy_t *enemy)
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
            angle_e_projectile(enemy, 0.10 * j, i);
        if (j == 3 || j == 4)
            angle_e_projectile(enemy, -0.10 * (j - 2), i);
        j++;
        i++;
    }
}

void roam_phase(game_t *game)
{
    roam(game, game->tower->enemies[0], game->tower->e_sprites[3]->rect);
    boss_shoot(game, game->tower->enemies[0]);
}

void chase_phase(game_t *game)
{
    chase(game, game->tower->enemies[0], game->tower->e_sprites[3]->rect);
    boss_shoot(game, game->tower->enemies[0]);
}