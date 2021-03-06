/*
** exist_data_from_list.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Mon May  5 17:53:30 2008 majdi toumi
** Last update Mon Jun 23 01:24:04 2008 caner candan
*/

#include <string.h>
#include "server.h"

int		exist_data_from_list(t_list *t, void *data)
{
  t_ressource	*res;

  if ((char *)data)
    {
      while (t)
	{
	  res = (t_ressource *)t->data;
	  if (!strcmp(res->name, (char *)data))
	    return (1);
	  t = t->next;
	}
    }
  return (0);
}
