/*
** EPITECH PROJECT, 2021
** my_strcatint.c
** File description:
** add an int as a str into a str
*/


#include "my_rpg.h"

int finding_decimals(int number)
{
    int i = 1;

    while (number > 10){
        number = number/ 10;
        i++;
    }
    return (i);
}

char * my_strcat_int(char *str, int number)
{
    int decimals = finding_decimals(number);
    char *str_temp = malloc(sizeof(char) * (decimals + 1));

    while (decimals >= 0){
        str_temp[decimals] = (number % 10) + 48;
        number = number / 10;
        decimals--;
    }
    str_temp[finding_decimals(number) + 1] = '\0';
    if (!str)
        return (str_temp);
    str = my_strcat(str, str_temp);
    free(str_temp);
    return (str);
}