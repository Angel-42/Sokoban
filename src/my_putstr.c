/*
** EPITECH PROJECT, 2023
** Day04-Task02
** File description:
** Task02-my_putstr
*/

#include "../include/my.h"

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
