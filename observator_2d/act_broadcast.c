/*
** act_broadcast.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:24:36 2008 caner candan
** Last update Sun Jun  8 05:06:14 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "observator_2d.h"

int	act_broadcast(t_info *info, t_client *client, char *param)
{
  (void) param;
  info->broadcast[(int)client->x][(int)client->y] = 1;
  return (0);
}
