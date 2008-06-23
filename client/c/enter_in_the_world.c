/*
** enter_in_the_world.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 19:18:20 2008 florent hochwelker
** Last update Mon Jun  9 19:00:58 2008 florent hochwelker
*/

#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "client.h"
#include "x.h"

static void	get_x_y_map(t_info *info, char *buff)
{
  char		*save;

  save = buff;
  buff = strchr(buff, '\n');
  info->x = atoi(buff);
  info->y = atoi(strchr(buff, ' '));
  free(save);
}

static int	step_two(t_info *info)
{
  char		*p;

  if (!(p = check_response(info)))
    return (-1);
  if (!isdigit(*p))
    return (-1);
  if (atoi(p) >= 1)
    fork_in_the_word(info);
  else
    get_x_y_map(info, p);
  return (0);
}

static int	step_one(t_info *info)
{
  char		*p;

  if (!(p = check_response(info)))
    return (-1);
  if (strncmp(p, MSG_WELCOME, strlen(MSG_WELCOME)))
    return (-1);
  xsend(info->socket, info->team_name, strlen(info->team_name), 0);
  xsend(info->socket, "\n", 1, 0);
  free(p);
  return (0);
}

int	enter_in_the_world(t_info *info)
{
  char	*p;

  if (step_one(info) < 0 || step_two(info) < 0)
    return (-1);
  srandom(getpid());
  printf("[%d] I enter in the world\n", info->socket);
  printf("map X = %d, Y = %d\n", info->x, info->y);
  xsend(info->socket, "voir\n", strlen("voir\n"), 0);
  while ((p = check_response(info)))
    {
      printf("<-- [%s]", p);
      free(p);
      p = get_rnd_action();
      sleep(1);
      xsend(info->socket, p, strlen(p), 0);
    }
  return (0);
}
