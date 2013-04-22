// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================

#ifndef __MonsterRoom_h__
#define __MonsterRoom_h__
#include "Room.h"
#include "Enemy.h"
#include <sstream>
#include "MoveCommand.h"
#include "Player.h"
////////////////////////////////////////////////////////////////////////////////
class MonsterRoom : public Room
{
private:
	Enemy e;
	bool noticedPlayer;
	bool gotExp;
public:
	MonsterRoom()
	{
		noticedPlayer = false;
		gotExp = false;
		e.SetName( "Orc");
		SetDescription("You are in the monster room. There is an orc here!");
	}
  ////////////////////
  /// Makes enemy attack player once on every turn.
	void Update()
	{
		if ( e.IsAlive() && noticedPlayer )
		{
			std::ostringstream s;
			Player & player = GetGame()->GetPlayer();
			s << e.GetName() << " attacks " << player.GetName() << "\n";
			GetGame()->GetRenderer()->Render(s.str());

			e.Attack(&player);
		}
		noticedPlayer = true;

		if(GetGame()->GetPlayer().GetHitpoints() == 0)
		{
			GetGame()->GetPlayer().Exp - 5;
			GetGame()->GetRenderer()->Render("You have fallen in combat. You lose 5 exp..\n");
		}
	}
  ////////////////////
  /// Restricts movement until enemy is killed.
  /// \param pCommand Move command.
  /// \return Room pointer to next available room, NULL if none available.
  Room * OnMoveCommand( MoveCommand *pCommand )
  {
	if ( e.IsAlive())
	{
		return NULL;
	}
	else
		return GetNextRoom( pCommand->GetDirection() );
  }
  
  void OnAttack( AttackCommand *pCommand )
  {
	if ( e.IsAlive() && noticedPlayer)
	{
		Player & player = GetGame()->GetPlayer();
		std::ostringstream s;
		s << player.GetName() << " attacks " << e.GetName() << "\n";
		GetGame()->GetRenderer()->Render(s.str());
		player.Attack( &e );

		// Change room description a bit
		if ( e.IsAlive() == false )
		{
			SetDescription("You are in the monster room. There is a pretty dead orc here.");
			if (gotExp == false)
			{
				GetGame()->GetPlayer().Exp + 5;
				gotExp = true;
			}
		}

	} 
	else 
	{
		// to encourage player to stop beating it further
		GetGame()->GetRenderer()->Render("Whoa! You already got your pound of flesh out of that one. Literally.\n");
	}
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif



