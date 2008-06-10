/*
** draw_gfx.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 08:56:50 2008 caner candan
** Last update Tue Jun 10 09:46:18 2008 caner candan
*/

#include <SDL.h>
#include <stdio.h>
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

  sort_client_list(&info->clients);
  t = info->clients;
  while (t)
    {
      if (!anim)
	put_direction_to_anim(t->data);
      if (CLIENT(t->data)->team_id % 2)
	set_character(info->gfx, CLIENT(t->data)->anim,
		      CLIENT(t->data)->x, CLIENT(t->data)->y);
      else
	set_pirate(info->gfx, CLIENT(t->data)->anim,
		   CLIENT(t->data)->x, CLIENT(t->data)->y);
      t = t->next;
    }
}

static void	put_object(t_info *info)
{
  int		x;
  int		y;
  int		z;

  for (x = 0; x < info->x - 2; x++)
    for (y = 0; y < info->y - 2; y++)
      for (z = 0; z < NB_OBJECT; z++)
	if (info->object[x][y][z])
	  set_object(info->gfx, z, x, y + 1);
}

static void	put_broadcast(t_info *info)
{
  int		x;
  int		y;

  for (x = 0; x < info->x - 2; x++)
    for (y = 0; y < info->y - 2; y++)
      if (info->broadcast[x][y])
	{
	  set_status(info->gfx, 0, x + 1, y + 1);
	  info->broadcast[x][y] = 0;
	}
}

int	draw_gfx(t_info *info, char anim)
{
  if (!info->x || !info->y)
    return (-1);
  set_backdrop(info);
  put_object(info);
  if (info->clients)
    put_clients(info, anim);
  put_broadcast(info);
  SDL_Flip(info->gfx->video);
  SDL_Delay(1);
  return (0);
}
