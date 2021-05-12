/*
** EPITECH PROJECT, 2020
** read_pos
** File description:
** reads position maps
*/

#include "my_rpg.h"

char *get_file(char *file)
{
    int size = get_size(file);
    char *buf = NULL;
    int fd = 0;

    if (size == -1)
        return (NULL);
    buf = malloc(sizeof(char) * (size + 1));
    if (buf == NULL)
        return (NULL);
    fd = open(file, O_RDONLY);
    if (fd == -1) {
        my_putstr("f(open) failed\n");
        return (NULL);
    }
    if (read_file(fd, buf, size) == 84 || close(fd) == -1)
        return (NULL);
    buf[size] = '\0';
    return (buf);
}