/*
** observator.h for zappy in /home/aubry_j/zappy/include
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Fri May  2 17:54:35 2008 jordan aubry
** Last update Sat Jun 14 21:19:20 2008 jordan aubry
*/

#ifndef __OBSERVATOR_3D_H__
# define __OBSERVATOR_3D_H__

/* Define general
*/

#define OBS_USAGE		"Usage : ./observator (host) (port)\n"
#define OBS_CASE		192

#define MODE_GRAPH		EDT_BURNINGSVIDEO
#define FAR_VALUE		100000
#define WIN_WEIGHT		640
#define WIN_HEIGHT		480
#define	CAMERA_SPEED		100.0f

#define NB_RESSOURCE		7

#define SOCK_ERROR		"ERROR : Can't connect !\n"

/* Define 3d
*/
#define OBS_NORTH		180
#define OBS_SOUTH		0
#define OBS_EAST		270
#define OBS_WEST		90

/*
** Files
*/
#define OBS_PK3		"map.pk3"

#define SKY_UP		"env/up.tga"
#define SKY_DN		"env/dn.tga"
#define SKY_RT		"env/rt.tga"
#define SKY_LF		"env/lf.tga"
#define SKY_FT		"env/ft.tga"
#define SKY_BK		"env/bk.tga"

#define MAP_CASE	"maps/case.bmp"
#define PALACE		"maps/test.bsp"

/*
** Item's defines
*/
#define ITEM_1	"textures/water.bmp"
#define ITEM_2	"textures/gold.bmp"
#define ITEM_3	"textures/brown.bmp"
#define ITEM_4	"textures/purple.bmp"
#define ITEM_5	"textures/grass.bmp"
#define ITEM_6	"textures/lava.bmp"
#define EGG	"textures/egg.bmp"

#define	INVADER			"models/Invader/invader.md2"
#define	INVADER_1		"models/Invader/i_1.bmp"
#define INVADER_2		"models/Invader/i_2.bmp"
#define INVADER_3               "models/Invader/i_3.bmp"
#define INVADER_4               "models/Invader/i_4.bmp"
#define INVADER_5               "models/Invader/i_5.bmp"
#define INVADER_6               "models/Invader/i_6.bmp"
#define INVADER_7               "models/Invader/i_7.bmp"
#define INVADER_8               "models/Invader/i_8.bmp"

#define DAEMON			"models/Daemon/daemon.md2"
#define DAEMON_1               "models/Daemon/d_1.bmp"
#define DAEMON_2               "models/Daemon/d_2.bmp"
#define DAEMON_3               "models/Daemon/d_3.bmp"
#define DAEMON_4               "models/Daemon/d_4.bmp"
#define DAEMON_5               "models/Daemon/d_5.bmp"
#define DAEMON_6               "models/Daemon/d_6.bmp"
#define DAEMON_7               "models/Daemon/d_7.bmp"
#define DAEMON_8               "models/Daemon/d_8.bmp"

#define YOHKO			"models/Yohko/yohko.md2"
#define YOHKO_1			"models/Yohko/y_1.bmp"
#define YOHKO_2                 "models/Yohko/y_2.bmp"
#define YOHKO_3                 "models/Yohko/y_3.bmp"
#define YOHKO_4                 "models/Yohko/y_4.bmp"
#define YOHKO_5                 "models/Yohko/y_5.bmp"
#define YOHKO_6                 "models/Yohko/y_6.bmp"
#define YOHKO_7                 "models/Yohko/y_7.bmp"
#define YOHKO_8                 "models/Yohko/y_8.bmp"

#define HOMICIDAL		"models/Homicidal/homicidal.md2"
#define HOMICIDAL_1		"models/Homicidal/h_1.bmp"
#define HOMICIDAL_2             "models/Homicidal/h_2.bmp"
#define HOMICIDAL_3             "models/Homicidal/h_3.bmp"
#define HOMICIDAL_4             "models/Homicidal/h_4.bmp"
#define HOMICIDAL_5             "models/Homicidal/h_5.bmp"
#define HOMICIDAL_6             "models/Homicidal/h_6.bmp"
#define HOMICIDAL_7             "models/Homicidal/h_7.bmp"
#define HOMICIDAL_8             "models/Homicidal/h_8.bmp"

#define GUARDIAN		"models/Guardian/guardian.md2"
#define GUARDIAN_1		"modals/Guardian/g_1.bmp"
#define GUARDIAN_2              "modals/Guardian/g_2.bmp"
#define GUARDIAN_3              "modals/Guardian/g_3.bmp"
#define GUARDIAN_4              "modals/Guardian/g_4.bmp"
#define GUARDIAN_5              "modals/Guardian/g_5.bmp"
#define GUARDIAN_6              "modals/Guardian/g_6.bmp"
#define GUARDIAN_7              "modals/Guardian/g_7.bmp"
#define GUARDIAN_8              "modals/Guardian/g_8.bmp"

/*
** Casts macros
*/
#define DEVICE(data)	((IrrlichtDevice *) (data))
#define DRIVER(data)	((IVideoDriver *) (data))
#define MANAGER(data)	((ISceneManager *) (data))
#define	ENV(data)	((IGUIEnvironment *) (data))
#define CAMERA(data)	((ICameraSceneNode *) (data))
#define TERRAIN(data)	((ITerrainSceneNode *) (data))
#define TEXTURE(data)	((ITexture *) (data))

#define	ISN(data)	((ISceneNode *) (data))

/*
** Get x/y
*/
#define X(data)		(((data + 1) * 100) - ((this->_x + 1) * 50))
#define Y(data)		(((data + 1) * 100) - ((this->_y + 1) * 50))

#define ItemX(data, type)	((data * 100) - (this->_x * 50) + 14)
#define ItemY(data, type)	((data * 100) - (this->_y * 50) + (type + 1) * 10)

#define CASEX(data)	(((data + 1) * 100) - ((this->_x + 1) * 50))
#define CASEY(data)	(((data + 1) * 100) - ((this->_y + 1) * 50))

#define COORD(data, a)		(((data + 1) * 100) - (((a) + 1) * 50))

/*
** Structures
*/

typedef struct	s_matrix
{
  int		move;
  int		level;
  int		item[NB_RESSOURCE];
  void		*rock[NB_RESSOURCE];
}		t_matrix;

typedef struct	s_window
{
  void		*device;
  void		*driver;
  void		*smgr;
  void		*env;
  void		*camera;
  void		*map;
}		t_window;

typedef struct	s_item
{
  void		*img;
  int		x;
  int		y;
  int		z;
}		t_item;

typedef struct	s_player
{
  char		*team;
  int		id;
  int		x;
  int		y;
  int		case_x;
  int		case_y;
  int		life;
  int		inventory[NB_RESSOURCE];
}		t_player;

typedef struct	s_obs
{
  char		*host;
  int		port;
  int		sock;
  t_window	*window;
  t_matrix	**matrix;
  t_player	*player;
  t_item	item[NB_RESSOURCE];
  int		x;
  int		y;
}		t_obs;

// Functions

void		main_usage(void);
int		parse_args(int ac, char **av, t_obs *obs);

// Init's functions

void		init_obs(t_obs *obs);
t_window	*init_window(void);
t_matrix	**init_matrix(t_obs *obs);
void		init_item(t_obs *obs);
void		init_map_size(t_obs *obs);
void		init_case(t_obs *obs);
void		init_socket(t_obs *obs);

int		extract_num(char *buf, int num);

void		msg_reception(t_obs *obs);

void		draw_all(t_obs *obs);
void		draw_rock(t_obs *obs, int x, int y, int type);
void		draw_player(t_obs *obs, int x, int y, int z);

void		rm_rock(t_obs *obs, int x, int y, int type);

void		free_obs(t_obs *obs);

#endif
