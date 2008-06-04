/*
** init.c for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Jun  4 08:37:03 2008 caner candan
** Last update Wed Jun  4 08:38:14 2008 caner candan
*/

#include "server.h"

t_info		*init()
{
  t_info	*info;

  init_random();
  info = init_info();
  init_signal(info);
  return (info);
}
