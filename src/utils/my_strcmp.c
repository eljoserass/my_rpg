/*
** EPITECH PROJECT, 2020
** my_strcmp
** File description:
** Reproduce the behavior of the str cmp function
*/

#include <stdio.h>

int my_strcmp(const char *s1, const char *s2)
{
    char c1 = '\0';
    char c2 = c1;
    int i = 0;

    do {
        c1 = s1[i];
        c2 = s2[i];
        if (c1 == '\0')
            return (c1 - c2);
        i++;
    } while (c1 == c2);
    return (c1 - c2);
}