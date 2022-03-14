#include "Game.h"

Game::Game(int w, int h, int l)
{
	//cout << "------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada ao construtor da classe Game " << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Constroi e inicializa a GameBoard" << endl<<endl;
	GameSore = 0;
	PlayBoard.Init(w,h,l);
	Level = l;
	DiscoverWornds = PlayBoard.Get_BoardNumWords();  //Definir o numero de palavras a descobrir
	this->WordDiscover = new int[PlayBoard.Get_BoardNumWords()];  //Criar um vetor para as palavras já descobertas
	if (this->WordDiscover == NULL)
		cout << "Erro ao criar vector de Inteiros" << endl;
	for (int i = 0; i < (PlayBoard.Get_BoardNumWords()); i++)
	{
		WordDiscover[i] = 0; //Iniciar vetor a zeros
	}
}
	
void Game::Run()
{
	//cout << "------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada a Run da classe Game para iniciar (correr) o jogo" << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Executa um ciclo que chama Play enquanto houver palavras por descobrir;" << endl;
	//cout << "OK \t- Play devolve o numero de palavras por descobrir." << endl << endl;

	//cout << "Running 1 call for testing" << endl << endl;

	Point p;
	int a = -1, c = 0, d = 0, s = 0, m = 0;
	float b = 0;
	clock_t t;
	if (Level == 0) {
		while (DiscoverWornds > 0) //Aguarda até que já não haja palavras
		{
			a = Play();
			if (a == 1)
			{
				DiscoverWornds--;
				GameSore++;
			}
			else if (a == 2) {
				system("cls");
				PlayBoard.Init(PlayBoard.Get_BoardWidth(), PlayBoard.Get_BoardHeight(), Level); //Criação de um novo jogo
				Run();
			}
			else if (a == 3) {
				exit(0); //Sair do jogo antes do fim
			}
		}
	}
	else{
		t = clock();   //Guarda as horas no inicio do programa
		while (DiscoverWornds > 0) //Aguarda até que já não haja palavras
		{
			a = Play();
			if (a == 1)
			{
				DiscoverWornds--;
			}
			else if (a == 2) {
				system("cls");
				PlayBoard.Init(PlayBoard.Get_BoardWidth(), PlayBoard.Get_BoardHeight(), Level); //Criação de um novo jogo
				Run();
			}
			else if (a == 3) {
				exit(0); //Sair do jogo antes do fim
			}
			else if (a == 4) {
				//gravar jogo
				exit(0); //Sair do jogo antes do fim
			}
		}
		t = clock() - t;  // Guada o tempo que demorou a realizar o play
		b = ((float)t) / CLOCKS_PER_SEC;   //Transforma o tempo em segundos
		c = b / 60;   //Transforma o tempo em minutos
		GameSore = ((PlayBoard.Get_BoardNumWords() * PlayBoard.Get_BoardNumWords())/c);   //Dá a pontuação em função do tempo demorado
	}
	
	system("cls");
	p.gotoxy(5, 5);
	cout << "Score : " << GameSore;
}

int Game::Play(void)
{

	//cout << "------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada a Play da classe Game para efetuar uma jogada completa" << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Executa uma jogada completa, incluindo:" << endl;

	//cout << "OK \t\tPede uma palavra ao jogador" << endl;
	//cout << "OK \t\tVerifica se a palavra existe, evocando um metodo Find da GameBoard;" << endl;
	//cout << "OK \t\tSe existe, assinala a palavra como descoberta, decrementa no número de palavras por descobrir;" << endl;
	//cout << "OK \t\tSe não existe existe, avisa que não existe;" << endl;
	//cout << "OK \t- Imprime a nova board" << endl;
	//cout << "OK \t- Devolve o valor de palavras por descobrir" << endl << endl;
	Point p;
	string palavra;
	int xx;
	int yy;
	int a = -3, b = -1, c = -2, d = (PlayBoard.Get_BoardNumWords() - DiscoverWornds), e = -1;
	system("cls");
	PlayBoard.View1();  // Iprimir a matriz
	for (int i = 0; i < d; i++) {  //Imprimir palavras já descobertas sobre a matriz
		PlayBoard.View2(WordDiscover[i]);
	}
	p.gotoxy((PlayBoard.Get_BoardHeight() * 2) + 8, 1);  //Mostrar o tema para procurar
	switch (PlayBoard.Get_TemaNum()) {
	case 1:
		cout << "Tema: Animais";
		break;
	case 2:
		cout << "Tema: Países do mundo";
		break;
	case 3:
		cout << "Tema: Frutas e vegetais";
		break;
	case 4:
		cout << "Tema: Profissões";
		break;
	case 5:
		cout << "Tema: Estados dos EUA";
		break;
	case 6:
		cout << "Tema: Distritos de Portugal";
		break;
	}
	if (Level == 0){
		p.gotoxy((PlayBoard.Get_BoardHeight() * 2) + 8, 3);
		cout << "Palavras a descobrir: " << DiscoverWornds;  //Mostrar nº de palavras a descobrir
		PlayBoard.Show_Words2();  //Mostrar palavras a descobrir ao lado da matriz
		p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 7));
		cout << "Palavra (Como na Matriz): ";
		p.gotoxy((PlayBoard.Get_BoardHeight() / 2) + 27, (PlayBoard.Get_BoardWidth() + 7));
		cin >> palavra;  //Pedir a palavra
		a = PlayBoard.Find_w(palavra); //Procurar a palavra
		if (a == -2) {
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 9));
			cout << "Palavra incorreta.";
			//this_thread::sleep_for(chrono::seconds(3));
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
			cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 12));
			cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
			cin >> e;
			if (e == 0) {
				system("cls");
				p.gotoxy(5, 5);
				cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
				return 3;
			}
			else if (e == 2) {
				return 2;
			}
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 14));
			system("pause");
			return 0;
		}
		else if (a == -1) {
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 9));
			cout << "Palavra já encontrada.";
			//this_thread::sleep_for(chrono::seconds(3));
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
			cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 12));
			cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
			cin >> e;
			if (e == 0) {
				system("cls");
				p.gotoxy(5, 5);
				cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
				return 3;
			}
			else if (e == 2) {
				return 2;
			}
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 14));
			system("pause");
			return 0;
		}
		else {
			WordDiscover[d] = (a + 1);
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 9));
			cout << "X: ";
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2) + 4, (PlayBoard.Get_BoardWidth() + 9));
			cin >> xx;  //Pedir x
			b = PlayBoard.Find_x(a, xx); //Procurar x
			if (b == 0) {
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
				cout << "Coordenada incorreta.";
				//this_thread::sleep_for(chrono::seconds(3));
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
				cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 14));
				cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 15));
				cin >> e;
				if (e == 0) {
					system("cls");
					p.gotoxy(5, 5);
					cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
					return 3;
				}
				else if (e == 2) {
					return 2;
				}
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 16));
				system("pause");
				return 0;
			}
			else {
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
				cout << "Y: ";
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2) + 4, (PlayBoard.Get_BoardWidth() + 11));
				cin >> yy; //Pedir y
				c = PlayBoard.Find_y(a, yy);  //Procurar y
				if (c == 0) {
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
					cout << "Coordenada incorreta.";
					//this_thread::sleep_for(chrono::seconds(3));
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 15));
					cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 16));
					cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 17));
					cin >> e;
					if (e == 0) {
						system("cls");
						p.gotoxy(5, 5);
						cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
						return 3;
					}
					else if (e == 2) {
						return 2;
					}
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 18));
					system("pause");
					return 0;
				}
				else {
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
					cout << "Palavra correta.";
					//this_thread::sleep_for(chrono::seconds(3));
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 15));
					cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 16));
					cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 17));
					cout << "Se quiseres guardar o jogo para continuar mais tarde prime 3.";
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 18));
					cin >> e;
					if (e == 0) {
						system("cls");
						p.gotoxy(5, 5);
						cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
						return 3;
					}
					else if (e == 2) {
						return 2;
					}
					else if (e == 3) {
						return 4;
					}
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 19));
					system("pause");
					return 1;
				}
			}
		}
	}
	else {
		p.gotoxy((PlayBoard.Get_BoardHeight() * 2) + 8, 3);
		cout << "Palavras a descobrir: " << DiscoverWornds;  //Mostrar nº de palavras a descobrir
		for (int i = 0; i < d; i++) {
			PlayBoard.Show_Words(WordDiscover[i], i);  //Mostrar palavras já descobertas ao lado da matriz
		}
		p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 7));
		cout << "Palavra (Como na Matriz): ";
		p.gotoxy((PlayBoard.Get_BoardHeight() / 2) + 27, (PlayBoard.Get_BoardWidth() + 7));
		cin >> palavra;  //Pedir a palavra
		a = PlayBoard.Find_w(palavra); //Procurar a palavra
		if (a == -2) {
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 9));
			cout << "Palavra incorreta.";
			//this_thread::sleep_for(chrono::seconds(3));
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
			cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 12));
			cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
			cin >> e;
			if (e == 0) {
				system("cls");
				p.gotoxy(5, 5);
				cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
				return 3;
			}
			else if (e == 2) {
				return 2;
			}
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 14));
			system("pause");
			return 0;
		}
		else if (a == -1) {
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 9));
			cout << "Palavra já encontrada.";
			//this_thread::sleep_for(chrono::seconds(3));
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
			cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 12));
			cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
			cin >> e;
			if (e == 0) {
				system("cls");
				p.gotoxy(5, 5);
				cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
				return 3;
			}
			else if (e == 2) {
				return 2;
			}
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 14));
			system("pause");
			return 0;
		}
		else {
			WordDiscover[d] = (a + 1);
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 9));
			cout << "X: ";
			p.gotoxy((PlayBoard.Get_BoardHeight() / 2) + 4, (PlayBoard.Get_BoardWidth() + 9));
			cin >> xx;  //Pedir x
			b = PlayBoard.Find_x(a, xx); //Procurar x
			if (b == 0) {
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
				cout << "Coordenada incorreta.";
				//this_thread::sleep_for(chrono::seconds(3));
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
				cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 14));
				cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 15));
				cin >> e;
				if (e == 0) {
					system("cls");
					p.gotoxy(5, 5);
					cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
					return 3;
				}
				else if (e == 2) {
					return 2;
				}
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 16));
				system("pause");
				return 0;
			}
			else {
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 11));
				cout << "Y: ";
				p.gotoxy((PlayBoard.Get_BoardHeight() / 2) + 4, (PlayBoard.Get_BoardWidth() + 11));
				cin >> yy; //Pedir y
				c = PlayBoard.Find_y(a, yy);  //Procurar y
				if (c == 0) {
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
					cout << "Coordenada incorreta.";
					//this_thread::sleep_for(chrono::seconds(3));
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 15));
					cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 16));
					cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 17));
					cin >> e;
					if (e == 0) {
						system("cls");
						p.gotoxy(5, 5);
						cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
						return 3;
					}
					else if (e == 2) {
						return 2;
					}
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 18));
					system("pause");
					return 0;
				}
				else {
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 13));
					cout << "Palavra correta.";
					//this_thread::sleep_for(chrono::seconds(3));
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 15));
					cout << "Deseja continuar a jogar? (Sim -> 1   Não -> 0)"; //Pedir ao jogador se pretende continuar...
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 16));
					cout << "Se preferires jogar de novo, mas com palavras diferentes prime 2.";
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 17));
					cout << "Se quiseres guardar o jogo para continuar mais tarde prime 3.";
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 18));
					cin >> e;
					if (e == 0) {
						system("cls");
						p.gotoxy(5, 5);
						cout << " Desististe do jogo logo não tens classificação!!!" << endl << endl;
						return 3;
					}
					else if (e == 2) {
						return 2;
					}
					else if (e == 3) {
						return 4;
					}
					p.gotoxy((PlayBoard.Get_BoardHeight() / 2), (PlayBoard.Get_BoardWidth() + 19));
					system("pause");
					return 1;
				}
			}
		}
	}
}