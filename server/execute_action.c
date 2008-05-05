/*
** execute_action.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 17:22:42 2008 florent hochwelker
** Last update Mon May  5 14:11:46 2008 florent hochwelker
*/

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "x.h"
#include "server.h"
#include "common.h"

static t_action	actions[] =
  {
    {UP, "avance", 7, act_up},
    {RIGHT, "droite", 7, act_right},
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

static struct timeval	*set_timeout(float delay,
				     t_info *info,
				     struct timeval *cur)
{
  float		tmp;

  cur->tv_sec += info->time * delay;
  tmp = info->time * delay - (int)(info->time * delay);
  cur->tv_usec += tmp * 10e5;
  if (cur->tv_usec > 10e5)
    {
      cur->tv_sec++;
      cur->tv_usec -= 10e5;
    }
  return (cur);
}

static int		get_last_action(struct timeval *empty,
					t_list *queue, t_client *client)
{
  int			i;

  i = 0;
  while (queue && i < MAX_QUEUE)
    {
      if (((t_queue*)queue->data)->client == client)
	{
	  empty->tv_sec =
	    ((struct timeval *)((t_queue*)queue->data)->time)->tv_sec;
	  empty->tv_usec =
	    ((struct timeval *)((t_queue*)queue->data)->time)->tv_usec;
	  i++;
	}
      queue = queue->next;
    }
  if (i == MAX_QUEUE)
    return (0);
  if (i == 0)
    gettimeofday(empty, NULL);
  return (1);
}

int			execute_action(char *str, t_client *cli, t_info *info)
{
  int			i;
  t_queue		*new_queue;
  struct timeval	tp;

  i = 0;
  if (cli->status == ST_CLIENT)
    while (actions[i].str)
      {
	if (strncmp(actions[i].str, str, strlen(actions[i].str)) == 0)
	  {
	    if (get_last_action(&tp, info->queue, cli))
	      {
		new_queue = create_new_queue(str, actions[i].f,
					     set_timeout(actions[i].delay, info,
							 &tp),
					     cli);
		push_list(&info->queue, new_queue);
		sort_queue_list(&info->queue);
	      }
	    return (0);
	  }
	i++;
      }
  strcat(cli->buf_write, KO);
  return (-1);
}
