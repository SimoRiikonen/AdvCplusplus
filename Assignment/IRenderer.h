// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __IRenderer_h__
#define __IRenderer_h__
////////////////////////////////////////////////////////////////////////////////
class IRenderer 
{
public:
  virtual void Render( const std::string & str ) = 0;
};
////////////////////////////////////////////////////////////////////////////////
#endif
