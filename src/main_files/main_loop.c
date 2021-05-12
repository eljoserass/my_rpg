/*
** EPITECH PROJECT, 2021
** main loop
** File description:
** main loop of the prog
*/

#include "my_rpg.h"

void do_main_loop(game_t *game, scene_t **scenes)
{
    while (sfRenderWindow_isOpen(game->render_info->window)) {
        sfRenderWindow_clear(game->render_info->window, sfBlack);
        get_event(game);
        refresh_window(game, scenes);
        draw_window(game, scenes);
        sfRenderWindow_display(game->render_info->window);
    }
}