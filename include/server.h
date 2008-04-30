/*
** server.h for **zappy** in /u/epitech_2010s/candan_c/cu/rendu/c/zappy/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 15 18:31:42 2008 caner candan
** Last update Wed Apr 30 13:07:34 2008 majdi toumi
*/

#ifndef __SERVER_H__
# define __SERVER_H__

/*
** Defines
*/
# define UNIT		010
# define TIME		100

/*
** Option's flags
*/
# define FLAG_P		1
# define FLAG_X		2
# define FLAG_Y		4
# define FLAG_N		8
# define FLAG_C		16
# define FLAG_T		32

/*
** Zappy's index names
*/
/* world */
# define NAME_WORLD	"Trantor"

/* rock */
# define LINEMATE	"Linemate"
# define DERAUMERE	"Deraumere"
# define SIBUR		"Sibur"
# define MENDIANE	"Mendiane"
# define PHIRAS		"Phiras"
# define THYSTAME	"Thystame"

/* food */
# define HAMBURGER	"Hamburger"
# define FISHBURGER	"Fishburger"
# define CHEESEBURGER	"Cheeseburger"

/*
** Exits, debug and errors
*/
# define DEBUG		01
# define EXIT_SUCC	00
# define EXIT_FAIL	42

/*
** Socket
*/
# define HOST_DEFAULT	"127.0.0.1"
# define PORT_DEFAULT	"12345"

/*
** Null
*/
# ifndef NULL
#  define NULL	(void *) 0
# endif /* !NULL */

/*
** Select's descriptors
*/
# define FD_FREE	0
# define FD_CLIENT	1
# define FD_SERVER	2

/*
** Limits' values
*/
# define MAX_FD		100
# define MAX_LISTEN	42

/*
** Alias
*/
typedef void	(*fct)();

/*
** Gerneric list of list chaine
*/
typedef struct		s_list
{
  void			*data;
  struct s_list		*next;
}			t_list;

/*
** Clients socket's structure
*/
typedef struct	s_cli
{
  int		socket;
  char		fd_type;
  fct		fct_read;
  fct		fct_write;
}		t_cli;

/*
** Environnement's structure
*/
typedef struct	s_env
{
  t_list	*clients;
  int		port;
  void		*timeout;
}		t_env;

/*
** Options' structure
*/
typedef struct		s_opt
{
  int			opt;
  char			*name;
  char			*desc;
  int			(*fun)();
}			t_opt;

/*
** Info about the game
*/
typedef struct		s_info
{
  int			port;
  int			width;
  int			lenght;
  t_list		*team;
  int			nb_player;
  int			time;
}			t_info;

/*
** One case of the map
*/
typedef struct		s_zone
{
  char			is_moveable;
  int			id_deco;
  t_list		*ressources;
  t_list		*clients;
}			t_zone;

/*
** Team's structure
*/
typedef struct		s_team
{
  char			*name;
  int			nb;
  int			max;
}			t_team;

/*
** Inventory structure
*/
typedef struct		s_inventory
{
  int			rock;
  unsigned int		qte;
}			t_inventory;

/*
** Queue actions' structure
*/
typedef struct		s_queue
{
  int			action;
  char			*param;
  unsigned int		time;
}			t_queue;

/*
** Clients' structure
*/
typedef struct		s_client
{
  int			hp;
  int			socket;
  int			level;
  t_team		*team;
  t_inventory		*stock;
  t_queue		queue;
}			t_client;

/*
** Actions list's structure
*/
typedef struct		s_action
{
  int			action;
  char			*str;
  unsigned int		delay;
  int			(*fun)(char *cmd, int socket);
}			t_action;

/*
** Ressources list's structure
*/
typedef struct		s_ressource
{
  char			*name;
  char			*desc;
}			t_ressource;

/*
** Criteres list's structure
*/
typedef struct		s_critere
{
  t_ressource	 	*rock;
  int			lvl;
  int			qte;
}			t_critere;

/*
** Level list's structure
*/
typedef struct		s_level
{
  int			lvl;
  int			nb_client;
  char			*desc;
}			t_level;

/*
** Globals
*/
extern t_opt		gl_opt_srv[];
extern t_opt		gl_opt_clt[];
extern t_ressource	gl_rock[];
extern t_ressource	gl_food[];
extern t_action		gl_actions[];

/*
** Socket's functions
*/
void	add_client(t_env *e, int s);
void	add_server(t_env *e);
void	client_read(t_env *e, int fd);
void	server_init(t_env *e, char *port);
void	server_get(t_env *e);
void	server_read(t_env *e, int fd);

/*
** Function's prototypes
*/
void	usage_server(void);
t_info	*parse_args(int argc, char **argv);
int	is_options(char *args);
int	check_flag(int flag);
int	opt_port(t_info *info, char **argv, int i);
int	opt_width(t_info *info, char **argv, int i);
int	opt_lenght(t_info *info, char **argv, int i);
int	opt_name_team(t_info *info, char **argv, int i);
int	opt_nb_player(t_info *info, char **argv, int i);
int	opt_delay(t_info *info, char **argv, int i);

t_zone	**create_world(int width, int lenght);
void	fill_ressources_world(t_zone **zone, int width, int lenght);
void	dump_world(t_zone **zone, int width, int lenght);
void	dump_ressources(t_list *ressource);
void	dump_clients(t_list *clients);

int	act_up(char *cmd, int socket);
int	act_right(char *cmd, int socket);
int	act_left(char *cmd, int socket);
int	act_see(char *cmd, int socket);
int	act_inventory(char *cmd, int socket);
int	act_take_obj(char *cmd, int socket);
int	act_drop_obj(char *cmd, int socket);
int	act_kick(char *cmd, int socket);
int	act_broadcast(char *cmd, int socket);
int	act_levelup(char *cmd, int socket);
int	act_fork(char *cmd, int socket);

/*
** Debug's functions
*/
void	debug(char *s);

/*
** List chaine's functions
*/
void	push_list(t_list **t, void *data);
void	*pop_list(t_list **t);
void	pop_all_list(t_list *t);
void	*pop_client_from_list(t_list **t, int socket);
void	*get_client_from_list(t_list *t, int socket);

#endif /* !__SERVER_H__ */
