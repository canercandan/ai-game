/*
** begin_session.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  2 15:30:40 2008 florent hochwelker
** Last update Sun May  4 15:01:01 2008 florent hochwelker
*/

#include <server.h>
#include <stdio.h>
#include "common.h"
#include "string.h"

static t_team	*get_team(char *name, t_info *info)
{
  t_list	*list_team;

  list_team = info->team;
  while (list_team)
    {
      if (strcmp(name, ((t_team *)list_team->data)->name) == 0)
	return (list_team->data);
      list_team = list_team->next;
    }
  if (strcmp(name, MAGIC_OBS) == 0)
    return ((t_team*)1);
  return (0);
}

static void	bye(t_error err, t_client *cli)
{
  if (err == ERR_WRONG_TEAM_NAME)
    printf("%d: Wrong team name  ... bye\n", cli->socket);
  else if (err == ERR_MAX_CLIENT)
    printf("%d: Max client ... try to fork :) bye\n", cli->socket);
  strcat(cli->buf_write, KO);
}

static int	inc_and_check_max_user(t_team *team, t_client *client)
{
  if (team->nb == team->max)
    {
      bye(ERR_MAX_CLIENT, client);
      return (0);
    }
  team->nb++;
  return (1);
}

static int	check_team_and_connect(t_client *cli, t_info *info)
{
  char		*name;
  t_team	*team;

  name = trim(cli->buf_read);
  if ((team = get_team(name, info)) > (t_team*)1) /* team OK */
    {
      if (!inc_and_check_max_user(team, cli))
	return (0);
      cli->status = ST_CLIENT;
      cli->team = team;
      snprintf(cli->buf_write, BUF_SIZE, "%d\n%d %d\n",
	       team->max - team->nb + 1, info->x, info->y);
    }
  else if (team == (t_team*)1)	/* le client est un observateur */
    {
      cli->status = ST_OBS_CLIENT;
      push_list(&info->observator, cli);
      send_info_to_obs(cli, info);
    }
  else if (team == 0)
    bye(ERR_WRONG_TEAM_NAME, cli);
  return (1);
}

int		begin_session(t_info *info, t_client *cli)
{
  if (cli->status == ST_NOT_LOGGED)
    {
      strcpy(cli->buf_write, "BIENVENUE\n");
      cli->status = ST_WELCOME_OK;
    }
  else if (cli->status == ST_WELCOME_OK)
    check_team_and_connect(cli, info);
  return (0);
}
