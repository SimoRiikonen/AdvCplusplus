// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __CoinPurse_h__
#define __CoinPurse_h__


class CoinPurse
{
private:
	unsigned int coinCount;
public:
	CoinPurse()
	{
		coinCount = 0;
	}
	unsigned int GetGoldAmount()
	{
		return coinCount;
	}
	void SetGoldAmount(unsigned int amount)
	{
		coinCount = amount;
	}
	//Operator overloading
	void operator+(unsigned int amount)
	{
		coinCount +=amount;
	}
};
////////////////////////////////////////////////////////////////////////////////
#endif
