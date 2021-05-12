/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init fps buttons
*/

#include "my_rpg.h"

button *init_volume(button *volume) 
{
    volume = init_button((sfVector2f){600, 300}, (sfVector2f) {344, 136});
    if (!volume)
        return (NULL);
    volume->fn = &vol_func;
    volume->unpressed = init_image(RED_EMPTY, (sfIntRect){0, 0, 344, 138},
                                volume->pos, volume->size.x);
    volume->hover = init_image(BLUE_EMPTY, (sfIntRect){0, 0, 344, 136},
                                volume->pos, volume->size.x);
    volume->is_clicked = 0;
    return (volume);
}

button *init_fps(button *fps) 
{
    fps = init_button((sfVector2f){600, 562}, (sfVector2f) {344, 136});
    if (!fps)
        return (NULL);
    fps->fn = &fps_func;
    fps->unpressed = init_image(RED_EMPTY, (sfIntRect){0, 0, 344, 138},
                                fps->pos, fps->size.x);
    fps->hover = init_image(BLUE_EMPTY, (sfIntRect){0, 0, 344, 136},
                                fps->pos, fps->size.x);
    fps->is_clicked = 0;
    return (fps);
}

button *init_back(button *back) 
{
    back = init_button((sfVector2f){50, 50}, (sfVector2f) {71, 69});
    if (!back)
        return (NULL);
    back->fn = &back_function;
    back->unpressed = init_image(RED_BACK, (sfIntRect){0, 0, 71, 69},
                                back->pos, back->size.x);
    back->hover = init_image(BLUE_BACK, (sfIntRect){0, 0, 71, 69},
                            back->pos, back->size.x);
    back->is_clicked = 0;
    return (back);
}

button **init_buttons_settings (scene_t *scenes)
{
    scenes->buttons = malloc(sizeof(button *) * (3 + 1));

    if (!scenes->buttons)
        return (NULL);
    scenes->buttons[VOLUME] = init_volume(scenes->buttons[VOLUME]);
    scenes->buttons[FPS] = init_fps(scenes->buttons[FPS]);
    scenes->buttons[BACK] = init_back(scenes->buttons[BACK]);
    if (scenes->buttons[VOLUME] == NULL || scenes->buttons[FPS] == NULL ||
        scenes->buttons[BACK] == NULL)
        return (NULL);
    scenes->buttons[3] = NULL;
    return (scenes->buttons);
}