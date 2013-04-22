// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================
#ifndef __Templates_h__
#define __Templates_h__

template <typename X> class SingleVariableContainer
{
private: 
	X value;
public:
	SingleVariableContainer()
	{
		value = 0;
	}
	X GetValue()
	{
		return value;
	}
	void SetValue(X param_value)
	{
		value = param_value;
	}
	void operator+(X param_value)
	{
		value += param_value;
	}
};

template <> class SingleVariableContainer <int>
{	
private: 
	int value;
public:
	SingleVariableContainer()
	{
		value = 0;
	}
	int GetValue()
	{
		return value;
	}
	void SetValue(int param_value)
	{
		value = param_value;
	}
	void operator+(int param_value)
	{
		value += param_value;
	}
	void operator-(int param_value)
	{
		value -= param_value;
	}
};

#endif