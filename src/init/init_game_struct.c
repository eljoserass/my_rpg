/*
** EPITECH PROJECT, 2021
** my_spg
** File description:
** function that initializes the main strict
*/

#include <stdlib.h>
#include "my_rpg.h"

int init_inventory(game_t *game)
{
    int i = 0;
    float x = 0;
    float y = 0;

    game->player->inventory = malloc(sizeof(object_t *) * (INV_SIZE + 1));
    if (!game->player->inventory)
        return (ERROR);
    while (i < INV_SIZE) {
        game->player->inventory[i] = malloc(sizeof(object_t));
        if (!game->player->inventory[i])
            return (ERROR);
        game->player->inventory[i]->is_empty = 1;
        game->player->inventory[i]->attack = 0;
        game->player->inventory[i]->defense = 0;
        game->player->inventory[i]->health = 0;
        game->player->inventory[i]->speed = 0;
        game->player->inventory[i]->type = -1;
        game->player->inventory[i]->pos.x = 1553 + (x * 85);
        game->player->inventory[i]->pos.y = 475 + (y * 85);
        x += 1;
        i++;
        if (x >= 4) {
            x = 0;
            y += 1;
        }
    }
    game->player->inventory[i] = NULL;
    return (SUCCESS);
}

int init_drop_dictionary(game_t *game)
{
    game->drops = malloc(sizeof(drop_dictionary_t *) * DROPS);

    game->drops[0] = malloc(sizeof(drop_dictionary_t));
    if (!game->drops[0])
        return (ERROR);
    game->drops[0]->attack = 5;
    game->drops[0]->defense = 0;
    game->drops[0]->health = 1;
    game->drops[0]->speed = 0;
    game->drops[0]->sprite = init_image(RED_BOTTLE, (sfIntRect){0, 0, 10, 11}, (sfVector2f){0, 0}, 10);
    sfSprite_setScale(game->drops[0]->sprite->sprite, (sfVector2f){5, 5});
    game->drops[1] = malloc(sizeof(drop_dictionary_t));
    if (!game->drops[1])
        return (ERROR);
    game->drops[1]->attack = 1;
    game->drops[1]->defense = 3;
    game->drops[1]->health = 1;
    game->drops[1]->speed = 0;
    game->drops[1]->sprite = init_image(BLUE_BOTTLE, (sfIntRect){0, 0, 10, 11}, (sfVector2f){0, 0}, 10);
    sfSprite_setScale(game->drops[1]->sprite->sprite, (sfVector2f){5, 5});
    game->drops[2] = malloc(sizeof(drop_dictionary_t));
    if (!game->drops[2])
        return (ERROR);
    game->drops[2]->attack = 2;
    game->drops[2]->defense = 2;
    game->drops[2]->health = 0;
    game->drops[2]->speed = 1;
    game->drops[2]->sprite = init_image(GREEN_BOTTLE, (sfIntRect){0, 0, 10, 11}, (sfVector2f){0, 0}, 10);
    sfSprite_setScale(game->drops[2]->sprite->sprite, (sfVector2f){5, 5});
    game->drops[3] = malloc(sizeof(drop_dictionary_t));
    if (!game->drops[3])
        return (ERROR);
    game->drops[3]->attack = 1;
    game->drops[3]->defense = 1;
    game->drops[3]->health = 1;
    game->drops[3]->speed = 3;
    game->drops[3]->sprite = init_image(YELLOW_BOTTLE, (sfIntRect){0, 0, 10, 11}, (sfVector2f){0, 0}, 10);
    sfSprite_setScale(game->drops[3]->sprite->sprite, (sfVector2f){5, 5});
    return (SUCCESS);
}

int init_game_struct_player(game_t *game)
{
    game->player = malloc(sizeof(player_t));
    if (!game->player)
        return (ERROR);
    game->player->attack = 10;
    game->player->defense = 1;
    game->player->health = 200;
    game->player->pos.x = 300;
    game->player->pos.y = 850;
    game->player->move = -1;
    game->player->speed = 7;
    game->player->projectiles = init_projectiles(6);
    game->player->proj_sprite = init_image_center(PLAYER_SHOT, (sfIntRect){0, 0, 48, 48}, (sfVector2f){-100, -100}, 192);
    if (init_inventory(game) == ERROR)
        return (ERROR);
    if (init_drop_dictionary(game) == ERROR)
        return (ERROR);
    return (SUCCESS);
}

void settings_pause_text(game_t *game)
{
    game->msg_settings = malloc(sizeof(msg_pause_s));
    game->msg_settings->text = sfText_create();
    game->msg_settings->font = sfFont_createFromFile(TEXT);
    game->msg_settings->msg = "SETTINGS";
}
void first_scene_pause_text(game_t *game)
{
    game->msg_menu = malloc(sizeof(msg_pause_s));
    game->msg_menu->text = sfText_create();
    game->msg_menu->font = sfFont_createFromFile(TEXT);
    game->msg_menu->msg = "MENU";
}
void exit_pause_text(game_t *game)
{
    game->msg_exit = malloc(sizeof(msg_pause_s));
    game->msg_exit->text = sfText_create();
    game->msg_exit->font = sfFont_createFromFile(TEXT);
    game->msg_exit->msg = "EXIT";
}

void return_pause_text(game_t *game)
{
    game->msg_return = malloc(sizeof(msg_pause_s));
    game->msg_return->text = sfText_create();
    game->msg_return->font = sfFont_createFromFile(TEXT);
    game->msg_return->msg = "RETURN";
}

void fps_text (game_t *game)
{
    game->fps->text = sfText_create();
    game->fps->font = sfFont_createFromFile(TEXT);
    game->fps->fps_msg = "30 FPS";
    game->render_info->fps = 30;
}

void vol_text (game_t *game)
{
    game->vol->text = sfText_create();
    game->vol->font = sfFont_createFromFile(TEXT);
    game->vol->vol_msg = "VOL 25";
}
    
void init_stats(game_t *game)
{
    game->stats->text = sfText_create();
    game->stats->font = sfFont_createFromFile(STATS);
    game->stats->lvl = malloc(sizeof(char) * 8 + 1);
    game->stats->health_bar = malloc(sizeof(char) * 8 + 1);
    game->stats->attack_txt = malloc(sizeof(char) * 8 + 1);
    game->stats->bullets = malloc(sizeof(char) * 8 + 1);
    game->stats->defend_txt = malloc(sizeof(char) * 8 + 1);
    game->stats->speed_txt = malloc(sizeof(char) * 8 + 1);
    game->stats->lvl = "LEVEL: 1";
    game->stats->health_bar = "HP: 200";
    game->stats->attack_txt = "DMG: 10";
    game->stats->bullets = "LEFT: 200";
    game->stats->defend_txt = "DEF: 10";
    game->stats->speed_txt = "SPD: 10";
}

game_t *init_game_struct(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (!game)
        return (NULL);
    game->render_info = malloc(sizeof(render_t));
    game->fps = malloc(sizeof(fps_t));
    game->vol = malloc(sizeof(vol_t));
    game->audio = malloc(sizeof(audio_t));
    game->stats = malloc(sizeof(stats_t));
    if (!game->render_info || !game->fps || !game->vol)
        return (NULL);
    game->render_info->window = init_window(1920, 1080, "EL MEJOR JUEGO DEL MUNDO");
    game->render_info->fps = 30;
    game->render_info->clock_refresh = sfClock_create();
    game->render_info->time_refresh = sfClock_getElapsedTime(game->render_info->clock_refresh);
    game->current = 0;
    game->before_pause = 0;
    game->render_info->pos_click.x = 0;
    game->render_info->pos_click.y = 0;
    game->render_info->seconds = 0;
    game->max_floor = 0;
    game->shoot_type = 0;
    game->image = malloc(sizeof(image_t *) * (1 + 1));
    game->image[0] = init_image(HELP_DISPLAY, (sfIntRect){0, 0, 1536, 171},
                                (sfVector2f){-1920, 800}, 1536);

    game->image[1] = NULL;
    fps_text(game);
    vol_text(game);
    init_audio(game);
    settings_pause_text(game);
    return_pause_text(game);
    exit_pause_text(game);
    first_scene_pause_text(game);
    init_stats(game);
    if (init_game_struct_player(game) == ERROR || init_tower(game) == ERROR)
        return (NULL);
    return (game);
}