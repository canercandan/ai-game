##
## Makefile for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
## 
## Made by majdi toumi
## Login   <toumi_m@epitech.net>
## 
## Started on  Thu Apr 10 08:41:58 2008 majdi toumi
## Last update Thu Apr 10 18:50:47 2008 majdi toumi
##

CC		=	/usr/bin/gcc

NAME_SRV	=	server
SRC_SRV		=	server.c		\
			usage.c			\
			parse_args.c		\
			is_options.c		\
			check_flag.c		\
			opt_port.c		\
			opt_width.c		\
			opt_lenght.c		\
			opt_nb_player.c		\
			opt_name_team.c		\
			opt_delay.c		\
			get_options.c		\
			create_zone.c		\
			fill_ressources_zone.c

OBJ_SRV		=	$(SRC_SRV:.c=.o)

SRC		=	xmalloc.c
OBJ		=	$(SRC:.c=.o)

INCLUDES	=	-I.

LIBRARIES	=	-L.

WARNING		=	-Wall
DEBUG		=	-g

CFLAGS		=	$(INCLUDES) $(DEBUG) $(WARNING)
LDFLAGS		=	$(LIBRARIES)

RM		=	rm -rf
TAR		=	tar -cvf

all		:	$(NAME_SRV)

$(NAME_SRV)	:	$(OBJ_SRV) $(OBJ)
			$(CC) -o $(NAME_SRV) $(OBJ_SRV) $(OBJ) $(LD_FLAGS)

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
