##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME	= arcade

all: $(NAME)

$(NAME): core

core:
	make -C ./src/Core/

games:
	make -C ./src/Games/

graphicals:

clean:
	make clean -C ./src/Core/

fclean: clean
	make fclean -C ./src/Core/

re:	fclean all
