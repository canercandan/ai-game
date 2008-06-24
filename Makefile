##
## Makefile for make in /home/candan_c/cu/rendu/test/make
## 
## Made by caner candan
## Login   <candan_c@epitech.net>
## 
## Started on  Tue Apr 15 11:19:53 2008 caner candan
## Last update Tue Jun 24 14:14:49 2008 majdi toumi
##

NAME_SRV	=	server
NAME_OBS_2D	=	observator_2d
NAME_X		=	x
NAME_BIN	=	bin

PATH_SRV	=	$(NAME_SRV)/
PATH_OBS_2D	=	$(NAME_OBS_2D)/
PATH_X		=	$(NAME_X)/
PATH_BIN	=	$(NAME_BIN)/

BIN_SRV		=	$(PATH_BIN)$(NAME_SRV)
BIN_OBS_2D	=	$(PATH_BIN)$(NAME_OBS_2D)

SRCS_X		=	$(PATH_X)xaccept.c				\
			$(PATH_X)xbind.c				\
			$(PATH_X)xconnect.c				\
			$(PATH_X)xgethostbyname.c			\
			$(PATH_X)xlisten.c				\
			$(PATH_X)xmalloc.c				\
			$(PATH_X)xopen.c				\
			$(PATH_X)xclose.c				\
			$(PATH_X)xrecv.c				\
			$(PATH_X)xsend.c				\
			$(PATH_X)xsocket.c				\
			$(PATH_X)xfork.c

SRCS_SRV	=	$(PATH_SRV)main.c				\
			$(PATH_SRV)init.c				\
			$(PATH_SRV)parse_args.c				\
			$(PATH_SRV)is_options.c				\
			$(PATH_SRV)usage_server.c			\
			$(PATH_SRV)check_flag.c				\
			$(PATH_SRV)opt_port.c				\
			$(PATH_SRV)opt_width.c				\
			$(PATH_SRV)opt_lenght.c				\
			$(PATH_SRV)opt_nb_player.c			\
			$(PATH_SRV)opt_name_team.c			\
			$(PATH_SRV)opt_delay.c				\
			$(PATH_SRV)opt_help.c				\
			$(PATH_SRV)opt_life.c				\
			$(PATH_SRV)opt_coeff.c				\
			$(PATH_SRV)create_world.c			\
			$(PATH_SRV)fill_ressources_world.c		\
			$(PATH_SRV)dump_clients.c			\
			$(PATH_SRV)dump_ressources.c			\
			$(PATH_SRV)get_word_n.c				\
			$(PATH_SRV)execute_action.c			\
			$(PATH_SRV)scheduler_exec.c			\
			$(PATH_SRV)act_up.c				\
			$(PATH_SRV)act_right.c				\
			$(PATH_SRV)act_left.c				\
			$(PATH_SRV)act_see.c				\
			$(PATH_SRV)act_inventory.c			\
			$(PATH_SRV)act_take_obj.c			\
			$(PATH_SRV)act_bird.c				\
			$(PATH_SRV)act_drop_obj.c			\
			$(PATH_SRV)act_kick.c				\
			$(PATH_SRV)act_broadcast.c			\
			$(PATH_SRV)act_levelup.c			\
			$(PATH_SRV)act_levelup_progress.c		\
			$(PATH_SRV)act_fork.c				\
			$(PATH_SRV)act_count.c				\
			$(PATH_SRV)begin_session.c			\
			$(PATH_SRV)server_get.c				\
			$(PATH_SRV)server_read.c			\
			$(PATH_SRV)add_client.c				\
			$(PATH_SRV)add_server.c				\
			$(PATH_SRV)client_read.c			\
			$(PATH_SRV)client_write.c			\
			$(PATH_SRV)client_disconnect.c			\
			$(PATH_SRV)debug.c				\
			$(PATH_SRV)push_list.c				\
			$(PATH_SRV)pop_list.c				\
			$(PATH_SRV)pop_all_list.c			\
			$(PATH_SRV)rm_data_from_list.c			\
			$(PATH_SRV)rm_client_from_queue.c		\
			$(PATH_SRV)rm_ressource_from_list.c		\
			$(PATH_SRV)free_client.c			\
			$(PATH_SRV)get_client_from_list.c		\
			$(PATH_SRV)show_clients_from_list.c		\
			$(PATH_SRV)sort_queue_list.c			\
			$(PATH_SRV)count_list.c				\
			$(PATH_SRV)count_list_from_clients.c		\
			$(PATH_SRV)count_list_with_same_lvl.c		\
			$(PATH_SRV)count_list_with_same_team_n_lvl.c	\
			$(PATH_SRV)init_info.c				\
			$(PATH_SRV)create_new_queue.c			\
			$(PATH_SRV)send_info_to_obs.c			\
			$(PATH_SRV)free_info.c				\
			$(PATH_SRV)trim.c				\
			$(PATH_SRV)dump_client_position.c		\
			$(PATH_SRV)send_ressources.c			\
			$(PATH_SRV)send_len_ressources.c		\
			$(PATH_SRV)is_in_map.c				\
			$(PATH_SRV)get_x.c				\
			$(PATH_SRV)get_y.c				\
			$(PATH_SRV)init_random.c			\
			$(PATH_SRV)get_random.c				\
			$(PATH_SRV)exist_data_from_list.c		\
			$(PATH_SRV)get_disconnect_client_from_team.c	\
			$(PATH_SRV)get_ressource_idx.c			\
			$(PATH_SRV)calculate_timeout.c			\
			$(PATH_SRV)power.c				\
			$(PATH_SRV)square_root.c			\
			$(PATH_SRV)get_see_len.c			\
			$(PATH_SRV)move_up.c				\
			$(PATH_SRV)putnbr.c				\
			$(PATH_SRV)obs_send_action.c			\
			$(PATH_SRV)get_inventory.c			\
			$(PATH_SRV)get_inventory_id.c			\
			$(PATH_SRV)obs_new_client.c			\
			$(PATH_SRV)obs_send_new_item.c			\
			$(PATH_SRV)obs_add_client_in_char.c		\
			$(PATH_SRV)send_to_obs.c			\
			$(PATH_SRV)init_signal.c			\
			$(PATH_SRV)is_levelmax.c			\
			$(PATH_SRV)get_position_from_list.c		\
			$(PATH_SRV)check_death_clients.c

SRCS_OBS_2D	=	$(PATH_OBS_2D)main.c				\
			$(PATH_OBS_2D)init_info.c			\
			$(PATH_OBS_2D)destroy_info.c			\
			$(PATH_OBS_2D)init_signal.c			\
			$(PATH_OBS_2D)init_screen.c			\
			$(PATH_OBS_2D)load_image.c			\
			$(PATH_OBS_2D)create_video.c			\
			$(PATH_OBS_2D)loop_env.c			\
			$(PATH_OBS_2D)destroy_surface.c			\
			$(PATH_OBS_2D)destroy_screen.c			\
			$(PATH_OBS_2D)catch_keys.c			\
			$(PATH_OBS_2D)set_backdrop.c			\
			$(PATH_OBS_2D)set_object.c			\
			$(PATH_OBS_2D)push_list.c			\
			$(PATH_OBS_2D)pop_list.c			\
			$(PATH_OBS_2D)sort_client_list.c		\
			$(PATH_OBS_2D)create_socket.c			\
			$(PATH_OBS_2D)parse_args.c			\
			$(PATH_OBS_2D)init_gfx.c			\
			$(PATH_OBS_2D)destroy_gfx.c			\
			$(PATH_OBS_2D)get_header.c			\
			$(PATH_OBS_2D)create_client.c			\
			$(PATH_OBS_2D)add_client.c			\
			$(PATH_OBS_2D)get_trame.c			\
			$(PATH_OBS_2D)put_char_from_buf.c		\
			$(PATH_OBS_2D)put_int_from_buf.c		\
			$(PATH_OBS_2D)put_float_from_buf.c		\
			$(PATH_OBS_2D)skip_from_buf.c			\
			$(PATH_OBS_2D)execute_action.c			\
			$(PATH_OBS_2D)get_map_size.c			\
			$(PATH_OBS_2D)get_object.c			\
			$(PATH_OBS_2D)dump_clients.c			\
			$(PATH_OBS_2D)get_client_from_list.c		\
			$(PATH_OBS_2D)act_up.c				\
			$(PATH_OBS_2D)act_right.c			\
			$(PATH_OBS_2D)act_left.c			\
			$(PATH_OBS_2D)act_take_obj.c			\
			$(PATH_OBS_2D)act_drop_obj.c			\
			$(PATH_OBS_2D)act_kick.c			\
			$(PATH_OBS_2D)act_broadcast.c			\
			$(PATH_OBS_2D)act_levelup.c			\
			$(PATH_OBS_2D)act_levelup_progress.c		\
			$(PATH_OBS_2D)act_fork.c			\
			$(PATH_OBS_2D)act_count.c			\
			$(PATH_OBS_2D)act_bird.c			\
			$(PATH_OBS_2D)act_death.c			\
			$(PATH_OBS_2D)rm_data_from_list.c		\
			$(PATH_OBS_2D)draw_gfx.c			\
			$(PATH_OBS_2D)round_nbr.c

OBJS_X		=	$(SRCS_X:.c=.o)
OBJS_SRV	=	$(SRCS_SRV:.c=.o) $(OBJS_X)
OBJS_OBS_2D	=	$(SRCS_OBS_2D:.c=.o) $(OBJS_X)

INCLUDES	=	-I./include
LIBRARY		=	-L.

INCLUDES_OBS_2D	=	`pkg-config --cflags sdl`
LIBRARY_OBS_2D	=	`pkg-config --libs sdl`

DEBUG_42	=	-g
PANIC		=	-Wall -W -Werror -pedantic -ansi
MINOR		=	-Wall -Werror -pedantic -ansi

CFLAGS		=	$(INCLUDES) $(PANIC) $(DEBUG_$(DEBUG))
LDFLAGS		=	$(LIBRARY)

CFLAGS_OBS_2D	=	$(INCLUDES_OBS_2D)
LDFLAGS_OBS_2D	=	$(LIBRARY_OBS_2D)

CC		=	gcc
RM		=	rm -f
FIND		=	find . -name
FIND_RM		=	-exec rm {} \;
MK		=	make
MKD		=	mkdir -p

RM_O		=	$(FIND) '*.o' $(FIND_RM)
RM_TILD		=	$(FIND) '*~' $(FIND_RM)
RM_CORE		=	$(FIND) '*.core' $(FIND_RM)

KEY_VALUE	=	42

.SUFFIXES	:	.c.o

all		:
			@$(MKD) $(PATH_BIN)
			@$(MK) $(BIN_SRV)
			@if [ "$(OBS_2D)" = "$(KEY_VALUE)" ]; then	\
				$(MK) $(BIN_OBS_2D);			\
			fi

$(BIN_SRV)	:	$(OBJS_SRV)
			@$(MKD) $(PATH_SRV)
			$(CC) -o $@ $(OBJS_SRV) $(LDFLAGS)

$(BIN_OBS_2D)	:	$(OBJS_OBS_2D)
			@$(MKD) $(PATH_OBS_2D)
			@$(CC) $(CFLAGS_OBS_2D) -o $@ $(OBJS_OBS_2D) $(LDFLAGS) $(LDFLAGS_OBS_2D)

clean		:
			@$(RM_O)
			@$(RM_TILD)
			@$(RM_CORE)

fclean		:	clean
			$(RM) $(BIN_SRV)
			$(RM) $(BIN_OBS_2D)

re		:	fclean all

.PHONY		:	all clean fclean re

.c.o		:
			@if [ "$(OBS_2D)" = "$(KEY_VALUE)" ]; then			\
				$(CC) $(CFLAGS) $(CFLAGS_OBS_2D) -c $< -o $@;		\
				echo $(CC) $(CFLAGS) $(CFLAGS_OBS_2D) -c $< -o $@;	\
			else								\
				$(CC) $(CFLAGS) -c $< -o $@;				\
				echo $(CC) $(CFLAGS) -c $< -o $@;			\
			fi
