/*
** init_signal.c for zappy in /home/candan_c/cu/rendu/project/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Thu May  8 12:42:35 2008 caner candan
** Last update Thu May  8 13:16:42 2008 caner candan
*/

#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "server.h"

static void	*signal_data = NULL;

static void	power_off(int signal)
{
  (void) signal;
  write(1, PWR_OFF_MESG, strlen(PWR_OFF_MESG));
  free_info(signal_data);
  exit(0);
}

void	init_signal(t_info *info)
{
  signal_data = info;
  signal(SIGINT, power_off);
}
