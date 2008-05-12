/*
** get_header.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:46:52 2008 caner candan
** Last update Mon May 12 22:00:46 2008 caner candan
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "x.h"

int	get_header(t_info *info, t_gfx *gfx)
{
  char	buf[1024];
  int	nbr;
  char	*tmp;

  (void) info;
  (void) gfx;
  if ((nbr = xrecv(info->socket, buf, sizeof(buf), 0)) > 0)
    {
      buf[nbr] = 0;
      printf("recv: [%s]\n", buf);
    }
  if ((nbr = xrecv(info->socket, buf, sizeof(buf), 0)) > 0)
    {
      buf[nbr] = 0;
      tmp = strchr(buf, ' ');
      buf[tmp - buf] = 0;
      gfx->x = atoi(tmp);
      gfx->y = atoi(buf);
      printf("x[%d], y[%d]\n", gfx->x, gfx->y);
    }
  return (0);
}
