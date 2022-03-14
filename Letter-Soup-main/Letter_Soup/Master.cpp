#include "Master.h"

Master::Master() {
	Set_Name("\0");
}

Master::Master(string s) {
	Set_Name(s);
}

Master::~Master() {
}

void Master::View_Level() {
	cout << Get_Level() << endl << endl;
}

void Master::View_Name() {
	cout << Get_Name() << endl << endl;
}