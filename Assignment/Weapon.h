// ============================================
// Advanced C++ Fall 2013
// Name: Simo Riikonen
// Student id: 1001123
// Assignment: ?
// ============================================

#ifndef Weapon_h_
#define Weapon_h_

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Weapon 
{
private:
	int damage;
	int hitChance;
	string attackMessage;
	string user;
	string name;

public:
	int GetDmg()
	{
		return damage;
	}
	void SetDmg(int dmg)
	{
		damage = dmg;
	}
	int GetHitChance()
	{
		return hitChance;
	}
	void SetHitChance(int hitC)
	{
		hitChance = hitC;
	}
	string GetAttackMessage()
	{
		return attackMessage;
	}
	void SetAttackMessage(string atkMsg)
	{
		attackMessage = atkMsg;
	}
	string GetUser()
	{
		return user;
	}
	void SetUser(string username)
	{
		user = username;
	}
	string GetName()
	{
		return name;
	}
	void SetName(string wep_name)
	{
		name = wep_name;
	}
};
class Sword : public Weapon
{
public:
	Sword(int i)
	{
		SetDmg(3);
		SetHitChance(75);
		SetAttackMessage(" attacks with a sword!\n");
		SetUser("Paladin");
		SetName("Swodr");
		
	}
	Sword(int dmg, int hitC, string attMsg)
	{
		SetDmg(dmg);
		SetHitChance(hitC);
		SetAttackMessage(attMsg);
	}
	Sword() : Sword(0)
	{
		SetName("Sword");
	}
};
class Club : public Weapon
{
public:
	Club()
	{
		SetDmg(5);
		SetHitChance(50);
		SetAttackMessage(" lands a heavy blow with a club \n");
		SetUser("Barbarian");
		SetName("Club");
	}
};
class Staff : public Weapon
{
public:
	Staff()
	{
		SetDmg(4);
		SetHitChance(60);
		SetAttackMessage(" casts a spell using a staff!\n");
		SetUser("Wizard");
		SetName("Staff");
	}
};
class Dagger : public Weapon
{
public:
	Dagger()
	{
		SetDmg(2);
		SetHitChance(90);
		SetAttackMessage(" attacks swiftly with a dagger!\n");
		SetUser("Thief");
		SetName("Dagger");
	}
};

typedef std::map<std::string, Weapon *> WeaponMap;
class WeaponSelector
{
public:
	WeaponMap Weapons;
	void Add(Weapon *weapon)
	{
		Weapons[weapon->GetUser()] = weapon;
	}
};

class PrintWeapons
{
public: 
	void operator()(WeaponMap::iterator it)
	{
		auto * weapon = it->second;
		cout<< "Class: " << it->first <<" |" 
			<< " Weapon: "<<weapon->GetName() <<" |"
			<< " Damage: " << weapon->GetDmg()<<" |"
			<< " Hit Chance: " << weapon->GetHitChance()<<"%"<< endl;
	}
};
#endif