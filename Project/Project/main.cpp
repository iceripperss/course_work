#include <windows.h>
#include <iostream>
#include <clocale>
#include <ostream>
#include <istream>
#include "WeeklyBalance.h"
#include "Functions.h"
#include "mainmenu.h"
#include "main.h"

WeeklyBalance A;

using namespace std;

extern HANDLE hStdOut; 
extern CONSOLE_SCREEN_BUFFER_INFO csbInfo; 
extern SMALL_RECT consolRect; 
extern WORD woкkWindowAttributes;
extern EnumMenuItemsMain current_MI;

int main()
{
	try
	{
		setlocale(LC_CTYPE, "rus");
		hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		consolRect = csbInfo.srWindow;
		system("CLS");
		DrawMenu();
	}
	catch (const exception & ex)
	{
		cout << ex.what() << endl;
	}
}

void Exit()//Функція відповідає за вихід з меню
{
	exit(0);
}

void Add()//Відповідає за позицію з додаванням новго елементу
{
	system("CLS");
	push(A);//Lviv 120 11 11 2020 1000 100 500 20 11 2020 Moskov-Lviv
	BackToMenu();
}

void ToScreen()//Відповідає за позицію з виведенням на екран
{
	system("CLS");
	toScreen(A);
	BackToMenu();
}

void ToBinaryFile()//Відповідає за позицію з виводом в бінарний файл
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	toBinaryF(A, temp);
	BackToMenu();
}

void ToWordFile()//Відповідає за позицію з виводом в текстовий файл
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	toWordF(A, temp);
	BackToMenu();
}

void FromBinaryFile()//Відповідає за позицію з зчитуванням в бінарного файлу
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	fromBinaryF(A, temp);
	BackToMenu();
}

void FromWordFile()//Відповідає за позицію з зчитуванням в текстового файлу
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	fromWordF(A, temp);
	BackToMenu();
}

void SearchByStr()//Відповідає за позицію з пошуком по введеній строці
{
	system("CLS");
	string temp;
	cout << "Please enter num for search" << endl;
	cin >> temp;
	searchByS(A, temp);
	BackToMenu();
}

void SearchByNum()//Відповідає за позицію з пошуком по введеному номеру
{
	system("CLS");
	double temp;
	cout << "Please enter num for search" << endl;
	cin >> temp;
	system("CLS");
	searchByN(A, temp);
	BackToMenu();
}
//Шаблон функції для знаходження середнього значення масиву данних
template<typename T>
T Middle(T* temp, int n)
{
	T sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += temp[i];
	}
	return sum/n;
}

void MiddlePetrolUs()//Відповідає за позицію з пошуком середніх витрат пального
{
	system("CLS");
	double* mass = new double[A.getSize()];
	for (int i = 0; i < A.getSize(); i++)
	{
		mass[i] = A[i].getUsedFuel();
	}
	cout << "Middle use of petrol: " << Middle(mass, A.getSize());
	BackToMenu();
}

void MiddleRouteLeng()//Відповідає за позицію з пошуком середньої довжини маршруту
{
	system("CLS");
	int* mass = new int[A.getSize()];
	for (int i = 0; i < A.getSize(); i++)
	{
		mass[i] = A[i].getRoutelenght();
	}
	cout << "Middle routelenght " << Middle(mass, A.getSize());
	BackToMenu();
}

