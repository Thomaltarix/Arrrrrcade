##
## EPITECH PROJECT, 2024
## Arcade
## File description:
## Makefile
##

NAME	= arcade

all: $(NAME)

$(NAME): core games graphicals

core:
	make -C ./src/Core/

games:
	make -C ./src/Games/

graphicals:
	make -C ./src/Graphical/

clean:
	make clean -C ./src/Core/
	make clean -C ./src/Games/
	make clean -C ./src/Graphical/

fclean: clean
	make fclean -C ./src/Core/
	make fclean -C ./src/Games/
	make fclean -C ./src/Graphical/

re:	fclean all
