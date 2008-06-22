//
// main.cpp for **zappy** in /u/epitech_2010s/toumi_m/cu/rendu/c/zappy/zappy/observator
// 
// Made by majdi toumi
// Login   <toumi_m@epitech.net>
// 
// Started on  Mon May 12 13:37:03 2008 majdi toumi
// Last update Sun Jun 22 22:14:37 2008 florent hochwelker
//

#include <irrlicht.h>
#include "observator_3d.h"
#include "Obs.h"
#include "Socket.h"
#include "Event.h"

using namespace	irr;

int			main(int ac, char **av)
{
  Obs			obs(ac, av);
  Socket		socket(obs.GetHost(), obs.GetPort());

  obs.Auth(socket);

  //  gui::ICursorControl*	monCurseur = obs.GetDevice()->getCursorControl();
  MyEventReceiver receiver(obs.GetScene(), obs.GetDevice()->getCursorControl());
  obs.GetDevice()->setEventReceiver(&receiver);

  obs.DrawAll(socket);


  return (0);
}
