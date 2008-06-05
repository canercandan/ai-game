//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Thu Jun  5 18:09:40 2008 caner candan
//

#include <string>
#include <iostream>
#include <sstream>
#include <cctype>
#include <cstdlib>
#include <unistd.h>
#include "Socket.h"
#include "AI.h"

std::string	AI::actionsMove[NB_ACTIONS_MOVE] =
  {"avance", "droite", "gauche"};

std::string	AI::actionsOther[NB_ACTIONS_OTHER] =
  {"voir", "inventaire", "prend objet", "pose objet",
   "expulse", "broadcast text", "incantation"};

int	AI::nbClientPerLevel[NB_LEVEL] =
  {1, 2, 2, 4, 4, 6, 6};
int	AI::nbObjectPerLevel[NB_LEVEL][NB_OBJECT] = {
  {1, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 0},
  {2, 0, 1, 0, 2, 0},
  {1, 1, 2, 0, 1, 0},
  {1, 2, 1, 3, 0, 0},
  {1, 2, 3, 0, 1, 0},
  {2, 2, 2, 2, 2, 1}
};

std::string	AI::objectName[NB_OBJECT] =
  {"linemate", "deraumere", "sibur",
   "mendiane", "phiras", "thystame"};

AI::AI()
  : _port(0), _x(0), _y(0), _level(0), _maxClient(0)
{}

AI::AI(const std::string& host, int port,
       const std::string& team)
  : _host(host), _port(port), _team(team),
    _x(0), _y(0), _level(1), _maxClient(0)
{}

AI::AI(const AI& ai)
{*this = ai;}

AI::~AI()
{}

AI&	AI::operator=(const AI& ai)
{
  if (this != &ai)
    {
      this->_socket = ai._socket;
      this->_host = ai._host;
      this->_port = ai._port;
      this->_team = ai._team;
      this->_x = ai._x;
      this->_y = ai._y;
      this->_level = ai._level;
      this->_maxClient = ai._maxClient;
    }
  return (*this);
}

void	AI::setHost(const std::string& host, int port)
{
  this->_host = host;
  this->_port = port;
}

void	AI::setTeamName(const std::string& team)
{
  this->_team = team;
}

bool	AI::connectToServer(void)
{
  try
    {
      this->_socket.connectSocket(this->_host, this->_port);
      if (!this->_socket.isConnected())
	throw true;
    }
  catch (bool)
    {
      std::cout << "AI: not connected" << std::endl;
      return (false);
    }
  return (true);
}

bool		AI::getHeader(void)
{
  std::string	mesg;

  try
    {
      mesg = this->_socket.recv();
      mesg =  mesg.substr(0, mesg.find_last_of('\n'));
      if (mesg != "BIENVENUE")
	throw true;
      this->_sendTeamName();
      if (!this->_getNbClientAndMapSize())
	return (false);
      if (this->_maxClient > 0)
	this->_forkWorld();
    }
  catch (bool)
    {
      std::cout << "AI: incorrect header" << std::endl;
      return (false);
    }
  return (true);
}

void	AI::_sendTeamName(void)
{
  this->_socket.send(this->_team + "\n");
}

bool			AI::_getNbClientAndMapSize(void)
{
  std::istringstream	iss;

  try
    {
      iss.str(this->_socket.recv());
      if (iss.str().substr(0, iss.str().find_last_of('\n')) == "ko")
	throw 1;
      std::cout << "AI: [" << this->_team << "] ok" << std::endl;
      iss >> this->_maxClient;
      if (this->_maxClient < 0)
	throw 2;
      iss >> this->_x;
      if (!this->_x)
	throw 3;
      iss >> this->_y;
      if (!this->_y)
	throw 4;
      std::cout << "AI: maxClient [" << this->_maxClient << "]"
		<< std::endl;
      std::cout << "AI: X: " << this->_x << "]" << std::endl;
      std::cout << "AI: Y: " << this->_y << "]" << std::endl;
    }
  catch (int e)
    {
      std::cout << "AI: ";
      if (e == 1)
	std::cout << "team not found";
      else if (e == 2)
	std::cout << "[" << this->_team << "] is full";
      else if (e == 3)
	std::cout << "x value incorrect";
      else if (e == 4)
	std::cout << "y value incorrect";
      std::cout << std::endl;
      return (false);
    }
  return (true);
}

bool	AI::_forkWorld(void)
{
  if (::fork())
    return (false);
  this->connectToServer();
  this->getHeader();
  return (true);
}

void		AI::actionLoop(void)
{
  std::string	mesg;

  ::srandom(::getpid());
  while (42)
    {
      if (!this->_hasObjectInventoryToLevelUp())
	{
	  mesg = this->_socket.sendRecv("voir\n");
	  if (!this->_hasObjectSeeToLevelUp(mesg))
	    this->_actionRandomMove();
	  else
	    this->_takeNeedObject(mesg);
	  continue;
	}
      mesg = this->_socket.recv();
      if (this->_hasClientSameCase(mesg))
	this->_moveToK(mesg);
    }
}

bool	AI::_hasObjectInventoryToLevelUp(void)
{
  int	i;

  for (i = 0; i < NB_OBJECT; i++)
    if (nbObjectPerLevel[LEVEL(this->_level + 1)][i]
	!= _qtePerObject[i])
      return (false);
  return (true);
}

bool	AI::_hasObjectSeeToLevelUp(const std::string& mesg)
{
  int	i;

  for (i = 0; i < NB_OBJECT; i++)
    if (mesg.find(objectName[i]) == std::string::npos)
      return (false);
  return (true);
}

void	AI::_takeNeedObject(const std::string& mesg)
{
  int	i;

  for (i = 0; i < NB_OBJECT; i++)
    if (mesg.find(objectName[i]) != std::string::npos)
      if (_qtePerObject[i]
	  < nbObjectPerLevel[LEVEL(this->_level + 1)][i])
	this->_socket.sendRecv("prend " + objectName[i]);
      else if (_qtePerObject[i]
	       > nbObjectPerLevel[LEVEL(this->_level + 1)][i])
	this->_socket.sendRecv("pose " + objectName[i]);
}

bool	AI::_hasClientSameCase(const std::string& mesg)
{
  if (mesg.find("message 0") != std::string::npos)
    this->_nbClientSameCase++;
  return (_nbClientSameCase != 0);
}

void		AI::_moveToK(const std::string& mesg)
{
  size_t	pos;

  if ((pos = mesg.find("message ")) != std::string::npos)
    if (mesg.find("message 0") == std::string::npos)
      {
	this->_nbClientSameCase = 0;
	if (mesg[pos] == '3')
	  this->_socket.sendRecv("gauche\n");
	else if (mesg[pos] == '7')
	  this->_socket.sendRecv("droite\n");
	else if (mesg[pos] == '4' ||
		 mesg[pos] == '5' ||
		 mesg[pos] == '6')
	  {
	    this->_socket.sendRecv("droite\n");
	    this->_socket.sendRecv("droite\n");
	  }
	this->_socket.sendRecv("avance\n");
      }
}

void	AI::_actionRandomMove(void)
{
  long	action;

  action = ::random() % NB_ACTIONS_MOVE;
  this->_socket.sendRecv(actionsMove[action] + '\n');
  std::cout << "action [" << actionsMove[action]
	    << "]" << std::endl;
}

void	AI::_actionAI(const std::string&)
{}

bool		AI::_hasEnoughClientSameCase(void)
{
  std::string	mesg;
  int		nbclient;

  nbclient = 0;
  this->_socket.sendRecv("broadcast\n");
  while ((mesg = this->_socket.recv()).find("message")
	 != std::string::npos)
    if (mesg.find("message 0") != std::string::npos)
      nbclient++;
  if (nbclient == nbClientPerLevel[LEVEL(this->_level + 1)])
    return (true);
  return (false);
}

bool		AI::_canLevelUp(void)
{
  std::string	mesg;
  int		i;

  if (this->_hasEnoughClientSameCase())
    
  this->_socket.send("voir\n");
  mesg = this->_socket.recv();
  for (i = 0; i < NB_OBJECT; i++)
    if (mesg.find(objectName[i]) != std::string::npos)
      {
	break;
      }
  return (false);
}
