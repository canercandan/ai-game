/*
** server.h for **zappy.h** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 08:38:28 2008 majdi toumi
** Last update Thu Apr 10 15:05:36 2008 majdi toumi
*/


#ifndef __SERVER_H__
# define __SERVER_H__

/*
** Defines:
*/
# define UNIT		010
# define TIME		100

/*
** Exits, debug and errors:
*/
# define EXIT_SUCC	00
# define EXIT_FAIL	42
# define DEBUG		01

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
  char			*name;
  char			*desc;
  void			(*fun)();
}			t_opt;

typedef struct		s_info
{
  int			port;
  int			width;
  int			length;
  t_list		*team;
  int			nb_player;
  int			time;
}			t_info;

typedef struct		s_case
{
  char			is_movible;
  int			id_deco;
  t_list		*ressources;
  t_list		*client;	/* data = client */
}			t_case;

typedef struct		s_team
{
  char			*name;
  int			nb;
  int			max;
}			t_team;

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

typedef struct		s_inventory
{
  int			rock;
  unsigned int		qte;
}			t_inventory;

typedef struct		s_rock
{
  char			*name;
  char			*desc;
}			t_rock;

typedef struct		s_food
{
  char			*name;
  char			*desc;
}			t_food;

typedef struct		s_critere
{
  t_rock	 	*rock;
  t_level		*level;
  int			qte;
}			t_critere;

typedef struct		s_level
{
  int			lvl;
  int			nb_player;
  char			*desc;
}			t_level;

/*
** Globals:
*/
t_opt			gl_opt_srv[];
t_opt			gl_opt_clt[];

/*
** Function's prototypes:
*/
void	usage_server();
int	parse_args(int argc, char **argv);

#endif /* !__SERVER_H__ */
