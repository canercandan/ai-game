/*
** get_disconnect_client_from_team.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue May 13 13:52:42 2008 florent hochwelker
** Last update Tue May 13 16:47:22 2008 florent hochwelker
*/

#include <string.h>
#include "server.h"

t_client	*get_disconnect_client_from_team(t_info *info, char *team)
{
  t_list	*client;

  client = info->clients;
  while (client)
    {
      if (CLIENT(client->data)->status == ST_DISCONNECT &&
	  !strcmp(CLIENT(client->data)->team->name, team))
	return (client->data);
      client = client->next;
    }
  return (NULL);
}
