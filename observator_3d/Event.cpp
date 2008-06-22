//
// Event.cpp for OBS 3D in /home/hochwe_f/zappy/observator_3d
// 
// Made by florent hochwelker
// Login   <hochwe_f@epitech.net>
// 
// Started on  Sun Jun 22 21:49:55 2008 florent hochwelker
// Last update Mon Jun 23 01:24:16 2008 florent hochwelker
//

#include <irrlicht.h>
#include <iostream>
#include <map>
#include "Event.h"

using namespace irr;

MyEventReceiver::MyEventReceiver(scene::ISceneManager* smgr, gui::ICursorControl* curseur)
{
  selectedSceneNode = 0;
  m_smgr = smgr;
  m_curseur = curseur;
}

bool MyEventReceiver::OnEvent(const SEvent& event)
{
  if (event.EventType == EET_MOUSE_INPUT_EVENT && event.MouseInput.Event == EMIE_RMOUSE_LEFT_UP)
    {
      core::vector3df intersection;
      core::triangle3df tri;

      selectedSceneNode = m_smgr->getSceneCollisionManager()->getSceneNodeFromScreenCoordinatesBB(m_curseur->getPosition());

      if (selectedSceneNode)
	{
	  core::vector3df v = selectedSceneNode->getPosition();
	  for (int x = 0; x < this->_obs->GetX(); ++x)
	    {
	      for (int y = 0; y < this->_obs->GetY(); ++y)
		{
		  if (v.equals(this->_obs->_case[x][y]))
		    {
		      char* green = "\033[1;40;32m";
		      char* red = "\033[1;40;31m";
		      char* blue = "\033[1;40;34m";
		      char* normal = "\033[0m";
		      std::cout << green  << "[" << blue << "contenu de la case " << x << " " << y
				<< green << "]" << normal << std::endl;
		      std::cout << " .Linemate: " << this->_obs->_item[x][y][LINEMATE]._qte << std::endl;
		      std::cout << " .Deraumere: " << this->_obs->_item[x][y][DERAUMERE]._qte << std::endl;
		      std::cout << " .Sibur: " << this->_obs->_item[x][y][SIBUR]._qte << std::endl;
		      std::cout << " .Mendiane: " << this->_obs->_item[x][y][MENDIANE]._qte << std::endl;
		      std::cout << " .Phiras: " << this->_obs->_item[x][y][PHIRAS]._qte << std::endl;
		      std::cout << " .Thystame: " << this->_obs->_item[x][y][THYSTAME]._qte << std::endl;
		      std::cout << " .Nourriture: " << this->_obs->_item[x][y][NOURRITURE]._qte << std::endl;

		      std::map<int, Player*>::iterator	it = this->_obs->_player.begin();
		      std::map<int, Player*>::iterator	it_end = this->_obs->_player.end();

		      for (;it != it_end; ++it)
			{
			  if (it->second->_x == x && it->second->_y == y)
			    {
			      std::cout << green  << " [" << blue << "Player " << it->second->_id
					<< green << "]" << normal << std::endl;
			      std::cout << "  .Team = " << it->second->_team << std::endl;
			      std::cout << "  .Level = " << it->second->_lvl << std::endl;
			      std::cout << green  << "  [" << red << "Inventaire du Player"
					<< green << "]" << normal << std::endl;
			      std::cout << "   .Linemate: " << it->second->_inventory[LINEMATE] << std::endl;
			      std::cout << "   .Deraumere: " << it->second->_inventory[DERAUMERE] << std::endl;
			      std::cout << "   .Sibur: " << it->second->_inventory[SIBUR] << std::endl;
			      std::cout << "   .Mendiane: " << it->second->_inventory[MENDIANE] << std::endl;
			      std::cout << "   .Phiras: " << it->second->_inventory[PHIRAS] << std::endl;
			      std::cout << "   .Thystame: " << it->second->_inventory[THYSTAME] << std::endl;
			      std::cout << "   .Nourriture: " << it->second->_inventory[NOURRITURE] << std::endl;
			      
			    }
			}
		      x = this->_obs->GetX();
		      y = this->_obs->GetY();
		    }
		}
	    }
	}
    }
  return (true);
}
