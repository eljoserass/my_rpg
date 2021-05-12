/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that add the stats of a drop
*/

#include "my_rpg.h"

void add_defense(game_t *game, int pos)
{
    game->player->defense += game->player->inventory[pos]->defense;
    game->player->inventory[pos]->defense = 0;
}

void add_health(game_t *game, int pos)
{
    game->player->health += game->player->inventory[pos]->health;
    game->player->inventory[pos]->health = 0;
}

void add_speed(game_t *game, int pos)
{
    game->player->speed += game->player->inventory[pos]->speed;
    game->player->inventory[pos]->speed = 0;
}

void add_attack(game_t *game, int pos)
{
    game->player->attack += game->player->inventory[pos]->attack;
    game->player->inventory[pos]->attack = 0;
}

void add_drop_stat(game_t *game, int pos)
{
    add_defense(game, pos);
    add_health(game, pos);
    add_speed(game, pos);
    add_attack(game, pos);
}