/*
** create_video.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:36:42 2008 caner candan
** Last update Mon May 12 21:06:31 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "observator_2d.h"

int	create_video(t_gfx *gfx)
{
  gfx->infos = (void *) SDL_GetVideoInfo();
  if (!(gfx->video = SDL_SetVideoMode(gfx->x * FLOOR_X, gfx->y * FLOOR_Y,
				      SDL_VI(gfx->infos)->vfmt->BitsPerPixel,
				      SDL_VI(gfx->infos)->video_mem)))
    {
      perror("SDL_SetVideoMode");
      return (-1);
    }
  return (0);
}
