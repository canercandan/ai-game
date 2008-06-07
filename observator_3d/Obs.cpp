//
// Obs.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Fri Jun  6 13:59:02 2008 florent hochwelker
// Last update Sat Jun  7 21:58:05 2008 florent hochwelker
//

#include <sstream>
#include <vector>
#include "Obs.h"
#include "Item.h"
#include "observator_3d.h"
#include "common.h"

Obs::Obs(int ac, char **av)
{
  if (ac > 2)
    {
      _host = av[1];
      std::stringstream	ss(av[2]);
      ss >> _port;
    }
  else
    {
      _host = DEFAULT_HOST;
      _port = DEFAULT_PORT;
    }
  _texture[0] = _driver->getTexture(ITEM_1);
  _texture[1] = _driver->getTexture(ITEM_2);
  _texture[2] = _driver->getTexture(ITEM_3);
  _texture[3] = _driver->getTexture(ITEM_4);
  _texture[4] = _driver->getTexture(ITEM_5);
  _texture[5] = _driver->getTexture(ITEM_6);
}

void		Obs::Auth(Socket& socket)
{
  std::stringstream	ss;
  std::string		tmp;
  int			x, y, type[NB_RESSOURCE];

  if (socket.recv() == "BIENVENUE\n")
    {
      socket.send(std::string(MAGIC_OBS) + "\n");
      ss << socket.recv();
      ss >> this->_x >> this->_y >> tmp;
      std::vector<Item>			v_item(NB_RESSOURCE);
      std::vector<std::vector<Item> >	v_y(this->_y, v_item);

  this->_item.assign(this->_x, v_y);

if (tmp == START_LIST)
  {
    while (ss.str().find(END_LIST) == std::string::npos)
      ss << socket.recv();
    tmp = ss.str().substr(sizeof(START_LIST) + ss.str().find(START_LIST));
    ss.str("");
    ss << tmp;
    while (tmp.find(END_LIST) != 0)
      {
      	ss >> x >> y;
      	ss 
      	  >> this->_item[x][y][0]._qte
      	  >> this->_item[x][y][1]._qte
      	  >> this->_item[x][y][2]._qte
      	  >> this->_item[x][y][3]._qte
      	  >> this->_item[x][y][4]._qte
      	  >> this->_item[x][y][5]._qte
      	  >> this->_item[x][y][6]._qte;
      	tmp = ss.str().substr(ss.str().find_first_of("\n") + 1);
      	ss.str("");
      	ss << tmp;
      	for (int i = 0; i < NB_RESSOURCE; i++)
      	  if (this->_item[x][y][i]._qte > 0)
	    this->DrawItem(x, y, i);
      }
  }
this->DrawPlate();
}
}

void				Obs::DrawPlate()
{
  irr::scene::ISceneNode	*node;
  int				x;
  int				y;

  for (x = 0; x < this->_x; x++)
    {
      for (y = 0; y < this->_y; y++)
	{
	  node = _scene->addCubeSceneNode();
	  node->setScale(irr::core::vector3df(10, 1, 10));
	  node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
	  node->setMaterialTexture(0, _driver->getTexture(MAP_CASE));
	  node->setPosition(irr::core::vector3df(CASEX(x), -29, CASEY(y)));
	}
    }
}

void		Obs::DrawAll()
{
  while (this->_device->run())
    {
      _driver->beginScene(true, true, 0);
      _scene->drawAll();
      _env->drawAll();
      _device->getGUIEnvironment()->drawAll();
      _driver->endScene();
    }
}

void					Obs::DrawPlayer(int x, int y, int z)
{
  irr::scene::IAnimatedMeshSceneNode	*node;

  node = this->_scene->addAnimatedMeshSceneNode(this->_scene->getMesh(INVADER));
  if (node)
    {
      node->setFrameLoop(1, 1);
      node->setAnimationSpeed(0);
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setPosition(irr::core::vector3df(X(x), 0, Y(y)));
      node->setMaterialTexture(0, this->_driver->getTexture(SKIN_1));
      if (z == NORTH)
	z = OBS_NORTH;
      else if (z == EAST)
	z = OBS_EAST;
      else if (z == WEST)
	z = OBS_WEST;
      else
	z = OBS_SOUTH;
      node->setRotation(irr::core::vector3df(0, z, 0));
      this->_player.push_back(new Player(x, y, node));
    }
}

void		Obs::DrawItem(int x, int y, int type)
{
  this->_item[x][y][type]._img = this->_scene->addSphereSceneNode();
  if (this->_item[x][y][type]._img)
    {
      this->_item[x][y][type]._img->setScale(irr::core::vector3df(1, 1, 1));
      this->_item[x][y][type]._img->setPosition(irr::core::vector3df(ItemX(x, type), -20, ItemY(y, type)));
      this->_item[x][y][type]._img->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      if (type != NOURRITURE)
	this->_item[x][y][type]._img->setMaterialTexture(0, this->_texture[type]);
    }
}

void		Obs::DeleteItem(int x, int y, int type)
{
  std::cout << "addr = " << this->_item[x][y][type]._img << std::endl;
  if (--this->_item[x][y][type]._qte == 0)
    this->_item[x][y][type]._img->remove();
}
