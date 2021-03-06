// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#include "GameObject.h"
#include <cstdlib>
#include <iostream>
#include "Enemy.h"
using namespace std;
////////////////////////////////////////////////////////////////////////////////
GameObject::GameObject()
{
  
}
////////////////////////////////////////////////////////////////////////////////
GameObject::~GameObject()
{
  
}
////////////////////////////////////////////////////////////////////////////////
void
GameObject::Attack( GameObject *pObject )
{
  int hp = pObject->GetHitpoints();
  if ( (rand() % 10) < 6 )
  {
    // TODO: convert this into weapon 
    // with damage property. Can you do it? Is so, explain in your learning diary how.
    pObject->SetHitpoints(hp-1); 
    cout << GetName() << " hits!\n";
  }
  else
    cout << GetName() << " misses!\n";
}
////////////////////////////////////////////////////////////////////////////////
int 
GameObject::GetHitpoints() const
{
  return hitpoints;
}
////////////////////////////////////////////////////////////////////////////////
void 
GameObject::SetHitpoints(int hp )
{
  hitpoints = hp;
}
////////////////////////////////////////////////////////////////////////////////

void 
GameObject::SetName( string name) 
{
  this->name = name;
}
////////////////////////////////////////////////////////////////////////////////
string 
GameObject::GetName() const
{
  return name;
}
////////////////////////////////////////////////////////////////////////////////
void 
GameObject::SetClass( Class c)
{
  myClass = c;
}
////////////////////////////////////////////////////////////////////////////////
Class 
GameObject::GetClass() const
{
  return myClass;
}
////////////////////////////////////////////////////////////////////////////////
void 
GameObject::SetAge( unsigned short int age )
{
  this->age = age;
}
////////////////////////////////////////////////////////////////////////////////
unsigned short int 
GameObject::GetAge() const
{
  return age;
}
////////////////////////////////////////////////////////////////////////////////
void 
GameObject::SetGender( Gender g )
{
  gender = g;
}
////////////////////////////////////////////////////////////////////////////////
Gender 
GameObject::GetGender() const
{
  return gender;
}

////////////////////////////////////////////////////////////////////////////////

void
GameObject::Update()
{
  
}
////////////////////////////////////////////////////////////////////////////////
