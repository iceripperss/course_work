#pragma once
#include "MenuItems.h"
#include <Windows.h>

void gotoxy(int x, int y);//�������, ��� �������� ��������� ������ �� ������ �������

void getCursorPosition();//�������, ��� �������� �������� ������� �������
void showCursor(bool visible);//�������, ��� ������� �� �������� �������

void ItemMenu(int sel, bool activate);//�������, ��� ������� �� ��������������� ����
void MenuRender();//�������, ��� ������� �� ���������� ���������� � ������

void DrawMenu();//������� ������� ���������� 

void BackToMenu();//������ ������� �� ��������� �� ���������

extern HANDLE hStdOut;


