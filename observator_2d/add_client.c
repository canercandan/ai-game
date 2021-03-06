/*
** add_client.c for zappy in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Jun  9 20:34:37 2008 caner candan
** Last update Thu Jun 12 10:52:17 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"
#include "x.h"

void		add_client(t_info *info, char **buf)
{
  t_client	*client;
  int		is_egg;
  int		i;

  client = xmalloc(sizeof(*client));
  put_int_from_buf(&is_egg, buf);
  put_int_from_buf(&(client->id), buf);
  put_char_from_buf(&(client->team_name), buf);
  put_int_from_buf(&(client->team_id), buf);
  put_int_from_buf(&(client->level), buf);
  put_float_from_buf(&(client->x), buf);
  put_float_from_buf(&(client->y), buf);
  put_int_from_buf(&(client->direction), buf);
  client->anim = 0;
  for (i = 0; i < NB_OBJECT - 1; i++)
    put_int_from_buf(&(client->inventory[i]), buf);
  push_list(&(info->clients), client);
  if (is_egg)
    if (info->object[(int)client->x][(int)client->y][EGGOBJ] > 0)
      info->object[(int)client->x][(int)client->y][EGGOBJ]--;
}
