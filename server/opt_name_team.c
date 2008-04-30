/*
** opt_name_team.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:43:36 2008 majdi toumi
** Last update Wed Apr 30 12:29:11 2008 majdi toumi
*/

#include "x.h"
#include "server.h"

int		opt_name_team(t_info *info, char **argv, int i)
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
