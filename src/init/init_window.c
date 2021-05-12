/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** function that initializes a window at 30fps
*/

#include <SFML/Graphics.h>

sfRenderWindow *init_window(int width, int height, char *name)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;
    window = sfRenderWindow_create(video_mode, name, sfFullscreen, NULL);
    sfRenderWindow_setFramerateLimit(window, 30);
    return (window);
}