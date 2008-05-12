/*
** load_image.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:24:27 2008 caner candan
** Last update Mon May 12 19:39:01 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "observator_2d.h"

void	*load_image(char *path)
{
  void	*image;

  if (!(image = (void *) SDL_LoadBMP(path)))
    {
      perror("SDL_LoadBMP");
      return (NULL);
    }
  return (image);
}
