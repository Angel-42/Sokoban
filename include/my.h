/*
** EPITECH PROJECT, 2023
** Day09-task01
** File description:
** my_h
*/

#include <stdbool.h>
#pragma once
#define SUIVANT(a) (a == ' ' || a == 'O')
#define LIBRE(a) (SUIVANT(a) || 'X')
#define SUITE(a) (a != '#' && a != 'P' && a != '\n')
#define CONDITION(a) (a != ' ' && a != 'X' && a != 'O' && SUITE(a))
#define MOUV(a, b) (a == 'X' && (b == ' ' || b == 'O'))
#define UP(a) (map[al->x_pos[a].x_y - 1][al->x_pos[a].x_x])
#define UP_UP(a) ((UP(a) == '#' || UP(a) == 'X'))
#define DOWN(a) (map[al->x_pos[a].x_y + 1][al->x_pos[a].x_x])
#define DOWN_DOWN(a) ((DOWN(a) == '#' || DOWN(a) == 'X'))
#define RIGHT(a) (map[al->x_pos[a].x_y][al->x_pos[a].x_x + 1])
#define RIGHT_RIGHT(a) ((RIGHT(a) == '#' || RIGHT(a) == 'X'))
#define LEFT(a) (map[al->x_pos[a].x_y][al->x_pos[a].x_x - 1])
#define LEFT_LEFT(a) ((LEFT(a) == '#' || LEFT(a) == 'X'))
#define UP2 map[al->p_y - 1][al->p_x]
#define DOWN2 map[al->p_y + 1][al->p_x]
#define RIGHT2 map[al->p_y][al->p_x + 1]
#define LEFT2 map[al->p_y][al->p_x - 1]

typedef struct {
    int o_x;
    int o_y;
} base_o;

typedef struct {
    int x_y;
    int x_x;
} base_x;

typedef struct {
    int p_x;
    int p_y;
    int rows;
    int cols;
    int size_y;
    int size_x;
    int size;
    char **orim;
    char **av;
    int cpt_o;
    char *l_o;
    base_o *o_pos;
    int cpt_x;
    char *l_x;
    base_x *x_pos;
} all;

int main(int ac, char **av);
int my_strlen(char const *str);
int my_strcmp(char const *s1, char const *s2);
void usages(void);
void move_plox(all *al, char **map);
int calc_size(int size, const char *buffer, all *al);
void draw_map(char **map, all *al);
void copy_map(char **original, all *al);
void save_o_pos(all *al, char **map);
void save_x_pos(all *al, char **map);
int is_not_file(int ac, char **av);
bool check_win(all *al, char **map);
bool check_loose(all *al, char **map);
int my_putstr(char const *str);
void my_putchar(char c);
