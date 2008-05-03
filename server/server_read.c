/*
** server_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:39:49 2008 caner candan
** Last update Sat May  3 16:19:08 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void		server_read(t_info *info, t_client *client)
{
  t_client	*c;

  debug("server_read()", 3);
  printf("New client\n");
  c = add_client(info, client->socket);
  begin_session(info, c);
}
