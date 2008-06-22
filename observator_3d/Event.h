/*
** Event.h for OBS 3D in /home/hochwe_f/zappy/observator_3d
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sun Jun 22 21:51:02 2008 florent hochwelker
** Last update Sun Jun 22 22:40:18 2008 florent hochwelker
*/

#include <irrlicht.h>
#include <iostream>

using namespace irr;

class MyEventReceiver : public irr::IEventReceiver
{

 public:
  MyEventReceiver(scene::ISceneManager* smgr, gui::ICursorControl* curseur)
    {
      selectedSceneNode = 0;
      m_smgr = smgr;
      m_curseur = curseur;
    }

  bool OnEvent(const SEvent& event)
  {
    if (event.EventType == EET_MOUSE_INPUT_EVENT && event.MouseInput.Event == EMIE_RMOUSE_LEFT_UP)
      {
	core::vector3df intersection;
	core::triangle3df tri;

	selectedSceneNode = m_smgr->getSceneCollisionManager()->getSceneNodeFromScreenCoordinatesBB(m_curseur->getPosition());

	if (selectedSceneNode)
	  {
	    std::cout << "j'ai clique sur le node " << selectedSceneNode << std::endl
		      << std::flush;
	  }
      }
    return (true);
  }

 protected:
  //scene::IAnimatedMeshSceneNode* node;
  scene::ISceneNode* selectedSceneNode;
  scene::ISceneManager* m_smgr;
  gui::ICursorControl* m_curseur;
};

/* int main() */
/* { */

/*   return 0; */
/* } */
