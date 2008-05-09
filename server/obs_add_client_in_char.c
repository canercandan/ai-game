/*
** obs_add_client_in_char.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  9 02:11:04 2008 florent hochwelker
** Last update Fri May  9 17:45:16 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"
#include "common.h"

void	obs_add_client_in_char(char *buf, t_client *client, t_info *info, int socket)
{
  char	buff[LEN_INVENTORY];

  strcat(buf, "ADD_CLIENT ");
  putnbr(socket, buf);
  strcat(buf, " ");
  strcat(buf, client->team->name);
  strcat(buf, " ");
  putnbr(client->level, buf);
  strcat(buf, " ");
  putnbr(client->x, buf);
  strcat(buf, " ");
  putnbr(client->y, buf);
  strcat(buf, " ");
  putnbr(client->direction, buf);
  strcat(buf, " ");
  get_inventory(client, buff, info);
  strcat(buf, buff);
}
