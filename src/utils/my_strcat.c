/*
** EPITECH PROJECT, 2021
** lib
** File description:
** function that concat two string
*/

#include <stdlib.h>
#include "my_rpg.h"

char *my_strcat(char *sone, char *stwo)
{
    int i = 0;
    int j = 0;
    int size = my_strlen(sone) + my_strlen(stwo) + 3;
    char *result = malloc(sizeof(char) * size);

    if (!result)
        return (NULL);
    while (sone[i] != '\0') {
        result[i] = sone[i];
        i++;
    }
    while (stwo[j] != '\0') {
        result[i] = stwo[j];
        i++;
        j++;
    }
    result[i] = '\0';
    return (result);
}