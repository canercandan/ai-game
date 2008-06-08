/*
** create_client.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 11:02:18 2008 caner candan
** Last update Sat Jun  7 20:05:29 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"
#include "x.h"

void		create_client(t_info *info, char **buf)
{
  t_client	*client;
  int		inventory_idx;
  int		i;

  client = xmalloc(sizeof(*client));
  put_int_from_buf(&(client->id), buf);
  put_char_from_buf(&(client->team_name), buf);
  put_int_from_buf(&(client->team_id), buf);
  put_int_from_buf(&(client->level), buf);
  put_float_from_buf(&(client->x), buf);
  put_float_from_buf(&(client->y), buf);
  put_int_from_buf(&(client->direction), buf);
  client->anim = 0;
  strsep(buf, START_CMD);
  for (i = 0; i < NB_OBJECT; i++)
    {
      put_int_from_buf(&inventory_idx, buf);
      put_int_from_buf(&(client->inventory[inventory_idx]), buf);
    }
  push_list(&(info->clients), client);
  dump_clients(info);
}
