/*
** catch_keys.c<2> for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:52:56 2008 caner candan
** Last update Mon May 12 19:53:06 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"

int		catch_keys(void)
{
  SDL_Event	event;

  event.type = 0;
  SDL_PollEvent(&event);
  if (event.type == SDL_KEYDOWN)
    if (event.key.keysym.sym == SDLK_ESCAPE)
      return (-1);
  if (event.type == SDL_QUIT)
    return (-1);
  return (0);
}
