/*
** swap_ptr_client.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue May 13 18:30:36 2008 florent hochwelker
** Last update Tue May 13 18:50:39 2008 florent hochwelker
*/

#include <string.h>
#include <stdio.h>		/* printf a vire */
#include "server.h"

void		swap_ptr_client(t_info *info, t_client *old, t_client *new)
{
  t_list	*list;

  list = info->clients;
  while (list)
    {
      if (list->data == old)
	{
	  list->data = new;
	  printf("== swap ptr ok ==\n");
	  break;
	}
      list = list->next;
    }
  printf("== swap ptr FAILED ==\n");
}
