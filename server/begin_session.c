/*
** begin_session.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  2 15:30:40 2008 florent hochwelker
** Last update Sat May  3 14:31:44 2008 florent hochwelker
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
      if (strcmp(name, ((t_team *)list_team->data)->name) == 0)
	{
	  cli->status = ST_CLIENT;
	  return (list_team->data);
	}
      list_team = list_team->next;
    }
  if (strcmp(name, OBS_CLIENT) == 0)
    return (1);
  return (0);
}

static void	check_team_and_connect(t_client *cli, char *name,
				       t_info *info, t_team *team)
{
  name = trim(cli->buf_read);
  if ((team = get_team(name, info)) > 1)
    {
      team->nb++;
      snprintf(cli->buf_write, BUF_SIZE, "%d\n%d %d\n",
	       team->max - team->nb + 1, info->x, info->y);
    }
  else if (team == 1)	/* le client est un observateur */
    {
      /* faire une fonction qui repond a Jordan la c vite fait */
      snprintf(cli->buf_write, BUF_SIZE, "%d %d\n",
	       info->x, info->y);
      push_list(&info->observator, cli);
    }
  else if (team == 0)
    {
      printf("%d: Wrong team name (%s)\n", cli->socket, name);
      client_disconnect(cli, info);
    }
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
    check_team_and_connect(cli, name, info, team);
  return (0);
}
