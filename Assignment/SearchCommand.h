// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __SearchCommand_h__
#define __SearchCommand_h__
#include <cstdlib>
#include "GoldFactory.h"
#include "Gold.h"
#include "Game.h"
#include <sstream>
#include "IRenderer.h"
////////////////////////////////////////////////////////////////////////////////
class SearchCommand : public Command
{
public:
  SearchCommand( Game *pGame ) : Command(pGame) {}
  void Execute()
  {
	if ( rand()%1000 < 436 )
	{
	GoldFactory f;
	Gold *g = f.Create( 1+rand()%100 );
	std::ostringstream s;
	s << "You found " << g->GetAmount() << " gold!\n";

	//NEW!!
	GetGame()->GetPlayer().Purse + g->GetAmount();


	GetGame()->GetRenderer()->Render(s.str());
	delete g;
	}
	else 
	{	
		GetGame()->GetRenderer()->Render("You found nothing...\n");
	}
  }
};
////////////////////////////////////////////////////////////////////////////////
#endif
