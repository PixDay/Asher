##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Adrien Colombier
##

CC	=	g++

SRC	=	sources/Main.cpp		\
		sources/Player.cpp		\
		sources/Menu.cpp		\
		sources/Option.cpp		\
		sources/Skin.cpp		\
		sources/Friend.cpp		\
		sources/Ennemy.cpp

OBJECTS =	${SRC:.cpp=.o}

NAME	=	Asher

CFLAGS	=	-Wall -Wextra -pedantic -Ofast -I ./include

LDFLAGS	=	-lsfml-window -lsfml-system -lsfml-graphics -lsfml-audio -L./library -lmerline

all:	${NAME}

%.o:	%.cpp
	@echo -e "\e[0;94mCompiled\t\e[0;95m$<\e[39m -> \e[38;5;208m$@\e[39m"
	@${CC} -c ${CFLAGS} $< -o $@

${NAME}:	${OBJECTS}
	@make -C library/ --no-print-directory
	@echo -e "\e[0;38;5;208mLibrary\t\t\e[0;92mBuild\e[39m"
	@${CC} -o ${NAME} ${OBJECTS} ${LDFLAGS}
	@echo -e "\e[0;92mDone ${NAME}\e[0m"

clean:
	@rm -f ${OBJECTS}
	@echo -e "\e[38;5;208mObjects:\e[38;5;124m\tDeleted\e[0m"

fclean:	clean
	@rm -f ${NAME}
	@echo -e "\e[0;92mExecutable:\e[38;5;124m\tDeleted\e[0m"
	@make fclean -C library/ --no-print-directory
	@echo -e "\e[0;92mLibrary:\e[38;5;124m\tDeleted\e[0m"

re:	fclean all

.PHONY:	all clean fclean re
