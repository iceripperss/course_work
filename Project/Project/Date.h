#pragma once
#include <iostream>
#include <exception>

using namespace std;

class Date {
	int day, month, year;

public:
	Date();//����������� �� �������������
	Date(int d, int m, int y);//����������� �������� �� ��������� ������
	Date(const Date& from);//����������� ��ﳿ

	//������� ��� ����
	Date& setDay(int d);
	Date& setMonth(int m);
	Date& setYear(int y);

	//������� ��� ����
	int getDay();
	int getMonth();
	int getYear();

	//������������� �������� ������������
	Date& operator = (Date other);

	//ϳ��������� ��������� ���������� ����� �� ������ ���������
	friend ostream& operator << (ostream& out, Date& outstream);
	friend istream& operator >> (istream& in, Date& instream);
};

