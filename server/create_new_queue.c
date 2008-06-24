/*
** create_new_queue.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:39:12 2008 florent hochwelker
** Last update Tue Jun 24 17:34:52 2008 caner candan
*/

#include <sys/time.h>
#include <string.h>
#include "x.h"
#include "server.h"

t_queue		*create_new_queue(char *str, int (*f)(),
				  void *new_time, t_client *cli)
{
  t_queue	*new_queue;

  new_queue = xmalloc(sizeof(*new_queue));
  new_queue->f = f;
  new_queue->param = str;
  new_queue->time = xmalloc(sizeof(struct timeval));
  TIMEVAL((new_queue->time))->tv_sec =
    TIMEVAL((new_time))->tv_sec;
  TIMEVAL((new_queue->time))->tv_usec =
    TIMEVAL(new_time)->tv_usec;
  new_queue->client = cli;
  return (new_queue);
}
