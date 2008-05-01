/*
** client_disconnect.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu May  1 15:10:27 2008 florent hochwelker
** Last update Thu May  1 15:51:04 2008 florent hochwelker
*/

#include <stdio.h>
#include "server.h"
#include "x.h"

void	client_disconnect(t_client *client, t_info *info)
{
  printf("%d: Connection closed\n", client->socket);
  xclose(client->socket);
  pop_client_from_list(&info->clients, client->socket);
}
