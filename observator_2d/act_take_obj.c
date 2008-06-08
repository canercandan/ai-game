/*
** act_take_obj.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:19:42 2008 caner candan
** Last update Sun Jun  8 04:27:43 2008 caner candan
*/

#include <stdlib.h>
#include "observator_2d.h"

int	act_take_obj(t_info *info, t_client *client, char *param)
{
  int	object;

  if (!client || !param)
    return (-1);
  object = atoi(param);
  if (info->object[(int)client->x][(int)client->y][object])
    info->object[(int)client->x][(int)client->y][object]--;
  return (0);
}
