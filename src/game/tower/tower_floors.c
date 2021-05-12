/*
** EPITECH PROJECT, 2021
** tower floor
** File description:
** manages tower floors
*/

#include "my_rpg.h"

void read_tower_config(game_t *game, char *path)
{
    char *config_str = get_file(path);
    char **config = NULL;
    int len = 0;
    int j = 0;

    if (config_str == NULL)
        return;
    config = str_to_array(remove_end_separators(config_str, " \n"), " \n");
    free(config_str);
    game->tower->enemies = malloc(sizeof(enemy_t *) * (my_getnbr(config[0]) + 1));
    for (len = 0; config[len] != NULL; len++);
    for (int i = 1; i < len; i += 3) {
        game->tower->enemies[j] = generate_enemy(game, my_getnbr(config[i]),
                                                (sfVector2f){my_getnbr(config[i + 1]), my_getnbr(config[i + 2])});
        j++;
    }
    game->tower->enemies[j] = NULL;
    free_char_array(config);
}

void empty_tower_floor(tower_t *tower)
{
    if (tower->enemies == NULL)
        return;
    for (int i = 0; tower->enemies[i] != NULL; i++) {
        for (int j = 0; tower->enemies[i]->projectiles[j] != NULL; j++) {
            sfClock_destroy(tower->enemies[i]->projectiles[j]->clock);
            free(tower->enemies[i]->projectiles[j]);
        }
        tower->enemies[i]->projectiles = NULL;
        sfClock_destroy(tower->enemies[i]->clock);
        free(tower->enemies[i]);
    }
    tower->enemies = NULL;
}

void fill_tower_floor(game_t *game, int floor)
{
    char *path = macro_to_path(FLOOR_CONFIG, floor);
    if (floor > 0 && floor < 25)
        read_tower_config(game, path);
    else if (floor == 25)
        spawn_boss(game);
    if (floor > 10 && floor < 25)
        enemy_health_buff(game->tower);
    free(path);
}

void change_tower_floor(game_t *game, int new_floor)
{
    empty_tower_floor(game->tower);
    game->tower->floor = new_floor;
    fill_tower_floor(game, new_floor);
}

int get_random_pos(int minimum_number, int max_number)
{
    return (rand() % (max_number + 1 - minimum_number) + minimum_number);
}

void check_tower_floor(game_t *game, enemy_t **enemies)
{
    int any_alive = 0;

    for (int i = 0; enemies != NULL && enemies[i] != NULL; i++) {
        if (enemies[i]->health > 0)
            any_alive = 1;
    }
    if (any_alive == 0 && player_in_stairs(game) == 1) {
        if (game->max_floor < game->tower->floor) {
            game->max_floor = game->tower->floor;
            add_item(game, get_random_pos(0, 3));
        }
        sfSprite_setOrigin(game->tower->background->sprite, (sfVector2f){300, 800});
        do_zoom_effect(game->render_info->window, game->tower->background->sprite);
        sfSprite_setOrigin(game->tower->background->sprite, (sfVector2f){0, 0});
        game->player->health += 10;
        change_tower_floor(game, game->tower->floor + 1);
    }
}