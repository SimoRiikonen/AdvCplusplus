// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================

#include "Player.h"
#include "Game.h"
#include "IRenderer.h"
#include <cstdlib>
#include <sstream>
#include <iostream>

using namespace std;

Player::Player()
{
  SetHitpoints(3);
}

Player::~Player()
{
  
}

void Player::Attack( GameObject *pObject )
{
	int hp = pObject->GetHitpoints();
	if ( (rand() % 100) < 63 )
	{
		pObject->SetHitpoints(hp-1); 
		ostringstream s;
		s << GetName() << " hits!\n";
		game->GetRenderer()->Render( s.str() );
	}

	else
	{
		ostringstream s;
		s << GetName() << " misses!\n";
		game->GetRenderer()->Render( s.str() );
	}
}

void Player::PrintSummary()
{
	  int playerClass = (Class)GetClass();
	  int gender = (Gender)GetGender();
	  string plrClass;
	  string plrGender;

	  if (playerClass == 1) plrClass = "Barbarian";
	  else if (playerClass == 2) plrClass = "Wizard";
	  else if (playerClass == 3) plrClass = "Paladin";
	  else if (playerClass == 4) plrClass = "Priest";

	  if (gender == 1) plrGender = "Male";
	  else plrGender = "Female"; 

	  cout << "Name:" << GetName() << "\n";
	  cout << "Class: " << plrClass << "\n";
	  cout << "Age: " << GetAge() << "\n";
	  cout << "Gender: " << plrGender << "\n";
	  cout << "Experience: " << GetExperience() << "\n";
}

void Player::AskInfo( Player & p)
{
		string name;
		int age;
		int c;
		int g;

		cout << "\nPlease enter your details:\n\n";	
		cout << "What is your name?: "; 
		cin >> name; 
		p.SetName(name);

		cout << "Choose a class: (1)Barbarian (2)Wizard (3)Paladin (4)Priest: ";
		cin >> c; 
		p.SetClass((Class)c);

		cout << "How old are you?: ";
		cin >> age;
		p.SetAge(age);

		cout << "Choose gender: (1)Male (2)Female: "; 
		cin >> g; 
		p.SetGender((Gender)g);

		p.SetExperience(0);
		cin.ignore();
}



void Player::SetGame( Game * game )
{ 
  this->game = game;
}

