#include "Point.h"

Point::Point(void)
{
	x = 0;
	y = 0;
	z = 0;
}
Point::Point(int xx, int yy)
{
	x = xx;
	y = yy;
	z = 0;
}

Point::Point(int xx, int yy, int zz)
{
	x = xx;
	y = yy;
	z = zz;
}

void Point::pointrand_Down(string s, int w, int h) {
	x = rand() % ((w - s.size()) - 0 + 1) + 0;
	y = rand() % (h - 0 + 1) + 0;
}

void Point::pointrand_FrontDown(string s, int w, int h) {
	x = rand() % ((w - s.size()) - 0 + 1) + 0;
	y = rand() % ((h - s.size()) - 0 + 1) + 0;
}

void Point::pointrand_BackDown(string s, int w, int h) {
	x = rand() % ((w - s.size()) - 0 + 1) + 0;
	y = rand() % (h - (s.size()) + 1) + (s.size());
}

void Point::pointrand_Up(string s, int w, int h) {
	x = rand() % ((w - 1) - (s.size()) + 1) + (s.size());
	y = rand() % (h - 0 + 1) + 0;
}

void Point::pointrand_FrontUp(string s, int w, int h) {
	x = rand() % ((w-1) - (s.size()) + 1) + (s.size());
	y = rand() % ((h - s.size()) - 0 + 1) + 0;
}

void Point::pointrand_BackUp(string s, int w, int h) {
	x = rand() % ((w - 1) - (s.size()) + 1) + (s.size());
	y = rand() % (h - (s.size()) + 1) + (s.size());
}

void Point::pointrand_Back(string s, int w, int h) {
	x = rand() % ((w - 1) - 0 + 1) + 0;
	y = rand() % (h - (s.size()) + 1) + (s.size());
}

void Point::pointrand_Front(string s, int w, int h) {
	x = rand() % ((w - 1) - 0 + 1) + 0;
	y = rand() % ((h - s.size()) - 0 + 1) + 0;
}

void Point::gotoxy(int x, int y) {
	COORD c = { (SHORT)x, (SHORT)y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}