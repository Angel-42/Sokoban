/*
** EPITECH PROJECT, 2023
** is_not_file
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

int is_file(char const *path)
{
    int fd = open(path, O_RDONLY);

    if (fd != -1) {
        close(fd);
        return 1;
    }
    return 0;
}

int check_file(char const *path)
{
    int fd = open(path, O_RDONLY);
    char buffer;
    int bytesRead = read(fd, &buffer, 1);

    if (bytesRead < 1)
        return 0;
    while (bytesRead > 0) {
        if (CONDITION(buffer)) {
            close(fd);
            return 0;
        }
        bytesRead = read(fd, &buffer, 1);
    }
    close(fd);
    return 1;
}

int is_not_file(int ac, char **av)
{
    if (ac != 2 || !is_file(av[1]) || !check_file(av[1]))
        return 1;
    return 0;
}
