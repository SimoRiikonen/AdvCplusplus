// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Command_h__
#define __Command_h__
#include "ICommand.h"
////////////////////////////////////////////////////////////////////////////////
class Game;
class Command : public ICommand
{
private:
  // Pointer to game
  Game *m_pGame;
public:
  // Parametrized constructor.
  Command( Game *pGame ) : m_pGame(pGame){}

  // Accessor
  Game * GetGame() { return m_pGame; }
  // Mutator
  void SetGame( Game *pGame ) { m_pGame = pGame; }

};
////////////////////////////////////////////////////////////////////////////////
#endif
