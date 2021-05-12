/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** funciton that prints usage
*/

#include "my_rpg.h"

int print_usage(void)
{
    my_putstr("\033[1;31m");
    my_putstr("USAGE\n");
    my_putstr("\tWASD and ARROWS to move\n");
    my_putstr("\tPress T to change shoot type\n");
    my_putstr("\tShoot with click\n");
    my_putstr("RECOMENDATIONS:\n\tPlay with mouse");
    my_putstr("\n\tDont't get near enemies\n");
    my_putstr("\033[0m");
    my_putstr("\033[0;32m");
    my_putstr("Enjoy :)\n");
    my_putstr("Made with love by Activision Publishing, Inc.\n");
    my_putstr("\033[0m");
    return (0);
}