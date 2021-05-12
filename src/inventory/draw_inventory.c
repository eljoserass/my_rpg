/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** funciton that dras the available items
*/

#include "my_rpg.h"

void draw_inventory(game_t *game)
{
    int i = 0;

    while (game->player->inventory[i]) {
        if (game->player->inventory[i]->is_empty == 0) {
            sfSprite_setPosition(game->drops[game->player->inventory[i]->type]->sprite->sprite ,game->player->inventory[i]->pos);
            sfRenderWindow_drawSprite(game->render_info->window, game->drops[game->player->inventory[i]->type]->sprite->sprite, NULL);
        }
        i++;
    }
}