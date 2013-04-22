// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Hallway_h__
#define __Hallway_h__
#include "Room.h"
#include <sstream>
////////////////////////////////////////////////////////////////////////////////
class Hallway : public Room
{
public:
  Hallway()
  {
    SetDescription("You are standing in a pretty damp hallway.");
  }
  
  void Update()
  {
    
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
