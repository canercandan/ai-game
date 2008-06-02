//
// Socket.h for Socket in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 11:26:34 2008 caner candan
// Last update Mon Jun  2 12:50:04 2008 caner candan
//

#ifndef __SOCKET_H__
# define __SOCKET_H__

# include <string>

class	Socket
{
public:
  Socket(const std::string& host, int port);
  Socket(const Socket& s);
  ~Socket();
  Socket&	operator=(const Socket& s);

  void		connectSocket(const std::string& host, int port);
  void		closeSocket(void);
  void		send(const std::string& s);
  std::string	recv(void);

  bool		isConnected(void);
private:
  int	_socket;
};

#endif /* !__SOCKET_H__ */
