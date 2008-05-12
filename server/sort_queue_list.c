/*
** sort_queue_list.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Wed Apr 30 17:53:33 2008 florent hochwelker
** Last update Mon May 12 13:10:53 2008 majdi toumi
*/

#include <stdio.h>
#include <sys/time.h>
#include "server.h"

void		sort_queue_list(t_list **begin)
{
  t_list	*p;
  t_list	*swap;

  p = *begin;
  while ((*begin)->next)
    {
      if (((struct timeval *)((t_queue*)(*begin)->data)->time)->tv_sec >
	  ((struct timeval *)((t_queue*)(*begin)->next->data)->time)->tv_sec
	  || (((struct timeval *)((t_queue*)(*begin)->data)->time)->tv_sec ==
	      ((struct timeval *)((t_queue*)(*begin)->next->data)->time)->tv_sec
	      && ((struct timeval *)((t_queue*)(*begin)->data)->time)->tv_usec >
	      ((struct timeval *)((t_queue*)(*begin)->next->data)->time)->tv_usec))
	{
	  printf("petit swap\n");
	  swap = (*begin)->next->data;
	  (*begin)->next->data = (*begin)->data;
	  (*begin)->data = swap;
	  *begin = p;
	}
      else
	*begin = (*begin)->next;
    }
  *begin = p;
}
