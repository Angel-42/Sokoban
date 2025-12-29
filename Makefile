##
## EPITECH PROJECT, 2023
## Compile mylib
## File description:
## Makefile that compiles the lib
##

NAME	=	my_sokoban

SRCS	=	my_sokoban.c \
			my_strlen.c \
			is_not_file.c \
			move_plox.c \
			my_strcmp.c \
			usages.c \
			loose_win.c \
			save_pos.c \
			draw_copy_calc_map.c \
			my_putstr.c \
			my_putchar.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-Werror -Wall -Wextra

LDFLAGS	=	-lncurses -lcurses

all:	$(NAME)

$(NAME):$(OBJS)
	$(CC) -o $(NAME) $(OBJS) $(LDFLAGS)

clean:
	rm -f $(OBJS)
	rm -f *~

fclean:	clean
	rm -f $(NAME_TEST)
	rm -f $(NAME)

re:	fclean all
