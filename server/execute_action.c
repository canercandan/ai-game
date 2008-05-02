/*
** execute_action.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 17:22:42 2008 florent hochwelker
** Last update Fri May  2 15:01:55 2008 florent hochwelker
*/

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"

static t_action	actions[] =
  {
    {UP, "avance", 7, act_up},
    {RIGHT, "droit", 7, act_right},
    {LEFT, "gauche", 7, act_left},
    {SEE, "voir", 1, act_see},
    {INVENTORY, "inventaire", 1, act_inventory},
    {TAKE_OBJ, "prend", 7, act_take_obj},
    {DROP_OBJ, "pose", 7, act_drop_obj},
    {KICK, "expulse", 7, act_kick},
    {BROADCAST, "broadcast", 7, act_broadcast},
    {LEVELUP, "incantation", 300, act_levelup},
    {FORK, "fork", 42, act_fork},
    {0, 0, 0, 0}
  };

int		execute_action(char *str, t_client *cli, t_info *info)
{
  int		i;
  unsigned int	cur_time;
  t_queue	*new_queue;

  i = 0;
  while (actions[i].str)
    {
      if (strncmp(actions[i].str, str, strlen(actions[i].str)) == 0)
	{
	  cur_time = time(NULL);
	  new_queue = malloc(sizeof(*new_queue));
	  new_queue->f = actions[i].f;
	  new_queue->param = strdup(get_word_n(str, 2));
	  new_queue->time = cur_time + actions[i].delay;
	  new_queue->client = cli;
	  push_list(&info->queue, new_queue);
	  sort_queue_list(&info->queue);
	  ((struct timeval *) (info->timeout))->tv_sec =
	    ((t_queue *)info->queue->data)->time - cur_time;
	  return (0);
	}
      i++;
    }
  return (-1);
}
