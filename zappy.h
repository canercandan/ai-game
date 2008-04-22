/*
** zappy.h for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:03:01 2008 majdi toumi
** Last update Tue Apr 22 17:11:32 2008 majdi toumi
*/

#ifndef __ZAPPY_H__
# define __ZAPPY_H__

/*
** Defines:
*/
# define UNIT		010
# define TIME		100

# define FLAG_P		1
# define FLAG_X		2
# define FLAG_Y		4
# define FLAG_N		8
# define FLAG_C		16
# define FLAG_T		32

# define LINEMATE	"Linemate"
# define DERAUMERE	"Deraumere"
# define SIBUR		"Sibur"
# define MENDIANE	"Mendiane"
# define PHIRAS		"Phiras"
# define THYSTAME	"Thystame"

# define MEZZOPASTA	"Mezzo_di_pasta"

/*
** Exits, debug and errors:
*/
# define DEBUG		1
# define EXIT_SUCC	00
# define EXIT_FAIL	42

/*
** Socket:
*/
# define HOST_DEFAULT	"127.0.0.1"
# define PORT_DEFAULT	"12345"

/*
** Null:
*/
# ifndef NULL
#  define NULL	0
# endif /* !NULL */

/*
** Typedef and structs:
*/
typedef struct		s_list
{
  void			*data;
  struct s_list		*prev;
  struct s_list		*next;
}			t_list;

typedef struct		s_opt
{
  int			opt;
  char			*name;
  char			*desc;
  int			(*fun)();
}			t_opt;

typedef struct		s_info
{
  int			port;
  int			width;
  int			lenght;
  t_list		*team;
  int			nb_player;
  int			time;
}			t_info;

typedef struct		s_cnt
{
  char			*host;
  char			*port;
  int			s;
  int			cs;
}			t_cnt;

typedef struct		s_zone
{
  char			is_moveable;
  int			id_deco;
  t_list		*ressources;
  t_list		*clients;
}			t_zone;

typedef struct		s_team
{
  char			*name;
  int			nb;
  int			max;
}			t_team;

typedef struct		s_inventory
{
  int			rock;
  unsigned int		qte;
}			t_inventory;

typedef struct		s_client
{
  int			hp;
  int			socket;
  int			level;
  t_team		*team;
  t_inventory		*stock;
}			t_client;

typedef struct		s_action
{
  char			*name;
  int			delay;
  char			(*fun)();
}			t_action;

typedef struct		s_ressource
{
  char			*name;
  char			*desc;
}			t_ressource;

typedef struct		s_critere
{
  t_ressource	 	*rock;
  int			lvl;
  int			qte;
}			t_critere;

typedef struct		s_level
{
  int			lvl;
  int			nb_client;
  char			*desc;
}			t_level;

/*
** Globals:
*/
extern t_opt		gl_opt_srv[];
extern t_opt		gl_opt_clt[];
extern t_ressource	gl_rock[];

/*
** Function's prototypes:
*/
void		usage_server();
t_info		*parse_args(int argc, char **argv);
int		is_options(char *args);
int		check_flag(int flag);
int		opt_port(t_info *info, char **argv, int i);
int		opt_width(t_info *info, char **argv, int i);
int		opt_lenght(t_info *info, char **argv, int i);
int		opt_name_team(t_info *info, char **argv, int i);
int		opt_nb_player(t_info *info, char **argv, int i);
int		opt_delay(t_info *info, char **argv, int i);

void		put_in_list(t_list **begin, void *data);
void		del_in_list(t_list **begin, char *name);
t_zone		**create_world(int width, int lenght);
void		fill_ressources_world(t_zone **world, int width, int lenght);
void		dump_world(t_zone **world, int width, int lenght);
static void	dump_ressources(t_list *ressource);
static void	dump_clients(t_list *clients);

/*
** My/x library:
*/
void	*xmalloc(int size);

/*
** Socket control:
*/
int	xaccept(int s, void *addr, void *addrlen);
int	xbind(int s, const void *addr, void *addrlen);
int	xconnect(int s, const void *name, void *namelen);
int	xlisten(int s, int backlog);
void	*xrecv(int s, void *buf, void *len, int flags);
void	*xsend(int s, const void *msg, void *len, int flags);
int	xsocket(int domain, int type, int protocol);

#endif /* !__ZAPPY_H__ */
