/*
** get_disconnect_client_from_team.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue May 13 13:52:42 2008 florent hochwelker
** Last update Mon Jun 23 01:31:55 2008 caner candan
*/

#include <string.h>
#include "server.h"

t_client	*get_disconnect_client_from_team(t_info *info,
						 char *team)
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
