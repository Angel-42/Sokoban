/*
** EPITECH PROJECT, 2023
** Day04-Task03
** File description:
** Task03-my_strlen
*/

#include "../include/my.h"

int my_strlen(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i = i + 1;
    }
    return i;
}
