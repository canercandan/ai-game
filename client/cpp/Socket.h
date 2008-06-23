//
// Socket.h for Socket in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 11:26:34 2008 caner candan
// Last update Mon Jun 16 20:07:04 2008 caner candan
//

#ifndef __SOCKET_H__
# define __SOCKET_H__

# include <string>

class	Socket
{
public:
  Socket(bool verbose = false, int pid = 0);
  Socket(const std::string& host, int port,
	 bool verbose = false, int pid = 0);
  Socket(const Socket& s);
  ~Socket();
  Socket&	operator=(const Socket& s);

  void		connectSocket(const std::string& host,
			      int port, int pid = 0);
  void		closeSocket(void);
  void		send(const std::string& s,
		     bool verbose = false);
  std::string	recv(bool verbose = false);
  std::string	recvNoWait(bool verbose = false);
  std::string	sendRecv(const std::string &s,
			 bool verbose = false);

  bool		isConnected(void);
  bool		isGoodRecv(void);

  void		headMessage(void);
private:
  int	_pid;
  int	_socket;
  bool	_verbose;
};

#endif /* !__SOCKET_H__ */
