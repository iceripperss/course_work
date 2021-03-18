#pragma once
#include <ostream>
#include <iostream>
#include <exception>

using namespace std;

class Truck
{
	double capacity, petrolper100km;

public:
	Truck();//Конструктор за замовчуванням
	Truck(double cap, double pet);//Конструктор відповідно до переданим данним
	Truck(const Truck& from);//Конструктор копії

	//Сеттери для полів
	Truck& setCapacity(double temp);
	Truck& setPetrolper100km(double temp);

	//Геттери для полів
	double getCapacity();
	double getPetrolper100km();

	//Перевантжений оператор присвоювання
	Truck& operator = (Truck other);

	//Підключення операторів потокового вводу та виводу інфорації
	friend ostream& operator << (ostream& out, Truck& Truck);
	friend istream& operator >> (istream& in, Truck& Truck);
	~Truck();//Деструктор
};

