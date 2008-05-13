/*
** main.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Mon May 12 19:17:53 2008 caner candan
** Last update Tue May 13 20:16:44 2008 caner candan
*/

#include "observator_2d.h"

int		main(int ac, char **av)
{
  t_info	info;
  t_gfx		gfx;

  init_info(&info);
  init_signal(&info, &gfx);
  parse_args(ac, av, &info);
  if (create_socket(&info) < 0)
    return (-1);
  if (get_header(&info) < 0)
    return (-1);
  if (init_gfx(&gfx) < 0)
    return (-1);
  while (42)
    if (loop_env(&info, &gfx) < 0)
      break;
  destroy_gfx(&gfx);
  destroy_info(&info);
  return (0);
}
