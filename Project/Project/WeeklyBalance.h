#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <exception>
#include "RideReport.h"

class RideReport;

class WeeklyBalance
{
	int size; //��������� ������
	RideReport* list;//����� �������� RideReport
public:
	WeeklyBalance();//����������� �� �������������
	WeeklyBalance(int size);//�����������, ���� ������� ������� ���������� � ����� �������� ��������� ������
	WeeklyBalance(const WeeklyBalance& other);//����������� ��ﳿ
	~WeeklyBalance();//����������

	int getSize();//������ ��� ��������� ������ ������

	RideReport& operator[](int value);//�������� ����������, ��� ��������� ������� ��� �������� ������ list
	void inputmask();//�����, ���� ��������������� ����� ��������� ����� ����� ����������

	void push_back(RideReport other);//�����, ���� �������� ������ ���� ������� � ����� list
};

