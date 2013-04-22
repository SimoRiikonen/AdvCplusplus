// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================

#include "Game.h"
#include "Player.h"
#include "QuitCommand.h"
#include "TextRenderer.h"
#include "IRenderer.h"
#include "CommandFactory.h"
#include "Dungeon.h"
#include "Hallway.h"
#include "MonsterRoom.h"
#include "Chambers.h"
#include "globals.h"
#include "FileController.h"

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <exception>
#include <sstream>
 
using namespace std;
#define DEV_NAME "simo_riikonen@hotmail.com"
#define YEAR 2013

Game::Game() : running(true)
{
	  renderer = new TextRenderer();

	  rooms[kDungeon] = new Dungeon();
	  rooms[kDungeon]->SetGame(this);

	  rooms[kHallway] = new Hallway();
	  rooms[kHallway]->SetGame(this);

	  rooms[kMonster] = new MonsterRoom();
	  rooms[kMonster]->SetGame(this);
  
	  rooms[kChambers] = new Chambers();
	  rooms[kChambers]->SetGame(this);

	  rooms[kDungeon]->SetNextRoom(North,rooms[kHallway]);

	  rooms[kHallway]->SetNextRoom(South,rooms[kDungeon]);
	  rooms[kHallway]->SetNextRoom(North,rooms[kMonster]);

	  rooms[kMonster]->SetNextRoom(South,rooms[kHallway]);
	  rooms[kMonster]->SetNextRoom(North,rooms[kChambers]);

	  rooms[kChambers]->SetNextRoom(South,rooms[kMonster]);
  
	  currentRoom = rooms[kDungeon];
}

Game::~Game()
{

}

void Game::Play()
{
	  string cmd;
	  renderer->Render("Adventure for adventure's sake!\n");
	  ostringstream s;
	  s << "by " << DEV_NAME << "(c) " << YEAR << ". Licensed under GPLv3.\n";
	  renderer->Render(s.str());
	 
	  renderer->Render("\nTrying to load data from a file...\n");
	  FileController::LoadInfo(player);
	  
	  string nameCheck = player.GetName();
	  if (nameCheck == "ERROR") Player::AskInfo(player);

	  renderer->Render("\nPlayer statistics: \n\n");
	  player.PrintSummary();
	  renderer->Render("\nAnd behold, the adventure begins! \n");
  
	  player.SetGame(this);
  
	  while(running)
	  {
			renderer->Render(GetCurrentRoom()->GetDescription());
			renderer->Render("\n> ");

			getline(cin,cmd);

			CommandFactory comm(this);
			ICommand *pCommand = comm.Create( cmd ); 
			if ( pCommand ) pCommand->Execute();
			delete pCommand;

			GetCurrentRoom()->Update();
      
			if ( player.GetHitpoints() <= 0 ) 
			{    
				renderer->Render("You're dead. Game over.\n");
				running = false;
			}
	  }

	  // final message to player
	  FileController::SaveInfo(player);
	  renderer->Render("Exiting, bye!\n");
}

void Game::SetRenderer( IRenderer *pRenderer )
{
	renderer = pRenderer;
}

IRenderer * Game::GetRenderer() const
{
	return renderer;
}

bool Game::IsRunning() const
{
	return running;
}

void Game::SetRunning( bool bFlag ) 
{
	running = bFlag;
}

Player & Game::GetPlayer()
{
	return player;
}

Room * Game::GetCurrentRoom()
{
	return currentRoom;
}
void Game::SetCurrentRoom( Room *pRoom )
{
	currentRoom = pRoom;
}


