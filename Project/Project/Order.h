#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <exception>
#include "Date.h"
#include "Truck.h"



using namespace std;

class Order
{
	string destination;
	double weidht, cost;
	int routelenght; 
	Date departure;
	Truck truck;
public:
	Order();//����������� �� �������������
	Order(string destination, double weidht, int routelenght, Date departure, Truck truck);//����������� �������� �� ��������� ������
	Order(const Order& from);//����������� ��ﳿ

	//������� ��� ����
	Order& setCost();
	Order& setDestination(string temp);
	Order& setWeidht(double temp);
	Order& setRoutelenght(int temp);
	Order& setDeparture(Date temp);
	Order& setTruck(Truck temp);

	//������� ��� ����
	string getDestination();
	double getWeidht();
	double getCost();
	int getRoutelenght();
	Date getDeparture();
	Truck getTruck();

	//������������� �������� ������������
	Order& operator = (Order other);

	//ϳ��������� ��������� ���������� ����� �� ������ ���������
	friend ostream& operator << (ostream& out, Order& Order);
	friend istream& operator >> (istream& in, Order& Order);

};

