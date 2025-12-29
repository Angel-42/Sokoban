/*
** EPITECH PROJECT, 2023
** save_pos
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

void is_caro(char **map, int y, int x, all *al)
{
    if (map[y][x] == 'O') {
        al->o_pos[al->cpt_o].o_x = x;
        al->o_pos[al->cpt_o].o_y = y;
        al->cpt_o++;
    }
}

void is_carx(char **map, int y, int x, all *al)
{
    if (map[y][x] == 'X') {
        al->x_pos[al->cpt_x].x_x = x;
        al->x_pos[al->cpt_x].x_y = y;
        al->cpt_x++;
    }
}

void save_o_pos(all *al, char **map)
{
    al->cpt_o = 0;
    al->l_o = malloc(al->size + 1);
    al->o_pos = malloc(al->size_y * al->size_x * sizeof(base_o));
    for (int y = 0; y < al->size_y; y++)
        for (int x = 0; x < al->size_x; x++)
            is_caro(map, y, x, al);
    al->l_o[al->cpt_o] = -1;
}

void save_x_pos(all *al, char **map)
{
    al->cpt_x = 0;
    al->l_x = malloc(al->size + 1);
    al->x_pos = malloc(al->size_y * al->size_x * sizeof(base_x));
    for (int y = 0; y < al->size_y; y++)
        for (int x = 0; x < al->size_x; x++)
            is_carx(map, y, x, al);
    al->l_x[al->cpt_x] = -1;
}
