/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** funciton to initialize an image
*/

#include <stdlib.h>
#include "my_rpg.h"

image_t *init_image(char *path, sfIntRect rect, sfVector2f pos, int max_value)
{
    image_t *image = malloc(sizeof(image_t));

    if (image == NULL)
        return (NULL);
    image->rect = rect;
    image->pos.x = pos.x;
    image->pos.y = pos.y;
    image->offset = rect.width;
    image->max_value = max_value;
    image->texture = sfTexture_createFromFile(path, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setTextureRect(image->sprite, image->rect);
    sfSprite_setPosition(image->sprite, pos);
    return (image);
}

image_t *init_image_center(char *path, sfIntRect rect, sfVector2f pos, int max_value)
{
    image_t *image = malloc(sizeof(image_t));

    if (image == NULL)
        return (NULL);
    image->rect = rect;
    image->pos.x = pos.x;
    image->pos.y = pos.y;
    image->offset = rect.width;
    image->max_value = max_value;
    image->texture = sfTexture_createFromFile(path, NULL);
    image->sprite = sfSprite_create();
    sfSprite_setTexture(image->sprite, image->texture, sfTrue);
    sfSprite_setTextureRect(image->sprite, image->rect);
    sfSprite_setOrigin(image->sprite, (sfVector2f){rect.width/2, rect.height/2});
    sfSprite_setPosition(image->sprite, pos);
    return (image);
}