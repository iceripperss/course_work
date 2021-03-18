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
	Date executiondate;//включення до класу власного класу дати
	double usedfuel;

public:
	RideReport();//Конструктор за замовчуванням
	RideReport(string pass, Date executiondate, string destination, double weidht, int routelenght, Date departure, Truck truck);//Конструктор відповідно до переданим данним
	RideReport(const RideReport& other);//Конструктор копії

	//Геттери для полів
	string getPass();//Перевантаження повного виведення поля
	string getPass(int);//Перевантаження частокового виведення поля виведення поля
	Date getExecutiondate();
	double getUsedFuel();

	//Сеттери для полів
	RideReport& setPass(string temp);
	RideReport& setExecutiondate(Date temp);
	RideReport& setUsedFuel();

	//Перевантжений оператор присвоювання для роботи з додатковою структорою данних
	void operator = (DopClass other);

	//Підключення операторів потокового вводу та виводу інфорації
	friend ostream& operator << (ostream& out, RideReport& RideReport);
	friend istream& operator >> (istream& in, RideReport& RideReport);
};


class DopClass//Додаткова структура данних для роботи з файлами
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

	//Перевантжений оператор присвоювання для коректного переносу данних з допоміжного в основний клас
	void operator=(RideReport other);
};



