#include "Rookie.h"

Rookie::Rookie() {
	Set_Name("\0");
}

Rookie::Rookie(string s) {
	Set_Name(s);
}

Rookie::~Rookie() {
}

void Rookie::View_Level() {
	cout << Get_Level() << endl << endl;
}

void Rookie::View_Name() {
	cout << Get_Name() << endl << endl;
}