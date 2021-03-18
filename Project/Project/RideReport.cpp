#include "RideReport.h"

RideReport::RideReport() :executiondate()//Конструктор за замовчуванням
{
	this->usedfuel = 0;
	this->pass = " ";
}

RideReport::RideReport(string pass, Date executiondate, string destination, double weidht, int routelenght, Date departure, Truck truck):executiondate(executiondate),Order(destination, weidht, routelenght, departure, truck)//Конструктор відповідно до переданим данним
{
	this->usedfuel = this->getRoutelenght() * this->getTruck().getPetrolper100km();
	this->pass = pass;
}

RideReport::RideReport(const RideReport& other) : Order((Order&)other)//Конструктор копії
{
	this->executiondate = other.executiondate;
	this->pass = other.pass;
	this->setUsedFuel();
}

//Геттери для полів
string RideReport::getPass()
{
	return this->pass;
}
string RideReport::getPass(int)
{
	string str1, str2, str;
	bool ch = 0;
	int i = 0;
	while(ch == 0)//Прохід до завершення першого слова
	{
		if (this->pass[i] != '-' && i < this->pass.size()) str1.push_back(this->pass[i]);
		else
		{
			ch = 1;
		}
		i++;
	}
	i = this->pass.size() - 1;
	while (ch == 1)//Прохід з кінця до початку останнього слова
	{
		if (this->pass[i] != '-' && i >= 0) str2.push_back(this->pass[i]);
		else
		{
			ch = 0;
		}
		i--;
	}
	//Конкатинація строк
	reverse(str2.begin(), str2.end());
	str += str1;
	str += "-";
	str += str2;
	return str;
}
Date RideReport::getExecutiondate()
{
	return this->executiondate;
}
double RideReport::getUsedFuel()
{
	return usedfuel;
}

//Сеттери для полів
RideReport& RideReport::setPass(string temp)
{
	this->pass = temp;
	return *this;
}
RideReport& RideReport::setExecutiondate(Date temp)
{
	this->executiondate = temp;
	return *this;
}
RideReport& RideReport::setUsedFuel()//Метод для оновлення данних про викорастане паливо
{
	this->usedfuel = this->getRoutelenght() * this->getTruck().getPetrolper100km();
	return *this;
}

//Перевантжений оператор присвоювання для роботи з додатковою структорою данних
void RideReport::operator=(DopClass other)
{
	this->setDestination(other.destination);
	this->setRoutelenght(other.routelenght);
	Truck truck(other.capacity, other.petrolper100km);
	this->setTruck(truck);
	this->setWeidht(other.weidht);
	Date data(other.dayo, other.montho, other.yearo), data1(other.dayr, other.monthr, other.yearr);
	this->setDeparture(data);
	this->executiondate = data1;
	this->pass = other.pass;
	this->setUsedFuel();
	this->setCost();
}

//Оператори потокового вводу і виводу
ostream& operator<<(ostream& out, RideReport& RideReport)
{
	//Виведення інформації через екземпляр ostream
	Date d;
	d = RideReport.getDeparture();
	Truck t;
	t = RideReport.getTruck();
	out << RideReport.getDestination() << " " << RideReport.getRoutelenght() << " " << d  << t  << RideReport.getWeidht() << " " << RideReport.executiondate << RideReport.getPass();
	return out;
}
istream& operator>>(istream& in, RideReport& RideReport)
{
	//Отримання інформації через екземпляр istream
	Order OR;
	in >> OR >> RideReport.executiondate >> RideReport.pass;
	RideReport.setTruck(OR.getTruck());
	RideReport.setWeidht(OR.getWeidht());
	RideReport.setDestination(OR.getDestination());
	RideReport.setRoutelenght(OR.getRoutelenght());
	RideReport.setDeparture(OR.getDeparture());
	RideReport.getUsedFuel();
	return in;
}

//Перевантжений оператор присвоювання для коректного переносу данних з допоміжного в основний клас
void DopClass::operator=(RideReport other)
{
	strcpy(this->destination, other.getDestination().c_str());
	this->routelenght = other.getRoutelenght();
	this->capacity = other.getTruck().getCapacity();
	this->petrolper100km = other.getTruck().getPetrolper100km();
	this->weidht = other.getWeidht();
	this->dayo = other.getDeparture().getDay();
	this->montho = other.getDeparture().getMonth();
	this->yearo = other.getDeparture().getYear();
	strcpy(this->pass, other.getPass().c_str());
	this->dayr = other.getExecutiondate().getDay();
	this->monthr = other.getExecutiondate().getMonth();
	this->yearr = other.getExecutiondate().getYear();
}
