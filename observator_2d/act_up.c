/*
** act_up.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 19:05:32 2008 caner candan
** Last update Tue Jun 24 13:51:59 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int	act_up(t_info *info, t_client *client, char *param)
{
  (void)param;
  if (!client)
    return (-1);
  move_up(client, client->direction, info);
  return (0);
}
