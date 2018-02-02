##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile for the unit tests
##

SRC	=	test.c	\
		../get_next_line.c	\

OBJ	=	$(SRC:.c=.o)

FLAGS	=	-lcriterion

NAME	=	test

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc $(OBJ) $(FLAGS) -o $(NAME)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
