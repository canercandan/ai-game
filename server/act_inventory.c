/*
** act_inventory.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Thu May  8 23:32:22 2008 florent hochwelker
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "server.h"
#include "common.h"
#include "x.h"

static void	get_inventory(t_client *client, char *buff)
{
  int		i;

  i = 0;
  strcpy(buff, START_CMD);
  strcat(buff, gl_ressource[NB_INVENTORY - 1].name);
  strcat(buff, SEPARATOR_ELM);
  putnbr(42, buff);
  while (i < NB_INVENTORY - 1)
    {
      if (i != (NB_INVENTORY - 1))
	strcat(strcat(buff, SEPARATOR_CMD), SEPARATOR_ELM);
      strcat(buff, gl_ressource[i].name);
      strcat(buff, SEPARATOR_ELM);
      putnbr(client->qte_ressource[i], buff);
      i++;
    }
  strcat(buff, END_CMD);
}

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
