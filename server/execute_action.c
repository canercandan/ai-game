/*
** execute_action.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 17:22:42 2008 florent hochwelker
** Last update Wed Apr 30 17:54:20 2008 florent hochwelker
*/

#include <sys/type.h>
#include <time.h>
#include "server.h"

int		execute_action(char *str, t_client *cli, t_info *info)
{
  int		i;
  t_queue	new_action;
  time_t	timeout;

  i = 0;
  while (gl_actions[i].cmd)
    {
      if (strncmp(gl_actions[i].cmd, cmd, strlen(gl_actions[i].cmd)) == 0)
	{
	  new_action->action = gl_actions[i].action;
	  new_action->param = strdup(get_word_n(str));
	  new_action->timeout = time(0) + gl_actions[i].delay;
	  put_in_list(&cli->queue, new_action);
	  if (((struct timeval *) (info->timeout))->tv_sec > gl_actions[i].delay)
	    ((struct timeval *) (info->timeout))->tv_sec = gl_actions[i].delay;
	  i++;
	}
      return (0);
    }
}
