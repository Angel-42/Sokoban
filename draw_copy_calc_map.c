/*
** EPITECH PROJECT, 2023
** draw_save_check_map
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
#include "my.h"

void copy_map(char **original, all *al)
{
    for (int i = 0; i < al->size_y; i++) {
        for (int j = 0; j < al->size_x; j++) {
            al->orim[i][j] = original[i][j];
        }
    }
}

void draw_map(char **map, all *al)
{
    for (int y = 0; y < al->size_y; y++) {
        printw("%s", map[y]);
        printw("%c", '\n');
    }
}

void condit_calcul(int om, all *al)
{
    if (om > al->size_x)
        al->size_x = om;
}

int calc_size(int size, const char *buffer, all *al)
{
    int k = 0;
    int o = 0;
    int om = 0;

    al->size = size;
    al->size_x = 0;
    al->size_y = 0;
    while (k < size) {
        if (buffer[k] == '\n') {
            o++;
            condit_calcul(om, al);
            om = 0;
        } else
            om++;
        k++;
    }
    al->size_y = o + 1;
    al->size = k;
    return 0;
}
