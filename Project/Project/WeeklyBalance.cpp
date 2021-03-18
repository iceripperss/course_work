#include "WeeklyBalance.h"

WeeklyBalance::WeeklyBalance() //Конструктор за замовчуванням
{
	this->size = 0;
	list = new RideReport[0];
}

WeeklyBalance::WeeklyBalance(int size)//Конструктор, який стоврює кільість екзамплярів в масиві відповідно переданим данним
{
	if (size < 0) throw exception("Array size < 0");//Перевірка чи задане число більше 0
	this->size = size;
	list = new RideReport[size];//Динамічне виілення памяті
	for (int i = 0; i < this->size; i++)
	{
		cout << "Enter " << i + 1 << " element of list:  ";
		cin >> list[i];
	}
}

WeeklyBalance::WeeklyBalance(const WeeklyBalance& other)
{
	this->size = other.size;
	list = new RideReport[size];
	for (int i = 0; i < this->size; i++)
	{
		list[i] = other.list[i];
	}
}//Конструктор копії

WeeklyBalance::~WeeklyBalance()
{
	delete[] list;
}//Деструктор

int WeeklyBalance::getSize()
{
	return this->size;
}//Геттер для отримання розміру масива

RideReport& WeeklyBalance::operator[](int value)//Оператор індексації, для отримання доступу для елементів масиву list
{
	{
		if ((value < size) && (value >= 0)) {
			return this->list[value];
		}
		else
			throw(exception("Index not in array"));//Перевірка на наявність індексу в масиві
	}
}

void WeeklyBalance::inputmask()//Метод, який використовується задля створення маски вводу інформації
{
	cout << "Destination" << " " << "Routelenght" << " " << "Departure(day mouth year)" << " " << "Truck(capacity petrolper100km)" << " " << "Weidht" << " " << "Pass(towns split by -)" << " " << "Executiondate(day mouth year)";
}

void WeeklyBalance::push_back(RideReport other)//Метод, який дозволяє додати один елемент в масив list
{
	RideReport* list1;//Створення нового масива
	list1 = new RideReport[size];
	for (int i = 0; i < size; i++)//Перезапис старого в новий
	{
		list1[i] = list[i];
	}
	delete[] list;//Очистка старого
	size++;
	list = new RideReport[size];//Динамічне виділення місця 
	for (int i = 0; i < size-1; i++)//Переписування маисвів
	{
		list[i] = list1[i];
	}
	list[size - 1] = other;
	delete[] list1;//Очистка додаткового

}
