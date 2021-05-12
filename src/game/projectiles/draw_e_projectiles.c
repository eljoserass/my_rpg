/*
** EPITECH PROJECT, 2021
** draw e projectiles
** File description:
** draws enemy projectils
*/

#include "my_rpg.h"

void draw_e_projectiles(game_t *game, int n)
{
    int type = 0;

    for (int i = 0; game->tower->enemies[n]->projectiles[i] != NULL; i++) {
        type = game->tower->enemies[n]->projectiles[i]->type - 1;
        if (game->tower->enemies[n]->projectiles[i]->travelling != 0) {
            sfSprite_setPosition(game->tower->p_sprites[type]->sprite,
                                game->tower->enemies[n]->projectiles[i]->pos);
            sfRenderWindow_drawSprite(game->render_info->window,
                                    game->tower->p_sprites[type]->sprite, NULL);
        }
    }
}