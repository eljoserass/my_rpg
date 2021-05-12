/*
** EPITECH PROJECT, 2021
** enemies
** File description:
** enemies functions
*/

#include "my_rpg.h"

sfVector2f enemy_chase_dir(game_t *game, sfVector2f e_pos)
{
    float x = 0;
    float y = 0;
    float mod = 0;
    sfVector2f direction;

    x = game->player->pos.x - e_pos.x;
    y = game->player->pos.y - e_pos.y;
    mod = sqrt(pow(x, 2) + pow(y , 2));
    x = x / mod;
    y = y / mod;
    direction = (sfVector2f){x, y};
    return (direction);
}

sfVector2f enemy_roam_dir(sfVector2f e_pos)
{
    float x = 0;
    float y = 0;
    float mod = 0;
    sfVector2f direction;

    x = (rand() % 200) - 100;
    y = (rand() % 200) - 100;
    mod = sqrt(pow(x, 2) + pow(y , 2));
    x = x / mod;
    y = y / mod;
    direction = (sfVector2f){x, y};

    return (direction);
}

void enemy_type(enemy_t *enemy, int type)
{
    if (type == 1)
        enemy_goblin(enemy);
    if (type == 2)
        enemy_orc(enemy);
    if (type == 3)
        enemy_ogre(enemy);
}

enemy_t *generate_enemy(game_t *game ,int type, sfVector2f pos)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->type = type;
    enemy->pos = pos;
    enemy_type(enemy, type);
    enemy->clock = sfClock_create();
    enemy->time = sfClock_getElapsedTime(enemy->clock);
    enemy->seconds = 0;
}