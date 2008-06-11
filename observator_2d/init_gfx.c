/*
** init_gfx.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:39:25 2008 caner candan
** Last update Wed Jun 11 19:27:14 2008 caner candan
*/

#include "observator_2d.h"

int	init_gfx(t_gfx *gfx)
{
  int	i;

  if (init_screen() < 0)
    return (-1);
  for (i = 0; i < NB_GFX; i++)
    gfx->object[i] = NULL;
  gfx->video = NULL;
  gfx->infos = NULL;
  return (0);
}
