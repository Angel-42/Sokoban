/*
** EPITECH PROJECT, 2023
** loose_win
** File description:
** PSU Angel
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../include/my.h"

bool check_win(all *al, char **map)
{
    int x;
    int y;

    for (int i = 0; i < al->cpt_o; i++) {
        x = al->o_pos[i].o_x;
        y = al->o_pos[i].o_y;
        if (map[y][x] != 'X')
            return false;
    }
    return true;
}

int test_lose(all *al, char **map, int i)
{
    if (UP_UP(i) && LEFT_LEFT(i))
        return 1;
    if (UP_UP(i) && RIGHT_RIGHT(i))
        return 1;
    if (DOWN_DOWN(i) && LEFT_LEFT(i))
        return 1;
    if (DOWN_DOWN(i) && RIGHT_RIGHT(i))
        return 1;
    return 0;
}

bool check_loose(all *al, char **map)
{
    int tot = 0;

    for (int i = 0; i < al->cpt_x; i++) {
        tot += test_lose(al, map, i);
    }
    if (tot >= al->cpt_x)
        return true;
    return false;
}
