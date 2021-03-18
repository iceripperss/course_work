#pragma once
#include "MenuItems.h"
#include <Windows.h>

void gotoxy(int x, int y);//Функція, яка дозволяє встновити курсор на задану позицію

void getCursorPosition();//Функція, яка дозволяє отримати позицію курсора
void showCursor(bool visible);//Функція, яка відповідає за видимість курсора

void ItemMenu(int sel, bool activate);//Функція, яка відповідає за функціональність меню
void MenuRender();//Функція, яка відповідає за відтворення інтерфейсу в консолі

void DrawMenu();//Оснвона функція інтерфейсу 

void BackToMenu();//Фукція відповідає за повернння до інтефейсу

extern HANDLE hStdOut;


