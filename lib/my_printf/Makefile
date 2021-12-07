##
## EPITECH PROJECT, 2021
## printf
## File description:
## Main kakefile
##

SRC	=	sources/convert.c	\
		sources/print_base.c	\
		sources/print_standard.c	\
		sources/utils.c	\
		sources/unsigned_o_u.c	\
		sources/print_pointeur.c	\
		sources/my_printf.c

OBJ	=	$(SRC:.c=.o)

NAME	=	libprintf.a

CFLAGS	=	-Wall -Wextra -Werror -Wshadow -Wimplicit -pedantic

CPPFLAGS	+=	-I./include/

all:	$(NAME)

$(NAME):	$(OBJ)
		mkdir -p ../../include
		ar rc ../$(NAME) $(OBJ)
		cp include/my_printf.h ../../include/my_printf.h
clean:
	rm -f $(OBJ)
	rm -f *.o
	rm -f *~
	rm -f vgcore*
	rm -f #*
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f ../$(NAME)
	rm -f ../../include/my_printf.h

my_tests: re tests_run cover

re:	fclean all

.PHONY: all clean fclean re
