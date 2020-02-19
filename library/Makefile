##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Adrien Colombier
##

CC 		=	g++

SRCS	=	source/Object.cpp 			\
			source/ObjectManager.cpp	\
			source/MapManager.cpp		\
			source/Cursor.cpp			\
			source/Bullet.cpp			\
			source/Tile.cpp				\
			source/Glow.cpp				\
			source/BlackHole.cpp		\
			source/Button.cpp			\
			source/Icon.cpp				\
			source/Text.cpp				\
			source/FakeBullet.cpp		\
			source/Star.cpp

OBJ	=	${SRCS:.cpp=.o}

%.o:	%.cpp
	@echo -e "\e[0;94mCompiled\t\e[0;95m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@${CC} -c $< -o $@
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
