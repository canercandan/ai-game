/*
** server_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:39:49 2008 caner candan
** Last update Wed Apr 30 13:19:33 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void	server_read(t_env *e, int socket)
{
  printf("New client\n");
  add_client(e, socket);
}
