/*
** EPITECH PROJECT, 2023
** move_plox
** File description:
** Angel
*/

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"

void get_p(all *al, char **map)
{
    int x = 0;
    int y = 0;

    for (y = 0; y < al->size_y; y++){
        for (x = 0; x < al->size_x && map[y][x] != 'P'; x++){
        }
        if (map[y][x] == 'P'){
            al->p_x = x;
            al->p_y = y;
            break;
        }
    }
}

void reset_map(all *al, char **map)
{
    for (int y = 0; y < al->size_y; y++) {
        for (int x = 0; x < al->size_x; x++) {
            map[y][x] = al->orim[y][x];
        }
    }
    al->p_x = -1;
    al->p_y = -1;
    get_p(al, map);
}

static void mouv_left(char **map, all *al)
{
    if (MOUV(map[al->p_y][al->p_x - 1], map[al->p_y][al->p_x - 2])) {
        map[al->p_y][al->p_x] = ' ';
        al->p_x--;
        map[al->p_y][al->p_x] = 'P';
        map[al->p_y][al->p_x - 1] = 'X';
    } else if (LEFT2 == ' ' || LEFT2 == 'O') {
        map[al->p_y][al->p_x] = ' ';
        al->p_x--;
        map[al->p_y][al->p_x] = 'P';
    }
}

static void mouv_right(char **map, all *al)
{
    if (MOUV(map[al->p_y][al->p_x + 1], map[al->p_y][al->p_x + 2])) {
        map[al->p_y][al->p_x] = ' ';
        al->p_x++;
        map[al->p_y][al->p_x] = 'P';
        map[al->p_y][al->p_x + 1] = 'X';
    } else if (RIGHT2 == ' ' || RIGHT2 == 'O') {
        map[al->p_y][al->p_x] = ' ';
        al->p_x++;
        map[al->p_y][al->p_x] = 'P';
    }
}

static void mouv_up(char **map, all *al)
{
    if (MOUV(map[al->p_y - 1][al->p_x], map[al->p_y - 2][al->p_x])) {
        map[al->p_y][al->p_x] = ' ';
        al->p_y--;
        map[al->p_y][al->p_x] = 'P';
        map[al->p_y - 1][al->p_x] = 'X';
    } else if (UP2 == ' ' || UP2 == 'O') {
        map[al->p_y][al->p_x] = ' ';
        al->p_y--;
        map[al->p_y][al->p_x] = 'P';
    }
}

static void mouv_down(char **map, all *al)
{
    if (MOUV(map[al->p_y + 1][al->p_x], map[al->p_y + 2][al->p_x])) {
        map[al->p_y][al->p_x] = ' ';
        al->p_y++;
        map[al->p_y][al->p_x] = 'P';
        map[al->p_y + 1][al->p_x] = 'X';
    } else if (DOWN2 == ' ' || DOWN2 == 'O') {
        map[al->p_y][al->p_x] = ' ';
        al->p_y++;
        map[al->p_y][al->p_x] = 'P';
    }
}

void move_plox(all *al, char **map)
{
    int key = getch();

    get_p(al, map);
    switch (key) {
        case KEY_UP:
            mouv_up(map, al);
            break;
        case KEY_DOWN:
            mouv_down(map, al);
            break;
        case KEY_LEFT:
            mouv_left(map, al);
            break;
        case KEY_RIGHT:
            mouv_right(map, al);
            break;
        case 32:
            reset_map(al, map);
            break;
    }
}
