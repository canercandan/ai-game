/*
** init_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 12:03:28 2008 caner candan
** Last update Tue May 13 19:41:52 2008 caner candan
*/

#include "observator_2d.h"

int	init_info(t_info *info)
{
  info->x = 0;
  info->y = 0;
  info->socket = 0;
  info->buf[0] = 0;
  info->timeout = NULL;
  info->host = NULL;
  info->port = 0;
  info->clients = NULL;
  return (0);
}
