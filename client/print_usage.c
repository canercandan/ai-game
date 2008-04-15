/*
** print_usage.c for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 18:56:00 2008 florent hochwelker
** Last update Tue Apr 15 17:35:52 2008 florent hochwelker
*/

void	print_usage(char *arg_zero)
{
  printf("Usage:\n%s -n team_name -p port [-h host]\n", arg_zero);
  exit(-1);
}
