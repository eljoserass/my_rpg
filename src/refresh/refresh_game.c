/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** funciton that refresh the game
*/

#include "my_rpg.h"

int move_player(game_t *game, scene_t *scene)
{
    if (game->player->move < 0)
        return (0);
    if (game->player->move > 3)
        game->player->pos.x += ((5 - game->player->move) * game->player->speed);
        if (game->player->pos.x <= 50 || game->player->pos.x >= 1484 - 50)
            game->player->pos.x -= ((5 - game->player->move) * game->player->speed);
    if (game->player->move < 3)
        game->player->pos.y += ((1 - game->player->move) * game->player->speed);
        if (game->player->pos.y < 135 || game->player->pos.y > 1080 - 185)
            game->player->pos.y -= ((1 - game->player->move) * game->player->speed);
    sfSprite_setPosition(scene->sprites[0]->sprite,  game->player->pos);
}

void move_view(game_t *game, scene_t *scene)
{
    sfVector2f vsize = sfView_getSize(game->render_info->view);
    sfFloatRect msize = sfSprite_getGlobalBounds(game->tower->background->sprite);
    sfVector2f pos = sfSprite_getPosition(scene->sprites[0]->sprite);
    sfVector2f view = sfView_getCenter(game->render_info->view);
    sfFloatRect player = sfSprite_getGlobalBounds(scene->sprites[0]->sprite);
    sfVector2f center = {pos.x + player.width / 2, pos.y + player.height / 2};
    sfVector2f max = {msize.width - vsize.x / 2 - player.width,
    msize.height - vsize.y / 2 - player.height};

    if (pos.x >= vsize.x / 2 && pos.x <= max.x)
        sfView_setCenter(game->render_info->view, (sfVector2f){center.x, view.y});
    view = sfView_getCenter(game->render_info->view);
    if (pos.y >= vsize.y / 2 && pos.y <= max.y)
        sfView_setCenter(game->render_info->view, (sfVector2f){view.x, center.y});
    sfRenderWindow_setView(game->render_info->window, game->render_info->view);
}

void refresh_player(game_t *game, scene_t *scene)
{
    move_player(game, scene);
    is_player_dead(game);
    if (game->tower->floor == 0)
        sfSprite_setPosition(scene->sprites[1]->sprite, (sfVector2f){0, 0});
    else
        sfSprite_setPosition(scene->sprites[1]->sprite, (sfVector2f){-1500, 0});
    if (game->tower->floor > 25)
        sfSprite_setPosition(scene->sprites[2]->sprite, (sfVector2f){0, 0});
    else
        sfSprite_setPosition(scene->sprites[2]->sprite, (sfVector2f){-1500, 0});
}

void refresh_projectiles(game_t *game)
{
    for (int i = 0; game->player->projectiles[i] != NULL; i++) {
        if (game->player->projectiles[i]->travelling == 1) {
            move_projectile(game->player->projectiles[i], game->player->proj_sprite->rect);
            check_proj_collision(game, game->tower->enemies, game->player->projectiles[i]);
        }
    }
}

int refresh_stats(game_t *game)
{
    char *temp = malloc(sizeof(char) * 5);

    if (!temp)
        return (ERROR);
    temp = my_itoa(game->tower->floor, 3, 10);
    game->stats->lvl = my_strcat("LEVEL: ", temp);
    temp = my_itoa(game->player->health, 3, 10);
    game->stats->health_bar = my_strcat("HP: ", temp);
    temp = my_itoa(game->player->speed, 3, 10);
    game->stats->speed_txt = my_strcat("SPD: ", temp);
    temp = my_itoa(game->player->defense, 3, 10);
    game->stats->defend_txt = my_strcat("DEF: ", temp);
    temp = my_itoa(game->player->attack, 3, 10);
    game->stats->attack_txt = my_strcat("DMG: ", temp);
    temp = my_itoa(count_active(game), 3, 10);
    game->stats->bullets = my_strcat("LEFT: ", temp);
    return (SUCCESS);
}

void refresh_game(game_t *game, scene_t *scene)
{
    game->render_info->time_refresh = sfClock_getElapsedTime(game->render_info->clock_refresh);
    game->render_info->seconds = game->render_info->time_refresh.microseconds / 1000000.0;
    refresh_player(game, scene);
    refresh_projectiles(game);
    refresh_stats(game);
    if (game->tower->enemies != NULL) {
        refresh_tower(game);
        animate_tower(game);
    }
    if (game->render_info->seconds > 0.1) {
        animate_sprite(&game->player->proj_sprite->rect, game->player->proj_sprite->offset, game->player->proj_sprite->max_value);
        sfSprite_setTextureRect(game->player->proj_sprite->sprite, game->player->proj_sprite->rect);
        animate_sprite(&scene->sprites[0]->rect, scene->sprites[0]->offset, scene->sprites[0]->max_value);
        sfSprite_setTextureRect(scene->sprites[0]->sprite, scene->sprites[0]->rect);
        sfClock_restart(game->render_info->clock_refresh);
    }
}