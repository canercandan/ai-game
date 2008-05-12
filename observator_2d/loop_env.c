/*
** loop_env.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:40:02 2008 caner candan
** Last update Mon May 12 21:19:10 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

int	loop_env(t_gfx *gfx)
{
  (void) gfx;
  if (catch_keys() < 0)
    return (-1);
  set_backdrop(gfx);
  set_character(gfx, 0, 2, 2);
  set_status(gfx, 0, 2, 2);
  set_character(gfx, 0, 7, 7);
  set_status(gfx, 0, 7, 7);
  SDL_Flip(gfx->video);
  SDL_Delay(DELAY);
  return (0);
}
