/*
** obs_add_client_in_char.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  9 02:11:04 2008 florent hochwelker
** Last update Wed Jun  4 19:59:56 2008 caner candan
*/

#include <string.h>
#include "server.h"
#include "common.h"

void	obs_add_client_in_char(char *buf, t_client *client,
			       t_info *info, int id)
{
  char	buff[LEN_INVENTORY];

  strcat(buf, "ADD_CLIENT ");
  putnbr(id, buf);
  strcat(buf, " ");
  strcat(buf, client->team->name);
  strcat(buf, " ");
  putnbr(get_position_from_list(info->team, client->team), buf);
  strcat(buf, " ");
  putnbr(client->level, buf);
  strcat(buf, " ");
  putnbr(client->x, buf);
  strcat(buf, " ");
  putnbr(client->y, buf);
  strcat(buf, " ");
  putnbr(client->direction, buf);
  strcat(buf, " ");
  get_inventory_id(client, buff, info);
  strcat(buf, buff);
}
