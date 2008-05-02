
/*
** server_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:39:49 2008 caner candan
** Last update Fri May  2 21:35:37 2008 florent hochwelker
*/

#include <stdio.h>
#include "server.h"

void		server_read(t_info *info, int socket)
{
  t_client	*client;

  debug("server_read()", 3);
  printf("New client\n");
  client = add_client(info, socket);
  begin_session(info, client);
}
