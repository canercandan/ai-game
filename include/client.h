/*
** client.h for Zappy Client 1 in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 19:11:25 2008 florent hochwelker
** Last update Tue Apr 15 18:21:51 2008 caner candan
*/

#ifndef __CLIENT_H__
# define __CLIENT_H__

# define READ_BUFF	1014
# define MSG_WELCOME	"BIENVENUE\n"

char	*server_host;

void	print_usage(char *arg_zero);
int	new_connection(char *team_name, char *host, int port);
int	enter_in_the_world(int socket, char *team_name, char *hostname, int port);

#endif /* !__CLIENT_H__ */
