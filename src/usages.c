/*
** EPITECH PROJECT, 2023
** Usages for my_sokoban
** File description:
** My_sokoban
*/

#include <unistd.h>
#include "../include/my.h"

void usages(void)
{
    write(1, "USAGE\n", 7);
    write(1, "     ./my_sokoban map\n", 23);
    write(1, "DESCRIPTION\n", 13);
    write(1, "     Map  file representing the warehouse map, ", 47);
    write(1, "containing '#' for walls,\n", 27);
    write(1, "          'P' for the player, 'X' for boxes and", 47);
    write(1, " 'O' for storage locations.\n", 29);
}
