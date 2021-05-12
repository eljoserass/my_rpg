/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that draw the game
*/

#include "my_rpg.h"

void draw_pause_text(game_t *game)
{
    sfText_setFont(game->msg_menu->text, game->msg_menu->font);
    sfText_setCharacterSize(game->msg_menu->text, 15);
    sfText_setPosition(game->msg_menu->text, (sfVector2f){180, 130});
    sfText_setColor(game->msg_menu->text, sfBlack);
    sfText_setString(game->msg_menu->text, game->msg_menu->msg);
    sfRenderWindow_drawText(game->render_info->window, game->msg_menu->text, NULL);
}

void draw_exit_in_pause(game_t *game)
{
    sfText_setFont(game->msg_exit->text, game->fps->font);
    sfText_setCharacterSize(game->msg_exit->text, 30);
    sfText_setPosition(game->msg_exit->text, (sfVector2f){1045, 720});
    sfText_setString(game->msg_exit->text, game->msg_exit->msg);
    sfText_setColor(game->msg_exit->text, sfBlack);
    sfRenderWindow_drawText(game->render_info->window, game->msg_exit->text , NULL);
}

void draw_settings_in_pause(game_t *game)
{
    sfText_setFont(game->msg_settings->text, game->fps->font);
    sfText_setCharacterSize(game->msg_settings->text, 30);
    sfText_setPosition(game->msg_settings->text, (sfVector2f){1045, 320});
    sfText_setString(game->msg_settings->text, game->msg_settings->msg);
    sfText_setColor(game->msg_settings->text, sfBlack);
    sfRenderWindow_drawText(game->render_info->window, game->msg_settings->text , NULL);
}

void draw_return_in_pause(game_t *game)
{
    sfText_setFont(game->msg_return->text, game->fps->font);
    sfText_setCharacterSize(game->msg_return->text, 30);
    sfText_setPosition(game->msg_return->text, (sfVector2f){1045, 520});
    sfText_setString(game->msg_return->text, game->msg_return->msg);
    sfText_setColor(game->msg_return->text, sfBlack);
    sfRenderWindow_drawText(game->render_info->window, game->msg_return->text , NULL);
}

void draw_pause(game_t *game, scene_t *scenes)
{
    draw_scene_sprites(game, scenes);
    draw_scenes_button_sprites(game, scenes);
    draw_settings_in_pause(game);
    draw_return_in_pause(game);
    draw_exit_in_pause(game);
    draw_pause_text(game);
}