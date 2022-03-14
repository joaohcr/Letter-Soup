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
	// GamePlayer é apenas uma string para guardar o nome do jogador, 
	// mas futuramente será uma class com mais informção e funcionalidades 
	int GameSore;
	// GameScore é um inteiro para guardar a pontuação do jogo,  
	// mas futuramente será uma class com mais informção e funcionalidades 
	// para iniciar e terminar a contagem de tempo e calcular a pontuaçãpo final
	int DiscoverWornds;
	int* WordDiscover;
	int Level;
};