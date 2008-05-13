/*
** act_bird.c for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon May 12 21:19:27 2008 florent hochwelker
** Last update Mon May 12 21:39:04 2008 florent hochwelker
*/

#include "server.h"

int	act_bird(char *param, t_client *team, t_info *info)
{
  (void)param;
  (void)info;
  ((t_team *)team)->max++;
  return (0);
}
