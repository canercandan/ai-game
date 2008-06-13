/*
** act_levelup.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:25:07 2008 caner candan
** Last update Fri Jun 13 17:35:23 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int		act_levelup(t_info *info, t_client *client, char *param)
{
  t_list	*t;
  int		i;

  if (!client)
    return (-1);
  if (param[0] == '0')
    {
      info->status[(int)client->x][(int)client->y] = -1;
      return (0);
    }
  info->status[(int)client->x][(int)client->y] = LEVELUP;
  t = info->clients;
  while (t)
    {
      if (CLIENT(t->data)->x == client->x &&
	  CLIENT(t->data)->y == client->y)
	{
	  info->status[(int)client->x][(int)client->y] = LEVELUP;
	  CLIENT(t->data)->level++;
	}
      t = t->next;
    }
  for (i = 0; i < NB_OBJECT - 1; i++)
    info->object[(int)client->x][(int)client->y][i] = 0;
  return (0);
}
