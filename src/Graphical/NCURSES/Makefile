##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Ncurses Makefile
##

SRC			= ncurses.cpp \

OBJ			= $(SRC:.cpp=.o)

NAME		= arcade_ncurses.so

GRPHFLAGS	=	-lncurses
CXXFLAGS 	= 	-Werror -Wall -Wextra -g -rdynamic -std=c++20 $(GRPHFLAGS)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -shared -o ../../../lib/$(NAME) -fPIC $(SRC) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../../lib/$(NAME)

re:	fclean all
