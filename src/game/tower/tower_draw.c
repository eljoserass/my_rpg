/*
** EPITECH PROJECT, 2021
** tower draw
** File description:
** draws tower
*/

#include "my_rpg.h"

void draw_tower_sprites(game_t *game)
{
    int type = 0;

    for (int i = 0; game->tower->enemies[i] != NULL; i++) {
        if (game->tower->enemies[i]->health > 0) {
            type = game->tower->enemies[i]->type - 1;
            sfSprite_setPosition(game->tower->e_sprites[type]->sprite,
                                game->tower->enemies[i]->pos);
            sfRenderWindow_drawSprite(game->render_info->window,
                                    game->tower->e_sprites[type]->sprite, NULL);
        }
        draw_e_projectiles(game, i);
    }
}

void draw_tower(game_t *game)
{
    if (game->tower->enemies != NULL)
        draw_tower_sprites(game);
}