##
## Makefile for AI in /u/epitech_2010s/candan_c/cu/rendu/c/zappy/clientAI
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Mon Jun  2 16:59:24 2008 caner candan
## Last update Mon Jun  2 17:09:56 2008 caner candan
##

NAME		=	AI

SRCS		=	main.cpp	\
			AI.cpp		\
			Socket.cpp

OBJS		=	$(SRCS:.cpp=.o)

CFLAGS		=	-W -Wall -Werror
LDFLAGS		=

CC		=	g++
RM		=	rm -f

$(NAME)		:	$(OBJS)
			$(CC) -o $@ $(OBJS) $(LDFLAGS)

all		:	$(NAME)

clean		:
			$(RM) *~
			$(RM) *.o
			$(RM) *.core

fclean		:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY		:	all clean fclean re
