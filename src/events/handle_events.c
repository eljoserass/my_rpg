/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main function to handle the events
*/

#include "my_rpg.h"

void get_game_player_event(game_t *game)
{
    if (game->render_info->event.type == sfEvtKeyPressed) {
        if (game->render_info->event.key.code == sfKeyW ||
        game->render_info->event.key.code == sfKeyUp)
            game->player->move = 2;
        if (game->render_info->event.key.code == sfKeyA ||
        game->render_info->event.key.code == sfKeyLeft)
            game->player->move = 6;
        if (game->render_info->event.key.code == sfKeyS ||
        game->render_info->event.key.code == sfKeyDown)
            game->player->move = 0;
        if (game->render_info->event.key.code == sfKeyD ||
        game->render_info->event.key.code == sfKeyRight)
            game->player->move = 4;
        if (game->render_info->event.key.code == sfKeyE)
            check_tower_floor(game, game->tower->enemies);
    }
    if (game->render_info->event.type == sfEvtKeyReleased) {
        game->player->move = -1;
    }
}

void get_attack_event(game_t *game)
{
    if (game->render_info->event.type == sfEvtMouseButtonPressed) {
        shoot_projectile_2(game);
    }
}

void shoot_projectile_type(game_t *game)
{
    if (game->shoot_type == 0)
        shoot_projectile(game);
    else
        shoot_projectile_2(game);
}

void change_shoot_type(game_t *game)
{
    if (game->shoot_type == 0)
        game->shoot_type = 1;
    else
        game->shoot_type = 0;
}

void get_event(game_t *game)
{
    game->render_info->pos_mouse = sfMouse_getPositionRenderWindow(game->render_info->window);

    while (sfRenderWindow_pollEvent(game->render_info->window, &game->render_info->event)) {
        if (game->render_info->event.type == sfEvtClosed)
            sfRenderWindow_close(game->render_info->window);
        if (game->render_info->event.type == sfEvtMouseButtonPressed) {
            game->render_info->pos_click.x = game->render_info->pos_mouse.x;
            game->render_info->pos_click.y = game->render_info->pos_mouse.y;
            shoot_projectile_type(game);
        }
        if (game->render_info->event.type == sfEvtMouseButtonReleased) {
            game->render_info->pos_click.x = 0;
            game->render_info->pos_click.y = 0;
        }
        if (game->render_info->event.type == sfEvtKeyPressed) {
            if ((game->render_info-> event.key.code == sfKeyP ||
            game->render_info->event.key.code == sfKeyEscape)
            && game->current == 1) {
                game->before_pause = game->current;
                game->current = 2;
            } else if ((game->render_info-> event.key.code == sfKeyP ||
            game->render_info->event.key.code == sfKeyEscape)
            && game->current == 2)
                game->current = game->before_pause;
            if (game->render_info->event.key.code == sfKeyT)
                change_shoot_type(game);
        }
        get_game_player_event(game);
    }
}