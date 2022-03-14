#include "Char.h"


Char::Char()
{
	Set_Ch('\0');
}

Char::Char(char c)
{
	Set_Ch(c);
}

Char::~Char() 
{
	Set_Ch('\0');
}

void Char::Rand()
{
	char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	Set_Ch(letters[rand() % 26]);
}

void Char::View(void)
{
	cout << Get_Ch();
}