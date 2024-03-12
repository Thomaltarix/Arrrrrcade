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
	make clean -C ./src/Games/

fclean: clean
	make fclean -C ./src/Core/
	make fclean -C ./src/Games/

re:	fclean all
