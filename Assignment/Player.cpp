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


#include "Weapon.h"

using namespace std;

Player::Player()
{
	SetHitpoints(3);
	p_purse = &Purse;
	p_exp = &Exp;
}
Player::~Player()
{
  
}

Weapon* Player::GetWeapon()
{
	WeaponSelector weaponSelector;
	Weapon *sword = new Sword();
	Weapon *club = new Club();
	Weapon *staff = new Staff();
	Weapon *dagger = new Dagger();

	weaponSelector.Add(sword);
	weaponSelector.Add(club);
	weaponSelector.Add(staff);
	weaponSelector.Add(dagger);

	int classNumber = GetClass();
	string className;
	switch (classNumber)
	{
		case 1: className = "Barbarian"; break;
		case 2: className = "Wizard"; break;
		case 3: className = "Paladin"; break;
		case 4: className = "Thief"; break;
	}
	
	typedef map<string, Weapon *> WeaponMap;
	WeaponMap::iterator it;
	it = weaponSelector.Weapons.find(className);

	Weapon *activeWeapon = it->second; 

	return activeWeapon;
}

void Player::Attack( GameObject *pObject )
{
	Weapon * activeWeapon = Player::GetWeapon();

	int hp = pObject->GetHitpoints();
	if ( (rand() % 100) < activeWeapon->GetHitChance() )
	{
		pObject->SetHitpoints(hp-activeWeapon->GetDmg()); 
		ostringstream s;
		s << GetName() << activeWeapon->GetAttackMessage();
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
	  else if (playerClass == 4) plrClass = "Theif";

	  if (gender == 1) plrGender = "Male";
	  else plrGender = "Female"; 

	  cout << "\n";
	  cout << "***********Statistics**********" << "\n";
	  cout << "Name:" << GetName() << "\n";
	  cout << "Class: " << plrClass << "\n";
	  cout << "Age: " << GetAge() << "\n";
	  cout << "Gender: " << plrGender << "\n";
	  cout << "Experience: " << GetExperience().GetValue() << "\n";
	  cout << "Gold: " << GetPurse().GetValue() << "\n";
	  cout << "*******************************" << "\n";
	  cout << "\n";
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

		cout << "Choose a class: (1)Barbarian (2)Wizard (3)Paladin (4)Thief: ";
		cin >> c; 
		p.SetClass((Class)c);

		cout << "How old are you?: ";
		cin >> age;
		p.SetAge(age);

		cout << "Choose gender: (1)Male (2)Female: "; 
		cin >> g; 
		p.SetGender((Gender)g);

		p.SetExperience(0);

		//NEW!!
		p.GetPurse().SetValue(50);
		
		cin.ignore();
}
void Player::SetGame( Game * game )
{ 
	this->game = game;
}

SingleVariableContainer<unsigned int> Player::GetPurse()
{
	return *p_purse;
}

//NEW!!
void Player::SetGoldAmount(unsigned int amount)
{
	Purse.SetValue(amount);
}

void Player::SetExperience( int experience )
{
	Exp.SetValue(experience);
}

SingleVariableContainer<int> Player::GetExperience() 
{
  return *p_exp;
}
