/*
** get_ressource_idx.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May  5 17:58:52 2008 majdi toumi
** Last update Mon May  5 18:02:49 2008 majdi toumi
*/

#include <string.h>
#include "server.h"

int	get_ressource_idx(char *data)
{
  int	i;

  i = 0;
  while (i < NB_INVENTORY)
    {
      if (!strcmp(data, gl_ressource[i].name))
	return (i);
      i++;
    }
  return (-1);
}
