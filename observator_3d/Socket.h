#ifndef __SOCKET_H__
# define __SOCKET_H__

# include <string>

# define DEBUG	0

class	Socket
{
 public:
  Socket();
  Socket(const std::string& host, int port);
  Socket(const Socket& s);
  ~Socket();
  Socket&	operator=(const Socket& s);

  void		connectSocket(const std::string& host, int port);
  void		closeSocket(void);
  void		send(const std::string& s);
  std::string	recv(bool wait);
  std::string	sendRecv(const std::string &s);

  bool		isConnected(void);

 private:
  int	_socket;
};

#endif /* !__SOCKET_H__ */
