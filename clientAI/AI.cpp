//
// AI.cpp for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:05:25 2008 caner candan
// Last update Tue Jun  3 00:53:36 2008 caner candan
//

#include <string>
#include <iostream>
#include "Socket.h"
#include "AI.h"

AI::AI(const std::string& host, int port, const std::string& team)
  : _host(host), _port(port), _team(team), _x(0), _y(0)
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
    }
  return (*this);
}

void	AI::connectToServer(void)
{
  this->_socket.connectSocket(this->_host, this->_port);
}

void		AI::getHeader(void)
{
  std::string	mesg;

  try
    {
      if (!this->_socket.isConnected())
	throw 1;
      mesg = this->_socket.recv();
      mesg =  mesg.substr(0, mesg.find_last_of('\n'));
      if (mesg != "BIENVENUE")
	throw 2;
      this->_socket.send(this->_team);
      this->_socket.send("\n");
      mesg = this->_socket.recv();
    }
  catch (int e)
    {
      if (e == 1)
	std::cout << "not connected" << std::endl;
      else if (e == 2)
	std::cout << "incorrect header" << std::endl;
    }
}
