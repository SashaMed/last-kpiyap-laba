#include"EmployerHeader.h"


string Employer::getName() {
	return this->name;
}

string Employer::getSurName() {
	return this->surName;
}

string Employer::getBirthDate() {
	return this->birthDate;
}



void Employer::setName(string n) {
	this->name = n;
}

void Employer::setSurName(string sn) {
	this->surName = sn;
}

void Employer::setBirthDate(string n) {
	this->birthDate = n;
}



string Employer::getPayhDate() {
	return this->payStruct.payDate;
}

long int Employer::getPaySum() {
	return this->payStruct.sum;
}

string Employer::getRegAd() {
	return this->regAddress;
}

string Employer::getRegNum() {
	return this->regNum;
}




void Employer::setPayDate(string n) {
	this->payStruct.payDate = n;
}

void Employer::setPaySum(long int n) {
	this->payStruct.sum = n;
}

void Employer::setRegAd(string n) {
	this->regAddress = n;
}

void Employer::setRegNum(string n) {
	this->regNum = n;
}


ostream& operator << (ostream& out,const Employer obj) {
	out << obj.regNum; 
	out << setw(15);
	out << obj.regAddress;
	out << setw(15);
	out << obj.payStruct.payDate;
	out << setw(15);
	out << obj.payStruct.sum;
	return out;
}


istream& operator >> (istream& in, Employer &obj) {
	InputCheak temp;
	obj.regAddress = temp.stringInput(in);
	obj.regAddress = temp.stringInput(in);
	obj.payStruct.payDate = temp.stringInput(in);
	obj.payStruct.sum = temp.intInput(in, 0);
	//in >> obj.regNum;
	//in >> obj.regAddress;
	//in >> obj.payStruct.payDate;
	//in >> obj.payStruct.sum;
	return in;
}


bool Employer::operator>(const Employer& obj) {
	if (this->payStruct.sum > obj.payStruct.sum) return true;
	return false;
}

Employer Employer::operator=(const Employer& obj)
{
	this->payStruct.sum = obj.payStruct.sum;
	this->payStruct.payDate = obj.payStruct.payDate;
	this->regNum = obj.regNum;
	this->regAddress = obj.regAddress;
	return Employer();
}
