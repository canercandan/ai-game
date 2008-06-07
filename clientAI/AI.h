//
// AI.h for AI in /home/candan_c/cu/rendu/project/zappy/clientAI
// 
// Made by caner candan
// Login   <candan_c@epitech.net>
// 
// Started on  Mon Jun  2 13:02:35 2008 caner candan
** Last update Sat Jun  7 13:42:15 2008 florent hochwelker
//

#ifndef __AI_H__
# define __AI_H__

# include <string>
# include <vector>
# include "Socket.h"

# define NB_ACTIONS		11
# define NB_ACTIONS_MOVE	3
# define NB_LEVEL		7
# define NB_OBJECT		7
# define NB_REPLY		3

# define LEVEL(x)	((x) - 2)

class	AI
{
 public:
  AI();
  AI(const std::string& host, int port, const std::string& team);
  AI(const AI& ai);
  ~AI();
  AI&	operator=(const AI& ai);

  enum	Action
  {
    UP,
    RIGHT,
    LEFT,
    SEE,
    INVENTORY,
    TAKE_OBJ,
    DROP_OBJ,
    KICK,
    BROADCAST,
    LEVELUP,
    FORK
  };

  enum	Reply
  {
    OK,
    KO,
    MESSAGE
  };

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

  static std::string	actionsName[NB_ACTIONS];
  static std::string	actionsMove[NB_ACTIONS_MOVE];
  static int		actionsHp[NB_ACTIONS];

  static std::string	actionsReply[NB_REPLY];

  static int	nbClientPerLevel[NB_LEVEL];
  static int	nbObjectPerLevel[NB_LEVEL][NB_OBJECT];

  static std::string	objectName[NB_OBJECT];

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
  bool	_hasEnoughClientSameCase(void);
  bool	_canLevelUp(void);

  bool	_hasClientSameCase(const std::string& mesg);
  void	_moveToK(const std::string& mesg);
  bool	_hasObjectInventoryToLevelUp(void);
  bool	_hasObjectSeeToLevelUp(const std::string& mesg);
  void	_takeNeedObject(const std::string& mesg);
  bool	_isNeedFood(Action idx);
  void	_seekFood(void);
  void	_goToGoodCase(const std::string& mesg,
		      Object idx);
  void	_randomMove(void);

  Socket	_socket;
  std::string	_host;
  int		_port;
  std::string	_team;
  int		_x;
  int		_y;
  int		_level;
  int		_maxClient;
  int		_nbClientSameCase;

  std::vector<int>	_qtePerObject;
};

#endif /* !__AI_H__ */
