/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that initializes the reosurces
*/

#include "my_rpg.h"

int init_resources(game_t **game, scene_t ***scenes)
{
    *game = init_game_struct();
    if (!game)
        return (ERROR);
    *scenes = init_scenes();
    if (!scenes)
        return (ERROR);
    return (SUCCESS);
}