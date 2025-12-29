##
## EPITECH PROJECT, 2023
## Compile mylib
## File description:
## Makefile that compiles the lib
##

NAME	=	my_sokoban

SRCS	=	src/my_sokoban.c \
			src/my_strlen.c \
			src/is_not_file.c \
			src/move_plox.c \
			src/my_strcmp.c \
			src/usages.c \
			src/loose_win.c \
			src/save_pos.c \
			src/draw_copy_calc_map.c \
			src/my_putstr.c \
			src/my_putchar.c \

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
