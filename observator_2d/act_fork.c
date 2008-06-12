/*
** act_fork.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:25:37 2008 caner candan
** Last update Thu Jun 12 10:12:06 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int	act_fork(t_info *info, t_client *client, char *param)
{
  (void) param;
  if (!client)
    return (-1);
  info->object[(int)client->x][(int)client->y][EGGOBJ]++;
  return (0);
}
