#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <exception>
#include "Date.h"
#include "Order.h"
#include <algorithm>

using namespace std;

class DopClass;

class RideReport: public Order 
{
	string pass;
	Date executiondate;//��������� �� ����� �������� ����� ����
	double usedfuel;

public:
	RideReport();//����������� �� �������������
	RideReport(string pass, Date executiondate, string destination, double weidht, int routelenght, Date departure, Truck truck);//����������� �������� �� ��������� ������
	RideReport(const RideReport& other);//����������� ��ﳿ

	//������� ��� ����
	string getPass();//�������������� ������� ��������� ����
	string getPass(int);//�������������� ����������� ��������� ���� ��������� ����
	Date getExecutiondate();
	double getUsedFuel();

	//������� ��� ����
	RideReport& setPass(string temp);
	RideReport& setExecutiondate(Date temp);
	RideReport& setUsedFuel();

	//������������� �������� ������������ ��� ������ � ���������� ���������� ������
	void operator = (DopClass other);

	//ϳ��������� ��������� ���������� ����� �� ������ ���������
	friend ostream& operator << (ostream& out, RideReport& RideReport);
	friend istream& operator >> (istream& in, RideReport& RideReport);
};


class DopClass//��������� ��������� ������ ��� ������ � �������
{
public:
	char destination[100];
	double weidht;
	int routelenght;
	double capacity;
	double petrolper100km;
	int dayo;
	int montho;
	int yearo;
	char pass[100];
	int dayr;
	int monthr;
	int yearr;

	//������������� �������� ������������ ��� ���������� �������� ������ � ���������� � �������� ����
	void operator=(RideReport other);
};



