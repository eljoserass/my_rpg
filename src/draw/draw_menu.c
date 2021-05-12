/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that draw the game
*/

#include "my_rpg.h"

void draw_menu(game_t *game, scene_t *scenes)
{
    draw_scene_sprites(game, scenes);
    draw_scenes_button_sprites(game, scenes);
    sfRenderWindow_drawSprite(game->render_info->window,
                                game->image[0]->sprite, NULL);
}