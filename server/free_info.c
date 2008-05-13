/*
** free_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 15:02:46 2008 caner candan
** Last update Tue May 13 20:15:15 2008 majdi
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

static void	free_queues(t_list *list)
{
  void		*data;

  while ((data = pop_list(&list)))
    {
      free(((t_queue *)data)->param);
      free(((t_queue *)data)->time);
      free(data);
    }
}

static void	free_zones(t_info *info)
{
  int		x;
  int		y;

  x = 0;
  while (x < info->x)
    {
      y = 0;
      while (y < info->y)
	{
	  while (pop_list(&(info->zone[x][y].ressources)));
	  while (pop_list(&(info->zone[x][y].clients)));
	  y++;
	}
      free(info->zone[x]);
      x++;
    }
  free(info->zone);
}

void	free_info(t_info *info)
{
  free_zones(info);
  free_list(info->team);
  free_clients(info->clients);
  free_queues(info->queue);
  free_list(info->observator);
  free(info->timeout);
  free(info);
}
