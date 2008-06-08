/*
** obs_send_action.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  9 15:49:07 2008 florent hochwelker
** Last update Sun Jun  8 03:30:58 2008 caner candan
*/

#include <string.h>
#include <stdio.h>
#include "server.h"

static int	send_param(t_list *obs, char idx_f, char *param)
{
  int		i;

  printf("send_param: [%d]\n", idx_f);
  if (idx_f == 5 ||
      idx_f == 6)
    for (i = 0; gl_ressource[i].idx >= 0; i++)
      if (!strcmp(gl_ressource[i].name, param))
	{
	  putnbr(gl_ressource[i].idx, CLIENT(obs->data)->buf_write);
	  return (0);
	}
  strcat(CLIENT(obs->data)->buf_write, param);
  return (0);
}

void		obs_send_action(int id, t_info *info, char idx_f, char *param)
{
  t_list	*obs;

  obs = info->observator;
  while (obs)
    {
      putnbr(id, CLIENT(obs->data)->buf_write);
      strcat(CLIENT(obs->data)->buf_write, " ");
      putnbr(idx_f, CLIENT(obs->data)->buf_write);
      strcat(CLIENT(obs->data)->buf_write, " ");
      send_param(obs, idx_f, param);
      strcat(CLIENT(obs->data)->buf_write, "\n");
      obs = obs->next;
    }
}
