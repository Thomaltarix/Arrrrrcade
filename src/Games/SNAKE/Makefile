##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Snake Makefile
##

SRC			=	Snake.cpp \
				getInstance.cpp \
				SnakePlayer.cpp \
				SnakeEntity.cpp \
				../Sound.cpp \
				../Text.cpp \
				../AEntity.cpp \
				../APlayer.cpp \

OBJ			= $(SRC:.cpp=.o)

NAME		= arcade_snake.so

INCLUDE		=	-I../ -I../../include/
CXXFLAGS 		= 	-Werror -Wall -Wextra -g -rdynamic -std=c++20 $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ)
	g++ -shared -o ../../../lib/$(NAME) -fPIC $(SRC) $(CXXFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../../../lib/$(NAME)

re:	fclean all
