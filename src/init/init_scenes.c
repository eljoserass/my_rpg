/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that initi the scenes
*/

#include "my_rpg.h"

int init_scene_menu(scene_t **scenes)
{
    scenes[MENU] = malloc(sizeof(scene_t));

    if (!scenes[MENU])
        return (ERROR);
    scenes[MENU]->buttons = init_buttons_menu(scenes[MENU]);
    if (scenes[MENU]->buttons == NULL)
        return (ERROR);
    scenes[MENU]->sprites = malloc(sizeof(image_t *) * (2 + 1));
    scenes[MENU]->sprites[0] = init_image(BACKGROUND, (sfIntRect){0, 0, 1920, 1080}, (sfVector2f){0, 0}, 1920);
    scenes[MENU]->sprites[1] = init_image(HELP_DISPLAY, (sfIntRect){0, 0, 1536, 171}, (sfVector2f){-1920, 800}, 1536);
    scenes[MENU]->sprites[2] = NULL;
    return (SUCCESS);
}

int init_scene_game(scene_t **scenes)
{
    scenes[GAME] = malloc(sizeof(scene_t));

    if (!scenes[GAME])
        return (ERROR);
    scenes[GAME]->buttons = NULL;
    scenes[GAME]->sprites = malloc(sizeof(image_t *) * (3 + 1));
    scenes[GAME]->sprites[0] = init_image_center(PLAYER_WALK, (sfIntRect){0, 0, 160, 96}, (sfVector2f){300, 850}, 640);
    scenes[GAME]->sprites[1] = init_image(MAIN_FLOOR, (sfIntRect){0, 0, 1440, 1080}, (sfVector2f){0, 0}, 1440);
    scenes[GAME]->sprites[2] = init_image(FINAL_FLOOR, (sfIntRect){0, 0, 1440, 1080}, (sfVector2f){-1500, 0}, 1440);
    scenes[GAME]->sprites[3] = NULL;
    return (SUCCESS);
}

int init_scene_pause(scene_t **scenes)
{
    scenes[PAUSE] = malloc(sizeof(scene_t));

    if (!scenes[PAUSE])
        return (ERROR);
    scenes[PAUSE]->buttons = init_buttons_pause(scenes[PAUSE]);
    scenes[PAUSE]->sprites = malloc(sizeof(image_t *) * (1 + 1));
    scenes[PAUSE]->sprites[0] = init_image(BACKGROUND_P, (sfIntRect) {0,0,1920,1080}, (sfVector2f) {0, 0}, 1920);
    scenes[PAUSE]->sprites[1] = NULL;
    return (SUCCESS);
}

int init_scene_settings(scene_t **scenes)
{
    scenes[SETTINGS] = malloc(sizeof(scene_t));

    if (!scenes[SETTINGS])
        return (ERROR);
    scenes[SETTINGS]->buttons = init_buttons_settings(scenes[SETTINGS]);
    scenes[SETTINGS]->sprites = malloc(sizeof(image_t *) * (1 + 1));
    scenes[SETTINGS]->sprites[0] = init_image(BACKGROUND_S, (sfIntRect) {0,0,1920,1080}, (sfVector2f) {0, 0}, 1920);
    scenes[SETTINGS]->sprites[1] = NULL;
    return (SUCCESS);
}

scene_t **init_scenes(void)
{
    scene_t **scenes = malloc(sizeof(scene_t *) * SCENES);

    if (!scenes)
        return (NULL);
    if (init_scene_menu(scenes) == ERROR)
        return (NULL);
    if (init_scene_game(scenes) == ERROR)
        return (NULL);
    if (init_scene_pause(scenes) == ERROR)
        return (NULL);
    if (init_scene_settings(scenes) == ERROR)
        return (NULL);
    return (scenes);
}