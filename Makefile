##
## Makefile for make in /home/candan_c/cu/rendu/test/make
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 11:19:53 2008 caner candan
## Last update Tue Apr 15 15:00:21 2008 caner candan
##

NAME_SRV	=	server
NAME_CLI	=	client
NAME_X		=	x
NAME_BIN	=	bin
NAME_OBJ	=	obj

PATH_SRV	=	$(NAME_SRV)/
PATH_CLI	=	$(NAME_CLI)/
PATH_X		=	$(NAME_X)/
PATH_BIN	=	$(NAME_BIN)/
PATH_OBJ	=	$(NAME_OBJ)/

BIN_SRV		=	$(PATH_BIN)$(NAME_SRV)
BIN_CLI		=	$(PATH_BIN)$(NAME_CLI)

SRCS_SRV	=	$(PATH_SRV)main.c

SRCS_CLI	=	$(PATH_CLI)main.c

OBJS_SRV	=	$(SRCS_SRV:.c=.o)
OBJS_CLI	=	$(SRCS_CLI:.c=.o)

INCLUDES	=	-I.
LIBRARY		=	-L.

CFLAGS		=	$(INCLUDES) -g -Wall -W -Werror -pedantic -ansi
LDFLAGS		=	$(LIBRARY)

CC		=	gcc
RM		=	rm -rf
MK		=	make
MKD		=	mkdir -p

.SUFFIXES	:	.c.o

all		:
			@$(MKD) $(PATH_SRV)
			@$(MKD) $(PATH_CLI)
			@$(MKD) $(PATH_BIN)
			@$(MK) $(BIN_SRV)
			@$(MK) $(BIN_CLI)

$(BIN_SRV)	:	$(OBJS_SRV)
			$(CC) -o $@ $(OBJS_SRV) $(LDFLAGS)

$(BIN_CLI)	:	$(OBJS_CLI)
			$(CC) -o $@ $(OBJS_CLI) $(LDFLAGS)

clean		:
			$(RM) *~
			$(RM) *.o
			$(RM) *.core

fclean		:	clean
			$(RM) $(BIN_SRV)
			$(RM) $(BIN_CLI)
			$(RM) $(PATH_BIN)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@ $(LDFLAGS)
