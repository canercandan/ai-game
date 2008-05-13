/*
** server.h for zappy in /u/epitech_2010s/candan_c/cu/rendu/c/zappy
** 
** Made by caner candan
** Login   <candan_c@epitech.net>
** 
** Started on  Wed Apr 30 13:37:20 2008 caner candan
** Last update Tue May 13 21:55:40 2008 florent hochwelker
*/

#ifndef __SERVER_H__
# define __SERVER_H__

/*
** Option's flags
*/
# define FLAG_P			1
# define FLAG_X			2
# define FLAG_Y			4
# define FLAG_N			8
# define FLAG_C			16
# define FLAG_T			32

/*
** Defines
*/
# define START_UNIT_LIFE	1000000.0	/* en float */
# define START_LEVEL		1
# define MAX_LEVEL		8

# define FOOD_HP		126.0	/* en float */
# define COEFFICIENT		0.05
# define BUF_SIZE		1024
# define NB_INVENTORY		7
# define LEN_INVENTORY		512
# define MAX_QUEUE		10

/*
** Functions' return
*/
# define LOOP_FOR_SEND		1337
# define RESPAWN		4242

/*
** Zappy's index names
*/
# define NAME_WORLD	"Trantor"

/*
** Default's values
*/
# define DEFAULT_WIDTH		10
# define DEFAULT_LENGHT		10
# define DEFAULT_NB_PLAYER	6
# define DEFAULT_TIME		1

/*
** Limits' values
*/
# define MAX_LISTEN	42

/*
** Error's messages
*/
# define ERR_SIZE_MAP	"create_world: your width and lenght must"	\
			"be an integer\n"

/*
** Terminal's messages
*/
# define PWR_OFF_MESG	"\nPower off of ZaPPy server ...\n"

/*
** Null
*/
# ifndef NULL
#  define NULL	(void *)0
# endif /* !NULL */

/*
** Macro useful
*/
# define IS_PRINTABLE(c)	(((c) <= 32 || (c) > 126) ? 1 : 0)
# define ABS(x)			(((x) < 0) ? (x) * -1 : (x))
# define PWR(x)			(1 << (x))

/*
** Macro to cast
*/
# define TIMEVAL(data)		((struct timeval *)(data))
# define CLIENT(data)		((t_client *)(data))

/*
** Macro send
*/
# define SEND(buff, txt)	(strncat(buff, txt, BUF_SIZE - strlen(buff)))

/*
** Status client
*/
typedef	enum
  {
    ST_NOT_LOGGED,
    ST_WELCOME_OK,
    ST_SERVER,
    ST_CLIENT,
    ST_OBS_CLIENT,
    ST_DEAD,
    ST_DISCONNECT,
    ST_BIRD
  }	t_status;

/*
** Alias
*/
typedef void	(*fct)();

/*
** Gerneric list of list chaine
*/
typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

/*
** Options' structure
*/
typedef struct	s_opt
{
  int		opt;
  char		*name;
  char		*desc;
  int		(*fun)();
}		t_opt;

/*
** Team's structure
*/
typedef struct	s_team
{
  char		*name;
  int		nb;	/* nb de client connecte */
  int		max;	/* nb max de client */
}		t_team;

/*
** Clients' structure
*/
typedef struct	s_client
{
  int		socket;
  t_status	status;
  fct		fct_read;
  fct		fct_write;
  char		buf_read[BUF_SIZE + 1];
  char		buf_write[BUF_SIZE + 1];
  char		level;
  double	hp;
  int		x;
  int		y;
  char		direction;
  t_team	*team;
  int		qte_ressource[NB_INVENTORY];
}		t_client;

/*
** One case of the map
*/
typedef struct	s_zone
{
  char		is_moveable;
  int		id_deco;
  t_list	*ressources;
  t_list	*clients;
}		t_zone;

/*
** Info about the game
*/
typedef struct	s_info
{
  int		port;
  int		x;
  int		y;
  t_list	*team;
  int		nb_player;
  float		time;
  t_list	*clients;
  void		*timeout;
  t_list	*queue;
  t_zone	**zone;
  t_list	*observator;
}		t_info;

/*
** Queue actions' structure
*/
typedef struct	s_queue
{
  int		(*f)(char *cmd, t_client *cli, t_info *info);
  char		idx_f;
  char		*param;
  void		*time;
  t_client	*client;
}		t_queue;

/*
** Actions list's strutcture
*/
typedef struct	s_action
{
  int	       	action;
  char		*str;
  unsigned int 	delay;
  int	       	(*f)(char *cmd, t_client *cli, t_info *info);
}	       	t_action;

/*
** Ressources list's structure
*/
typedef struct	s_ressource
{
  char		idx;
  char		*name;
  char		*desc;
}		t_ressource;

/*
** Criteres list's structure
*/
typedef struct	s_critere
{
  int		lvl;
  char		idx_ressource;
  int		qte;
}		t_critere;

/*
** Level list's structure
*/
typedef struct	s_level
{
  int		lvl;
  int		nb_client;
}		t_level;

/*
** Global:
*/
extern t_ressource	gl_ressource[];

/*
** Socket's functions
*/
t_client	*add_client(t_info *info, int server);
void		add_server(t_info *info);
void		client_read(t_info *info, t_client **client);
void		client_write(t_info *info, t_client *client);
void		client_disconnect(t_client *client, t_info *info);
void		server_get(t_info *info);
void		server_read(t_info *info, t_client **client);
void		server_write(t_info *info, t_client *client);
int		execute_action(char *str, t_client *cli, t_info *info);
int		scheduler_exec(t_info *info, void *tp);
void		calculate_timeout(t_info *info, void *tp);
int		send_buf_to_client(t_client *client, char *buf);
void		send_info_to_obs(t_client *client, t_info *info);

/*
** Observator's functions
*/
void		obs_add_client_in_char(char *buf, t_client *client, t_info *info, int socket);
void		obs_new_client(t_list *obs, t_client *client, t_info *info);
void		obs_send_action(int socket, t_info *info, char idx_f, char *param);

/*
** Options' functions
*/
void		usage_server();
int		is_options(char *args);
t_info		*parse_args(int argc, char **argv, t_info *info);
int		check_flag(int flag);
int		opt_port(t_info *info, char **argv, int i);
int		opt_width(t_info *info, char **argv, int i);
int		opt_lenght(t_info *info, char **argv, int i);
int		opt_name_team(t_info *info, char **argv, int i);
int		opt_nb_player(t_info *info, char **argv, int i);
int		opt_delay(t_info *info, char **argv, int i);

/*
** Zones' functions
*/
t_zone		**create_world(t_info *info);
void		fill_ressources_world(t_zone **world, t_info *info);
t_ressource	*generate_ressources(int i);
int		begin_session(t_info *i, t_client **cli);

/*
** Actions' functions
*/
int	move_up(t_client *client, char direction, t_info *info);
int	act_up(char *param, t_client *client, t_info *info);
int	act_right(char *param, t_client *client, t_info *info);
int	act_left(char *param, t_client *client, t_info *info);
int	act_see(char *param, t_client *client, t_info *info);
int	act_inventory(char *param, t_client *client, t_info *info);
int	act_take_obj(char *param, t_client *client, t_info *info);
int	act_drop_obj(char *param, t_client *client, t_info *info);
int	act_kick(char *param, t_client *client, t_info *info);
int	act_bird(char *param, t_client *client, t_info *info);
int	act_broadcast(char *param, t_client *client, t_info *info);
int	act_levelup(char *param, t_client *client, t_info *info);
int	act_levelup_progress(char *param, t_client *client, t_info *info);
int	is_levelmax(t_client *client, t_info *info);
int	act_fork(char *param, t_client *client, t_info *info);
void	get_inventory(t_client *client, char *buff, t_info *info);
void	get_inventory_id(t_client *client, char *buff, t_info *info);
int	act_count(char *param, t_client *client, t_info *info);

/*
** Mathematical's functions
*/
int	power(int nb, int pwr);
int	square_root(int nb);

/*
** Debug's functions
*/
void	debug(char *s, int pos);
void	dump_world(t_zone **zworld, int y, int x);
void	dump_ressources(t_list *ressource);
void	dump_clients(t_list *clients);
void	dump_client_position(t_list *client);

/*
** List chaine's functions
*/
void	push_list(t_list **t, void *data);
void	*pop_list(t_list **t);
void	pop_all_list(t_list **t);

/*
** Clients list chaine's functions
*/
void	*rm_data_from_list(t_list **t, void *data);
void	rm_ressource_from_list(t_list **t, char *name);
void	*get_client_from_list(t_list *t, int socket);
void	show_clients_from_list(t_list *t);
void	sort_queue_list(t_list **begin);
int	count_list(t_list *t);
int	count_list_with_same_lvl(t_list *t, int lvl);
int	count_list_with_same_team_n_lvl(t_list *t, t_team *team, int lvl);
int	exist_data_from_list(t_list *t, void *data);

/*
** Queue list functions
*/
void		rm_client_from_queue(t_list **t, int socket, t_info *info);
t_queue		*create_new_queue(char *str, int (*f)(),
			  void *new_time, t_client *cli);
t_client	*get_disconnect_client_from_team(t_info *info, char *team);


/*
** Client's functions
*/
void	free_client(t_client *client);

/*
** Info's functions
*/
t_info	*init_info();
void	free_info(t_info *info);
int	get_ressource_idx(char *data);
int	get_see_len(t_client *client, t_info *info);
void    is_in_map(t_info *info, int *x, int *y);
int     get_x(t_client *client, int x_diff, int y_diff);
int     get_y(t_client *client, int x_diff, int y_diff);
int	send_ressources(t_info *info, t_client *client, char *buff, int *diff);
int	send_len_ressources(t_info *info, t_client *client,
			    int x_diff, int y_diff);

/*
** Useful functions
*/
char	*get_word_n(char *str, int n);
char	*trim(char *str);
void	putnbr(unsigned int nb, char *buff);

/*
** Random's functions
*/
void	init_random(void);
int	get_random(int max, int diff);

/*
** Signals' functions
*/
void	init_signal(t_info *info);

#endif /* !__SERVER_H__ */
