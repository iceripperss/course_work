#include "Functions.h"
#include<Windows.h>
#include<iostream>
#include<string>
#include<fstream>
#include<exception>

void MenuReturn()//������� ��� ��������� ����������� �����������
{
	std::cout << std::endl << "Tap Backspace to return" << std::endl;
}

void push(WeeklyBalance& A)//�������, ��� ������� �� ������� ���������� � ��� ��������� WeeklyBalance
{
	RideReport temp;
	A.inputmask();
	cout << endl;
	cin >> temp;
	A.push_back(temp);
	MenuReturn();
}

void PrintMain()//�������� ����� ������
{
	//�� ��������� �������, ��� ���������� ������ �� ������ ���� ������� ����� ������
	gotoxy(0, 0);
	std::cout << "�|Destination";
	gotoxy(20, 0);
	std::cout << "| Routelenght";
	gotoxy(34, 0);
	std::cout << "| Weidht";
	gotoxy(43, 0);
	std::cout << "| Departure";
	gotoxy(55, 0);
	std::cout << "| Truck";
	gotoxy(70, 0);
	std::cout << "| Pass(begin-end)";
	gotoxy(95, 0);
	std::cout << "| Executiondate";
	gotoxy(112, 0);
	std::cout << "| Cost";
	std::cout << std::endl << std::endl;
}

void PrintOne(RideReport a, int n)
{
	//�� ��������� �������, ��� ���������� ������ �� ������ ���� � ��������� ������ �������� ������� ������
	gotoxy(0, n + 1);
	cout << n << "|";
	cout << a.getDestination();
	gotoxy(20, n + 1);
	cout << "|";
	cout << a.getRoutelenght();
	gotoxy(34, n + 1);
	cout << "|";
	cout << a.getWeidht();
	gotoxy(43, n + 1);
	cout << "|";
	Truck truck(a.getTruck());
	Date data(a.getDeparture()), data1(a.getExecutiondate());
	cout << data;
	gotoxy(55, n + 1);
	cout << "|c:";
	cout << truck.getCapacity();
	cout << " p:" << truck.getPetrolper100km();
	gotoxy(70, n + 1);
	cout << "|";
	cout << a.getPass(1);
	gotoxy(95, n + 1);
	cout << "|";
	cout << data1;
	gotoxy(112, n + 1);
	cout << "|";
	cout << a.getCost();
	cout << endl;
}

void toScreen(WeeklyBalance& a)//�������, ��� ������ ��������� ��� ���������� �� �����
{
	PrintMain();
	for (int i = 0; i < a.getSize(); i++)
	{
		PrintOne(a[i], i);
	}
	MenuReturn();
}

void toBinaryF(WeeklyBalance& a, string name)//�������� ���������� � ������� ����
{
	ofstream fout;
	DopClass ch;
	fout.exceptions(ofstream::failbit | ofstream::badbit);//ϳ��������� ���������
	fout.open((name + ".txt"), ofstream::app);//³������� �����
	if (!fout.is_open()) throw exception("������ �������� ");//�������� �������� �����
	int n = a.getSize();//����� ���������
	fout.write((char*)&n, sizeof(int));
	for (int i = 0; i < a.getSize(); i++)//����� ���������� � ������������� ���������� ������
	{
		ch = a[i];
		fout.write((char*)&ch, sizeof(DopClass));
	}
	fout.close();//�������� �����
	MenuReturn();
}

void toWordF(WeeklyBalance& a, string name)
{
	ofstream fout;
	fout.exceptions(ofstream::failbit | ofstream::badbit);//ϳ��������� ���������
	fout.open((name + ".txt"), ofstream::app);//³������� �����
	if (!fout.is_open()) throw exception("������ �������� ");//�������� �������� �����
	fout << a.getSize() << " ";//����� ���������
	for (int i = 0; i < a.getSize(); i++)
	{
		fout << a[i] << "\n";
	}
	fout.close();//�������� �����
	MenuReturn();
}

void fromBinaryF(WeeklyBalance& a, string name)
{
	int n, i = 0;
	DopClass ch;
	RideReport ch1;
	ifstream fin;
	fin.exceptions(ofstream::failbit | ofstream::badbit);//ϳ��������� ���������
	fin.open(name + ".txt");//³������� �����
	if (!fin.is_open()) throw exception("������ �������� ");//�������� �������� �����
	fin.read((char*)&n, sizeof(int));//���������� ���������
	while (fin.read((char*)&ch, sizeof(DopClass)))//���������� �����
	{
		ch1 = ch;
		a.push_back(ch1);
		i++;
		if (i == n) break;
	}
	fin.close();//�������� �����
	MenuReturn();
}

void fromWordF(WeeklyBalance& a, string name)
{
	int n, i = 0;
	ifstream fin;
	fin.exceptions(ofstream::failbit | ofstream::badbit);//ϳ��������� ���������
	fin.open(name + ".txt");//³������� �����
	if (!fin.is_open()) throw exception("������ �������� ");//�������� �������� �����
	fin >> n;//���������� ���������
	while (i < n)//����������� �����
	{
		RideReport temp;
		fin >> temp;
		a.push_back(temp);
		i++;
	}
	fin.close();//�������� �����
	MenuReturn();
}

void searchByS(WeeklyBalance& a, string str)//����� ���������� � ����� �� ������� �������
{
	system("CLS");
	PrintMain();
	int k = 0;
	for (int i = 0; i < a.getSize(); i++)//�������� �� ������� � ������
	{
		if ((a[i].getDestination() == str || a[i].getPass() == str) && (i < a.getSize()))
		{
			PrintOne(a[i], k);
			k++;
		}
	}
	if (k < 1)
		cout << "Not need elements" << endl;
	MenuReturn();
}

void searchByN(WeeklyBalance& a, double num)//����� ���������� � ����� �� ������� ������
{
	system("CLS");
	PrintMain();
	int k = 0;
	for (int i = 0; i < a.getSize(); i++)//�������� �� ������� � ������
	{
		if ((a[i].getCost() == num || a[i].getDeparture().getDay() == num || a[i].getDeparture().getMonth() == num || a[i].getDeparture().getYear() == num || a[i].getExecutiondate().getDay() == num || a[i].getExecutiondate().getMonth() == num || a[i].getExecutiondate().getYear() == num || a[i].getRoutelenght() == num || a[i].getTruck().getCapacity() == num || a[i].getTruck().getPetrolper100km() == num || a[i].getUsedFuel() == num || a[i].getWeidht() == num) && (i < a.getSize()))
		{	
			PrintOne(a[i], k);
			k++;
		}
	}
	if (k < 1)
		cout << "Not found elements" << endl;
	MenuReturn();
}
