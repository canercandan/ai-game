/*
** act_drop_obj.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:20:08 2008 caner candan
** Last update Sun Jun  8 04:31:57 2008 caner candan
*/

#include <stdlib.h>
#include "observator_2d.h"

int	act_drop_obj(t_info *info, t_client *client, char *param)
{
  int	object;

  if (!client || !param)
    return (-1);
  object = atoi(param);
  info->object[(int)client->x][(int)client->y][object]++;
  return (0);
}
