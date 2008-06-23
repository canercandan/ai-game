/*
** draw_gfx.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed May 14 08:56:50 2008 caner candan
** Last update Mon Jun 23 03:16:58 2008 caner candan
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

static void	put_clients(t_info *info, int anim)
{
  t_list	*t;
  t_param	p;

  sort_client_list(&info->clients);
  t = info->clients;
  while (t)
    {
      if (!anim)
	put_direction_to_anim(t->data);
      p.x = (CLIENT(t->data)->x + 1) * FLOOR_X;
      p.y = CLIENT(t->data)->y * FLOOR_Y;
      p.anim = CLIENT(t->data)->anim
	+ (16 * (CLIENT(t->data)->level - 1));
      p.gfx = BIBI + (CLIENT(t->data)->team_id % NB_CHARACTER);
      set_object(info->gfx, &p);
      t = t->next;
    }
}

static void	put_object(t_info *info)
{
  t_param	p;
  int		x;
  int		y;
  int		z;

  for (x = 0; x < info->x - 2; x++)
    for (y = 0; y < info->y - 2; y++)
      for (z = 0; z < NB_OBJECT; z++)
	if (info->object[x][y][z])
	  {
	    p.gfx = OBJECT;
	    p.x = (x + 1) * FLOOR_X;
	    p.y = (y + 1) * FLOOR_Y;
	    p.anim = z;
	    set_object(info->gfx, &p);
	  }
}

static void	put_status(t_info *info)
{
  t_param	p;
  int		x;
  int		y;

  for (x = 0; x < info->x - 2; x++)
    for (y = 0; y < info->y - 2; y++)
      if (info->status[x][y] >= 0)
	{
	  p.gfx = STATUS;
	  p.x = (x + 1) * FLOOR_X;
	  p.y = (y + 1) * FLOOR_Y;
	  if (info->status[x][y] == BROADCAST)
	    p.anim = 0;
	  else if (info->status[x][y] == LEVELUP_PROGRESS)
	    p.anim = 2;
	  else if (info->status[x][y] == LEVELUP)
	    p.anim = 8;
	  else if (info->status[x][y] == TAKE_OBJ)
	    p.anim = 20;
	  else if (info->status[x][y] == DROP_OBJ)
	    p.anim = 9;
	  if (info->status[x][y] != LEVELUP_PROGRESS)
	    info->status[x][y] = -1;
	  set_object(info->gfx, &p);
	}
}

int	draw_gfx(t_info *info, int anim)
{
  if (!info->x || !info->y)
    return (-1);
  set_backdrop(info);
  put_object(info);
  if (info->clients)
    put_clients(info, anim);
  put_status(info);
  SDL_Flip(info->gfx->video);
  SDL_Delay(1);
  return (0);
}
