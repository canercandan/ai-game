/*
** execute_action.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 17:22:42 2008 florent hochwelker
** Last update Wed Apr 30 19:43:40 2008 florent hochwelker
*/

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

int		execute_action(char *str, t_client *cli, t_info *info)
{
  int		i;
  t_queue	*new_action;

  i = 0;
  while (gl_actions[i].str)
    {
      if (strncmp(gl_actions[i].str, str, strlen(gl_actions[i].str)) == 0)
	{
	  new_action = malloc(sizeof(*new_action));
	  new_action->action = gl_actions[i].action;
	  new_action->param = strdup(get_word_n(str, 2));
	  new_action->time = time(0) + gl_actions[i].delay;
	  new_action->client = cli;
	  push_list(&info->queue, new_action);
	  if (((struct timeval *) (info->timeout))->tv_sec > (long)gl_actions[i].delay)
	    {
	      ((struct timeval *) (info->timeout))->tv_sec = gl_actions[i].delay;
	      sort_queue_list(&info->queue);
	    }
	  i++;
	}
      return (0);
    }
  return (-1);
}
