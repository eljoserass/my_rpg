/*
** EPITECH PROJECT, 2021
** init menu struct
** File description:
** init menu struct
*/

#include "my_rpg.h"

button *init_play(button *play) 
{
    play = init_button((sfVector2f){280, 162}, (sfVector2f) {134, 138});
    if (!play)
        return (NULL);
    play->fn = &change_to_game;
    play->unpressed = init_image(RED_PLAY, (sfIntRect){0, 0, 134, 138},
                                play->pos, play->size.x);
    play->hover = init_image(BLUE_PLAY, (sfIntRect){0, 0, 140, 138},
                                play->pos, play->size.x);
    play->is_clicked = 0;
    return (play);
}

button *init_exit(button *exit)
{
    exit = init_button((sfVector2f){424, 314}, (sfVector2f) {140, 140});
    if (!exit)
        return (NULL);
    exit->fn = &close_window;
    exit->unpressed = init_image(RED_EXIT, (sfIntRect){0, 0, 142, 136},
                                exit->pos, exit->size.x);
    exit->hover = init_image(BLUE_EXIT, (sfIntRect){0, 0, 142, 140},
                                exit->pos, exit->size.x);
    exit->is_clicked = 0;
    return (exit);
}

button *init_settings(button *settings) 
{
    settings = init_button((sfVector2f){424, 162}, (sfVector2f) {140, 136});
    if (!settings)
        return (NULL);
    settings->fn = &change_to_settings;
    settings->unpressed = init_image(RED_SETTINGS, (sfIntRect){0, 0, 140, 138},
                                settings->pos, settings->size.x);
    settings->hover = init_image(BLUE_SETTINGS, (sfIntRect){0, 0, 138, 136},
                                settings->pos, settings->size.x);
    settings->is_clicked = 0;
    return (settings);
}

button *init_help(button *help) 
{
    help = init_button((sfVector2f){280, 314}, (sfVector2f) {140, 138});
    if (!help)
        return (NULL);
    help->fn = &display_help;
    help->unpressed = init_image(RED_HELP, (sfIntRect){0, 0, 140, 140},
                                help->pos, help->size.x);
    help->hover = init_image(BLUE_HELP, (sfIntRect){0, 0, 140, 138},
                            help->pos, help->size.x);
    help->is_clicked = 0;
    return (help);
}
button **init_buttons_menu (scene_t *scenes)
{
    scenes->buttons = malloc(sizeof(button *) * (4 + 1));

    if (!scenes->buttons)
        return (NULL);
    scenes->buttons[PLAY] = init_play(scenes->buttons[PLAY]);
    scenes->buttons[EXIT] = init_exit(scenes->buttons[EXIT]);
    scenes->buttons[SETTINGS_B] = init_settings(scenes->buttons[SETTINGS_B]);
    scenes->buttons[HELP] = init_help(scenes->buttons[HELP]);
    if (scenes->buttons[PLAY] == NULL || scenes->buttons[EXIT] == NULL ||
        scenes->buttons[SETTINGS_B] == NULL || scenes->buttons[HELP] == NULL)
        return (NULL);
    scenes->buttons[4] = NULL;
    return (scenes->buttons);
}