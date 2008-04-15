/*
** enter_in_the_world.c for Client Zappy 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 19:18:20 2008 florent hochwelker
** Last update Thu Apr 10 19:44:24 2008 florent hochwelker
*/

static int	step_two(int socket)
{
  int	count;
  char	buff[1024];

  if ((count = recv(socket, buff, 1024, 0)) != 1)
    {
      if (strncmp(buff, MSG_WELCOME, strlen(MSG_WELCOME)) == 0)
	{
	  snprintf(buff, 1024, "%s\n", team_name);
	  send(socket, buff, strlen(buff), 0);
	  return (0);
	}
    }
  return (-1);
}

static int	step_one(int socket, char *team_name)
{
  int		count;
  char		buff[1024];

  if ((count = recv(socket, buff, 1024, 0)) != 1)
    {
      if (strncmp(buff, MSG_WELCOME, strlen(MSG_WELCOME)) == 0)
	{
	  snprintf(buff, 1024, "%s\n", team_name);
	  send(socket, buff, strlen(buff), 0);
	  return (0);
	}
    }
  return (-1);
}

int	enter_in_the_world(int socket, char *team_name)
{
  if (step_one(socket, team_name) != -1 &&
      step_two(socket) != -1 &&
      step_three(socket) != -1)
    {
      printf("[%d] I enter in the world\n", socket);
    }
}
