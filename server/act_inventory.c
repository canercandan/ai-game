/*
** act_inventory.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Fri May  9 00:46:07 2008 florent hochwelker
*/

#include <stdio.h>
#include <time.h>
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
      get_inventory(client, buff);
    }
  bzero(client->buf_write, BUF_SIZE);
  strncpy(client->buf_write, buff + i, BUF_SIZE);
  i += strlen(client->buf_write);
  if (i <= strlen(buff) && strlen(buff + i) > 0)
    return (LOOP_FOR_SEND);
  i = 0;
  return (0);
}
