// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Gold_h__
#define __Gold_h__
////////////////////////////////////////////////////////////////////////////////
class GoldFactory;
////////////////////////////////////////////////////////////////////////////////
class Gold 
{
  friend class GoldFactory;
private:
  unsigned int m_nAmount;
  Gold(unsigned int value);
public:
  virtual ~Gold();
  unsigned int GetAmount() const;
  void SetAmount( unsigned int value );
};
////////////////////////////////////////////////////////////////////////////////
#endif
