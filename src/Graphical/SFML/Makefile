##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Sfml Makefile
##

SRC			=	getInstance.cpp \
				SFML.cpp \

OBJ			= $(SRC:.cpp=.o)

NAME		= arcade_sfml.so

INCLUDE		=	-I../ -I../../include/
GRPHFLAGS	=	-lsfml-graphics
CXXFLAGS 	= 	-Werror -Wall -Wextra -g -rdynamic -std=c++20 $(GRPHFLAGS) \
				$(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -shared -o ../../../lib/$(NAME) -fPIC $(SRC) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../../lib/$(NAME)

re:	fclean all
