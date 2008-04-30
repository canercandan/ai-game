/*
** execute_action.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 17:22:42 2008 florent hochwelker
** Last update Tue Apr 29 20:38:12 2008 florent hochwelker
*/

#include "zappy.h"

int		execute_action(char *str, t_client *origin)
{
  int		i;
  t_queue	new_action;

  i = 0;
  while (gl_actions[i].cmd)
    {
      if (strncmp(gl_actions[i].cmd, cmd, strlen(gl_actions[i].cmd)) == 0)
	{
	  new_action->action = gl_actions[i].action;
	  new_action->param = strdup(get_word_n(str));
	  put_in_list(&origin, gl_actions[i]);
	  gl_actions[i].f(cmd, socket);
	}
      i++;
    }
  return (0);
}
