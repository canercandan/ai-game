/*
** act_inventory.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Wed May  7 11:20:09 2008 caner candan
*/

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "server.h"
#include "common.h"
#include "x.h"

static void	get_inventory(t_client *client, char *buff)
{
  char		qte[3];
  char		hp[5];
  int		i;

  i = 0;
  strcpy(buff, START_CMD);
  snprintf(hp, 4, "0"); /*(int)(client->hp - time(NULL)) / FOOD_HP); */
  strcat(buff, gl_ressource[NB_INVENTORY - 1].name);
  strcat(buff, SEPARATOR_ELM);
  strcat(buff, hp);
  while (i < NB_INVENTORY - 1)
    {
      if (i != (NB_INVENTORY - 1))
	strcat(strcat(buff, SEPARATOR_CMD), SEPARATOR_ELM);
      snprintf(qte, 3, "%d", client->qte_ressource[i]);
      strcat(buff, gl_ressource[i].name);
      strcat(buff, SEPARATOR_ELM);
      strcat(buff, qte);
      i++;
    }
  strcat(buff, END_CMD);
}

int		act_inventory(char *param, t_client *client, t_info *info)
{
  static char	buff[LEN_INVENTORY];
  static int	i = 0;

  (void)param;
  (void)info;
  if (i == 0)
    {
      bzero(buff, sizeof(buff));
      get_inventory(client, buff);
      printf("[buff %s]\n", buff);
    }
  bzero(client->buf_write, BUF_SIZE);
  strncpy(client->buf_write, buff + i, BUF_SIZE);
  printf("[client %s]\n", client->buf_write);
  if (strlen(client->buf_write) == BUF_SIZE)
    {
      i = BUF_SIZE;
      return (LOOP_FOR_SEND);
    }
  return (0);
}
