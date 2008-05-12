//
// main_usage.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:36:39 2008 majdi toumi
// Last update Mon May 12 13:51:22 2008 majdi toumi
//

#include <unistd.h>
#include <stdlib.h>
#include "observator.h"
#include "common.h"

void	main_usage(void)
{
  write(1, OBS_USAGE, strlen(OBS_USAGE));
  exit(EXIT_SUCC);
}
