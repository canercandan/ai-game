/*
** act_levelup_progress.c for zappy in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Jun 11 10:00:13 2008 caner candan
** Last update Wed Jun 11 10:01:51 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int	act_levelup_progress(t_info *info,
			     t_client *client,
			     char *param)
{
  (void) param;
  if (!client)
    return (-1);
  info->status[(int)client->x][(int)client->y] = LEVELUP_PROGRESS;
  return (0);
}
