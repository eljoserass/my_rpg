/*
** EPITECH PROJECT, 2021
** str to arg
** File description:
** string to array
*/

#include "my_rpg.h"

/*requires remove_end_spaces used in order to not crash*/
/*0 = is not good*/
/*1 = is good*/

int is_separator(char c, char *separators)
{
    int i = 0;

    while (separators[i] != '\0') {
        if (c == separators[i])
            return (0);
        i++;
    }
    if (c == '\0')
        return (0);
    return (1);
}

char *remove_end_separators(char *str, char *separators)
{
    int len = 0;

    if (str == NULL)
        return (NULL);
    len = my_strlen(str) - 1;
    while (is_separator(str[len], separators) == 0)
        len--;
    str[len + 1] = '\0';
    return (str);
}

int num_words(char const *str, char *separators)
{
    int i = 0;
    int n_words = 0;

    while (str[i] != '\0') {
        while (is_separator(str[i], separators) == 0)
            i++;
        while (is_separator(str[i], separators) == 1){
            if (is_separator(str[i + 1], separators) == 0)
                n_words++;
            i++;
        }
    }
    return (n_words);
}

char **malloc_array(char const *str, char *separators)
{
    int n_words = num_words(str, separators);
    char **word_arr = malloc(sizeof(char *) * (n_words + 1));
    int i = 0;
    int j = 0;
    int n_letters = 0;

    while (str[i] != '\0') {
        while (is_separator(str[i], separators) == 0)
            i++;
        while (is_separator(str[i], separators) == 1){
            if (is_separator(str[i + 1], separators) == 0) {
                word_arr[j] = malloc(sizeof(char) * (n_letters + 2));
                j++;
            }
            n_letters++;
            i++;
        }
        n_letters = 0;
    }
    return (word_arr);
}

char **str_to_array(char const *str, char *separators)
{
    char **word_arr = malloc_array(str, separators);
    int i = 0, j = 0;
    int w_position = 0;

    while (str[i] != '\0') {
        while (is_separator(str[i], separators) == 0)
            i++;
        while (is_separator(str[i], separators) == 1) {
            word_arr[j][w_position] = str[i];
            w_position++;
            if (is_separator(str[i + 1], separators) == 0)
                j++;
            i++;
        }
        if (j - 1 > -1)
            word_arr[j - 1][w_position] = '\0';
        w_position = 0;
    }
    word_arr[num_words(str, separators)] = NULL;
    return (word_arr);
}