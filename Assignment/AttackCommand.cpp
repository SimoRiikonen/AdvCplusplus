// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#include "AttackCommand.h"
#include "Game.h"
#include "Room.h"

void AttackCommand::Execute()
{
	GetGame()->GetCurrentRoom()->OnAttack(this);
}

