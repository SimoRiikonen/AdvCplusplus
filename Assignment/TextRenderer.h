// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#include <iostream>
#include "IRenderer.h"
////////////////////////////////////////////////////////////////////////////////
class TextRenderer : public IRenderer
{
public:
  void Render( const std::string & str )
  {
    std::cout << str;
  }
};
////////////////////////////////////////////////////////////////////////////////
