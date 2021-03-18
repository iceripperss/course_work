#pragma once
#include<ostream>
#include<istream>
#include<string>
#include "WeeklyBalance.h"
#include "mainmenu.h"

void MenuReturn();//������� ��� ��������� ����������� �����������

void push(WeeklyBalance& A);//�������, ��� ������� �� ������� ���������� � ��� ��������� WeeklyBalance

//������� ��� ������ �� ����� ����������
void PrintMain();//�������� ����� ������
void PrintOne(RideReport a, int n);//�������� ��������� �������
void toScreen(WeeklyBalance& a);//�������, ��� ������ ��������� ��� ���������� �� �����

void toBinaryF(WeeklyBalance& a, string name);//�������� ���������� � ������� ����

void toWordF(WeeklyBalance& a, string name);//��������� ���������� � ��������� ����

void fromBinaryF(WeeklyBalance& a, string name);//���������� ���������� � ������� �����

void fromWordF(WeeklyBalance& a, string name);//���������� ���������� � ��������� �����

void searchByS(WeeklyBalance& a, string str);//����� ���������� � ����� �� ������� �������

void searchByN(WeeklyBalance& a, double num);//����� ���������� � ����� �� ������� ������
