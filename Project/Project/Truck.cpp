#include "Truck.h"


Truck::Truck()//Конструктор за замовчуванням
{
	this->capacity = 0;
	this->petrolper100km = 0;
}

Truck::Truck(double cap, double pet)//Конструктор відповідно до переданим данним
{
	//Перевірка на позитивність внесених данних
	if (cap < 0) throw exception("Capacity < 0");
	if (pet < 0) throw exception("Petrolper100km < 0");
	capacity = cap; 
	petrolper100km = pet;
}

Truck::Truck(const Truck& from)//Конструктор копії
{
	capacity = from.capacity; 
	petrolper100km = from.petrolper100km; 
}

//Сеттери
Truck& Truck::setCapacity(double temp)
{
	//Перевірка на позитивність внесених данних
	if (temp < 0) throw exception("Capacity < 0");
	capacity = temp;
	return *this;
}
Truck& Truck::setPetrolper100km(double temp)
{
	//Перевірка на позитивність внесених данних
	if (temp < 0) throw exception("Petrolper100km < 0");
	petrolper100km = temp;
	return *this;
}

//Геттери
double Truck::getCapacity()
{
	return capacity;
}
double Truck::getPetrolper100km()
{
	return petrolper100km;
}

//Перевантжений оператор присвоювання
Truck& Truck::operator=(Truck other)
{
	this->capacity = other.capacity;
	this->petrolper100km = other.petrolper100km;
	return *this;
}

Truck::~Truck()//Деструктор
{
	capacity = petrolper100km = 0;
}

//Оператори потокового вводу і виводу
istream& operator >> (istream& in, Truck& Truck) {
	//Отримання інформації через екземпляр istream
	in >> Truck.capacity >> Truck.petrolper100km;
	return in;
}
ostream& operator << (ostream& out, Truck& Truck) {
	//Виведення інформації через екземпляр ostream
	out << Truck.capacity << " " << Truck.petrolper100km << " ";
	if (Truck.capacity < 0) throw exception("Capacity < 0");
	if (Truck.petrolper100km < 0) throw exception("Petrolper100km < 0");
	return out;
}
