// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Updateable_h__
#define __Updateable_h__
////////////////////////////////////////////////////////////////////////////////
struct Updateable 
{
  virtual ~Updateable(){}
  virtual void Update() = 0;
};
////////////////////////////////////////////////////////////////////////////////
#endif
