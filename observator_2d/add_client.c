/*
** add_client.c for zappy in /home/candan_c/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon Jun  9 20:34:37 2008 caner candan
** Last update Tue Jun 10 09:38:03 2008 caner candan
*/

#include "observator_2d.h"
#include "x.h"

void		add_client(t_info *info, char **buf)
{
  t_client	*client;
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
  for (i = 0; i < NB_OBJECT; i++)
    put_int_from_buf(&(client->inventory[i]), buf);
  push_list(&(info->clients), client);
}
