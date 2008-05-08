/*
** free_info.c for zappy in /home/candan_c/cu/rendu/project/zappy/client
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May  7 21:10:47 2008 caner candan
** Last update Wed May  7 21:11:24 2008 caner candan
*/

#include <stdlib.h>
#include "client.h"

void	free_info(t_info *info)
{
  free(info);
}
