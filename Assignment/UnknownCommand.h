// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __UnknownCommand_h__
#define __UnknownCommand_h__
////////////////////////////////////////////////////////////////////////////////
#include "Command.h"
////////////////////////////////////////////////////////////////////////////////
class UnknownCommand  : public Command
{
public:
  UnknownCommand( Game *pGame ) : Command(pGame) { }
  
  void Execute()
  {
    GetGame()->GetRenderer()->Render("I do not understand you.\n");
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
