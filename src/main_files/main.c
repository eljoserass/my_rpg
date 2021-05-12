/*
** EPITECH PROJECT, 2021
** main
** File description:
** main mr main
*/

#include "my_rpg.h"

int main(int ac, char **av)
{
    if (ac == 2 && my_strcmp(av[1], "-h") == 0)
        return (print_usage());
    return (do_my_rpg());
}
