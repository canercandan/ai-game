/*
** begin_session.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Fri May  2 15:30:40 2008 florent hochwelker
** Last update Wed Jun 11 22:08:08 2008 florent hochwelker
*/

#include <stdio.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "common.h"
#include "server.h"

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

static int		inc_and_check_max_user(t_team *team, t_client **client,
					       t_info *info)
{
  struct timeval	tp;
  t_client		*cli;

  gettimeofday(&tp, NULL);
  if (team->nb == team->max)
    strcat((*client)->buf_write, KO);
  else if ((cli = get_disconnect_client_from_team(info, team->name)))
    {
      cli->socket = (*client)->socket;
      cli->status = ST_RESPAWN;
      rm_data_from_list(&info->clients, *client);
      free_client(*client);
      *client = cli;
      team->nb++;
      printf("RESPAWN BABY !!\n");
      return (RESPAWN);
    }
  else
    {
      (*client)->hp = tp.tv_sec + START_UNIT_LIFE * FOOD_HP * info->time;
      (*client)->status = ST_CLIENT;
    }
  team->nb++;
  return (1);
}

static void	send_map_and_nb_connect(t_client *cli, t_team *team, t_info *info)
{
  /* this */
  /*   putnbr(team->max - team->nb, cli->buf_write); */
  /* replaced by this */

  snprintf(cli->buf_write, sizeof(cli->buf_write),
	   "%d", team->max - team->nb);

  /* end */

  SEND(cli->buf_write, "\n");
  putnbr(info->x, cli->buf_write);
  SEND(cli->buf_write, " ");
  putnbr(info->y, cli->buf_write);
  SEND(cli->buf_write, "\n");
}

static int	check_team_and_connect(t_client **cli, t_info *info)
{
  char		*name;
  t_team	*team;
  int		res;

  name = trim((*cli)->buf_read);
  if ((team = get_team(name, info)) > (t_team*)1) /* team OK */
    {
      if ((res = inc_and_check_max_user(team, cli, info)) == 0)
	return (0);
      (*cli)->team = team;
      if (res != RESPAWN)
	obs_new_client(info->observator, *cli, info, 0);
      send_map_and_nb_connect(*cli, team, info);
    }
  else if (team == (t_team*)1)	/* le client est un observateur */
    {
      (*cli)->status = ST_OBS_CLIENT;
      push_list(&info->observator, *cli);
      send_info_to_obs(*cli, info);
    }
  else if (team == 0)
    strcat((*cli)->buf_write, KO);
  return (1);
}

int		begin_session(t_info *info, t_client **cli)
{
  if ((*cli)->status == ST_NOT_LOGGED)
    {
      strcpy((*cli)->buf_write, "BIENVENUE\n");
      (*cli)->status = ST_WELCOME_OK;
    }
  else if ((*cli)->status == ST_WELCOME_OK)
    check_team_and_connect(cli, info);
  return (0);
}
