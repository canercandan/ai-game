/*
** create_video.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:36:42 2008 caner candan
** Last update Wed May 14 11:37:11 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
#include "observator_2d.h"

int	create_video(t_info *info)
{
  info->gfx->infos = (void *) SDL_GetVideoInfo();
  if (!(info->gfx->video =
	SDL_SetVideoMode(info->x * FLOOR_X,
			 info->y * FLOOR_Y,
			 SDL_VI(info->gfx->infos)->vfmt->BitsPerPixel,
			 SDL_VI(info->gfx->infos)->video_mem)))
    {
      perror("SDL_SetVideoMode");
      return (-1);
    }
  SDL_WM_SetCaption(TITLE, NULL);
  return (0);
}
