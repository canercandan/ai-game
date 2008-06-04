//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Wed Jun  4 16:29:21 2008 caner candan
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
  {"voir", "inventaire", "prend objet", "pose objet", "expulse",
   "broadcast text", "incantation"};

int	AI::nbClientPerLevel[NB_LEVEL] = {1, 2, 2, 4, 4, 6, 6};
int	AI::nbObjectPerLevel[NB_LEVEL][NB_OBJECT] = {
  {1, 0, 0, 0, 0, 0},
  {1, 1, 1, 0, 0, 0},
  {2, 0, 1, 0, 2, 0},
  {1, 1, 2, 0, 1, 0},
  {1, 2, 1, 3, 0, 0},
  {1, 2, 3, 0, 1, 0},
  {2, 2, 2, 2, 2, 1}
};

AI::AI()
  : _port(0), _x(0), _y(0), _nbClient(0), _level(0)
{}

AI::AI(const std::string& host, int port, const std::string& team)
  : _host(host), _port(port), _team(team),
    _x(0), _y(0), _nbClient(0), _level(1)
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
      this->_nbClient = ai._nbClient;
      this->_level = ai._level;
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
      if (this->_nbClient > 0)
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
  this->_socket.send(this->_team);
  this->_socket.send("\n");
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
      iss >> this->_nbClient;
      if (this->_nbClient < 0)
	throw 2;
      iss >> this->_x;
      if (!this->_x)
	throw 3;
      iss >> this->_y;
      if (!this->_y)
	throw 4;
      std::cout << "AI: nbClient [" << this->_nbClient << "]"
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
  this->_socket.send("voir\n");
  while (!(mesg = this->_socket.recv()).empty())
    {
      this->_actionRandomMove();
      ::sleep(1);
    }
}

void	AI::_actionRandomMove(void)
{
  long	action;

  action = ::random() % NB_ACTIONS_MOVE;
  this->_socket.send(actionsMove[action] + '\n');
  std::cout << "action [" << actionsMove[action] << "]" << std::endl;
}

void	AI::_actionAI(const std::string&)
{
  
}
