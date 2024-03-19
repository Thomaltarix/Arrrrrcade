##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Sdl2 Makefile
##

SRC			= 	getInstance.cpp \
				sdl2.cpp \

OBJ			= $(SRC:.cpp=.o)

NAME		= arcade_sdl2.so

INCLUDE		=	-I../ -I../../include
GRPHFLAGS	=	-lSDL2 -lSDL2_image
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
