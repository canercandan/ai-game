/*
** move_up.c<2> for observator_2d in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue Jun 24 13:50:06 2008 caner candan
** Last update Tue Jun 24 13:55:21 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

static void	anim_to_north(int dst, t_client *client, t_info *info)
{
  if (dst < 0)
    client->y = ((float) info->y) - 3.0;
  else
    while (client->y - 0.1 > (float) dst)
      {
	client->anim++;
	if (client->anim > 15)
	  client->anim = 12;
	draw_gfx(info, 1);
	client->y -= 0.1;
      }
  client->y = round_nbr(client->y);
}

static void	anim_to_south(int dst, t_client *client, t_info *info)
{
  if (dst > info->y - 3)
    client->y = 0;
  else
    while (client->y + 0.1 < (float) dst)
      {
	client->anim++;
	if (client->anim > 3)
	  client->anim = 0;
	draw_gfx(info, 1);
	client->y += 0.1;
      }
  client->y = round_nbr(client->y);
}

static void	anim_to_east(int dst, t_client *client, t_info *info)
{
  if (dst > info->x - 3)
    client->x = 0;
  else
    while (client->x + 0.1 < (float) dst)
      {
	client->anim++;
	if (client->anim > 11)
	  client->anim = 8;
	draw_gfx(info, 1);
	client->x += 0.1;
      }
  client->x = round_nbr(client->x);
}

static void	anim_to_west(int dst, t_client *client, t_info *info)
{
  if (dst < 0)
    client->x = ((float) info->x) - 3.0;
  else
    while (client->x - 0.1 > (float) dst)
      {
	client->anim++;
	if (client->anim > 7)
	  client->anim = 4;
	draw_gfx(info, 1);
	client->x -= 0.1;
      }
  client->x = round_nbr(client->x);
}

int	move_up(t_client *client, char direction, t_info *info)
{
  if (direction == NORTH)
    anim_to_north((int)client->y - 1.0, client, info);
  else if (direction == EAST)
    anim_to_east((int)client->x + 1.0, client, info);
  else if (direction == WEST)
    anim_to_west((int)client->x - 1.0, client, info);
  else
    anim_to_south((int)client->y + 1.0, client, info);
  return (0);
}
