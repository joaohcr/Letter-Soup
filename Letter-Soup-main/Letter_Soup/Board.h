#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <iomanip>
#include <string>
#include <thread>
#include <chrono>
#include "Char.h"
#include "Word.h"
#include "Rookie.h"
#include "Master.h"

#define MY_COLOR_BLACK			0
#define MY_COLOR_DARK_BLUE		1
#define MY_COLOR_SOFT_GREEN		2
#define MY_COLOR_SOFT_BLUE		3
#define MY_COLOR_DARK_RED		4
#define MY_COLOR_PURPLE			5
#define MY_COLOR_DARK_YELLOW	6
#define MY_COLOR_GRAY			7
#define MY_COLOR_DARK_GRAY		8
#define MY_COLOR_CYAN			9
#define MY_COLOR_LIGTH_GREEN	10
#define MY_COLOR_LIGTH_BLUE		11
#define MY_COLOR_LIGTH_RED		12
#define MY_COLOR_PINK			13
#define MY_COLOR_LIGTH_YELLOW	14
#define MY_COLOR_WHITE			15
using namespace std;

class Board
{
public:
	Board(void);
	void Init(int, int, int);
	void View1(void);
	void View2(int);
	int Find_w(string);
	int Find_x(int, int);
	int Find_y(int, int);
	void Show_Words(int, int);
	void Show_Words2();
	~Board();

	inline void Set_BoardWidth(int bw) { BoardWidth = bw; };
	inline int Get_BoardWidth() { return BoardWidth; };
	inline void Set_BoardHeight(int bh) { BoardHeight = bh; };
	inline int Get_BoardHeight() { return BoardHeight; };
	inline int Get_BoardNumWords() { return NumWords; };
	inline int Get_TemaNum() { return TemaNum; };

	void setForeColor(int);
	void showRectAt(int, int);
	
private:
	int BoardWidth;
	int BoardHeight;
	Char** Chars1;
	Char** Chars2;
	Word* Words1;
	Word* Words2;
	Point* Points;
	int NumWords;
	int* SizeWords;
	int TemaNum;
};