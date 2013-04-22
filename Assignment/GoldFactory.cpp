// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#include "GoldFactory.h"
#include "Gold.h"
#include <cstdlib>
////////////////////////////////////////////////////////////////////////////////
Gold *
GoldFactory::Create( size_t amount )
{
  Gold *pG = new Gold(amount);
  return pG;
}
////////////////////////////////////////////////////////////////////////////////
