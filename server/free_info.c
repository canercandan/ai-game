/*
** free_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 15:02:46 2008 caner candan
** Last update Thu May  8 13:45:03 2008 caner candan
*/

#include "server.h"
#include <stdlib.h>

static void	free_list(t_list *list)
{
  void		*data;

  while ((data = pop_list(&list)))
    free(data);
}

/* static void	free_clients(t_list *list) */
/* { */

/* } */

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
  free_list(info->clients);
  free_list(info->queue);
  free_list(info->observator);
  free(info);
}
