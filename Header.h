#pragma once
#include<iostream>
#include<string>
#include <iomanip>
#include"ExceptionHeader.h"
#include"FuncuClass.h"
#include <fstream>
#include < string.h >
#include<stdlib.h>
#include<algorithm>
#include"TreeHeader.h"
#include"FileHeader.h"

#define _CRT_SECURE_NO_WARNINGS
#define SIZE 16
using namespace std;

/*Класс "Человек" - имя, фамилия, год рождения
Реализовать производные классы -
1. "предприниматель" - номер лицензии, адрес регистрации, данные о налоговых платежах (дата и сумма - структура)
2. "Турист" - номер паспорта, данные о пересечении границы (дата и страна) - структура
3. "Бизнес" (наследуется от предпринимателя и туриста) - массив строк со списком адресов где покупали товары
Все классы должны содержать методы доступа и изменения всех полей, конструкторы, деструкторы, get, set, перегрузка ввода и вывода*/

void static stringToChar(string iz, char* to) {
	int len = iz.size();
	int i = 0;
	for (i = 0; i < len; i++) {
		to[i] = iz[i];
	}
	to[i] = '\0';
};



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
