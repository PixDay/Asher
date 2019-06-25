##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Adrien Colombier
##

SRCS	=	source/ObjectManager.cpp	

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
