// Magical Game.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
using namespace std;
class CDragon;
class CGhost;
class CWolf;
class CMode {
protected:
	int power;
	int hp;
public:
	void display() 
	{
		cout << "Power: " << power << " HP: " << hp << endl;
	}
	void SetValue(int n, int m)
	{
		power = n;
		hp = m;
	}
	void Hurted(int n)
	{
		hp -= n;
	}
	void Attack(CMode * obj)
	{
		obj->Hurted(power);
		obj->Fightback(this);
	}
	void Fightback(CMode * obj)
	{
		obj->Hurted(power / 2);
	}
};
class CDragon : public CMode
{
	// 龙
};
class CGhost : public CMode
{
	// 幽灵
};
class CWolf : public CMode
{
	// 狼
};
int main()
{
	CDragon Dragon;
	Dragon.SetValue(20, 100);
	CWolf Wolf;
	Wolf.SetValue(4, 100);
	CGhost Ghost;
	Ghost.SetValue(10, 100);
	Dragon.display();
	Wolf.display();
	Ghost.display();
	Dragon.Attack(&Wolf);
	Dragon.Attack(&Wolf);
	Ghost.Attack(&Dragon);
	Dragon.display();
	Wolf.display();
	Ghost.display();
	return 0;
}

