#pragma once
#include<ostream>
#include<istream>
#include<string>
#include "WeeklyBalance.h"
#include "mainmenu.h"

void MenuReturn();//Функція для донесення користовачу повідомлення

void push(WeeklyBalance& A);//Функція, яка відповідає за додання інформації в наш екземпляр WeeklyBalance

//Функції для виводу на екран інофрмації
void PrintMain();//Виводить маску виводу
void PrintOne(RideReport a, int n);//Виводить переданий елемент
void toScreen(WeeklyBalance& a);//Функція, яка виконує загальний виід інформації на екран

void toBinaryF(WeeklyBalance& a, string name);//Введення інформації в бінарний файл

void toWordF(WeeklyBalance& a, string name);//Виведення інформації в текстовий файл

void fromBinaryF(WeeklyBalance& a, string name);//Зчитування інформації з бінарний файлу

void fromWordF(WeeklyBalance& a, string name);//Зчитування інформації з текствого файлу

void searchByS(WeeklyBalance& a, string str);//Пошук інформації в масиві за наданою строкою

void searchByN(WeeklyBalance& a, double num);//Пошук інформації в масиві за наданим числом
