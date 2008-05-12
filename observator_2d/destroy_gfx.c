/*
** destroy_gfx.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:42:03 2008 caner candan
** Last update Mon May 12 21:42:38 2008 caner candan
*/

#include "observator_2d.h"

void	destroy_gfx(t_gfx *gfx)
{
  destroy_surface(gfx->floor);
  destroy_surface(gfx->status);
  destroy_surface(gfx->character);
  destroy_surface(gfx->video);
  destroy_screen();
}
