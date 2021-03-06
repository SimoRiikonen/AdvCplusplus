// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Room_h__
#define __Room_h__
////////////////////////////////////////////////////////////////////////////////
#include <string>
#include "Updateable.h"
#include "globals.h"
////////////////////////////////////////////////////////////////////////////////
class MoveCommand;
class AttackCommand;
class Game;
////////////////////////////////////////////////////////////////////////////////
class Room : public Updateable 
{
private:
  Room *        rooms[kNumDirs];
  std::string   description;
  Game *        game;
public:

  Room();
  virtual ~Room();
  void SetGame( Game * pGame );
  Game * GetGame() const;
  void SetDescription( const std::string & desc );
  const std::string & GetDescription() const;
  void   SetNextRoom( Direction d, Room * pRoom );
  Room * GetNextRoom( Direction d );

  virtual Room * OnMoveCommand( MoveCommand *pCommand );
  virtual void   OnAttack( AttackCommand *pCommand );
};
////////////////////////////////////////////////////////////////////////////////
#endif
