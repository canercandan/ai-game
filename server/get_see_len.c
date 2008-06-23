/*
** get_see_len.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon Jun 23 01:34:15 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

int	get_see_len(t_client *client, t_info *info)
{
  int	i;
  int	j;
  int	len;

  len = strlen(START_CMD);
  i = 0;
  while (i <= client->level)
    {
      j = 0 - i;
      while (j <= i)
	{
	  len += send_len_ressources(info, client, j, i);
	  if (i != client->level || j != i)
	    len += strlen(SEPARATOR_CMD);
	  j++;
	}
      i++;
    }
  len += strlen(END_CMD);
  return (len);
}
