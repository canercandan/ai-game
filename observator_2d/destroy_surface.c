/*
** destroy_surface.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:46:16 2008 caner candan
** Last update Mon May 12 19:46:47 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

void	destroy_surface(void *surface)
{
  SDL_FreeSurface(surface);
}
