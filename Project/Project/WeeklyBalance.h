#pragma once
#include <string>
#include <iostream>
#include <ostream>
#include <exception>
#include "RideReport.h"

class RideReport;

class WeeklyBalance
{
	int size; //Розмірність масиву
	RideReport* list;//Масив елементів RideReport
public:
	WeeklyBalance();//Конструктор за замовчуванням
	WeeklyBalance(int size);//Конструктор, який стоврює кільість екзамплярів в масиві відповідно переданим данним
	WeeklyBalance(const WeeklyBalance& other);//Конструктор копії
	~WeeklyBalance();//Деструктор

	int getSize();//Геттер для отримання розміру масива

	RideReport& operator[](int value);//Оператор індексації, для отримання доступу для елементів масиву list
	void inputmask();//Метод, який використовується задля створення маски вводу інформації

	void push_back(RideReport other);//Метод, який дозволяє додати один елемент в масив list
};

