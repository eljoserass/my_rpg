/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** int to array funcition
*/

#include "my_rpg.h"

char *reverse_string(char *str)
{
    int i = 0;
    int size = my_strlen(str) - 1;
    char aux = 0;

    while (i < size) {
        aux = str[i];
        str[i] = str[size];
        str[size] = aux;
        i++;
        size--;
    }
    return (str);
}

char *my_itoa(int num, int size, int base)
{
    char *str = malloc(sizeof(char) * size + 1);
    int rem = 0;
    int i = 0;

    while (num != 0) {
        rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }
    str[i]  = '\0';
    str = reverse_string(str);
    return (str);
}