/*
** check_flag.c for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/server
** 
** Made by majdi toumi
** Login   <toumi_m@epitech.net>
** 
** Started on  Thu Apr 10 18:47:32 2008 majdi toumi
** Last update Wed Apr 30 12:34:41 2008 caner candan
*/

#include "server.h"

int		check_flag(int flag)
{
  if (flag & FLAG_P &&
      flag & FLAG_X &&
      flag & FLAG_Y &&
      flag & FLAG_N &&
      flag & FLAG_C &&
      flag & FLAG_T)
    return (1);
  else
    return (0);
}
