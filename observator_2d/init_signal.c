/*
** init_signal.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:09:54 2008 caner candan
** Last update Wed May 14 11:19:06 2008 caner candan
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "observator_2d.h"

static t_info	*sig_info;

static void	power_off(int signal)
{
  (void) signal;
  destroy_gfx(sig_info->gfx);
  destroy_info(sig_info);
  exit(0);
}

void	init_signal(t_info *info)
{
  sig_info = info;
  signal(SIGINT, power_off);
}
