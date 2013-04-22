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
////////////////////////////////////////////////////////////////////////////////
class Player : public GameObject
{
private:
		Game *game;
		//NEW!!
		CoinPurse Purse;
		friend class SearchCommand;
public:
		Player();
		virtual ~Player();
		void SetGame(Game *game);
		void Attack(GameObject *pObject);

		void PrintSummary();
		static void AskInfo(Player & p);

		CoinPurse GetPurse();
		void SetGoldAmount(unsigned int amount);

		void operator + (int amount);


};
////////////////////////////////////////////////////////////////////////////////
#endif
