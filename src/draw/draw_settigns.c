/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that draw the settings window
*/

#include "my_rpg.h"

void draw_fps_text(game_t *game)
{
    sfText_setFont(game->fps->text, game->fps->font);
    sfText_setCharacterSize(game->fps->text, 45);
    sfText_setPosition(game->fps->text, (sfVector2f){625, 605});
    sfText_setString(game->fps->text, game->fps->fps_msg);
    sfRenderWindow_drawText(game->render_info->window, game->fps->text, NULL);
}

void draw_vol_text(game_t *game)
{
    sfText_setFont(game->vol->text, game->vol->font);
    sfText_setCharacterSize(game->vol->text, 45);
    sfText_setPosition(game->vol->text, (sfVector2f){615, 343});
    sfText_setString(game->vol->text, game->vol->vol_msg);
    sfRenderWindow_drawText(game->render_info->window, game->vol->text, NULL);
}

void draw_settings(game_t *game, scene_t *scenes)
{
    draw_scene_sprites(game, scenes);
    draw_scenes_button_sprites(game, scenes);
    sfRenderWindow_drawSprite(game->render_info->window,
                                game->image[0]->sprite, NULL);
    draw_fps_text(game);
    draw_vol_text(game);
}