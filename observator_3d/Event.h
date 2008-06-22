/*
** Event.h for OBS 3D in /home/hochwe_f/zappy/observator_3d
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Sun Jun 22 21:51:02 2008 florent hochwelker
** Last update Mon Jun 23 00:17:14 2008 florent hochwelker
*/

#include <irrlicht.h>
#include "Obs.h"

using namespace irr;

class MyEventReceiver : public irr::IEventReceiver
{

 public:
  MyEventReceiver(scene::ISceneManager* smgr, gui::ICursorControl* curseur);
  bool OnEvent(const SEvent& event);

  inline void	SetObs(Obs* obs)  { this->_obs = obs; }

 protected:
  //scene::IAnimatedMeshSceneNode* node;
  scene::ISceneNode* selectedSceneNode;
  scene::ISceneManager* m_smgr;
  gui::ICursorControl* m_curseur;

  Obs*	_obs;
};
