##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Centipede Makefile
##

SRC			=	centipede.cpp \
				../Sound.cpp \
				../Text.cpp \

OBJ			= $(SRC:.cpp=.o)

NAME		= arcade_centipede.so

INCLUDE		=	-I../ -I../../include/
CXXFLAGS 		= 	-Werror -Wall -Wextra -g -rdynamic -std=c++20

all: $(NAME)

$(NAME): $(OBJ)
	g++ -shared -o ../../../lib/$(NAME) -fPIC $(SRC) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../../lib/$(NAME)

re:	fclean all
