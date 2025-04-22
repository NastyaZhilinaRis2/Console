#include <iostream>
#include <stdlib.h> 
#include <ctime>
#include <conio.h>

using namespace std;

bool gameOver;
const int width = 25;
const int height = 20;
int x, y, fruitX, fruitY, score = 0;
enum eDirection { STOP, LEFT, RIGHT, UP, DOWN };
eDirection dir;
int flag;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	srand(time(0));
	fruitX = 2 + rand() % (width - 1 - 2 + 1);
	fruitY = 2 + rand() % (height - 1 - 2 + 1);
	score = 0;
}
void Draw() {
	system("cls");
	for (int i = 1; i <= width; i++)
		cout << "%";
	cout << endl;

	for (int i = 2; i < height; i++)
	{
		for (int j = 1; j <= width; j++)
		{
			if (j == 1 || j == width)
				cout << "%";
			else
				if (x == j && y == i)
					cout << "O";
				else if (fruitX == j && fruitY == i)
					cout << "*";
				else cout << " ";


		}
		cout << endl;
	}

	for (int i = 1; i <= width; i++)
		cout << "%";
	cout << endl;
	cout << "\nscore = " << score;
}
void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 75:
		case 228:
		case 'a': dir = LEFT;  break;
		case 77:
		case 162:
		case 'd': dir = RIGHT;  break;
		case 72:
		case 230:
		case 'w': dir = UP;  break;
		case 80:
		case 235:
		case 's': dir = DOWN; break;
		}
	}
}
void Logic()
{
	switch (dir)
	{
	case LEFT: x--; break;
	case RIGHT: x++; break;
	case UP: y--; break;
	case DOWN: y++; break;
	}
	if (x == 1 || x == width || y == 1 || y == height)
		gameOver = true;
	if (x == fruitX && y == fruitY)
	{
		fruitX = 2 + rand() % (width - 1 - 2 + 1);
		fruitY = 2 + rand() % (height - 1 - 2 + 1);
		score++;
	}
}
void Exit()
{
	int otstupX, otstupY;
	bool m = true;
	while (m == true)
	{
		system("cls");
		for (otstupY = height / 2; otstupY >= 0; otstupY-=2) cout << "\n"; 
		for (otstupX = width / 2; otstupX >= 0; otstupX -= 2) cout << " ";
		cout << "Game Over!\n";
		for (otstupX = width / 2; otstupX >= 0; otstupX -= 2) cout << " ";
		cout << "score = " << score << "\n";
		for (otstupX = width / 2; otstupX >= 0; otstupX -= 2) cout << " ";
		cout << "Чтобы начать заново, нажмите 1\n";
		for (otstupX = width / 2; otstupX >= 0; otstupX -= 2) cout << " ";
		cout << "Чтобы выйти, нажмите ESC";
		for (otstupY = height / 2; otstupY >= 0; otstupY -= 2) cout << "\n";
		for (otstupX = width / 2; otstupX >= 0; otstupX -= 2) cout << " ";
		cout <<"\n";
		if (_kbhit())
		{
			switch (_getch())
			{
			case 27: m = false; gameOver = true; break;
			case 49: m = false; flag = 1; break;
			}
		}
	}
}
int main()
{
	repeat:
	setlocale(LC_ALL, "RUSSIAN");
	Setup();
	while (gameOver == false)
	{
		Draw();
		Input();
		Logic();
	}
	Exit();
	if (flag == 1) { goto repeat; };
}