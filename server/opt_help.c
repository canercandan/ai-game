/*
** opt_help.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:43:14 2008 majdi toumi
** Last update Fri Jun 13 19:27:25 2008 majdi toumi
*/

#include "server.h"

int	opt_help(t_info *info, char **argv, int i)
{
  (void)info;
  (void)argv;
  (void)i;
  usage_server();
  return (0);
}
