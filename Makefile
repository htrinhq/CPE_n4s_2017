##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## makefile for tetris
##

SRC	=	source/main.c			\
		source/input.c			\
		source/utilities.c		\
		source/my_str_to_word_array.c	\
		source/change_dir.c		\
		source/simulation.c

OBJ	=	$(SRC:.c=.o)

NAME	=	ai

CFLAGS	=	-W -Wall -Wextra -I include

LDFLAGS	=


all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all

.PHONY: fclean clean all re
