/*
** create_new_queue.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sat May  3 15:39:12 2008 florent hochwelker
** Last update Sat May  3 16:05:06 2008 florent hochwelker
*/

#include <string.h>
#include "x.h"
#include "server.h"

t_queue		*create_new_queue(char *str, int (*f)(),
				  unsigned int new_time, t_client *cli)
{
  t_queue	*new_queue;

  new_queue = xmalloc(sizeof(*new_queue));
  new_queue->f = f;
  new_queue->param = strdup(get_word_n(str, 2));
  new_queue->time = new_time;
  new_queue->client = cli;
  return (new_queue);
}
