#include "Date.h"

Date::Date()//Конструктор за замовчуванням
{
	this->day = 1;
	this->month = 1;
	this->year = 2000;
}

Date::Date(int d, int m, int y)//Конструктор відповідно до переданим данним
{
	//Обробка правильності введення інформації
	if (d < 0) throw exception("Day < 0");
	if (d > 31) throw exception("Day > 31");
	if (m < 0) throw exception("Month < 0");
	if (m > 12) throw exception("Month > 12");
	if (y < 0) throw exception("Year < 0");
	day = d; 
	month = m; 
	year = y;
}
Date::Date(const Date& from)//Конструктор копії
{
	day = from.day; 
	month = from.month; 
	year = from.year;
}

//Сеттери для полів
Date& Date::setDay(int d)
{
	//Обробка правильності введення інформації
	if (d < 0) throw exception("Day < 0");
	if (d > 31) throw exception("Day > 31");
	day = d; 
	return *this; 
}
Date& Date::setMonth(int m)
{
	//Обробка правильності введення інформації
	if (m < 0) throw exception("Month < 0");
	if (m > 12) throw exception("Month > 12");
	month = m; 
	return *this;
}
Date& Date::setYear(int y)
{
	//Обробка правильності введення інформації
	if (y < 0) throw exception("Year < 0");
	year = y; 
	return *this;
}

//Геттери для полів
int Date::getDay()
{
	return day;
}
int Date::getMonth()
{
	return month;
}
int Date::getYear()
{
	return year;
}

//Перевантжений оператор присвоювання
Date& Date::operator=(Date other)
{
	this->day = other.day; this->month = other.month; this->year = other.year; return *this;
}

//Перевантаження оператору потокового вводу
istream& operator >> (istream& in, Date& Date) {
	//Отримання інформації через екземпляр istream
	in >> Date.day >> Date.month >> Date.year;
	//Обробка правильності введення інформації
	if (Date.day < 0) throw exception("Day < 0");
	if (Date.day > 31) throw exception("Day > 31");
	if (Date.month < 0) throw exception("Month < 0");
	if (Date.month > 12) throw exception("Month > 12");
	if (Date.year < 0) throw exception("Year < 0");
	return in;
}

//Перевантаження оператору потокового виведення
ostream& operator << (ostream& out, Date& Date) {
	//Отримання інформації через екземпляр istream
	out << Date.day << " " << Date.month << " " << Date.year << " ";
	return out;
}
