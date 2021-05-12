/*
** EPITECH PROJECT, 2021
** init menu struct
** File description:
** init pause struct
*/

#include "my_rpg.h"

button *init_buttons_first_scene_in_pause(button *first_scene)
{
    first_scene = init_button((sfVector2f) {100, 100}, (sfVector2f) {71,69});
    if (!first_scene)
        return (NULL);
    first_scene->fn = &return_first_scene;
    first_scene->unpressed = init_image(RED_BACK,  (sfIntRect){0, 0, 71, 69},
                                        first_scene->pos, first_scene->size.x);
    first_scene->hover = init_image(BLUE_BACK,  (sfIntRect){0, 0, 71, 69},
                                first_scene->pos, first_scene->size.x);
    return (first_scene);

}

button *init_buttons_settings_in_pause(button *settings)
{
     settings = init_button((sfVector2f) {860, 262}, (sfVector2f) {140,136});
     if (!settings)
        return (NULL);
    settings->fn = &change_to_settings;
    settings->unpressed = init_image(RED_SETTINGS, (sfIntRect){0, 0, 140, 138},
                                settings->pos, settings->size.x);
    settings->hover = init_image(BLUE_SETTINGS, (sfIntRect){0, 0, 138, 136},
                                settings->pos, settings->size.x);
    return (settings);
}

button *init_buttons_exit_in_pause(button *exit)
{
    exit = init_button((sfVector2f) {860, 662}, (sfVector2f) {140, 136});
    if (!exit)
        return (NULL);
    exit->fn = &close_window;
    exit->unpressed = init_image(RED_EXIT, (sfIntRect){0, 0, 138, 136},
                                exit->pos, exit->size.x);
    exit->hover = init_image(BLUE_EXIT, (sfIntRect){0, 0, 138, 136},
                                exit->pos, exit->size.x);
    return (exit);
}

button *init_buttons_menu_in_pause(button *pause)
{
    pause = init_button((sfVector2f){860, 462}, (sfVector2f) {140, 136});
    if (!pause)
        return (NULL);
    pause->fn = &return_to_scene;
    pause->unpressed = init_image(RED_PLAY, (sfIntRect){0, 0, 138, 136},
                                pause->pos, pause->size.x);
    pause->hover = init_image(BLUE_PLAY, (sfIntRect){0, 0, 138, 136},
                                pause->pos, pause->size.x);
    pause->is_clicked = 0;
    return (pause);
}

button **init_buttons_pause(scene_t *scenes) 
{
    scenes->buttons = malloc(sizeof(button *)* (4 + 1));

    if (scenes->buttons == NULL)
        return (NULL);
    scenes->buttons[0] = init_buttons_menu_in_pause(scenes->buttons[0]);
    scenes->buttons[1] = init_buttons_exit_in_pause(scenes->buttons[1]);
    scenes->buttons[2] = init_buttons_settings_in_pause(scenes->buttons[2]);
    scenes->buttons[3] = init_buttons_first_scene_in_pause(scenes->buttons[3]);
    scenes->buttons[4] = NULL;
    return (scenes->buttons);
}