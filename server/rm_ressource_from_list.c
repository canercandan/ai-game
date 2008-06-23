/*
** rm_ressource_from_list.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Tue May  6 16:32:45 2008 majdi toumi
** Last update Mon Jun 23 01:39:28 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "server.h"

static void	rm_first_elem(t_list **begin)
{
  t_list	*tmp;

  tmp = *begin;
  *begin = (*begin)->next;
  free(tmp);
}

static void	rm_loop_elem(t_list **begin, char *name)
{
  t_list	*pos;
  t_list	*tmp;
  t_list	*next;
  t_ressource	*res;

  pos = *begin;
  while (pos->next)
    {
      res = (t_ressource *)pos->next->data;
      if (!strcmp(res->name, name))
	{
	  next = pos->next->next;
	  tmp = pos->next;
	  free(tmp);
	  pos->next = next;
	  break;
	}
      pos = pos->next;
    }
}

void		rm_ressource_from_list(t_list **begin, char *name)
{
  t_ressource	*res;

  if (*begin)
    {
      res = (t_ressource *)(*begin)->data;
      if (!strcmp(res->name, name))
	rm_first_elem(begin);
      else
	rm_loop_elem(begin, name);
    }
}
