/*
** sort_queue_list.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Wed Apr 30 17:53:33 2008 florent hochwelker
** Last update Wed Apr 30 18:52:39 2008 florent hochwelker
*/

#include "server.h"

void		sort_queue_list(t_list **begin)
{
  t_list	*p;
  t_list	*swap;

  p = *begin;
  while ((*begin)->next)
    {
      if (((t_queue *)(*begin)->data)->queue->timeout >
	  ((t_queue *)((*begin)->next->data))->queue->timeout)
	{
	  swap = (*begin)->next;
	  (*begin)->next->data = (*begin)->data;
	  (*begin)->data = swap;
	  *begin = p;
	}
      else
	*begin = (*begin)->next;
    }
  *begin = p;
}
