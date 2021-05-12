/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that add a new drop to the inventory
*/

#include "my_rpg.h"

int add_item(game_t *game, int id)
{
    int pos = 0;

    while (game->player->inventory[pos]->is_empty == 0)
        pos++;
    if (pos >= INV_SIZE -1)
        return (-1);
    game->player->inventory[pos]->attack = game->drops[id]->attack;
    game->player->inventory[pos]->speed = game->drops[id]->speed;
    game->player->inventory[pos]->defense = game->drops[id]->defense;
    game->player->inventory[pos]->health = game->drops[id]->health;
    game->player->inventory[pos]->type = id;
    game->player->inventory[pos]->is_empty = 0;
    add_drop_stat(game, pos);
    return (0);
}