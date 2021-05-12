/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that draw the game
*/

#include "my_rpg.h"

void draw_game_projectiles(game_t *game)
{
    for (int i = 0; game->player->projectiles[i] != NULL; i++) {
        if (game->player->projectiles[i]->travelling != 0) {
            sfSprite_setPosition(game->player->proj_sprite->sprite,
                                game->player->projectiles[i]->pos);
            sfRenderWindow_drawSprite(game->render_info->window,
                game->player->proj_sprite->sprite, NULL);
        }
    }
}

void draw_text(game_t *game, char *str, sfVector2f pos, int size)
{
    sfText_setFont(game->stats->text, game->stats->font);
    sfText_setCharacterSize(game->stats->text, size);
    sfText_setPosition(game->stats->text, pos);
    sfText_setString(game->stats->text, str);
    sfRenderWindow_drawText(game->render_info->window, game->stats->text, NULL);
}

void draw_stats(game_t *game)
{
    draw_text(game, game->stats->lvl, (sfVector2f){1560, 50}, 50);
    draw_text(game, game->stats->health_bar, (sfVector2f){1555, 140}, 45);
    draw_text(game, game->stats->attack_txt, (sfVector2f){1522, 240}, 35);
    draw_text(game, game->stats->speed_txt, (sfVector2f){1522, 340}, 35);
    draw_text(game, game->stats->bullets, (sfVector2f){1700, 340}, 35);
    draw_text(game, game->stats->defend_txt, (sfVector2f){1700, 240}, 35);
}

void draw_game(game_t *game, scene_t *scenes)
{
    sfRenderWindow_drawSprite(game->render_info->window,
                            game->tower->background->sprite, NULL);
    draw_scene_sprites(game, scenes);
    draw_game_projectiles(game);
    draw_tower(game);
    draw_inventory(game);
    draw_stats(game);
}