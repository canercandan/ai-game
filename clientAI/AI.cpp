//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Tue Jun  3 19:45:41 2008 caner candan
//

#include <string>
#include <iostream>
#include <sstream>
#include <unistd.h>
#include <cctype>
#include "Socket.h"
#include "AI.h"

AI::AI()
  : _port(0), _x(0), _y(0), _nbClient(0)
{}

AI::AI(const std::string& host, int port, const std::string& team)
  : _host(host), _port(port), _team(team),
    _x(0), _y(0), _nbClient(0)
{}

AI::AI(const AI& ai)
{*this = ai;}

AI::~AI()
{
  std::cout << "AI: ";
  std::cout << "bye bye ..." << std::endl;
}

AI&	AI::operator=(const AI& ai)
{
  if (this != &ai)
    {
      this->_socket = ai._socket;
      this->_host = ai._host;
      this->_port = ai._port;
      this->_team = ai._team;
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
      if (this->_socket.isConnected())
	throw 1;
      this->_socket.connectSocket(this->_host, this->_port);
      if (!this->_socket.isConnected())
	throw 2;
    }
  catch (int e)
    {
      std::cout << "AI: ";
      if (e == 1)
	std::cout << "already connected" << std::endl;
      else if (e == 2)
	std::cout << "not connected" << std::endl;
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
	throw true;
    }
  catch (bool)
    {
      std::cout << "AI: ";
      std::cout << "incorrect header" << std::endl;
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
      std::cout << "AI: team ok" << std::endl;
      iss >> this->_nbClient;
      iss >> this->_x;
      if (!this->_x)
	throw 2;
      iss >> this->_y;
      if (!this->_y)
	throw 3;
      std::cout << "nbClient: " << this->_nbClient << std::endl;
      std::cout << "X: " << this->_x << std::endl;
      std::cout << "Y: " << this->_y << std::endl;
    }
  catch (int e)
    {
      std::cout << "AI: ";
      if (e == 1)
	std::cout << "team not found" << std::endl;
      else if (e == 1)
	std::cout << "x value incorrect" << std::endl;
      else if (e == 2)
	std::cout << "y value incorrect" << std::endl;
      return (false);
    }
  return (true);
}

bool	AI::forkWorld(void)
{
  if (::fork())
    return (false);
  this->connectToServer();
  this->getHeader();
  return (true);
}
