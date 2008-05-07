/*
** observator.h for zappy in /home/aubry_j/zappy/include
** 
** Made by jordan aubry
** Login   <aubry_j@epitech.net>
** 
** Started on  Fri May  2 17:54:35 2008 jordan aubry
** Last update Wed May  7 17:42:16 2008 jordan aubry
*/

#ifndef __OBSERVATOR_H__
# define __OBSERVATOR_H__


/* Define
*/

#define OBS_USAGE		"Usage :\n./observator (host) (port)\n"
#define OBS_CASE		192

#define MODE_GRAPH		EDT_BURNINGSVIDEO
#define FAR_VALUE		100000
#define WIN_WEIGHT		640
#define WIN_HEIGHT		480
#define	CAMERA_SPEED		100

#define NB_RESSOURCE		10

#define SOCK_ERROR		"ERROR : Can't connect !"

/* Files
*/

#define OBS_PK3			"bin/map.pk3"

#define SKY_UP			"env/up.tga"
#define SKY_DN			"env/dn.tga"
#define SKY_RT			"env/rt.tga"
#define SKY_LF			"env/lf.tga"
#define SKY_FT			"env/ft.tga"
#define SKY_BK			"env/bk.tga"

#define MAP_CASE                "maps/case.bmp"

#define	ITEM_0			"textures/rpck_0.bmp"
#define ITEM_1                  "textures/water.bmp"
#define ITEM_2                  "textures/gold.bmp"
#define ITEM_3                  "textures/rock.bmp"
#define ITEM_4                  "textures/purple.bmp"
#define ITEM_5                  "textures/grass.bmp"
#define ITEM_6                  "textures/lava.bmp"
#define ITEM_7                  "textures/rock_7.bmp"
#define ITEM_8                  "textures/rock_8.bmp"
#define ITEM_9                  "textures/rock_9.bmp"

/*
** Mask structure
*/

/*
using namespace irr;
using namespace video;
using namespace scene;
using namespace gui;
using namespace core;
*/

#define DEVICE(data)	((IrrlichtDevice *) (data))
#define DRIVER(data)	((IVideoDriver *) (data))
#define MANAGER(data)	((ISceneManager *) (data))
#define	ENV(data)	((IGUIEnvironment *) (data))
#define CAMERA(data)	((ICameraSceneNode *) (data))
#define TERRAIN(data)	((ITerrainSceneNode *) (data))
#define TEXTURE(data)	((ITexture *) (data))

/* Structure
*/

typedef struct	s_matrix
{
  int		move;
  int		level;
  int		item[NB_RESSOURCE];
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

typedef struct	s_obs
{
  t_window	*window;
  t_matrix	**matrix;
  t_item	item[NB_RESSOURCE];
  int		x;
  int		y;
  int		sock;
}		t_obs;

/* Function
*/

void		main_usage();

t_obs		*init_obs(char *host, char *port);
t_window	*init_window();
t_matrix	**init_matrix(t_obs *obs);
void		init_item(t_obs *obs);
void		init_map_size(t_obs *obs);
void		init_case(t_obs *obs);
void		init_socket(t_obs *obs, char *host, char *port);

int		extract_num(char *buf, int num);

void		msg_reception(t_obs *obs);

void		draw_all(t_obs *obs);
void		draw_rock(t_obs *obs, int x, int y, int type);

void		free_obs(t_obs *obs);

#endif
