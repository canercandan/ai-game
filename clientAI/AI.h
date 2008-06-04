//
// AI.h for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:02:35 2008 caner candan
// Last update Wed Jun  4 15:59:52 2008 caner candan
//

#ifndef __AI_H__
# define __AI_H__

# include <string>
# include "Socket.h"

# define NB_ACTIONS_MOVE	3
# define NB_ACTIONS_OTHER	7
# define NB_LEVEL		7
# define NB_OBJECT		7

# define LEVEL(x)	((x) - 2)

class	AI
{
public:
  AI();
  AI(const std::string& host, int port, const std::string& team);
  AI(const AI& ai);
  ~AI();
  AI&	operator=(const AI& ai);

  enum	Object
    {
      LINEMATE,
      DERAUMERE,
      SIBUR,
      MENDIANE,
      PHIRAS,
      THYSTAME,
      FOOD
    };

  static std::string	actionsMove[NB_ACTIONS_MOVE];
  static std::string	actionsOther[NB_ACTIONS_OTHER];

  static int	nbClientPerLevel[NB_LEVEL];
  static int	nbObjectPerLevel[NB_LEVEL][NB_OBJECT];

  void	setHost(const std::string& host, int port);
  void	setTeamName(const std::string& team);
  bool	connectToServer(void);
  bool	getHeader(void);
  void	actionLoop(void);
private:
  void	_sendTeamName(void);
  bool	_getNbClientAndMapSize(void);
  bool	_forkWorld(void);
  void	_actionRandomMove(void);
  void	_actionAI(const std::string& mesg);

  Socket	_socket;
  std::string	_host;
  int		_port;
  std::string	_team;
  int		_x;
  int		_y;
  int		_nbClient;
  int		_level;
  int		_qtePerObject[NB_OBJECT];
};

#endif /* !__AI_H__ */
