/*
** get_options.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 14:03:29 2008 majdi toumi
** Last update Thu Apr 10 17:19:40 2008 majdi toumi
*/

#include <stdlib.h>
#include "server.h"

int		get_port(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->port = atoi(argv[i]);
  return (i + 1);
}

int		get_width(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->width = atoi(argv[i]);
  return (i + 1);
}

int		get_lenght(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->lenght = atoi(argv[i]);
  return (i + 1);
}

int		get_name_team(t_info *info, char **argv, int i)
{
  t_list	*begin;
  t_list	*new_elt;

  begin = 0;
  while (argv[i] && (is_options(argv[i]) == -1))
    {
      new_elt = xmalloc(sizeof(*new_elt));
      new_elt->data = argv[i];
      new_elt->next = begin;
      begin = new_elt;
      i++;
    }
  info->team = begin;
 return (i);
}

int		get_nb_player(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->nb_player = atoi(argv[i]);
  return (i + 1);
}

int		get_delay(t_info *info, char **argv, int i)
{
  if (argv[i])
    info->time = atoi(argv[i]);
  return (i + 1);
}

