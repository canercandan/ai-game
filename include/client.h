/*
** client.h for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 19:11:25 2008 florent hochwelker
** Last update Tue Apr 22 09:52:04 2008 florent hochwelker
*/

#ifndef __CLIENT_H__
# define __CLIENT_H__

# define READ_BUFF	1014
# define MSG_WELCOME	"BIENVENUE\n"

typedef struct		s_map
{
  int			x;
  int			y;
}			t_map;

char	*server_host;

void	print_usage(char *arg_zero);
int	new_connection(char *team_name, char *host, int port);
int	enter_in_the_world(int socket, char *team_name, char *hostname, int port);
char	*check_response(int socket);
int	enter_in_the_world(int socket, char *team_name,
			   char *hostname, int port);
int	fork_in_the_word(char *team_name, char *hostname, int port);

#endif /* !__CLIENT_H__ */
