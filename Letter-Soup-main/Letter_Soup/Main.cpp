#include <iostream>
#include <chrono>
#include <ctime>
#include <conio.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include "Game.h"
using namespace std;

int main()
{
	int board_w;
	int board_h;
	string name;
	int level;
	int s;
	ifstream is;
	string line;

	is.open("Letras.txt");
	if (!is) {
		cout << "ERRO: nao e' possivel abrir o ficheiro Letras.txt" << '\n';
		exit(0);
	}

	while (!is.eof())
	{
		getline(is, line);

		cout << line << endl;
	}
	cout << endl;
	system("Pause");
	system("cls");
	is.close();

	setlocale(LC_ALL, "");
	/*do
	{
		cout << endl << "Deseja carregar o último jogo gravado?" << endl;
		cout << " Sim -> 1   Não -> 0" << endl;
		cin >> g;
	} while (g != 0 && g != 1);*/

	/*if (g == 1){
		//Carregar jogo
	}*/

	cout << endl << " Digite o seu nome de jogador:" << "\n";
	cin >> name;

	cout << endl;

	do
	{
		cout << " Digite o seu nível de jogador:" << "\n";
		cout << " Rookie -> 0   Master -> 1" << endl;
		cin >> level;
	} while (level != 0 && level != 1);
	
	if (level == 0) {
		Rookie r(name);
		r.Set_Level(0);
	}
	else {
		Master m(name);
		m.Set_Level(1);
	}

	cout << endl;

	do
	{
		cout << " Deseja que o nº de linhas seja igual ao nº de colunas? (Matriz Quadrada)" << endl;
		cout << " Sim -> 1   Não -> 0" << endl;
		cin >> s;
	} while (s != 0 && s != 1);

	cout << endl;
	if (level == 0)
	{
		if (s == 1) {
			do
			{
				do
				{
					cout << " Digite o nº do lado da matriz quadrada: (max 50)" << endl;
					cin >> board_w;
				} while (1 > board_w);
			} while (board_w > 50);
			board_h = board_w;
		}
		else
		{
			do
			{
				do
				{
					cout << " Digite o nº de linhas: (max 50)" << "\n";
					cin >> board_w;
				} while (1 > board_w);
			} while (board_w > 50);

			cout << endl;

			do
			{
				do
				{
					cout << " Digite o nº de colunas: (max 50)" << "\n";
					cin >> board_h;
				} while (1 > board_h);
			} while (board_h > 50);
		}
	}
	else
	{
		if (s == 1) {
			do
			{
				do
				{
					cout << " Digite o nº do lado da matriz quadrada: (min 8 e max 50)" << endl;
					cin >> board_w;
				} while (1 > board_w);
			} while (board_w < 8 || board_w > 50);
			board_h = board_w;
		}
		else
		{
			do
			{
				do
				{
					cout << " Digite o nº de linhas: (min 8 e max 50)" << "\n";
					cin >> board_w;
				} while (1 > board_w);
			} while (board_w < 8 || board_w > 50);

			cout << endl;

			do
			{
				do
				{
					cout << " Digite o nº de colunas: (min 8 e max 50)" << "\n";
					cin >> board_h;
				} while (1 > board_h);
			} while (board_h < 8 || board_h > 50);
		}
	}

	system("cls");

	cout << " Game begins!" << endl << endl;
	cout << " Hi new gamer: " << name << endl;
	if (level == 0)
		cout << " Level: Rookie!!!" << endl;
	else
		cout << " Level: Master!!!" << endl;
	cout << " Board = " << board_w << " Width X " << board_h << " Hieght" << endl << endl;
	system("pause");
	system("cls");

	Game MyGame(board_w, board_h, level);

	MyGame.Run();

	system("pause");
	return 0;
}