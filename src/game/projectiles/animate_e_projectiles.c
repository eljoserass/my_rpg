/*
** EPITECH PROJECT, 2021
** animate e projectiles
** File description:
** animates enemy projectiles
*/

#include "my_rpg.h"

/*void animate_e_projectiles(game_t *game, int n)
{
    int sprite_pos = 0;

    for (int i = 0; game->tower->enemies[n]->projectiles[i] != NULL; i++) {
        sprite_pos = game->tower->enemies[n]->projectiles[i]->type - 1;
        game->tower->enemies[n]->projectiles[i]->time = sfClock_getElapsedTime(game->tower->enemies[n]->projectiles[i]->clock);
        game->tower->enemies[n]->projectiles[i]->seconds = game->tower->enemies[n]->projectiles[i]->time.microseconds / 1000000.0;
        if (game->tower->enemies[n]->projectiles[i]->seconds > 0.075) {
            animate_sprite(&game->tower->p_sprites[sprite_pos]->rect,
                        game->tower->p_sprites[sprite_pos]->offset,
                        game->tower->p_sprites[sprite_pos]->max_value);
            sfSprite_setTextureRect(game->tower->p_sprites[sprite_pos]->sprite,
                                    game->tower->p_sprites[sprite_pos]->rect);
            sfClock_restart(game->tower->enemies[n]->projectiles[i]->clock);
        }
    }
}*/

void animate_e_projectiles(game_t *game, tower_clocks_t *clocks)
{
    clocks->p_time = sfClock_getElapsedTime(clocks->p_clock);
    clocks->p_seconds = clocks->p_time.microseconds / 1000000.0;

    for (int i = 0; game->tower->p_sprites[i] != NULL; i++) {
        if (clocks->p_seconds > 0.07) {
            animate_sprite(&game->tower->p_sprites[i]->rect,
                        game->tower->p_sprites[i]->offset,
                        game->tower->p_sprites[i]->max_value);
            sfSprite_setTextureRect(game->tower->p_sprites[i]->sprite,
                                    game->tower->p_sprites[i]->rect);
            sfClock_restart(clocks->p_clock);
        }
    }
}