#pragma once
#include <iostream>
#include <exception>

using namespace std;

class Date {
	int day, month, year;

public:
	Date();//Конструктор за замовчуванням
	Date(int d, int m, int y);//Конструктор відповідно до переданим данним
	Date(const Date& from);//Конструктор копії

	//Сеттери для полів
	Date& setDay(int d);
	Date& setMonth(int m);
	Date& setYear(int y);

	//Геттери для полів
	int getDay();
	int getMonth();
	int getYear();

	//Перевантжений оператор присвоювання
	Date& operator = (Date other);

	//Підключення операторів потокового вводу та виводу інфорації
	friend ostream& operator << (ostream& out, Date& outstream);
	friend istream& operator >> (istream& in, Date& instream);
};

