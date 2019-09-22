##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Adrien Colombier
##

SRCS	=	source/Object.cpp 			\
			source/ObjectManager.cpp	\
			source/MapManager.cpp		\
			source/Cursor.cpp			\
			source/Bullet.cpp			\
			source/Tile.cpp				\
			source/Glow.cpp

OBJ	=	${SRCS:.cpp=.o}

NAME	=	libmerline.a

all:	${NAME}

$(NAME):	${OBJ}
	@ar rc ${NAME} ${OBJ}

clean:
	@rm -f ${OBJ}

fclean:	clean
	@rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
