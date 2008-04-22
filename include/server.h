/*
** server.h for **zappy** in /u/epitech_2010s/candan_c/cu/rendu/c/zappy/include
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 15 18:31:42 2008 caner candan
** Last update Tue Apr 22 09:45:09 2008 caner candan
*/

#ifndef __SERVER_H__
# define __SERVER_H__

# define FD_FREE	0
# define FD_CLIENT	1
# define FD_SERVER	2

# define MAX_FD		OPEN_MAX

typedef void	(*fct)();

typedef struct	s_env
{
  char		fd_type[MAX_FD];
  fct		fct_read[MAX_FD];
  fct		fct_write[MAX_FD];
  int		port;
}		t_env;

/*
**
*/

void	add_client(t_env *e, int s);
void	add_server(t_env *e);
void	client_read(t_env *e, int fd);
void	server_read(t_env *e, int fd);

#endif /* !__SERVER_H__ */
