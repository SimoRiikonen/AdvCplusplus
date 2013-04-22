// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================

#ifndef __CommandFactory_h__
#define __CommandFactory_h__
#include <string>
class Game;
class ICommand;
////////////////////////////////////////////////////////////////////////////////
class CommandFactory 
{
private:
  Game * m_pGame;
public:
  CommandFactory( Game *pGame ) : m_pGame(pGame) {}
  virtual ~CommandFactory() {}
  
  ICommand * Create( const std::string & str );
};
////////////////////////////////////////////////////////////////////////////////

#endif
