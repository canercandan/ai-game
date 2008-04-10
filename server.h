/*
** server.h for **zappy.h** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 08:38:28 2008 majdi toumi
** Last update Thu Apr 10 11:16:31 2008 majdi toumi
*/


#ifndef __SERVER_H__
# define __SERVER_H__

/*
** Defines:
*/

/*
** Exits and errors:
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
  int			x;
  int			y;
}			t_client;

typedef struct		s_inventory
{
  t_rock		*rock;
  t_client		*client;
  int			qte;
}			t_inventory;

typedef struct		s_rock
{
  char			*name;
}			t_rock;

typedef struct		s_floor
{
  int			x;
  int			y;
  t_rock		*rock;
}			t_floor;

typedef struct		s_critere
{
  t_rock	 	*rock;
  t_level		*level;
  int			nb_client;
  int			qte;
}			t_critere;

typedef struct		s_level
{
  int			lvl;
  int			nb_player;
  char			*desc;
}			t_level;

/*
** Functions's prototypes:
*/
void	usage_server();
int	parse_args(int argc, char **argv);

#endif /* !__SERVER_H__ */
