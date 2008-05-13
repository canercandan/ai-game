/*
** execute_action.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Tue May 13 16:43:47 2008 caner candan
** Last update Tue May 13 19:16:26 2008 caner candan
*/

#include "observator_2d.h"
#include "common.h"

static t_actions	actions[] = {
  {UP, act_up},
  {RIGHT, act_right},
  {LEFT, act_left},
  {TAKE_OBJ, act_take_obj},
  {DROP_OBJ, act_drop_obj},
  {KICK, act_kick},
  {BROADCAST, act_broadcast},
  {LEVELUP, act_levelup},
  {FORK, act_fork},
  {COUNT, act_count},
  {BIRD, act_bird},
  {-1, NULL}
};

void		execute_action(t_info *info, char **buf, char *first)
{
  t_client	*client;
  int		id;
  int		action;
  char		*param;
  int		i;

  put_int_from_buf(&id, &first);
  put_int_from_buf(&action, buf);
  put_char_from_buf(&param, buf);
  client = get_client_from_list(info->clients, id);
  for (i = 0; actions[i].idx >= 0; i++)
    if (actions[i].idx == action)
      actions[i].f(info, client, param);
  dump_clients(info);
}
