/*
** act_see.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 16:24:30 2008 florent hochwelker
** Last update Sat May  3 17:15:06 2008 caner candan
*/

#include <string.h>
#include "server.h"

static void	send_ressources(t_info *info, t_client *client, int x, int y)
{
  t_list	*ressources;

  ressources = info->zone[client->x + x][client->y + y].ressources;
  while (ressources)
    {
      strcat(client->buf_write, SEPARATOR_ELM);
      strcat(client->buf_write, ((t_ressource *) ressources->data)->name);
      ressources = ressources->next;
    }
  strcat(client->buf_write, SEPARATOR_CMD);
}

int	act_see(char *param, t_client *client, t_info *info)
{
  int	i;

  (void) param;
  dump_client_position(info->clients);
  strcat(client->buf_write, START_CMD);
  send_ressources(info, client, 0, 0);
  for (i = 0; i < client->level; i++)
    send_ressources(info, client, 0, i);
  strcat(client->buf_write, END_CMD);
  return (0);
}
