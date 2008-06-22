/*
** client_disconnect.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 15:10:27 2008 florent hochwelker
** Last update Mon Jun 23 01:11:45 2008 caner candan
*/

#include <stdio.h>
#include "server.h"
#include "x.h"

void	client_disconnect(t_client *client, t_info *info)
{
  printf("%d: Connection closed\n", client->id);
  xclose(client->socket);
  rm_client_from_queue(&info->queue, client->id, info);
  if (client->status == ST_CLIENT)
    {
      client->team->nb--;
      client->status = ST_DISCONNECT;
      client->buf_write[0] = 0;
      client->buf_read[0] = 0;
    }
  else if (client->status == ST_OBS_CLIENT)
    {
      rm_data_from_list(&info->zone[client->x][client->y].clients, client);
      rm_data_from_list(&info->observator, client);
      rm_data_from_list(&info->clients, client);
      free_client(client);
    }
  else
    {
      rm_data_from_list(&info->zone[client->x][client->y].clients, client);
      rm_data_from_list(&info->clients, client);
      free_client(client);
    }
}
