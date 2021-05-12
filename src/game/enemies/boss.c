/*
** EPITECH PROJECT, 2021
** boss function
** File description:
** bosssssssss
*/

#include "my_rpg.h"

enemy_t *init_boss(void)
{
    enemy_t *boss = malloc(sizeof(enemy_t));

    boss->health = 5555;
    boss->pos = (sfVector2f){1400, 500};
    boss->type = 4;
    boss->spd = 20;
    boss->dir = (sfVector2f){0, 0} ;
    boss->clock = sfClock_create();
    boss->time = sfClock_getElapsedTime(boss->clock);
    boss->seconds = 0;
    boss->projectiles = projectile_array(5, 4);
    return (boss);
}

void spawn_boss(game_t *game)
{
    game->tower->enemies = malloc(sizeof(enemy_t *) * 2);
    game->tower->enemies[0] = init_boss();
    game->tower->enemies[1] = NULL;
}

void refresh_boss(game_t *game)
{
    game->tower->enemies[0]->time = sfClock_getElapsedTime(game->tower->enemies[0]->clock);
    game->tower->enemies[0]->seconds = game->tower->enemies[0]->time.microseconds / 1000000.0;
    if (game->tower->enemies[0]->health < 1000)
        chase_phase(game);
    else
        roam_phase(game);
}