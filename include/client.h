/*
** client.h for zappy in /u/epitech_2010s/hochwe_f/cu/rendu/c/zappy/zappy/client
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Thu Apr 10 19:11:25 2008 florent hochwelker
** Last update Wed May  7 23:26:26 2008 caner candan
*/

#ifndef __CLIENT_H__
# define __CLIENT_H__

# define BUF_SIZE	1024

# define READ_BUFF	1014
# define MSG_WELCOME	"BIENVENUE\n"
# define NB_ACTIONS	10

/*
** Defaults' values
*/
# define DEFAULT_HOST	"localhost"

/*
** Null's define
*/
# ifndef NULL
#  define NULL	((void *) 0)
# endif /* !NULL */

/*
** Infos' structure
*/
typedef struct	s_info
{
  char		*team_name;
  char		*host;
  int		port;
  int		socket;
  int		x;
  int		y;
}		t_info;

/*
** Useful's functions
*/
void	print_usage(char *arg_zero);
int	new_connection(t_info *info);
int	enter_in_the_world(t_info *info);
char	*check_response(t_info *info);
int	fork_in_the_word(t_info *info);
char	*get_rnd_action();

/*
** Info's functions
*/
t_info	*init_info(void);
void	free_info(t_info *info);

/*
** Parsing's functions
*/
int	parse_args(int ac, char **av, t_info *info);

#endif /* !__CLIENT_H__ */
