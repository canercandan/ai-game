/*
** observator_2d.h for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:25:12 2008 caner candan
** Last update Tue Jun 24 13:56:01 2008 caner candan
*/

#ifndef __OBSERVATOR_2D_H__
# define __OBSERVATOR_2D_H__

/*
** Useful's defines
*/
# define DELIMIT	" \n"
# define BUF_SIZE	1024 * 16

/*
** SDL's defines
*/
# define SCREEN_X	640
# define SCREEN_Y	480
# define DELAY		50
# define DELAY_ANIM	20
# define UNIT_X		5.0
# define UNIT_Y		5.0
# define TITLE		"OBS 2D !!!"
# define NB_GFX		9
# define NB_CHARACTER	5
# define FLOOR_X	32
# define FLOOR_Y	32

/*
** Server's infos
*/
# define MSG_WELCOME	"BIENVENUE\n"
# define ADD_CLIENT	"ADD_CLIENT"
# define BROADCAST_MESG	"message"
# define NB_OBJECT	8

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
** Gfx objects
*/
enum
  {
    FLOOR,
    STATUS,
    OBJECT,
    BIBI,
    PIRATE,
    FENIX,
    CHICKEN,
    KUIPOU,
    EGG
  };

/*
** Gerneric list of list chaine
*/
typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

/*
** Inventory's structure
*/
typedef struct	s_inventory
{
  int		idx;
  int		qte;
}		t_inventory;

/*
** Clients' structure
*/
typedef struct	s_client
{
  int		id;
  char		*team_name;
  int		team_id;
  int		level;
  float		x;
  float		y;
  int		direction;
  int		anim;
  int		inventory[NB_OBJECT];
}		t_client;

/*
** GFX's structure
*/
typedef struct	s_gfx
{
  void		*video;
  void		*infos;
  void		*object[NB_GFX];
}		t_gfx;

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
  t_gfx		*gfx;
  float		time;
  int		(**object)[NB_OBJECT];
  int		**status;
}		t_info;

/*
** Actions table's structure
*/
typedef struct	s_actions
{
  int		idx;
  int		(*f)();
}		t_actions;

/*
** Object's infos
*/
typedef struct	s_object
{
  char		*path;
  int		max_per_line;
  int		size_x;
  int		size_y;
  int		padding_x;
  int		padding_y;
  int		r;
  int		g;
  int		b;
}		t_object;

typedef struct	s_param
{
  int		gfx;
  float		x;
  float		y;
  int		anim;
}		t_param;

/*
** Useful's functions
*/
int	init_info(t_info *info, t_gfx *gfx);
void	destroy_info(t_info *info);
void	init_signal(t_info *info);
int	parse_args(int ac, char **av, t_info *info);
int	create_socket(t_info *info);
int	get_header(t_info *info);
int	get_trame(t_info *info);
void	get_map_size(t_info *info, char **buf, char *first);
int	get_object(t_info *info, char **buf);

/*
** Client's functions
*/
int	create_client(t_info *info, char **buf);
void	add_client(t_info *info, char **buf);
void	dump_clients(t_info *info);
void	*get_client_from_list(t_list *t, int socket);

/*
** Actions' functions
*/
int	move_up(t_client *client, char direction, t_info *info);
void	execute_action(t_info *info, char **buf, char *first);
int	act_up(t_info *info, t_client *client, char *param);
int	act_right(t_info *info, t_client *client, char *param);
int	act_left(t_info *info, t_client *client, char *param);
int	act_take_obj(t_info *info, t_client *client, char *param);
int	act_drop_obj(t_info *info, t_client *client, char *param);
int	act_kick(t_info *info, t_client *client, char *param);
int	act_broadcast(t_info *info, t_client *client, char *param);
int	act_levelup(t_info *info, t_client *client, char *param);
int	act_levelup_progress(t_info *info, t_client *client,
			     char *param);
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
int	create_video(t_info *info);
void	*load_image(char *path);
int	loop_env(t_info *info);
void	destroy_surface(void *surface);
void	destroy_screen(void);
int	catch_keys(void);
void	set_backdrop(t_info *info);
void	set_object(t_gfx *gfx, t_param *p);
int	draw_gfx(t_info *info, int anim);

/*
** List chaine's functions
*/
void	push_list(t_list **t, void *data);
void	*pop_list(t_list **t);
void	*rm_data_from_list(t_list **t, void *data);
void	sort_client_list(t_list **begin);

/*
** Buffer's functions
*/
void	put_char_from_buf(char **elm, char **buf);
void	put_int_from_buf(int *elm, char **buf);
void	put_float_from_buf(float *elm, char **buf);
void	skip_from_buf(char **buf);

/*
** Matimatical's functions
*/
float	round_nbr(float nbr);

#endif /* !__OBSERVATOR_2D_H__ */
