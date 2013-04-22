// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Dungeon_h__
#define __Dungeon_h__
#include "Room.h"
#include "Enemy.h"
#include "Player.h"
#include "IRenderer.h"
#include "Game.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////

class Dungeon : public Room
{
private:

public:
  Dungeon()
  {
    SetDescription("You are locked up in a dungeon.");
  }
  void Update()
  {
    
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
