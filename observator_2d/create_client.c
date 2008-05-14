/*
** create_client.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 11:02:18 2008 caner candan
** Last update Wed May 14 10:28:53 2008 caner candan
*/

#include <string.h>
#include <stdlib.h>
#include "observator_2d.h"
#include "common.h"
#include "x.h"

void		create_client(t_info *info, char **buf)
{
  t_client	*client;
  t_inventory	*inventory;
  int		i;

  client = xmalloc(sizeof(*client));
  put_int_from_buf(&(client->id), buf);
  put_char_from_buf(&(client->team_name), buf);
  put_int_from_buf(&(client->level), buf);
  put_float_from_buf(&(client->x), buf);
  put_float_from_buf(&(client->y), buf);
  put_int_from_buf(&(client->direction), buf);
  client->anim = 0;
  strsep(buf, START_CMD);
  for (i = 0; i < NB_INVENTORY; i++)
    {
      inventory = xmalloc(sizeof(*inventory));
      put_int_from_buf(&(inventory->idx), buf);
      put_int_from_buf(&(inventory->qte), buf);
      push_list(&(client->inventory), inventory);
    }
  push_list(&(info->clients), client);
  dump_clients(info);
}
