/*
** EPITECH PROJECT, 2021
** animate enemies
** File description:
** animates them enemies
*/

#include "my_rpg.h"

void animate_enemies(game_t *game, tower_clocks_t *clocks)
{
    clocks->e_time = sfClock_getElapsedTime(clocks->e_clock);
    clocks->e_seconds = clocks->e_time.microseconds / 1000000.0;

    for (int i = 0; game->tower->e_sprites[i] != NULL; i++) {
        if (clocks->e_seconds > 0.2) {
            animate_sprite(&game->tower->e_sprites[i]->rect,
                        game->tower->e_sprites[i]->offset,
                        game->tower->e_sprites[i]->max_value);
            sfSprite_setTextureRect(game->tower->e_sprites[i]->sprite,
                                    game->tower->e_sprites[i]->rect);
            sfClock_restart(clocks->e_clock);
        }
    }
}