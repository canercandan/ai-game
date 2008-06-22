/*
** opt_name_team.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:43:36 2008 majdi toumi
** Last update Fri Jun 13 19:24:28 2008 majdi toumi
*/

#include <stdio.h>
#include "server.h"
#include "x.h"

int		opt_name_team(t_info *info, char **argv, int i)
{
  t_team	*team;
  void		*data;
  int		flag;

  while ((data = pop_list(&info->team)))
    printf("Team removed: [%s]\n", ((t_team *) (data))->name);
  flag = 0;
  while (argv[i] && (is_options(argv[i]) == -1))
    {
      flag = 1;
      printf("Name %s is added\n", argv[i]);
      team = xmalloc(sizeof(*team));
      team->name = argv[i];
      team->nb = 0;
      team->max = info->nb_player;
      push_list(&info->team, team);
      i++;
    }
  return (flag == 1 ? i : -1);
}
