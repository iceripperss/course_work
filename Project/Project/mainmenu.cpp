#include<Windows.h>
#include <conio.h>
#include <iostream>
#include "mainmenu.h"
#include "main.h"
#include <iomanip>
#include <string>

using namespace std;

HANDLE hStdOut;
CONSOLE_SCREEN_BUFFER_INFO csbInfo;
SMALL_RECT consolRect;
COORD curspos = { 0, 0 };
WORD inactiveItemAttributes = 112; //атрибут кольору неактивного
									// пункта меню
WORD activeItemAttributes = 124; // атрибут кольору активного
								// пункта меню

const int numMenuM = 11;//кількість позицій в меню

EnumMenuItemsMain current_MI;
//Дефайни клавіш
#define KEY_ARROW_DOWN 80
#define KEY_ARROW_UP 72
#define KEY_ENTER 13

//Створення показника на функцію для роботи меню

typedef void(*pointerFun) (); 

//Створення структури меню
class MenuItem 
{	
public:
	const static char menuTitle[13];
	
	int x, y;
	string str;
	pointerFun pFun; 
};

MenuItem menu[numMenuM] =
{
{ 10, 3,"Add", Add },
{ 10, 5,"To screen", ToScreen },
{ 10, 7,"To binary file", ToBinaryFile },
{ 10, 9,"To word file", ToWordFile },
{ 55, 3,"From binary file", FromBinaryFile },
{ 55, 5,"From word file", FromWordFile },
{ 55, 7,"Search by str", SearchByStr },
{ 55, 9,"Search by number", SearchByNum },
{ 27, 11,"Middle petrol using", MiddlePetrolUs },
{ 28, 13,"Middle routelenght", MiddleRouteLeng },
{ 32, 15,"E X I T",	 Exit },
};

const char MenuItem::menuTitle[13] = 
{
		"Курсач сцука",
};

void gotoxy(int x, int y)//Функція, яка дозволяє встновити курсор на задану позицію
{
	COORD cursorPos = { x, y };
	SetConsoleCursorPosition(hStdOut, cursorPos);
}

void getCursorPosition()//Функція, яка дозволяє отримати позицію курсора
{
	GetConsoleScreenBufferInfo(hStdOut, &csbInfo);
	curspos = csbInfo.dwCursorPosition;
}

void showCursor(bool visible)//Функція, яка відповідає за видимість курсора
{
	CONSOLE_CURSOR_INFO ccInfo;
	ccInfo.bVisible = visible;
	ccInfo.dwSize = 20;
	SetConsoleCursorInfo(hStdOut, &ccInfo);
}

void ItemMenu(int current_MIC, bool activate)//Функція, яка відповідає за функціональність меню, перехід між пунктами
{
	WORD itemAttributes;

	if (activate) itemAttributes = activeItemAttributes;
	else itemAttributes = inactiveItemAttributes;

	gotoxy(menu[current_MIC].x, menu[current_MIC].y);
	SetConsoleTextAttribute(hStdOut, itemAttributes);
	cout << menu[current_MIC].str;
}

void MenuRender()//Функція, яка промальовує меню
{
	gotoxy(32, 0);
	for (int j = 0; j < 14; j++)
	{
		cout << menu->menuTitle[j];
	}
	for (int i = 0; i < numMenuM; i++)
	{ 
		gotoxy(menu[i].x, menu[i].y);
		cout << menu[i].str;
	}
}

void DrawMenu() 
{

	SetConsoleTextAttribute(hStdOut, 112);
	
	showCursor(false);

	MenuRender();
	
	ItemMenu(current_MI, true); 
	int iKey;
	while (1)
	{
		if (_kbhit())
		{
			iKey = _getch();
			switch (iKey)
			{
			case KEY_ARROW_DOWN://Переміщення по меню вниз
			{

				if (current_MI < numMenuM - 1)
				{
					ItemMenu(current_MI, false); 
					current_MI = (EnumMenuItemsMain)(current_MI + 1);
					ItemMenu(current_MI, true); 
				}
				else {
					ItemMenu(current_MI, false); 
					current_MI = add; 
					ItemMenu(current_MI, true); 
				}
				break; 
			}
			case KEY_ARROW_UP://переміщення по меню вгору
			{
				if (current_MI > 0) {
					ItemMenu(current_MI, false);
					current_MI = (EnumMenuItemsMain)(current_MI - 1);
					ItemMenu(current_MI, true);
				}
				else {
					ItemMenu(current_MI, false);
					current_MI = menuexit; // прокрутка вниз
					ItemMenu(current_MI, true);
				}

				break;
			}

			case KEY_ENTER://Вибір дії на пункті
			{

				switch (current_MI)
				{
					case add:
					{
						Add();
						std::cout << std::endl;
						break;
					}
					case Print:
					{
						ToScreen();
						std::cout << std::endl;
						break;
					}
					case SaveBin:
					{
						ToBinaryFile();
						std::cout << std::endl;
						break;					
					}
					case SaveWord:
					{
						ToWordFile();
						std::cout << std::endl;
						break;
					}
					case UpBin:
					{
						FromBinaryFile();
						std::cout << std::endl;
						break;
					}
					case UpWord:
					{
						FromWordFile();
						std::cout << std::endl;
						break;
					}
					case SearchStr:
					{
						SearchByStr();
						std::cout << std::endl;
						break;
					}
					case SearchNumber:
					{
						SearchByNum();
						std::cout << std::endl;
						break;
					}
					case MiddlePetrolUsing:
					{
						MiddlePetrolUs();
						std::cout << std::endl;
						break;
					}
					case MiddleRouteLenghts:
					{
						MiddleRouteLeng();
						std::cout << std::endl;
						break;
					}
					case menuexit:
					{
						Exit();
					}
					MenuRender();
					break;
				}
				break;
			}

			case 120:
			case 88:
			case 27: 
					 exit(0);

			}
		}
	}
}

void BackToMenu()//Фукція відповідає за повернння до інтефейсу
{
	while (_kbhit()) { getch(); }

	int action = NULL;

	while (action != 8)
	{
		action = _getch();
	}

	system("cls");
	SetConsoleTextAttribute(hStdOut, 112);
	MenuRender();
	ItemMenu(add, true);
	current_MI = add;
}