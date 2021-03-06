//
// Socket.cpp for Socket in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 11:34:39 2008 caner candan
// Last update Mon Jun 16 20:10:32 2008 caner candan
//

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include <cstdlib>
#include <cerrno>
#include <string>
#include <iostream>
#include "Socket.h"

Socket::Socket(bool verbose/*=false*/, int pid/*= 0*/)
  : _pid(pid), _socket(-1), _verbose(verbose)
{}

Socket::Socket(const std::string& host, int port,
	       bool verbose/*=false*/, int pid/* = 0*/)
  : _pid(pid), _socket(-1), _verbose(verbose)
{
  connectSocket(host, port, pid);
}

Socket::Socket(const Socket& s)
{*this = s;}

Socket::~Socket()
{
  if (_socket >= 0)
    {
      ::close(_socket);
      if (_verbose)
	{
	  this->headMessage();
	  std::cout << "socket closed"
		    << std::endl;
	}
    }
}

Socket&	Socket::operator=(const Socket& s)
{
  if (this != &s)
    this->_socket = s._socket;
  return (*this);
}

void	Socket::connectSocket(const std::string& host,
			      int port, int pid/*= 0*/)
{
  struct sockaddr_in	sin;
  struct protoent	*pe;
  struct hostent	*h;
  struct in_addr	in;

  try
    {
      if (pid)
	this->_pid = pid;
      pe = ::getprotobyname("tcp");
      if ((this->_socket = ::socket(PF_INET, SOCK_STREAM, pe->p_proto)) < 0)
	throw 1;
      sin.sin_family = AF_INET;
      if (this->_verbose)
	{
	  this->headMessage();
	  std::cout << "Resolving " << host
		    << " ..." << std::endl;
	}
      if (!(h = ::gethostbyname(host.c_str())))
	throw 2;
      ::memcpy(&in, h->h_addr, sizeof(in));
      sin.sin_port = ::htons(port);
      sin.sin_addr.s_addr = ::inet_addr(inet_ntoa(in));
      if (::connect(this->_socket, (struct sockaddr*)&sin, sizeof(sin)) < 0)
	throw 3;
    }
  catch (int e)
    {
      this->headMessage();
      if (e == 1)
	std::cout << "socket error";
      else if (e == 2)
	std::cout << "resolving error";
      else if (e == 3)
	std::cout << "connect error";
      std::cout << std::endl;
      this->closeSocket();
    }
}

void	Socket::closeSocket(void)
{
  try
    {
      if (this->_socket < 0)
	throw true;
      ::close(this->_socket);
      this->_socket = -1;
    }
  catch (bool)
    {
      this->headMessage();
      std::cout << "socket already closed"
		<< std::endl;
    }
}

void	Socket::send(const std::string& s,
		     bool verbose /*=false*/)
{
  try
    {
      if (!this->isConnected())
	throw 1;
      if (::send(this->_socket, s.c_str(), s.size(), 0) < 0)
	throw 2;
      if (this->_verbose || verbose)
	{
	  this->headMessage();
	  std::cout << "send [" << s << ']'
		    << std::endl;
	}
    }
  catch (int e)
    {
      this->headMessage();
      if (e == 1)
	std::cout << "send error, not connected";
      else if (e == 2)
	std::cout << "send error";
      std::cout << std::endl;
    }
}

std::string	Socket::recv(bool verbose /*=false*/)
{
  char		buf[1024];
  int		size;

  try
    {
      if (!this->isConnected())
	throw true;
      size = ::recv(this->_socket, buf, sizeof(buf), 0);
      if (!this->isGoodRecv())
	return ("");
      buf[size] = 0;
      if (this->_verbose || verbose)
	{
	  this->headMessage();
	  std::cout << "recv [" << buf << ']'
		    << std::endl;
	}
      return (std::string(buf));
    }
  catch (bool)
    {
      this->headMessage();
      std::cout << "error recv, not connected"
		<< std::endl;
    }
  return ("");
}

std::string	Socket::recvNoWait(bool verbose /*=false*/)
{
  char		buf[1024];
  int		size;

  try
    {
      if (!this->isConnected())
	throw true;
      size = ::recv(this->_socket, buf, sizeof(buf),
		    MSG_DONTWAIT);
      if (!this->isGoodRecv())
	return ("");
      buf[size] = 0;
      if (this->_verbose || verbose)
	{
	  this->headMessage();
	  std::cout << "recvNoWait [" << buf << ']'
		    << std::endl;
	}
      return (std::string(buf));
    }
  catch (bool)
    {
      this->headMessage();
      std::cout << "error recvNoWait, "
		<< "not connected" << std::endl;
    }
  return ("");
}

bool	Socket::isGoodRecv(void)
{
  if (errno == EAGAIN)
    return (false);
  return (true);
}

std::string	Socket::sendRecv(const std::string &s,
				 bool verbose /*=false*/)
{
  this->send(s, verbose);
  return (this->recv(verbose));
}

bool	Socket::isConnected(void)
{
  return (this->_socket >= 0);
}

void	Socket::headMessage(void)
{
  std::cout << '[' << this->_pid << ']'
	    << " Socket: ";
}
