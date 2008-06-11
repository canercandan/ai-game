/*
** destroy_gfx.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:42:03 2008 caner candan
** Last update Wed Jun 11 20:16:27 2008 caner candan
*/

#include "observator_2d.h"

void	destroy_gfx(t_gfx *gfx)
{
  int	i;

  for (i = 0; i < NB_GFX; i++)
    if (gfx->object[i])
      destroy_surface(gfx->object[i]);
  destroy_surface(gfx->video);
  destroy_screen();
}
