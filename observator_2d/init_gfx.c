/*
** init_gfx.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 21:39:25 2008 caner candan
** Last update Tue May 13 19:41:37 2008 caner candan
*/

#include "observator_2d.h"

int	init_gfx(t_gfx *gfx)
{
  if (init_screen() < 0 ||
      !(gfx->character = load_image(CHARACTER_FILE)) ||
      !(gfx->status = load_image(STATUS_FILE)) ||
      !(gfx->floor = load_image(FLOOR_FILE)))
    return (-1);
  gfx->video = NULL;
  gfx->infos = NULL;
  return (0);
}
