/*
** server_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:39:49 2008 caner candan
** Last update Mon Jun 23 03:47:36 2008 caner candan
*/

#include "server.h"

void		server_read(t_info *info, t_client **client)
{
  t_client	*c;

  c = add_client(info, (*client)->socket, 0, 0);
  begin_session(info, &c);
}
