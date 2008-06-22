/*
** act_inventory.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon Jun 23 01:00:41 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"
#include "x.h"

int			act_inventory(char *param, t_client *client, t_info *info)
{
  static char		buff[LEN_INVENTORY];
  static unsigned int	i = 0;

  (void)param;
  (void)info;
  if (i == 0)
    {
      bzero(buff, sizeof(buff));
      get_inventory(client, buff, info);
    }
  SEND(client->buf_write, buff + i);
  i += strlen(client->buf_write);
  if (i <= strlen(buff) && strlen(buff + i) > 0)
    return (LOOP_FOR_SEND);
  i = 0;
  return (0);
}
