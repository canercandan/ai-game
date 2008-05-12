/*
** init_signal.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:09:54 2008 caner candan
** Last update Mon May 12 21:46:38 2008 caner candan
*/

#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "observator_2d.h"

static t_info	*sig_info;
static t_gfx	*sig_gfx;

static void	power_off(int signal)
{
  (void) signal;
  close(sig_info->socket);
  destroy_gfx(sig_gfx);
  exit(0);
}

void	init_signal(t_info *info, t_gfx *gfx)
{
  sig_info = info;
  sig_gfx = gfx;
  signal(SIGINT, power_off);
}
