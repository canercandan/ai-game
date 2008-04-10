/*
** server.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 09:10:57 2008 majdi toumi
** Last update Thu Apr 10 09:24:06 2008 majdi toumi
*/

#include <stdio.h>
#include "server.h"

int		main(int ac, char **av)
{
  if (!parse_args(ac, av))
    usage_server();
}
