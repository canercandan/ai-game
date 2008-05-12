/*
** init_screen.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:45:28 2008 caner candan
** Last update Mon May 12 19:46:03 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "observator_2d.h"

int	init_screen(void)
{
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      perror("SDL_Init");
      return (-1);
    }
  return (0);
}
