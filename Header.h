#pragma once
#include<iostream>
#include<string>
#include <iomanip>
#include"ExceptionHeader.h"

using namespace std;

/*����� "�������" - ���, �������, ��� ��������
����������� ����������� ������ -
1. "���������������" - ����� ��������, ����� �����������, ������ � ��������� �������� (���� � ����� - ���������)
2. "������" - ����� ��������, ������ � ����������� ������� (���� � ������) - ���������
3. "������" (����������� �� ��������������� � �������) - ������ ����� �� ������� ������� ��� �������� ������
��� ������ ������ ��������� ������ ������� � ��������� ���� �����, ������������, �����������, get, set, ���������� ����� � ������*/

class Human {
protected:
	string name;
	string surName;
	string birthDate;
public:
	Human() { this->name = '\0'; this->surName = '\0'; this->birthDate = '\0'; };
	Human(string n, string sn, string bd) { this->name = n; this->surName = sn; this->birthDate = bd; };
	~Human() {};
	virtual string getName() = 0;
	virtual string getSurName() = 0;
	virtual string getBirthDate() = 0;
	virtual void setName(string n) = 0;
	virtual void setSurName(string sn) = 0;
	virtual void setBirthDate(string bd) = 0;
};
