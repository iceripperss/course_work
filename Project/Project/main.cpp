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
extern WORD wo�kWindowAttributes;
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

void Exit()//������� ������� �� ����� � ����
{
	exit(0);
}

void Add()//³������ �� ������� � ���������� ����� ��������
{
	system("CLS");
	push(A);//Lviv 120 11 11 2020 1000 100 500 20 11 2020 Moskov-Lviv
	BackToMenu();
}

void ToScreen()//³������ �� ������� � ���������� �� �����
{
	system("CLS");
	toScreen(A);
	BackToMenu();
}

void ToBinaryFile()//³������ �� ������� � ������� � ������� ����
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	toBinaryF(A, temp);
	BackToMenu();
}

void ToWordFile()//³������ �� ������� � ������� � ��������� ����
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	toWordF(A, temp);
	BackToMenu();
}

void FromBinaryFile()//³������ �� ������� � ����������� � �������� �����
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	fromBinaryF(A, temp);
	BackToMenu();
}

void FromWordFile()//³������ �� ������� � ����������� � ���������� �����
{
	system("CLS");
	string temp;
	cout << "Please enter filename" << endl;
	cin >> temp;
	fromWordF(A, temp);
	BackToMenu();
}

void SearchByStr()//³������ �� ������� � ������� �� ������� ������
{
	system("CLS");
	string temp;
	cout << "Please enter num for search" << endl;
	cin >> temp;
	searchByS(A, temp);
	BackToMenu();
}

void SearchByNum()//³������ �� ������� � ������� �� ��������� ������
{
	system("CLS");
	double temp;
	cout << "Please enter num for search" << endl;
	cin >> temp;
	system("CLS");
	searchByN(A, temp);
	BackToMenu();
}
//������ ������� ��� ����������� ���������� �������� ������ ������
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

void MiddlePetrolUs()//³������ �� ������� � ������� ������� ������ ��������
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

void MiddleRouteLeng()//³������ �� ������� � ������� �������� ������� ��������
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

