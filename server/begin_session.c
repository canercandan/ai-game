/*
** begin_session.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  2 15:30:40 2008 florent hochwelker
** Last update Fri May  2 18:35:59 2008 florent hochwelker
*/

#include <server.h>
#include <stdio.h>
#include "string.h"

static t_team	*get_team(char *name, t_info *info)
{
  t_list	*list_team;

  list_team = info->team;
  while (list_team)
    {
      printf("current team = [%s]\n", ((t_team *)list_team->data)->name);
      if (strcmp(name, ((t_team *)list_team->data)->name) == 0)
	return (list_team->data);
      list_team = list_team->next;
    }
  return (0);
}

int		begin_session(t_info *info, t_client *cli)
{
  t_team	*team;
  char		*name;

  if (cli->status == ST_NOT_LOGGED)
    {
      strcpy(cli->buf_write, "BIENVENUE\n");
      cli->status = ST_WELCOME_OK;
    }
  else if (cli->status == ST_WELCOME_OK)
    {
      name = trim(cli->buf_read);
      if ((team = get_team(name, info)))
	{
	  team->nb++;
	  snprintf(cli->buf_write, BUF_SIZE, "%d\n%d %d\n",
		   team->max - team->nb + 1, info->x, info->y);
	  cli->status = ST_CLIENT;
	}
      else
	{
	  printf("%d: Wrong team name (%s)\n", cli->socket, name);
	  client_disconnect(cli, info);
	}
    }
  return (0);
}
