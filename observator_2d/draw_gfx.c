/*
** draw_gfx.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 08:56:50 2008 caner candan
** Last update Wed Jun  4 18:21:37 2008 caner candan
*/

#include <SDL.h>
#include "observator_2d.h"
#include "common.h"

static void	put_direction_to_anim(t_client *client)
{
  if (client->direction == NORTH)
    client->anim = 12;
  else if (client->direction == EAST)
    client->anim = 8;
  else if (client->direction == SOUTH)
    client->anim = 0;
  else
    client->anim = 4;
}

static void	put_clients(t_info *info, char anim)
{
  t_list	*t;

  t = info->clients;
  while (t)
    {
      if (CLIENT(t->data)->id % 2)
	{
	  if (!anim)
	    put_direction_to_anim(t->data);
	  set_character(info->gfx, CLIENT(t->data)->anim,
			CLIENT(t->data)->x, CLIENT(t->data)->y);
	}
      else
	{
	  if (!anim)
	    put_direction_to_anim(t->data);
	  set_pirate(info->gfx, CLIENT(t->data)->anim,
		     CLIENT(t->data)->x, CLIENT(t->data)->y);
	}
      t = t->next;
    }
}

int	draw_gfx(t_info *info, char anim)
{
  if (!info->x || !info->y)
    return (-1);
  set_backdrop(info);
  put_clients(info, anim);
  SDL_Flip(info->gfx->video);
  SDL_Delay(info->time);
  return (0);
}
