#pragma once
#include<string>
#include <iostream>
using namespace std;

class Player
{
public:
	Player();
	Player(string);
	~Player();

	inline string Get_Name() { return Name; };
	inline void Set_Name(string s) { Name = s; };
	inline int Get_Level() { return Level; };
	inline void Set_Level(int l) { Level = l; };

	virtual void View_Name() = 0;	//método virtual puro => classe abstrata
	virtual void View_Level() = 0;	//método virtual puro => classe abstrata

private:
	string Name;
	int Level;
};