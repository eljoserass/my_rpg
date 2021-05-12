/*
** EPITECH PROJECT, 2021
** do my rpg
** File description:
** initializes game
*/

#include "my_rpg.h"

void free_resources(game_t *game)
{
    sfClock_destroy(game->render_info->clock_refresh);
    sfRenderWindow_destroy(game->render_info->window);
    free(game->render_info);
    free(game);
}

int do_my_rpg(void)
{
    game_t *game = NULL;
    scene_t **scenes = NULL;
    if (init_resources(&game, &scenes) == 84)
        return (ERROR);
    do_main_loop(game, scenes);
    free_resources(game);
    return (SUCCESS);
}