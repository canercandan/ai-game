/*
** zappy.h for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 19:03:01 2008 majdi toumi
** Last update Tue Apr 15 15:43:49 2008 caner candan
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

# define MEZZOPASTA	"Mezzopasta"

/*
** Exits, debug and errors:
*/
# define DEBUG		01
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
  struct s_client	*next;
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
void	usage_server();
t_info	*parse_args(int argc, char **argv);
int	is_options(char *args);
int	check_flag(int flag);
int	opt_port(t_info *info, char **argv, int i);
int	opt_width(t_info *info, char **argv, int i);
int	opt_lenght(t_info *info, char **argv, int i);
int	opt_name_team(t_info *info, char **argv, int i);
int	opt_nb_player(t_info *info, char **argv, int i);
int	opt_delay(t_info *info, char **argv, int i);

t_zone	**create_zone(int width, int lenght);
void	fill_ressources_zone(t_zone **zone, int width, int lenght);
void	dump_zone(t_zone **zone, int width, int lenght);
void	dump_ressources(t_list *ressource);
void	dump_clients(t_list *clients);

#endif /* !__ZAPPY_H__ */
