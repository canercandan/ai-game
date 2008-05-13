/*
** create_video.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:36:42 2008 caner candan
** Last update Tue May 13 19:43:48 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "observator_2d.h"

int	create_video(t_info *info, t_gfx *gfx)
{
  gfx->infos = (void *) SDL_GetVideoInfo();
  if (!(gfx->video = SDL_SetVideoMode(info->x * FLOOR_X, info->y * FLOOR_Y,
				      SDL_VI(gfx->infos)->vfmt->BitsPerPixel,
				      SDL_VI(gfx->infos)->video_mem)))
    {
      perror("SDL_SetVideoMode");
      return (-1);
    }
  return (0);
}
