#include "Order.h"

Order::Order():departure(), truck()//����������� �� �������������
{
	this->destination = " ";
	this->weidht = 0;
	this->routelenght = 0;
	this->cost = 0;
}

Order::Order(string destination, double weidht, int routelenght, Date departure, Truck truck):departure(departure), truck(truck)//����������� �������� �� ��������� ������
{
	//������� ����������� �������� ������
	if (weidht < 0) throw exception("Weidht < 0");
	if (weidht > truck.getCapacity()) throw exception("Weidht > TruckCapacity");
	if (routelenght < 0) throw exception("Routelenght < 0");
	this->destination = destination;
	this->weidht = weidht;
	this->routelenght = routelenght;
	this->cost = (truck.getPetrolper100km() * routelenght * 28 + 5000);
}

Order::Order(const Order& from):departure(from.departure), truck(from.truck)//����������� ��ﳿ
{
	this->destination = from.destination;
	this->weidht = from.weidht;
	this->routelenght = from.routelenght;
	this->cost = from.cost;
}

Order& Order::setCost()//�������� ��� ��������� ����������� ���� cost 
{
	this->cost = (this->truck.getPetrolper100km() * this->routelenght * 28 + 5000);;
	return *this;
}
Order& Order::setDestination(string temp)
{
	this->destination = temp;
	return *this;
}
Order& Order::setWeidht(double temp)
{
	//������� ����������� �������� ������
	if (temp < 0) throw exception("Weidht < 0");
	if (temp > truck.getCapacity()) throw exception("Weidht > TruckCapacity");
	weidht = temp;
	return *this;
}
Order& Order::setRoutelenght(int temp)
{
	//������� ����������� �������� ������
	if (temp < 0) throw exception("Routelenght < 0");
	this->cost = (truck.getPetrolper100km() * routelenght * 28 + weidht * 10);
	routelenght = temp;
	return *this;
}
Order& Order::setDeparture(Date temp)
{
	departure = temp;
	return *this;
}
Order& Order::setTruck(Truck temp)
{
	truck = temp;
	this->cost = (truck.getPetrolper100km() * routelenght * 28 + weidht * 10);
	return *this;
}

//������� ��� ����
string Order::getDestination()
{
	return this->destination;
}
double Order::getWeidht()
{
	return this->weidht;
}
double Order::getCost()
{
	return this->cost;
}
int Order::getRoutelenght()
{
	return this->routelenght;
}
Date Order::getDeparture()
{
	return this->departure;
}
Truck Order::getTruck()
{
	return this->truck;
}

//������������� �������� ������������
Order& Order::operator=(Order from)
{
	this->destination = from.destination;
	this->weidht = from.weidht;
	this->routelenght = from.routelenght;
	this->cost = from.cost;
	this->truck = from.truck;
	this->departure = from.departure;
	return *this;
}

//�������������� ��������� ���������� ���������
ostream& operator<<(ostream& out, Order& Order)
{
	//��������� ���������� ����� ��������� istream
	out << Order.destination << "  " << Order.routelenght << "  " << Order.departure << "  "  << Order.truck << "  " << Order.weidht;
	return out;
}
//�������������� ��������� ���������� �����
istream& operator>>(istream& in, Order& Order)
{
	//��������� ���������� ����� ��������� istream
	in >> Order.destination >> Order.routelenght >> Order.departure >> Order.truck >> Order.weidht;
	if (Order.routelenght < 0) throw exception("Routelenght < 0");
	if (Order.weidht < 0) throw exception("Weidht < 0");
	Order.setCost();
	return in;
}

