#include "Truck.h"


Truck::Truck()//����������� �� �������������
{
	this->capacity = 0;
	this->petrolper100km = 0;
}

Truck::Truck(double cap, double pet)//����������� �������� �� ��������� ������
{
	//�������� �� ����������� �������� ������
	if (cap < 0) throw exception("Capacity < 0");
	if (pet < 0) throw exception("Petrolper100km < 0");
	capacity = cap; 
	petrolper100km = pet;
}

Truck::Truck(const Truck& from)//����������� ��ﳿ
{
	capacity = from.capacity; 
	petrolper100km = from.petrolper100km; 
}

//�������
Truck& Truck::setCapacity(double temp)
{
	//�������� �� ����������� �������� ������
	if (temp < 0) throw exception("Capacity < 0");
	capacity = temp;
	return *this;
}
Truck& Truck::setPetrolper100km(double temp)
{
	//�������� �� ����������� �������� ������
	if (temp < 0) throw exception("Petrolper100km < 0");
	petrolper100km = temp;
	return *this;
}

//�������
double Truck::getCapacity()
{
	return capacity;
}
double Truck::getPetrolper100km()
{
	return petrolper100km;
}

//������������� �������� ������������
Truck& Truck::operator=(Truck other)
{
	this->capacity = other.capacity;
	this->petrolper100km = other.petrolper100km;
	return *this;
}

Truck::~Truck()//����������
{
	capacity = petrolper100km = 0;
}

//��������� ���������� ����� � ������
istream& operator >> (istream& in, Truck& Truck) {
	//��������� ���������� ����� ��������� istream
	in >> Truck.capacity >> Truck.petrolper100km;
	return in;
}
ostream& operator << (ostream& out, Truck& Truck) {
	//��������� ���������� ����� ��������� ostream
	out << Truck.capacity << " " << Truck.petrolper100km << " ";
	if (Truck.capacity < 0) throw exception("Capacity < 0");
	if (Truck.petrolper100km < 0) throw exception("Petrolper100km < 0");
	return out;
}
