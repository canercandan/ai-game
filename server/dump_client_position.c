/*
** dump_client_position.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Sat May  3 17:06:56 2008 caner candan
** Last update Wed May  7 19:01:15 2008 caner candan
*/

#include <stdio.h>
#include "server.h"

void		dump_client_position(t_list *clients)
{
  t_client	*c;

  while (clients)
    {
      c = (t_client *) clients->data;
      if (c->status == ST_CLIENT)
	printf("Client %d Coordonnes [%d][%d] Direction [%d] Level [%d]\n",
	       c->socket, c->x, c->y, c->direction, c->level);
      clients = clients->next;
    }
}
