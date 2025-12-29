/*
** EPITECH PROJECT, 2023
** my_sokoban
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

static void refr_clear(void)
{
    refresh();
    clear();
}

static void initialize(void)
{
    initscr();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
}

char **convert_str(const char *buffer, all *al)
{
    char **str;
    int k = 0;
    int o = 0;
    int om = 0;

    str = malloc(sizeof(char *) * (al->size_y + 1));
    for (int i = 0; i < al->size_y; i++)
        str[i] = malloc(al->size_x * sizeof(char) + 1);
    while (k < al->size) {
        if (buffer[k] == '\n') {
            o++;
            om = 0;
        } else {
            str[o][om] = buffer[k];
            om++;
        }
        k++;
    }
    return str;
}

static void window_check(all *al)
{
    int max_y;
    int max_x;

    getmaxyx(stdscr, max_y, max_x);
    while (max_y < al->size_y || max_x < al->size_x + 1) {
        clear();
        getmaxyx(stdscr, max_y, max_x);
        mvprintw(max_y / 2, (max_x - my_strlen("Resize!")) / 2, "Resize!");
        refr_clear();
    }
}

static void replace_o(all *al, char **map)
{
    int x;
    int y;

    for (int i = 0; al->l_o[i] != -1; i++) {
        x = al->o_pos[i].o_x;
        y = al->o_pos[i].o_y;
        if (map[y][x] == ' ')
            map[y][x] = 'O';
    }
}

int run_game(all *al, char **map)
{
    while (1) {
        window_check(al);
        save_x_pos(al, map);
        draw_map(map, al);
        if (check_win(al, map)) {
            refr_clear();
            return 0;
        }
        if (check_loose(al, map)) {
            refr_clear();
            return 1;
        }
        move_plox(al, map);
        replace_o(al, map);
        refr_clear();
    }
    return 0;
}

int main_sec(all *al, char **map)
{
    int result;

    al->orim = malloc(sizeof(char *) * al->size_y);
    for (int i = 0; i < al->size_y; i++)
        al->orim[i] = malloc(al->size_x + 1);
    if (!map)
        return 84;
    initialize();
    copy_map(map, al);
    save_o_pos(al, map);
    result = run_game(al, map);
    return result;
}

int process_input(int ac, char **av, struct stat *sb, char **buffer)
{
    if (is_not_file(ac, av) == 1)
        return 84;
    if (stat(av[1], sb) != -1) {
        lstat(av[1], sb);
        *buffer = malloc(sb->st_size + 1);
        if (!(*buffer)) {
            return 84;
        }
        return 0;
    }
    return 84;
}

int main(int ac, char **av)
{
    FILE *file = fopen(av[1], "r");
    all *al = malloc(sizeof(all));
    char *buffer = NULL;
    struct stat sb;
    int k = 0;
    char **map;

    if (ac == 2 && my_strcmp(av[1], "-h") == 0) {
        usages();
        return 0;
    }
    if (process_input(ac, av, &sb, &buffer) != 0)
        return 84;
    fread(buffer, sb.st_size, 1, file);
    calc_size((int)sb.st_size, buffer, al);
    map = convert_str(buffer, al);
    k = main_sec(al, map);
    endwin();
    return k;
}
