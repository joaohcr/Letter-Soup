#include "Board.h"

Board::Board(void)
{
	//cout << "------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada ao construtor da classe Board " << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Inicializa as propriedades da Board, ie, BoarWidth e BoardHeight" << endl;

	Set_BoardWidth(0); 
	Set_BoardHeight(0);
	Chars1 = NULL;
	Chars2 = NULL;
	NumWords = 0;
}

 void Board::Init(int w, int h, int l)
{
	//cout << "------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada a Init da Board para preparar a Board para jogar" << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Alocar a matriz Chars (de Char *), com dimensoes Sx Sy" << endl;
	//cout << "OK \t- Preenche a matriz Chars, criando os Char e atribuindo-os aos ponteiros da matriz Chars" << endl;
	//cout << "OK \t- Carrega as palavras de um ficheiro e coloca-as na matriz"<<endl;
	//cout << "OK \t  pode e deve usar outros métodos privados da classe" << endl << endl;

	Set_BoardWidth(w); //Definir a altura e largura da matriz
	Set_BoardHeight(h);
	char space = ' '; 

	Chars1 = (Char**) new Char * [w]; //Criar duas matrizes, uma para alocar só as palavras
	Chars2 = (Char**) new Char * [w]; //outra que a partir da primeira coloca as palavras sobre as letras aleatorias

	for (int i = 0; i < w; i++){
		Chars1[i] = (Char*) new Char[h];
	}

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			Chars1[i][j].Set_Ch(space);

	for (int i = 0; i < w; i++) {
		Chars2[i] = (Char*) new Char[h];
	}

	for (int i = 0; i < w; i++)
		for (int j = 0; j < h; j++)
			Chars2[i][j].Rand();

	if (l == 0) {
		if (w < h) {
			NumWords = w/2;  //escolha do numero de palavras
		}
		else {
			NumWords = h/2;
		}
	}
	else
	{
		if (w < h) {
			NumWords = w;  //escolha do numero de palavras
		}
		else {
			NumWords = h;
		}
	}

	srand(time(NULL));
	int i = 0;
	string str = " ";
	Point p;
	ifstream is;
	
	this->Words1 = new Word[NumWords];  //criação de dois vetores de palavras
	if (this->Words1 == NULL)
		cout << "Erro ao criar vector de Palavras1" << endl;

	this->Words2 = new Word[NumWords];
	if (this->Words2 == NULL)
		cout << "Erro ao criar vector de Palavras2" << endl;

	this->Points = new Point[NumWords]; //criação de um vetor de pontos
	if (this->Points == NULL)
		cout << "Erro ao criar vector de Pontos" << endl;

	this->SizeWords = new int[NumWords]; //criação de um vetor de inteiros
	if (this->SizeWords == NULL)
		cout << "Erro ao criar vector de Inteiros" << endl;

	//int Num = rand() % (max - min + 1) + min;
	int num1 = 0;
	if (NumWords <= 15){
		num1 = rand() % (6 - 1 + 1) + 1;
	}
	else if (NumWords <= 39){
		num1 = rand() % (5 - 1 + 1) + 1;
	}
	else{
		num1 = rand() % (4 - 1 + 1) + 1;
	}
	TemaNum = num1;
	switch (num1)  //escolha de qual ficheiro se irá retirar as palavras para a matriz
	{
	case 1:
		is.open("Animals.txt");
		if (!is) {
			cout << "ERRO: nao e' possivel abrir o ficheiro Animals.txt" << '\n';
			exit(0);
		}
		break;
	case 2:
		is.open("Countries.txt");
		if (!is) {
			cout << "ERRO: nao e' possivel abrir o ficheiro Countries.txt" << '\n';
			exit(0);
		}
		break;
	case 3:
		is.open("Fruits_Vegetables.txt");
		if (!is) {
			cout << "ERRO: nao e' possivel abrir o ficheiro Fruits_Vegetables.txt" << '\n';
			exit(0);
		}
		break;
	case 4:
		is.open("Jobs.txt");
		if (!is) {
			cout << "ERRO: nao e' possivel abrir o ficheiro Jobs.txt" << '\n';
			exit(0);
		}
		break;
	case 5:
		is.open("States_of_EUA.txt");
		if (!is) {
			cout << "ERRO: nao e' possivel abrir o ficheiro States_of_EUA.txt" << '\n';
			exit(0);
		}
		break;
	case 6:
		is.open("Distritos_de_Portugal.txt");
		if (!is) {
			cout << "ERRO: nao e' possivel abrir o ficheiro Distritos_de_Portugal.txt" << '\n';
			exit(0);
		}
		break;
	}

	while (i != NumWords)
	{
		getline(is, str);
		Point p;
		Words1[i].Set_Letters(str);
		Words2[i].Set_Letters(str);
		SizeWords[i] = str.size();
	inicio:
		//int Num = rand() % (max - min + 1) + min;
		int num2 = rand() % (8 - 1 + 1) + 1;

		switch (num2)  //escolha da direção das palavras com possibilidade de cruzamento
		{
		case 1:
			p.pointrand_Down(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if ((Chars1[p.Get_X() + i][p.Get_Y()]).Get_Ch() == ' ') {
					(Chars1[p.Get_X() + i][p.Get_Y()]).Set_Ch(str[i]);
				}
				else if ((Chars1[p.Get_X() + i][p.Get_Y()]).Get_Ch() == str[i]) {
					int j = i + 1;
					if ((Chars1[p.Get_X() + j][p.Get_Y()]).Get_Ch() == ' ' || (Chars1[p.Get_X() + j][p.Get_Y()]).Get_Ch() == str[j]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++)
						{
							(Chars1[p.Get_X() + i][p.Get_Y()]).Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i <= j; i++) {
						(Chars1[p.Get_X() + i][p.Get_Y()]).Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				(Chars2[p.Get_X() + i][p.Get_Y()]).Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		case 2:
			p.pointrand_FrontDown(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if ((Chars1[p.Get_X() + i][p.Get_Y() + i]).Get_Ch() == ' ') {
					(Chars1[p.Get_X() + i][p.Get_Y() + i]).Set_Ch(str[i]);
				}
				else if ((Chars1[p.Get_X() + i][p.Get_Y() + i]).Get_Ch() == str[i]) {
					int j = i + 1;
					if ((Chars1[p.Get_X() + j][p.Get_Y() + j]).Get_Ch() == ' ' || (Chars1[p.Get_X() + j][p.Get_Y() + j]).Get_Ch() == str[j]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++) {
							(Chars1[p.Get_X() + i][p.Get_Y() + i]).Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i <= j; i++) {
						(Chars1[p.Get_X() + i][p.Get_Y() + i]).Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				(Chars2[p.Get_X() + i][p.Get_Y() + i]).Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		case 3:
			p.pointrand_BackDown(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if (Chars1[p.Get_X() + i][p.Get_Y() - i].Get_Ch() == ' ') {
					Chars1[p.Get_X() + i][p.Get_Y() - i].Set_Ch(str[i]);
				}
				else if (Chars1[p.Get_X() + i][p.Get_Y() - i].Get_Ch() == str[i]) {
					int j = i + 1;
					if (Chars1[p.Get_X() + j][p.Get_Y() - j].Get_Ch() == ' ' || Chars1[p.Get_X() + j][p.Get_Y() - j].Get_Ch() == str[j]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++) {
							Chars1[p.Get_X() + i][p.Get_Y() - i].Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i <= j; i++) {
						Chars1[p.Get_X() + i][p.Get_Y() - i].Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				(Chars2[p.Get_X() + i][p.Get_Y() - i]).Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		case 4:
			p.pointrand_Up(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if (Chars1[p.Get_X() - i][p.Get_Y()].Get_Ch() == ' ') {
					Chars1[p.Get_X() - i][p.Get_Y()].Set_Ch(str[i]);
				}
				else if (Chars1[p.Get_X() - i][p.Get_Y()].Get_Ch() == str[i]) {
					int j = i + 1;
					if (Chars1[p.Get_X() - j][p.Get_Y()].Get_Ch() == ' ' || Chars1[p.Get_X() - j][p.Get_Y()].Get_Ch() == str[j]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++) {
							Chars1[p.Get_X() - i][p.Get_Y()].Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i <= j; i++) {
						Chars1[p.Get_X() - i][p.Get_Y()].Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				Chars2[p.Get_X() - i][p.Get_Y()].Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		case 5:
			p.pointrand_FrontUp(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if (Chars1[p.Get_X() - i][p.Get_Y() + i].Get_Ch() == ' ') {
					Chars1[p.Get_X() - i][p.Get_Y() + i].Set_Ch(str[i]);
				}
				else if (Chars1[p.Get_X() - i][p.Get_Y() + i].Get_Ch() == str[i]) {
					int j = i + 1;
					if (Chars1[p.Get_X() - j][p.Get_Y() + j].Get_Ch() == ' ' || Chars1[p.Get_X() - j][p.Get_Y() + j].Get_Ch() == str[j]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++) {
							Chars1[p.Get_X() - i][p.Get_Y() + i].Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i <= j; i++) {
						Chars1[p.Get_X() - i][p.Get_Y() + i].Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				Chars2[p.Get_X() - i][p.Get_Y() + i].Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		case 6:
			p.pointrand_BackUp(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if (Chars1[p.Get_X() - i][p.Get_Y() - i].Get_Ch() == ' ') {
					Chars1[p.Get_X() - i][p.Get_Y() - i].Set_Ch(str[i]);
				}
				else if (Chars1[p.Get_X() - i][p.Get_Y() - i].Get_Ch() == str[i]) {
					int j = i + 1;
					if (Chars1[p.Get_X() - j][p.Get_Y() - j].Get_Ch() == ' ' || Chars1[p.Get_X() - j][p.Get_Y() - j].Get_Ch() == str[j]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++) {
							Chars1[p.Get_X() - i][p.Get_Y() - i].Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i < j; i++) {
						Chars1[p.Get_X() - i][p.Get_Y() - i].Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				Chars2[p.Get_X() - i][p.Get_Y() - i].Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		case 7:
			p.pointrand_Back(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if (Chars1[p.Get_X()][p.Get_Y() - i].Get_Ch() == ' ' || Chars1[p.Get_X()][p.Get_Y() - i].Get_Ch() == str[i]) {
					Chars1[p.Get_X()][p.Get_Y() - i].Set_Ch(str[i]);
				}
				else if (Chars1[p.Get_X()][p.Get_Y() - i].Get_Ch() == str[i]) {
					int j = i + 1;
					if (Chars1[p.Get_X()][p.Get_Y() - j].Get_Ch() == ' ' || Chars1[p.Get_X()][p.Get_Y() - j].Get_Ch() == str[j]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++) {
							Chars1[p.Get_X()][p.Get_Y() - i].Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i < j; i++) {
						Chars1[p.Get_X()][p.Get_Y() - i].Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				Chars2[p.Get_X()][p.Get_Y() - i].Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		case 8:
			p.pointrand_Front(str, Get_BoardWidth(), Get_BoardHeight());
			for (int i = 0; i < str.size(); i++) {
				if (Chars1[p.Get_X()][p.Get_Y() + i].Get_Ch() == ' ') {
					Chars1[p.Get_X()][p.Get_Y() + i].Set_Ch(str[i]);
				}
				else if (Chars1[p.Get_X()][p.Get_Y() + i].Get_Ch() == str[i]) {
					int j = i + 1;
					if (Chars1[p.Get_X()][p.Get_Y() + i].Get_Ch() == ' ' || Chars1[p.Get_X()][p.Get_Y() + i].Get_Ch() == str[i]) {
					}
					else {
						int j = i - 1;
						for (int i = 0; i <= j; i++) {
							Chars1[p.Get_X()][p.Get_Y() + i].Set_Ch(space);
						}
						goto inicio;
					}
				}
				else {
					int j = i - 1;
					for (int i = 0; i < j; i++) {
						Chars1[p.Get_X()][p.Get_Y() + i].Set_Ch(space);
					}
					goto inicio;
				}
			}
			for (int i = 0; i < str.size(); i++) {
				Chars2[p.Get_X()][p.Get_Y() + i].Set_Ch(str[i]);
			}
			Points[i].Set_Z(num2);
			break;
		}
		Points[i].Set_X(p.Get_X());
		Points[i].Set_Y(p.Get_Y());
		i++;
	}
	//for test
	for (int i = 0; i < NumWords; i++){
		cout << endl << Points[i].Get_X() << " " << Points[i].Get_Y() << " " <<  Points[i].Get_z() << " " <<  SizeWords[i] << " " << Words1[i].Get_Letters() <<endl;
	}
	system("Pause");
	is.close();
 }

void Board::View1()
{
	//cout << "------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada a View da Board" << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Percorre a matriz Chars e imprime cada Char. NB: Cada Char imprimem-se a si próprio, eg, Char::View()" << endl << endl;
	Point p;
	for (int i = 0; i < Get_BoardWidth(); i++) {
		p.gotoxy(5, 5+i);
		for (int j = 0; j < Get_BoardHeight(); j++) {  //imprimir a matriz com as letras aleatórias
			Chars2[i][j].View();
			cout << " ";
		}
		cout << endl;
	}
	setForeColor(1);
	showRectAt(4, 4);  //imprimir retângulo á volta da matriz
	setForeColor(15);
	int a = 0;
	for (int i = 0; i < Get_BoardHeight(); i++) {  //Colocar identificadores á volta da matriz
		p.gotoxy(5 + (2 * i), 3);
		if (a > 9){
			a = 0;
		}
		cout << a;
		a++;
	}
	int b = 1, c = 0;
	for (int i = 0; i < (Get_BoardHeight() - 10); i++) {  //Colocar identificadores á volta da matriz
		p.gotoxy(25 + (2*i), 2);
		if (c > 9){
			b++;
			c = 0;
		}
		cout << b;
		c++;
	}

	for (int i = 0; i < Get_BoardWidth(); i++){  //Colocar identificadores á volta da matriz
		p.gotoxy(1, 5 + i);
		cout << setw(2) << i;
	}

	setForeColor(12);
	p.gotoxy(2, 4);  //Colocar identificadores á volta da matriz
	cout << "X";

	p.gotoxy(3, 3);  //Colocar identificadores á volta da matriz
	cout << "Y";
	setForeColor(15);
}

void Board::View2(int p)
{
	//cout << "------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada a View da Board" << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Percorre a matriz Chars e imprime cada Char. NB: Cada Char imprimem-se a si próprio, eg, Char::View()" << endl << endl;
	int y = (Points[(p - 1)].Get_X());
	int x = (Points[(p - 1)].Get_Y());
	int a = y, b = x, c = Points[(p - 1)].Get_z();
	Point pt;
	if (p != 0)
	{
		switch (c)  //Vizualizar as palavras já advinhadas na matriz a cor diferente
		{
		case 1:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy((5 + 2*x), ((y + i) + 5));
				cout << Chars1[a][b].Get_Ch();
				a++;
			}
			setForeColor(15);
			break;
		case 2:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy(((2*x + 5) + (2 * i)), (y + i) + 5);
				cout << Chars1[a][b].Get_Ch();
				a++;
				b++;
			}
			setForeColor(15);
			break;
		case 3:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy(((2*x + 5) + (2 * i)), (y - i) + 5);
				cout << Chars1[a][b].Get_Ch();
				a++;
				b--;
			}
			setForeColor(15);
			break;
		case 4:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy((2*x + 5), (y - i) + 5);
				cout << Chars1[a][b].Get_Ch();
				a--;
			}
			setForeColor(15);
			break;
		case 5:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy((2*x + 5) + (2 * i), (y - i) + 5);
				cout << Chars1[a][b].Get_Ch();
				a--;
				b++;
			}
			setForeColor(15);
			break;
		case 6:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy((2*x + 5) - (2 * i), (y - i) + 5);
				cout << Chars1[a][b].Get_Ch();
				a--;
				b--;
			}
			setForeColor(15);
			break;
		case 7:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy(((2 * x + 5) - (2 * i)), y + 5);
				cout << Chars1[a][b].Get_Ch();
				b--;
			}
			setForeColor(15);
			break;
		case 8:
			for (int i = 0; i < SizeWords[(p - 1)]; i++) {
				setForeColor(10);
				pt.gotoxy(((2 * x + 5) + (2 * i)), y + 5);
				cout << Chars1[a][b].Get_Ch();
				b++;
			}
			setForeColor(15);
			break;
		}
	}
	setForeColor(15);
}

void Board::setForeColor(int foreGround) {  //Definir cor da letra
	int backGround = MY_COLOR_BLACK;
	CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbiInfo);
	backGround = csbiInfo.wAttributes / 16;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), backGround * 16 + foreGround);
}

void Board::showRectAt(int x, int y) { //Desenhar retângulo

	setlocale(LC_ALL, "C");
	int i;
	Point p;
	p.gotoxy(x, y);
	cout << char(201);
	for (i = 1; i < (2* Get_BoardHeight()); i++) {
		cout << char(205);
	}

	cout << char(187);
	p.gotoxy(x, ((Get_BoardWidth() + y) + 1));
	cout << char(200);

	for (i = 1; i < (2* Get_BoardHeight()); i++) {
		cout << char(205);
	}

	cout << char (188);

	for (i = (y+1); i < (Get_BoardWidth() + y + 1); i++) {
		p.gotoxy(x, i);
		cout << char(186);

		p.gotoxy(x + (2* Get_BoardHeight()), i);
		cout << char(186);
	}
	setlocale(LC_ALL, "");
}

int Board::Find_w(string s) { //Procura palavra
	for (int i = 0; i < NumWords; i++){
		if ((Words1[i].Get_Letters()) == s){
			Words1[i].Set_Letters(" ");
			return i;
		}
	}
	for (int i = 0; i < NumWords; i++) {
		if (Words1[i].Get_Letters() == " "){
			if ((Words2[i].Get_Letters()) == s){
				return -1;
			}
		}
	}
	return -2;
}

int Board::Find_x(int p, int x) {  //Procura x
	if (Points[p].Get_X() == x) {
		return 1;
	}
	else{
		return 0;
	}
}

int Board::Find_y(int p, int y) {  //Procura y
	if (Points[p].Get_Y() == y) {
		return 1;
	}
	else {
		return 0;
	}
}

void Board::Show_Words(int a, int b) { //Mostra as palvavras já descobertas ao lado da matriz 
	Point p;
	p.gotoxy((Get_BoardHeight() * 2) + 11, 5);
	cout << "Plavras Descobertas: ";
	if (a != 0)
	{
		p.gotoxy((Get_BoardHeight() * 2) + 11, 7 + (2*b));
		cout << Words2[(a-1)].Get_Letters();
	}
}

void Board::Show_Words2() { //Mostra as palvavras já descobertas ao lado da matriz 
	Point p;
	for (int i = 0; i < NumWords; i++){
		p.gotoxy((Get_BoardHeight() * 2) + 11, 5 + (2 * i));
		cout << Words1[i].Get_Letters();
	}
}

Board::~Board()
{
	//cout << "OK ------------------------------------------------------" << endl << endl;
	//cout << "OK Chamada a Destruidor da Board" << endl;
	//cout << "OK O que deve fazer: " << endl;
	//cout << "OK \t- Liberta a memória da matriz Chars (os objetos da classe Char)" << endl << endl;

	for (int i = 0; i < Get_BoardWidth(); i++)
		for (int j = 0; j < Get_BoardHeight(); j++)
			Chars1[i][j].~Char();

	for (int i = 0; i < Get_BoardWidth(); i++)
		for (int j = 0; j < Get_BoardHeight(); j++)
			Chars2[i][j].~Char();
}