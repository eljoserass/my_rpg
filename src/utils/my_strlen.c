/*
** EPITECH PROJECT, 2021
** library
** File description:
** len of a str
*/

unsigned int my_strlen(const char *str)
{
    int i = 0;

    while (str[i] != '\0')
        i++;
    return (i);
}