#pragma once
#include <Windows.h>
#include <locale.h>
#include <iostream>
using namespace std;

class Point
{
public:
	Point(void);
	Point(int , int);
	Point(int, int, int);

	inline void Set_X(int xx) { x = xx; }
	inline void Set_Y(int yy) { y = yy; }
	inline void Set_Z(int zz) { z = zz; }

	inline int Get_X(void) { return x; }
	inline int Get_Y(void) { return y; }
	inline int Get_z(void) { return z; }

	void pointrand_Down(string, int, int);
	void pointrand_FrontDown(string, int, int);
	void pointrand_BackDown(string, int, int);
	void pointrand_Up(string, int, int);
	void pointrand_FrontUp(string, int, int);
	void pointrand_BackUp(string, int, int);
	void pointrand_Back(string, int, int);
	void pointrand_Front(string, int, int);

	void gotoxy(int, int);

private:
	int x;
	int y;
	int z;
};