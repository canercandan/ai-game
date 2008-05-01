/*
** free_client.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  1 19:40:01 2008 caner candan
** Last update Thu May  1 20:10:56 2008 caner candan
*/

#include <stdlib.h>
#include "server.h"

void	free_client(t_client *client)
{
  debug("free_client()", -1);
  free(client->team->name);
  free(client->team);
  free(client);
}
