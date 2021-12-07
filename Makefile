##
## EPITECH PROJECT, 2021
## my hunter
## File description:
## Main kakefile
##

SRC	=	src/main.c	\
		src/setup.c	\
		src/window.c	\
		src/game_elements.c	\
		src/cat_animator.c	\
		src/destroyer.c	\
		src/utils.c	\
		src/player_event.c	\
		src/event.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

#CFLAGS	=	-Wall -Wextra ## -Werror
#CFLAGS	+=	-Wshadow -Wimplicit -pedantic

LDFLAGS	=	-lcsfml-graphics -lcsfml-system

CPPFLAGS	+=	-L./lib -lprintf
CPPFLAGS	+=	-L./lib -lmy
CPPFLAGS	+=	-I./include/
CPPFLAGS	+=	-O2

all:	$(NAME)

lib:
	make -C ./lib/my
	make -C ./lib/my_printf

$(NAME):	lib	$(OBJ)
		gcc $(OBJ) -o $(NAME) -ggdb3 $(LDFLAGS) $(CPPFLAGS)
		rm -f $(OBJ)

debug:	$(OBJ)
		gcc $(OBJ) -o $(NAME) -ggdb3 $(LDFLAGS) -g

tests_run:	lib
	@gcc -o unit_tests $(SRC) tests/*.c $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) --coverage -lcriterion
	@-./unit_tests
	@rm unit_tests

cover:
	@mkdir -p criterions_r
	@gcovr --exclude tests/ --html --html-details -o criterions_r/cover.html
	@gcovr --branches --exclude tests/
	@make -C ./ clean

clean:
	make -C ./lib/my_printf clean
	make -C ./lib/my clean
	@find . -type f | xargs touch
	rm -f $(OBJ)
	@rm -f *.o
	@rm -f *~
	@rm -f vgcore*
	@rm -f #*
	@rm -f *.gcda
	@rm -f *.gcno

fclean:	clean
	make -C ./lib/my_printf fclean
	make -C ./lib/my fclean
	rm -f $(NAME)
	@rm -f criterions_r/*.html
	@rm -f criterions_r/*.css
	@rm -rf criterions_r/

my_tests: tests_run cover

re:	fclean all

.PHONY: all clean fclean re tests_run cover lib
