##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Core Makefile
##

MAIN 		= main.cpp \

SRC			= 	DLLoader.cpp \
				Core.cpp \

OBJ			= $(SRC:.cpp=.o)

MAIN_OBJ	= $(MAIN:.cpp=.o)

NAME		= arcade

INCLUDE		= -I../include
DLFLAG		= -fno-gnu-unique
CXXFLAGS 	= -std=c++20 -Wall -Wextra -Werror -g $(DLFLAG) $(INCLUDE)

all: $(NAME)

$(NAME): $(OBJ) $(MAIN_OBJ)
	g++ $(MAIN_OBJ) $(OBJ) -o $(NAME) $(CXXFLAGS)
	mv $(NAME) ../../$(NAME)

clean:
	rm -f $(MAIN_OBJ)
	rm -f $(OBJ)

fclean: clean
	rm -f ../../$(NAME)

re:	fclean all
