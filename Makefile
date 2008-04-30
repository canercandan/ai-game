##
## Makefile for make in /home/candan_c/cu/rendu/test/make
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 11:19:53 2008 caner candan
## Last update Wed Apr 30 18:18:02 2008 caner candan
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

SRCS_X		=	$(PATH_X)xaccept.c			\
			$(PATH_X)xbind.c			\
			$(PATH_X)xconnect.c			\
			$(PATH_X)xgethostbyname.c		\
			$(PATH_X)xlisten.c			\
			$(PATH_X)xmalloc.c			\
			$(PATH_X)xopen.c			\
			$(PATH_X)xclose.c			\
			$(PATH_X)xrecv.c			\
			$(PATH_X)xsend.c			\
			$(PATH_X)xsocket.c			\
			$(PATH_X)xfork.c

SRCS_SRV	=	$(PATH_SRV)main.c			\
			$(PATH_SRV)usage_server.c		\
			$(PATH_SRV)parse_args.c			\
			$(PATH_SRV)is_options.c			\
			$(PATH_SRV)check_flag.c			\
			$(PATH_SRV)opt_port.c			\
			$(PATH_SRV)opt_width.c			\
			$(PATH_SRV)opt_lenght.c			\
			$(PATH_SRV)opt_nb_player.c		\
			$(PATH_SRV)opt_name_team.c		\
			$(PATH_SRV)opt_delay.c			\
			$(PATH_SRV)create_world.c		\
			$(PATH_SRV)fill_ressources_world.c	\
			$(PATH_SRV)dump_world.c			\
			$(PATH_SRV)list_action.c		\
			$(PATH_SRV)get_word_n.c			\
			$(PATH_SRV)act_up.c			\
			$(PATH_SRV)act_right.c			\
			$(PATH_SRV)act_left.c			\
			$(PATH_SRV)act_see.c			\
			$(PATH_SRV)act_inventory.c		\
			$(PATH_SRV)act_take_obj.c		\
			$(PATH_SRV)act_drop_obj.c		\
			$(PATH_SRV)act_kick.c			\
			$(PATH_SRV)act_broadcast.c		\
			$(PATH_SRV)act_levelup.c		\
			$(PATH_SRV)act_fork.c			\
			$(PATH_SRV)server_get.c			\
			$(PATH_SRV)server_init.c		\
			$(PATH_SRV)server_read.c		\
			$(PATH_SRV)add_client.c			\
			$(PATH_SRV)add_server.c			\
			$(PATH_SRV)client_read.c		\
			$(PATH_SRV)debug.c			\
			$(PATH_SRV)push_list.c			\
			$(PATH_SRV)pop_list.c			\
			$(PATH_SRV)pop_all_list.c		\
			$(PATH_SRV)pop_client_from_list.c	\
			$(PATH_SRV)get_client_from_list.c	\
			$(PATH_SRV)show_clients_from_list.c	\
			$(PATH_SRV)count_list.c

SRCS_CLI	=	$(PATH_CLI)main.c			\
			$(PATH_CLI)enter_in_the_world.c		\
			$(PATH_CLI)new_connection.c		\
			$(PATH_CLI)print_usage.c		\
			$(PATH_CLI)check_response.c		\
			$(PATH_CLI)fork_in_the_word.c		\
			$(PATH_CLI)get_rnd_action.c

OBJS_X		=	$(SRCS_X:.c=.o)
OBJS_SRV	=	$(SRCS_SRV:.c=.o) $(OBJS_X)
OBJS_CLI	=	$(SRCS_CLI:.c=.o) $(OBJS_X)

INCLUDES	=	-I./include
LIBRARY		=	-L.

DEBUG		=	-g
PANIC		=	-Wall -W -Werror -pedantic -ansi

CFLAGS		=	$(INCLUDES) $(PANIC)
LDFLAGS		=	$(LIBRARY)

CC		=	gcc
RM		=	rm -rf
RM_O		=	find . -name '*.o' -exec rm {} \;
RM_TILD		=	find . -name '*~' -exec rm {} \;
RM_CORE		=	find . -name '*.core' -exec rm {} \;
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
			@$(CC) -o $@ $(OBJS_SRV) $(LDFLAGS)

$(BIN_CLI)	:	$(OBJS_CLI)
			@$(CC) -o $@ $(OBJS_CLI) $(LDFLAGS)

clean		:
			@$(RM_O)
			@$(RM_TILD)
			@$(RM_CORE)

fclean		:	clean
			$(RM) $(BIN_SRV)
			$(RM) $(BIN_CLI)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@
