/*
** init_info.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Fri May  2 15:01:08 2008 caner candan
** Last update Fri May  2 23:58:28 2008 florent hochwelker
*/

#include "server.h"
#include "x.h"

t_info		*init_info()
{
  t_info	*info;

  info = xmalloc(sizeof(*info));
  info->queue = 0;
  return (info);
}
