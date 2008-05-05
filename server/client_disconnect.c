/*
** client_disconnect.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 15:10:27 2008 florent hochwelker
** Last update Mon May  5 17:52:25 2008 caner candan
*/

#include <stdio.h>
#include "server.h"
#include "x.h"

void		client_disconnect(t_client *client, t_info *info)
{
  printf("%d: Connection closed\n", client->socket);
  xclose(client->socket);
  rm_data_from_list(&info->clients, client);
  rm_client_from_queue(&info->queue, client->socket);
  if (client->status == ST_CLIENT)
    client->team->nb--;
  else if (client->status == ST_OBS_CLIENT)
    rm_data_from_list(&info->observator, client);
  free_client(client);
}
