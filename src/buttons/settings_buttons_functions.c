/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** settings buttons functions
*/

#include "my_rpg.h"

void back_function (game_t *game)
{
    game->current = game->before_settings;
}

void fps_func(game_t *game)
{
    game->fps->fps_msg = malloc(sizeof(char) * 7 + 1);

    if (game->render_info->fps == 30) {
        game->render_info->fps = 60;
        game->fps->fps_msg = my_strcpy(game->fps->fps_msg, "60 FPS");
        sfRenderWindow_setFramerateLimit(game->render_info->window, 60);
    } else if (game->render_info->fps == 60) {
        game->render_info->fps = 144;
        game->fps->fps_msg = my_strcpy(game->fps->fps_msg, "144 FPS");
        sfRenderWindow_setFramerateLimit(game->render_info->window, 144);
    } else {
        game->render_info->fps = 30;
        game->fps->fps_msg = my_strcpy(game->fps->fps_msg, "30 FPS");
        sfRenderWindow_setFramerateLimit(game->render_info->window, 30);
    }
}

void vol_func(game_t *game)
{
    char *temp = malloc(sizeof(char) * 3 + 1);

    game->vol->vol_msg = malloc(sizeof(char) * 5 + 1);
    if (game->audio_storms->volume == 100) {
        game->audio_storms->volume = 00;
        game->vol->vol_msg = "VOL 00";
    }
    else {
        game->audio_storms->volume += 25;
        temp = my_itoa(game->audio_storms->volume, 3, 10);
        game->vol->vol_msg = my_strcat("VOL ", temp);
    }
    if (game->audio_storms->ost)
    sfSound_setVolume(game->audio_storms->ost, game->audio_storms->volume);
    free(temp);
}