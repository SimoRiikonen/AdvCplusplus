// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Player_h__
#define __Player_h__
#include <string>
#include "GameObject.h"
#include "CoinPurse.h"


class Game;
class Weapon;
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
private:
		Game *game;
		
		
		SingleVariableContainer<unsigned int> Purse;
		SingleVariableContainer<unsigned int> * p_purse;

		SingleVariableContainer<int> Exp;
		SingleVariableContainer<int> * p_exp;
		
		friend class SearchCommand;
		friend class MonsterRoom;
	
public:
		Player();
		virtual ~Player();
		void SetGame(Game *game);
		void Attack(GameObject *pObject);

		void PrintSummary();
		static void AskInfo(Player & p);

		SingleVariableContainer<unsigned int> GetPurse();
		void SetGoldAmount(unsigned int amount);

		Weapon * GetWeapon();

		void SetExperience(int experience);	
		SingleVariableContainer<int> GetExperience();
};
////////////////////////////////////////////////////////////////////////////////
#endif
