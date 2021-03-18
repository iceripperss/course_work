#include "WeeklyBalance.h"

WeeklyBalance::WeeklyBalance() //����������� �� �������������
{
	this->size = 0;
	list = new RideReport[0];
}

WeeklyBalance::WeeklyBalance(int size)//�����������, ���� ������� ������� ���������� � ����� �������� ��������� ������
{
	if (size < 0) throw exception("Array size < 0");//�������� �� ������ ����� ����� 0
	this->size = size;
	list = new RideReport[size];//�������� ������� �����
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
}//����������� ��ﳿ

WeeklyBalance::~WeeklyBalance()
{
	delete[] list;
}//����������

int WeeklyBalance::getSize()
{
	return this->size;
}//������ ��� ��������� ������ ������

RideReport& WeeklyBalance::operator[](int value)//�������� ����������, ��� ��������� ������� ��� �������� ������ list
{
	{
		if ((value < size) && (value >= 0)) {
			return this->list[value];
		}
		else
			throw(exception("Index not in array"));//�������� �� �������� ������� � �����
	}
}

void WeeklyBalance::inputmask()//�����, ���� ��������������� ����� ��������� ����� ����� ����������
{
	cout << "Destination" << " " << "Routelenght" << " " << "Departure(day mouth year)" << " " << "Truck(capacity petrolper100km)" << " " << "Weidht" << " " << "Pass(towns split by -)" << " " << "Executiondate(day mouth year)";
}

void WeeklyBalance::push_back(RideReport other)//�����, ���� �������� ������ ���� ������� � ����� list
{
	RideReport* list1;//��������� ������ ������
	list1 = new RideReport[size];
	for (int i = 0; i < size; i++)//��������� ������� � �����
	{
		list1[i] = list[i];
	}
	delete[] list;//������� �������
	size++;
	list = new RideReport[size];//�������� �������� ���� 
	for (int i = 0; i < size-1; i++)//������������� ������
	{
		list[i] = list1[i];
	}
	list[size - 1] = other;
	delete[] list1;//������� �����������

}
