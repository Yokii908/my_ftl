##
## Makefile for my_ftl in /Users/alexiscoquard/Documents/C/my_ftl
##
## Made by COQUARD Alexis
## Login   <coquar_a@etna-alternance.net>
##
## Started on  Thu Nov  9 17:23:06 2017 COQUARD Alexis
## Last update Thu Nov  9 17:23:06 2017 COQUARD Alexis
##

CC	=	gcc
CFLAGS	=	-W -Werror -Wall -Wextra -pedantic -std=gnu99
NAME	=	my_ftl
SRC	=	main.c			\
		air_shed.c		\
		my_string.c		\
		container.c     \
		bonus.c  		\
		system_control.c\
		system_repair.c \
		commands.c 		\
		game.c 			\
		sector.c 		\
		free.c 			\
		attack.c 		\
		detect.c
OBJ	=	$(SRC:%.c=%.o)
RM	=	rm -f

$(NAME):	$(OBJ)
			$(CC) $(OBJ) -o $(NAME)

all:		$(NAME)

clean:
			$(RM) $(OBJ)

fclean:		clean
			$(RM) $(NAME)
			$(RM) *~

re:			fclean all