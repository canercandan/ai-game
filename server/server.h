/*
** server.h for **zappy.h** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 08:38:28 2008 majdi toumi
** Last update Thu Apr 10 09:28:37 2008 majdi toumi
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

/*
** Typedef and structs:
*/
typedef struct		s_opt
{
  char			*name;
  char			*desc;
}			t_opt;

typedef struct		s_info
{

}			t_info;

/*
** Functions's prototypes:
*/
void	usage_server();
int	parse_args(int argc, char **argv);

#endif /* !__SERVER_H__ */
