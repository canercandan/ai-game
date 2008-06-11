/*
** act_levelup.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:25:07 2008 caner candan
** Last update Wed Jun 11 10:43:06 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int	act_levelup(t_info *info, t_client *client, char *param)
{
  (void) param;
  if (!client)
    return (-1);
  info->status[(int)client->x][(int)client->y] = LEVELUP;
  client->level++;
  return (0);
}
