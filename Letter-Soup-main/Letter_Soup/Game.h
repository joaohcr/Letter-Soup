#pragma once
#include <iostream>
#include <stdlib.h>
#include "Board.h"
using namespace std;

class Game
{
public:
	Game(int, int, int);

	int Play();
	void Run();
	
private:
	Board PlayBoard;
	//string GamePlayer; 
	// GamePlayer � apenas uma string para guardar o nome do jogador, 
	// mas futuramente ser� uma class com mais inform��o e funcionalidades 
	int GameSore;
	// GameScore � um inteiro para guardar a pontua��o do jogo,  
	// mas futuramente ser� uma class com mais inform��o e funcionalidades 
	// para iniciar e terminar a contagem de tempo e calcular a pontua��po final
	int DiscoverWornds;
	int* WordDiscover;
	int Level;
};