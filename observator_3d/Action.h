/*
** Action.h for Obs3D in /home/hochwe_f/zappy/observator_3d
** 
** Made by florent hochwelker
** Login   <hochwe_f@epitech.net>
** 
** Started on  Mon Jun  9 19:05:49 2008 florent hochwelker
** Last update Tue Jun 10 14:13:34 2008 florent hochwelker
*/

#include <map>
#include <string>
#include "Obs.h"
#include "Player.h"

class	Action
{
  typedef void	(Action::*f)(Player*, std::string& param);

 public:
  Action(Obs*);
  void		ApplyAction(Player*, int idx, std::string& param);

 private:
  void		ActionUp(Player*, std::string&);
  void		ActionRight(Player*, std::string&);
  void		ActionLeft(Player*, std::string&);
  void		ActionSee(Player*, std::string&);
  void		ActionInventory(Player*, std::string&);
  void		ActionTakeObj(Player*, std::string&);
  void		ActionDropObj(Player*, std::string&);
  void		ActionKick(Player*, std::string&);
  void		ActionBroadcast(Player*, std::string&);
  void		ActionLevelUpProgress(Player*, std::string&);
  void		ActionLevelUp(Player*, std::string&);
  void		ActionFork(Player*, std::string&);
  void		ActionCount(Player*, std::string&);
  void		ActionBird(Player*, std::string&);
  void		ActionDeath(Player*, std::string&);
  void		MovePlayer(Player*, int x, int y);

  std::map<int, f>	_map;
  Obs*		_obs;
};
