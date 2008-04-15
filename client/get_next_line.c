/*
** get_next_line.c for Client Zappy 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 19:54:47 2008 florent hochwelker
** Last update Fri Apr 11 14:12:16 2008 florent hochwelker
*/

char		*get_next_line(int socket)
{
  static int	i = 0;
  static char	buff[READ_BUFF + 1];
  char		*buff_ret;
  int		count;

  buff[READ_BUFF] = 0;
  buff_ret = malloc(sizeof(*buff_ret) * (READ_BUFF + 1));
  if (i != 0)
    {
      strcpy(buff_ret, buff[i]);
    }
  count = recv(socket, buff, READ_BUFF, 0);
  if (count && count != 1)
    {
      if (strstr(buff, "\n"))
	{
	  i = strstr(buff, "\n");
	  buff[i + 1] = 0;
	  strcpy(buff_ret, buff);
	  return (buff);
	}
      else
	i = count;
    }	
  else if (!count)
    return (0);
}
