##
## Makefile for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
## 
## Made by majdi toumi
## Login   <toumi_m@epitech.net>
## 
## Started on  Thu Apr 10 08:41:58 2008 majdi toumi
## Last update Thu Apr 10 08:49:04 2008 majdi toumi
##

CC		=	/usr/bin/gcc

NAME_SRV	=	server
SRC_SRV		=	server.c
OBJ_SRV		=	$(SRC:.c=.o)

INCLUDES	=	-I.

LIBRARIES	=	-L.

WARNING		=	-Wall
DEBUG		=	-g

CFLAGS		=	$(INCLUDES) $(DEBUG) $(WARNING)
LDFLAGS		=	$(LIBRARIES)

RM		=	rm -rf
TAR		=	tar -cvf

$(NAME_SRV)	:	$(OBJ_SRV)
			$(CC) -o $(NAME_SRV) $(OBJ_SRV) $(LD_FLAGS)

all		:	$(NAME_SRV)

clean		:
			$(RM) *.o *.core

fclean		:	clean
			$(RM) $(NAME_SRV)

rclean		:	fclean
			$(RM) *~ \#*\#

re		:	fclean all

tar		:
			$(TAR) $(NAME_SRV).tar *

.PHONY		:	all clean fclean rclean re tar
