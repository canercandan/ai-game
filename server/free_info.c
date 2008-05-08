/*
** free_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 15:02:46 2008 caner candan
** Last update Thu May  8 12:47:39 2008 caner candan
*/

#include "server.h"
#include <stdlib.h>

void	free_info(t_info *info)
{
  int	i;

  for (i = 0; i < info->y; i++)
    free(info->zone[i]);
  free(info->zone);
  free(info);
}
