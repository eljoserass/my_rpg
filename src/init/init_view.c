/*
** EPITECH PROJECT, 2021
** init view
** File description:
** inits view
*/

#include "my_rpg.h"

void init_view(game_t *game, scene_t **scenes)
{
    sfFloatRect player = sfSprite_getGlobalBounds(scenes[GAME]->sprites[0]->sprite);
    sfVector2f pos = sfSprite_getPosition(scenes[GAME]->sprites[0]->sprite);
    sfVector2f center = {pos.x + player.width/ 2, pos.y + player.height / 2};

    game->render_info->view = sfView_create();
    sfView_setSize(game->render_info->view, (sfVector2f){1920 / 1.2, 1080 / 1.2});
    sfView_setCenter(game->render_info->view, center);
}