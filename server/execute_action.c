/*
** execute_action.c for **zappy** in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/server
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Tue Apr 22 17:22:42 2008 florent hochwelker
** Last update Mon May 12 21:53:34 2008 florent hochwelker
*/

#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include "x.h"
#include "server.h"
#include "common.h"

static t_action		actions[] =
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
    {LEVELUP_PROGRESS, "incantation", 0, act_levelup_progress},
    {LEVELUP, 0, 300, act_levelup},
    {FORK, "fork", 42, act_fork},
    {COUNT, "connect_nbr", 0, act_count},
    {BIRD, 0, 600, act_bird},
    {0, 0, 0, 0},
  };

static struct timeval	*set_timeout(float delay,
				     t_info *info,
				     struct timeval *cur)
{
  float			tmp;

  cur->tv_sec += info->time * delay;
  tmp = info->time * delay - (int)(info->time * delay);
  cur->tv_usec += tmp * 1e6;
  if (cur->tv_usec > 1e6)
    {
      cur->tv_sec++;
      cur->tv_usec -= 1e6;
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
	    TIMEVAL(((t_queue*)queue->data)->time)->tv_sec;
	  empty->tv_usec =
	    TIMEVAL(((t_queue*)queue->data)->time)->tv_usec;
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

static void		set_idx_f(t_queue *new_queue, int i, struct timeval *tp,
				  t_info *info)
{
  t_queue		*queue;

  new_queue->idx_f = i;
  push_list(&info->queue, new_queue);
  if (i == LEVELUP_PROGRESS)
    {
      queue = create_new_queue("", actions[LEVELUP].f,
			       set_timeout(actions[LEVELUP].delay, info,
					   tp), new_queue->client);
      queue->idx_f = LEVELUP;
      push_list(&info->queue, queue);
    }
  if (i == FORK)
    {
      queue = create_new_queue("", actions[BIRD].f,
			       set_timeout(actions[BIRD].delay +
					   actions[FORK].delay, info,
					   tp),
			       (t_client *)new_queue->client->team);
      queue->idx_f = BIRD;
      push_list(&info->queue, queue);
    }
  sort_queue_list(&info->queue);
}

int			execute_action(char *str, t_client *cli, t_info *info)
{
  int			i;
  t_queue		*new_queue;
  struct timeval	tp;

  i = 0;
  if (cli->status == ST_CLIENT)
    while (actions[i].f != 0)
      {
	if (actions[i].str &&
	    strncmp(actions[i].str, str, strlen(actions[i].str)) == 0)
	  {
	    if (get_last_action(&tp, info->queue, cli))
	      {
		new_queue = create_new_queue(str, actions[i].f,
					     set_timeout(actions[i].delay, info,
							 &tp), cli);
		set_idx_f(new_queue, i, &tp, info);
	      }
	    return (0);
	  }
	i++;
      }
  SEND(cli->buf_write, KO);
  return (-1);
}
