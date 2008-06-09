/*
** sort_client_list.c for zappy in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Jun  9 21:03:18 2008 caner candan
** Last update Mon Jun  9 21:09:35 2008 caner candan
*/

#include <stdio.h>
#include "observator_2d.h"

void		sort_client_list(t_list **begin)
{
  t_list	*p;
  t_list	*swap;

  p = *begin;
  while ((*begin)->next)
    {
      if (CLIENT((*begin)->data)->y
	  > CLIENT((*begin)->next->data)->y)
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
