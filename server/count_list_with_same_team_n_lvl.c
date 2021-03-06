/*
** count_list_with_same_team_n_lvl.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 16:07:50 2008 caner candan
** Last update Mon Jun 23 07:00:11 2008 florent hochwelker
*/

#include "server.h"

int	count_list_with_same_team_n_lvl(t_list *t, t_team *team, int lvl)
{
  int	i;

  i = 0;
  while (t)
    {
      if (CLIENT(t->data)->team == team &&
	  CLIENT(t->data)->level == lvl &&
	  (CLIENT(t->data)->status == ST_CLIENT ||
	   CLIENT(t->data)->status == ST_DISCONNECT))
	i++;
      t = t->next;
    }
  return (i);
}
