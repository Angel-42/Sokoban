/*
** EPITECH PROJECT, 2023
** rush_1
** File description:
** On a un peu besoin d'un putchar dans sa vie non ?
*/

#include <unistd.h>
#include "../include/my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}
