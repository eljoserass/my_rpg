/*
** EPITECH PROJECT, 2021
** types of projectiles
** File description:
** types of projectiles
*/

#include "my_rpg.h"

void proj_dagger(e_projectile_t *projectile)
{
    projectile->dmg = 10;
    projectile->spd = 13;
}

void proj_mace(e_projectile_t *projectile)
{
    projectile->dmg = 15;
    projectile->spd = 20;
}

void proj_hammer(e_projectile_t *projectile)
{
    projectile->dmg = 50;
    projectile->spd = 7;
}

void proj_evil(e_projectile_t *projectile)
{
    projectile->dmg = 25;
    projectile->spd = 25;
}

void projectile_types(e_projectile_t *projectile, int type)
{
    if (type == 1)
        proj_dagger(projectile);
    if (type == 2)
        proj_mace(projectile);
    if (type == 3)
        proj_hammer(projectile);
    if (type == 4)
        proj_evil(projectile);
}