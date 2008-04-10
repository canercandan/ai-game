/*
** server.h for **zappy.h** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 08:38:28 2008 majdi toumi
** Last update Thu Apr 10 12:10:13 2008 majdi toumi
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
}			t_opt;

typedef struct		s_info
{
  int			port;
  int			width;
  int			length;
  t_list		*team;
  int			nb_client;
  float			time;
}			t_info;

typedef struct		s_omega
{
  char			**map;
  int			is_movible;
  int			nb_player;
}			t_omega;

typedef struct		s_team
{
  char			*name;
  int			nb;
  int			max;
}			t_team;

typedef struct		s_client
{
  t_team		*team;
  t_level		*level;
  int			hp;
  int			x;
  int			y;
}			t_client;

typedef struct		s_action
{
  char			*name;
  int			delay;
  void			(*fun)();
}			t_action;

typedef struct		s_inventory
{
  t_rock		*rock;
  t_client		*client;
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

typedef struct		s_floor
{
  int			x;
  int			y;
  void			*ressources;	/* @rock or @food */
}			t_floor;

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
