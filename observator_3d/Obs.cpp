//
// Obs.cpp for Obs3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Fri Jun  6 13:59:02 2008 florent hochwelker
// Last update Sat Jun  7 17:51:15 2008 florent hochwelker
//

#include <sstream>
#include <vector>
#include "Obs.h"
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
}

void		Obs::Auth(Socket& socket)
{
  std::stringstream	ss;
  std::string		tmp;
  std::string		tmp2;

  if (socket.recv() == "BIENVENUE\n")
    {
      socket.send(std::string(MAGIC_OBS) + "\n");
      ss << socket.recv();
      ss >> this->_x >> this->_y >> tmp;
      std::vector	v_item(NOURRITURE + 1);
      this->_item.assign(this->x,);
      if (tmp == START_LIST)
	{
	  while (tmp != END_LIST)
	    {
	      
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

void			Obs::DrawItem(int x, int y, int type)
{
  //   irr::scene::ISceneNode	*rock;

  //   rock = this->_scene->addSphereSceneNode();
  //   if (rock)
  //     {
  //       rock->setScale(irr::core::vector3df(1, 1, 1));
  //       rock->setPosition(irr::core::vector3df(X(x), obs->item[type].z, Y(y)));
  //       rock->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  //       rock->setMaterialTexture(0, TEXTURE(obs->item[type].img));
  //     }
  //   if (obs->matrix[x][y].move == 1)
  //     {
  //       obs->matrix[x][y].item[type] += 1;
  //       if (obs->matrix[x][y].item[type] > 1)
  // 	rock->~ISceneNode();
  //       else
  // 	obs->matrix[x][y].rock[type] = rock;
  //       obs->matrix[x][y].item[type] += 1;
  //     }
}
