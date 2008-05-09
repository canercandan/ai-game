/*
** free_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 15:02:46 2008 caner candan
** Last update Fri May  9 18:58:12 2008 florent hochwelker
*/

#include <stdlib.h>
#include <unistd.h>
#include "server.h"

static void	free_list(t_list *list)
{
  void		*data;

  while ((data = pop_list(&list)))
    free(data);
}

static void	free_clients(t_list *list)
{
  t_client	*client;

  while ((client = pop_list(&list)))
    {
      close(client->socket);
      free(client);
    }
}

static void	free_zones(t_info *info)
{
  int		x;
  int		y;

  for (x = 0; x < info->x; x++)
    {
      for (y = 0; y < info->y; y++)
	while (pop_list(&(info->zone[x][y].ressources)));
      free(info->zone[x]);
    }
  free(info->zone);
}

void	free_info(t_info *info)
{
  free_zones(info);
  free_list(info->team);
  free_clients(info->clients);
  free_list(info->queue);
  free_list(info->observator);
  free(info->timeout);
  free(info);
}
