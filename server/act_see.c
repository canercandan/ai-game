/*
** act_see.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May 12 20:42:17 2008 majdi toumi
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "server.h"
#include "common.h"
#include "x.h"

static void		get_ressources(t_client *client, t_info *info,
				       char *buff)
{
  int			i;
  int			j;
  int			diff[2];

  i = 0;
  while (i <= client->level)
    {
      j = 0 - i;
      while (j <= i)
	{
	  diff[0] = j;
	  diff[1] = i;
	  send_ressources(info, client, buff, diff);
	  if (i != client->level || j != i)
	    strcat(buff, SEPARATOR_CMD);
	  j++;
	}
      i++;
    }
  strcat(buff, END_CMD);
}

int			act_see(char *param, t_client *client, t_info *info)
{
  static unsigned int	i = 0;
  static char		*buff;
  int			len;

  (void)param;
  if (i == 0)
    {
      len = get_see_len(client, info);
      buff = xmalloc(sizeof(*buff) * (len + 1));
      bzero(buff, sizeof(buff));
      strcpy(buff, START_CMD);
      get_ressources(client, info, buff);
    }
  SEND(client->buf_write, buff + i);
  i += strlen(client->buf_write);
  if (i <= strlen(buff) && strlen(buff + i) > 0)
    return (LOOP_FOR_SEND);
  i = 0;
  free(buff);
  return (0);
}
