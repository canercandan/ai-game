/*
** server_read.c for zappy in /home/candan_c/cu/rendu/project/zappy/server/select
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Apr 22 09:39:49 2008 caner candan
** Last update Tue Apr 22 18:29:25 2008 caner candan
*/

#include <stdio.h>
#include "server.h"
#include "zappy.h"

void	server_read(t_env *e, int fd)
{
  printf("New client\n");
  add_client(e, fd);
}
