#pragma once
#include <ostream>
#include <iostream>
#include <exception>

using namespace std;

class Truck
{
	double capacity, petrolper100km;

public:
	Truck();//����������� �� �������������
	Truck(double cap, double pet);//����������� �������� �� ��������� ������
	Truck(const Truck& from);//����������� ��ﳿ

	//������� ��� ����
	Truck& setCapacity(double temp);
	Truck& setPetrolper100km(double temp);

	//������� ��� ����
	double getCapacity();
	double getPetrolper100km();

	//������������� �������� ������������
	Truck& operator = (Truck other);

	//ϳ��������� ��������� ���������� ����� �� ������ ���������
	friend ostream& operator << (ostream& out, Truck& Truck);
	friend istream& operator >> (istream& in, Truck& Truck);
	~Truck();//����������
};

