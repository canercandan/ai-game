/*
** observator_2d.h for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:25:12 2008 caner candan
** Last update Tue May 13 21:48:34 2008 caner candan
*/

#ifndef __OBSERVATOR_2D_H__
# define __OBSERVATOR_2D_H__

/*
** Useful's defines
*/
# define DELIMIT	" \n"
# define BUF_SIZE	1024

/*
** SDL's defines
*/
# define SCREEN_X	640
# define SCREEN_Y	480
# define DELAY		50
# define DELAY_ANIM	20
# define UNIT_X		5
# define UNIT_Y		5

/*
** Server's infos
*/
# define MSG_WELCOME	"BIENVENUE\n"
# define ADD_CLIENT	"ADD_CLIENT"
# define NB_INVENTORY		7

/*
** Backdrop's infos
*/
# define BACKDROP_FILE	"images/arena.bmp"

/*
** Character's infos
*/
# define CHARACTER_FILE		"images/bibi.bmp"
# define CHARACTER_MAX_PER_LINE	4
# define CHARACTER_X		32
# define CHARACTER_Y		48

/*
** Status' infos
*/
# define STATUS_FILE		"images/status.bmp"
# define STATUS_MAX_PER_LINE	5
# define STATUS_X		17
# define STATUS_Y		17

/*
** Floor's infos
*/
# define FLOOR_FILE		"images/floor.bmp"
# define FLOOR_MAX_PER_LINE	4
# define FLOOR_X		32
# define FLOOR_Y		32

/*
** Null's define
*/
# ifndef NULL
#  define NULL	((void *) 0)
# endif /* !NULL */

/*
** SDL's macros
*/
# define SDL_SF(data)	((SDL_Surface *) (data))
# define SDL_VI(data)	((SDL_VideoInfo *) (data))

/*
** Position's macros
*/
# define GET_POSITION_X(nbr, max)	((nbr) % (max))
# define GET_POSITION_Y(nbr, max)	((nbr) / (max))

/*
** Get character's axes
*/
# define GET_CHAR_X(w, x)	((w) - (UNIT_X * (x)) - (CHARACTER_X / 2))
# define GET_CHAR_Y(h, y)	((h) - (UNIT_Y * (y)) - (CHARACTER_Y / 2))

/*
** Macros of cast
*/
# define INFO(data)		((t_info *) (data))
# define GFX(data)		((t_gfx *) (data))
# define CLIENT(data)		((t_client *) (data))
# define INVENTORY(data)	((t_inventory *) (data))
# define TIMEVAL(data)		((struct timeval *) (data))

/*
** Gerneric list of list chaine
*/
typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

/*
** Clients' structure
*/
typedef struct	s_client
{
  int		socket;
  char		*team_name;
  int		level;
  int		x;
  int		y;
  int		direction;
  t_list	*inventory;
}		t_client;

/*
** Infos' structure
*/
typedef struct	s_info
{
  int		x;
  int		y;
  int		socket;
  char		buf[BUF_SIZE];
  void		*timeout;
  char		*host;
  int		port;
  t_list	*clients;
}		t_info;

/*
** Inventory's structure
*/
typedef struct	s_inventory
{
  int		idx;
  int		qte;
}		t_inventory;

/*
** Actions table's structure
*/
typedef struct	s_actions
{
  int		idx;
  int		(*f)();
}		t_actions;

/*
** GFX's structure
*/
typedef struct	s_gfx
{
  void		*video;
  void		*infos;
  void		*character;
  void		*status;
  void		*floor;
}		t_gfx;

/*
** Useful's functions
*/
int	init_info(t_info *info);
void	destroy_info(t_info *info);
void	init_signal(t_info *info, t_gfx *gfx);
int	parse_args(int ac, char **av, t_info *info);
int	create_socket(t_info *info);
int	get_header(t_info *info);
int	get_trame(t_info *info, t_gfx *gfx);
void	get_map_size(t_info *info, t_gfx *gfx, char **buf, char *first);

/*
** Client's functions
*/
void	create_client(t_info *info, char **buf);
void	dump_clients(t_info *info);
void	*get_client_from_list(t_list *t, int socket);

/*
** Actions' functions
*/
void	execute_action(t_info *info, char **buf, char *first);
int	act_up(t_info *info, t_client *client, char *param);
int	act_right(t_info *info, t_client *client, char *param);
int	act_left(t_info *info, t_client *client, char *param);
int	act_take_obj(t_info *info, t_client *client, char *param);
int	act_drop_obj(t_info *info, t_client *client, char *param);
int	act_kick(t_info *info, t_client *client, char *param);
int	act_broadcast(t_info *info, t_client *client, char *param);
int	act_levelup(t_info *info, t_client *client, char *param);
int	act_fork(t_info *info, t_client *client, char *param);
int	act_count(t_info *info, t_client *client, char *param);
int	act_bird(t_info *info, t_client *client, char *param);
int	act_death(t_info *info, t_client *client, char *param);

/*
** GFX's functions
*/
int	init_gfx(t_gfx *gfx);
void	destroy_gfx(t_gfx *gfx);
int	init_screen(void);
int	create_video(t_info *info, t_gfx *gfx);
void	*load_image(char *path);
int	loop_env(t_info *info, t_gfx *gfx);
void	destroy_surface(void *surface);
void	destroy_screen(void);
int	catch_keys(void);
void	set_backdrop(t_info *info, t_gfx *gfx);
void	set_character(t_gfx *gfx, int nbr, int x, int y);
void	set_status(t_gfx *gfx, int nbr, int x, int y);
void	set_floor(t_gfx *gfx, int nbr, int x, int y);

/*
** List chaine's functions
*/
void	push_list(t_list **t, void *data);
void	*pop_list(t_list **t);
void	*rm_data_from_list(t_list **t, void *data);

/*
** Buffer's functions
*/
void	put_char_from_buf(char **elm, char **buf);
void	put_int_from_buf(int *elm, char **buf);

#endif /* !__OBSERVATOR_2D_H__ */