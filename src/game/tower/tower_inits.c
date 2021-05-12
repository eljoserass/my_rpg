/*
** EPITECH PROJECT, 2021
** tower inits
** File description:
** inciating stuff in tower
*/

#include "my_rpg.h"

void init_enemy_sprites(game_t *game)
{
    game->tower->e_sprites = malloc(sizeof(image_t *) * (4 + 1));
    game->tower->e_sprites[0] = init_image_center(GOBLIN, (sfIntRect){0, 0, 64, 40}, (sfVector2f){-100, -100}, 256);
    game->tower->e_sprites[1] = init_image_center(ORC, (sfIntRect){0, 0, 67, 72}, (sfVector2f){-100, -100}, 201);
    game->tower->e_sprites[2] = init_image_center(OGRE, (sfIntRect){0, 0, 135, 112}, (sfVector2f){-100, -100}, 540);
    game->tower->e_sprites[3] = init_image_center(BOSS, (sfIntRect){0, 0, 160, 96}, (sfVector2f){-100, -100}, 640   );
    game->tower->e_sprites[4] = NULL;
}

void init_e_projectiles(game_t *game)
{
    game->tower->p_sprites = malloc(sizeof(image_t *) * (4 + 1));
    game->tower->p_sprites[0] = init_image_center(DAGGER, (sfIntRect){0, 0, 28, 28}, (sfVector2f){-100, -100}, 113);
    game->tower->p_sprites[1] = init_image_center(MACE, (sfIntRect){0, 0, 44, 44}, (sfVector2f){-100, -100}, 176);
    game->tower->p_sprites[2] = init_image_center(HAMMER, (sfIntRect){0, 0, 74, 74}, (sfVector2f){-100, -100}, 296);
    game->tower->p_sprites[3] = init_image_center(BOSS_SHOT, (sfIntRect){0, 0, 48, 48}, (sfVector2f){-100, -100}, 384);
    game->tower->p_sprites[4] = NULL;
}

void init_tower_clocks(game_t *game)
{
    game->tower->clocks = malloc(sizeof(tower_clocks_t));
    game->tower->clocks->e_clock = sfClock_create();
    game->tower->clocks->e_time = sfClock_getElapsedTime(game->tower->clocks->e_clock);
    game->tower->clocks->e_seconds = 0;
    game->tower->clocks->p_clock = sfClock_create();
    game->tower->clocks->p_time = sfClock_getElapsedTime(game->tower->clocks->p_clock);
    game->tower->clocks->p_seconds = 0;
}

int init_tower(game_t *game)
{
    tower_t *tower = malloc(sizeof(tower_t));
    game->tower = tower;
    tower->background = init_image(TOWER_BACKGROUND, (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0}, 1920);
    tower->enemies = NULL;
    tower->floor = 0;
    init_enemy_sprites(game);
    init_e_projectiles(game);
    init_tower_clocks(game);
    return (0);
}