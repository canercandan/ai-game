/*
** act_death.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 21:07:15 2008 caner candan
** Last update Sat Jun  7 11:22:13 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

int	act_death(t_info *info, t_client *client, char *param)
{
  (void) param;
  if (!client)
    return (-1);
  rm_data_from_list(&(info->clients), client);
  return (0);
}
