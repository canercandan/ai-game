/*
** exist_data_from_list.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May  5 17:53:30 2008 majdi toumi
** Last update Mon May  5 18:04:31 2008 majdi toumi
*/

#include <string.h>
#include "server.h"

int	exist_data_from_list(t_list *t, void *data)
{
  while (t)
    {
      if (!strcmp(t->data, (char *)data))
	return (1);
      t = t->next;
    }
  return (0);
}
