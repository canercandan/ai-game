/*
** init_info.c for zappy in /home/candan_c/cu/rendu/project/zappy/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May  7 21:08:41 2008 caner candan
** Last update Wed May  7 21:09:43 2008 caner candan
*/

#include <stdlib.h>
#include "client.h"
#include "x.h"

t_info		*init_info(void)
{
  t_info	*info;

  info = xmalloc(sizeof(*info));
  return (info);
}
