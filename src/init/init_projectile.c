/*
** EPITECH PROJECT, 2021
** init projectile
** File description:
** initiates projectile
*/

#include "my_rpg.h"

projectile_t **init_projectiles(int n_proyectiles)
{
    int i = 0;
    projectile_t **projectiles = malloc(sizeof(projectile_t *) * (n_proyectiles + 1));

    if (!projectiles)
        return (NULL);
    for (i = 0; i < n_proyectiles; i++) {
        projectiles[i] = malloc(sizeof(projectile_t));
        if (!projectiles[i])
            return (NULL);
        projectiles[i]->damage = 10;
        projectiles[i]->direction = (sfVector2f){0, 0};
        projectiles[i]->speed = 30;
        projectiles[i]->pos = (sfVector2f){-10, -10};
        projectiles[i]->type = 0;
        projectiles[i]->travelling = 0;
    }
    projectiles[i] = NULL;

    return (projectiles);
}

