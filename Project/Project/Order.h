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
	Order();//Конструктор за замовчуванням
	Order(string destination, double weidht, int routelenght, Date departure, Truck truck);//Конструктор відповідно до переданим данним
	Order(const Order& from);//Конструктор копії

	//Сеттери для полів
	Order& setCost();
	Order& setDestination(string temp);
	Order& setWeidht(double temp);
	Order& setRoutelenght(int temp);
	Order& setDeparture(Date temp);
	Order& setTruck(Truck temp);

	//Геттери для полів
	string getDestination();
	double getWeidht();
	double getCost();
	int getRoutelenght();
	Date getDeparture();
	Truck getTruck();

	//Перевантжений оператор присвоювання
	Order& operator = (Order other);

	//Підключення операторів потокового вводу та виводу інфорації
	friend ostream& operator << (ostream& out, Order& Order);
	friend istream& operator >> (istream& in, Order& Order);

};

