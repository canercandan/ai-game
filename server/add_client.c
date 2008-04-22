/*
** add_client.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:37:41 2008 caner candan
** Last update Tue Apr 22 18:08:21 2008 caner candan
*/

#include "server.h"
#include "x.h"
#include "zappy.h"

void	add_client(t_env *e, int s)
{
  int	cs;

  cs = xaccept(s, NULL, NULL);
  e->fd_type[cs] = FD_CLIENT;
  e->fct_read[cs] = client_read;
  e->fct_write[cs] = NULL;
}
