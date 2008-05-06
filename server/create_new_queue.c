/*
** create_new_queue.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:39:12 2008 florent hochwelker
** Last update Tue May  6 16:56:13 2008 florent hochwelker
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
  new_queue->param = strdup(get_word_n(str, 2));
  new_queue->time = xmalloc(sizeof(struct timeval));
  ((struct timeval *)(new_queue->time))->tv_sec =
    ((struct timeval *)(new_time))->tv_sec;
  ((struct timeval *)(new_queue->time))->tv_usec =
    ((struct timeval *)new_time)->tv_usec;
  new_queue->client = cli;
  return (new_queue);
}
