/*
** server.h for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 13:37:20 2008 caner candan
** Last update Fri May  2 16:40:23 2008 caner candan
*/

#ifndef __SERVER_H__
# define __SERVER_H__

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
** Defines
*/
# define UNIT		10
# define TIME		100
# define COEFFICIENT	0.3
# define BUF_SIZE	1024
# define NB_INVENTORY	6
# define NB_FOOD	3

/*
** Zappy's index names
*/
/* world */
# define NAME_WORLD	"Trantor"

/*
** Exits, debug and errors
*/
# define DEBUG		1
# define EXIT_SUCC	0
# define EXIT_FAIL	42

/*
** Default's values
*/
# define DEFAULT_PORT		12345
# define DEFAULT_WIDTH		100
# define DEFAULT_LENGHT		100
# define DEFAULT_NB_PLAYER	10
# define DEFAULT_TIME		100

/*
** Null
*/
# ifndef NULL
#  define NULL	(void *) 0
# endif /* !NULL */

/*
** Status client
*/
typedef	enum
  {
    ST_NOT_LOGGED,
    ST_SERVER,
    ST_CLIENT,
    ST_GRAPH_CLIENT
  }	t_status;

/*
** Limits' values
*/
# define MAX_FD		100
# define MAX_LISTEN	42
# define MAX_OBJECT	2

/*
** Macros:
*/

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
** Options' structure
*/
typedef struct	s_opt
{
  int		opt;
  char		*name;
  char		*desc;
  int		(*fun)();
}		t_opt;

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
** Clients' structure
*/
typedef struct	s_client
{
  int		socket;
  t_status	status;
  fct		fct_read;
  fct		fct_write;
  char		buf_read[BUF_SIZE + 1];
  char		buf_write[BUF_SIZE + 1];
  char		level;
  int		hp;
  int		x;
  int		y;
  char		direction;
  t_team	*team;
  char		inventory[NB_INVENTORY];
}		t_client;

/*
** Queue actions' structure
*/
typedef struct		s_queue
{
  int			(*f)(char *cmd, int socket);
  char			*param;
  unsigned int		time;
  t_client		*client;
}			t_queue;

/*
** One case of the map
*/
typedef struct		s_zone
{
  char			is_moveable;
  int			id_deco;
  t_list		*ressources;
  t_list		*client;
}			t_zone;

/*
** Info about the game
*/
typedef struct	s_info
{
  int		port;
  int		y;
  int		x;
  t_list	*team;
  int		nb_player;
  int		time;
  t_list	*clients;
  void		*timeout;
  t_list	*queue;
  t_zone	**zone;
}		t_info;

/*
** Actions list's structure
*/
typedef struct		s_action
{
  int			action;
  char			*str;
  unsigned int		delay;
  int			(*f)(char *cmd, int socket);
}			t_action;

/*
** Ressources list's structure
*/
typedef struct		s_ressource
{
  int			idx;
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
** Enum action
*/
enum
  {
    UP = 1,
    RIGHT,
    LEFT,
    SEE,
    INVENTORY,
    TAKE_OBJ,
    DROP_OBJ,
    KICK,
    BROADCAST,
    LEVELUP,
    FORK
  };

/*
** Globals
*/
extern t_opt		gl_opt_srv[];
extern t_opt		gl_opt_clt[];
extern t_ressource	gl_rock[];
extern t_ressource	gl_food[];

/*
** Socket's functions
*/
void	add_client(t_info *info, int server);
void	add_server(t_info *info);
void	client_read(t_info *info, int socket);
void	client_write(t_info *info, int socket);
void	client_disconnect(t_client *client, t_info *info);
void	server_init(t_info *info);
void	server_get(t_info *info);
void	server_read(t_info *info, int socket);
void	server_write(t_info *info, int socket);

/*
** Options' functions
*/
void		usage_server(void);
t_info		*parse_args(int argc, char **argv, t_info *info);
int		is_options(char *args);
int		check_flag(int flag);
int		opt_port(t_info *info, char **argv, int i);
int		opt_width(t_info *info, char **argv, int i);
int		opt_lenght(t_info *info, char **argv, int i);
int		opt_name_team(t_info *info, char **argv, int i);
int		opt_nb_player(t_info *info, char **argv, int i);
int		opt_delay(t_info *info, char **argv, int i);

/*
** Zones' functions
*/
t_zone		**create_world(t_info *info);
void		fill_ressources_world(t_zone **world, t_info *info);
t_ressource	*generate_ressources(int level_max, int i);
void		dump_world(t_zone **zworld, int y, int x);

/*
** Actions' functions
*/
int		execute_action(char *str, t_client *cli, t_info *info);
int		act_up(char *cmd, int socket);
int		act_right(char *cmd, int socket);
int		act_left(char *cmd, int socket);
int		act_see(char *cmd, int socket);
int		act_inventory(char *cmd, int socket);
int		act_take_obj(char *cmd, int socket);
int		act_drop_obj(char *cmd, int socket);
int		act_kick(char *cmd, int socket);
int		act_broadcast(char *cmd, int socket);
int		act_levelup(char *cmd, int socket);
int		act_fork(char *cmd, int socket);

/*
** Debug's functions
*/
void	debug(char *s, int pos);

/*
** List chaine's functions
*/
void	push_list(t_list **t, void *data);
void	*pop_list(t_list **t);
void	pop_all_list(t_list *t);

/*
** Clients list chaine's functions
*/
void	*rm_client_from_list(t_list **t, int socket);
void	*get_client_from_list(t_list *t, int socket);
void	show_clients_from_list(t_list *t);
void	sort_queue_list(t_list **begin);
int	count_list(t_list *t);

/*
** Queue list functions
*/
void	rm_client_from_queue(t_list **t, int socket);

/*
** Client's functions
*/
void	free_client(t_client *client);

/*
** Info's functions
*/
t_info	*init_info();
void	free_info(t_info *info);

/*
** Usefull functions
*/
char	*get_word_n(char *str, int n);

#endif /* !__SERVER_H__ */
