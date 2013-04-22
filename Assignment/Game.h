// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================

#ifndef __Game_h__
#define __Game_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer;
class Room;
////////////////////////////////////////////////////////////////////////////////
enum RoomId { kDungeon, kHallway, kMonster, kChambers, kNumRooms };
#include "Player.h"
#include "Enemy.h"
////////////////////////////////////////////////////////////////////////////////
class Game 
{
private:
  bool running;
  Player player;
  IRenderer *renderer;
  Room      *rooms[kNumRooms]; ///< Map.
  Room      *currentRoom;
public:
  Game();
  virtual ~Game();
  void Play();
  void SetRenderer( IRenderer *pRenderer );
  IRenderer * GetRenderer() const;
  bool IsRunning() const;
  void SetRunning(bool bFlag ) ;
  Player & GetPlayer();
  Room * GetCurrentRoom();
  void SetCurrentRoom( Room *pRoom );
};
////////////////////////////////////////////////////////////////////////////////
#endif
