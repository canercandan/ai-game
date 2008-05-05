/*
** act_inventory.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Mon May  5 17:17:02 2008 majdi toumi
*/

#include <stdio.h>
#include <string.h>
#include "server.h"
#include "common.h"
#include "x.h"

static int	get_size_inventory(t_client *client)
{
  int		qte;
  char		*nb;
  int		len;
  int		i;

  i = 0;
  len =  strlen(START_CMD);
  while (i < NB_INVENTORY)
    {
      qte = client->qte_ressource[i];
      snprintf(nb, 3, "%d", qte);
      len += strlen(SEPARATOR_ELM) + strlen(gl_ressource[i].name) + 
	strlen(SEPARATOR_ELM) + strlen(nb);
      if (i != (NB_INVENTORY - 1))
	len += strlen(SEPARATOR_CMD);
      i++;
    }
  len += strlen(SEPARATOR_ELM);
  len += strlen(END_CMD);
  return (len);
}

static char	*get_inventory(t_client *client, int len)
{
  int		qte;
  char		*nb;
  char		*s;
  int		i;

  i = 0;
  s = xmalloc(sizeof(*s) * len);
  strcpy(s, START_CMD);
  while (i < NB_INVENTORY)
    {
      qte = client->qte_ressource[i];
      snprintf(nb, 3, "%d", qte);
      strcat(s, SEPARATOR_ELM);
      strcat(s, gl_ressource[i].name);
      strcat(s, SEPARATOR_ELM);
      strcat(s, nb);
      if (i != (NB_INVENTORY - 1))
	strcat(s, SEPARATOR_CMD);
      i++;
    }
  strcat(s, SEPARATOR_ELM);
  strcat(s, END_CMD);
  return (s);
}

int		act_inventory(char *param, t_client *client, t_info *info)
{
  static int	i = 0;
  static char	*s;
  int		len;

  (void)param;
  (void)info;
  if (i == 0)
    {
      len = get_size_inventory(client);
      s = get_inventory(client, len);
    }
  bzero(client->buf_write, BUF_SIZE);
  send_buf_to_client(client, OK);
  return (0);
}

