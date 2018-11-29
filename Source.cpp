#include <iostream>
#include <ctime>
#include <Windows.h>
#include <conio.h>
using namespace std;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
COORD position;
bool KEY[256];

void GetKEY()
{
	int i = 0;
	while (i < 256)
	{
		if (GetAsyncKeyState(i)) KEY[i] = 1; else KEY[i] = 0;
		i++;
	}
}
///First
void sky()
{
	////Console lighting
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci = { sizeof(CONSOLE_CURSOR_INFO), false };
	SetConsoleCursorInfo(h, &cci);
	/////
	for (int j = 0; j < 15; j++)
	{
		for (int i = 0; i < 80; i++)
		{
			position.X = i;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 1);
			cout << char(219);
		}
	}
}
void City()
{
	int Build_Start = 0;
	int Room_Counts = 0;
	for (int z = 0; z < 15; z++)
	{
		Room_Counts = (rand() % 4 + 3);
		for (int j = (rand() % 12); j < 15; j++)
		{
			for (int i = Build_Start; i <= (Room_Counts + Build_Start); i++)
			{
				if ((rand() % 10) == 1)
				{
					position.X = i;
					position.Y = j;
					SetConsoleCursorPosition(hConsole, position);
					SetConsoleTextAttribute(hConsole, 6);
					cout << char(219);
				}
				else
				{
					position.X = i;
					position.Y = j;
					SetConsoleCursorPosition(hConsole, position);
					SetConsoleTextAttribute(hConsole, 8);
					cout << char(219);
				}
			}
		}
		Build_Start += Room_Counts + (rand() % 3 + 1);//distance between buildings
	}
}
void GrassRoad()
{
	for (int j = 15; j < 31; j++)
	{
		for (int i = 0; i < 80; i++)
		{
			if ((i < (40 - 10 - (j - 7))) || (i > (40 + 10 + (j - 7))))
			{
				position.X = i;
				position.Y = j;
				SetConsoleCursorPosition(hConsole, position);
				SetConsoleTextAttribute(hConsole, 10);
				cout << char(219);
			}
			else
			{
				position.X = i;
				position.Y = j;
				SetConsoleCursorPosition(hConsole, position);
				SetConsoleTextAttribute(hConsole, 7);
				cout << char(219);
			}
		}
	}
}
////
///COLOR
void CarBody(int x, int y, int color)
{
	for (int j = y; j < y + 3; j++)
	{
		if (j == y + 1)
		{
			position.X = x;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);

			for (int i = x + 1; i < x + 4; i++)
			{
				position.X = i;
				position.Y = j;
				SetConsoleCursorPosition(hConsole, position);
				SetConsoleTextAttribute(hConsole, color);
				cout << char(178);
			}
			position.X = x + 4;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
		}
		else
		{
			/////left wheel
			position.X = x - 1;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
			position.X = x;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 8);
			cout << char(177);
			/////left stick
			position.X = x + 1;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112);
			cout << char(196);
			/////Body
			position.X = x + 2;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, color);
			cout << char(178);
			/////right stick
			position.X = x + 3;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112);
			cout << char(196);
			////right wheel
			position.X = x + 4;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 8);
			cout << char(177);
			position.X = x + 5;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
		}
	}
}
void CarColor(int colorid)
{
	int SelectColor = 0;
	for (int i = 15; i < 28; i += 4)
	{
		if (i - (colorid * 4) == 11)
		{
			SelectColor = 10;
		}
		else
		{
			SelectColor = 0;
		}
		position.X = 29;
		position.Y = i + 1;
		SetConsoleCursorPosition(hConsole, position);
		SetConsoleTextAttribute(hConsole, 112 + SelectColor);
		if (i == 15)
		{
			cout << "BLUE";
		}
		else if (i == 19)
		{
			cout << "PINK";
		}
		else if (i == 23)
		{
			cout << "BLUE2";
		}
		else if (i == 27)
		{
			cout << "VIOLET";
		}
	}
}
void CarColorMenu(int &ColorId)
{
	//ColorId = 0;
	GrassRoad();
	for (int i = 15; i < 28; i += 4)
	{
		CarBody(23, i, 98 + i);
	}
	CarColor(ColorId);
	while (1)
	{
		GetKEY();
		if (KEY[38] || KEY[87]) //UP
		{
			if (ColorId == 0)
			{

				ColorId = 4;
			}
			else if (ColorId >= 1)
			{
				ColorId--;
			}
			CarColor(ColorId);
		}
		else if (KEY[40] || KEY[83])//DOWN
		{
			if ((ColorId == 0) || (ColorId == 5))
			{
				ColorId = 1;
			}
			else if (ColorId <= 4)
			{
				ColorId++;
			}
			CarColor(ColorId);
		}
		else if (KEY[13])//select
		{
			return;
		}
		Sleep(200);
	}
}
////
void GrassMove(bool &color)
{
	if (color == false)
	{
		for (int j = 15; j < 31; j++)
		{
			if (j % 2 == 0)
			{
				for (int i = 0; i < 80; i++)
				{
					if ((i < (40 - 10 - (j - 7))) || (i > (40 + 10 + (j - 7))))
					{
						position.X = i;
						position.Y = j;
						SetConsoleCursorPosition(hConsole, position);
						SetConsoleTextAttribute(hConsole, 10);
						cout << char(219);
					}
				}
			}
			else
			{
				for (int i = 0; i < 80; i++)
				{
					if ((i < (40 - 10 - (j - 7))) || (i > (40 + 10 + (j - 7))))
					{
						position.X = i;
						position.Y = j;
						SetConsoleCursorPosition(hConsole, position);
						SetConsoleTextAttribute(hConsole, 2);
						cout << char(219);
					}
				}
			}
		}
		color = true;
	}
	else
	{
		for (int j = 15; j < 31; j++)
		{
			if (j % 2 != 0)
			{
				for (int i = 0; i < 80; i++)
				{
					if ((i < (40 - 10 - (j - 7))) || (i > (40 + 10 + (j - 7))))
					{
						position.X = i;
						position.Y = j;
						SetConsoleCursorPosition(hConsole, position);
						SetConsoleTextAttribute(hConsole, 10);
						cout << char(219);
					}
				}
			}
			else
			{
				for (int i = 0; i < 80; i++)
				{
					if ((i < (40 - 10 - (j - 7))) || (i > (40 + 10 + (j - 7))))
					{
						position.X = i;
						position.Y = j;
						SetConsoleCursorPosition(hConsole, position);
						SetConsoleTextAttribute(hConsole, 2);
						cout << char(219);
					}
				}
			}
		}
		color = false;
	}
}
void Car(int x, int y, int ColorId)
{
	for (int j = 25; j < 28; j++)
	{
		if (j == 26)
		{
			position.X = x;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);

			for (int i = x + 1; i < x + 4; i++)
			{
				position.X = i;
				position.Y = j;
				SetConsoleCursorPosition(hConsole, position);
				SetConsoleTextAttribute(hConsole, 109 + (ColorId * 4));
				cout << char(178);
			}
			position.X = x + 4;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
		}
		else
		{
			/////left wheel
			position.X = x - 1;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
			position.X = x;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 8);
			cout << char(177);
			/////left stick
			position.X = x + 1;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112);
			cout << char(196);
			/////Body
			position.X = x + 2;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 109 + (ColorId * 4));
			cout << char(178);
			/////right stick
			position.X = x + 3;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112);
			cout << char(196);
			////right wheel
			position.X = x + 4;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 8);
			cout << char(177);
			position.X = x + 5;
			position.Y = j;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
		}
	}
}
void Roadblock(int &yp, int &xp, int x, int y, int &speed, int &life)
{
	for (int i = xp; i < (xp + 5); i++)
	{
		position.X = i;
		position.Y = yp;
		SetConsoleCursorPosition(hConsole, position);
		SetConsoleTextAttribute(hConsole, 12);
		cout << char(219);
		position.X = i;
		position.Y = yp - 1;
		SetConsoleCursorPosition(hConsole, position);
		SetConsoleTextAttribute(hConsole, 7);
		cout << char(219);
	}
	////face hit
	if (((yp == y) && (x >= xp) && (x <= (xp + 4))) || ((yp == y) && (x <= xp) && (x >= (xp - 4))))
	{
		for (int i = xp; i < (xp + 5); i++)
		{
			position.X = i;
			position.Y = yp;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
		}
		yp = 17;
		xp = rand() % 32 + 23;
		speed = 0;
		life--;
	}
	/////left hit
	if (((yp == y) || (yp == (y + 1)) || (yp == (y + 2))) && (x > xp) && (x <= (xp + 4)))
	{
		for (int i = xp; i < (xp + 5); i++)
		{
			position.X = i;
			position.Y = yp;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
		}
		yp = 17;
		xp = rand() % 32 + 23;
		speed = 0;
		life--;
	}
	////right hit
	if (((yp == y) || (yp == (y + 1)) || (yp == (y + 2))) && ((x + 4) < (xp + 5)) && ((x + 4) >= xp))
	{
		for (int i = xp; i < (xp + 5); i++)
		{
			position.X = i;
			position.Y = yp;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 7);
			cout << char(219);
		}
		yp = 17;
		xp = rand() % 32 + 23;
		speed = 0;
		life--;
	}

}
void CoutSpeed(int life, int Score, int Speed, double distance)
{
	position.X = 0;
	position.Y = 31;
	SetConsoleCursorPosition(hConsole, position);
	SetConsoleTextAttribute(hConsole, 2);
	cout << "Best Score " << Score << " Speed " << Speed << " Distance " << distance << " ";
	SetConsoleTextAttribute(hConsole, 4);
	for (int i = 0; i < life; i++)
	{
		cout << char(219) << " ";
	}
	cout << "    ";
}
void VlevoVpravo(int &x, int y, int stay, int Speed, int ColorId)
{
	if (KEY[68] || KEY[39])//vpravo
	{
		if ((x + 1) > 63)
		{
			Car(x, y, ColorId);
			Sleep(stay - Speed);
		}
		else
		{
			x += 1;
			Car(x, y, ColorId);
			Sleep(stay - Speed);

		}
	}
	else if (KEY[65] || KEY[37])//vlevo
	{
		if ((x - 1) < 13)
		{
			Car(x, y, ColorId);
			Sleep(stay - Speed);
		}
		else
		{
			x -= 1;
			Car(x, y, ColorId);
			Sleep(stay - Speed);
		}
	}
}
void RoadblockMove(int &yp, int &xp, int x, int y, int &Speed, int &life, int distance)
{
	if (int(distance) % 2 == 0)
	{
		Roadblock(yp, xp, x, y, Speed, life);
		yp++;
		if (yp == 31)
		{
			for (int i = xp; i < (xp + 5); i++)
			{
				position.X = i;
				position.Y = yp - 1;
				SetConsoleCursorPosition(hConsole, position);
				SetConsoleTextAttribute(hConsole, 7);
				cout << char(219);
			}
			yp = 17;
			xp = rand() % 32 + 23;
		}
	}
}
void BestScoreRead(int &Score)
{
	FILE *f;
	fopen_s(&f, "Score.bin", "rb");
	if (f == 0)
	{
		Score = 0;
		return;
	}
	else
	{
		fread(&Score, sizeof(Score), 1, f);
	}
	fclose(f);
}
void BestScoreAdd(int &Distance)
{
	FILE *f;
	fopen_s(&f, "Score.bin", "wb");
	fwrite(&Distance, sizeof(Distance), 1, f);
	fclose(f);
}
void GameOver()
{
	GrassRoad();
	position.X = 0;
	position.Y = 31;
	SetConsoleCursorPosition(hConsole, position);
	SetConsoleTextAttribute(hConsole, 2);
	cout << "                                               ";
	position.X = 37;
	position.Y = 20;
	SetConsoleCursorPosition(hConsole, position);
	SetConsoleTextAttribute(hConsole, 112);
	cout << "GAME OVER" << endl;
	while (1)
	{
		GetKEY();
		if (KEY[27])//EXIT
		{
			return;
		}
	}
}
void Move(int ColorId)
{
	int yp = 16, xp = rand() % 32 + 23;
	bool color = false;
	int Speed = 0, stay = 100, Score = 0;
	int  distance = 0;
	int x = 39, life = 3;
	int y = 25;
	BestScoreRead(Score);
	while (1)
	{
		GetKEY();
		if (KEY[87] || KEY[38]) //pressed W
		{
			if (life == 0)
			{
				if (distance > Score)
				{
					BestScoreAdd(distance);
				}
				GameOver();
				return;
			}
			Car(x, y, ColorId);
			Sleep(stay - Speed);
			if (Speed < 99)
			{
				Speed += 3;
			}
			GrassMove(color);
			distance += (Speed) / 3;
			RoadblockMove(yp, xp, x, y, Speed, life, distance);
			CoutSpeed(life, Score, Speed, distance);
			VlevoVpravo(x, y, stay, Speed, ColorId);
		}
		else if (KEY[27])//exit
		{
			position.X = 0;
			position.Y = 31;
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 2);
			cout << "                                               ";
			return;
		}
		else//no pressed w
		{
			Car(x, y, ColorId);
			Sleep(stay - Speed);
			if (Speed > 0)
			{
				VlevoVpravo(x, y, stay, Speed, ColorId);
				GrassMove(color);
				Speed -= 3;
				distance += (Speed) / 3;
				RoadblockMove(yp, xp, x, y, Speed, life, distance);
				CoutSpeed(life, Score, Speed, distance);
			}
		}
	}

}
void buttons(int ButPos)
{
	int PosBut = 0;
	for (int i = 0; i < 10; i += 3)
	{
		if (i == 0)
		{
			if ((ButPos - i) == 1)
			{
				PosBut = 10;
			}
			else
			{
				PosBut = 0;
			}
		}
		else
		{
			if ((ButPos - i / 3) == 1)
			{
				PosBut = 10;
			}
			else
			{
				PosBut = 0;
			}
		}
		position.X = 39;
		position.Y = 16 + i;
		SetConsoleCursorPosition(hConsole, position);
		SetConsoleTextAttribute(hConsole, 112 + PosBut);
		cout << char(201) << char(205) << char(205) << char(205) << char(205) << char(205) << char(187) << endl;
		position.X = 39;
		position.Y = 17 + i;
		if (i == 0)
		{
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112 + PosBut);
			cout << char(186) << "START" << char(186) << endl;
		}
		else if (i == 3)
		{
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112 + PosBut);
			cout << char(186) << "RULES" << char(186) << endl;
		}
		else if (i == 6)
		{
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112 + PosBut);
			cout << char(186) << "COLOR" << char(186) << endl;
		}
		else if (i == 9)
		{
			SetConsoleCursorPosition(hConsole, position);
			SetConsoleTextAttribute(hConsole, 112 + PosBut);
			cout << char(186) << "EXIT " << char(186) << endl;
		}
		position.X = 39;
		position.Y = 18 + i;
		SetConsoleCursorPosition(hConsole, position);
		SetConsoleTextAttribute(hConsole, 112 + PosBut);
		cout << char(200) << char(205) << char(205) << char(205) << char(205) << char(205) << char(188) << endl;
	}
}
void rules()
{
	GrassRoad();
	position.X = 23;
	position.Y = 16;
	SetConsoleCursorPosition(hConsole, position);
	SetConsoleTextAttribute(hConsole, 112);
	cout << " Toxic race - hardcore game" << endl;
	position.X = 24;
	position.Y = 17;
	SetConsoleCursorPosition(hConsole, position);
	SetConsoleTextAttribute(hConsole, 112);
	cout << "You must to drive for more distance.";
	position.X = 24;
	position.Y = 18;
	SetConsoleCursorPosition(hConsole, position);
	SetConsoleTextAttribute(hConsole, 112);
	cout << "Press ESC for exit";
	while (1)
	{
		GetKEY();
		if (KEY[13]) //exit
		{
			GrassRoad();
			break;
		}
	}
}
void StartMenu(bool &stop, int &ColorId)
{
	int ButPos = 0;
	GrassRoad();
	buttons(ButPos);
	while (1)
	{
		GetKEY();
		if (KEY[38] || KEY[87]) //up
		{
			if (ButPos == 0)
			{
				ButPos = 4;
			}
			else if (ButPos >= 1)
			{
				ButPos--;
			}
			buttons(ButPos);
		}
		else if (KEY[40] || KEY[83])//down
		{
			if ((ButPos == 0) || (ButPos == 5))
			{
				ButPos = 1;
			}
			else if (ButPos <= 4)
			{
				ButPos++;
			}
			buttons(ButPos);
		}
		else if (KEY[13])//select
		{
			if (ButPos == 1)
			{
				GrassRoad();
				Move(ColorId);
				return;
			}
			else if (ButPos == 2)
			{
				rules();
				return;
			}

			else if (ButPos == 3)
			{
				CarColorMenu(ColorId);
				return;
			}
			else if (ButPos == 4)
			{
				stop = false;
				return;
			}
		}
		Sleep(200);
	}
}
/*void Move()
{

	while (1)
	{
		GetKEY();
		if (KEY[13]) //нажат ентер
		{
			cout << "ENtrer" << endl;
		}
		else
			if (KEY[32]) //нажат пробел
			{
				MoveGrass();
				//cout << "Sp...";
			}
		//Sleep(100);
	}
}*/
int main()
{
	system("title TOXIC RACE");
	srand(time(0));
	bool stop = true;
	int ColorId = 0;
	sky();
	City();
	while (stop == true)
	{
		StartMenu(stop, ColorId);
	}
	return 0;
}