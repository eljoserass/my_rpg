/*
** EPITECH PROJECT, 2021
** menu functions
** File description:
** menu functions
*/

#include "my_rpg.h"

void close_window(game_t *game)
{
    sfSound_setLoop(game->audio_storms->ost, sfFalse);
    sfSound_destroy(game->audio_storms->ost);
    sfSoundBuffer_destroy(game->audio->ost_buffer);
    sfRenderWindow_close(game->render_info->window);
}

void change_to_game(game_t *game)
{
    do_zoom_effect(game->render_info->window, game->tower->background->sprite);
    game->current = GAME;
    game->before_pause = GAME;
}

void display_help(game_t *game)
{
    if (game->image[0]->pos.x != 192)
        game->image[0]->pos.x = 192;
    else
        game->image[0]->pos.x = 4000;
    sfSprite_setPosition(game->image[0]->sprite, game->image[0]->pos);
    game->render_info->pos_mouse.x = 0;
    game->render_info->pos_mouse.y = 0;
}

void change_to_settings(game_t *game)
{
    game->before_settings = game->current;
    game->current = SETTINGS;
}

void change_to_pause(game_t *game)
{
    game->current = PAUSE;
}