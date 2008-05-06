##
## Makefile for make in /home/candan_c/cu/rendu/test/make
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 11:19:53 2008 caner candan
## Last update Tue May  6 17:35:07 2008 jordan aubry
##

NAME_SRV	=	server
NAME_CLI	=	client
NAME_OBS	=	observator
NAME_X		=	x
NAME_BIN	=	bin

PATH_SRV	=	$(NAME_SRV)/
PATH_CLI	=	$(NAME_CLI)/
PATH_OBS	=	$(NAME_OBS)/
PATH_X		=	$(NAME_X)/
PATH_BIN	=	$(NAME_BIN)/

BIN_SRV		=	$(PATH_BIN)$(NAME_SRV)
BIN_CLI		=	$(PATH_BIN)$(NAME_CLI)
BIN_OBS		=	$(PATH_BIN)$(NAME_OBS)

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
			$(PATH_SRV)options.c			\
			$(PATH_SRV)check_flag.c			\
			$(PATH_SRV)opt_port.c			\
			$(PATH_SRV)opt_width.c			\
			$(PATH_SRV)opt_lenght.c			\
			$(PATH_SRV)opt_nb_player.c		\
			$(PATH_SRV)opt_name_team.c		\
			$(PATH_SRV)opt_delay.c			\
			$(PATH_SRV)create_world.c		\
			$(PATH_SRV)fill_ressources_world.c	\
			$(PATH_SRV)generate_ressources.c	\
			$(PATH_SRV)dump_world.c			\
			$(PATH_SRV)dump_clients.c		\
			$(PATH_SRV)dump_ressources.c		\
			$(PATH_SRV)get_word_n.c			\
			$(PATH_SRV)execute_action.c		\
			$(PATH_SRV)scheduler_exec.c		\
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
			$(PATH_SRV)begin_session.c		\
			$(PATH_SRV)server_get.c			\
			$(PATH_SRV)server_read.c		\
			$(PATH_SRV)server_write.c		\
			$(PATH_SRV)add_client.c			\
			$(PATH_SRV)add_server.c			\
			$(PATH_SRV)client_read.c		\
			$(PATH_SRV)client_write.c		\
			$(PATH_SRV)client_disconnect.c		\
			$(PATH_SRV)debug.c			\
			$(PATH_SRV)push_list.c			\
			$(PATH_SRV)pop_list.c			\
			$(PATH_SRV)pop_all_list.c		\
			$(PATH_SRV)rm_data_from_list.c		\
			$(PATH_SRV)rm_client_from_queue.c	\
			$(PATH_SRV)free_client.c		\
			$(PATH_SRV)get_client_from_list.c	\
			$(PATH_SRV)show_clients_from_list.c	\
			$(PATH_SRV)sort_queue_list.c		\
			$(PATH_SRV)count_list.c			\
			$(PATH_SRV)init_info.c			\
			$(PATH_SRV)create_new_queue.c		\
			$(PATH_SRV)send_info_to_obs.c		\
			$(PATH_SRV)free_info.c			\
			$(PATH_SRV)trim.c			\
			$(PATH_SRV)dump_client_position.c	\
			$(PATH_SRV)init_random.c		\
			$(PATH_SRV)get_random.c			\
			$(PATH_SRV)send_buf_to_client.c		\
			$(PATH_SRV)is_levelup.c			\
			$(PATH_SRV)exist_data_from_list.c	\
			$(PATH_SRV)get_ressource_idx.c		\
			$(PATH_SRV)calculate_timeout.c

SRCS_CLI	=	$(PATH_CLI)main.c			\
			$(PATH_CLI)enter_in_the_world.c		\
			$(PATH_CLI)new_connection.c		\
			$(PATH_CLI)print_usage.c		\
			$(PATH_CLI)check_response.c		\
			$(PATH_CLI)fork_in_the_word.c		\
			$(PATH_CLI)get_rnd_action.c

SRCS_OBS	=	$(PATH_OBS)main.cpp			\
			$(PATH_OBS)main_usage.cpp		\
			$(PATH_OBS)init_obs.cpp			\
			$(PATH_OBS)init_window.cpp		\
			$(PATH_OBS)init_socket.cpp		\
			$(PATH_OBS)init_matrix.cpp		\
			$(PATH_OBS)init_map_size.cpp		\
			$(PATH_OBS)init_case.cpp		\
			$(PATH_OBS)draw_all.cpp			\
			$(PATH_OBS)draw_rock.cpp		\
			$(PATH_OBS)extract_num.cpp		\
			$(PATH_OBS)free_obs.cpp			\
			$(PATH_OBS)msg_reception.cpp

OBJS_X		=	$(SRCS_X:.c=.o)
OBJS_SRV	=	$(SRCS_SRV:.c=.o) $(OBJS_X)
OBJS_CLI	=	$(SRCS_CLI:.c=.o) $(OBJS_X)
OBJS_OBS	=	$(SRCS_OBS:.cpp=.o) $(OBJS_X)

INCLUDES	=	-I./include
LIBRARY		=	-L.

INCLUDES_OBS	=	-I/usr/local/include/irrlicht -I/usr/X11R6/include
LIBRARY_OBS	=	-L/usr/X11R6/lib -L/usr/local/lib 		\
			-lGL -lGLU -lXxf86vm -lXext -lX11 -lpng -ljpeg	\
			-lIrrlicht

DEBUG		=	-g
PANIC		=	-Wall -W -Werror -pedantic -ansi
MINOR		=	-Wall -Werror -pedantic -ansi

CFLAGS		=	$(INCLUDES) $(PANIC) $(DEBUG)
LDFLAGS		=	$(LIBRARY)

CFLAGS_OBS	=	$(INCLUDES) $(INCLUDES_OBS) $(MINOR)
LDFLAGS_OBS	=	$(LIBRARY) $(LIBRARY_OBS)

CC		=	gcc
RM		=	rm -f
RM_O		=	find . -name '*.o' -exec rm {} \;
RM_TILD		=	find . -name '*~' -exec rm {} \;
RM_CORE		=	find . -name '*.core' -exec rm {} \;
MK		=	make
MKD		=	mkdir -p

.SUFFIXES	:	.c.o
.SUFFIXES	:	.cpp.o

all		:
			@$(MKD) $(PATH_BIN)
			@$(MK) $(BIN_SRV)
			@$(MK) $(BIN_CLI)

$(BIN_SRV)	:	$(OBJS_SRV)
			@$(MKD) $(PATH_SRV)
			@$(CC) -o $@ $(OBJS_SRV) $(LDFLAGS)

$(BIN_CLI)	:	$(OBJS_CLI)
			@$(MKD) $(PATH_CLI)
			@$(CC) -o $@ $(OBJS_CLI) $(LDFLAGS)

$(BIN_OBS)	:	$(OBJS_OBS)
			@$(MKD) $(PATH_OBS)
			@$(CC) $(CFLAGS_OBS) -o $@ $(OBJS_OBS) $(LDFLAGS_OBS)

obs		:	$(BIN_OBS)

clean		:
			@$(RM_O)
			@$(RM_TILD)
			@$(RM_CORE)

fclean		:	clean
			$(RM) $(BIN_SRV)
			$(RM) $(BIN_CLI)
			$(RM) $(BIN_OBS)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			$(CC) $(CFLAGS) -c $< -o $@

.cpp.o		:
			$(CC) $(CFLAGS_OBS) -c $< -o $@
