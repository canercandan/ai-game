/*
** act_see.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Fri May  9 01:06:30 2008 florent hochwelker
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "common.h"
#include "x.h"

static int		send_to_client(t_client *client, char *buff,
				       unsigned int *idx)
{
  bzero(client->buf_write, BUF_SIZE);
  strncpy(client->buf_write, buff + *idx, BUF_SIZE);
  *idx += strlen(client->buf_write);
  if (*idx <= strlen(buff) && strlen(buff + *idx) > 0)
    return (LOOP_FOR_SEND);
  *idx = 0;
  return (0);
}

int			act_see(char *param, t_client *client, t_info *info)
{
  static unsigned int	idx = 0;
  static char		*buff;
  int			res;
  int			len;
  int			i;
  int			j;

  (void) param;
  if (idx == 0)
    {
      len = get_see_len(client, info);
      buff = xmalloc(sizeof(*buff) * (len + 1));
      bzero(buff, sizeof(buff));
      strcpy(buff, START_CMD);
      for (i = 0; i <= client->level; i++)
	for (j = 0 - i; j <= i; j++)
	  {
	    send_ressources(info, client, buff, j, i);
	    if (i != client->level || j != i)
	      strcat(buff, SEPARATOR_CMD);
	  }
      strcat(buff, END_CMD);
    }
  res = send_to_client(client, buff, &idx);
  return (res);
}
