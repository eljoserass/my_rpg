##
## EPITECH PROJECT, 2020
## makefile
## File description:
## compiles n stuff
##

CFLAGS		+=	-I./$(INCLUDE)
CFLAGS		+=	-g

rwildcard	=	$(foreach d,$(wildcard $(1:=/*)),$(call rwildcard,$d,$2) $(filter $(subst *,%,$2),$d))

TRASH		+=	*~
TRASH		+=	vgcore.*

INCLUDE		=	include/

SRCS		=	$(call rwildcard, ./src, *.c)

OBJ			=	$(SRCS:.c=.o)

NAME		=	my_rpg

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) -l csfml-window -l csfml-graphics -l csfml-system -l csfml-audio -lm

clean:
		rm -rf $(OBJ) $(TRASH)	$(addprefix $(SRC), $(TRASH))
		rm -rf $(addprefix $(INCLUDE), $(TRASH))

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
		make clean

.PHONY:		all clean fclean re
